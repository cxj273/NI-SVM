/*
 * getSPMPooler.cpp
 *
 * Code generation for function 'getSPMPooler'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "getSPMPooler.h"
#include "FisherVectorEncode_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * function obj = getSPMPooler(encoder)
 */
void getSPMPooler(boolean_T encoder_grad_weights, boolean_T encoder_grad_means,
                  boolean_T encoder_grad_variances, real32_T encoder_alpha,
                  real32_T encoder_pnorm, const emxArray_real32_T
                  *encoder_codebook__mean, const emxArray_real32_T
                  *encoder_codebook__variance, const emxArray_real32_T
                  *encoder_codebook__coef, int32_T encoder_codebook__n_gauss,
                  int32_T encoder_codebook__n_dim, b_struct_T *obj_encoder_,
                  char_T obj_subbin_norm_type[2], char_T obj_norm_type[2],
                  char_T obj_post_norm_type[4], char_T obj_pool_type[3], real32_T *
                  obj_quad_divs, real32_T *obj_horiz_divs, char_T obj_kermap[4])
{
  int32_T i6;
  static const char_T cv28[3] = { 'l', '2', '\0' };

  static const char_T cv29[5] = { 'n', 'o', 'n', 'e', '\0' };

  static const char_T cv30[4] = { 's', 'u', 'm', '\0' };


  /*  set default parameter values */
  /* 'getSPMPooler:4' obj.subbin_norm_type = 'l2'; */
  for (i6 = 0; i6 < 3; i6++) {
    obj_subbin_norm_type[i6] = cv28[i6];

    /* 'getSPMPooler:5' obj.norm_type = 'l2'; */
    obj_norm_type[i6] = cv28[i6];
  }

  /* 'getSPMPooler:6' obj.post_norm_type = 'none'; */
  for (i6 = 0; i6 < 5; i6++) {
    obj_post_norm_type[i6] = cv29[i6];
  }

  /* 'getSPMPooler:7' obj.pool_type = 'sum'; */
  for (i6 = 0; i6 < 4; i6++) {
    obj_pool_type[i6] = cv30[i6];
  }

  /* 'getSPMPooler:8' obj.quad_divs = 2; */
  *obj_quad_divs = 2.0;

  /* 'getSPMPooler:9' obj.horiz_divs = 3; */
  *obj_horiz_divs = 3.0;

  /* 'getSPMPooler:10' obj.kermap = 'none'; */
  for (i6 = 0; i6 < 4; i6++) {
    obj_kermap[i6] = cv29[i6];
  }

  /*  setup encoder */
  /* 'getSPMPooler:13' obj.encoder_ = encoder; */
  //not used....
  obj_encoder_->grad_weights = encoder_grad_weights;
  obj_encoder_->grad_means = encoder_grad_means;
  obj_encoder_->grad_variances = encoder_grad_variances;
  obj_encoder_->alpha = encoder_alpha;
  obj_encoder_->pnorm = encoder_pnorm;
  /*
  emxArray_real32_T *encoder_codebook__mean;
  emxInit_real32_T
  i6 = obj_encoder_->codebook_.mean->size[0] * obj_encoder_->
    codebook_.mean->size[1];
  obj_encoder_->codebook_.mean->size[0] = encoder_codebook__mean->size[0];
  obj_encoder_->codebook_.mean->size[1] = encoder_codebook__mean->size[1];
  emxEnsureCapacity((emxArray__common *)obj_encoder_->codebook_.mean, i6,
                    (int32_T)sizeof(real32_T));
  loop_ub = encoder_codebook__mean->size[0] * encoder_codebook__mean->size[1] -
    1;
  for (i6 = 0; i6 <= loop_ub; i6++) {
    obj_encoder_->codebook_.mean->data[i6] = encoder_codebook__mean->data[i6];
  }

  i6 = obj_encoder_->codebook_.variance->size[0] *
    obj_encoder_->codebook_.variance->size[1];
  obj_encoder_->codebook_.variance->size[0] = encoder_codebook__variance->size[0];
  obj_encoder_->codebook_.variance->size[1] = encoder_codebook__variance->size[1];
  emxEnsureCapacity((emxArray__common *)obj_encoder_->codebook_.variance, i6,
                    (int32_T)sizeof(real32_T));
  loop_ub = encoder_codebook__variance->size[0] *
    encoder_codebook__variance->size[1] - 1;
  for (i6 = 0; i6 <= loop_ub; i6++) {
    obj_encoder_->codebook_.variance->data[i6] =
      encoder_codebook__variance->data[i6];
  }

  i6 = obj_encoder_->codebook_.coef->size[0];
  obj_encoder_->codebook_.coef->size[0] = encoder_codebook__coef->size[0];
  emxEnsureCapacity((emxArray__common *)obj_encoder_->codebook_.coef, i6,
                    (int32_T)sizeof(real32_T));
  loop_ub = encoder_codebook__coef->size[0] - 1;
  for (i6 = 0; i6 <= loop_ub; i6++) {
    obj_encoder_->codebook_.coef->data[i6] = encoder_codebook__coef->data[i6];
  }
  */

  obj_encoder_->codebook_.n_gauss = encoder_codebook__n_gauss;
  obj_encoder_->codebook_.n_dim = encoder_codebook__n_dim;
}

/* End of code generation (getSPMPooler.cpp) */
