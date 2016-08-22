package ncku.hpds.tzulitai.mapreduce.svm.bagging;

import java.io.IOException;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.Vector;

import libsvm.svm;
import libsvm.svm_model;
import libsvm.svm_node;
import libsvm.svm_parameter;
import libsvm.svm_problem;
import ncku.hpds.tzulitai.mapreduce.svm.bagging.io.TrainingSubsetInputFormat;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.filecache.DistributedCache;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;

public class BaggingSvm {
	
	public static class PreStatCounterMapper
		extends Mapper<Object, Text, NullWritable, Text>{
	
		public void map(Object offset, Text v_trainingData,
				Context context) throws IOException, InterruptedException {
			context.getCounter("trainingDataStats","TOTAL_RECORD_COUNT").increment(1);
		
			String dataStr = v_trainingData.toString();
			String label = dataStr.substring(0, dataStr.indexOf(" "));
		
			// TODO: Can only recognize labels with "+1" "-1" format...
			if(label.equals("+1")){
				context.getCounter("trainingDataStats","CLASS_1_COUNT").increment(1);
			} else if(label.equals("-1")) {
				context.getCounter("trainingDataStats","CLASS_2_COUNT").increment(1);
			}
			context.write(NullWritable.get(), v_trainingData);
		}
	}
	
	public static class PrePartitionerMapper
		extends Mapper<Object, Text, IntWritable, Text>{
	
		Random r = new Random();
	
		public void map(Object offset, Text v_trainingData,
						Context context) throws IOException, InterruptedException {
			final double subsetCount = context.getConfiguration().getInt("SUBSET_COUNT", 2);
			final double classCount_1 = context.getConfiguration().getDouble("CLASS_1_COUNT", 2);
			final double totalRecordCount = context.getConfiguration().getDouble("TOTAL_RECORD_COUNT", 2);

			final double classRatio = classCount_1/totalRecordCount;

			final double subsetMaxRecordCount = Math.ceil(totalRecordCount/subsetCount);
			final double subsetMaxClassCount_1 = Math.ceil(subsetMaxRecordCount*classRatio);
			final double subsetMaxClassCount_2 = subsetMaxRecordCount - subsetMaxClassCount_1 + 1;
		
			String dataStr = v_trainingData.toString();
			String label = dataStr.substring(0, dataStr.indexOf(" "));
			int subsetId = r.nextInt((int)subsetCount);
		
			if(label.equals("+1")) {
				while(context.getCounter("subsetDataStats", "SUBSET_" + subsetId + "_CLASS_1").getValue()
						>= subsetMaxClassCount_1)
					subsetId = r.nextInt((int)subsetCount);
				context.getCounter("subsetDataStats", "SUBSET_" + subsetId + "_CLASS_1").increment(1);
				context.write(new IntWritable(subsetId), v_trainingData);
			} else if(label.equals("-1")) {
				while(context.getCounter("subsetDataStats", "SUBSET_" + subsetId + "_CLASS_2").getValue()
						>= subsetMaxClassCount_2)
					subsetId = r.nextInt((int)subsetCount);
				context.getCounter("subsetDataStats", "SUBSET_" + subsetId + "_CLASS_2").increment(1);
				context.write(new IntWritable(subsetId), v_trainingData);
			}
		}
	}
	
	public static class SubsetDataOutputReducer
		extends Reducer<IntWritable, Text, NullWritable, Text>{
	
		public void reduce(IntWritable subsetId, Iterable<Text> v_subsetTrainingDataset,
			 		   	   Context context) throws IOException, InterruptedException {
			for(Text trainingData : v_subsetTrainingDataset) 
				context.write(NullWritable.get(), trainingData);
		}
	}
	
	private static class SvmTrainer {
		private svm_problem prob;
		private svm_parameter param;
		private int max_index = 0;
		private String[] subsetRecords;
		
		SvmTrainer(String[] subsetRecords){
			this.subsetRecords = subsetRecords;
			formSvmProblem();
			configureSvmParameters();
		}
		
