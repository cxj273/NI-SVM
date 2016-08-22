/*
 * compute.cpp
 *
 * Code generation for function 'compute'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "compute.h"
#include "mrdivide.h"
#include "FEencode.h"
#include "FisherVectorEncode_emxutil.h"
#include "nnz.h"
#include "isnan.h"
#include "max.h"
#include "sum.h"
#include "norm.h"
#include "sqrt.h"
#include "abs.h"
#include "sign.h"
#include "isequal.h"
#include "bsxfun.h"
#include "rdivide.h"
#include "power.h"
#include "mpower.h"
#include "FKEncoder_get_output_dim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static int32_T compute_nones(const emxArray_boolean_T *x, int32_T n);
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y);
static boolean_T n_eml_strcmp(const char_T a[2]);
static boolean_T o_eml_strcmp(const char_T a[2]);
static boolean_T p_eml_strcmp(const emxArray_char_T *a);
static boolean_T q_eml_strcmp(const emxArray_char_T *a);
static boolean_T r_eml_strcmp(const emxArray_char_T *a);
static boolean_T s_eml_strcmp(const emxArray_char_T *a);

/* Function Definitions */

/*
 *
 */
static int32_T compute_nones(const emxArray_boolean_T *x, int32_T n)
{
  int32_T k;
  int32_T i;
  k = 0;
  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      k++;
    }
  }

  return k;
}

/*
 *
 */
static void eml_li_find(const emxArray_boolean_T *x, emxArray_int32_T *y)
{
  int32_T n;
  int32_T k;
  int32_T i;
  n = x->size[1];
  k = compute_nones(x, n);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = k;
  emxEnsureCapacity((emxArray__common *)y, i, (int32_T)sizeof(int32_T));
  k = 0;
  for (i = 1; i <= n; i++) {
    if (x->data[i - 1]) {
      y->data[k] = i;
      k++;
    }
  }
}

/*
 *
 */

/*
 *
 */
static boolean_T n_eml_strcmp(const char_T a[2])
{
  boolean_T b_bool;
  int32_T k;
  int32_T exitg1;
  static const char_T cv33[2] = { 'l', '2' };

  b_bool = FALSE;
  k = 0;
  do {
    exitg1 = 0U;
    if (k + 1 <= 2) {
      if (a[k] != cv33[k]) {
        exitg1 = 1U;
      } else {
        k++;
      }
    } else {
      b_bool = TRUE;
      exitg1 = 1U;
    }
  } while (exitg1 == 0U);

  return b_bool;
}

/*
 *
 */
static boolean_T o_eml_strcmp(const char_T a[2])
{
  boolean_T b_bool;
  int32_T k;
  int32_T exitg1;
  static const char_T cv34[2] = { 'l', '1' };

  b_bool = FALSE;
  k = 0;
  do {
    exitg1 = 0U;
    if (k + 1 <= 2) {
      if (a[k] != cv34[k]) {
        exitg1 = 1U;
      } else {
        k++;
      }
    } else {
      b_bool = TRUE;
      exitg1 = 1U;
    }
  } while (exitg1 == 0U);

  return b_bool;
}

/*
 *
 */
static boolean_T p_eml_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T k;
  uint32_T sza[2];
  int32_T exitg2;
  int32_T exitg1;
  static const char_T cv35[2] = { 'l', '2' };

  b_bool = FALSE;
  for (k = 0; k < 2; k++) {
    sza[k] = (uint32_T)a->size[k];
  }

  k = 0;
  do {
    exitg2 = 0U;
    if (k + 1 <= 2) {
      if ((real_T)sza[k] != (real_T)(int8_T)(1 + (int8_T)k)) {
        exitg2 = 1U;
      } else {
        k++;
      }
    } else {
      k = 0;
      exitg2 = 2U;
    }
  } while (exitg2 == 0U);

  if (exitg2 == 1U) {
  } else {
    do {
      exitg1 = 0U;
      if (k + 1 <= a->size[1]) {
        if (a->data[k] != cv35[k]) {
          exitg1 = 1U;
        } else {
          k++;
        }
      } else {
        b_bool = TRUE;
        exitg1 = 1U;
      }
    } while (exitg1 == 0U);
  }

  return b_bool;
}

/*
 *
 */
static boolean_T q_eml_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T k;
  uint32_T sza[2];
  int32_T exitg2;
  int32_T exitg1;
  static const char_T cv36[2] = { 'l', '1' };

  b_bool = FALSE;
  for (k = 0; k < 2; k++) {
    sza[k] = (uint32_T)a->size[k];
  }

  k = 0;
  do {
    exitg2 = 0U;
    if (k + 1 <= 2) {
      if ((real_T)sza[k] != (real_T)(int8_T)(1 + (int8_T)k)) {
        exitg2 = 1U;
      } else {
        k++;
      }
    } else {
      k = 0;
      exitg2 = 2U;
    }
  } while (exitg2 == 0U);

  if (exitg2 == 1U) {
  } else {
    do {
      exitg1 = 0U;
      if (k + 1 <= a->size[1]) {
        if (a->data[k] != cv36[k]) {
          exitg1 = 1U;
        } else {
          k++;
        }
      } else {
        b_bool = TRUE;
        exitg1 = 1U;
      }
    } while (exitg1 == 0U);
  }

  return b_bool;
}

/*
 *
 */
static boolean_T r_eml_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T k;
  uint32_T sza[2];
  int32_T exitg2;
  int32_T exitg1;
  static const char_T cv38[6] = { 'h', 'o', 'm', 'k', 'e', 'r' };

  b_bool = FALSE;
  for (k = 0; k < 2; k++) {
    sza[k] = (uint32_T)a->size[k];
  }

  k = 0;
  do {
    exitg2 = 0U;
    if (k + 1 <= 2) {
      if ((real_T)sza[k] != (real_T)(int8_T)(1 + (int8_T)(5 * (int8_T)k))) {
        exitg2 = 1U;
      } else {
        k++;
      }
    } else {
      k = 0;
      exitg2 = 2U;
    }
  } while (exitg2 == 0U);

  if (exitg2 == 1U) {
  } else {
    do {
      exitg1 = 0U;
      if (k + 1 <= a->size[1]) {
        if (a->data[k] != cv38[k]) {
          exitg1 = 1U;
        } else {
          k++;
        }
      } else {
        b_bool = TRUE;
        exitg1 = 1U;
      }
    } while (exitg1 == 0U);
  }

  return b_bool;
}

