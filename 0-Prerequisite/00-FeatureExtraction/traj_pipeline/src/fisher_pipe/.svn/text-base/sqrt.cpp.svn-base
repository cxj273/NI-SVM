/*
 * sqrt.cpp
 *
 * Code generation for function 'sqrt'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "sqrt.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void eml_scalar_sqrt(real32_T *x);

/* Function Definitions */

/*
 *
 */
static void eml_scalar_sqrt(real32_T *x)
{
  *x = (real32_T)sqrt(*x);
}

/*
 *
 */
void b_sqrt(emxArray_real32_T *x)
{
  int32_T loop_ub;
  uint32_T k;
  loop_ub = x->size[1];
  for (k = 1U; k <= (uint32_T)loop_ub; k++) {
    eml_scalar_sqrt(&x->data[(int32_T)k - 1]);
  }
}

/*
 *
 */
void c_sqrt(emxArray_real32_T *x)
{
  int32_T loop_ub;
  uint32_T k;
  loop_ub = x->size[0];
  for (k = 1U; k <= (uint32_T)loop_ub; k++) {
    eml_scalar_sqrt(&x->data[(int32_T)k - 1]);
  }
}

/* End of code generation (sqrt.cpp) */
