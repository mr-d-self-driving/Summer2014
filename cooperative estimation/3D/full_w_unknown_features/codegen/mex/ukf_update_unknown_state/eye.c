/*
 * eye.c
 *
 * Code generation for function 'eye'
 *
 * C source code generated on: Thu Dec 11 11:40:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "eye.h"
#include "minangle.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "ukf_update_unknown_state_mexutil.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo lk_emlrtRSI = { 17, "eye",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/eye.m"
};

static emlrtRSInfo mk_emlrtRSI = { 50, "eye",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/eye.m"
};

static emlrtRSInfo nk_emlrtRSI = { 59, "eye",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/eye.m"
};

static emlrtRTEInfo jb_emlrtRTEI = { 1, 14, "eye",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/eye.m"
};

/* Function Definitions */
void eye(real_T n, emxArray_real_T *I)
{
  boolean_T p;
  const mxArray *y;
  static const int32_T iv96[2] = { 1, 28 };

  const mxArray *m11;
  char_T cv42[28];
  int32_T i;
  static const char_T cv43[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I',
    'n', 'p', 'u', 't' };

  const mxArray *b_y;
  static const int32_T iv97[2] = { 1, 28 };

  real_T b_n;
  real_T c_n;
  const mxArray *c_y;
  static const int32_T iv98[2] = { 1, 21 };

  char_T cv44[21];
  static const char_T cv45[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T loop_ub;
  real_T minval;
  boolean_T b2;
  emlrtPushRtStackR2012b(&lk_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&mk_emlrtRSI, emlrtRootTLSGlobal);
  if ((n != n) || muDoubleScalarIsInf(n)) {
    p = FALSE;
  } else {
    p = TRUE;
  }

  if (p) {
  } else {
    emlrtPushRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    y = NULL;
    m11 = mxCreateCharArray(2, iv96);
    for (i = 0; i < 28; i++) {
      cv42[i] = cv43[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 28, m11, cv42);
    emlrtAssign(&y, m11);
    error(message(y, &r_emlrtMCI), &s_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
  }

  if ((n != n) || muDoubleScalarIsInf(n)) {
    p = FALSE;
  } else {
    p = TRUE;
  }

  if (p) {
  } else {
    emlrtPushRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    b_y = NULL;
    m11 = mxCreateCharArray(2, iv97);
    for (i = 0; i < 28; i++) {
      cv42[i] = cv43[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 28, m11, cv42);
    emlrtAssign(&b_y, m11);
    error(message(b_y, &r_emlrtMCI), &s_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
  }

  if (n <= 0.0) {
    b_n = 0.0;
  } else {
    if (n <= 0.0) {
      c_n = 0.0;
    } else {
      c_n = n;
    }

    b_n = c_n * n;
  }

  if (2.147483647E+9 >= b_n) {
  } else {
    emlrtPushRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    c_y = NULL;
    m11 = mxCreateCharArray(2, iv98);
    for (i = 0; i < 21; i++) {
      cv44[i] = cv45[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m11, cv44);
    emlrtAssign(&c_y, m11);
    error(message(c_y, &t_emlrtMCI), &u_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&mk_emlrtRSI, emlrtRootTLSGlobal);
  i = I->size[0] * I->size[1];
  I->size[0] = (int32_T)n;
  I->size[1] = (int32_T)n;
  emxEnsureCapacity((emxArray__common *)I, i, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  loop_ub = (int32_T)n * (int32_T)n;
  for (i = 0; i < loop_ub; i++) {
    I->data[i] = 0.0;
  }

  minval = muDoubleScalarMin(n, n);
  if ((int32_T)minval > 0) {
    emlrtPushRtStackR2012b(&nk_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > (int32_T)minval) {
      b2 = FALSE;
    } else {
      b2 = ((int32_T)minval > 2147483646);
    }

    if (b2) {
      emlrtPushRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&nk_emlrtRSI, emlrtRootTLSGlobal);
    for (i = 0; i + 1 <= (int32_T)minval; i++) {
      I->data[i + I->size[0] * i] = 1.0;
    }
  }

  emlrtPopRtStackR2012b(&lk_emlrtRSI, emlrtRootTLSGlobal);
}

/* End of code generation (eye.c) */
