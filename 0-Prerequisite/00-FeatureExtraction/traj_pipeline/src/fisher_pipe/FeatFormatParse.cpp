/*
 * FeatFormatParse.cpp
 *
 * Code generation for function 'FeatFormatParse'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "FeatFormatParse.h"
#include "FisherVectorEncode_emxutil.h"
#include "repmat.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/*
 * function feat_format = FeatFormatParse(feat_type)
 */
void FeatFormatParse(const char_T feat_type[1024], emxArray_char_T
                     *feat_format_regex, real32_T *feat_format_feat_dim, real32_T
                     *feat_format_feat_st_col, real32_T *feat_format_feat_ed_col,
                     real32_T *feat_format_feat_st_row, real32_T *feat_format_x_col,
                     real32_T *feat_format_y_col, boolean_T *feat_format_spatial)
{
  char_T cv12[786];
  int32_T i4;
  char_T cv13[399];
  char_T cv14[1167];
  char_T cv15[510];
  char_T cv16[150];
  char_T cv17[1200];
  char_T cv18[1404];
  char_T cv19[120];

  /* 'FeatFormatParse:3' if(strcmp(feat_type, 'MoSIFT_resized') == 1) */
  if (strcmp("MoSIFT_resized", feat_type) == 0) {
    /* 'FeatFormatParse:4' feat_format.feat_dim = 256; */
    *feat_format_feat_dim = 256.0;

    /* 'FeatFormatParse:5' feat_format.feat_st_col = 7; */
    *feat_format_feat_st_col = 7.0;

    /* 'FeatFormatParse:6' feat_format.feat_ed_col = 262; */
    *feat_format_feat_ed_col = 262.0;

    /* 'FeatFormatParse:7' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* feat_format.time_col = 3; */
    /* 'FeatFormatParse:9' feat_format.x_col = 1; */
    *feat_format_x_col = 1.0;

    /* 'FeatFormatParse:10' feat_format.y_col = 2; */
    *feat_format_y_col = 2.0;

    /* 'FeatFormatParse:11' feat_format.spatial = true; */
    *feat_format_spatial = TRUE;

    /* 'FeatFormatParse:12' feat_format.regex = repmat('%f ',1,262); */
    repmat(cv12);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 786;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 786; i4++) {
      feat_format_regex->data[i4] = cv12[i4];
    }
  } else if (strcmp("sift", feat_type) == 0) {
    /* 'FeatFormatParse:13' elseif(strcmp(feat_type, 'sift') == 1) */
    /* 'FeatFormatParse:14' feat_format.feat_dim = 128; */
    *feat_format_feat_dim = 128.0;

    /* 'FeatFormatParse:15' feat_format.feat_st_col = 6; */
    *feat_format_feat_st_col = 6.0;

    /* 'FeatFormatParse:16' feat_format.feat_ed_col = 133; */
    *feat_format_feat_ed_col = 133.0;

    /* 'FeatFormatParse:17' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* 'FeatFormatParse:18' feat_format.x_col = 1; */
    *feat_format_x_col = 1.0;

    /* 'FeatFormatParse:19' feat_format.y_col = 2; */
    *feat_format_y_col = 2.0;

    /* 'FeatFormatParse:20' feat_format.spatial = true; */
    *feat_format_spatial = TRUE;

    /* 'FeatFormatParse:21' feat_format.regex = repmat('%f ',1,133); */
    b_repmat(cv13);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 399;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 399; i4++) {
      feat_format_regex->data[i4] = cv13[i4];
    }
  } else if (strcmp("csift", feat_type) == 0) {
    /* 'FeatFormatParse:22' elseif(strcmp(feat_type, 'csift') == 1) */
    /* 'FeatFormatParse:23' feat_format.feat_dim = 384; */
    *feat_format_feat_dim = 384.0;

    /* 'FeatFormatParse:24' feat_format.feat_st_col = 6; */
    *feat_format_feat_st_col = 6.0;

    /* 'FeatFormatParse:25' feat_format.feat_ed_col = 389; */
    *feat_format_feat_ed_col = 389.0;

    /* 'FeatFormatParse:26' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* 'FeatFormatParse:27' feat_format.x_col = 1; */
    *feat_format_x_col = 1.0;

    /* 'FeatFormatParse:28' feat_format.y_col = 2; */
    *feat_format_y_col = 2.0;

    /* 'FeatFormatParse:29' feat_format.spatial = true; */
    *feat_format_spatial = TRUE;

    /* 'FeatFormatParse:30' feat_format.regex = repmat('%f ',1,389); */
    c_repmat(cv14);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 1167;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 1167; i4++) {
      feat_format_regex->data[i4] = cv14[i4];
    }
  } else if ((strcmp("stip_new", feat_type) == 0) || (strcmp("stip_old", feat_type) == 0) ||
             (strcmp("stip", feat_type) == 0)) {
    /* 'FeatFormatParse:31' elseif(strcmp(feat_type, 'stip_new') == 1 | strcmp(feat_type, 'stip_old') == 1 | strcmp(feat_type, 'stip') == 1 ) */
    /* 'FeatFormatParse:32' feat_format.feat_dim = 162; */
    *feat_format_feat_dim = 162.0;

    /* 'FeatFormatParse:33' feat_format.feat_st_col = 9; */
    *feat_format_feat_st_col = 9.0;

    /* 'FeatFormatParse:34' feat_format.feat_ed_col = 170; */
    *feat_format_feat_ed_col = 170.0;

    /* 'FeatFormatParse:35' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* feat_format.time_col = 3; */
    /* 'FeatFormatParse:37' feat_format.x_col = 1; */
    *feat_format_x_col = 1.0;

    /* 'FeatFormatParse:38' feat_format.y_col = 2; */
    *feat_format_y_col = 2.0;

    /* 'FeatFormatParse:39' feat_format.spatial = true; */
    *feat_format_spatial = TRUE;

    /* 'FeatFormatParse:40' feat_format.regex = repmat('%f ',1,170); */
    d_repmat(cv15);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 510;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 510; i4++) {
      feat_format_regex->data[i4] = cv15[i4];
    }
  } else if (strcmp("tch", feat_type) == 0) {
    /* 'FeatFormatParse:41' elseif(strcmp(feat_type, 'tch') == 1) */
    /* 'FeatFormatParse:42' feat_format.feat_dim = 45; */
    *feat_format_feat_dim = 45.0;

    /* 'FeatFormatParse:43' feat_format.feat_st_col = 6; */
    *feat_format_feat_st_col = 6.0;

    /* 'FeatFormatParse:44' feat_format.feat_ed_col = 50; */
    *feat_format_feat_ed_col = 50.0;

    /* 'FeatFormatParse:45' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* 'FeatFormatParse:46' feat_format.x_col = 1; */
    *feat_format_x_col = 1.0;

    /* 'FeatFormatParse:47' feat_format.y_col = 2; */
    *feat_format_y_col = 2.0;

    /* 'FeatFormatParse:48' feat_format.spatial = true; */
    *feat_format_spatial = TRUE;

    /* 'FeatFormatParse:49' feat_format.regex = repmat('%f ',1,50); */
    e_repmat(cv16);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 150;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 150; i4++) {
      feat_format_regex->data[i4] = cv16[i4];
    }
  } else if (strcmp("trajectory", feat_type) == 0) {
    /* 'FeatFormatParse:50' elseif(strcmp(feat_type, 'trajectory') == 1) */
    /* 'FeatFormatParse:51' feat_format.feat_dim = 396; */
    *feat_format_feat_dim = 396.0;

    /* 'FeatFormatParse:52' feat_format.feat_st_col = 5; */
    *feat_format_feat_st_col = 5.0;

    /* 'FeatFormatParse:53' feat_format.feat_ed_col = 400; */
    *feat_format_feat_ed_col = 400.0;

    /* 'FeatFormatParse:54' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* 'FeatFormatParse:55' feat_format.x_col = 1; */
    *feat_format_x_col = 1.0;

    /* 'FeatFormatParse:56' feat_format.y_col = 2; */
    *feat_format_y_col = 2.0;

    /* 'FeatFormatParse:57' feat_format.spatial = true; */
    *feat_format_spatial = TRUE;

    /* 'FeatFormatParse:58' feat_format.regex = repmat('%f ',1,400); */
    f_repmat(cv17);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 1200;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 1200; i4++) {
      feat_format_regex->data[i4] = cv17[i4];
    }
  } else if (strcmp("TRAJSTAB", feat_type) == 0) {
    /* 'FeatFormatParse:59' elseif(strcmp(feat_type, 'TRAJ_NIC') == 1) */
    /* 'FeatFormatParse:60' feat_format.feat_dim = 426; */
    *feat_format_feat_dim = 426.0;

    /* 'FeatFormatParse:61' feat_format.feat_st_col = 43; */
    *feat_format_feat_st_col = 11.0;

    /* 'FeatFormatParse:62' feat_format.feat_ed_col = 468; */
    *feat_format_feat_ed_col = 436.0;

    /* 'FeatFormatParse:63' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* feat_format.time_col = 1; */
    /* 'FeatFormatParse:65' feat_format.x_col = 5; */
    *feat_format_x_col = 2.0;

    /* 'FeatFormatParse:66' feat_format.y_col = 6; */
    *feat_format_y_col = 3.0;

    /* 'FeatFormatParse:67' feat_format.spatial = true; */
    *feat_format_spatial = TRUE;

    //this guy is not used..gomibako
    /* 'FeatFormatParse:68' feat_format.regex = repmat('%f ',1,468); */
    g_repmat(cv18);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 1404;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 1404; i4++) {
      feat_format_regex->data[i4] = cv18[i4];
    }
  } else if (strcmp("mfcc", feat_type) == 0) {
    /* 'FeatFormatParse:69' elseif(strcmp(feat_type, 'mfcc') == 1) */
    /* 'FeatFormatParse:70' feat_format.feat_dim = 40; */
    *feat_format_feat_dim = 40.0;

    /* 'FeatFormatParse:71' feat_format.feat_st_col = 1; */
    *feat_format_feat_st_col = 1.0;

    /* 'FeatFormatParse:72' feat_format.feat_ed_col = 40; */
    *feat_format_feat_ed_col = 40.0;

    /* 'FeatFormatParse:73' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* 'FeatFormatParse:74' feat_format.x_col = -1; */
    *feat_format_x_col = -1.0;

    /*  MFCC doesn't have spatial coordiantes! */
    /* 'FeatFormatParse:75' feat_format.y_col = -1; */
    *feat_format_y_col = -1.0;

    /* 'FeatFormatParse:76' feat_format.spatial = false; */
    *feat_format_spatial = FALSE;

    /* 'FeatFormatParse:77' feat_format.regex = repmat('%f ',1,40); */
    h_repmat(cv19);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 120;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 120; i4++) {
      feat_format_regex->data[i4] = cv19[i4];
    }
  } else {
    /* 'FeatFormatParse:78' else */
    /* 'FeatFormatParse:79' feat_format.feat_dim = 40; */
    *feat_format_feat_dim = 40.0;

    /* 'FeatFormatParse:80' feat_format.feat_st_col = 1; */
    *feat_format_feat_st_col = 1.0;

    /* 'FeatFormatParse:81' feat_format.feat_ed_col = 40; */
    *feat_format_feat_ed_col = 40.0;

    /* 'FeatFormatParse:82' feat_format.feat_st_row = 1; */
    *feat_format_feat_st_row = 1.0;

    /* 'FeatFormatParse:83' feat_format.x_col = -1; */
    *feat_format_x_col = -1.0;

    /*  MFCC doesn't have spatial coordiantes! */
    /* 'FeatFormatParse:84' feat_format.y_col = -1; */
    *feat_format_y_col = -1.0;

    /* 'FeatFormatParse:85' feat_format.spatial = false; */
    *feat_format_spatial = FALSE;

    /* 'FeatFormatParse:86' feat_format.regex = repmat('%f ',1,40); */
    h_repmat(cv19);
    i4 = feat_format_regex->size[0] * feat_format_regex->size[1];
    feat_format_regex->size[0] = 1;
    feat_format_regex->size[1] = 120;
    emxEnsureCapacity((emxArray__common *)feat_format_regex, i4, (int32_T)sizeof
                      (char_T));
    for (i4 = 0; i4 < 120; i4++) {
      feat_format_regex->data[i4] = cv19[i4];
    }

    /* 'FeatFormatParse:87' error('invalid feature type'); */
    fprintf(stderr, "invalid feature type %s\n", feat_type);
    exit(-1);
  }
}

/* End of code generation (FeatFormatParse.cpp) */
