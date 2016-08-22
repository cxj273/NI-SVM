/*
 * FisherVectorEncode_types.h
 *
 * Code generation for function 'FisherVectorEncode'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

#ifndef __FISHERVECTORENCODE_TYPES_H__
#define __FISHERVECTORENCODE_TYPES_H__

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
typedef struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_real_T;
#endif
typedef struct
{
    emxArray_real_T *mean;
    emxArray_real_T *variance;
    emxArray_real_T *coef;
    int32_T n_gauss;
    int32_T n_dim;
} struct_T;
typedef struct
{
    boolean_T grad_weights;
    boolean_T grad_means;
    boolean_T grad_variances;
    real32_T alpha;
    real32_T pnorm;
    struct_T codebook_;
} b_struct_T;
#ifndef struct_emxArray__common
#define struct_emxArray__common
typedef struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray__common;
#endif
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
typedef struct emxArray_boolean_T
{
    boolean_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_boolean_T;
#endif
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
typedef struct emxArray_char_T
{
    char_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_char_T;
#endif
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
typedef struct emxArray_int32_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_int32_T;
#endif
#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T
typedef struct emxArray_real32_T
{
    real32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_real32_T;
#endif

#endif
/* End of code generation (FisherVectorEncode_types.h) */
