/*
 * FisherVectorEncode_emxutil.h
 *
 * Code generation for function 'FisherVectorEncode_emxutil'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

#ifndef __FISHERVECTORENCODE_EMXUTIL_H__
#define __FISHERVECTORENCODE_EMXUTIL_H__
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
extern void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
extern void b_emxInit_real32_T(emxArray_real32_T **pEmxArray, int32_T numDimensions);
extern void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
extern void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel, int32_T elementSize);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_char_T(emxArray_char_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real32_T(emxArray_real32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInitStruct_struct_T(b_struct_T *pStruct);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T numDimensions);
extern void emxInit_char_T(emxArray_char_T **pEmxArray, int32_T numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
extern void emxInit_real32_T(emxArray_real32_T **pEmxArray, int32_T numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
#endif
/* End of code generation (FisherVectorEncode_emxutil.h) */
