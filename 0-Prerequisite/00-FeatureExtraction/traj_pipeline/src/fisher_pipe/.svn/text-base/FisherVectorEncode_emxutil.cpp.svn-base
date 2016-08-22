/*
 * FisherVectorEncode_emxutil.cpp
 *
 * Code generation for function 'FisherVectorEncode_emxutil'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "FisherVectorEncode_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_emxInitStruct_struct_T(struct_T *pStruct);

/* Function Definitions */
static void b_emxInitStruct_struct_T(struct_T *pStruct)
{
  emxInit_real_T(&pStruct->mean, 2);
  emxInit_real_T(&pStruct->variance, 2);
  b_emxInit_real_T(&pStruct->coef, 1);
}

void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

void b_emxInit_real32_T(emxArray_real32_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real32_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_real32_T *)malloc(sizeof(emxArray_real32_T));
  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel, int32_T
  elementSize)
{
  int32_T newNumel;
  int32_T loop_ub;
  int32_T i;
  void *newData;
  newNumel = 1;
  loop_ub = emxArray->numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    loop_ub = emxArray->allocatedSize;
    if (loop_ub < 16) {
      loop_ub = 16;
    }

    while (loop_ub < newNumel) {
      loop_ub <<= 1;
    }

    newData = calloc((uint32_T)loop_ub, (uint32_T)elementSize);
    if( newData == NULL ){
	fprintf(stderr, "allocation of %u * %u failed\n", (uint32_T)loop_ub, (uint32_T)elementSize);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = loop_ub;
    emxArray->canFreeData = TRUE;
  }
}

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_real32_T(emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if ((*pEmxArray)->canFreeData) {
      free((void *)(*pEmxArray)->data);
    }

    free((void *)(*pEmxArray)->size);
    free((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxInitStruct_struct_T(b_struct_T *pStruct)
{
  b_emxInitStruct_struct_T(&pStruct->codebook_);
}

void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T numDimensions)
{
  emxArray_boolean_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_char_T(emxArray_char_T **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_char_T *)malloc(sizeof(emxArray_char_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real32_T(emxArray_real32_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real32_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_real32_T *)malloc(sizeof(emxArray_real32_T));
  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  int32_T loop_ub;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = TRUE;
  loop_ub = numDimensions - 1;
  for (i = 0; i <= loop_ub; i++) {
    emxArray->size[i] = 0;
  }
}

/* End of code generation (FisherVectorEncode_emxutil.cpp) */