		private void formSvmProblem() {
			Vector<Double> vy = new Vector<Double>();
			Vector<svm_node[]> vx = new Vector<svm_node[]>();
			
			for(int itr=0; itr<this.subsetRecords.length; itr++) {
				StringTokenizer recordTokenItr = new StringTokenizer(this.subsetRecords[itr]," \t\n\r\f:");
				
				vy.addElement(atof(recordTokenItr.nextToken()));
				int featureCount = recordTokenItr.countTokens()/2;
				svm_node[] features = new svm_node[featureCount];
				
				// filling in the features of current record
				for(int i=0; i<featureCount; i++) {
					features[i] = new svm_node();
					features[i].index = atoi(recordTokenItr.nextToken());
					features[i].value = atof(recordTokenItr.nextToken());
				}
				
				// compare the largest feature index with max_index
				if(featureCount>0)
					this.max_index = Math.max(this.max_index, features[featureCount-1].index);
				
				vx.addElement(features);
			}
			
			this.prob = new svm_problem();
			this.prob.l = vy.size();
			
			this.prob.x = new svm_node[this.prob.l][];
			this.prob.y = new double[this.prob.l];
			for(int i=0; i<prob.l; i++) {
				this.prob.x[i] = vx.elementAt(i);
				this.prob.y[i] = vy.elementAt(i);
			}
		}
		
		private void configureSvmParameters() {
			this.param = new svm_parameter();

            		// default values
            		this.param.svm_type = svm_parameter.C_SVC;
            		this.param.kernel_type = svm_parameter.RBF;
            		this.param.degree = 3;
            		this.param.gamma = 0;        // 1/num_features
            		this.param.coef0 = 0;
            		this.param.nu = 0.5;
            		this.param.cache_size = 100;
            		this.param.C = 1;
            		this.param.eps = 1e-3;
            		this.param.p = 0.1;
            		this.param.shrinking = 1;
            		this.param.probability = 0;
            		this.param.nr_weight = 0;
            		this.param.weight_label = new int[0];
            		this.param.weight = new double[0];
            
            		if(this.param.gamma == 0 && this.max_index > 0)
                		this.param.gamma = 1.0/this.max_index;
            
            		if(this.param.kernel_type == svm_parameter.PRECOMPUTED)
                		for(int i=0;i<this.prob.l;i++) {
                        		if (this.prob.x[i][0].index != 0) {
                                		System.err.print("Wrong kernel matrix: first column must be 0:sample_serial_number\n");
                                		System.exit(1);
                        		}

                        		if ((int)this.prob.x[i][0].value <= 0 || (int)this.prob.x[i][0].value > this.max_index) {
                                		System.err.print("Wrong input format: sample_serial_number out of range\n");
                                		System.exit(1);
                        		}
                		}
		}
		
		public svm_model train(){
			svm_model model = svm.svm_train(this.prob, this.param);
			return model;
		}
	}

	
	/*
	 * A refactorization of LIBSVM's implementation of reading and training a svm problem.
	 * Mostly identical to the original implementation.
	 * Used by SubSvmMapper, and LastLayerSvmModelOutputReducer.
	 */
	
	public static class SubSvmMapper
		extends Mapper<Object, Text, IntWritable, Text>{
		
		private Text supportVector = new Text();
		private IntWritable partitionIndex = new IntWritable();
		
		public void map(Object offset, Text wholeSubset,
						Context context) throws IOException, InterruptedException {
			String[] subsetRecords = wholeSubset.toString().split("\n");
			
			SvmTrainer svmTrainer = new SvmTrainer(subsetRecords);
			svm_model model = svmTrainer.train();
            
            int[] svIndices = model.sv_indices;
            
            for(int i=0; i<svIndices.length; i++) {
            	supportVector.set(subsetRecords[svIndices[i]-1]);
            	int taskId = context.getTaskAttemptID().getTaskID().getId();
            	partitionIndex.set((int)Math.floor(taskId/2));
            	context.write(partitionIndex, supportVector);
            }
		}
	}
	
	private static double atof(String s) {
		double d = Double.valueOf(s).doubleValue();
		if (Double.isNaN(d) || Double.isInfinite(d)) {
                	System.err.print("NaN or Infinity in training data input\n");
                	System.exit(1);
        	}
		
		return d;
	}
	
	private static int atoi(String s) {
		return Integer.parseInt(s);
	}
	
