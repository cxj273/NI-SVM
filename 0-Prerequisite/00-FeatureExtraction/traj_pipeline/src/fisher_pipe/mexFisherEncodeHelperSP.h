#ifndef MEXFISHERENCODEHELPERSP_H
#define MEXFISHERENCODEHELPERSP_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "FisherVectorEncode_types.h"

fisher_handle<float>* fisher_init(const emxArray_real32_T* codebook_mean, const emxArray_real32_T* codebook_variance, const emxArray_real32_T* codebook_coef, int32_T num_gaussians, int32_T pca_dim, boolean_T encoder_grad_weights, boolean_T encoder_grad_means, boolean_T encoder_grad_variances, real32_T encoder_alpha, real32_T encoder_pnorm);

void fisher_encode(fisher_handle<float> *fisher_encoder, emxArray_real32_T* x, emxArray_real32_T* fv, int n_gauss, int n_dim );

#endif
