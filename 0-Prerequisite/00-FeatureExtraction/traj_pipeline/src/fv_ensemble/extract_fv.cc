// Extract Fisher vectors for dense trajectory.
// Zexi Mao
// Jun. 2014

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <vector>

#include "fisher.h"
#include "gmm.h"
#include "gzstream/gzstream.h"

using namespace std;

const int kGauss = 256;
const int kDes = 4;
const int kDim = 426;
const int kDimFull = 436;
const int kRange[4][2] = { {11, 40}, {41, 136}, {137, 244}, {245, 436} };
const int kDesDim[4] = {15, 48, 54, 96};

void FinalNormalize(float*, int);
void SaveFv(vector<float*>&, ogzstream&);
void ComputeNormalizeSave(vector< fisher<float>* >&, ogzstream&);
void AddSubFv(vector< fisher<float>* >&, vector< fisher<float>* >&);
void AddSaveClean(vector< fisher<float>* >&, vector< fisher<float>* >&, ogzstream&);

int main(int argc, const char **argv)
{
    bool skip1_finished = false;
    // Check arguments.
    if (argc != 7) {
        cerr << "Usage: " << argv[0] << "save_name skip136_save_name shot_save_name segx_name fps codebook_pca_list" << endl;
        exit(-1);
    }
    string save_name(argv[1]);
    string skip136_save_name(argv[2]);
    string shot_save_name(argv[3]);
    string segx_name(argv[4]);
    float fps = atof(argv[5]);
    string cb_pca_list_name(argv[6]);
    save_name += ".gz";
    skip136_save_name += ".gz";
    shot_save_name += ".gz";
    // Open feature files for writing.
    ogzstream save_file(save_name.c_str());
    ogzstream shot_save_file(shot_save_name.c_str());

    fisher_param fisher_encoder_params;

    vector< vector<float*> > gmm_mean;
    vector< vector<float*> > gmm_var;
    vector< vector<float> > gmm_coef;
    vector< gaussian_mixture<float>* > gmm_proc;
    vector< vector< vector<float> > > pca_proj;
    fstream cb_pca_list_file(cb_pca_list_name.c_str(), fstream::in);
    for (int i_des = 0; i_des < kDes; ++i_des) {
        string tmp_line;
        stringstream tmp_stream;
        getline(cb_pca_list_file, tmp_line);
        string codebook_name = tmp_line.substr(0, tmp_line.find(' '));
        string pca_proj_name = tmp_line.substr(tmp_line.find(' ')+1);
        
        /*****************************
         ** Start reading codebook. **
         *****************************/
        vector<float*> this_gmm_mean;
        vector<float*> this_gmm_var;
        vector<float> this_gmm_coef(kGauss);
        fstream codebook_file(codebook_name.c_str(), fstream::in);

        // Check validity of the codebook files.
        int in_gauss, in_dim1, in_dim2;
        getline(codebook_file, tmp_line);
        tmp_stream.clear();
        tmp_stream.str(tmp_line);
        tmp_stream >> in_dim1 >> in_gauss;
        assert(in_dim1 == kDesDim[i_des]);
        assert(in_gauss == kGauss);
        // Debug output.
        cerr << "Codebook validated " << i_des << '!' << endl;

        // Read out each GMM mean.
        getline(codebook_file, tmp_line);
        tmp_stream.clear();
        tmp_stream.str(tmp_line);
        for (int j_gauss = 0; j_gauss < kGauss; ++j_gauss) {
            float *this_mean = new float[in_dim1];
            for (int k_dim = 0; k_dim < in_dim1; ++k_dim)
                tmp_stream >> this_mean[k_dim];
            this_gmm_mean.push_back(this_mean);
        }

        // Read out each GMM variance.
        getline(codebook_file, tmp_line);
        getline(codebook_file, tmp_line);
        tmp_stream.clear();
        tmp_stream.str(tmp_line);
        for (int j_gauss = 0; j_gauss < kGauss; ++j_gauss) {
            float *this_var = new float[in_dim1];
            for (int k_dim = 0; k_dim < in_dim1; ++k_dim)
                tmp_stream >> this_var[k_dim];
            this_gmm_var.push_back(this_var);
        }

        // Read out each GMM weight.
        getline(codebook_file, tmp_line);
        getline(codebook_file, tmp_line);
        tmp_stream.clear();
        tmp_stream.str(tmp_line);
        for (int j_gauss = 0; j_gauss < kGauss; ++j_gauss)
            tmp_stream >> this_gmm_coef[j_gauss];

        gmm_mean.push_back(this_gmm_mean);
        gmm_var.push_back(this_gmm_var);
        gmm_coef.push_back(this_gmm_coef);

        // Build the GMM instance.
        gaussian_mixture<float> *this_gmm_proc = new gaussian_mixture<float>(kGauss, kDesDim[i_des]);
        this_gmm_proc->set(this_gmm_mean, this_gmm_var, this_gmm_coef);
        gmm_proc.push_back(this_gmm_proc);

        /*****************************
         Start reading PCA projection.
         *****************************/
        vector< vector<float> > this_pca_proj;
        fstream pca_proj_file(pca_proj_name.c_str(), fstream::in);

        // Check the validity of the PCA projection files.
        getline(pca_proj_file, tmp_line);
        tmp_stream.clear();
        tmp_stream.str(tmp_line);
        tmp_stream >> in_dim1 >> in_dim2;
        assert(in_dim1 == kDesDim[i_des]);
        assert(in_dim2 == kDesDim[i_des] * 2);
        // Debug output.
        cerr << "PCA projection validated " << i_des << '!' << endl;

        // Read out each PCA projection.
        getline(pca_proj_file, tmp_line);
        tmp_stream.clear();
        tmp_stream.str(tmp_line);
        for (int j_dim = 0; j_dim < in_dim1; ++j_dim) {
            vector<float> pca_proj_line(in_dim2);
            this_pca_proj.push_back(pca_proj_line);
        }
        for (int k_dim = 0; k_dim < in_dim2; ++k_dim) {
            for (int j_dim = 0; j_dim < in_dim1; ++j_dim)
                tmp_stream >> this_pca_proj[j_dim][k_dim];
        }
        pca_proj.push_back(this_pca_proj);
    }

    /*****************************
       Initialize Fisher vectors.
     *****************************/
    vector< fisher<float>* > shot_fishers(kDes, NULL);

    vector< fisher<float>* > fishers(kDes, NULL);
    for (int i_des = 0; i_des < kDes; ++i_des) {
        // Construct a struct with default parameter values.
        fisher<float> *this_fisher = new fisher<float>(fisher_encoder_params);

        // Initialize the encoder with the GMM codebook.
        this_fisher->set_model(*(gmm_proc[i_des]));

        fishers[i_des] = this_fisher;
    }

    vector< fisher<float>* > fishers_36(kDes, NULL);
    for (int i_des = 0; i_des < kDes; ++i_des) {
        fisher<float> *this_fisher = new fisher<float>(fisher_encoder_params);

        // Initialize the encoder with the GMM codebook.
        this_fisher->set_model(*(gmm_proc[i_des]));

        fishers_36[i_des] = this_fisher;
    }

    vector< fisher<float>* > fishers_136(kDes, NULL);
    for (int i_des = 0; i_des < kDes; ++i_des) {
        fisher<float> *this_fisher = new fisher<float>(fisher_encoder_params);

        // Initialize the encoder with the GMM codebook.
        this_fisher->set_model(*(gmm_proc[i_des]));

        fishers_136[i_des] = this_fisher;
    }

    // Prepare the shot-level metadata.
    fstream segx_file(segx_name.c_str(), fstream::in);
    string segx_line;
    stringstream segx_stream;
    float shot_end_time = 0.0;

    /*****************************
      Start reading raw features.
     *****************************/
    string traj_line;
    stringstream traj_stream;
    while (getline(cin, traj_line)) {
        if (traj_line != "Skip 1 finished!") {
#ifndef DEBUG
            // Send the exact raw features to the standard output.
            cout << traj_line << endl;
#endif
        } else {
            skip1_finished = true;

            // Save the last shot-level Fisher vector and update the skip-1.
            AddSaveClean(fishers, shot_fishers, shot_save_file);
            
            // Save the skip-1 Fisher vector.
            AddSaveClean(fishers_136, fishers, save_file);

            // This line of standart input will not be processed.
            cout << traj_line << endl;
            continue;
        }

        traj_stream.clear();
        traj_stream.str(traj_line);
        float *sample_point = new float[kDimFull];
        for (int i_float = 0; i_float < kDimFull; ++i_float)
            traj_stream >> sample_point[i_float];

        float traj_time = sample_point[0] / fps;

        // Check whether the skip-1 has finished.
        if (!skip1_finished) {
            // Check whether the feature point is in a new shot.
            if (traj_time - shot_end_time > - numeric_limits<float>::epsilon()) {
                if (fabs(shot_end_time - 0.0f) > numeric_limits<float>::epsilon()) {
                    AddSaveClean(fishers, shot_fishers, shot_save_file);
                    shot_save_file << endl;
                }

                getline(segx_file, segx_line);
                segx_stream.clear();
                segx_stream.str(segx_line);
                for (int i = 0; i < 3; ++i)
                    segx_stream >> shot_end_time;

                // Initialize the shot-level Fisher vectors.
                for (int i_des = 0; i_des < kDes; ++i_des) {
                    fisher<float> *this_fisher = new fisher<float>(fisher_encoder_params);

                    // Initialize the encoder with the GMM codebook.
                    this_fisher->set_model(*(gmm_proc[i_des]));

                    shot_fishers[i_des] = this_fisher;
                }
            }
        }

        for (int i_des = 0; i_des < kDes; ++i_des) {
            float *sub_sample = sample_point;
            sub_sample += (kRange[i_des][0] - 1);

            // Perform RootSIFT normalization, only do it for hog, hof, mbh, (don't do it for traj).
            if (i_des >= 1) {
                float sum = 0.0;
                for (int j_dim = 0; j_dim < 2*kDesDim[i_des]; ++j_dim)
                    sum += sub_sample[j_dim];
                for (int j_dim = 0; j_dim < 2*kDesDim[i_des]; ++j_dim)
                    sub_sample[j_dim] = sqrt(sub_sample[j_dim] / sum);
            }

            // Perform PCA and feed the shortened features into the Fisher vectors.
            float *sample_out = new float[kDesDim[i_des]](); // This includes the initialization to 0,
            for (int j_dim = 0; j_dim < kDesDim[i_des]; ++j_dim) {
                for (int k_dim = 0; k_dim < kDesDim[i_des]*2; ++k_dim)
                    sample_out[j_dim] += sub_sample[k_dim] * pca_proj[i_des][j_dim][k_dim];
            }
            
            // Check the correct Fisher vector to add the samples.
            if (!skip1_finished)
                shot_fishers[i_des]->AddOne(sample_out);
            else
                fishers_36[i_des]->AddOne(sample_out);
            delete[] sample_out;
        }
        delete[] sample_point;
    }

    if (skip1_finished) {
        // Save the skip-1-3-6 Fisher vector.
        AddSubFv(fishers_136, fishers_36);
        ogzstream skip136_save_file(skip136_save_name.c_str());
        ComputeNormalizeSave(fishers_136, skip136_save_file);
        skip136_save_file.close();
    } else { // Does not have skip-3-6 raw features.
        // Save the last shot-level Fisher and update the skip-1.
        AddSaveClean(fishers, shot_fishers, shot_save_file);
        ComputeNormalizeSave(fishers, save_file);
        cerr << "No skip-3-6 feature provided!" << endl;
    }

    // Close feature files.
    save_file.close();
    shot_save_file.close();

    // Clean up.
    for (vector< vector<float*> >::iterator gmm_mean_it = gmm_mean.begin(); gmm_mean_it != gmm_mean.end(); ++gmm_mean_it) {
        for (vector<float*>::iterator this_mean_it = (*gmm_mean_it).begin(); this_mean_it != (*gmm_mean_it).end(); ++this_mean_it)
            delete[] (*this_mean_it);
    }
    for (vector< vector<float*> >::iterator gmm_var_it = gmm_var.begin(); gmm_var_it != gmm_var.end(); ++gmm_var_it) {
        for (vector<float*>::iterator this_var_it = (*gmm_var_it).begin(); this_var_it != (*gmm_var_it).end(); ++this_var_it)
            delete[] (*this_var_it);
    }
    for (vector< gaussian_mixture<float>* >::iterator gmm_it = gmm_proc.begin(); gmm_it != gmm_proc.end(); ++gmm_it)
        delete (*gmm_it);
}


