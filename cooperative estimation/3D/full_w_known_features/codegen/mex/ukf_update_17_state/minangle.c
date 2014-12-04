/*
 * minangle.c
 *
 * Code generation for function 'minangle'
 *
 * C source code generated on: Thu Dec  4 12:26:47 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_17_state.h"
#include "minangle.h"
#include "ukf_update_17_state_emxutil.h"
#include "ukf_update_17_state_mexutil.h"
#include "abs.h"
#include "ukf_update_17_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 51, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo lj_emlrtRSI = { 11, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo mj_emlrtRSI = { 4, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo nj_emlrtRSI = { 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo oj_emlrtRSI = { 7, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo tj_emlrtRSI = { 41, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRSInfo vj_emlrtRSI = { 230, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRSInfo wj_emlrtRSI = { 239, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtMCInfo d_emlrtMCI = { 52, 9, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo e_emlrtMCI = { 51, 15, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo y_emlrtMCI = { 11, 9, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtMCInfo fb_emlrtMCI = { 239, 9, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRTEInfo gb_emlrtRTEI = { 1, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRTEInfo tb_emlrtRTEI = { 127, 5, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRTEInfo ub_emlrtRTEI = { 5, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRTEInfo vb_emlrtRTEI = { 33, 6, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtECInfo xc_emlrtECI = { -1, 6, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo yc_emlrtECI = { -1, 8, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo ad_emlrtECI = { -1, 7, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo bd_emlrtECI = { -1, 7, 39, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo cd_emlrtECI = { -1, 7, 21, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo dd_emlrtECI = { -1, 5, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo ed_emlrtECI = { -1, 5, 39, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo fd_emlrtECI = { -1, 5, 21, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo gd_emlrtECI = { -1, 4, 12, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo hd_emlrtECI = { -1, 4, 46, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo id_emlrtECI = { -1, 4, 68, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo jd_emlrtECI = { -1, 4, 50, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo kd_emlrtECI = { -1, 4, 13, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo ld_emlrtECI = { -1, 4, 35, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo md_emlrtECI = { -1, 4, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 6, 5, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 6, 15, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 8, 5, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 8, 15, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

/* Function Declarations */
static const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location);

/* Function Definitions */
static const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[2];
  const mxArray *m21;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m21, 2, pArrays,
    "message", TRUE, location);
}

