/*
 * rand.cpp
 *
 * Code generation for function 'rand'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "rand.h"
#include "FisherVectorEncode_emxutil.h"
#include "FisherVectorEncode_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static uint32_T twister_state[625];

/* Function Declarations */
static real_T b_eml_rand_mt19937ar(uint32_T state[625]);
static real_T b_genrandu(uint32_T mt[625]);
static real_T eml_rand_mcg16807(uint32_T *state);
static void eml_rand_mt19937ar(uint32_T state[625]);
static void genrand_uint32_vector(uint32_T mt[625], uint32_T u[2]);
static void genrandu(uint32_T s, uint32_T *state, real_T *r);
static void twister_state_vector(uint32_T mt[625], real_T seed);

/* Function Definitions */

/*
 *
 */
static real_T b_eml_rand_mt19937ar(uint32_T state[625])
{
  return b_genrandu(state);
}

/*
 *
 */
static real_T b_genrandu(uint32_T mt[625])
{
  real_T r;
  int32_T exitg1;
  uint32_T u[2];
  boolean_T isvalid;
  int32_T k;
  boolean_T exitg2;

  /* <LEGAL>   This is a uniform (0,1) pseudorandom number generator based on: */
  /* <LEGAL> */
  /* <LEGAL>    A C-program for MT19937, with initialization improved 2002/1/26. */
  /* <LEGAL>    Coded by Takuji Nishimura and Makoto Matsumoto. */
  /* <LEGAL> */
  /* <LEGAL>    Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /* <LEGAL>    All rights reserved. */
  /* <LEGAL> */
  /* <LEGAL>    Redistribution and use in source and binary forms, with or without */
  /* <LEGAL>    modification, are permitted provided that the following conditions */
  /* <LEGAL>    are met: */
  /* <LEGAL> */
  /* <LEGAL>      1. Redistributions of source code must retain the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer. */
  /* <LEGAL> */
  /* <LEGAL>      2. Redistributions in binary form must reproduce the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer in the */
  /* <LEGAL>         documentation and/or other materials provided with the distribution. */
  /* <LEGAL> */
  /* <LEGAL>      3. The names of its contributors may not be used to endorse or promote */
  /* <LEGAL>         products derived from this software without specific prior written */
  /* <LEGAL>         permission. */
  /* <LEGAL> */
  /* <LEGAL>    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /* <LEGAL>    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /* <LEGAL>    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /* <LEGAL>    A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR */
  /* <LEGAL>    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
  /* <LEGAL>    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, */
  /* <LEGAL>    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR */
  /* <LEGAL>    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF */
  /* <LEGAL>    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING */
  /* <LEGAL>    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS */
  /* <LEGAL>    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  do {
    exitg1 = 0U;
    genrand_uint32_vector(mt, u);
    u[0] >>= 5U;
    u[1] >>= 6U;
    r = 1.1102230246251565E-16 * ((real_T)u[0] * 6.7108864E+7 + (real_T)u[1]);
    if (r == 0.0) {
      if ((mt[624] >= 1U) && (mt[624] < 625U)) {
        isvalid = TRUE;
      } else {
        isvalid = FALSE;
      }

      if (isvalid) {
        isvalid = FALSE;
        k = 1;
        exitg2 = 0U;
        while ((exitg2 == 0U) && (k < 625)) {
          if (mt[k - 1] == 0U) {
            k++;
          } else {
            isvalid = TRUE;
            exitg2 = 1U;
          }
        }
      }

      if (!isvalid) {
        twister_state_vector(mt, 5489.0);
      }
    } else {
      exitg1 = 1U;
    }
  } while (exitg1 == 0U);

  return r;
}

/*
 *
 */
static real_T eml_rand_mcg16807(uint32_T *state)
{
  real_T r;
  uint32_T b_state;
  genrandu(*state, &b_state, &r);
  *state = b_state;
  return r;
}

/*
 *
 */
static void eml_rand_mt19937ar(uint32_T state[625])
{
  memset((void *)&state[0], 0, 625U * sizeof(uint32_T));
  twister_state_vector(state, 5489.0);
}

/*
 *
 */
static void genrand_uint32_vector(uint32_T mt[625], uint32_T u[2])
{
  int32_T i;
  uint32_T mti;
  int32_T kk;
  uint32_T y;
  for (i = 0; i < 2; i++) {
    u[i] = 0U;
  }

  for (i = 0; i < 2; i++) {
    mti = mt[624] + 1U;
    if (mti >= 625U) {
      for (kk = 0; kk < 227; kk++) {
        y = (mt[kk] & 2147483648U) | (mt[kk + 1] & 2147483647U);
        if ((int32_T)(y & 1U) == 0) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        mt[kk] = mt[kk + 397] ^ y;
      }

      for (kk = 0; kk < 396; kk++) {
        y = (mt[kk + 227] & 2147483648U) | (mt[kk + 228] & 2147483647U);
        if ((int32_T)(y & 1U) == 0) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        mt[kk + 227] = mt[kk] ^ y;
      }

      y = (mt[623] & 2147483648U) | (mt[0] & 2147483647U);
      if ((int32_T)(y & 1U) == 0) {
        y >>= 1U;
      } else {
        y = y >> 1U ^ 2567483615U;
      }

      mt[623] = mt[396] ^ y;
      mti = 1U;
    }

    y = mt[(int32_T)mti - 1];
    mt[624] = mti;
    y ^= y >> 11U;
    y ^= y << 7U & 2636928640U;
    y ^= y << 15U & 4022730752U;
    y ^= y >> 18U;
    u[i] = y;
  }
}

/*
 *
 */
static void genrandu(uint32_T s, uint32_T *state, real_T *r)
{
  int32_T hi;
  uint32_T test1;
  uint32_T test2;
  hi = (int32_T)(s / 127773U);
  test1 = 16807U * (s - (uint32_T)hi * 127773U);
  test2 = 2836U * (uint32_T)hi;
  if (test1 < test2) {
    *state = (test1 - test2) + 2147483647U;
  } else {
    *state = test1 - test2;
  }

  *r = (real_T)*state * 4.6566128752457969E-10;
}

/*
 *
 */
static void twister_state_vector(uint32_T mt[625], real_T seed)
{
  uint32_T r;
  int32_T mti;
  if (seed < 4.294967296E+9) {
    if (seed >= 0.0) {
      r = (uint32_T)seed;
    } else {
      r = 0U;
    }
  } else if (seed >= 4.294967296E+9) {
    r = MAX_uint32_T;
  } else {
    r = 0U;
  }

  mt[0] = r;
  for (mti = 0; mti < 623; mti++) {
    r = ((r ^ r >> 30U) * 1812433253U + (uint32_T)mti) + 1U;
    mt[mti + 1] = r;
  }

  mt[624] = 624U;
}

/*
 *
 */
void b_rand(int32_T varargin_2, emxArray_real_T *r)
{
  int32_T loop_ub;
  uint32_T k;
  real_T d1;
  loop_ub = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = varargin_2;
  emxEnsureCapacity((emxArray__common *)r, loop_ub, (int32_T)sizeof(real_T));
  if (method == 2) {
    if (!twister_state_not_empty) {
      eml_rand_mt19937ar(twister_state);
      twister_state_not_empty = TRUE;
    }

    loop_ub = r->size[1];
    for (k = 1U; k <= (uint32_T)loop_ub; k++) {
      d1 = b_eml_rand_mt19937ar(twister_state);
      r->data[(int32_T)k - 1] = d1;
    }
  } else {
    loop_ub = r->size[1];
    for (k = 1U; k <= (uint32_T)loop_ub; k++) {
      d1 = eml_rand_mcg16807(&v4_state);
      r->data[(int32_T)k - 1] = d1;
    }
  }
}

/* End of code generation (rand.cpp) */
