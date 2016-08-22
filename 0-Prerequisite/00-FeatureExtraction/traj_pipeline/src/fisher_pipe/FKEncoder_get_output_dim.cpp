/*
 * FKEncoder_get_output_dim.cpp
 *
 * Code generation for function 'FKEncoder_get_output_dim'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "FKEncoder_get_output_dim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * function dim = FKEncoder_get_output_dim(obj)
 */
int32_T FKEncoder_get_output_dim(boolean_T obj_grad_weights, boolean_T
  obj_grad_means, boolean_T obj_grad_variances, int32_T obj_codebook__n_gauss,
  int32_T obj_codebook__n_dim)
{
  int32_T dim;
  int64_T i8;

  /* 'FKEncoder_get_output_dim:3' dim = int32(0); */
  dim = 0;

  /* 'FKEncoder_get_output_dim:5' if obj.grad_weights */
  if (obj_grad_weights) {
    /* 'FKEncoder_get_output_dim:6' dim = dim + obj.codebook_.n_gauss; */
    dim = obj_codebook__n_gauss;
  }

  /* 'FKEncoder_get_output_dim:9' if obj.grad_means */
  if (obj_grad_means) {
    /* 'FKEncoder_get_output_dim:10' dim = dim + obj.codebook_.n_gauss*obj.codebook_.n_dim; */
    i8 = (int64_T)obj_codebook__n_gauss * (int64_T)obj_codebook__n_dim;
    if (i8 > 2147483647L) {
      i8 = 2147483647L;
    } else {
      if (i8 <= -2147483648L) {
        i8 = -2147483648L;
      }
    }

    i8 = (int64_T)dim + (int64_T)(int32_T)i8;
    if (i8 > 2147483647L) {
      i8 = 2147483647L;
    } else {
      if (i8 <= -2147483648L) {
        i8 = -2147483648L;
      }
    }

    dim = (int32_T)i8;
  }

  /* 'FKEncoder_get_output_dim:13' if obj.grad_variances */
  if (obj_grad_variances) {
    /* 'FKEncoder_get_output_dim:14' dim = dim + obj.codebook_.n_gauss*obj.codebook_.n_dim; */
    i8 = (int64_T)obj_codebook__n_gauss * (int64_T)obj_codebook__n_dim;
    if (i8 > 2147483647L) {
      i8 = 2147483647L;
    } else {
      if (i8 <= -2147483648L) {
        i8 = -2147483648L;
      }
    }

    i8 = (int64_T)dim + (int64_T)(int32_T)i8;
    if (i8 > 2147483647L) {
      i8 = 2147483647L;
    } else {
      if (i8 <= -2147483648L) {
        i8 = -2147483648L;
      }
    }

    dim = (int32_T)i8;
  }

  return dim;
}

/* End of code generation (FKEncoder_get_output_dim.cpp) */