void b_minangle(real_T x1[4], const real_T x2[4])
{
  int32_T count;
  int32_T exitg1;
  real_T x[4];
  int32_T i;
  real_T y[4];
  real_T b_y[4];
  real_T c_y[4];
  real_T d_y[4];
  boolean_T e_y;
  boolean_T exitg4;
  int8_T ii_data[4];
  int32_T ii;
  boolean_T exitg3;
  boolean_T guard2 = FALSE;
  int8_T b_ii_data[4];
  int8_T in1_data[4];
  boolean_T exitg2;
  boolean_T guard1 = FALSE;
  const mxArray *f_y;
  static const int32_T iv86[2] = { 1, 39 };

  const mxArray *m26;
  char_T cv54[39];
  static const char_T cv55[39] = { 'W', 'a', 'r', 'n', 'i', 'n', 'g', ':', ' ',
    'm', 'i', 'n', 'a', 'n', 'g', 'l', 'e', '(', ')', ' ', 'f', 'a', 'i', 'l',
    'i', 'n', 'g', ' ', 't', 'o', ' ', 'c', 'o', 'n', 'v', 'e', 'r', 'g', 'e' };

  /* find the minimum angle between two vectors of 2D angles x1 and x2 */
  count = 0;
  do {
    exitg1 = 0;
    for (i = 0; i < 4; i++) {
      x[i] = (x1[i] - 6.2831853071795862) - x2[i];
    }

    for (i = 0; i < 4; i++) {
      y[i] = muDoubleScalarAbs(x[i]);
    }

    for (i = 0; i < 4; i++) {
      x[i] = x1[i] - x2[i];
    }

    for (i = 0; i < 4; i++) {
      b_y[i] = muDoubleScalarAbs(x[i]);
    }

    for (i = 0; i < 4; i++) {
      x[i] = (x1[i] + 6.2831853071795862) - x2[i];
    }

    for (i = 0; i < 4; i++) {
      c_y[i] = muDoubleScalarAbs(x[i]);
    }

    for (i = 0; i < 4; i++) {
      x[i] = x1[i] - x2[i];
    }

    for (i = 0; i < 4; i++) {
      d_y[i] = muDoubleScalarAbs(x[i]);
    }

    e_y = FALSE;
    i = 0;
    exitg4 = FALSE;
    while ((exitg4 == FALSE) && (i < 4)) {
      if (!(((y[i] < b_y[i]) || (c_y[i] < d_y[i])) == 0)) {
        e_y = TRUE;
        exitg4 = TRUE;
      } else {
        i++;
      }
    }

    if (e_y) {
      for (i = 0; i < 4; i++) {
        x[i] = (x1[i] - 6.2831853071795862) - x2[i];
      }

      for (i = 0; i < 4; i++) {
        y[i] = muDoubleScalarAbs(x[i]);
      }

      for (i = 0; i < 4; i++) {
        x[i] = x1[i] - x2[i];
      }

      for (i = 0; i < 4; i++) {
        b_y[i] = muDoubleScalarAbs(x[i]);
      }

      i = 0;
      ii = 1;
      exitg3 = FALSE;
      while ((exitg3 == FALSE) && (ii < 5)) {
        guard2 = FALSE;
        if (y[ii - 1] < b_y[ii - 1]) {
          i++;
          ii_data[i - 1] = (int8_T)ii;
          if (i >= 4) {
            exitg3 = TRUE;
          } else {
            guard2 = TRUE;
          }
        } else {
          guard2 = TRUE;
        }

        if (guard2 == TRUE) {
          ii++;
        }
      }

      if (1 > i) {
        i = 0;
      }

      for (ii = 0; ii < i; ii++) {
        b_ii_data[ii] = ii_data[ii];
      }

      for (ii = 0; ii < i; ii++) {
        ii_data[ii] = b_ii_data[ii];
      }

      for (ii = 0; ii < i; ii++) {
        in1_data[ii] = ii_data[ii];
      }

      for (ii = 0; ii < i; ii++) {
        ii_data[ii] = in1_data[ii];
      }

      emlrtSizeEqCheck1DFastR2012b(i, i, &xc_emlrtECI, emlrtRootTLSGlobal);
      for (ii = 0; ii < i; ii++) {
        b_ii_data[ii] = (int8_T)(ii_data[ii] - 1);
      }

      for (ii = 0; ii < i; ii++) {
        x[ii] = x1[in1_data[ii] - 1] - 6.2831853071795862;
      }

      for (ii = 0; ii < i; ii++) {
        x1[b_ii_data[ii]] = x[ii];
      }

      for (i = 0; i < 4; i++) {
        x[i] = (x1[i] + 6.2831853071795862) - x2[i];
      }

      for (i = 0; i < 4; i++) {
        y[i] = muDoubleScalarAbs(x[i]);
      }

      for (i = 0; i < 4; i++) {
        x[i] = x1[i] - x2[i];
      }

      for (i = 0; i < 4; i++) {
        b_y[i] = muDoubleScalarAbs(x[i]);
      }

      i = 0;
      ii = 1;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (ii < 5)) {
        guard1 = FALSE;
        if (y[ii - 1] < b_y[ii - 1]) {
          i++;
          ii_data[i - 1] = (int8_T)ii;
          if (i >= 4) {
            exitg2 = TRUE;
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

      if (1 > i) {
        i = 0;
      }

      for (ii = 0; ii < i; ii++) {
        b_ii_data[ii] = ii_data[ii];
      }

      for (ii = 0; ii < i; ii++) {
        ii_data[ii] = b_ii_data[ii];
      }

      for (ii = 0; ii < i; ii++) {
        in1_data[ii] = ii_data[ii];
      }

      for (ii = 0; ii < i; ii++) {
        ii_data[ii] = in1_data[ii];
      }

      emlrtSizeEqCheck1DFastR2012b(i, i, &yc_emlrtECI, emlrtRootTLSGlobal);
      for (ii = 0; ii < i; ii++) {
        b_ii_data[ii] = (int8_T)(ii_data[ii] - 1);
      }

      for (ii = 0; ii < i; ii++) {
        x[ii] = x1[in1_data[ii] - 1] + 6.2831853071795862;
      }

      for (ii = 0; ii < i; ii++) {
        x1[b_ii_data[ii]] = x[ii];
      }

      count++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
      if (count > 50) {
        emlrtPushRtStackR2012b(&lj_emlrtRSI, emlrtRootTLSGlobal);
        f_y = NULL;
        m26 = mxCreateCharArray(2, iv86);
        for (i = 0; i < 39; i++) {
          cv54[i] = cv55[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 39, m26, cv54);
        emlrtAssign(&f_y, m26);
        disp(f_y, &y_emlrtMCI);
        emlrtPopRtStackR2012b(&lj_emlrtRSI, emlrtRootTLSGlobal);
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

void c_minangle(emxArray_real_T *x1, const emxArray_real_T *x2)
{
  int32_T count;
  emxArray_real_T *in1;
  emxArray_real_T *r53;
  emxArray_real_T *r54;
  emxArray_real_T *r55;
  emxArray_boolean_T *r56;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_real_T *b_x1;
  emxArray_real_T *c_x1;
  emxArray_real_T *d_x1;
  emxArray_real_T *e_x1;
  emxArray_real_T *f_x1;
  emxArray_real_T *g_x1;
  emxArray_real_T *h_x1;
  emxArray_real_T *i_x1;
  emxArray_int32_T *b_ii;
  emxArray_int32_T *c_ii;
  emxArray_real_T *j_x1;
  emxArray_int32_T *d_ii;
  emxArray_int32_T *e_ii;
  emxArray_real_T *k_x1;
  int32_T exitg1;
  int32_T i15;
  int32_T i;
  int32_T idx;
  boolean_T overflow;
  boolean_T p;
  int32_T exitg5;
  const mxArray *y;
  static const int32_T iv87[2] = { 1, 41 };

  const mxArray *m27;
  char_T cv56[41];
  static const char_T cv57[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p',
    't', 'y' };

  boolean_T b9;
  const mxArray *b_y;
  static const int32_T iv88[2] = { 1, 51 };

  char_T cv58[51];
  static const char_T cv59[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T exitg4;
  boolean_T exitg3;
  boolean_T guard2 = FALSE;
  const mxArray *c_y;
  int32_T i16;
  boolean_T exitg2;
  boolean_T guard1 = FALSE;
  const mxArray *d_y;
  const mxArray *e_y;
  static const int32_T iv89[2] = { 1, 39 };

  char_T cv60[39];
  static const char_T cv61[39] = { 'W', 'a', 'r', 'n', 'i', 'n', 'g', ':', ' ',
    'm', 'i', 'n', 'a', 'n', 'g', 'l', 'e', '(', ')', ' ', 'f', 'a', 'i', 'l',
    'i', 'n', 'g', ' ', 't', 'o', ' ', 'c', 'o', 'n', 'v', 'e', 'r', 'g', 'e' };

  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /* find the minimum angle between two vectors of 2D angles x1 and x2 */
  count = 0;
  b_emxInit_real_T(&in1, 1, &ub_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r53, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r54, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r55, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_boolean_T(&r56, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_boolean_T(&x, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&ii, 1, &vb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&b_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&c_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&d_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&e_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&f_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&g_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&h_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&i_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&b_ii, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&c_ii, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&j_x1, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&d_ii, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&e_ii, 1, &gb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&k_x1, 1, &gb_emlrtRTEI, TRUE);
  do {
    exitg1 = 0;
    i15 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i15, i, &md_emlrtECI, emlrtRootTLSGlobal);
    i15 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i15, i, &ld_emlrtECI, emlrtRootTLSGlobal);
    i15 = i_x1->size[0];
    i_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)i_x1, i15, (int32_T)sizeof(real_T),
                      &gb_emlrtRTEI);
    idx = x1->size[0];
    for (i15 = 0; i15 < idx; i15++) {
      i_x1->data[i15] = (x1->data[i15] - 6.2831853071795862) - x2->data[i15];
    }

    b_abs(i_x1, in1);
    i15 = h_x1->size[0];
    h_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)h_x1, i15, (int32_T)sizeof(real_T),
                      &gb_emlrtRTEI);
    idx = x1->size[0];
    for (i15 = 0; i15 < idx; i15++) {
      h_x1->data[i15] = x1->data[i15] - x2->data[i15];
    }

    b_abs(h_x1, r53);
    i15 = in1->size[0];
    i = r53->size[0];
    emlrtSizeEqCheck1DFastR2012b(i15, i, &kd_emlrtECI, emlrtRootTLSGlobal);
    i15 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i15, i, &jd_emlrtECI, emlrtRootTLSGlobal);
    i15 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i15, i, &id_emlrtECI, emlrtRootTLSGlobal);
    i15 = g_x1->size[0];
    g_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)g_x1, i15, (int32_T)sizeof(real_T),
                      &gb_emlrtRTEI);
    idx = x1->size[0];
    for (i15 = 0; i15 < idx; i15++) {
      g_x1->data[i15] = (x1->data[i15] + 6.2831853071795862) - x2->data[i15];
    }

    b_abs(g_x1, r54);
    i15 = f_x1->size[0];
    f_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)f_x1, i15, (int32_T)sizeof(real_T),
                      &gb_emlrtRTEI);
    idx = x1->size[0];
    for (i15 = 0; i15 < idx; i15++) {
      f_x1->data[i15] = x1->data[i15] - x2->data[i15];
    }

    b_abs(f_x1, r55);
    i15 = r54->size[0];
    i = r55->size[0];
    emlrtSizeEqCheck1DFastR2012b(i15, i, &hd_emlrtECI, emlrtRootTLSGlobal);
    i15 = x->size[0];
    x->size[0] = in1->size[0];
    emxEnsureCapacity((emxArray__common *)x, i15, (int32_T)sizeof(boolean_T),
                      &gb_emlrtRTEI);
    idx = in1->size[0];
    for (i15 = 0; i15 < idx; i15++) {
      x->data[i15] = (in1->data[i15] < r53->data[i15]);
    }

    i15 = r56->size[0];
    r56->size[0] = r54->size[0];
    emxEnsureCapacity((emxArray__common *)r56, i15, (int32_T)sizeof(boolean_T),
                      &gb_emlrtRTEI);
    idx = r54->size[0];
    for (i15 = 0; i15 < idx; i15++) {
      r56->data[i15] = (r54->data[i15] < r55->data[i15]);
    }

    i15 = x->size[0];
    i = r56->size[0];
    emlrtSizeEqCheck1DFastR2012b(i15, i, &gd_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
    i15 = x->size[0];
    emxEnsureCapacity((emxArray__common *)x, i15, (int32_T)sizeof(boolean_T),
                      &gb_emlrtRTEI);
    idx = x->size[0];
    for (i15 = 0; i15 < idx; i15++) {
      x->data[i15] = (x->data[i15] || r56->data[i15]);
    }

    emlrtPushRtStackR2012b(&pj_emlrtRSI, emlrtRootTLSGlobal);
    overflow = FALSE;
    p = FALSE;
    i = 0;
    do {
      exitg5 = 0;
      if (i < 2) {
        if (i + 1 <= 1) {
          i15 = x->size[0];
        } else {
          i15 = 1;
        }

        if (i15 != 0) {
          exitg5 = 1;
        } else {
          i++;
        }
      } else {
        p = TRUE;
        exitg5 = 1;
      }
    } while (exitg5 == 0);

    if (!p) {
    } else {
      overflow = TRUE;
    }

    if (!overflow) {
    } else {
      emlrtPushRtStackR2012b(&qj_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      y = NULL;
      m27 = mxCreateCharArray(2, iv87);
      for (i = 0; i < 41; i++) {
        cv56[i] = cv57[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 41, m27, cv56);
      emlrtAssign(&y, m27);
      error(message(y, &ab_emlrtMCI), &bb_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&qj_emlrtRSI, emlrtRootTLSGlobal);
    }

    if ((x->size[0] == 1) || (x->size[0] != 1)) {
      b9 = TRUE;
    } else {
      b9 = FALSE;
    }

    if (b9) {
    } else {
      emlrtPushRtStackR2012b(&rj_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      b_y = NULL;
      m27 = mxCreateCharArray(2, iv88);
      for (i = 0; i < 51; i++) {
        cv58[i] = cv59[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m27, cv58);
      emlrtAssign(&b_y, m27);
      error(message(b_y, &cb_emlrtMCI), &db_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&rj_emlrtRSI, emlrtRootTLSGlobal);
    }

    b9 = FALSE;
    emlrtPushRtStackR2012b(&sj_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > x->size[0]) {
      overflow = FALSE;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

    if (overflow) {
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&sj_emlrtRSI, emlrtRootTLSGlobal);
    i = 1;
    exitg4 = FALSE;
    while ((exitg4 == FALSE) && (i <= x->size[0])) {
      p = (x->data[i - 1] == 0);
      if (!p) {
        b9 = TRUE;
        exitg4 = TRUE;
      } else {
        i++;
      }
    }

    emlrtPopRtStackR2012b(&pj_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
    if (b9) {
      i15 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i15, i, &fd_emlrtECI, emlrtRootTLSGlobal);
      i15 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i15, i, &ed_emlrtECI, emlrtRootTLSGlobal);
      i15 = e_x1->size[0];
      e_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)e_x1, i15, (int32_T)sizeof(real_T),
                        &gb_emlrtRTEI);
      idx = x1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        e_x1->data[i15] = (x1->data[i15] - 6.2831853071795862) - x2->data[i15];
      }

      b_abs(e_x1, in1);
      i15 = d_x1->size[0];
      d_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)d_x1, i15, (int32_T)sizeof(real_T),
                        &gb_emlrtRTEI);
      idx = x1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        d_x1->data[i15] = x1->data[i15] - x2->data[i15];
      }

      b_abs(d_x1, r53);
      i15 = in1->size[0];
      i = r53->size[0];
      emlrtSizeEqCheck1DFastR2012b(i15, i, &dd_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
      i15 = x->size[0];
      x->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)x, i15, (int32_T)sizeof(boolean_T),
                        &gb_emlrtRTEI);
      idx = in1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        x->data[i15] = (in1->data[i15] < r53->data[i15]);
      }

      emlrtPushRtStackR2012b(&tj_emlrtRSI, emlrtRootTLSGlobal);
      idx = 0;
      i15 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                        &tb_emlrtRTEI);
      emlrtPushRtStackR2012b(&vj_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > x->size[0]) {
        overflow = FALSE;
      } else {
        overflow = (x->size[0] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&vj_emlrtRSI, emlrtRootTLSGlobal);
      i = 1;
      exitg3 = FALSE;
      while ((exitg3 == FALSE) && (i <= x->size[0])) {
        guard2 = FALSE;
        if (x->data[i - 1]) {
          idx++;
          ii->data[idx - 1] = i;
          if (idx >= x->size[0]) {
            exitg3 = TRUE;
          } else {
            guard2 = TRUE;
          }
        } else {
          guard2 = TRUE;
        }

        if (guard2 == TRUE) {
          i++;
        }
      }

      if (idx <= x->size[0]) {
      } else {
        emlrtPushRtStackR2012b(&wj_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        c_y = NULL;
        m27 = mxCreateString("Assertion failed.");
        emlrtAssign(&c_y, m27);
        error(c_y, &fb_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&wj_emlrtRSI, emlrtRootTLSGlobal);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i15 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                            &gb_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i15 = b_ii->size[0];
        b_ii->size[0] = idx;
        emxEnsureCapacity((emxArray__common *)b_ii, i15, (int32_T)sizeof(int32_T),
                          &gb_emlrtRTEI);
        for (i15 = 0; i15 < idx; i15++) {
          b_ii->data[i15] = ii->data[i15];
        }

        i15 = ii->size[0];
        ii->size[0] = b_ii->size[0];
        emxEnsureCapacity((emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                          &gb_emlrtRTEI);
        idx = b_ii->size[0];
        for (i15 = 0; i15 < idx; i15++) {
          ii->data[i15] = b_ii->data[i15];
        }
      }

      emlrtPopRtStackR2012b(&tj_emlrtRSI, emlrtRootTLSGlobal);
      i15 = in1->size[0];
      in1->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)in1, i15, (int32_T)sizeof(real_T),
                        &gb_emlrtRTEI);
      idx = ii->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        in1->data[i15] = ii->data[i15];
      }

      emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
      i15 = ii->size[0];
      ii->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                        &gb_emlrtRTEI);
      idx = in1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        i = x1->size[0];
        i16 = (int32_T)in1->data[i15];
        ii->data[i15] = emlrtDynamicBoundsCheckFastR2012b(i16, 1, i,
          &sf_emlrtBCI, emlrtRootTLSGlobal);
      }

      idx = in1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        i = x1->size[0];
        i16 = (int32_T)in1->data[i15];
        emlrtDynamicBoundsCheckFastR2012b(i16, 1, i, &tf_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i15 = ii->size[0];
      i = in1->size[0];
      emlrtSizeEqCheck1DFastR2012b(i15, i, &xc_emlrtECI, emlrtRootTLSGlobal);
      i15 = c_ii->size[0];
      c_ii->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)c_ii, i15, (int32_T)sizeof(int32_T),
                        &gb_emlrtRTEI);
      idx = ii->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        c_ii->data[i15] = ii->data[i15] - 1;
      }

      i15 = j_x1->size[0];
      j_x1->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)j_x1, i15, (int32_T)sizeof(real_T),
                        &gb_emlrtRTEI);
      idx = in1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        j_x1->data[i15] = x1->data[(int32_T)in1->data[i15] - 1] -
          6.2831853071795862;
      }

      idx = j_x1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        x1->data[c_ii->data[i15]] = j_x1->data[i15];
      }

      i15 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i15, i, &cd_emlrtECI, emlrtRootTLSGlobal);
      i15 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i15, i, &bd_emlrtECI, emlrtRootTLSGlobal);
      i15 = c_x1->size[0];
      c_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)c_x1, i15, (int32_T)sizeof(real_T),
                        &gb_emlrtRTEI);
      idx = x1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        c_x1->data[i15] = (x1->data[i15] + 6.2831853071795862) - x2->data[i15];
      }

      b_abs(c_x1, in1);
      i15 = b_x1->size[0];
      b_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)b_x1, i15, (int32_T)sizeof(real_T),
                        &gb_emlrtRTEI);
      idx = x1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        b_x1->data[i15] = x1->data[i15] - x2->data[i15];
      }

      b_abs(b_x1, r53);
      i15 = in1->size[0];
      i = r53->size[0];
      emlrtSizeEqCheck1DFastR2012b(i15, i, &ad_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
      i15 = x->size[0];
      x->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)x, i15, (int32_T)sizeof(boolean_T),
                        &gb_emlrtRTEI);
      idx = in1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        x->data[i15] = (in1->data[i15] < r53->data[i15]);
      }

      emlrtPushRtStackR2012b(&tj_emlrtRSI, emlrtRootTLSGlobal);
      idx = 0;
      i15 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                        &tb_emlrtRTEI);
      emlrtPushRtStackR2012b(&vj_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > x->size[0]) {
        overflow = FALSE;
      } else {
        overflow = (x->size[0] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&vj_emlrtRSI, emlrtRootTLSGlobal);
      i = 1;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (i <= x->size[0])) {
        guard1 = FALSE;
        if (x->data[i - 1]) {
          idx++;
          ii->data[idx - 1] = i;
          if (idx >= x->size[0]) {
            exitg2 = TRUE;
          } else {
            guard1 = TRUE;
          }
        } else {
          guard1 = TRUE;
        }

        if (guard1 == TRUE) {
          i++;
        }
      }

      if (idx <= x->size[0]) {
      } else {
        emlrtPushRtStackR2012b(&wj_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        d_y = NULL;
        m27 = mxCreateString("Assertion failed.");
        emlrtAssign(&d_y, m27);
        error(d_y, &fb_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&wj_emlrtRSI, emlrtRootTLSGlobal);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i15 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                            &gb_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i15 = d_ii->size[0];
        d_ii->size[0] = idx;
        emxEnsureCapacity((emxArray__common *)d_ii, i15, (int32_T)sizeof(int32_T),
                          &gb_emlrtRTEI);
        for (i15 = 0; i15 < idx; i15++) {
          d_ii->data[i15] = ii->data[i15];
        }

        i15 = ii->size[0];
        ii->size[0] = d_ii->size[0];
        emxEnsureCapacity((emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                          &gb_emlrtRTEI);
        idx = d_ii->size[0];
        for (i15 = 0; i15 < idx; i15++) {
          ii->data[i15] = d_ii->data[i15];
        }
      }

      emlrtPopRtStackR2012b(&tj_emlrtRSI, emlrtRootTLSGlobal);
      i15 = in1->size[0];
      in1->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)in1, i15, (int32_T)sizeof(real_T),
                        &gb_emlrtRTEI);
      idx = ii->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        in1->data[i15] = ii->data[i15];
      }

      emlrtPopRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
      i15 = ii->size[0];
      ii->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i15, (int32_T)sizeof(int32_T),
                        &gb_emlrtRTEI);
      idx = in1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        i = x1->size[0];
        i16 = (int32_T)in1->data[i15];
        ii->data[i15] = emlrtDynamicBoundsCheckFastR2012b(i16, 1, i,
          &uf_emlrtBCI, emlrtRootTLSGlobal);
      }

      idx = in1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        i = x1->size[0];
        i16 = (int32_T)in1->data[i15];
        emlrtDynamicBoundsCheckFastR2012b(i16, 1, i, &vf_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i15 = ii->size[0];
      i = in1->size[0];
      emlrtSizeEqCheck1DFastR2012b(i15, i, &yc_emlrtECI, emlrtRootTLSGlobal);
      i15 = e_ii->size[0];
      e_ii->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)e_ii, i15, (int32_T)sizeof(int32_T),
                        &gb_emlrtRTEI);
      idx = ii->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        e_ii->data[i15] = ii->data[i15] - 1;
      }

      i15 = k_x1->size[0];
      k_x1->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)k_x1, i15, (int32_T)sizeof(real_T),
                        &gb_emlrtRTEI);
      idx = in1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        k_x1->data[i15] = x1->data[(int32_T)in1->data[i15] - 1] +
          6.2831853071795862;
      }

      idx = k_x1->size[0];
      for (i15 = 0; i15 < idx; i15++) {
        x1->data[e_ii->data[i15]] = k_x1->data[i15];
      }

      count++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
      if (count > 50) {
        emlrtPushRtStackR2012b(&lj_emlrtRSI, emlrtRootTLSGlobal);
        e_y = NULL;
        m27 = mxCreateCharArray(2, iv89);
        for (i = 0; i < 39; i++) {
          cv60[i] = cv61[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 39, m27, cv60);
        emlrtAssign(&e_y, m27);
        disp(e_y, &y_emlrtMCI);
        emlrtPopRtStackR2012b(&lj_emlrtRSI, emlrtRootTLSGlobal);
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&k_x1);
  emxFree_int32_T(&e_ii);
  emxFree_int32_T(&d_ii);
  emxFree_real_T(&j_x1);
  emxFree_int32_T(&c_ii);
  emxFree_int32_T(&b_ii);
  emxFree_real_T(&i_x1);
  emxFree_real_T(&h_x1);
  emxFree_real_T(&g_x1);
  emxFree_real_T(&f_x1);
  emxFree_real_T(&e_x1);
  emxFree_real_T(&d_x1);
  emxFree_real_T(&c_x1);
  emxFree_real_T(&b_x1);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_boolean_T(&r56);
  emxFree_real_T(&r55);
  emxFree_real_T(&r54);
  emxFree_real_T(&r53);
  emxFree_real_T(&in1);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void check_forloop_overflow_error(void)
{
  const mxArray *y;
  static const int32_T iv26[2] = { 1, 34 };

  const mxArray *m1;
  char_T cv8[34];
  int32_T i;
  static const char_T cv9[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *b_y;
  static const int32_T iv27[2] = { 1, 23 };

  char_T cv10[23];
  static const char_T cv11[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't',
    'e', 'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_synchGlobalsToML();
  y = NULL;
  m1 = mxCreateCharArray(2, iv26);
  for (i = 0; i < 34; i++) {
    cv8[i] = cv9[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 34, m1, cv8);
  emlrtAssign(&y, m1);
  b_y = NULL;
  m1 = mxCreateCharArray(2, iv27);
  for (i = 0; i < 23; i++) {
    cv10[i] = cv11[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 23, m1, cv10);
  emlrtAssign(&b_y, m1);
  error(b_message(y, b_y, &d_emlrtMCI), &e_emlrtMCI);
  emlrt_synchGlobalsFromML();
  emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
}

void minangle(const real_T x1[4], const real_T x2[4], real_T b_x1[4])
{
  int32_T i;
  for (i = 0; i < 4; i++) {
    b_x1[i] = x1[i];
  }

  b_minangle(b_x1, x2);
}

/* End of code generation (minangle.c) */
