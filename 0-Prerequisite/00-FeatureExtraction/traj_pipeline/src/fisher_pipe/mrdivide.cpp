/*
 * mrdivide.cpp
 *
 * Code generation for function 'mrdivide'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "FisherVectorEncode_emxutil.h"
#include "mrdivide.h"
#include "rdivide.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 *
 */
int32_T b_mrdivide(int32_T A, real_T B)
{
  return b_rdivide(A, B);
}

/*
 *
 */
void c_mrdivide(const emxArray_int32_T *A, int32_T B, emxArray_int32_T *y)
{
  c_rdivide(A, B, y);
}

void eml_scalexp_alloc(const emxArray_int32_T *varargin_1,
  emxArray_int32_T *z)
{
  int32_T i10;
  uint32_T uv0[2];
  for (i10 = 0; i10 < 2; i10++) {
    uv0[i10] = (uint32_T)varargin_1->size[i10];
  }

  i10 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)z, i10, (int32_T)sizeof(int32_T));
}

void c_mrdivide_ceil(const emxArray_int32_T *x, real_T y, emxArray_int32_T *z)
{
  uint32_T k;
  int32_T loop_ub;
  eml_scalexp_alloc(x, z);
  loop_ub = z->size[1];
  for (k = 1U; k <= (uint32_T)loop_ub; k++) {
    z->data[(int32_T)k - 1] = (int32_T)ceil( (double)x -> data[(int32_T)k - 1] / y);
  }
}

/*
 *
 */
void d_mrdivide(const emxArray_real32_T *A, real32_T B, emxArray_real32_T *y)
{
  e_rdivide(A, B, y);
}

/*
 *
 */
real_T mrdivide(real_T A, real_T B)
{
  return rdivide(A, B);
}

/* End of code generation (mrdivide.cpp) */
