/*
 * norm.cpp
 *
 * Code generation for function 'norm'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "norm.h"
#include "abs.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static real32_T b_genpnorm(const emxArray_real32_T *x);
static real32_T eml_blas_xnrm2(real_T n, const emxArray_real32_T *x);
static real32_T eml_refblas_xnrm2(real_T n, const emxArray_real32_T *x);
static real32_T eml_xnrm2(real_T n, const emxArray_real32_T *x);
static real32_T genpnorm(const emxArray_real32_T *x);

/* Function Definitions */

/*
 *
 */
static real32_T b_genpnorm(const emxArray_real32_T *x)
{
  real32_T y;
  uint32_T k;
  y = 0.0F;
  for (k = 1U; k <= (uint32_T)x->size[0]; k++) {
    y += b_abs(x->data[(int32_T)k - 1]);
  }

  return y;
}

/*
 *
 */
static real32_T eml_blas_xnrm2(real_T n, const emxArray_real32_T *x)
{
  return eml_refblas_xnrm2(n, x);
}

/*
 *
 */
static real32_T eml_refblas_xnrm2(real_T n, const emxArray_real32_T *x)
{
  real32_T y;
  real32_T scale;
  boolean_T firstNonZero;
  real_T d2;
  int32_T kend;
  int32_T k;
  real32_T absxk;
  real32_T t;
  y = 0.0F;
  if (n < 1.0) {
  } else if (n == 1.0) {
    y = b_abs(x->data[0]);
  } else {
    scale = 0.0F;
    firstNonZero = TRUE;
    d2 = n;
    d2 = floor(d2 + 0.5);
    if (d2 < 2.147483648E+9) {
      kend = (int32_T)d2;
    } else if (d2 >= 2.147483648E+9) {
      kend = MAX_int32_T;
    } else {
      kend = 0;
    }

    for (k = 0; k + 1 <= kend; k++) {
      if (x->data[k] != 0.0F) {
        absxk = b_abs(x->data[k]);
        if (firstNonZero) {
          scale = absxk;
          y = 1.0F;
          firstNonZero = FALSE;
        } else if (scale < absxk) {
          t = scale / absxk;
          y = 1.0F + y * t * t;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }
    }

    y = scale * (real32_T)sqrt(y);
  }

  return y;
}

/*
 *
 */
static real32_T eml_xnrm2(real_T n, const emxArray_real32_T *x)
{
  return eml_blas_xnrm2(n, x);
}

/*
 *
 */
static real32_T genpnorm(const emxArray_real32_T *x)
{
  return eml_xnrm2((real_T)x->size[0], x);
}

/*
 *
 */
real32_T b_norm(const emxArray_real32_T *x)
{
  return b_genpnorm(x);
}

/*
 *
 */
real32_T norm(const emxArray_real32_T *x)
{
  return genpnorm(x);
}

/* End of code generation (norm.cpp) */
