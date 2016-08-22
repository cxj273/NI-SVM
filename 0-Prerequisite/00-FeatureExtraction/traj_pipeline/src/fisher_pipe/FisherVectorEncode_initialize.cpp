/*
 * FisherVectorEncode_initialize.cpp
 *
 * Code generation for function 'FisherVectorEncode_initialize'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "FisherVectorEncode_initialize.h"
#include "FisherVectorEncode_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void FisherVectorEncode_initialize(void)
{
  rt_InitInfAndNaN(8U);
  twister_state_not_empty = FALSE;
  method = 2;
  v4_state = 1144108930U;
}

/* End of code generation (FisherVectorEncode_initialize.cpp) */
