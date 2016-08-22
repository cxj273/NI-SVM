/*
 * rdivide.h
 *
 * Code generation for function 'rdivide'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

#ifndef __RDIVIDE_H__
#define __RDIVIDE_H__
/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "FisherVectorEncode_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern int32_T b_rdivide(int32_T x, real_T y);
extern void c_rdivide(const emxArray_int32_T *x, int32_T y, emxArray_int32_T *z);
extern void d_rdivide(real_T x, const emxArray_real32_T *y, emxArray_real32_T *z);
extern void e_rdivide(const emxArray_real32_T *x, real32_T y, emxArray_real32_T *z);
extern real_T rdivide(real_T x, real_T y);
#endif
/* End of code generation (rdivide.h) */
