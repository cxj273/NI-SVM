/*
 * find.cpp
 *
 * Code generation for function 'find'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "find.h"
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
void b_find(const emxArray_boolean_T *x, emxArray_real32_T *i)
{
  int32_T nx;
  int32_T idx;
  int32_T i21;
  uint32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  emxArray_int32_T *r18;
  emxArray_real32_T *b_i;
  int32_T iv8[2];
  int32_T i22;
  emxArray_int32_T r19;
  nx = x->size[1];
  idx = 0;
  i21 = i->size[0] * i->size[1];
  i->size[0] = 1;
  i->size[1] = nx;
  emxEnsureCapacity((emxArray__common *)i, i21, (int32_T)sizeof(real32_T));
  ii = 1U;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (ii <= (uint32_T)nx)) {
    guard1 = FALSE;
    if (x->data[(int32_T)ii - 1]) {
      idx++;
      i->data[idx - 1] = (real32_T)ii;
      if (idx >= nx) {
        exitg1 = 1U;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      ii++;
    }
  }

  if (nx == 1) {
    if (idx == 0) {
      i21 = i->size[0] * i->size[1];
      i->size[0] = 1;
      i->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)i, i21, (int32_T)sizeof(real32_T));
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    b_emxInit_int32_T(&r18, 1);
    i21 = r18->size[0];
    r18->size[0] = idx;
    emxEnsureCapacity((emxArray__common *)r18, i21, (int32_T)sizeof(int32_T));
    nx = idx - 1;
    for (i21 = 0; i21 <= nx; i21++) {
      r18->data[i21] = 1 + i21;
    }

    emxInit_real32_T(&b_i, 2);
    iv8[0] = 1;
    iv8[1] = r18->size[0];
    i21 = b_i->size[0] * b_i->size[1];
    b_i->size[0] = iv8[0];
    b_i->size[1] = iv8[1];
    emxEnsureCapacity((emxArray__common *)b_i, i21, (int32_T)sizeof(real32_T));
    nx = iv8[1] - 1;
    for (i21 = 0; i21 <= nx; i21++) {
      idx = iv8[0] - 1;
      for (i22 = 0; i22 <= idx; i22++) {
        r19 = *r18;
        r19.size = (int32_T *)&iv8;
        r19.numDimensions = 1;
        b_i->data[i22 + b_i->size[0] * i21] = i->data[r19.data[i22 + r19.size[0]
          * i21] - 1];
      }
    }

    emxFree_int32_T(&r18);
    i21 = i->size[0] * i->size[1];
    i->size[0] = 1;
    i->size[1] = b_i->size[1];
    emxEnsureCapacity((emxArray__common *)i, i21, (int32_T)sizeof(real32_T));
    nx = b_i->size[1] - 1;
    for (i21 = 0; i21 <= nx; i21++) {
      i->data[i->size[0] * i21] = b_i->data[b_i->size[0] * i21];
    }

    emxFree_real32_T(&b_i);
  }
}

/*
 *
 */