void AddSaveClean(vector< fisher<float>* >& fishers_sum, vector< fisher<float>* >& fishers_sub, ogzstream& save_file)
{
    // Add the sub Fisher vector to the whole.
    AddSubFv(fishers_sum, fishers_sub);

    // Normalize and save the sub Fisher vector.
    ComputeNormalizeSave(fishers_sub, save_file);

    // Clean up the sub Fisher vector.
    for (int i_des = 0; i_des < kDes; ++i_des) {
        delete fishers_sub[i_des];
        fishers_sub[i_des] = NULL;
    }
}


void AddSubFv(vector< fisher<float>* >& fishers_sum, vector< fisher<float>* >& fishers_sub)
{
    for (int i_des = 0; i_des < kDes; ++i_des)
        fishers_sum[i_des]->AddSub(fishers_sub[i_des]);
}


void ComputeNormalizeSave(vector< fisher<float>* >& fishers, ogzstream& save_file)
{
    vector<float*> fisher_vectors;
    for (int i_des = 0; i_des < kDes; ++i_des) {
        // Compute the Fisher vectors.
        fishers[i_des]->Compute();
        fishers[i_des]->alpha_and_lp_normalization();
        float *this_fv = fishers[i_des]->get_fv();
        fisher_vectors.push_back(this_fv);
    }

    // Final Normalization
    for (int i_des = 0; i_des < kDes; ++i_des) {
        FinalNormalize(fisher_vectors[i_des], 2*kGauss*kDesDim[i_des]);
    }

    // Output the Fisher vectors to gzipped files.
    SaveFv(fisher_vectors, save_file);
}


