/*
 * power.cpp
 *
 * Code generation for function 'power'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "power.h"
#include "FisherVectorEncode_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_eml_scalexp_alloc(const emxArray_real32_T *varargin_1,
  emxArray_real32_T *z);
static real_T rt_powd_snf(real_T u0, real_T u1);
static real32_T rt_powf_snf(real32_T u0, real32_T u1);

/* Function Definitions */

/*
 *
 */
static void b_eml_scalexp_alloc(const emxArray_real32_T *varargin_1,
  emxArray_real32_T *z)
{
  int32_T i14;
  uint32_T uv1[2];
  for (i14 = 0; i14 < 2; i14++) {
    uv1[i14] = (uint32_T)varargin_1->size[i14];
  }

  i14 = z->size[0] * z->size[1];
  z->size[0] = (int32_T)uv1[0];
  z->size[1] = (int32_T)uv1[1];
  emxEnsureCapacity((emxArray__common *)z, i14, (int32_T)sizeof(real32_T));
}

static real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T d3;
  real_T d4;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d3 = fabs(u0);
    d4 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d3 == 1.0) {
        y = rtNaN;
      } else if (d3 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d4 == 0.0) {
      y = 1.0;
    } else if (d4 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T f0;
  real32_T f1;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = ((real32_T)rtNaN);
  } else {
    f0 = (real32_T)fabs(u0);
    f1 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (f0 == 1.0F) {
        y = ((real32_T)rtNaN);
      } else if (f0 > 1.0F) {
        if (u1 > 0.0F) {
          y = ((real32_T)rtInf);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = ((real32_T)rtInf);
      }
    } else if (f1 == 0.0F) {
      y = 1.0F;
    } else if (f1 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = ((real32_T)rtNaN);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/*
 *
 */
void b_power(const emxArray_real32_T *a, emxArray_real32_T *y)
{
  int32_T loop_ub;
  uint32_T k;
  b_eml_scalexp_alloc(a, y);
  loop_ub = y->size[0] * y->size[1];
  for (k = 1U; k <= (uint32_T)loop_ub; k++) {
    y->data[(int32_T)k - 1] = rt_powf_snf(a->data[(int32_T)k - 1], 2.0F);
  }
}

/*
 *
 */
real_T power(real_T a, real_T b)
{
  return rt_powd_snf(a, b);
}

/* End of code generation (power.cpp) */
