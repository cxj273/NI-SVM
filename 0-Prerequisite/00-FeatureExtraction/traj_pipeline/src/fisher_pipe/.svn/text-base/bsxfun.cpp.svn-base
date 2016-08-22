/*
 * bsxfun.cpp
 *
 * Code generation for function 'bsxfun'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "bsxfun.h"
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
void bsxfun(const emxArray_real32_T *a, const emxArray_real32_T *b,
            emxArray_real32_T *c)
{
  int32_T na1;
  int32_T b_a;
  int32_T csz[2];
  emxArray_real32_T *av;
  int32_T asub;
  int32_T bsub;
  int32_T ak;
  int32_T bk;
  int32_T nc1;
  int32_T loop_ub;
  int32_T ck;
  emxArray_real32_T *cv;
  real32_T b_b;
  int32_T b_loop_ub;
  na1 = a->size[0];
  for (b_a = 0; b_a < 2; b_a++) {
    csz[b_a] = 0;
  }

  b_emxInit_real32_T(&av, 1);
  csz[0] = a->size[0];
  csz[1] = a->size[1];
  b_a = c->size[0] * c->size[1];
  c->size[0] = csz[0];
  c->size[1] = csz[1];
  emxEnsureCapacity((emxArray__common *)c, b_a, (int32_T)sizeof(real32_T));
  csz[0] = na1;
  csz[1] = 1;
  b_a = av->size[0];
  av->size[0] = csz[0];
  emxEnsureCapacity((emxArray__common *)av, b_a, (int32_T)sizeof(real32_T));
  asub = 1;
  bsub = 1;
  ak = -1;
  bk = 0;
  nc1 = c->size[0];
  b_a = c->size[0] * c->size[1];
  loop_ub = b_a - nc1;
  ck = 0;
  b_emxInit_real32_T(&cv, 1);
  while ((nc1 > 0) && (ck <= loop_ub)) {
    for (b_a = 1; b_a <= na1; b_a++) {
      av->data[b_a - 1] = a->data[ak + b_a];
    }

    b_b = b->data[bk];
    b_a = cv->size[0];
    cv->size[0] = av->size[0];
    emxEnsureCapacity((emxArray__common *)cv, b_a, (int32_T)sizeof(real32_T));
    b_loop_ub = av->size[0] - 1;
    for (b_a = 0; b_a <= b_loop_ub; b_a++) {
      cv->data[b_a] = av->data[b_a] * b_b;
    }

    for (b_a = 0; b_a + 1 <= nc1; b_a++) {
      c->data[ck + b_a] = cv->data[b_a];
    }

    if (asub < a->size[1]) {
      ak += na1;
      bk++;
      bsub++;
      asub++;
    } else if (bsub < b->size[1]) {
      bk++;
      bsub++;
    } else {
      asub = 1;
      bsub = 1;
    }

    ck += nc1;
  }

  emxFree_real32_T(&cv);
  emxFree_real32_T(&av);
}

/* End of code generation (bsxfun.cpp) */
