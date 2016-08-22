/*
 * nnz.cpp
 *
 * Code generation for function 'nnz'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "nnz.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 *
 */
real_T nnz(const emxArray_boolean_T *s)
{
  int32_T j;
  uint32_T k;
  j = 0;
  for (k = 1U; k <= (uint32_T)s->size[1]; k++) {
    if (s->data[(int32_T)k - 1]) {
      j++;
    }
  }

  return (real_T)j;
}

/* End of code generation (nnz.cpp) */
