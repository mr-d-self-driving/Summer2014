/*
 * ukf_update_17_state_mexutil.c
 *
 * Code generation for function 'ukf_update_17_state_mexutil'
 *
 * C source code generated on: Thu Nov 20 12:39:29 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_17_state.h"
#include "ukf_update_17_state_mexutil.h"
#include "fprintf.h"
#include "ukf_update_17_state_data.h"
#include <stdio.h>

/* Function Declarations */
static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void disp(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "disp", TRUE,
                        location);
}

void emlrt_checkEscapedGlobals(void)
{
  Ts_dirty |= Ts_dirty >> 1U;
}

real_T emlrt_marshallIn(const mxArray *b_feval, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(emlrtAlias(b_feval), &thisId);
  emlrtDestroyArray(&b_feval);
  return y;
}

const mxArray *emlrt_marshallOut(real_T u)
{
  const mxArray *y;
  const mxArray *m16;
  y = NULL;
  m16 = mxCreateDoubleScalar(u);
  emlrtAssign(&y, m16);
  return y;
}

void emlrt_synchGlobalsFromML(void)
{
  Ts = emlrt_marshallIn(mexGetVariable("global", "Ts"), "Ts");
}

void emlrt_synchGlobalsToML(void)
{
  if (Ts_dirty & 1U) {
    mexPutVariable("global", "Ts", emlrt_marshallOut(Ts));
    Ts_dirty &= 2U;
  }
}

void error(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", TRUE,
                        location);
}

const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m20;
  pArray = b;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m20, 1, &pArray,
    "message", TRUE, location);
}

void warning(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "warning", TRUE,
                        location);
}

/* End of code generation (ukf_update_17_state_mexutil.c) */
