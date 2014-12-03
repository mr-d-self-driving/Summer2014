/*
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "fprintf.h"
#include "ukf_update_10_state_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo gi_emlrtRSI = { 33, "fprintf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/lang/fprintf.m"
};

static emlrtRSInfo hi_emlrtRSI = { 66, "fprintf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/lang/fprintf.m"
};

static emlrtMCInfo q_emlrtMCI = { 66, 14, "fprintf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/lang/fprintf.m"
};

/* Function Declarations */
static real_T c_fprintf(real_T varargin_1);
static const mxArray *feval(const mxArray *b, const mxArray *c, const mxArray *d,
  const mxArray *e, emlrtMCInfo *location);

/* Function Definitions */
static real_T c_fprintf(real_T varargin_1)
{
  real_T nbytes;
  const mxArray *y;
  static const int32_T iv22[2] = { 1, 7 };

  const mxArray *m6;
  char_T cv23[7];
  int32_T i;
  static const char_T cv24[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  static const int32_T iv23[2] = { 1, 48 };

  char_T cv25[48];
  static const char_T cv26[48] = { 'E', 'r', 'r', 'o', 'r', ':', ' ', 'm', 'a',
    't', 'r', 'i', 'x', ' ', 's', 'q', 'u', 'a', 'r', 'e', ' ', 'r', 'o', 'o',
    't', ' ', 'r', 'e', 's', 'i', 'd', 'u', 'a', 'l', ' ', 'n', 'o', 'r', 'm',
    ' ', 'i', 's', ' ', '%', 'g', '.', '\\', 'n' };

  emlrtPushRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_synchGlobalsToML();
  y = NULL;
  m6 = mxCreateCharArray(2, iv22);
  for (i = 0; i < 7; i++) {
    cv23[i] = cv24[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 7, m6, cv23);
  emlrtAssign(&y, m6);
  b_y = NULL;
  m6 = mxCreateCharArray(2, iv23);
  for (i = 0; i < 48; i++) {
    cv25[i] = cv26[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 48, m6, cv25);
  emlrtAssign(&b_y, m6);
  nbytes = emlrt_marshallIn(feval(y, emlrt_marshallOut(1.0), b_y,
    emlrt_marshallOut(varargin_1), &q_emlrtMCI), "feval");
  emlrt_synchGlobalsFromML();
  emlrtPopRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
  return nbytes;
}

static const mxArray *feval(const mxArray *b, const mxArray *c, const mxArray *d,
  const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m22;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m22, 4, pArrays, "feval",
    TRUE, location);
}

void b_fprintf(real_T formatSpec)
{
  emlrtPushRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
  c_fprintf(formatSpec);
  emlrtPopRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
}

/* End of code generation (fprintf.c) */
