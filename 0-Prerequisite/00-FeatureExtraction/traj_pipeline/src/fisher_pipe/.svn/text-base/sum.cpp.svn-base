/*
 * sum.cpp
 *
 * Code generation for function 'sum'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "sum.h"
#include "FisherVectorEncode_emxutil.h"
#include "max.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static int32_T b_eml_size_prod(const emxArray_real32_T *x);

/* Function Definitions */

/*
 *
 */
static int32_T b_eml_size_prod(const emxArray_real32_T *x)
{
  return x->size[1];
}

/*
 *
 */
void b_sum(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  int32_T vlen;
  uint32_T sz[2];
  int32_T npages;
  int32_T ixstart;
  int32_T iy;
  int32_T i;
  real32_T s;
  int32_T k;
  for (vlen = 0; vlen < 2; vlen++) {
    sz[vlen] = (uint32_T)x->size[vlen];
  }

  sz[0] = 1U;
  vlen = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int32_T)sz[1];
  emxEnsureCapacity((emxArray__common *)y, vlen, (int32_T)sizeof(real32_T));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vlen = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, vlen, (int32_T)sizeof(real32_T));
    npages = y->size[1] - 1;
    for (vlen = 0; vlen <= npages; vlen++) {
      y->data[y->size[0] * vlen] = 0.0F;
    }
  } else {
    vlen = x->size[0];
    npages = b_eml_size_prod(x);
    ixstart = -1;
    iy = -1;
    for (i = 1; i <= npages; i++) {
      ixstart++;
      s = x->data[ixstart];
      for (k = 2; k <= vlen; k++) {
        ixstart++;
        s += x->data[ixstart];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

/*
 *
 */
void sum(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  int32_T vstride;
  uint32_T sz[2];
  int32_T vlen;
  int32_T iy;
  int32_T ixstart;
  int32_T j;
  int32_T ix;
  real32_T s;
  int32_T k;
  for (vstride = 0; vstride < 2; vstride++) {
    sz[vstride] = (uint32_T)x->size[vstride];
  }

  sz[1] = 1U;
  vstride = y->size[0];
  y->size[0] = (int32_T)sz[0];
  emxEnsureCapacity((emxArray__common *)y, vstride, (int32_T)sizeof(real32_T));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vlen = y->size[0];
    vstride = y->size[0];
    y->size[0] = vlen;
    emxEnsureCapacity((emxArray__common *)y, vstride, (int32_T)sizeof(real32_T));
    vlen--;
    for (vstride = 0; vstride <= vlen; vstride++) {
      y->data[vstride] = 0.0F;
    }
  } else {
    vlen = x->size[1];
    vstride = eml_size_prod(x);
    iy = -1;
    ixstart = -1;
    for (j = 1; j <= vstride; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      for (k = 2; k <= vlen; k++) {
        ix += vstride;
        s += x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

/* End of code generation (sum.cpp) */