	public static class BaseModelOutputMapper
		extends Mapper<NullWritable, Text, NullWritable, Text>{
	
		private static final String svm_type_table[] = {
        	"c_svc","nu_svc","one_class","epsilon_svr","nu_svr",
    	};

		static final String kernel_type_table[]= {
                "linear","polynomial","rbf","sigmoid","precomputed"
    	};
	
		// An identical implementation of svm.svm_save_model in LIBSVM,
		// different in that the file is saved to HDFS instead of a local path.
		private void saveModelToHdfs(svm_model model, String pathStr, int taskId, Context context){
			try {
				FileSystem fs = FileSystem.get(context.getConfiguration());
				Path file = new Path(fs.getHomeDirectory(),pathStr+"/base-models/model-"+taskId+".model");
				FSDataOutputStream fos = fs.create(file);
			
				svm_parameter param = model.param;
			
				fos.writeBytes("svm_type "+svm_type_table[param.svm_type]+"\n");
				fos.writeBytes("kernel_type "+kernel_type_table[param.kernel_type]+"\n");
			
				if(param.kernel_type == svm_parameter.POLY)
					fos.writeBytes("degree "+param.degree+"\n");
			
				if(param.kernel_type == svm_parameter.POLY ||
					param.kernel_type == svm_parameter.RBF ||
	           	   	param.kernel_type == svm_parameter.SIGMOID)
					fos.writeBytes("gamma "+param.gamma+"\n");
			
				if(param.kernel_type == svm_parameter.POLY ||
					param.kernel_type == svm_parameter.SIGMOID)
	            	fos.writeBytes("coef0 "+param.coef0+"\n");
			
				int nr_class = model.nr_class;
            	int l = model.l;
            	fos.writeBytes("nr_class "+nr_class+"\n");
            	fos.writeBytes("total_sv "+l+"\n");
            
            	fos.writeBytes("rho");
            	for(int i=0;i<nr_class*(nr_class-1)/2;i++)
            		fos.writeBytes(" "+model.rho[i]);
            	fos.writeBytes("\n");
            
            	if(model.label != null) {
            		fos.writeBytes("label");
                	for(int i=0;i<nr_class;i++)
                		fos.writeBytes(" "+model.label[i]);
                	fos.writeBytes("\n");
            	}
            
            	if(model.probA != null) { // regression has probA only
            		fos.writeBytes("probA");
                	for(int i=0;i<nr_class*(nr_class-1)/2;i++)
                		fos.writeBytes(" "+model.probA[i]);
                	fos.writeBytes("\n");
            	}
            
            	if(model.probB != null) {
                	fos.writeBytes("probB");
                	for(int i=0;i<nr_class*(nr_class-1)/2;i++)
                    	fos.writeBytes(" "+model.probB[i]);
                	fos.writeBytes("\n");
            	}
            
            	if(model.nSV != null) {
            		fos.writeBytes("nr_sv");
                	for(int i=0;i<nr_class;i++)
                		fos.writeBytes(" "+model.nSV[i]);
                	fos.writeBytes("\n");
            	}
            
            	fos.writeBytes("SV\n");
            	double[][] sv_coef = model.sv_coef;
            	svm_node[][] SV = model.SV;
            
            	for(int i=0;i<l;i++) {
            		for(int j=0;j<nr_class-1;j++)
            			fos.writeBytes(sv_coef[j][i]+" ");

                	svm_node[] p = SV[i];
                	if(param.kernel_type == svm_parameter.PRECOMPUTED)
                		fos.writeBytes("0:"+(int)(p[0].value));
                	else
                		for(int j=0;j<p.length;j++)
                			fos.writeBytes(p[j].index+":"+p[j].value+" ");
                	fos.writeBytes("\n");
            	}
            
            	fos.close();

			} catch (IOException ioe) {
				throw new RuntimeException(ioe);
			}
		}
	
		private Text supportVector = new Text();
	
		public void map(NullWritable offset, Text trainingSubset,
						Context context) throws IOException, InterruptedException {
			String[] svRecords = trainingSubset.toString().split("\n");
		
			SvmTrainer svmTrainer = new SvmTrainer(svRecords);
			svm_model model = svmTrainer.train();
		
			String userOutputPathStr = context.getConfiguration().get("USER_OUTPUT_PATH");
			int taskId = context.getTaskAttemptID().getTaskID().getId();
			saveModelToHdfs(model,userOutputPathStr,taskId,context);
        
        	int[] svIndices = model.sv_indices;
        
        	for(int i=0; i<svIndices.length; i++) {
        		supportVector.set(svRecords[svIndices[i]-1]);
        		context.write(NullWritable.get(), supportVector);
        	}
		}
	}
	
