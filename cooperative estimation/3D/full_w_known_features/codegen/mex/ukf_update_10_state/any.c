/*
 * any.c
 *
 * Code generation for function 'any'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "any.h"
#include "minangle.h"
#include "ukf_update_10_state_mexutil.h"
#include "ukf_update_10_state_emxutil.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo oj_emlrtRSI = { 102, "eml_all_or_any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m"
};

static emlrtRTEInfo hb_emlrtRTEI = { 1, 14, "any",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/any.m"
};

/* Function Definitions */
void any(const emxArray_boolean_T *x, emxArray_boolean_T *y)
{
  boolean_T overflow;
  boolean_T p;
  int32_T i;
  int32_T exitg2;
  const mxArray *b_y;
  static const int32_T iv33[2] = { 1, 41 };

  const mxArray *m9;
  char_T cv35[41];
  static const char_T cv36[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p',
    't', 'y' };

  const mxArray *c_y;
  static const int32_T iv34[2] = { 1, 51 };

  char_T cv37[51];
  static const char_T cv38[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  uint32_T outsize[2];
  int32_T i2;
  int32_T iy;
  int32_T i1;
  boolean_T b_i1;
  boolean_T exitg1;
  emlrtPushRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
  overflow = FALSE;
  p = FALSE;
  i = 0;
  do {
    exitg2 = 0;
    if (i < 2) {
      if (x->size[i] != 0) {
        exitg2 = 1;
      } else {
        i++;
      }
    } else {
      p = TRUE;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (!p) {
  } else {
    overflow = TRUE;
  }

  if (!overflow) {
  } else {
    emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    b_y = NULL;
    m9 = mxCreateCharArray(2, iv33);
    for (i = 0; i < 41; i++) {
      cv35[i] = cv36[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 41, m9, cv35);
    emlrtAssign(&b_y, m9);
    error(message(b_y, &bb_emlrtMCI), &cb_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
  }

  if (((x->size[0] == 1) && (x->size[1] == 1)) || (x->size[0] != 1)) {
    overflow = TRUE;
  } else {
    overflow = FALSE;
  }

  if (overflow) {
  } else {
    emlrtPushRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    c_y = NULL;
    m9 = mxCreateCharArray(2, iv34);
    for (i = 0; i < 51; i++) {
      cv37[i] = cv38[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m9, cv37);
    emlrtAssign(&c_y, m9);
    error(message(c_y, &db_emlrtMCI), &eb_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
  }

  for (i = 0; i < 2; i++) {
    outsize[i] = (uint32_T)x->size[i];
  }

  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)y, i, (int32_T)sizeof(boolean_T),
                    &hb_emlrtRTEI);
  i = y->size[0] * y->size[1];
  y->size[1] = (int32_T)outsize[1];
  emxEnsureCapacity((emxArray__common *)y, i, (int32_T)sizeof(boolean_T),
                    &hb_emlrtRTEI);
  i2 = (int32_T)outsize[1];
  for (i = 0; i < i2; i++) {
    y->data[i] = FALSE;
  }

  i2 = 0;
  iy = -1;
  emlrtPushRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
  if (1 > x->size[1]) {
    overflow = FALSE;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    check_forloop_overflow_error();
    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
  for (i = 1; i <= x->size[1]; i++) {
    i1 = i2 + 1;
    i2 += x->size[0];
    iy++;
    emlrtPushRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
    if (i1 > i2) {
      b_i1 = FALSE;
    } else {
      b_i1 = (i2 > 2147483646);
    }

    if (b_i1) {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (i1 <= i2)) {
      overflow = (x->data[i1 - 1] == 0);
      if (!overflow) {
        y->data[iy] = TRUE;
        exitg1 = TRUE;
      } else {
        i1++;
      }
    }
  }

  emlrtPopRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
}

boolean_T b_any(const emxArray_boolean_T *x)
{
  boolean_T y;
  boolean_T overflow;
  boolean_T p;
  int32_T i;
  int32_T exitg2;
  const mxArray *b_y;
  static const int32_T iv35[2] = { 1, 41 };

  const mxArray *m10;
  char_T cv39[41];
  static const char_T cv40[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p',
    't', 'y' };

  const mxArray *c_y;
  static const int32_T iv36[2] = { 1, 51 };

  char_T cv41[51];
  static const char_T cv42[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r',
    '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c',
    'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  boolean_T exitg1;
  emlrtPushRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
  overflow = FALSE;
  p = FALSE;
  i = 0;
  do {
    exitg2 = 0;
    if (i < 2) {
      if (x->size[i] != 0) {
        exitg2 = 1;
      } else {
        i++;
      }
    } else {
      p = TRUE;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (!p) {
  } else {
    overflow = TRUE;
  }

  if (!overflow) {
  } else {
    emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    b_y = NULL;
    m10 = mxCreateCharArray(2, iv35);
    for (i = 0; i < 41; i++) {
      cv39[i] = cv40[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 41, m10, cv39);
    emlrtAssign(&b_y, m10);
    error(message(b_y, &bb_emlrtMCI), &cb_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
  }

  if ((x->size[1] == 1) || (x->size[1] != 1)) {
    overflow = TRUE;
  } else {
    overflow = FALSE;
  }

  if (overflow) {
  } else {
    emlrtPushRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    c_y = NULL;
    m10 = mxCreateCharArray(2, iv36);
    for (i = 0; i < 51; i++) {
      cv41[i] = cv42[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m10, cv41);
    emlrtAssign(&c_y, m10);
    error(message(c_y, &db_emlrtMCI), &eb_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
  }

  y = FALSE;
  emlrtPushRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
  if (1 > x->size[1]) {
    overflow = FALSE;
  } else {
    overflow = (x->size[1] > 2147483646);
  }

  if (overflow) {
    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    check_forloop_overflow_error();
    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
  i = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (i <= x->size[1])) {
    overflow = (x->data[i - 1] == 0);
    if (!overflow) {
      y = TRUE;
      exitg1 = TRUE;
    } else {
      i++;
    }
  }

  emlrtPopRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
  return y;
}

/* End of code generation (any.c) */