/*
 *
 */
static boolean_T s_eml_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T k;
  uint32_T sza[2];
  int32_T exitg2;
  int32_T exitg1;
  static const char_T cv39[9] = { 'h', 'e', 'l', 'l', 'i', 'n', 'g', 'e', 'r' };

  b_bool = FALSE;
  for (k = 0; k < 2; k++) {
    sza[k] = (uint32_T)a->size[k];
  }

  k = 0;
  do {
    exitg2 = 0U;
    if (k + 1 <= 2) {
      if ((real_T)sza[k] != (real_T)(int8_T)(1 + (int8_T)((int8_T)k << 3))) {
        exitg2 = 1U;
      } else {
        k++;
      }
    } else {
      k = 0;
      exitg2 = 2U;
    }
  } while (exitg2 == 0U);

  if (exitg2 == 1U) {
  } else {
    do {
      exitg1 = 0U;
      if (k + 1 <= a->size[1]) {
        if (a->data[k] != cv39[k]) {
          exitg1 = 1U;
        } else {
          k++;
        }
      } else {
        b_bool = TRUE;
        exitg1 = 1U;
      }
    } while (exitg1 == 0U);
  }

  return b_bool;
}

/*
 * function pcode = compute(obj, imsize, feats, frames, is_spatial)
 */