void SaveFv(vector<float*>& this_fvs, ogzstream& save_file)
{
    int count = 0;

    for (int i_des = 0; i_des < kDes; ++i_des) {
        for (int j_dim = 0; j_dim < 2*kGauss*kDesDim[i_des]; ++j_dim)
            save_file << ++count << ':' << this_fvs[i_des][j_dim] << ' ';
    }
}


void FinalNormalize(float *this_fv, int n_dim)
{
    // L2 normalization on whole code.
    float norm_factor = 0.0;
    for (int i_dim = n_dim; i_dim--;)
        norm_factor += this_fv[i_dim] * this_fv[i_dim];
    if (norm_factor > 0.0) {
        norm_factor = sqrt(norm_factor);
        for (int i_dim = n_dim; i_dim--;)
            this_fv[i_dim] /= norm_factor;
    }

    // Apply Hellinger kernel map.
    for (int i_dim = n_dim; i_dim--;) {
        if (this_fv[i_dim] < 0)
            this_fv[i_dim] = - sqrt(-this_fv[i_dim]);
        else
            this_fv[i_dim] = sqrt(this_fv[i_dim]);
    }

    // L2 post-normalization on whole code and divide by two to make the whole
    // vector L2-normalized.
    float post_factor = 0.0;
    for (int i_dim = n_dim; i_dim--;)
        post_factor += this_fv[i_dim] * this_fv[i_dim];
    if (post_factor > 0.0) {
        post_factor = sqrt(post_factor);
        post_factor *= 2.0;
        for (int i_dim = n_dim; i_dim--;)
            this_fv[i_dim] /= post_factor;
    }
}
