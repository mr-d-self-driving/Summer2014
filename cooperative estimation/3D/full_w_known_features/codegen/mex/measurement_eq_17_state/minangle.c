/*
 * minangle.c
 *
 * Code generation for function 'minangle'
 *
 * C source code generated on: Thu Nov 20 11:58:36 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurement_eq_17_state.h"
#include "minangle.h"
#include "measurement_eq_17_state_emxutil.h"
#include "abs.h"
#include "measurement_eq_17_state_mexutil.h"
#include "measurement_eq_17_state_data.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = { 51, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo ab_emlrtRSI = { 11, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo bb_emlrtRSI = { 4, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo cb_emlrtRSI = { 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo db_emlrtRSI = { 7, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRSInfo eb_emlrtRSI = { 12, "any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/any.m"
};

static emlrtRSInfo fb_emlrtRSI = { 24, "eml_all_or_any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"
};

static emlrtRSInfo gb_emlrtRSI = { 27, "eml_all_or_any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"
};

static emlrtRSInfo hb_emlrtRSI = { 109, "eml_all_or_any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"
};

static emlrtRSInfo ib_emlrtRSI = { 41, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRSInfo kb_emlrtRSI = { 230, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRSInfo lb_emlrtRSI = { 239, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtMCInfo c_emlrtMCI = { 52, 9, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo d_emlrtMCI = { 51, 15, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo i_emlrtMCI = { 11, 9, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtMCInfo j_emlrtMCI = { 25, 9, "eml_all_or_any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"
};

static emlrtMCInfo k_emlrtMCI = { 24, 19, "eml_all_or_any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"
};

static emlrtMCInfo l_emlrtMCI = { 30, 9, "eml_all_or_any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"
};

static emlrtMCInfo m_emlrtMCI = { 27, 19, "eml_all_or_any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"
};

static emlrtMCInfo o_emlrtMCI = { 239, 9, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 1, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRTEInfo i_emlrtRTEI = { 127, 5, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 5, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtRTEInfo k_emlrtRTEI = { 33, 6, "find",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/find.m"
};

static emlrtECInfo h_emlrtECI = { -1, 6, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo i_emlrtECI = { -1, 8, 5, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo j_emlrtECI = { -1, 7, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo k_emlrtECI = { -1, 7, 39, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo l_emlrtECI = { -1, 7, 21, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo m_emlrtECI = { -1, 5, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo n_emlrtECI = { -1, 5, 39, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo o_emlrtECI = { -1, 5, 21, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo p_emlrtECI = { -1, 4, 12, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo q_emlrtECI = { -1, 4, 46, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo r_emlrtECI = { -1, 4, 68, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo s_emlrtECI = { -1, 4, 50, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo t_emlrtECI = { -1, 4, 13, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo u_emlrtECI = { -1, 4, 35, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtECInfo v_emlrtECI = { -1, 4, 17, "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m" };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 6, 5, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 6, 15, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 8, 5, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 8, 15, "x1", "minangle",
  "/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m", 0 };

/* Function Declarations */
static const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location);
static void b_minangle(real_T x1[4], const real_T x2[4]);
static void disp(const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[2];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m5, 2, pArrays, "message",
    TRUE, location);
}

