/*
 * compute.h
 *
 * Code generation for function 'compute'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

#ifndef __COMPUTE_H__
#define __COMPUTE_H__
/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "fisher_handle.h"

#include "rtwtypes.h"
#include "FisherVectorEncode_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void compute(const char_T obj_subbin_norm_type[2], const emxArray_char_T *obj_norm_type, const emxArray_char_T *obj_post_norm_type, char *obj_pool_type, real_T obj_quad_divs, real_T obj_horiz_divs, const emxArray_char_T *obj_kermap, boolean_T obj_encoder__grad_weights, boolean_T obj_encoder__grad_means, boolean_T obj_encoder__grad_variances, int32_T obj_encoder__codebook__n_gauss, int32_T obj_encoder__codebook__n_dim, const emxArray_real32_T *feats, const emxArray_int32_T *frames, boolean_T is_spatial, emxArray_real32_T *pcode, fisher_handle<float>* fh, int video_width, int video_height);
#endif
/* End of code generation (compute.h) */
