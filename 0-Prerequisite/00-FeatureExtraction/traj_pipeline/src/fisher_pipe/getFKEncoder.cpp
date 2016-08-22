/*
 * getFKEncoder.cpp
 *
 * Code generation for function 'getFKEncoder'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "getFKEncoder.h"
#include "FisherVectorEncode_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * function obj = getFKEncoder(codebook)
 */
void getFKEncoder(const emxArray_real32_T *codebook_mean, const emxArray_real32_T
                  *codebook_variance, const emxArray_real32_T *codebook_coef,
                  int32_T codebook_n_gauss, int32_T codebook_n_dim,
                  emxArray_real32_T *obj_codebook__mean, emxArray_real32_T
                  *obj_codebook__variance, emxArray_real32_T *obj_codebook__coef,
                  boolean_T *obj_grad_weights, boolean_T *obj_grad_means,
                  boolean_T *obj_grad_variances, real32_T *obj_alpha, real32_T
                  *obj_pnorm, int32_T *obj_codebook__n_gauss, int32_T
                  *obj_codebook__n_dim)
{
  int32_T i5;
  int32_T loop_ub;

  /*  set default parameter values */
  /*  "soft" BOW */
  /* 'getFKEncoder:6' obj.grad_weights = false; */
  *obj_grad_weights = FALSE;

  /*  1st order */
  /* 'getFKEncoder:9' obj.grad_means = true; */
  *obj_grad_means = TRUE;

  /*  2nd order */
  /* 'getFKEncoder:12' obj.grad_variances = true; */
  *obj_grad_variances = TRUE;

  /*  power normalization (set to 1 to disable) */
  /* 'getFKEncoder:15' obj.alpha = single(0.5); */
  *obj_alpha = 0.5F;

  /*  norm regularisation (set to 0 to disable) */
  /* 'getFKEncoder:18' obj.pnorm = single(2); */
  *obj_pnorm = 2.0F;

  /*  setup encoder */
  /* 'getFKEncoder:21' obj.codebook_ = codebook; */
  i5 = obj_codebook__mean->size[0] * obj_codebook__mean->size[1];
  obj_codebook__mean->size[0] = codebook_mean->size[0];
  obj_codebook__mean->size[1] = codebook_mean->size[1];
  emxEnsureCapacity((emxArray__common *)obj_codebook__mean, i5, (int32_T)sizeof
                    (real32_T));
  loop_ub = codebook_mean->size[0] * codebook_mean->size[1] - 1;
  for (i5 = 0; i5 <= loop_ub; i5++) {
    obj_codebook__mean->data[i5] = codebook_mean->data[i5];
  }

  i5 = obj_codebook__variance->size[0] * obj_codebook__variance->size[1];
  obj_codebook__variance->size[0] = codebook_variance->size[0];
  obj_codebook__variance->size[1] = codebook_variance->size[1];
  emxEnsureCapacity((emxArray__common *)obj_codebook__variance, i5, (int32_T)
                    sizeof(real32_T));
  loop_ub = codebook_variance->size[0] * codebook_variance->size[1] - 1;
  for (i5 = 0; i5 <= loop_ub; i5++) {
    obj_codebook__variance->data[i5] = codebook_variance->data[i5];
  }

  i5 = obj_codebook__coef->size[0];
  obj_codebook__coef->size[0] = codebook_coef->size[0];
  emxEnsureCapacity((emxArray__common *)obj_codebook__coef, i5, (int32_T)sizeof
                    (real32_T));
  loop_ub = codebook_coef->size[0] - 1;
  for (i5 = 0; i5 <= loop_ub; i5++) {
    obj_codebook__coef->data[i5] = codebook_coef->data[i5];
  }

  *obj_codebook__n_gauss = codebook_n_gauss;
  *obj_codebook__n_dim = codebook_n_dim;

  /* just a place holder */
  /* 'getFKEncoder:24' obja.grad_weights = false; */
  /* 'getFKEncoder:25' obja.grad_means = true; */
  /* 'getFKEncoder:26' obja.grad_variances = true; */
  /* 'getFKEncoder:27' obja.alpha = single(0.5); */
  /* 'getFKEncoder:28' obja.pnorm = single(2); */
  /* 'getFKEncoder:30' obj.fc_ = getFisherEncoder(codebook, obja); */
}

/* End of code generation (getFKEncoder.cpp) */
