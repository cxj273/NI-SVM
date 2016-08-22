/*
 * rdivide.cpp
 *
 * Code generation for function 'rdivide'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "rdivide.h"
#include "FisherVectorEncode_emxutil.h"
#include "intmin.h"
#include "intmax.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static int32_T b_eml_div(int32_T x, real_T y);
static void c_eml_div(const emxArray_int32_T *x, int32_T y, emxArray_int32_T *z);
static void d_eml_div(real_T x, const emxArray_real32_T *y, emxArray_real32_T *z);
static void e_eml_div(const emxArray_real32_T *x, real32_T y, emxArray_real32_T *
                      z);
static real_T eml_div(real_T x, real_T y);
static void eml_scalexp_alloc(const emxArray_int32_T *varargin_1,
  emxArray_int32_T *z);

/* Function Definitions */

/*
 *
 */
static int32_T b_eml_div(int32_T x, real_T y)
{
  int32_T z;
  real_T d0;
  d0 = (real_T)x / y;
  d0 = d0 < 0.0 ? ceil(d0 - 0.5) : floor(d0 + 0.5);
  if (d0 < 2.147483648E+9) {
    if (d0 >= -2.147483648E+9) {
      z = (int32_T)d0;
    } else {
      z = MIN_int32_T;
    }
  } else if (d0 >= 2.147483648E+9) {
    z = MAX_int32_T;
  } else {
    z = 0;
  }

  return z;
}

/*
 *
 */
static void c_eml_div(const emxArray_int32_T *x, int32_T y, emxArray_int32_T *z)
{
  int32_T loop_ub;
  uint32_T k;
  int32_T saturatedUnaryMinus;
  uint32_T b_y;
  uint32_T c_y;
  uint32_T q;
  eml_scalexp_alloc(x, z);
  loop_ub = z->size[1];
  for (k = 1U; k <= (uint32_T)loop_ub; k++) {
    if (y == 0) {
      if (x->data[(int32_T)k - 1] == 0) {
        z->data[(int32_T)k - 1] = 0;
      } else if (x->data[(int32_T)k - 1] < 0) {
        z->data[(int32_T)k - 1] = intmin();
      } else {
        z->data[(int32_T)k - 1] = intmax();
      }
    } else if (y == 1) {
      z->data[(int32_T)k - 1] = x->data[(int32_T)k - 1];
    } else {
      if (x->data[(int32_T)k - 1] >= 0) {
        saturatedUnaryMinus = x->data[(int32_T)k - 1];
        if (saturatedUnaryMinus <= 0) {
          saturatedUnaryMinus = 0;
        }

        b_y = (uint32_T)saturatedUnaryMinus;
      } else if (x->data[(int32_T)k - 1] == intmin()) {
        saturatedUnaryMinus = intmax();
        if (saturatedUnaryMinus <= 0) {
          saturatedUnaryMinus = 0;
        }

        b_y = (uint32_T)saturatedUnaryMinus + 1U;
      } else {
        saturatedUnaryMinus = x->data[(int32_T)k - 1];
        if (saturatedUnaryMinus <= MIN_int32_T) {
          saturatedUnaryMinus = MAX_int32_T;
        } else {
          saturatedUnaryMinus = -saturatedUnaryMinus;
        }

        if (saturatedUnaryMinus <= 0) {
          saturatedUnaryMinus = 0;
        }

        b_y = (uint32_T)saturatedUnaryMinus;
      }

      if (y >= 0) {
        c_y = (uint32_T)y;
      } else if (y == intmin()) {
        saturatedUnaryMinus = intmax();
        if (saturatedUnaryMinus <= 0) {
          saturatedUnaryMinus = 0;
        }

        c_y = (uint32_T)saturatedUnaryMinus + 1U;
      } else {
        if (y <= MIN_int32_T) {
          saturatedUnaryMinus = MAX_int32_T;
        } else {
          saturatedUnaryMinus = -y;
        }

        c_y = (uint32_T)saturatedUnaryMinus;
      }

      q = c_y == (uint32_T)0 ? MAX_uint32_T : b_y / c_y;
      b_y -= q * c_y;
      if ((b_y > 0U) && (b_y >= (c_y >> 1U) + (c_y & 1U))) {
        q++;
      }

      if ((x->data[(int32_T)k - 1] < 0) != (y < 0)) {
        if (q > 2147483647U) {
          q = 2147483647U;
        }

        z->data[(int32_T)k - 1] = -(int32_T)q;
      } else {
        if (q > 2147483647U) {
          q = 2147483647U;
        }

        z->data[(int32_T)k - 1] = (int32_T)q;
      }
    }
  }
}

/*
 *
 */
static void d_eml_div(real_T x, const emxArray_real32_T *y, emxArray_real32_T *z)
{
  int32_T i16;
  int32_T loop_ub;
  i16 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = y->size[1];
  emxEnsureCapacity((emxArray__common *)z, i16, (int32_T)sizeof(real32_T));
  loop_ub = y->size[0] * y->size[1] - 1;
  for (i16 = 0; i16 <= loop_ub; i16++) {
    z->data[i16] = (real32_T)x / y->data[i16];
  }
}

/*
 *
 */
static void e_eml_div(const emxArray_real32_T *x, real32_T y, emxArray_real32_T *
                      z)
{
  int32_T i17;
  int32_T loop_ub;
  i17 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i17, (int32_T)sizeof(real32_T));
  loop_ub = x->size[0] - 1;
  for (i17 = 0; i17 <= loop_ub; i17++) {
    z->data[i17] = x->data[i17] / y;
  }
}

/*
 *
 */
static real_T eml_div(real_T x, real_T y)
{
  return x / y;
}

/*
 *
 */
static void eml_scalexp_alloc(const emxArray_int32_T *varargin_1,
  emxArray_int32_T *z)
{
  int32_T i10;
  uint32_T uv0[2];
  for (i10 = 0; i10 < 2; i10++) {
    uv0[i10] = (uint32_T)varargin_1->size[i10];
  }

  i10 = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = (int32_T)uv0[1];
  emxEnsureCapacity((emxArray__common *)z, i10, (int32_T)sizeof(int32_T));
}

/*
 *
 */
int32_T b_rdivide(int32_T x, real_T y)
{
  return b_eml_div(x, y);
}

/*
 *
 */
void c_rdivide(const emxArray_int32_T *x, int32_T y, emxArray_int32_T *z)
{
  c_eml_div(x, y, z);
}

/*
 *
 */
void d_rdivide(real_T x, const emxArray_real32_T *y, emxArray_real32_T *z)
{
  d_eml_div(x, y, z);
}

/*
 *
 */
void e_rdivide(const emxArray_real32_T *x, real32_T y, emxArray_real32_T *z)
{
  e_eml_div(x, y, z);
}

/*
 *
 */
real_T rdivide(real_T x, real_T y)
{
  return eml_div(x, y);
}

/* End of code generation (rdivide.cpp) */