void compute(const char_T obj_subbin_norm_type[2], const emxArray_char_T
             *obj_norm_type, const emxArray_char_T *obj_post_norm_type, 
             char *obj_pool_type, real_T obj_quad_divs, real_T
             obj_horiz_divs, const emxArray_char_T *obj_kermap, boolean_T
             obj_encoder__grad_weights, boolean_T obj_encoder__grad_means,
             boolean_T obj_encoder__grad_variances, int32_T
             obj_encoder__codebook__n_gauss, int32_T
             obj_encoder__codebook__n_dim, const emxArray_real32_T *feats, const
             emxArray_int32_T *frames, boolean_T is_spatial, emxArray_real32_T
             *pcode, fisher_handle<float>* fh, int video_width, int video_height )
{
  real_T bin_quads_count;
  real_T bin_quad_levels;
  real_T bin_div_tmp;
  emxArray_real32_T *b_pcode;
  int32_T i9;
  int32_T loop_ub;
  emxArray_int32_T *b_frames;
  emxArray_int32_T *y_bin;
  emxArray_int32_T *c_frames;
  emxArray_int32_T *x_bin;
  uint32_T code_idx;
  real_T sx_bin;
  emxArray_real32_T *feats_sel;
  emxArray_real32_T *pcode_norm;
  emxArray_int32_T *r8;
  emxArray_boolean_T *r9;
  emxArray_int32_T *r10;
  emxArray_boolean_T *b_y_bin;
  real_T sy_bin;
  int32_T c_pcode;
  int32_T b_loop_ub;
  int32_T exitg1;
  emxArray_real32_T *r11;
  real_T prev_level_bin_divs;
  real_T prev_level_start_bin;
  real_T i;
  emxArray_real_T *feats_sel_num;
  emxArray_real32_T *d_pcode;
  emxArray_real32_T *e_pcode;
  real_T level_bin_divs;
  real_T level_start_bin;
  real_T xstart;
  real_T xend;
  real_T ystart;
  real_T yend;
  int32_T f_pcode;
  emxArray_int32_T *d_frames;
  emxArray_boolean_T *c_y_bin;
  emxArray_real32_T *g_pcode;
  emxArray_int32_T *r12;
  emxArray_real32_T *h_pcode;
  int32_T iv4[2];
  emxArray_real32_T i_pcode;
  emxArray_real32_T *b_pcode_norm;
  emxArray_real32_T *c_pcode_norm;
  emxArray_real32_T *j_pcode;
  int32_T k_pcode[1];
  int32_T l_pcode[1];
  emxArray_real32_T m_pcode;
  int32_T n_pcode[1];
  int32_T o_pcode[1];
  emxArray_real32_T *p_pcode;
  emxArray_real32_T *q_pcode;

  /* COMPUTE Pool features using the spatial pyramid match kernel */
  /* 'compute:5' if (nargin < 5) */
  /*  check pool type is valid */
  /* 'compute:10' if ~strcmp(obj.pool_type,'sum') && ~strcmp(obj.pool_type,'max') */
  /*  check bin levels */
  /* 'compute:15' if mod(log2(obj.quad_divs),1) */
  /* 'compute:18' bin_quads_count = obj.quad_divs*obj.quad_divs; */
  bin_quads_count = obj_quad_divs * obj_quad_divs;

  /* 'compute:19' bin_quad_levels = 1; */
  bin_quad_levels = 1.0;

  /* 'compute:20' bin_div_tmp = obj.quad_divs; */
  bin_div_tmp = obj_quad_divs;

  /* 'compute:21' while bin_div_tmp ~= 2 */
  while (bin_div_tmp != 2.0) {
    /* 'compute:22' bin_div_tmp = bin_div_tmp/2; */
    bin_div_tmp = mrdivide(bin_div_tmp, 2.0);

    /* 'compute:23' bin_quad_levels = bin_quad_levels + 1; */
    bin_quad_levels++;

    /* 'compute:24' bin_quads_count = bin_quads_count + bin_div_tmp*bin_div_tmp; */
    bin_quads_count += bin_div_tmp * bin_div_tmp;
  }

  emxInit_real32_T(&b_pcode, 2);

  /* clear bin_div_tmp; */
  /* 'compute:28' bin_count = bin_quads_count + obj.horiz_divs + 1; */
  bin_div_tmp = (bin_quads_count + obj_horiz_divs) + 1.0;

  /* 'compute:30' pcode = zeros(FKEncoder_get_output_dim(obj.encoder_), bin_count, 'single'); */
  i9 = b_pcode->size[0] * b_pcode->size[1];
  b_pcode->size[0] = FKEncoder_get_output_dim(obj_encoder__grad_weights,
    obj_encoder__grad_means, obj_encoder__grad_variances,
    obj_encoder__codebook__n_gauss, obj_encoder__codebook__n_dim);
  b_pcode->size[1] = (int32_T)bin_div_tmp;
  emxEnsureCapacity((emxArray__common *)b_pcode, i9, (int32_T)sizeof(real32_T));
  i9 = FKEncoder_get_output_dim(obj_encoder__grad_weights,
    obj_encoder__grad_means, obj_encoder__grad_variances,
    obj_encoder__codebook__n_gauss, obj_encoder__codebook__n_dim);
  loop_ub = i9 * (int32_T)bin_div_tmp - 1;
  for (i9 = 0; i9 <= loop_ub; i9++) {
    b_pcode->data[i9] = 0.0F;
  }

  emxInit_int32_T(&b_frames, 2);

  /*  first compute for finest 'quarter' bins */
  /* 'compute:33' h_unit = imsize(1) / obj.quad_divs; */
  /* 'compute:34' w_unit = imsize(2) / obj.quad_divs; */
  /* 'compute:35' y_bin = ceil(frames(2,:) / h_unit); */
  i9 = b_frames->size[0] * b_frames->size[1];
  b_frames->size[0] = 1;
  b_frames->size[1] = frames->size[1];
  emxEnsureCapacity((emxArray__common *)b_frames, i9, (int32_T)sizeof(int32_T));
  loop_ub = frames->size[1] - 1;
  for (i9 = 0; i9 <= loop_ub; i9++) {
    b_frames->data[b_frames->size[0] * i9] = frames->data[1 + frames->size[0] *
      i9];
  }

  emxInit_int32_T(&y_bin, 2);
  emxInit_int32_T(&c_frames, 2);
  c_mrdivide_ceil(b_frames, (double)video_height / (double)obj_quad_divs, y_bin);

  /* 'compute:36' x_bin = ceil(frames(1,:) / w_unit); */
  i9 = c_frames->size[0] * c_frames->size[1];
  c_frames->size[0] = 1;
  c_frames->size[1] = frames->size[1];
  emxEnsureCapacity((emxArray__common *)c_frames, i9, (int32_T)sizeof(int32_T));
  emxFree_int32_T(&b_frames);
  loop_ub = frames->size[1] - 1;
  for (i9 = 0; i9 <= loop_ub; i9++) {
    c_frames->data[c_frames->size[0] * i9] = frames->data[frames->size[0] * i9];
  }

  emxInit_int32_T(&x_bin, 2);
  c_mrdivide_ceil(c_frames, (double)video_width / (double)obj_quad_divs, x_bin);
   
  /* 'compute:38' feats_sel_num = zeros(obj.quad_divs ^ 2, 1); */
  /* 'compute:39' code_idx = 0; */
  code_idx = 0U;

  /* 'compute:41' for sx_bin = 1:obj.quad_divs */
  sx_bin = 1.0;
  emxFree_int32_T(&c_frames);
  emxInit_real32_T(&feats_sel, 2);
  emxInit_real32_T(&pcode_norm, 2);
  b_emxInit_int32_T(&r8, 1);
  emxInit_boolean_T(&r9, 2);
  emxInit_int32_T(&r10, 2);
  emxInit_boolean_T(&b_y_bin, 2);
  while (sx_bin <= obj_quad_divs) {
    //fprintf(stderr, "sx_bin %g obj_quad_divs %g\n", sx_bin, obj_quad_divs);
    /* 'compute:42' for sy_bin = 1:obj.quad_divs */
    for (sy_bin = 1.0; sy_bin <= obj_quad_divs; sy_bin++) {
      /* 'compute:44' code_idx = code_idx + 1; */
      code_idx++;

      /* 'compute:46' feats_sel = feats(:, (y_bin == sy_bin) & (x_bin == sx_bin)); */
      i9 = b_y_bin->size[0] * b_y_bin->size[1];
      b_y_bin->size[0] = 1;
      b_y_bin->size[1] = y_bin->size[1];
      emxEnsureCapacity((emxArray__common *)b_y_bin, i9, (int32_T)sizeof
                        (boolean_T));
      loop_ub = y_bin->size[0] * y_bin->size[1] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        b_y_bin->data[i9] = (((real_T)y_bin->data[i9] == sy_bin) && ((real_T)
          x_bin->data[i9] == sx_bin));
      }

      eml_li_find(b_y_bin, r10);
      c_pcode = r10->size[1];
      i9 = feats_sel->size[0] * feats_sel->size[1];
      feats_sel->size[0] = feats->size[0];
      feats_sel->size[1] = c_pcode;
      emxEnsureCapacity((emxArray__common *)feats_sel, i9, (int32_T)sizeof
                        (real32_T));
      loop_ub = c_pcode - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        b_loop_ub = feats->size[0] - 1;
        for (c_pcode = 0; c_pcode <= b_loop_ub; c_pcode++) {
          feats_sel->data[c_pcode + feats_sel->size[0] * i9] = feats->
            data[c_pcode + feats->size[0] * (r10->data[i9] - 1)];
        }
      }

      fprintf(stderr, "feats_sel %d %d\n", feats_sel->size[0], feats_sel->size[1]);
      /* 'compute:47' feats_sel_num(code_idx) = size(feats_sel, 2); */
      /* 'compute:49' if ~isempty(feats_sel) */
      if (!((feats_sel->size[0] == 0) || (feats_sel->size[1] == 0))) {
        /* 'compute:50' code = FEencode(obj.encoder_, feats_sel); */
        FEencode(obj_encoder__codebook__n_gauss, obj_encoder__codebook__n_dim,
                 feats_sel, pcode_norm, fh);

        /* 'compute:51' while nnz(isnan(code)) */
        do {
          exitg1 = 0U;
          b_isnan(pcode_norm, r9);
          if (nnz(r9) != 0.0) {
            /* 'compute:52' code = FEencode(obj.encoder_, feats_sel); */
            FEencode(obj_encoder__codebook__n_gauss,
                     obj_encoder__codebook__n_dim, feats_sel, pcode_norm, fh);
          } else {
            exitg1 = 1U;
          }
        } while (exitg1 == 0U);

        /* 'compute:54' pcode(:, code_idx) = code; */
        i9 = r8->size[0];
        r8->size[0] = b_pcode->size[0];
        emxEnsureCapacity((emxArray__common *)r8, i9, (int32_T)sizeof(int32_T));
        loop_ub = b_pcode->size[0] - 1;
        for (i9 = 0; i9 <= loop_ub; i9++) {
          r8->data[i9] = i9;
        }

        i9 = (int32_T)code_idx - 1;
        c_pcode = r8->size[0];
        loop_ub = c_pcode - 1;
        for (c_pcode = 0; c_pcode <= loop_ub; c_pcode++) {
          b_pcode->data[r8->data[c_pcode] + b_pcode->size[0] * i9] =
            pcode_norm->data[c_pcode];
        }
      } else {
        /* 'compute:55' else */
        /* 'compute:56' error('SPMPool:EmptyBin','empty bin!'); */
      }
    }

    sx_bin++;
  }

  emxFree_boolean_T(&b_y_bin);
  emxFree_boolean_T(&r9);
  emxFree_int32_T(&x_bin);

  /*  now merge to form subsequent bin levels */
  /* 'compute:62' if bin_quad_levels > 1 */
  b_emxInit_real32_T(&r11, 1);
  if (bin_quad_levels > 1.0) {
    /* 'compute:63' prev_level_bin_divs = obj.quad_divs; */
    prev_level_bin_divs = obj_quad_divs;

    /* 'compute:64' prev_level_start_bin = 1; */
    prev_level_start_bin = 1.0;

    /* 'compute:65' for i = 2:bin_quad_levels */
    i = 2.0;
    b_emxInit_real_T(&feats_sel_num, 1);
    emxInit_real32_T(&d_pcode, 2);
    emxInit_real32_T(&e_pcode, 2);
    while (i <= bin_quad_levels) {
      /* 'compute:66' level_bin_divs = prev_level_bin_divs/2; */
      level_bin_divs = mrdivide(prev_level_bin_divs, 2.0);

      /* 'compute:67' level_start_bin = prev_level_start_bin + ... */
      /* 'compute:68'                 prev_level_bin_divs*prev_level_bin_divs; */
      level_start_bin = prev_level_start_bin + prev_level_bin_divs *
        prev_level_bin_divs;

      /* 'compute:70' for sx_bin = 1:level_bin_divs */
      for (sx_bin = 1.0; sx_bin <= level_bin_divs; sx_bin++) {
        /* 'compute:71' for sy_bin = 1:level_bin_divs */
        for (sy_bin = 1.0; sy_bin <= level_bin_divs; sy_bin++) {
          /* 'compute:72' xstart = 2*sx_bin-1; */
          xstart = 2.0 * sx_bin - 1.0;

          /* 'compute:73' xend = 2*(sx_bin+1)-2; */
          xend = 2.0 * (sx_bin + 1.0) - 2.0;

          /* 'compute:74' ystart = 2*sy_bin-1; */
          ystart = 2.0 * sy_bin - 1.0;

          /* 'compute:75' yend = 2*(sy_bin+1)-2; */
          yend = 2.0 * (sy_bin + 1.0) - 2.0;

          /* 'compute:76' bins_sel = zeros((xend-xstart+1)*(yend-ystart+1),1); */
          bin_div_tmp = ((xend - xstart) + 1.0) * ((yend - ystart) + 1.0);
          i9 = feats_sel_num->size[0];
          feats_sel_num->size[0] = (int32_T)bin_div_tmp;
          emxEnsureCapacity((emxArray__common *)feats_sel_num, i9, (int32_T)
                            sizeof(real_T));
          loop_ub = (int32_T)bin_div_tmp - 1;
          for (i9 = 0; i9 <= loop_ub; i9++) {
            feats_sel_num->data[i9] = 0.0;
          }

          /* 'compute:77' bsidx = 1; */
          code_idx = 1U;

          /* 'compute:78' for xri = xstart:xend */
          while (xstart <= xend) {
            /* 'compute:79' for yri = ystart:yend */
            for (bin_div_tmp = ystart; bin_div_tmp <= yend; bin_div_tmp++) {
              /* 'compute:80' bins_sel(bsidx) = prev_level_start_bin + ... */
              /* 'compute:81'                                 prev_level_bin_divs*(xri-1) + yri - 1; */
              feats_sel_num->data[(int32_T)code_idx - 1] =
                ((prev_level_start_bin + prev_level_bin_divs * (xstart - 1.0)) +
                 bin_div_tmp) - 1.0;

              /* 'compute:82' bsidx = bsidx + 1; */
              code_idx++;
            }

            xstart++;
          }

          /*  combine bins */
          /* 'compute:87' if strcmp(obj.pool_type,'sum') */
          if (strcmp(obj_pool_type, "sum") == 0) {
            /* 'compute:88' pcode(:,level_start_bin + ... */
            /* 'compute:89'                             level_bin_divs*(sx_bin-1) + ... */
            /* 'compute:90'                             sy_bin - 1) = sum(pcode(:,bins_sel),2); */
            i9 = (int32_T)(((level_start_bin + level_bin_divs * (sx_bin - 1.0))
                            + sy_bin) - 1.0) - 1;
            c_pcode = e_pcode->size[0] * e_pcode->size[1];
            e_pcode->size[0] = b_pcode->size[0];
            e_pcode->size[1] = feats_sel_num->size[0];
            emxEnsureCapacity((emxArray__common *)e_pcode, c_pcode, (int32_T)
                              sizeof(real32_T));
            loop_ub = feats_sel_num->size[0] - 1;
            for (c_pcode = 0; c_pcode <= loop_ub; c_pcode++) {
              b_loop_ub = b_pcode->size[0] - 1;
              for (f_pcode = 0; f_pcode <= b_loop_ub; f_pcode++) {
                e_pcode->data[f_pcode + e_pcode->size[0] * c_pcode] =
                  b_pcode->data[f_pcode + b_pcode->size[0] * ((int32_T)
                  feats_sel_num->data[c_pcode] - 1)];
              }
            }

            sum(e_pcode, r11);
            loop_ub = r11->size[0] - 1;
            for (c_pcode = 0; c_pcode <= loop_ub; c_pcode++) {
              b_pcode->data[c_pcode + b_pcode->size[0] * i9] = r11->data[c_pcode];
            }
          }

          /* 'compute:92' if strcmp(obj.pool_type,'max') */
          if (strcmp(obj_pool_type, "max") == 0) {
            /* 'compute:93' pcode(:,level_start_bin + ... */
            /* 'compute:94'                             level_bin_divs*(sx_bin-1) + ... */
            /* 'compute:95'                             sy_bin - 1) = max(pcode(:,bins_sel),[],2); */
            i9 = (int32_T)(((level_start_bin + level_bin_divs * (sx_bin - 1.0))
                            + sy_bin) - 1.0) - 1;
            c_pcode = d_pcode->size[0] * d_pcode->size[1];
            d_pcode->size[0] = b_pcode->size[0];
            d_pcode->size[1] = feats_sel_num->size[0];
            emxEnsureCapacity((emxArray__common *)d_pcode, c_pcode, (int32_T)
                              sizeof(real32_T));
            loop_ub = feats_sel_num->size[0] - 1;
            for (c_pcode = 0; c_pcode <= loop_ub; c_pcode++) {
              b_loop_ub = b_pcode->size[0] - 1;
              for (f_pcode = 0; f_pcode <= b_loop_ub; f_pcode++) {
                d_pcode->data[f_pcode + d_pcode->size[0] * c_pcode] =
                  b_pcode->data[f_pcode + b_pcode->size[0] * ((int32_T)
                  feats_sel_num->data[c_pcode] - 1)];
              }
            }

            b_max(d_pcode, r11);
            loop_ub = r11->size[0] - 1;
            for (c_pcode = 0; c_pcode <= loop_ub; c_pcode++) {
              b_pcode->data[c_pcode + b_pcode->size[0] * i9] = r11->data[c_pcode];
            }
          }
        }
      }

      /* 'compute:100' prev_level_start_bin = level_start_bin; */
      prev_level_start_bin = level_start_bin;

      /* 'compute:101' prev_level_bin_divs = level_bin_divs; */
      prev_level_bin_divs = level_bin_divs;
      i++;
    }

    emxFree_real32_T(&e_pcode);
    emxFree_real32_T(&d_pcode);
    emxFree_real_T(&feats_sel_num);
  }

  /*  now compute the three horizontal bins */
  /* 'compute:106' if obj.horiz_divs > 0 */
  if (obj_horiz_divs > 0.0 && is_spatial) {
    emxInit_int32_T(&d_frames, 2);

    /* 'compute:107' h_hunit = imsize(1) / obj.horiz_divs; */
    /* 'compute:108' h_ybin = ceil(frames(2,:) / h_hunit); */
    i9 = d_frames->size[0] * d_frames->size[1];
    d_frames->size[0] = 1;
    d_frames->size[1] = frames->size[1];
    emxEnsureCapacity((emxArray__common *)d_frames, i9, (int32_T)sizeof(int32_T));
    loop_ub = frames->size[1] - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      d_frames->data[d_frames->size[0] * i9] = frames->data[1 + frames->size[0] *
        i9];
    }

    c_mrdivide_ceil(d_frames, (double)video_height / (double)obj_horiz_divs, y_bin);
