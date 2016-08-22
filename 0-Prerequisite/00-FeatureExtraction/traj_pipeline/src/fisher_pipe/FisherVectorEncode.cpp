/*
 * FisherVectorEncode.cpp
 *
 * Code generation for function 'FisherVectorEncode'
 *
 * C source code generated on: Sat Sep  7 17:42:49 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "FisherVectorEncode_emxutil.h"
#include "FeatFormatParse.h"
#include "rand.h"
#include "getFKEncoder.h"
#include "getSPMPooler.h"
#include "readfeatsmat.h"
#include "compute.h"
#include "find.h"
#include "isnan.h"
#include "mexFisherEncodeHelperSP.h"
#include "gzstream.h"

#include <vector>

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void c_string(const char_T s[1024], char_T y[1025]);

/* Function Definitions */

/*
 * function y = c_string(s)
 */
static void c_string(const char_T s[1024], char_T y[1025])
{
	/* 'FisherVectorEncode:84' y = [s 0]; */
	memcpy((void *)&y[0], (void *)&s[0], sizeof(char_T) << 10);
	y[1024] = '\x00';
}

/*
 *
 */

void get_fisher(emxArray_real32_T* feat_data, std::vector<float>& final_vector, int xyt_mode,
	emxArray_real32_T *pca_proj[4], fisher_handle<float>* fhs[4], 
	int video_width, int video_height, 
	boolean_T encoder_grad_means[4], boolean_T encoder_grad_variances[4], boolean_T encoder_grad_weights[4],
	char_T t0_subbin_norm_type[2], int32_T t0_encoder__codebook__n_gauss[4], int32_T t0_encoder__codebook__n_dim[4],
	emxArray_char_T *pooler_post_norm_type, char_T* pooling, emxArray_char_T *pooler_norm_type,
	real32_T feat_format_y_col, real32_T feat_format_x_col,	boolean_T feat_format_spatial,
	real32_T b_expl_temp, emxArray_char_T *pooler_kermap, real32_T feat_format_feat_dim
){
	
	int32_T i0;
	int32_T loop_ub;
	int32_T i1;
	int32_T i2;
	int32_T encoder_codebook__n_dim;
	int32_T encoder_codebook__n_gauss;
	real32_T encoder_alpha;
	int32_T iv2[2];
	int32_T iv3[2];
	int32_T b_loop_ub;
	int32_T i3;


	emxArray_real32_T *fv_code;
	emxArray_real32_T *val;
	emxArray_real32_T *idx_fv;
	emxArray_real32_T *h_idx;
	emxArray_real32_T *w_idx;
	emxArray_real32_T *r0;
	emxArray_int32_T *r1;
	emxArray_boolean_T *r3;
	emxArray_int32_T *frame;
	emxArray_int32_T *r4;
	emxArray_real32_T *b_feat_data;
	emxArray_int32_T *r5;
	emxArray_real32_T *c_feat_data;
	emxArray_int32_T *r6;
	emxArray_real32_T *d_feat_data;
	emxArray_real32_T *e_feat_data;
	emxArray_real32_T *b_pca_proj;
	emxArray_real32_T *b_fv_code;
		
	b_emxInit_real32_T(&fv_code, 1);
	emxInit_real32_T(&val, 2);
	emxInit_real32_T(&idx_fv, 2);
	emxInit_real32_T(&h_idx, 2);
	emxInit_real32_T(&w_idx, 2);
	emxInit_real32_T(&b_fv_code, 2);
	emxInit_int32_T(&frame, 2);
	emxInit_real32_T(&r0, 2);
	emxInit_int32_T(&r1, 2);
	emxInit_boolean_T(&r3, 2);
	emxInit_real32_T(&b_pca_proj, 2);
	b_emxInit_int32_T(&r4, 1);
	b_emxInit_real32_T(&b_feat_data, 1);
	b_emxInit_int32_T(&r5, 1);
	b_emxInit_real32_T(&c_feat_data, 1);
	b_emxInit_int32_T(&r6, 1);
	emxInit_real32_T(&d_feat_data, 2);
	emxInit_real32_T(&e_feat_data, 2);
	
	emxArray_real32_T f_feat_data;


	//int dims_acc[4] = { 0, 7680-2560, 32256-2560, 59904-2560 };
	int dims_acc[5] = { 0, 0, 0, 0, 0 };
	int range[4][2] = { {11, 40}, {41, 136}, {137, 244}, {245, 436} };
	int mult = 8;
	int div = 1;
	for(int ii = 1; ii < 5; ii++){
		dims_acc[ii] = dims_acc[ii-1] + ((range[ii-1][1] - range[ii-1][0] + 1)/2 + xyt_mode) * t0_encoder__codebook__n_gauss[ii-1] * 2;
	}
	if( feat_format_spatial == TRUE ){
		for(int ii = 1; ii < 5; ii++){
			dims_acc[ii] *= 8;
		}
	}
	final_vector.resize(dims_acc[4], 0 );
	fprintf(stderr, "final fv dimension %d\n", dims_acc[4]);
	//int range[4][2] = { {11, 30}, {31, 126}, {127, 234}, {235, 426} };
	for(int ii = 0; ii < 4; ii++){
		/* feat_data = single(rand(2, feat_format.feat_ed_col)'); */
		/* 'FisherVectorEncode:59' frame = [feat_data(:,feat_format.x_col),feat_data(:,feat_format.y_col),ones(size(feat_data,1),2)]'; */
		/* 'FisherVectorEncode:60' feat=single(feat_data(:,feat_format.feat_st_col:feat_format.feat_ed_col)'); */
		//i0 = (int32_T)feat_format_feat_st_col - 1;
		//i1 = (int32_T)feat_format_feat_ed_col;
		i0 = range[ii][0]-1;
		i1 = range[ii][1];
		fprintf(stderr, "fv dims range %d %d raw feat range %d %d\n", dims_acc[ii], dims_acc[ii+1], i0, i1);

		/* 'FisherVectorEncode:61' feat = pca_proj * feat; */
		/* 'FisherVectorEncode:62' if strcmp(feat_type,'MFCC') */
		if ( feat_format_spatial == FALSE ) {
			/*  generate "fake" coordinates for MFCC features and don't generate spatial fv */
			/* 'FisherVectorEncode:64' frame = int32([ones(size(feat_data,1),4)]'); */
			encoder_codebook__n_gauss = feat_data->size[0];
			i2 = frame->size[0] * frame->size[1];
			frame->size[0] = 4;
			frame->size[1] = encoder_codebook__n_gauss;
			emxEnsureCapacity((emxArray__common *)frame, i2, (int32_T)sizeof(int32_T));
			loop_ub = encoder_codebook__n_gauss - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				for (encoder_codebook__n_dim = 0; encoder_codebook__n_dim < 4;
						encoder_codebook__n_dim++) {
					frame->data[encoder_codebook__n_dim + frame->size[0] * i2] = 1;
				}
			}
		} else {
			/* 'FisherVectorEncode:65' else */
			/* 'FisherVectorEncode:66' frame = int32([feat_data(:,feat_format.x_col),feat_data(:,feat_format.y_col),single(ones(size(feat_data,1),2))]'); */
			encoder_codebook__n_gauss = feat_data->size[0];
			i2 = r0->size[0] * r0->size[1];
			r0->size[0] = encoder_codebook__n_gauss;
			r0->size[1] = 2;
			emxEnsureCapacity((emxArray__common *)r0, i2, (int32_T)sizeof(real32_T));
			loop_ub = (feat_data->size[0] << 1) - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				r0->data[i2] = 1.0F;
			}

			encoder_codebook__n_gauss = (int32_T)feat_format_x_col;
			i2 = r4->size[0];
			r4->size[0] = feat_data->size[0];
			emxEnsureCapacity((emxArray__common *)r4, i2, (int32_T)sizeof(int32_T));
			loop_ub = feat_data->size[0] - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				r4->data[i2] = 1 + i2;
			}

			i2 = b_feat_data->size[0];
			b_feat_data->size[0] = feat_data->size[0];
			emxEnsureCapacity((emxArray__common *)b_feat_data, i2, (int32_T)sizeof
					(real32_T));
			loop_ub = feat_data->size[0] - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				b_feat_data->data[i2] = feat_data->data[i2 + feat_data->size[0] *
					(encoder_codebook__n_gauss - 1)];
				//fprintf(stderr, "%g %d %d %g\n", b_feat_data->data[i2], feat_data->size[0], encoder_codebook__n_gauss, feat_format_x_col);
			}

			iv2[0] = r4->size[0];
			iv2[1] = 1;
			encoder_codebook__n_gauss = (int32_T)feat_format_y_col;
			i2 = r5->size[0];
			r5->size[0] = feat_data->size[0];
			emxEnsureCapacity((emxArray__common *)r5, i2, (int32_T)sizeof(int32_T));
			loop_ub = feat_data->size[0] - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				r5->data[i2] = 1 + i2;
			}

			i2 = c_feat_data->size[0];
			c_feat_data->size[0] = feat_data->size[0];
			emxEnsureCapacity((emxArray__common *)c_feat_data, i2, (int32_T)sizeof
					(real32_T));
			loop_ub = feat_data->size[0] - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				c_feat_data->data[i2] = feat_data->data[i2 + feat_data->size[0] *
					(encoder_codebook__n_gauss - 1)];
			}

			iv3[0] = r5->size[0];
			iv3[1] = 1;
			i2 = r6->size[0];
			r6->size[0] = feat_data->size[0];
			emxEnsureCapacity((emxArray__common *)r6, i2, (int32_T)sizeof(int32_T));
			loop_ub = feat_data->size[0] - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				r6->data[i2] = 1 + i2;
			}

			encoder_codebook__n_gauss = r6->size[0];
			i2 = d_feat_data->size[0] * d_feat_data->size[1];
			d_feat_data->size[0] = iv3[0];
			d_feat_data->size[1] = iv3[1];
			emxEnsureCapacity((emxArray__common *)d_feat_data, i2, (int32_T)sizeof
					(real32_T));
			loop_ub = iv3[1] - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				b_loop_ub = iv3[0] - 1;
				for (encoder_codebook__n_dim = 0; encoder_codebook__n_dim <= b_loop_ub;
						encoder_codebook__n_dim++) {
					f_feat_data = *c_feat_data;
					f_feat_data.size = (int32_T *)&iv3;
					f_feat_data.numDimensions = 1;
					d_feat_data->data[encoder_codebook__n_dim + d_feat_data->size[0] * i2]
						= f_feat_data.data[encoder_codebook__n_dim + f_feat_data.size[0] *
						i2];
				}
			}

			i2 = frame->size[0] * frame->size[1];
			frame->size[0] = iv2[1] + 3;
			frame->size[1] = iv2[0];
			emxEnsureCapacity((emxArray__common *)frame, i2, (int32_T)sizeof(int32_T));
			loop_ub = iv2[0] - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				b_loop_ub = iv2[1] - 1;
				for (encoder_codebook__n_dim = 0; encoder_codebook__n_dim <= b_loop_ub;
						encoder_codebook__n_dim++) {
					f_feat_data = *b_feat_data;
					f_feat_data.size = (int32_T *)&iv2;
					f_feat_data.numDimensions = 1;
					encoder_alpha = f_feat_data.data[i2 + f_feat_data.size[0] *
						encoder_codebook__n_dim];
					if ((encoder_alpha < 8.388608E+6F) && (encoder_alpha > -8.388608E+6F))
					{
						encoder_alpha = encoder_alpha < 0.0F ? (real32_T)ceil(encoder_alpha
								- 0.5F) : (real32_T)floor(encoder_alpha + 0.5F);
					}

					if (encoder_alpha < 2.14748365E+9F) {
						if (encoder_alpha >= -2.14748365E+9F) {
							i3 = (int32_T)encoder_alpha;
						} else {
							i3 = MIN_int32_T;
						}
					} else if (encoder_alpha >= 2.14748365E+9F) {
						i3 = MAX_int32_T;
					} else {
						i3 = 0;
					}

					frame->data[encoder_codebook__n_dim + frame->size[0] * i2] = i3;
				}
			}

			loop_ub = encoder_codebook__n_gauss - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				encoder_alpha = d_feat_data->data[i2];
				if ((encoder_alpha < 8.388608E+6F) && (encoder_alpha > -8.388608E+6F)) {
					encoder_alpha = encoder_alpha < 0.0F ? (real32_T)ceil(encoder_alpha -
							0.5F) : (real32_T)floor(encoder_alpha + 0.5F);
				}

				if (encoder_alpha < 2.14748365E+9F) {
					if (encoder_alpha >= -2.14748365E+9F) {
						encoder_codebook__n_dim = (int32_T)encoder_alpha;
					} else {
						encoder_codebook__n_dim = MIN_int32_T;
					}
				} else if (encoder_alpha >= 2.14748365E+9F) {
					encoder_codebook__n_dim = MAX_int32_T;
				} else {
					encoder_codebook__n_dim = 0;
				}

				frame->data[iv2[1] + frame->size[0] * i2] = encoder_codebook__n_dim;
			}

			loop_ub = r0->size[0] - 1;
			for (i2 = 0; i2 <= loop_ub; i2++) {
				for (encoder_codebook__n_dim = 0; encoder_codebook__n_dim < 2;
						encoder_codebook__n_dim++) {
					encoder_alpha = r0->data[i2 + r0->size[0] * encoder_codebook__n_dim];
					if ((encoder_alpha < 8.388608E+6F) && (encoder_alpha > -8.388608E+6F))
					{
						encoder_alpha = encoder_alpha < 0.0F ? (real32_T)ceil(encoder_alpha
								- 0.5F) : (real32_T)floor(encoder_alpha + 0.5F);
					}

					if (encoder_alpha < 2.14748365E+9F) {
						if (encoder_alpha >= -2.14748365E+9F) {
							i3 = (int32_T)encoder_alpha;
						} else {
							i3 = MIN_int32_T;
						}
					} else if (encoder_alpha >= 2.14748365E+9F) {
						i3 = MAX_int32_T;
					} else {
						i3 = 0;
					}

					frame->data[((encoder_codebook__n_dim + iv2[1]) + frame->size[0] * i2)
						+ 1] = i3;
				}
			}
		}

		/* 'FisherVectorEncode:68' fv_code = compute(pooler, [width(1); height(1); 3], feat, frame,feat_format.spatial); */
		i2 = e_feat_data->size[0] * e_feat_data->size[1];
		e_feat_data->size[0] = i1 - i0;
		e_feat_data->size[1] = feat_data->size[0];
		emxEnsureCapacity((emxArray__common *)e_feat_data, i2, (int32_T)sizeof
				(real32_T));
		loop_ub = feat_data->size[0] - 1;
		for (i2 = 0; i2 <= loop_ub; i2++) {
			b_loop_ub = (i1 - i0) - 1;
			for (encoder_codebook__n_dim = 0; encoder_codebook__n_dim <= b_loop_ub;
					encoder_codebook__n_dim++) {
				e_feat_data->data[encoder_codebook__n_dim + e_feat_data->size[0] * i2] =
					feat_data->data[i2 + feat_data->size[0] * (i0 +
							encoder_codebook__n_dim)];
			}
		}

		i0 = b_pca_proj->size[0] * b_pca_proj->size[1];
		b_pca_proj->size[0] = pca_proj[ii]->size[0] + xyt_mode;
		b_pca_proj->size[1] = e_feat_data->size[1];
		emxEnsureCapacity((emxArray__common *)b_pca_proj, i0, (int32_T)sizeof
				(real32_T));
		loop_ub = pca_proj[ii]->size[0] - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			b_loop_ub = e_feat_data->size[1] - 1;
			for (i1 = 0; i1 <= b_loop_ub; i1++) {
				b_pca_proj->data[i0 + xyt_mode + b_pca_proj->size[0] * i1] = 0.0F;
				encoder_codebook__n_gauss = pca_proj[ii]->size[1] - 1;
				for (i2 = 0; i2 <= encoder_codebook__n_gauss; i2++) {
					b_pca_proj->data[i0 + xyt_mode + b_pca_proj->size[0] * i1] += (real32_T)
						pca_proj[ii]->data[i0 + pca_proj[ii]->size[0] * i2] * e_feat_data->data[i2 +
						e_feat_data->size[0] * i1];
				}
			}
		}
			
		b_loop_ub = e_feat_data->size[1] - 1;
		for (i1 = 0; i1 <= b_loop_ub; i1++) {
			if( xyt_mode >= 2 ){
				b_pca_proj->data[0 + b_pca_proj->size[0] * i1] = feat_data->data[i1 + 7 * feat_data->size[0]];
				b_pca_proj->data[1 + b_pca_proj->size[0] * i1] = feat_data->data[i1 + 8 * feat_data->size[0]];
			}
			if( xyt_mode == 3 ){
				b_pca_proj->data[2 + b_pca_proj->size[0] * i1] = feat_data->data[i1 + 9 * feat_data->size[0]];
			}
			//fprintf(stderr, "%g %g %g\n", feat_data->data[i1 + 7 * feat_data->size[0]], feat_data->data[i1 + 8 * feat_data->size[0]], feat_data->data[i1 + 9 * feat_data->size[0]]);
		}
		/*
		for(int iii = 0; iii < b_pca_proj->size[0]; iii++){
			fprintf(stderr, "%g\n", b_pca_proj->data[iii]);
		}
		exit(-1);
		*/

		/*
		   for(int ii = 0; ii < frame->size[0]; ii++){
		   for(int jj = 0; jj < frame->size[1]; jj++){
		   fprintf(stderr, "%d ", frame->data[ii + jj * frame->size[0]]);
		   }
		   fprintf(stderr, "\n");
		   }
		 */

		fprintf(stderr, "pca size = (%d %d), (width height) = (%d %d), (num gaussians, feat dim) = (%d, %d)\n", b_pca_proj->size[0], b_pca_proj->size[1], video_width, video_height, t0_encoder__codebook__n_gauss[ii], t0_encoder__codebook__n_dim[ii]);
		compute(t0_subbin_norm_type, pooler_norm_type, pooler_post_norm_type,
				pooling, feat_format_feat_dim, b_expl_temp, pooler_kermap,
				encoder_grad_weights[ii], encoder_grad_means[ii], encoder_grad_variances[ii],
				t0_encoder__codebook__n_gauss[ii], t0_encoder__codebook__n_dim[ii],
				b_pca_proj, frame, feat_format_spatial, fv_code, fhs[ii], video_width, video_height); 
		/* 'FisherVectorEncode:69' fv_code = fv_code'; */
		/* 'FisherVectorEncode:70' [h_idx,w_idx,val] = find(fv_code); */
		i0 = b_fv_code->size[0] * b_fv_code->size[1];
		b_fv_code->size[0] = 1;
		emxEnsureCapacity((emxArray__common *)b_fv_code, i0, (int32_T)sizeof
				(real32_T));
		encoder_codebook__n_gauss = fv_code->size[0];
		i0 = b_fv_code->size[0] * b_fv_code->size[1];
		b_fv_code->size[1] = encoder_codebook__n_gauss;
		emxEnsureCapacity((emxArray__common *)b_fv_code, i0, (int32_T)sizeof
				(real32_T));
		loop_ub = fv_code->size[0] - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			b_fv_code->data[i0] = fv_code->data[i0];
		}

		find(b_fv_code, h_idx, w_idx, val);

		/* hack */
		/* 'FisherVectorEncode:72' val( find(isnan(val)) ) = 0; */
		b_isnan(val, r3);
		b_find(r3, h_idx);
		i0 = r1->size[0] * r1->size[1];
		r1->size[0] = 1;
		r1->size[1] = h_idx->size[1];
		emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(int32_T));
		loop_ub = h_idx->size[0] * h_idx->size[1] - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			r1->data[i0] = (int32_T)h_idx->data[i0];
		}

		loop_ub = r1->size[0] * r1->size[1] - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			val->data[r1->data[i0] - 1] = 0.0F;
		}

		/* 'FisherVectorEncode:73' idx_fv = [w_idx;val]; */
		i0 = idx_fv->size[0] * idx_fv->size[1];
		idx_fv->size[0] = 2;
		idx_fv->size[1] = w_idx->size[1];
		emxEnsureCapacity((emxArray__common *)idx_fv, i0, (int32_T)sizeof(real32_T));
		loop_ub = w_idx->size[1] - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			idx_fv->data[idx_fv->size[0] * i0] = (real32_T)w_idx->data[w_idx->size[0] *
				i0];
		}

		loop_ub = val->size[1] - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			idx_fv->data[1 + idx_fv->size[0] * i0] = val->data[val->size[0] * i0];
		}

		/* 'FisherVectorEncode:74' f = coder.opaque('FILE *', 'NULL'); */
		/* 'FisherVectorEncode:75' f = coder.ceval('fopen', outfile, c_string('w')); */

		/* 'FisherVectorEncode:76' for v=1:size(idx_fv, 1) */
		for (encoder_codebook__n_gauss = 0; encoder_codebook__n_gauss < idx_fv->size[0] * idx_fv->size[1];
				encoder_codebook__n_gauss+=2) {
			/* 'FisherVectorEncode:77' coder.ceval('fprintf', f, c_string('%d:%g '), idx_fv(v, 1), idx_fv(v, 2)); */
			final_vector[ (int)idx_fv->data[encoder_codebook__n_gauss] + dims_acc[ii] - 1 ] = idx_fv->data[encoder_codebook__n_gauss + 1] / 2;
		}
	}
		
	emxFree_real32_T(&fv_code);
	emxFree_real32_T(&val);
	emxFree_real32_T(&idx_fv);
	emxFree_real32_T(&h_idx);
	emxFree_real32_T(&w_idx);
	emxFree_int32_T(&frame);
	emxFree_real32_T(&r0);
	emxFree_int32_T(&r1);
	emxFree_boolean_T(&r3);
	emxFree_real32_T(&b_fv_code);
	emxFree_real32_T(&b_pca_proj);
	emxFree_int32_T(&r4);
	emxFree_real32_T(&b_feat_data);
	emxFree_int32_T(&r5);
	emxFree_real32_T(&c_feat_data);
	emxFree_int32_T(&r6);
	emxFree_real32_T(&d_feat_data);
	emxFree_real32_T(&e_feat_data);
}


