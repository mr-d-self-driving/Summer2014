/*
 * vector2polar.c
 *
 * Code generation for function 'vector2polar'
 *
 * C source code generated on: Thu Dec 11 11:40:55 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "vector2polar.h"
#include "mldivide.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo vj_emlrtRSI = { 3, "vector2polar",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m"
};

static emlrtRSInfo wj_emlrtRSI = { 5, "vector2polar",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m"
};

/* Function Definitions */
void vector2polar(const real_T r[3], real_T rbd[3])
{
  real_T y[3];
  int32_T k;
  real_T b_y;
  emlrtPushRtStackR2012b(&vj_emlrtRSI, emlrtRootTLSGlobal);
  for (k = 0; k < 3; k++) {
    y[k] = r[k] * r[k];
  }

  b_y = y[0];
  for (k = 0; k < 2; k++) {
    b_y += y[k + 1];
  }

  if (b_y < 0.0) {
    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    eml_error();
    emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  }

  rbd[0] = muDoubleScalarSqrt(b_y);
  emlrtPopRtStackR2012b(&vj_emlrtRSI, emlrtRootTLSGlobal);
  rbd[1] = muDoubleScalarAtan2(r[1], r[0]);
  emlrtPushRtStackR2012b(&wj_emlrtRSI, emlrtRootTLSGlobal);
  b_y = r[0] * r[0] + r[1] * r[1];
  if (b_y < 0.0) {
    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    eml_error();
    emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  }

  rbd[2] = muDoubleScalarAtan2(r[2], muDoubleScalarSqrt(b_y));
  emlrtPopRtStackR2012b(&wj_emlrtRSI, emlrtRootTLSGlobal);
}

/* End of code generation (vector2polar.c) */