/*  for(int i = 0; i < y_bin->size[1]; i++){
	  fprintf(stderr, "%d %d\n", d_frames->data[i], y_bin->data[i]);
  }
  fprintf(stderr, "%d %g %d\n", video_height, obj_horiz_divs, b_mrdivide(video_height, obj_horiz_divs));
  exit(-1);*/
  
  


    /* 'compute:109' for sy_bin = 1:obj.horiz_divs */
    sy_bin = 1.0;
    emxFree_int32_T(&d_frames);
    emxInit_boolean_T(&c_y_bin, 2);
    while (sy_bin <= obj_horiz_divs) {
      /* 'compute:110' feats_sel = feats(:, (h_ybin == sy_bin)); */
      i9 = c_y_bin->size[0] * c_y_bin->size[1];
      c_y_bin->size[0] = 1;
      c_y_bin->size[1] = y_bin->size[1];
      emxEnsureCapacity((emxArray__common *)c_y_bin, i9, (int32_T)sizeof
                        (boolean_T));
      loop_ub = y_bin->size[0] * y_bin->size[1] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        c_y_bin->data[i9] = ((real_T)y_bin->data[i9] == sy_bin);
      }

      eml_li_find(c_y_bin, r10);
      c_pcode = r10->size[1];
      i9 = feats_sel->size[0] * feats_sel->size[1];
      feats_sel->size[0] = feats->size[0];
      feats_sel->size[1] = c_pcode;
      emxEnsureCapacity((emxArray__common *)feats_sel, i9, (int32_T)sizeof
                        (real32_T));
      loop_ub = c_pcode - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        b_loop_ub = feats->size[0] - 1;
        for (c_pcode = 0; c_pcode <= b_loop_ub; c_pcode++) {
          feats_sel->data[c_pcode + feats_sel->size[0] * i9] = feats->
            data[c_pcode + feats->size[0] * (r10->data[i9] - 1)];
        }
      }

      fprintf(stderr, "feats_sel %d %d\n", feats_sel->size[0], feats_sel->size[1]);
      /* 'compute:111' if ~isempty(feats_sel) */
      if (!((feats_sel->size[0] == 0) || (feats_sel->size[1] == 0))) {
        /* 'compute:112' code =  FEencode(obj.encoder_, feats_sel); */
        FEencode(obj_encoder__codebook__n_gauss, obj_encoder__codebook__n_dim,
                 feats_sel, pcode_norm, fh);

        /*                  if nnz(isnan(code)), error('Code contains NaNs'); end */
        /* 'compute:114' pcode(:,bin_quads_count+sy_bin) = code; */
        i9 = r8->size[0];
        r8->size[0] = b_pcode->size[0];
        emxEnsureCapacity((emxArray__common *)r8, i9, (int32_T)sizeof(int32_T));
        loop_ub = b_pcode->size[0] - 1;
        for (i9 = 0; i9 <= loop_ub; i9++) {
          r8->data[i9] = i9;
        }

        i9 = (int32_T)(bin_quads_count + sy_bin) - 1;
        c_pcode = r8->size[0];
        loop_ub = c_pcode - 1;
        for (c_pcode = 0; c_pcode <= loop_ub; c_pcode++) {
          b_pcode->data[r8->data[c_pcode] + b_pcode->size[0] * i9] =
            pcode_norm->data[c_pcode];
        }
      } else {
        /* 'compute:115' else */
        /* 'compute:116' error('SPMPool:EmptyBin','empty bin!'); */
      }

      sy_bin++;
    }

    emxFree_boolean_T(&c_y_bin);
  }

  emxFree_int32_T(&r10);
  emxFree_int32_T(&r8);
  emxFree_int32_T(&y_bin);

  /* 'compute:121' if true */
  /*  now combine the first binset to make up the whole image bin */
  /* 'compute:124' if strcmp(obj.pool_type,'sum') */
  if (strcmp(obj_pool_type, "sum") == 0) {
    /* 'compute:125' pcode(:, end) = sum(pcode(:, 1 : obj.quad_divs ^ 2),2); */
    bin_div_tmp = mpower(obj_quad_divs);
    if (1.0 > bin_div_tmp) {
      i9 = 0;
    } else {
      i9 = (int32_T)bin_div_tmp;
    }

    emxInit_real32_T(&g_pcode, 2);
    c_pcode = b_pcode->size[1] - 1;
    f_pcode = g_pcode->size[0] * g_pcode->size[1];
    g_pcode->size[0] = b_pcode->size[0];
    g_pcode->size[1] = i9;
    emxEnsureCapacity((emxArray__common *)g_pcode, f_pcode, (int32_T)sizeof
                      (real32_T));
    loop_ub = i9 - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      b_loop_ub = b_pcode->size[0] - 1;
      for (f_pcode = 0; f_pcode <= b_loop_ub; f_pcode++) {
        g_pcode->data[f_pcode + g_pcode->size[0] * i9] = b_pcode->data[f_pcode +
          b_pcode->size[0] * i9];
      }
    }

    sum(g_pcode, r11);
    emxFree_real32_T(&g_pcode);
    loop_ub = r11->size[0] - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      b_pcode->data[i9 + b_pcode->size[0] * c_pcode] = r11->data[i9];
    }

    /*  * (feats_sel_num / sum(feats_sel_num)); */
  } else {
    if ( strcmp(obj_pool_type, "max") == 0 ) {
      /* 'compute:126' elseif strcmp(obj.pool_type,'max') */
      /* 'compute:127' pcode(:,end) = max(pcode(:,1:obj.quad_divs^2),[],2); */
      bin_div_tmp = mpower(obj_quad_divs);
      if (1.0 > bin_div_tmp) {
        i9 = 0;
      } else {
        i9 = (int32_T)bin_div_tmp;
      }

      emxInit_real32_T(&g_pcode, 2);
      c_pcode = b_pcode->size[1] - 1;
      f_pcode = g_pcode->size[0] * g_pcode->size[1];
      g_pcode->size[0] = b_pcode->size[0];
      g_pcode->size[1] = i9;
      emxEnsureCapacity((emxArray__common *)g_pcode, f_pcode, (int32_T)sizeof
                        (real32_T));
      loop_ub = i9 - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        b_loop_ub = b_pcode->size[0] - 1;
        for (f_pcode = 0; f_pcode <= b_loop_ub; f_pcode++) {
          g_pcode->data[f_pcode + g_pcode->size[0] * i9] = b_pcode->data[f_pcode
            + b_pcode->size[0] * i9];
        }
      }

      b_max(g_pcode, r11);
      emxFree_real32_T(&g_pcode);
      loop_ub = r11->size[0] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        b_pcode->data[i9 + b_pcode->size[0] * c_pcode] = r11->data[i9];
      }
    }
  }

  /* 'compute:135' if ~is_spatial */
  if (!is_spatial) {
    b_emxInit_int32_T(&r12, 1);

    /* 'compute:136' pcode = pcode(:,end); */
    f_pcode = b_pcode->size[0];
    b_loop_ub = b_pcode->size[1] - 1;
    c_pcode = b_pcode->size[0];
    i9 = r12->size[0];
    r12->size[0] = c_pcode;
    emxEnsureCapacity((emxArray__common *)r12, i9, (int32_T)sizeof(int32_T));
    loop_ub = c_pcode - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      r12->data[i9] = 1 + i9;
    }

    b_emxInit_real32_T(&h_pcode, 1);
    i9 = h_pcode->size[0];
    h_pcode->size[0] = f_pcode;
    emxEnsureCapacity((emxArray__common *)h_pcode, i9, (int32_T)sizeof(real32_T));
    loop_ub = f_pcode - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      h_pcode->data[i9] = b_pcode->data[i9 + b_pcode->size[0] * b_loop_ub];
    }

    iv4[0] = r12->size[0];
    iv4[1] = 1;
    i9 = b_pcode->size[0] * b_pcode->size[1];
    b_pcode->size[0] = iv4[0];
    b_pcode->size[1] = iv4[1];
    emxEnsureCapacity((emxArray__common *)b_pcode, i9, (int32_T)sizeof(real32_T));
    emxFree_int32_T(&r12);
    loop_ub = iv4[1] - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      b_loop_ub = iv4[0] - 1;
      for (c_pcode = 0; c_pcode <= b_loop_ub; c_pcode++) {
        i_pcode = *h_pcode;
        i_pcode.size = (int32_T *)&iv4;
        i_pcode.numDimensions = 1;
        b_pcode->data[c_pcode + b_pcode->size[0] * i9] = i_pcode.data[c_pcode +
          i_pcode.size[0] * i9];
      }
    }

    emxFree_real32_T(&h_pcode);
  }

  /*      if nnz(pcode(:,end)) < 1, error('Code is all zeros!'); end */
  /*  now normalize all sub-bins */
  /* 'compute:143' if strcmp(obj.subbin_norm_type, 'l2') */
  if (n_eml_strcmp(obj_subbin_norm_type)) {
    emxInit_real32_T(&b_pcode_norm, 2);

    /* 'compute:145' pcode_norm = sqrt(sum(pcode .^ 2, 1)); */
    b_power(b_pcode, feats_sel);
    b_sum(feats_sel, pcode_norm);
    b_sqrt(pcode_norm);

    /* 'compute:146' pcode_norm = max(pcode_norm, eps); */
    i9 = b_pcode_norm->size[0] * b_pcode_norm->size[1];
    b_pcode_norm->size[0] = 1;
    b_pcode_norm->size[1] = pcode_norm->size[1];
    emxEnsureCapacity((emxArray__common *)b_pcode_norm, i9, (int32_T)sizeof
                      (real32_T));
    loop_ub = pcode_norm->size[0] * pcode_norm->size[1] - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      b_pcode_norm->data[i9] = pcode_norm->data[i9];
    }

    emxInit_real32_T(&c_pcode_norm, 2);
    c_max(b_pcode_norm, pcode_norm);

    /* 'compute:147' pcode = bsxfun(@times, pcode, 1 ./ pcode_norm); */
    i9 = c_pcode_norm->size[0] * c_pcode_norm->size[1];
    c_pcode_norm->size[0] = 1;
    c_pcode_norm->size[1] = pcode_norm->size[1];
    emxEnsureCapacity((emxArray__common *)c_pcode_norm, i9, (int32_T)sizeof
                      (real32_T));
    emxFree_real32_T(&b_pcode_norm);
    loop_ub = pcode_norm->size[0] * pcode_norm->size[1] - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      c_pcode_norm->data[i9] = pcode_norm->data[i9];
    }

    emxInit_real32_T(&j_pcode, 2);
    d_rdivide(1.0, c_pcode_norm, pcode_norm);
    i9 = j_pcode->size[0] * j_pcode->size[1];
    j_pcode->size[0] = b_pcode->size[0];
    j_pcode->size[1] = b_pcode->size[1];
    emxEnsureCapacity((emxArray__common *)j_pcode, i9, (int32_T)sizeof(real32_T));
    emxFree_real32_T(&c_pcode_norm);
    loop_ub = b_pcode->size[0] * b_pcode->size[1] - 1;
    for (i9 = 0; i9 <= loop_ub; i9++) {
      j_pcode->data[i9] = b_pcode->data[i9];
    }

    bsxfun(j_pcode, pcode_norm, b_pcode);
    emxFree_real32_T(&j_pcode);
  } else {
    if (o_eml_strcmp(obj_subbin_norm_type)) {
      emxInit_real32_T(&b_pcode_norm, 2);

      /* 'compute:149' elseif strcmp(obj.subbin_norm_type, 'l1') */
      /* 'compute:151' pcode_norm = sum(pcode, 1); */
      b_sum(b_pcode, pcode_norm);

      /* 'compute:152' pcode_norm = max(pcode_norm, eps); */
      i9 = b_pcode_norm->size[0] * b_pcode_norm->size[1];
      b_pcode_norm->size[0] = 1;
      b_pcode_norm->size[1] = pcode_norm->size[1];
      emxEnsureCapacity((emxArray__common *)b_pcode_norm, i9, (int32_T)sizeof
                        (real32_T));
      loop_ub = pcode_norm->size[0] * pcode_norm->size[1] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        b_pcode_norm->data[i9] = pcode_norm->data[i9];
      }

      emxInit_real32_T(&c_pcode_norm, 2);
      c_max(b_pcode_norm, pcode_norm);

      /* 'compute:153' pcode = bsxfun(@times, pcode, 1 ./ pcode_norm); */
      i9 = c_pcode_norm->size[0] * c_pcode_norm->size[1];
      c_pcode_norm->size[0] = 1;
      c_pcode_norm->size[1] = pcode_norm->size[1];
      emxEnsureCapacity((emxArray__common *)c_pcode_norm, i9, (int32_T)sizeof
                        (real32_T));
      emxFree_real32_T(&b_pcode_norm);
      loop_ub = pcode_norm->size[0] * pcode_norm->size[1] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        c_pcode_norm->data[i9] = pcode_norm->data[i9];
      }

      emxInit_real32_T(&j_pcode, 2);
      d_rdivide(1.0, c_pcode_norm, pcode_norm);
      i9 = j_pcode->size[0] * j_pcode->size[1];
      j_pcode->size[0] = b_pcode->size[0];
      j_pcode->size[1] = b_pcode->size[1];
      emxEnsureCapacity((emxArray__common *)j_pcode, i9, (int32_T)sizeof
                        (real32_T));
      emxFree_real32_T(&c_pcode_norm);
      loop_ub = b_pcode->size[0] * b_pcode->size[1] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        j_pcode->data[i9] = b_pcode->data[i9];
      }

      bsxfun(j_pcode, pcode_norm, b_pcode);
      emxFree_real32_T(&j_pcode);
    }
  }

  emxFree_real32_T(&pcode_norm);
  emxFree_real32_T(&feats_sel);

  /*  vectorise */
  /* 'compute:158' pcode = pcode(:); */
  i9 = pcode->size[0];
  pcode->size[0] = b_pcode->size[0] * b_pcode->size[1];
  //fprintf(stderr, "%d %d\n", b_pcode->size[0], b_pcode->size[1]);
  emxEnsureCapacity((emxArray__common *)pcode, i9, (int32_T)sizeof(real32_T));
  loop_ub = b_pcode->size[0] * b_pcode->size[1] - 1;
  for (i9 = 0; i9 <= loop_ub; i9++) {
    pcode->data[i9] = b_pcode->data[i9];
  }

  /*  now normalize whole code */
  /* 'compute:161' if strcmp(obj.norm_type,'l2') */
  if (p_eml_strcmp(obj_norm_type)) {
    /* 'compute:162' pcode = pcode/norm(pcode,2); */
    k_pcode[0] = b_pcode->size[0] * b_pcode->size[1];
    l_pcode[0] = b_pcode->size[0] * b_pcode->size[1];
    i_pcode = *b_pcode;
    i_pcode.size = (int32_T *)&k_pcode;
    i_pcode.numDimensions = 1;
    m_pcode = *b_pcode;
    m_pcode.size = (int32_T *)&l_pcode;
    m_pcode.numDimensions = 1;
    d_mrdivide(&i_pcode, norm(&m_pcode), pcode);
  } else {
    if (q_eml_strcmp(obj_norm_type)) {
      /* 'compute:163' elseif strcmp(obj.norm_type,'l1') */
      /* 'compute:164' pcode = pcode/norm(pcode,1); */
      n_pcode[0] = b_pcode->size[0] * b_pcode->size[1];
      o_pcode[0] = b_pcode->size[0] * b_pcode->size[1];
      i_pcode = *b_pcode;
      i_pcode.size = (int32_T *)&n_pcode;
      i_pcode.numDimensions = 1;
      m_pcode = *b_pcode;
      m_pcode.size = (int32_T *)&o_pcode;
      m_pcode.numDimensions = 1;
      d_mrdivide(&i_pcode, b_norm(&m_pcode), pcode);
    }
  }

  emxFree_real32_T(&b_pcode);

  /*  now apply kernel map if specified */
  /* 'compute:168' if ~isequal(obj.kermap, 'none') */
  if (!isequal(obj_kermap)) {
    /*  (note: when adding extra kernel maps, note that the getDim function */
    /*  must also be modified to reflect the appropriate increase in code */
    /*  dimensionality) */
    /* 'compute:172' if strcmp(obj.kermap,'homker') */
    if (r_eml_strcmp(obj_kermap) || (!s_eml_strcmp(obj_kermap))) {
      /*  chi-squared approximation */
      /* pcode = vl_homkermap(pcode, 1, 'kchi2'); */
    } else {
      /* 'compute:175' elseif strcmp(obj.kermap,'hellinger') */
      /*  "generalised" (signed) Hellinger kernel */
      /* 'compute:177' pcode = sign(pcode) .* sqrt(abs(pcode)); */
      i9 = r11->size[0];
      r11->size[0] = pcode->size[0];
      emxEnsureCapacity((emxArray__common *)r11, i9, (int32_T)sizeof(real32_T));
      loop_ub = pcode->size[0] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        r11->data[i9] = pcode->data[i9];
      }

      b_emxInit_real32_T(&p_pcode, 1);
      b_sign(r11);
      i9 = p_pcode->size[0];
      p_pcode->size[0] = pcode->size[0];
      emxEnsureCapacity((emxArray__common *)p_pcode, i9, (int32_T)sizeof
                        (real32_T));
      loop_ub = pcode->size[0] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        p_pcode->data[i9] = pcode->data[i9];
      }

      c_abs(p_pcode, pcode);
      c_sqrt(pcode);
      i9 = pcode->size[0];
      pcode->size[0] = r11->size[0];
      emxEnsureCapacity((emxArray__common *)pcode, i9, (int32_T)sizeof(real32_T));
      emxFree_real32_T(&p_pcode);
      loop_ub = r11->size[0] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        pcode->data[i9] *= r11->data[i9];
      }
    }

    /*  now post-normalize whole code */
    /* 'compute:181' if strcmp(obj.post_norm_type,'l2') */
    if (p_eml_strcmp(obj_post_norm_type)) {
      b_emxInit_real32_T(&q_pcode, 1);

      /* 'compute:182' pcode = pcode/norm(pcode,2); */
      i9 = q_pcode->size[0];
      q_pcode->size[0] = pcode->size[0];
      emxEnsureCapacity((emxArray__common *)q_pcode, i9, (int32_T)sizeof
                        (real32_T));
      loop_ub = pcode->size[0] - 1;
      for (i9 = 0; i9 <= loop_ub; i9++) {
        q_pcode->data[i9] = pcode->data[i9];
      }

      d_mrdivide(q_pcode, norm(pcode), pcode);
      emxFree_real32_T(&q_pcode);
    } else {
      if (q_eml_strcmp(obj_post_norm_type)) {
        b_emxInit_real32_T(&q_pcode, 1);

        /* 'compute:183' elseif strcmp(obj.post_norm_type,'l1') */
        /* 'compute:184' pcode = pcode/norm(pcode,1); */
        i9 = q_pcode->size[0];
        q_pcode->size[0] = pcode->size[0];
        emxEnsureCapacity((emxArray__common *)q_pcode, i9, (int32_T)sizeof
                          (real32_T));
        loop_ub = pcode->size[0] - 1;
        for (i9 = 0; i9 <= loop_ub; i9++) {
          q_pcode->data[i9] = pcode->data[i9];
        }

        d_mrdivide(q_pcode, b_norm(pcode), pcode);
        emxFree_real32_T(&q_pcode);
      }
    }
  }

  emxFree_real32_T(&r11);
}

/* End of code generation (compute.cpp) */