void find(const emxArray_real32_T *x, emxArray_real32_T *i, emxArray_real32_T *j,
          emxArray_real32_T *v)
{
  int32_T nx;
  int32_T idx;
  int32_T i20;
  int32_T n;
  uint32_T jj;
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  emxArray_int32_T *r14;
  emxArray_real32_T *b_i;
  int32_T iv5[2];
  int32_T loop_ub;
  emxArray_int32_T r15;
  emxArray_int32_T *r16;
  emxArray_real32_T *b_j;
  int32_T iv6[2];
  emxArray_int32_T *r17;
  emxArray_real32_T *b_v;
  int32_T iv7[2];
  nx = x->size[1];
  idx = 0;
  i20 = i->size[0] * i->size[1];
  i->size[0] = 1;
  i->size[1] = nx;
  emxEnsureCapacity((emxArray__common *)i, i20, (int32_T)sizeof(real32_T));
  i20 = j->size[0] * j->size[1];
  j->size[0] = 1;
  j->size[1] = nx;
  emxEnsureCapacity((emxArray__common *)j, i20, (int32_T)sizeof(real32_T));
  i20 = v->size[0] * v->size[1];
  v->size[0] = 1;
  v->size[1] = (int32_T)(uint32_T)nx;
  emxEnsureCapacity((emxArray__common *)v, i20, (int32_T)sizeof(real32_T));
  n = x->size[1];
  if (nx == 0) {
    i20 = i->size[0] * i->size[1];
    i->size[0] = 1;
    i->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)i, i20, (int32_T)sizeof(real32_T));
    i20 = j->size[0] * j->size[1];
    j->size[0] = 1;
    j->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)j, i20, (int32_T)sizeof(real32_T));
    i20 = v->size[0] * v->size[1];
    v->size[0] = 1;
    v->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)v, i20, (int32_T)sizeof(real32_T));
  } else {
    jj = 1U;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (jj <= (uint32_T)n)) {
      guard1 = FALSE;
      if (x->data[x->size[0] * ((int32_T)jj - 1)] != 0.0F) {
        idx++;
        i->data[idx - 1] = 1.0;
        j->data[idx - 1] = (real32_T)jj;
        v->data[idx - 1] = x->data[x->size[0] * ((int32_T)jj - 1)];
        if (idx >= nx) {
          exitg1 = 1U;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        jj++;
      }
    }

    if (nx == 1) {
      if (idx == 0) {
        i20 = i->size[0] * i->size[1];
        i->size[0] = 1;
        i->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)i, i20, (int32_T)sizeof(real32_T));
        i20 = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)j, i20, (int32_T)sizeof(real32_T));
        i20 = v->size[0] * v->size[1];
        v->size[0] = 1;
        v->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)v, i20, (int32_T)sizeof(real32_T));
      }
    } else {
      if (1 > idx) {
        i20 = 0;
      } else {
        i20 = idx;
      }

      b_emxInit_int32_T(&r14, 1);
      n = r14->size[0];
      r14->size[0] = i20;
      emxEnsureCapacity((emxArray__common *)r14, n, (int32_T)sizeof(int32_T));
      nx = i20 - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        r14->data[i20] = 1 + i20;
      }

      emxInit_real32_T(&b_i, 2);
      iv5[0] = 1;
      iv5[1] = r14->size[0];
      i20 = b_i->size[0] * b_i->size[1];
      b_i->size[0] = iv5[0];
      b_i->size[1] = iv5[1];
      emxEnsureCapacity((emxArray__common *)b_i, i20, (int32_T)sizeof(real32_T));
      nx = iv5[1] - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        loop_ub = iv5[0] - 1;
        for (n = 0; n <= loop_ub; n++) {
          r15 = *r14;
          r15.size = (int32_T *)&iv5;
          r15.numDimensions = 1;
          b_i->data[n + b_i->size[0] * i20] = i->data[r15.data[n + r15.size[0] *
            i20] - 1];
        }
      }

      emxFree_int32_T(&r14);
      i20 = i->size[0] * i->size[1];
      i->size[0] = 1;
      i->size[1] = b_i->size[1];
      emxEnsureCapacity((emxArray__common *)i, i20, (int32_T)sizeof(real32_T));
      nx = b_i->size[1] - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        i->data[i->size[0] * i20] = b_i->data[b_i->size[0] * i20];
      }

      emxFree_real32_T(&b_i);
      if (1 > idx) {
        i20 = 0;
      } else {
        i20 = idx;
      }

      b_emxInit_int32_T(&r16, 1);
      n = r16->size[0];
      r16->size[0] = i20;
      emxEnsureCapacity((emxArray__common *)r16, n, (int32_T)sizeof(int32_T));
      nx = i20 - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        r16->data[i20] = 1 + i20;
      }

      emxInit_real32_T(&b_j, 2);
      iv6[0] = 1;
      iv6[1] = r16->size[0];
      i20 = b_j->size[0] * b_j->size[1];
      b_j->size[0] = iv6[0];
      b_j->size[1] = iv6[1];
      emxEnsureCapacity((emxArray__common *)b_j, i20, (int32_T)sizeof(real32_T));
      nx = iv6[1] - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        loop_ub = iv6[0] - 1;
        for (n = 0; n <= loop_ub; n++) {
          r15 = *r16;
          r15.size = (int32_T *)&iv6;
          r15.numDimensions = 1;
          b_j->data[n + b_j->size[0] * i20] = j->data[r15.data[n + r15.size[0] *
            i20] - 1];
        }
      }

      emxFree_int32_T(&r16);
      i20 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = b_j->size[1];
      emxEnsureCapacity((emxArray__common *)j, i20, (int32_T)sizeof(real32_T));
      nx = b_j->size[1] - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        j->data[j->size[0] * i20] = b_j->data[b_j->size[0] * i20];
      }

      emxFree_real32_T(&b_j);
      if (1 > idx) {
        idx = 0;
      }

      b_emxInit_int32_T(&r17, 1);
      i20 = r17->size[0];
      r17->size[0] = idx;
      emxEnsureCapacity((emxArray__common *)r17, i20, (int32_T)sizeof(int32_T));
      nx = idx - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        r17->data[i20] = 1 + i20;
      }

      emxInit_real32_T(&b_v, 2);
      iv7[0] = 1;
      iv7[1] = r17->size[0];
      i20 = b_v->size[0] * b_v->size[1];
      b_v->size[0] = iv7[0];
      b_v->size[1] = iv7[1];
      emxEnsureCapacity((emxArray__common *)b_v, i20, (int32_T)sizeof(real32_T));
      nx = iv7[1] - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        loop_ub = iv7[0] - 1;
        for (n = 0; n <= loop_ub; n++) {
          r15 = *r17;
          r15.size = (int32_T *)&iv7;
          r15.numDimensions = 1;
          b_v->data[n + b_v->size[0] * i20] = v->data[r15.data[n + r15.size[0] *
            i20] - 1];
        }
      }

      emxFree_int32_T(&r17);
      i20 = v->size[0] * v->size[1];
      v->size[0] = 1;
      v->size[1] = b_v->size[1];
      emxEnsureCapacity((emxArray__common *)v, i20, (int32_T)sizeof(real32_T));
      nx = b_v->size[1] - 1;
      for (i20 = 0; i20 <= nx; i20++) {
        v->data[v->size[0] * i20] = b_v->data[b_v->size[0] * i20];
      }

      emxFree_real32_T(&b_v);
    }
  }
}

/* End of code generation (find.cpp) */
