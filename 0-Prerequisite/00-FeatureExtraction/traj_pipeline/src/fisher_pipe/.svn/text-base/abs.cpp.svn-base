/*
 * abs.cpp
 *
 * Code generation for function 'abs'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "abs.h"
#include "FisherVectorEncode_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static real32_T eml_scalar_abs(real32_T x);

/* Function Definitions */

/*
 *
 */
static real32_T eml_scalar_abs(real32_T x)
{
  return (real32_T)fabs(x);
}

/*
 *
 */
real32_T b_abs(real32_T x)
{
  return eml_scalar_abs(x);
}

/*
 *
 */
void c_abs(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  uint32_T unnamed_idx_0;
  int32_T i19;
  unnamed_idx_0 = (uint32_T)x->size[0];
  i19 = y->size[0];
  y->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)y, i19, (int32_T)sizeof(real32_T));
  for (unnamed_idx_0 = 1U; unnamed_idx_0 <= (uint32_T)x->size[0]; unnamed_idx_0
       ++) {
    y->data[(int32_T)unnamed_idx_0 - 1] = eml_scalar_abs(x->data[(int32_T)
      unnamed_idx_0 - 1]);
  }
}

/* End of code generation (abs.cpp) */
