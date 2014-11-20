/*
 * update_eq_17_state_mexutil.c
 *
 * Code generation for function 'update_eq_17_state_mexutil'
 *
 * C source code generated on: Thu Nov 20 12:06:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "update_eq_17_state.h"
#include "update_eq_17_state_mexutil.h"
#include "update_eq_17_state_api.h"
#include "update_eq_17_state_data.h"

/* Function Declarations */
static real_T h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);

/* Function Definitions */
static real_T h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void emlrt_checkEscapedGlobals(void)
{
  Ts_dirty |= Ts_dirty >> 1U;
}

const mxArray *emlrt_marshallOut(real_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = mxCreateDoubleScalar(u);
  emlrtAssign(&y, m1);
  return y;
}

void emlrt_synchGlobalsFromML(void)
{
  Ts = g_emlrt_marshallIn(mexGetVariable("global", "Ts"), "Ts");
}

void emlrt_synchGlobalsToML(void)
{
  if (Ts_dirty & 1U) {
    mexPutVariable("global", "Ts", emlrt_marshallOut(Ts));
    Ts_dirty &= 2U;
  }
}

real_T g_emlrt_marshallIn(const mxArray *c_Ts, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = h_emlrt_marshallIn(emlrtAlias(c_Ts), &thisId);
  emlrtDestroyArray(&c_Ts);
  return y;
}

/* End of code generation (update_eq_17_state_mexutil.c) */
