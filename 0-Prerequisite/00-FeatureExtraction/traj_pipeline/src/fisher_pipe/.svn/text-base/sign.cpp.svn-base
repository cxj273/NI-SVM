/*
 * sign.cpp
 *
 * Code generation for function 'sign'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "sign.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void eml_scalar_sign(real32_T *x);

/* Function Definitions */

/*
 *
 */
static void eml_scalar_sign(real32_T *x)
{
  if ((real_T)*x > 0.0) {
    *x = 1.0F;
  } else if ((real_T)*x < 0.0) {
    *x = -1.0F;
  } else {
    if ((real_T)*x == 0.0) {
      *x = 0.0F;
    }
  }
}

/*
 *
 */
void b_sign(emxArray_real32_T *x)
{
  int32_T loop_ub;
  uint32_T k;
  loop_ub = x->size[0];
  for (k = 1U; k <= (uint32_T)loop_ub; k++) {
    eml_scalar_sign(&x->data[(int32_T)k - 1]);
  }
}

/* End of code generation (sign.cpp) */