	public static void main(String[] args) throws Exception {
		Configuration firstConf = new Configuration();
		String[] otherArgs = new GenericOptionsParser(firstConf, args).getRemainingArgs();
		if (otherArgs.length < 2) {
			System.err.println("Usage: bagging-svm <in> <out> <subsets>");
			System.exit(2);
		}
		
		final double subsets = Double.valueOf(otherArgs[2]);
		final int prepartitionJobCount = 2;
		
		Configuration[] prepartitionConfs = new Configuration[prepartitionJobCount];
		prepartitionConfs[0] = firstConf;
		prepartitionConfs[1] = new Configuration();

		/*
		 *  Prepare prepartitioning jobs
		 */
		
		Job[] prepartitionJobs = new Job[prepartitionJobCount];
		
		prepartitionJobs[0] = new Job(prepartitionConfs[0], "Bagging SVM: Partitioning training data, Phase 1");
		prepartitionJobs[0].setJarByClass(BaggingSvm.class);
		prepartitionJobs[0].setNumReduceTasks(0);	// map-only job
		prepartitionJobs[0].setMapperClass(PreStatCounterMapper.class);
		prepartitionJobs[0].setOutputKeyClass(NullWritable.class);
		prepartitionJobs[0].setOutputValueClass(Text.class);
		FileInputFormat.addInputPath(prepartitionJobs[0], new Path(otherArgs[0]));
		FileOutputFormat.setOutputPath(prepartitionJobs[0], new Path(otherArgs[1]+"/tmp"));
		prepartitionJobs[0].waitForCompletion(true);
		
		prepartitionConfs[1].setInt("SUBSET_COUNT",(int)subsets);
		prepartitionConfs[1].setInt("TOTAL_RECORD_COUNT",
				(int)prepartitionJobs[0].getCounters().findCounter("trainingDataStats","TOTAL_RECORD_COUNT").getValue());
		prepartitionConfs[1].setInt("CLASS_1_COUNT",
				(int)prepartitionJobs[0].getCounters().findCounter("trainingDataStats","CLASS_1_COUNT").getValue());
		prepartitionConfs[1].setInt("CLASS_2_COUNT",
				(int)prepartitionJobs[0].getCounters().findCounter("trainingDataStats","CLASS_2_COUNT").getValue());
		
		prepartitionJobs[1] = new Job(prepartitionConfs[1], "Bagging SVM: Partitioning training data, Phase 2");
		prepartitionJobs[1].setJarByClass(BaggingSvm.class);
		prepartitionJobs[1].setNumReduceTasks((int)subsets);
		prepartitionJobs[1].setMapperClass(PrePartitionerMapper.class);
		prepartitionJobs[1].setReducerClass(SubsetDataOutputReducer.class);
		prepartitionJobs[1].setMapOutputKeyClass(IntWritable.class);
		prepartitionJobs[1].setMapOutputValueClass(Text.class);
		prepartitionJobs[1].setOutputKeyClass(NullWritable.class);
		prepartitionJobs[1].setOutputValueClass(Text.class);
		FileInputFormat.addInputPath(prepartitionJobs[1], new Path(otherArgs[1]+"/tmp"));
		FileOutputFormat.setOutputPath(prepartitionJobs[1], new Path(otherArgs[1]+"/base-model-subsets"));
		prepartitionJobs[1].waitForCompletion(true);
		
		Configuration baggingJobConf = new Configuration();
		DistributedCache.addFileToClassPath( new Path("/user/hpds/libsvm.jar"), baggingJobConf);
		baggingJobConf.set("USER_OUTPUT_PATH", otherArgs[1]);
		
		Job baggingJob = new Job(baggingJobConf,"Bagging SVM: Base models training");
		baggingJob.setJarByClass(BaggingSvm.class);
		baggingJob.setNumReduceTasks(0);
		baggingJob.setMapperClass(BaseModelOutputMapper.class);
		baggingJob.setOutputKeyClass(NullWritable.class);
		baggingJob.setOutputValueClass(Text.class);
		baggingJob.setInputFormatClass(TrainingSubsetInputFormat.class);
		FileInputFormat.addInputPath(baggingJob, new Path(otherArgs[1]+"/base-model-subsets"));
		FileOutputFormat.setOutputPath(baggingJob, new Path(otherArgs[1]+"/base-model-SVs"));
		System.exit(baggingJob.waitForCompletion(true) ? 0 : 1);
	}
}
