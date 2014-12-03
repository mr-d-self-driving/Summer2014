/*
 * minangle.c
 *
 * Code generation for function 'minangle'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "minangle.h"
#include "ukf_update_10_state_emxutil.h"
#include "ukf_update_10_state_mexutil.h"
#include "abs.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo bb_emlrtRSI = { 51, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo cj_emlrtRSI = { 11, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo dj_emlrtRSI = { 4, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo ej_emlrtRSI = { 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo fj_emlrtRSI = { 7, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo kj_emlrtRSI = { 41, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRSInfo mj_emlrtRSI = { 230, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRSInfo nj_emlrtRSI = { 239, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtMCInfo e_emlrtMCI = { 52, 9, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo f_emlrtMCI = { 51, 15, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo ab_emlrtMCI = { 11, 9, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtMCInfo gb_emlrtMCI = { 239, 9, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRTEInfo fb_emlrtRTEI = { 1, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRTEInfo ac_emlrtRTEI = { 127, 5, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRTEInfo bc_emlrtRTEI = { 5, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRTEInfo cc_emlrtRTEI = { 33, 6, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtECInfo tb_emlrtECI = { -1, 8, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo ub_emlrtECI = { -1, 7, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo vb_emlrtECI = { -1, 7, 39, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo wb_emlrtECI = { -1, 7, 21, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo xb_emlrtECI = { -1, 6, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo yb_emlrtECI = { -1, 5, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo ac_emlrtECI = { -1, 5, 39, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo bc_emlrtECI = { -1, 5, 21, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo cc_emlrtECI = { -1, 4, 12, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo dc_emlrtECI = { -1, 4, 46, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo ec_emlrtECI = { -1, 4, 68, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo fc_emlrtECI = { -1, 4, 50, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo gc_emlrtECI = { -1, 4, 13, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo hc_emlrtECI = { -1, 4, 35, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo ic_emlrtECI = { -1, 4, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 6, 5, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 6, 15, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 8, 5, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 8, 15, "x1", "minangle",
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

void check_forloop_overflow_error(void)
{
  const mxArray *y;
  static const int32_T iv14[2] = { 1, 34 };

  const mxArray *m1;
  char_T cv9[34];
  int32_T i;
  static const char_T cv10[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *b_y;
  static const int32_T iv15[2] = { 1, 23 };

  char_T cv11[23];
  static const char_T cv12[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't',
    'e', 'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_synchGlobalsToML();
  y = NULL;
  m1 = mxCreateCharArray(2, iv14);
  for (i = 0; i < 34; i++) {
    cv9[i] = cv10[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 34, m1, cv9);
  emlrtAssign(&y, m1);
  b_y = NULL;
  m1 = mxCreateCharArray(2, iv15);
  for (i = 0; i < 23; i++) {
    cv11[i] = cv12[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 23, m1, cv11);
  emlrtAssign(&b_y, m1);
  error(b_message(y, b_y, &e_emlrtMCI), &f_emlrtMCI);
  emlrt_synchGlobalsFromML();
  emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
}

void minangle(emxArray_real_T *x1, const emxArray_real_T *x2)
{
  int32_T count;
  emxArray_real_T *in1;
  emxArray_real_T *r25;
  emxArray_real_T *r26;
  emxArray_real_T *r27;
  emxArray_boolean_T *r28;
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
  int32_T i22;
  int32_T i;
  int32_T idx;
  boolean_T overflow;
  boolean_T p;
  int32_T exitg5;
  const mxArray *y;
  static const int32_T iv55[2] = { 1, 41 };

  const mxArray *m26;
  char_T cv55[41];
  static const char_T cv56[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p',
    't', 'y' };

  boolean_T b13;
  const mxArray *b_y;
  static const int32_T iv56[2] = { 1, 51 };

  char_T cv57[51];
  static const char_T cv58[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T exitg4;
  boolean_T exitg3;
  boolean_T guard2 = FALSE;
  const mxArray *c_y;
  int32_T i23;
  boolean_T exitg2;
  boolean_T guard1 = FALSE;
  const mxArray *d_y;
  const mxArray *e_y;
  static const int32_T iv57[2] = { 1, 39 };

  char_T cv59[39];
  static const char_T cv60[39] = { 'W', 'a', 'r', 'n', 'i', 'n', 'g', ':', ' ',
    'm', 'i', 'n', 'a', 'n', 'g', 'l', 'e', '(', ')', ' ', 'f', 'a', 'i', 'l',
    'i', 'n', 'g', ' ', 't', 'o', ' ', 'c', 'o', 'n', 'v', 'e', 'r', 'g', 'e' };

  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /* find the minimum angle between two vectors of 2D angles x1 and x2 */
  count = 0;
  b_emxInit_real_T(&in1, 1, &bc_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r25, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r26, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r27, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_boolean_T(&r28, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_boolean_T(&x, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&ii, 1, &cc_emlrtRTEI, TRUE);
  b_emxInit_real_T(&b_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&c_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&d_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&e_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&f_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&g_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&h_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&i_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&b_ii, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&c_ii, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&j_x1, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&d_ii, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&e_ii, 1, &fb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&k_x1, 1, &fb_emlrtRTEI, TRUE);
  do {
    exitg1 = 0;
    i22 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i22, i, &ic_emlrtECI, emlrtRootTLSGlobal);
    i22 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i22, i, &hc_emlrtECI, emlrtRootTLSGlobal);
    i22 = i_x1->size[0];
    i_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)i_x1, i22, (int32_T)sizeof(real_T),
                      &fb_emlrtRTEI);
    idx = x1->size[0];
    for (i22 = 0; i22 < idx; i22++) {
      i_x1->data[i22] = (x1->data[i22] - 6.2831853071795862) - x2->data[i22];
    }

    b_abs(i_x1, in1);
    i22 = h_x1->size[0];
    h_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)h_x1, i22, (int32_T)sizeof(real_T),
                      &fb_emlrtRTEI);
    idx = x1->size[0];
    for (i22 = 0; i22 < idx; i22++) {
      h_x1->data[i22] = x1->data[i22] - x2->data[i22];
    }

    b_abs(h_x1, r25);
    i22 = in1->size[0];
    i = r25->size[0];
    emlrtSizeEqCheck1DFastR2012b(i22, i, &gc_emlrtECI, emlrtRootTLSGlobal);
    i22 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i22, i, &fc_emlrtECI, emlrtRootTLSGlobal);
    i22 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i22, i, &ec_emlrtECI, emlrtRootTLSGlobal);
    i22 = g_x1->size[0];
    g_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)g_x1, i22, (int32_T)sizeof(real_T),
                      &fb_emlrtRTEI);
    idx = x1->size[0];
    for (i22 = 0; i22 < idx; i22++) {
      g_x1->data[i22] = (x1->data[i22] + 6.2831853071795862) - x2->data[i22];
    }

    b_abs(g_x1, r26);
    i22 = f_x1->size[0];
    f_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)f_x1, i22, (int32_T)sizeof(real_T),
                      &fb_emlrtRTEI);
    idx = x1->size[0];
    for (i22 = 0; i22 < idx; i22++) {
      f_x1->data[i22] = x1->data[i22] - x2->data[i22];
    }

    b_abs(f_x1, r27);
    i22 = r26->size[0];
    i = r27->size[0];
    emlrtSizeEqCheck1DFastR2012b(i22, i, &dc_emlrtECI, emlrtRootTLSGlobal);
    i22 = x->size[0];
    x->size[0] = in1->size[0];
    emxEnsureCapacity((emxArray__common *)x, i22, (int32_T)sizeof(boolean_T),
                      &fb_emlrtRTEI);
    idx = in1->size[0];
    for (i22 = 0; i22 < idx; i22++) {
      x->data[i22] = (in1->data[i22] < r25->data[i22]);
    }

    i22 = r28->size[0];
    r28->size[0] = r26->size[0];
    emxEnsureCapacity((emxArray__common *)r28, i22, (int32_T)sizeof(boolean_T),
                      &fb_emlrtRTEI);
    idx = r26->size[0];
    for (i22 = 0; i22 < idx; i22++) {
      r28->data[i22] = (r26->data[i22] < r27->data[i22]);
    }

    i22 = x->size[0];
    i = r28->size[0];
    emlrtSizeEqCheck1DFastR2012b(i22, i, &cc_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&dj_emlrtRSI, emlrtRootTLSGlobal);
    i22 = x->size[0];
    emxEnsureCapacity((emxArray__common *)x, i22, (int32_T)sizeof(boolean_T),
                      &fb_emlrtRTEI);
    idx = x->size[0];
    for (i22 = 0; i22 < idx; i22++) {
      x->data[i22] = (x->data[i22] || r28->data[i22]);
    }

    emlrtPushRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
    overflow = FALSE;
    p = FALSE;
    i = 0;
    do {
      exitg5 = 0;
      if (i < 2) {
        if (i + 1 <= 1) {
          i22 = x->size[0];
        } else {
          i22 = 1;
        }

        if (i22 != 0) {
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
      emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      y = NULL;
      m26 = mxCreateCharArray(2, iv55);
      for (i = 0; i < 41; i++) {
        cv55[i] = cv56[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 41, m26, cv55);
      emlrtAssign(&y, m26);
      error(message(y, &bb_emlrtMCI), &cb_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
    }

    if ((x->size[0] == 1) || (x->size[0] != 1)) {
      b13 = TRUE;
    } else {
      b13 = FALSE;
    }

    if (b13) {
    } else {
      emlrtPushRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      b_y = NULL;
      m26 = mxCreateCharArray(2, iv56);
      for (i = 0; i < 51; i++) {
        cv57[i] = cv58[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m26, cv57);
      emlrtAssign(&b_y, m26);
      error(message(b_y, &db_emlrtMCI), &eb_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
    }

    b13 = FALSE;
    emlrtPushRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > x->size[0]) {
      overflow = FALSE;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

    if (overflow) {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
    i = 1;
    exitg4 = FALSE;
    while ((exitg4 == FALSE) && (i <= x->size[0])) {
      p = (x->data[i - 1] == 0);
      if (!p) {
        b13 = TRUE;
        exitg4 = TRUE;
      } else {
        i++;
      }
    }

    emlrtPopRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&dj_emlrtRSI, emlrtRootTLSGlobal);
    if (b13) {
      i22 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i22, i, &bc_emlrtECI, emlrtRootTLSGlobal);
      i22 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i22, i, &ac_emlrtECI, emlrtRootTLSGlobal);
      i22 = e_x1->size[0];
      e_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)e_x1, i22, (int32_T)sizeof(real_T),
                        &fb_emlrtRTEI);
      idx = x1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        e_x1->data[i22] = (x1->data[i22] - 6.2831853071795862) - x2->data[i22];
      }

      b_abs(e_x1, in1);
      i22 = d_x1->size[0];
      d_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)d_x1, i22, (int32_T)sizeof(real_T),
                        &fb_emlrtRTEI);
      idx = x1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        d_x1->data[i22] = x1->data[i22] - x2->data[i22];
      }

      b_abs(d_x1, r25);
      i22 = in1->size[0];
      i = r25->size[0];
      emlrtSizeEqCheck1DFastR2012b(i22, i, &yb_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ej_emlrtRSI, emlrtRootTLSGlobal);
      i22 = x->size[0];
      x->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)x, i22, (int32_T)sizeof(boolean_T),
                        &fb_emlrtRTEI);
      idx = in1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        x->data[i22] = (in1->data[i22] < r25->data[i22]);
      }

      emlrtPushRtStackR2012b(&kj_emlrtRSI, emlrtRootTLSGlobal);
      idx = 0;
      i22 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i22, (int32_T)sizeof(int32_T),
                        &ac_emlrtRTEI);
      emlrtPushRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > x->size[0]) {
        overflow = FALSE;
      } else {
        overflow = (x->size[0] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
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
        emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        c_y = NULL;
        m26 = mxCreateString("Assertion failed.");
        emlrtAssign(&c_y, m26);
        error(c_y, &gb_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i22 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i22, (int32_T)sizeof(int32_T),
                            &fb_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i22 = b_ii->size[0];
        b_ii->size[0] = idx;
        emxEnsureCapacity((emxArray__common *)b_ii, i22, (int32_T)sizeof(int32_T),
                          &fb_emlrtRTEI);
        for (i22 = 0; i22 < idx; i22++) {
          b_ii->data[i22] = ii->data[i22];
        }

        i22 = ii->size[0];
        ii->size[0] = b_ii->size[0];
        emxEnsureCapacity((emxArray__common *)ii, i22, (int32_T)sizeof(int32_T),
                          &fb_emlrtRTEI);
        idx = b_ii->size[0];
        for (i22 = 0; i22 < idx; i22++) {
          ii->data[i22] = b_ii->data[i22];
        }
      }

      emlrtPopRtStackR2012b(&kj_emlrtRSI, emlrtRootTLSGlobal);
      i22 = in1->size[0];
      in1->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)in1, i22, (int32_T)sizeof(real_T),
                        &fb_emlrtRTEI);
      idx = ii->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        in1->data[i22] = ii->data[i22];
      }

      emlrtPopRtStackR2012b(&ej_emlrtRSI, emlrtRootTLSGlobal);
      i22 = ii->size[0];
      ii->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i22, (int32_T)sizeof(int32_T),
                        &fb_emlrtRTEI);
      idx = in1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        i = x1->size[0];
        i23 = (int32_T)in1->data[i22];
        ii->data[i22] = emlrtDynamicBoundsCheckFastR2012b(i23, 1, i,
          &ad_emlrtBCI, emlrtRootTLSGlobal);
      }

      idx = in1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        i = x1->size[0];
        i23 = (int32_T)in1->data[i22];
        emlrtDynamicBoundsCheckFastR2012b(i23, 1, i, &bd_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i22 = ii->size[0];
      i = in1->size[0];
      emlrtSizeEqCheck1DFastR2012b(i22, i, &xb_emlrtECI, emlrtRootTLSGlobal);
      i22 = c_ii->size[0];
      c_ii->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)c_ii, i22, (int32_T)sizeof(int32_T),
                        &fb_emlrtRTEI);
      idx = ii->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        c_ii->data[i22] = ii->data[i22] - 1;
      }

      i22 = j_x1->size[0];
      j_x1->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)j_x1, i22, (int32_T)sizeof(real_T),
                        &fb_emlrtRTEI);
      idx = in1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        j_x1->data[i22] = x1->data[(int32_T)in1->data[i22] - 1] -
          6.2831853071795862;
      }

      idx = j_x1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        x1->data[c_ii->data[i22]] = j_x1->data[i22];
      }

      i22 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i22, i, &wb_emlrtECI, emlrtRootTLSGlobal);
      i22 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i22, i, &vb_emlrtECI, emlrtRootTLSGlobal);
      i22 = c_x1->size[0];
      c_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)c_x1, i22, (int32_T)sizeof(real_T),
                        &fb_emlrtRTEI);
      idx = x1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        c_x1->data[i22] = (x1->data[i22] + 6.2831853071795862) - x2->data[i22];
      }

      b_abs(c_x1, in1);
      i22 = b_x1->size[0];
      b_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)b_x1, i22, (int32_T)sizeof(real_T),
                        &fb_emlrtRTEI);
      idx = x1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        b_x1->data[i22] = x1->data[i22] - x2->data[i22];
      }

      b_abs(b_x1, r25);
      i22 = in1->size[0];
      i = r25->size[0];
      emlrtSizeEqCheck1DFastR2012b(i22, i, &ub_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&fj_emlrtRSI, emlrtRootTLSGlobal);
      i22 = x->size[0];
      x->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)x, i22, (int32_T)sizeof(boolean_T),
                        &fb_emlrtRTEI);
      idx = in1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        x->data[i22] = (in1->data[i22] < r25->data[i22]);
      }

      emlrtPushRtStackR2012b(&kj_emlrtRSI, emlrtRootTLSGlobal);
      idx = 0;
      i22 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i22, (int32_T)sizeof(int32_T),
                        &ac_emlrtRTEI);
      emlrtPushRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > x->size[0]) {
        overflow = FALSE;
      } else {
        overflow = (x->size[0] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
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
        emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        d_y = NULL;
        m26 = mxCreateString("Assertion failed.");
        emlrtAssign(&d_y, m26);
        error(d_y, &gb_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i22 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i22, (int32_T)sizeof(int32_T),
                            &fb_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i22 = d_ii->size[0];
        d_ii->size[0] = idx;
        emxEnsureCapacity((emxArray__common *)d_ii, i22, (int32_T)sizeof(int32_T),
                          &fb_emlrtRTEI);
        for (i22 = 0; i22 < idx; i22++) {
          d_ii->data[i22] = ii->data[i22];
        }

        i22 = ii->size[0];
        ii->size[0] = d_ii->size[0];
        emxEnsureCapacity((emxArray__common *)ii, i22, (int32_T)sizeof(int32_T),
                          &fb_emlrtRTEI);
        idx = d_ii->size[0];
        for (i22 = 0; i22 < idx; i22++) {
          ii->data[i22] = d_ii->data[i22];
        }
      }

      emlrtPopRtStackR2012b(&kj_emlrtRSI, emlrtRootTLSGlobal);
      i22 = in1->size[0];
      in1->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)in1, i22, (int32_T)sizeof(real_T),
                        &fb_emlrtRTEI);
      idx = ii->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        in1->data[i22] = ii->data[i22];
      }

      emlrtPopRtStackR2012b(&fj_emlrtRSI, emlrtRootTLSGlobal);
      i22 = ii->size[0];
      ii->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i22, (int32_T)sizeof(int32_T),
                        &fb_emlrtRTEI);
      idx = in1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        i = x1->size[0];
        i23 = (int32_T)in1->data[i22];
        ii->data[i22] = emlrtDynamicBoundsCheckFastR2012b(i23, 1, i,
          &cd_emlrtBCI, emlrtRootTLSGlobal);
      }

      idx = in1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        i = x1->size[0];
        i23 = (int32_T)in1->data[i22];
        emlrtDynamicBoundsCheckFastR2012b(i23, 1, i, &dd_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i22 = ii->size[0];
      i = in1->size[0];
      emlrtSizeEqCheck1DFastR2012b(i22, i, &tb_emlrtECI, emlrtRootTLSGlobal);
      i22 = e_ii->size[0];
      e_ii->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)e_ii, i22, (int32_T)sizeof(int32_T),
                        &fb_emlrtRTEI);
      idx = ii->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        e_ii->data[i22] = ii->data[i22] - 1;
      }

      i22 = k_x1->size[0];
      k_x1->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)k_x1, i22, (int32_T)sizeof(real_T),
                        &fb_emlrtRTEI);
      idx = in1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        k_x1->data[i22] = x1->data[(int32_T)in1->data[i22] - 1] +
          6.2831853071795862;
      }

      idx = k_x1->size[0];
      for (i22 = 0; i22 < idx; i22++) {
        x1->data[e_ii->data[i22]] = k_x1->data[i22];
      }

      count++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
      if (count > 50) {
        emlrtPushRtStackR2012b(&cj_emlrtRSI, emlrtRootTLSGlobal);
        e_y = NULL;
        m26 = mxCreateCharArray(2, iv57);
        for (i = 0; i < 39; i++) {
          cv59[i] = cv60[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 39, m26, cv59);
        emlrtAssign(&e_y, m26);
        disp(e_y, &ab_emlrtMCI);
        emlrtPopRtStackR2012b(&cj_emlrtRSI, emlrtRootTLSGlobal);
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
  emxFree_boolean_T(&r28);
  emxFree_real_T(&r27);
  emxFree_real_T(&r26);
  emxFree_real_T(&r25);
  emxFree_real_T(&in1);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (minangle.c) */
