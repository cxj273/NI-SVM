/*
 * readfeatsmat.cpp
 *
 * Code generation for function 'readfeatsmat'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "readfeatsmat.h"
#include "FisherVectorEncode_emxutil.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <cassert>
#include <algorithm>
#include <time.h>

#define MAX_LINES 500000

using namespace std;

#ifdef MX_API_VER
#if MX_API_VER < 0x07030000
typedef int mwIndex;
#endif 
#endif 
#ifndef max
#define max(x,y) (((x)>(y))?(x):(y))
#endif
#ifndef min
#define min(x,y) (((x)<(y))?(x):(y))
#endif

void readfeatsmat(emxArray_real32_T *feat_data, int start_frame, int end_frame)
{
	int dims = 426;
	//if( feat_id < 3 ){ //ColorDescriptor tar.gz, WATCH OUT IF YOU CHANGE FEATURE ORDER!!!
	int skip = 10;
	vector<string> record;
	int lines = 0;
	vector<int> to_replace;
	int round = 1;
	int this_round_lines = 0;
	unsigned int to_replace_acc = 0;
	srand(time(0));
	while( 1 ){
		string line;
		getline(cin, line);
		if( cin.eof() ){
			fprintf(stderr, "end of stdin, break\n");
			break;
		}
		//cout << line << endl;
		int frame;
		sscanf(line.c_str(), "%d", &frame);
		if( end_frame != -1 && frame >= end_frame ){
			break;
		}
		//will lose the first feature of each shot, but I guess that is ok....
		if( lines < MAX_LINES ){
			record.push_back(line);
			lines++;
		}else{
			if( to_replace_acc == to_replace.size() ){
				fprintf(stderr, "round %d full\n", round);
				round++;
				to_replace.clear();
				for(int i = 0; i < lines; i++){
					to_replace.push_back(i);
				}
				for(int i = 0; i < MAX_LINES * 2; i++){
					int v1 = rand() % lines;
					int v2 = rand() % lines;
					int id = to_replace[v1];
					to_replace[v1] = to_replace[v2];
					to_replace[v2] = id;
				}
				int left = (int)((double)lines / (double)round);
				if( left < MAX_LINES / 100 ){ //make sure left doesn't go to 0...
					left = MAX_LINES / 100;
				}
				to_replace.resize( left );
				fprintf(stderr, "round %d, replace size %d, to_replace_acc %d\n", round, to_replace.size(), to_replace_acc);
				to_replace_acc = 0;
				this_round_lines = 0;
			}
			if( this_round_lines % round == 0 ){
				record[ to_replace[to_replace_acc] ] = line;
				//fprintf(stderr, "replacing %d\n", to_replace[to_replace_acc]);
				to_replace_acc++;
			}
			this_round_lines++;
		}
	}

	fprintf(stderr, "printing %d lines to stdout\n", lines);
	for(int kk = 0; kk < lines; kk++){
		cout << record[kk] << endl;
	}

	fprintf(stderr, "final lines %d\n", lines);
	int i7 = feat_data->size[0] * feat_data->size[1];
	feat_data->size[0] = skip + dims;
	feat_data->size[1] = lines;
	emxEnsureCapacity((emxArray__common *)feat_data, i7, (int32_T)sizeof(real32_T));
	float* out_ptr = feat_data->data;
	int acc = 0;
	//int now_idx = 0;
	for(int kk = 0; kk < lines; kk++){
		string& line = record[kk];

		char* ptr = (char*)malloc(sizeof(char) * (line.length() + 1));
		strcpy(ptr, line.c_str());
		char *ptr2 = ptr, *tok;
		int line_start = acc;
		int read_elements = 0;
		for(int i = 0; i < skip + dims; i++){
			tok = strtok(ptr2, " \t");
			if( tok == NULL ){
				fprintf(stderr, "error at line %d, dim %d\n", acc + 1, i);
				//fake_answer(feat_data);
				exit(-1);
			}
			ptr2 = NULL;
			sscanf(tok, "%f", &out_ptr[acc]);
			read_elements++;
			acc++;
		}
		//ignore extra stuff behind
		//tok = strtok(NULL, " \t");
		//if( tok != NULL ){
		//	fprintf(stderr, "error at line %d %s\n", acc + 1, tok);
		//	fake_answer(feat_data);
		//	return;
		//}
		free(ptr);

		//root sift normalization, only do it for hog, hof, mbh, (don't do it for traj)

		int range[4][2] = { {11, 40}, {41, 136}, {137, 244}, {245, 436} };
		//int range[4][2] = { {11, 30}, {31, 126}, {127, 234}, {235, 426} };
		for(int i = 1; i < 4; i++){
			//fprintf(stderr, "root sift %d to %d\n", range[i][0]-1, range[i][1]-1);
			float sum = 0;
			for(int j = line_start + range[i][0] - 1; j < line_start + range[i][1]; j++){
				sum += out_ptr[j];
			}
			for(int j = line_start + range[i][0] - 1; j < line_start + range[i][1]; j++){
				out_ptr[j] = sqrtf( out_ptr[j] / sum );
			}
		}
	}
	assert(acc == lines * (dims + skip));
}
