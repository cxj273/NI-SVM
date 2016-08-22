/*
 * isequal.cpp
 *
 * Code generation for function 'isequal'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "isequal.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static boolean_T same_size(const emxArray_char_T *x1);

/* Function Definitions */

/*
 *
 */
static boolean_T same_size(const emxArray_char_T *x1)
{
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i18;
  p = FALSE;
  k = 0;
  do {
    exitg1 = 0U;
    if (k + 1 <= 2) {
      i18 = x1->size[k];
      if (i18 != (int8_T)(1 + (int8_T)(3 * (int8_T)k))) {
        exitg1 = 1U;
      } else {
        k++;
      }
    } else {
      p = TRUE;
      exitg1 = 1U;
    }
  } while (exitg1 == 0U);

  return p;
}

/*
 *
 */
boolean_T isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  static const char_T cv37[4] = { 'n', 'o', 'n', 'e' };

  p = FALSE;
  if (same_size(varargin_1)) {
    b_p = TRUE;
  } else {
    b_p = FALSE;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (k + 1 <= varargin_1->size[1])) {
      if (!(varargin_1->data[k] == cv37[k])) {
        b_p = FALSE;
        exitg1 = 1U;
      } else {
        k++;
      }
    }
  }

  if (!b_p) {
  } else {
    p = TRUE;
  }

  return p;
}

/* End of code generation (isequal.cpp) */
