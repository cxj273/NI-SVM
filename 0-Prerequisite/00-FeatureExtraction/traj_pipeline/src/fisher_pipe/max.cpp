/*
 * max.cpp
 *
 * Code generation for function 'max'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "max.h"
#include "isnan.h"
#include "FisherVectorEncode_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_eml_min_or_max(const emxArray_real32_T *x, emxArray_real32_T
  *extremum);
static void c_eml_scalexp_alloc(const emxArray_real32_T *varargin_1,
  emxArray_real32_T *z);
static void eml_bin_extremum(const emxArray_real32_T *x, emxArray_real32_T
  *extremum);
static void eml_min_or_max(const emxArray_real32_T *x, emxArray_real32_T
  *extremum);

/* Function Definitions */

/*
 *
 */
static void b_eml_min_or_max(const emxArray_real32_T *x, emxArray_real32_T
  *extremum)
{
  eml_bin_extremum(x, extremum);
}

/*
 *
 */
static void c_eml_scalexp_alloc(const emxArray_real32_T *varargin_1,
  emxArray_real32_T *z)
{
  int32_T i15;
  uint32_T uv2[2];
  for (i15 = 0; i15 < 2; i15++) {
    uv2[i15] = (uint32_T)varargin_1->size[i15];
  }

  i15 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = (int32_T)uv2[1];
  emxEnsureCapacity((emxArray__common *)z, i15, (int32_T)sizeof(real32_T));
}

/*
 *
 */
static void eml_bin_extremum(const emxArray_real32_T *x, emxArray_real32_T
  *extremum)
{
  int32_T loop_ub;
  int32_T k;
  real32_T b_extremum;
  c_eml_scalexp_alloc(x, extremum);
  loop_ub = extremum->size[1];
  for (k = 0; k + 1 <= loop_ub; k++) {
    if (((real_T)x->data[k] < 2.2204460492503131E-16) || c_isnan(x->data[k])) {
      b_extremum = 2.22044605E-16F;
    } else {
      b_extremum = x->data[k];
    }

    extremum->data[k] = b_extremum;
  }
}

/*
 *
 */
static void eml_min_or_max(const emxArray_real32_T *x, emxArray_real32_T
  *extremum)
{
  int32_T n;
  uint32_T outsz[2];
  int32_T vstride;
  int32_T ix;
  int32_T iy;
  int32_T j;
  real32_T mtmp;
  int32_T itmp;
  int32_T b_ix;
  boolean_T guard1 = FALSE;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T exitg1;
  for (n = 0; n < 2; n++) {
    outsz[n] = (uint32_T)x->size[n];
  }

  outsz[1] = 1U;
  n = extremum->size[0];
  extremum->size[0] = (int32_T)outsz[0];
  emxEnsureCapacity((emxArray__common *)extremum, n, (int32_T)sizeof(real32_T));
  n = x->size[1];
  vstride = eml_size_prod(x);
  ix = -1;
  iy = -1;
  for (j = 1; j <= vstride; j++) {
    ix++;
    mtmp = x->data[ix];
    itmp = 2;
    if (n == 1) {
    } else {
      b_ix = ix;
      guard1 = FALSE;
      if (c_isnan(x->data[ix])) {
        searchingForNonNaN = TRUE;
        k = 2;
        exitg1 = 0U;
        while ((exitg1 == 0U) && (k <= n)) {
          b_ix += vstride;
          if (!c_isnan(x->data[b_ix])) {
            mtmp = x->data[b_ix];
            itmp = k + 1;
            searchingForNonNaN = FALSE;
            exitg1 = 1U;
          } else {
            k++;
          }
        }

        if (searchingForNonNaN) {
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        while (itmp <= n) {
          b_ix += vstride;
          if (x->data[b_ix] > mtmp) {
            mtmp = x->data[b_ix];
          }

          itmp++;
        }
      }
    }

    iy++;
    extremum->data[iy] = mtmp;
  }
}

/*
 *
 */
void b_max(const emxArray_real32_T *varargin_1, emxArray_real32_T *maxval)
{
  eml_min_or_max(varargin_1, maxval);
}

/*
 *
 */
void c_max(const emxArray_real32_T *varargin_1, emxArray_real32_T *maxval)
{
  b_eml_min_or_max(varargin_1, maxval);
}

/*
 *
 */
int32_T eml_size_prod(const emxArray_real32_T *x)
{
  return x->size[0];
}

/* End of code generation (max.cpp) */