/*
 * function FisherVectorEncode(feat_type, pnorm, alpha, pooling, num_gaussians, pca_dim, config_filepath)
 */
void FisherVectorEncode(const char_T feat_type[1024], int spatial, real32_T pnorm, real32_T alpha, int xyt_mode,
		char_T* pooling, char* codebook_pca_path, char_T* output_path, char_T* width_str, char_T* height_str,
		char_T* segx_str, char_T* fps_str)
{
	emxArray_real32_T *codebook_mean;
	emxArray_char_T *expl_temp;
	b_struct_T t0_encoder_;
	boolean_T feat_format_spatial;
	real32_T feat_format_y_col;
	real32_T feat_format_x_col;
	real32_T b_expl_temp;
	real32_T feat_format_feat_ed_col;
	real32_T feat_format_feat_st_col;
	real32_T feat_format_feat_dim;
	int32_T i0;
	int32_T loop_ub;
	emxArray_real32_T *codebook_variance;
	emxArray_real32_T *codebook_coef;
	emxArray_real32_T *pca_proj[4];
	emxArray_real32_T *encoder_codebook__mean;
	emxArray_real32_T *encoder_codebook__variance;
	emxArray_real32_T *encoder_codebook__coef;
	emxArray_real32_T *feat_data;
	int32_T encoder_codebook__n_dim;
	int32_T encoder_codebook__n_gauss;
	real32_T encoder_pnorm;
	real32_T encoder_alpha;
	boolean_T encoder_grad_variances[4];
	boolean_T encoder_grad_means[4];
	boolean_T encoder_grad_weights[4];
	char_T t0_kermap[4];
	char_T t0_pool_type[3];
	char_T t0_post_norm_type[4];
	char_T t0_norm_type[2];
	char_T t0_subbin_norm_type[2];
	int32_T t0_encoder__codebook__n_gauss[4];
	int32_T t0_encoder__codebook__n_dim[4];
	static const char_T cv0[2] = { 'l', '2' };

	emxArray_char_T *pooler_norm_type;
	static const char_T cv1[4] = { 'n', 'o', 'n', 'e' };

	//emxArray_char_T *pooler_pool_type;
	emxArray_char_T *pooler_kermap;
	static const char_T cv2[9] = { 'h', 'e', 'l', 'l', 'i', 'n', 'g', 'e', 'r' };

	emxArray_char_T *pooler_post_norm_type;
	static const char_T cv3[2] = { 'r', '\x00' };

	char_T cv4[1025];
	emxArray_real32_T *r2;
	static const char_T cv5[12] = { '%', 's', ' ', '%', 's', ' ', '%', 'd', ' ',
		'%', 'd', '\x00' };

	char_T cv6[12];
	char_T cv7[1024];
	char_T cv8[1024];
	int32_T iv0[2];
	int32_T iv1[2];
	int32_T i1;
	emxInit_char_T(&expl_temp, 2);
	emxInitStruct_struct_T(&t0_encoder_);

	/* 			  config_filepath, feat_type,... */
	/*                           codebook_filepath, pca_filepath,... */
	/*                           pnorm, alpha,pooling, varargin) */
	/*     %% This script encodes the raw features to the fisher vectors based on pre-trained gmm codebook and pca projections (if provided). */
	/*  inputs: */
	/*    config_filepath: each line is: input_filepath(raw feature) output_filepath(fisher vector) vid_width vid_height */
	/*    feat_type: currently supported: MOSIFT */
	/*    codebook_filepath: the gmm codebook filepath */
	/*    pca_filepath: pca projection filepath */
	/*    pnorm, alpha: the normalization parameters. */
	/* 	pooling: the pooling method: [sum|max]. */
	/* vgg_lib_path = 'vgg_lib'; */
	/* addpath(genpath(vgg_lib_path)); */
	/* util_path = 'matlab'; */
	/* addpath(genpath(util_path)); */
	/* [input_filepaths, output_filepaths, vid_widths, vid_heights] = textread(config_filepath, '%s %s %d %d\n'); */
	/* 'FisherVectorEncode:21' feat_format = FeatFormatParse(feat_type); */

	FeatFormatParse(feat_type, expl_temp, &feat_format_feat_dim,
			&feat_format_feat_st_col, &feat_format_feat_ed_col,
			&b_expl_temp, &feat_format_x_col, &feat_format_y_col,
			&feat_format_spatial);
	if( spatial == 1 ){
		feat_format_spatial = TRUE;
	}else{
		feat_format_spatial = FALSE;
	}

	emxFree_char_T(&expl_temp);
	//emxFree_char_T(&expl_temp);
	feat_format_feat_dim = 0; //this guy is not used either....

	//read codebook
	FILE *code_pca_fp = fopen(codebook_pca_path, "r");
	fisher_handle<float>* fhs[4];
	for(int i = 0; i < 4; i++){
		emxInit_real32_T(&codebook_mean, 2);
		int32_T num_gaussians, pca_dim, gaussian_dim;
		char codebook_path[1024], pca_proj_path[1024];
		fscanf(code_pca_fp, "%s %s\n", codebook_path, pca_proj_path);
		FILE *gaussian_fp = fopen(codebook_path, "r");
		fscanf(gaussian_fp, "%d %d\n", &gaussian_dim, &num_gaussians);
		fprintf(stderr, "pca %d n_gauss %d\n", gaussian_dim, num_gaussians);
		// 'FisherVectorEncode:23' codebook.mean = zeros(pca_dim, num_gaussians); 
		i0 = codebook_mean->size[0] * codebook_mean->size[1];
		codebook_mean->size[0] = gaussian_dim;
		codebook_mean->size[1] = num_gaussians;
		emxEnsureCapacity((emxArray__common *)codebook_mean, i0, (int32_T)sizeof
				(real32_T));
		loop_ub = gaussian_dim * num_gaussians - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			fscanf(gaussian_fp, "%f", &codebook_mean->data[i0]);
		}

		emxInit_real32_T(&codebook_variance, 2);
		fscanf(gaussian_fp, "%d %d\n", &gaussian_dim, &num_gaussians);
		// 'FisherVectorEncode:24' codebook.variance = zeros(pca_dim, num_gaussians); 
		i0 = codebook_variance->size[0] * codebook_variance->size[1];
		codebook_variance->size[0] = gaussian_dim;
		codebook_variance->size[1] = num_gaussians;
		emxEnsureCapacity((emxArray__common *)codebook_variance, i0, (int32_T)sizeof
				(real32_T));
		loop_ub = gaussian_dim * num_gaussians - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			fscanf(gaussian_fp, "%f", &codebook_variance->data[i0]);
		}

		b_emxInit_real32_T(&codebook_coef, 1);
		int garbage;
		fscanf(gaussian_fp, "%d %d\n", &num_gaussians, &garbage);
		// 'FisherVectorEncode:25' codebook.coef = zeros(num_gaussians,1) 
		i0 = codebook_coef->size[0];
		codebook_coef->size[0] = num_gaussians;
		emxEnsureCapacity((emxArray__common *)codebook_coef, i0, (int32_T)sizeof
				(real32_T));
		loop_ub = num_gaussians - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			fscanf(gaussian_fp, "%f", &codebook_coef->data[i0]);
		}
		fclose(gaussian_fp);

		emxInit_real32_T(&pca_proj[i], 2);
		emxInit_real32_T(&encoder_codebook__mean, 2);
		emxInit_real32_T(&encoder_codebook__variance, 2);
		b_emxInit_real32_T(&encoder_codebook__coef, 1);

		/* 'FisherVectorEncode:26' codebook.n_gauss = num_gaussians; */
		/* 'FisherVectorEncode:27' codebook.n_dim = pca_dim; */
		/* 'FisherVectorEncode:28' pca_proj = rand(pca_dim, feat_format.feat_dim); */
		//b_rand(pca_dim, feat_format_feat_dim, pca_proj);

		FILE *pca_proj_fp = fopen(pca_proj_path, "r");
		int ori_num_dim;
		fscanf(pca_proj_fp, "%d %d\n", &pca_dim, &ori_num_dim);
		fprintf(stderr, "pca_dim %d + xyt_mode %d =  gaussian_dim %d\n", pca_dim, xyt_mode, gaussian_dim);
		assert( pca_dim + xyt_mode == gaussian_dim);
		i0 = pca_proj[i]->size[0] * pca_proj[i]->size[1];
		pca_proj[i]->size[0] = pca_dim;
		pca_proj[i]->size[1] = ori_num_dim;
		emxEnsureCapacity((emxArray__common *)pca_proj[i], i0, (int32_T)sizeof
				(real32_T));
		loop_ub = pca_dim * ori_num_dim - 1;
		for (i0 = 0; i0 <= loop_ub; i0++) {
			fscanf(pca_proj_fp, "%f", &pca_proj[i]->data[i0]);
		}
		fclose(pca_proj_fp);

		/* 'FisherVectorEncode:29' encoder = getFKEncoder(codebook); */
		getFKEncoder(codebook_mean, codebook_variance, codebook_coef, num_gaussians,
				gaussian_dim, encoder_codebook__mean, encoder_codebook__variance,
				encoder_codebook__coef, &encoder_grad_weights[i],
				&encoder_grad_means[i], &encoder_grad_variances[i], &encoder_alpha,
				&encoder_pnorm, &encoder_codebook__n_gauss,
				&encoder_codebook__n_dim);
		encoder_alpha = alpha;
		encoder_pnorm = pnorm;

		/* 'FisherVectorEncode:30' encoder.pnorm = single(pnorm); */
		/* 'FisherVectorEncode:31' encoder.alpha = single(alpha); */
		/* 'FisherVectorEncode:32' encoder.grad_weights = false; */
		/* 'FisherVectorEncode:33' encoder.grad_means = true; */
		/* 'FisherVectorEncode:34' encoder.grad_variances = true; */
		/* 'FisherVectorEncode:38' pooler = getSPMPooler(encoder); */
		getSPMPooler(FALSE, TRUE, TRUE, (real32_T)alpha, (real32_T)pnorm,
				encoder_codebook__mean, encoder_codebook__variance,
				encoder_codebook__coef, encoder_codebook__n_gauss,
				encoder_codebook__n_dim, &t0_encoder_, t0_subbin_norm_type,
				t0_norm_type, t0_post_norm_type, t0_pool_type,
				&feat_format_feat_dim, &b_expl_temp, t0_kermap);
		encoder_grad_weights[i] = t0_encoder_.grad_weights;
		encoder_grad_means[i] = t0_encoder_.grad_means;
		encoder_grad_variances[i] = t0_encoder_.grad_variances;
		t0_encoder__codebook__n_gauss[i] = t0_encoder_.codebook_.n_gauss;
		t0_encoder__codebook__n_dim[i] = t0_encoder_.codebook_.n_dim;


		/* 'FisherVectorEncode:35' encoder.fc_ = getFisherEncoder(codebook, encoder); */
		fisher_handle<float>* fh = fisher_init(codebook_mean, codebook_variance, codebook_coef, num_gaussians, gaussian_dim, encoder_grad_weights[i], encoder_grad_means[i], encoder_grad_variances[i], encoder_alpha, encoder_pnorm);
		fhs[i] = fh;

		/* 'FisherVectorEncode:39' pooler.subbin_norm_type = 'l2'; */
		emxFree_real32_T(&encoder_codebook__coef);
		emxFree_real32_T(&encoder_codebook__variance);
		emxFree_real32_T(&encoder_codebook__mean);
		emxFree_real32_T(&codebook_coef);
		emxFree_real32_T(&codebook_variance);
		emxFree_real32_T(&codebook_mean);

	}
	fclose(code_pca_fp);

	for (i0 = 0; i0 < 2; i0++) {
		t0_subbin_norm_type[i0] = cv0[i0];
	}

	emxInit_char_T(&pooler_norm_type, 2);

	/* 'FisherVectorEncode:40' pooler.norm_type = 'none'; */
	i0 = pooler_norm_type->size[0] * pooler_norm_type->size[1];
	pooler_norm_type->size[0] = 1;
	pooler_norm_type->size[1] = 4;
	emxEnsureCapacity((emxArray__common *)pooler_norm_type, i0, (int32_T)sizeof
			(char_T));
	for (i0 = 0; i0 < 4; i0++) {
		pooler_norm_type->data[i0] = cv1[i0];
	}

	//emxInit_char_T(&pooler_pool_type, 2);

	/* 'FisherVectorEncode:41' pooler.pool_type = pooling; */
	/* stupid, not using it
	   i0 = pooler_pool_type->size[0] * pooler_pool_type->size[1];
	   pooler_pool_type->size[0] = 1;
	   pooler_pool_type->size[1] = 1024;
	   emxEnsureCapacity((emxArray__common *)pooler_pool_type, i0, (int32_T)sizeof
	   (char_T));
	   for (i0 = 0; i0 < 1024; i0++) {
	   pooler_pool_type->data[i0] = pooling[i0];
	   }
	 */

	emxInit_char_T(&pooler_kermap, 2);

	/* 'FisherVectorEncode:42' pooler.kermap = 'hellinger'; */
	i0 = pooler_kermap->size[0] * pooler_kermap->size[1];
	pooler_kermap->size[0] = 1;
	pooler_kermap->size[1] = 9;
	emxEnsureCapacity((emxArray__common *)pooler_kermap, i0, (int32_T)sizeof
			(char_T));
	for (i0 = 0; i0 < 9; i0++) {
		pooler_kermap->data[i0] = cv2[i0];
	}

	emxInit_char_T(&pooler_post_norm_type, 2);

	/* 'FisherVectorEncode:43' pooler.post_norm_type = 'l2'; */
	i0 = pooler_post_norm_type->size[0] * pooler_post_norm_type->size[1];
	pooler_post_norm_type->size[0] = 1;
	pooler_post_norm_type->size[1] = 2;
	emxEnsureCapacity((emxArray__common *)pooler_post_norm_type, i0, (int32_T)
			sizeof(char_T));
	for (i0 = 0; i0 < 2; i0++) {
		pooler_post_norm_type->data[i0] = cv0[i0];
	}

	/* 'FisherVectorEncode:46' f_config = coder.opaque('FILE *', 'NULL'); */
	/* 'FisherVectorEncode:47' f_config = coder.ceval('fopen', c_string(config_filepath), c_string('r')); */
	for (i0 = 0; i0 < 2; i0++) {
		t0_norm_type[i0] = cv3[i0];
	}

	//c_string(config_filepath, cv4);
	//f_config = fopen(cv4, t0_norm_type);

	/* [input_filepaths, output_filepaths, vid_widths, vid_heights] = textread(config_filepath, '%s %s %d %d\n'); */
	/* 'FisherVectorEncode:50' while(1) */

	{
		/* 'FisherVectorEncode:51' width = int32( zeros(1,2) ); */
		/* 'FisherVectorEncode:52' height = int32( zeros(1,2) ); */
		/* 'FisherVectorEncode:53' infile = '                                                                                                                                                                                                                              '; */
		/* 'FisherVectorEncode:54' outfile = '                                                                                                                                                                                                                              '; */
		/* 'FisherVectorEncode:55' ret = int32(0); */
		/* 'FisherVectorEncode:56' ret = coder.ceval('fscanf', f_config, c_string('%s %s %d %d'), infile, outfile, width, height); */
		for (i0 = 0; i0 < 12; i0++) {
			cv6[i0] = cv5[i0];
		}

		for (i0 = 0; i0 < 2; i0++) {
			iv0[i0] = 0;
			iv1[i0] = 0;
		}

		char segx_file[1024], a[1024], b[1024];
		double fps;
		strcpy(cv8, output_path);
		strcat(cv8, ".gz");
		ogzstream f(cv8);
		int video_width;
		int video_height;
		sscanf(width_str, "%d", &video_width);
		sscanf(height_str, "%d", &video_height);
		strcpy(segx_file, segx_str);
		sscanf(fps_str, "%lf", &fps);
		std::vector<int> segx_start;
		if( fps < 0 ){ //no segx
			segx_start.push_back(0);
			segx_start.push_back(-1);
		}else{
			FILE *in = fopen(segx_file, "r");
			assert(in != NULL);
			double start, middle, end;
			while( fscanf(in, "%lf\t%lf\t%lf\t%s\t%s\n", &start, &middle, &end, a, b) > 0 ){
				segx_start.push_back((int)(start * fps));
			}
			segx_start.push_back(-1);
			fclose(in);
		}

		/* 'FisherVectorEncode:57' feat_data = single(readfeatsmat(infile, feat_type, '/tmp')'); */
		int shots = segx_start.size();
		for(int ii = 0; ii < shots-1; ii++){
			fprintf(stderr, "part %d/%d, frame %d to %d\n", ii+1, shots-1, segx_start[ii], segx_start[ii+1]);
			emxInit_real32_T(&feat_data, 2);
			emxInit_real32_T(&r2, 2);

			readfeatsmat(r2, segx_start[ii], segx_start[ii+1]);
			i0 = feat_data->size[0] * feat_data->size[1];
			feat_data->size[0] = r2->size[1];
			feat_data->size[1] = r2->size[0];
			emxEnsureCapacity((emxArray__common *)feat_data, i0, (int32_T)sizeof
					(real32_T));
			for (i0 = 0; i0 < r2->size[0]; i0++) {
				loop_ub = r2->size[1] - 1;
				for (i1 = 0; i1 <= loop_ub; i1++) {
					feat_data->data[i1 + feat_data->size[0] * i0] = (real32_T)r2->data[i0 +
						r2->size[0] * i1];
				}
			}

			std::vector<float> final_vector;
			get_fisher(feat_data, final_vector, xyt_mode, pca_proj, fhs, video_width, video_height, 
					encoder_grad_means, encoder_grad_variances, encoder_grad_weights,
					t0_subbin_norm_type, t0_encoder__codebook__n_gauss, t0_encoder__codebook__n_dim,
					pooler_post_norm_type, pooling, pooler_norm_type,
					feat_format_y_col, feat_format_x_col, feat_format_spatial,
					b_expl_temp, pooler_kermap, feat_format_feat_dim
				  );

			int dims = final_vector.size();
			for(int i = 0; i < dims; i++){
				f << i+1 << ":" << final_vector[i] << " ";
			}
			f << std::endl;
			emxFree_real32_T(&feat_data);
			emxFree_real32_T(&r2);
		}
		f.close();
	}
	for(int i = 0; i < 4; i++){
		delete fhs[i];
	}
}

/* End of code generation (FisherVectorEncode.cpp) */

int main(int argc, char* argv[]){
	if( argc != 11 ){
		fprintf(stderr, "usage: %s outspbof width height segx fps spatial(0,1) pnorm alpha xyt_mode(0,2(xy),3(xyt)) codebook_pca_list(codebook_path pca_path)\n", argv[0]);
		return -1;
	}
	float pnorm, alpha;
	int spatial = 0;
	int xyt_mode = 0;
	sscanf(argv[6], "%d", &spatial);
	sscanf(argv[7], "%f", &pnorm);
	sscanf(argv[8], "%f", &alpha);	
	sscanf(argv[9], "%d", &xyt_mode);
	if( xyt_mode != 0 && xyt_mode != 2 && xyt_mode != 3 ){
		fprintf(stderr, "xyt_mode %d unknown, only 0, 2, 3 allowed\n", xyt_mode);
		return 0;
	}
	FisherVectorEncode("TRAJSTAB", spatial, pnorm, alpha, xyt_mode, "sum", argv[10], argv[1], argv[2], argv[3], argv[4], argv[5]);
	fprintf(stderr, "fisher vector program completed\n");
	return 0;
}
