/*
 * isnan.cpp
 *
 * Code generation for function 'isnan'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "isnan.h"
#include "FisherVectorEncode_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 *
 */
void b_isnan(const emxArray_real32_T *x, emxArray_boolean_T *b)
{
  int32_T i13;
  int32_T loop_ub;
  i13 = b->size[0] * b->size[1];
  b->size[0] = x->size[0];
  b->size[1] = x->size[1];
  emxEnsureCapacity((emxArray__common *)b, i13, (int32_T)sizeof(boolean_T));
  loop_ub = x->size[0] * x->size[1] - 1;
  for (i13 = 0; i13 <= loop_ub; i13++) {
    b->data[i13] = rtIsNaNF(x->data[i13]);
  }
}

/*
 *
 */
boolean_T c_isnan(real32_T x)
{
  return rtIsNaNF(x);
}

/* End of code generation (isnan.cpp) */