static void b_minangle(real_T x1[4], const real_T x2[4])
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
  static const int32_T iv31[2] = { 1, 39 };

  const mxArray *m6;
  char_T cv9[39];
  static const char_T cv10[39] = { 'W', 'a', 'r', 'n', 'i', 'n', 'g', ':', ' ',
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

      emlrtSizeEqCheck1DFastR2012b(i, i, &h_emlrtECI, emlrtRootTLSGlobal);
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

      emlrtSizeEqCheck1DFastR2012b(i, i, &i_emlrtECI, emlrtRootTLSGlobal);
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
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        f_y = NULL;
        m6 = mxCreateCharArray(2, iv31);
        for (i = 0; i < 39; i++) {
          cv9[i] = cv10[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 39, m6, cv9);
        emlrtAssign(&f_y, m6);
        disp(f_y, &i_emlrtMCI);
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

static void disp(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "disp", TRUE,
                        location);
}

void c_minangle(emxArray_real_T *x1, const emxArray_real_T *x2)
{
  int32_T count;
  emxArray_real_T *in1;
  emxArray_real_T *r33;
  emxArray_real_T *r34;
  emxArray_real_T *r35;
  emxArray_boolean_T *r36;
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
  int32_T i6;
  int32_T i;
  int32_T idx;
  boolean_T overflow;
  boolean_T p;
  int32_T exitg5;
  const mxArray *y;
  static const int32_T iv32[2] = { 1, 41 };

  const mxArray *m7;
  char_T cv11[41];
  static const char_T cv12[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p',
    't', 'y' };

  boolean_T b0;
  const mxArray *b_y;
  static const int32_T iv33[2] = { 1, 51 };

  char_T cv13[51];
  static const char_T cv14[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T exitg4;
  boolean_T exitg3;
  boolean_T guard2 = FALSE;
  const mxArray *c_y;
  int32_T i7;
  boolean_T exitg2;
  boolean_T guard1 = FALSE;
  const mxArray *d_y;
  const mxArray *e_y;
  static const int32_T iv34[2] = { 1, 39 };

  char_T cv15[39];
  static const char_T cv16[39] = { 'W', 'a', 'r', 'n', 'i', 'n', 'g', ':', ' ',
    'm', 'i', 'n', 'a', 'n', 'g', 'l', 'e', '(', ')', ' ', 'f', 'a', 'i', 'l',
    'i', 'n', 'g', ' ', 't', 'o', ' ', 'c', 'o', 'n', 'v', 'e', 'r', 'g', 'e' };

  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /* find the minimum angle between two vectors of 2D angles x1 and x2 */
  count = 0;
  b_emxInit_real_T(&in1, 1, &j_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r33, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r34, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r35, 1, &f_emlrtRTEI, TRUE);
  emxInit_boolean_T(&r36, 1, &f_emlrtRTEI, TRUE);
  emxInit_boolean_T(&x, 1, &f_emlrtRTEI, TRUE);
  emxInit_int32_T(&ii, 1, &k_emlrtRTEI, TRUE);
  b_emxInit_real_T(&b_x1, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&c_x1, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&d_x1, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&e_x1, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&f_x1, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&g_x1, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&h_x1, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&i_x1, 1, &f_emlrtRTEI, TRUE);
  emxInit_int32_T(&b_ii, 1, &f_emlrtRTEI, TRUE);
  emxInit_int32_T(&c_ii, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&j_x1, 1, &f_emlrtRTEI, TRUE);
  emxInit_int32_T(&d_ii, 1, &f_emlrtRTEI, TRUE);
  emxInit_int32_T(&e_ii, 1, &f_emlrtRTEI, TRUE);
  b_emxInit_real_T(&k_x1, 1, &f_emlrtRTEI, TRUE);
  do {
    exitg1 = 0;
    i6 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i6, i, &v_emlrtECI, emlrtRootTLSGlobal);
    i6 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i6, i, &u_emlrtECI, emlrtRootTLSGlobal);
    i6 = i_x1->size[0];
    i_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)i_x1, i6, (int32_T)sizeof(real_T),
                      &f_emlrtRTEI);
    idx = x1->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      i_x1->data[i6] = (x1->data[i6] - 6.2831853071795862) - x2->data[i6];
    }

    b_abs(i_x1, in1);
    i6 = h_x1->size[0];
    h_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)h_x1, i6, (int32_T)sizeof(real_T),
                      &f_emlrtRTEI);
    idx = x1->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      h_x1->data[i6] = x1->data[i6] - x2->data[i6];
    }

    b_abs(h_x1, r33);
    i6 = in1->size[0];
    i = r33->size[0];
    emlrtSizeEqCheck1DFastR2012b(i6, i, &t_emlrtECI, emlrtRootTLSGlobal);
    i6 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i6, i, &s_emlrtECI, emlrtRootTLSGlobal);
    i6 = x1->size[0];
    i = x2->size[0];
    emlrtSizeEqCheck1DFastR2012b(i6, i, &r_emlrtECI, emlrtRootTLSGlobal);
    i6 = g_x1->size[0];
    g_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)g_x1, i6, (int32_T)sizeof(real_T),
                      &f_emlrtRTEI);
    idx = x1->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      g_x1->data[i6] = (x1->data[i6] + 6.2831853071795862) - x2->data[i6];
    }

    b_abs(g_x1, r34);
    i6 = f_x1->size[0];
    f_x1->size[0] = x1->size[0];
    emxEnsureCapacity((emxArray__common *)f_x1, i6, (int32_T)sizeof(real_T),
                      &f_emlrtRTEI);
    idx = x1->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      f_x1->data[i6] = x1->data[i6] - x2->data[i6];
    }

    b_abs(f_x1, r35);
    i6 = r34->size[0];
    i = r35->size[0];
    emlrtSizeEqCheck1DFastR2012b(i6, i, &q_emlrtECI, emlrtRootTLSGlobal);
    i6 = x->size[0];
    x->size[0] = in1->size[0];
    emxEnsureCapacity((emxArray__common *)x, i6, (int32_T)sizeof(boolean_T),
                      &f_emlrtRTEI);
    idx = in1->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      x->data[i6] = (in1->data[i6] < r33->data[i6]);
    }

    i6 = r36->size[0];
    r36->size[0] = r34->size[0];
    emxEnsureCapacity((emxArray__common *)r36, i6, (int32_T)sizeof(boolean_T),
                      &f_emlrtRTEI);
    idx = r34->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      r36->data[i6] = (r34->data[i6] < r35->data[i6]);
    }

    i6 = x->size[0];
    i = r36->size[0];
    emlrtSizeEqCheck1DFastR2012b(i6, i, &p_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    i6 = x->size[0];
    emxEnsureCapacity((emxArray__common *)x, i6, (int32_T)sizeof(boolean_T),
                      &f_emlrtRTEI);
    idx = x->size[0];
    for (i6 = 0; i6 < idx; i6++) {
      x->data[i6] = (x->data[i6] || r36->data[i6]);
    }

    emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
    overflow = FALSE;
    p = FALSE;
    i = 0;
    do {
      exitg5 = 0;
      if (i < 2) {
        if (i + 1 <= 1) {
          i6 = x->size[0];
        } else {
          i6 = 1;
        }

        if (i6 != 0) {
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
      emlrtPushRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
      y = NULL;
      m7 = mxCreateCharArray(2, iv32);
      for (i = 0; i < 41; i++) {
        cv11[i] = cv12[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 41, m7, cv11);
      emlrtAssign(&y, m7);
      error(message(y, &j_emlrtMCI), &k_emlrtMCI);
      emlrtPopRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
    }

    if ((x->size[0] == 1) || (x->size[0] != 1)) {
      b0 = TRUE;
    } else {
      b0 = FALSE;
    }

    if (b0) {
    } else {
      emlrtPushRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
      b_y = NULL;
      m7 = mxCreateCharArray(2, iv33);
      for (i = 0; i < 51; i++) {
        cv13[i] = cv14[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m7, cv13);
      emlrtAssign(&b_y, m7);
      error(message(b_y, &l_emlrtMCI), &m_emlrtMCI);
      emlrtPopRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
    }

    b0 = FALSE;
    emlrtPushRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > x->size[0]) {
      overflow = FALSE;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

    if (overflow) {
      emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
    i = 1;
    exitg4 = FALSE;
    while ((exitg4 == FALSE) && (i <= x->size[0])) {
      p = (x->data[i - 1] == 0);
      if (!p) {
        b0 = TRUE;
        exitg4 = TRUE;
      } else {
        i++;
      }
    }

    emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    if (b0) {
      i6 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i6, i, &o_emlrtECI, emlrtRootTLSGlobal);
      i6 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i6, i, &n_emlrtECI, emlrtRootTLSGlobal);
      i6 = e_x1->size[0];
      e_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)e_x1, i6, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      idx = x1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        e_x1->data[i6] = (x1->data[i6] - 6.2831853071795862) - x2->data[i6];
      }

      b_abs(e_x1, in1);
      i6 = d_x1->size[0];
      d_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)d_x1, i6, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      idx = x1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        d_x1->data[i6] = x1->data[i6] - x2->data[i6];
      }

      b_abs(d_x1, r33);
      i6 = in1->size[0];
      i = r33->size[0];
      emlrtSizeEqCheck1DFastR2012b(i6, i, &m_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i6 = x->size[0];
      x->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)x, i6, (int32_T)sizeof(boolean_T),
                        &f_emlrtRTEI);
      idx = in1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        x->data[i6] = (in1->data[i6] < r33->data[i6]);
      }

      emlrtPushRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
      idx = 0;
      i6 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i6, (int32_T)sizeof(int32_T),
                        &i_emlrtRTEI);
      emlrtPushRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > x->size[0]) {
        overflow = FALSE;
      } else {
        overflow = (x->size[0] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
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
        emlrtPushRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
        c_y = NULL;
        m7 = mxCreateString("Assertion failed.");
        emlrtAssign(&c_y, m7);
        error(c_y, &o_emlrtMCI);
        emlrtPopRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i6 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i6, (int32_T)sizeof(int32_T),
                            &f_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i6 = b_ii->size[0];
        b_ii->size[0] = idx;
        emxEnsureCapacity((emxArray__common *)b_ii, i6, (int32_T)sizeof(int32_T),
                          &f_emlrtRTEI);
        for (i6 = 0; i6 < idx; i6++) {
          b_ii->data[i6] = ii->data[i6];
        }

        i6 = ii->size[0];
        ii->size[0] = b_ii->size[0];
        emxEnsureCapacity((emxArray__common *)ii, i6, (int32_T)sizeof(int32_T),
                          &f_emlrtRTEI);
        idx = b_ii->size[0];
        for (i6 = 0; i6 < idx; i6++) {
          ii->data[i6] = b_ii->data[i6];
        }
      }

      emlrtPopRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
      i6 = in1->size[0];
      in1->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)in1, i6, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      idx = ii->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        in1->data[i6] = ii->data[i6];
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i6 = ii->size[0];
      ii->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i6, (int32_T)sizeof(int32_T),
                        &f_emlrtRTEI);
      idx = in1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        i = x1->size[0];
        i7 = (int32_T)in1->data[i6];
        ii->data[i6] = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &rc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      idx = in1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        i = x1->size[0];
        i7 = (int32_T)in1->data[i6];
        emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &sc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i6 = ii->size[0];
      i = in1->size[0];
      emlrtSizeEqCheck1DFastR2012b(i6, i, &h_emlrtECI, emlrtRootTLSGlobal);
      i6 = c_ii->size[0];
      c_ii->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)c_ii, i6, (int32_T)sizeof(int32_T),
                        &f_emlrtRTEI);
      idx = ii->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        c_ii->data[i6] = ii->data[i6] - 1;
      }

      i6 = j_x1->size[0];
      j_x1->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)j_x1, i6, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      idx = in1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        j_x1->data[i6] = x1->data[(int32_T)in1->data[i6] - 1] -
          6.2831853071795862;
      }

      idx = j_x1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        x1->data[c_ii->data[i6]] = j_x1->data[i6];
      }

      i6 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i6, i, &l_emlrtECI, emlrtRootTLSGlobal);
      i6 = x1->size[0];
      i = x2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i6, i, &k_emlrtECI, emlrtRootTLSGlobal);
      i6 = c_x1->size[0];
      c_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)c_x1, i6, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      idx = x1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        c_x1->data[i6] = (x1->data[i6] + 6.2831853071795862) - x2->data[i6];
      }

      b_abs(c_x1, in1);
      i6 = b_x1->size[0];
      b_x1->size[0] = x1->size[0];
      emxEnsureCapacity((emxArray__common *)b_x1, i6, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      idx = x1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        b_x1->data[i6] = x1->data[i6] - x2->data[i6];
      }

      b_abs(b_x1, r33);
      i6 = in1->size[0];
      i = r33->size[0];
      emlrtSizeEqCheck1DFastR2012b(i6, i, &j_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      i6 = x->size[0];
      x->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)x, i6, (int32_T)sizeof(boolean_T),
                        &f_emlrtRTEI);
      idx = in1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        x->data[i6] = (in1->data[i6] < r33->data[i6]);
      }

      emlrtPushRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
      idx = 0;
      i6 = ii->size[0];
      ii->size[0] = x->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i6, (int32_T)sizeof(int32_T),
                        &i_emlrtRTEI);
      emlrtPushRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > x->size[0]) {
        overflow = FALSE;
      } else {
        overflow = (x->size[0] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
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
        emlrtPushRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
        d_y = NULL;
        m7 = mxCreateString("Assertion failed.");
        emlrtAssign(&d_y, m7);
        error(d_y, &o_emlrtMCI);
        emlrtPopRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      }

      if (x->size[0] == 1) {
        if (idx == 0) {
          i6 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i6, (int32_T)sizeof(int32_T),
                            &f_emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i6 = d_ii->size[0];
        d_ii->size[0] = idx;
        emxEnsureCapacity((emxArray__common *)d_ii, i6, (int32_T)sizeof(int32_T),
                          &f_emlrtRTEI);
        for (i6 = 0; i6 < idx; i6++) {
          d_ii->data[i6] = ii->data[i6];
        }

        i6 = ii->size[0];
        ii->size[0] = d_ii->size[0];
        emxEnsureCapacity((emxArray__common *)ii, i6, (int32_T)sizeof(int32_T),
                          &f_emlrtRTEI);
        idx = d_ii->size[0];
        for (i6 = 0; i6 < idx; i6++) {
          ii->data[i6] = d_ii->data[i6];
        }
      }

      emlrtPopRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
      i6 = in1->size[0];
      in1->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)in1, i6, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      idx = ii->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        in1->data[i6] = ii->data[i6];
      }

      emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      i6 = ii->size[0];
      ii->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)ii, i6, (int32_T)sizeof(int32_T),
                        &f_emlrtRTEI);
      idx = in1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        i = x1->size[0];
        i7 = (int32_T)in1->data[i6];
        ii->data[i6] = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &tc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      idx = in1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        i = x1->size[0];
        i7 = (int32_T)in1->data[i6];
        emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &uc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i6 = ii->size[0];
      i = in1->size[0];
      emlrtSizeEqCheck1DFastR2012b(i6, i, &i_emlrtECI, emlrtRootTLSGlobal);
      i6 = e_ii->size[0];
      e_ii->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)e_ii, i6, (int32_T)sizeof(int32_T),
                        &f_emlrtRTEI);
      idx = ii->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        e_ii->data[i6] = ii->data[i6] - 1;
      }

      i6 = k_x1->size[0];
      k_x1->size[0] = in1->size[0];
      emxEnsureCapacity((emxArray__common *)k_x1, i6, (int32_T)sizeof(real_T),
                        &f_emlrtRTEI);
      idx = in1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        k_x1->data[i6] = x1->data[(int32_T)in1->data[i6] - 1] +
          6.2831853071795862;
      }

      idx = k_x1->size[0];
      for (i6 = 0; i6 < idx; i6++) {
        x1->data[e_ii->data[i6]] = k_x1->data[i6];
      }

      count++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
      if (count > 50) {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        e_y = NULL;
        m7 = mxCreateCharArray(2, iv34);
        for (i = 0; i < 39; i++) {
          cv15[i] = cv16[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 39, m7, cv15);
        emlrtAssign(&e_y, m7);
        disp(e_y, &i_emlrtMCI);
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
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
  emxFree_boolean_T(&r36);
  emxFree_real_T(&r35);
  emxFree_real_T(&r34);
  emxFree_real_T(&r33);
  emxFree_real_T(&in1);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void check_forloop_overflow_error(void)
{
  const mxArray *y;
  static const int32_T iv21[2] = { 1, 34 };

  const mxArray *m1;
  char_T cv4[34];
  int32_T i;
  static const char_T cv5[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *b_y;
  static const int32_T iv22[2] = { 1, 23 };

  char_T cv6[23];
  static const char_T cv7[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't',
    'e', 'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  emlrtPushRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
  y = NULL;
  m1 = mxCreateCharArray(2, iv21);
  for (i = 0; i < 34; i++) {
    cv4[i] = cv5[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 34, m1, cv4);
  emlrtAssign(&y, m1);
  b_y = NULL;
  m1 = mxCreateCharArray(2, iv22);
  for (i = 0; i < 23; i++) {
    cv6[i] = cv7[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 23, m1, cv6);
  emlrtAssign(&b_y, m1);
  error(b_message(y, b_y, &c_emlrtMCI), &d_emlrtMCI);
  emlrtPopRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
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
