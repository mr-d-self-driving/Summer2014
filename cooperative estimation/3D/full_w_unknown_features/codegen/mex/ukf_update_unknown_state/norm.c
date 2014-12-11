/*
 * norm.c
 *
 * Code generation for function 'norm'
 *
 * C source code generated on: Thu Dec 11 11:40:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "norm.h"
#include "ukf_update_unknown_state_mexutil.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo ii_emlrtRSI = { 37, "norm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/norm.m"
};

static emlrtRSInfo ji_emlrtRSI = { 39, "norm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/norm.m"
};

static emlrtRSInfo ki_emlrtRSI = { 170, "norm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/norm.m"
};

/* Function Definitions */
real_T b_norm(const emxArray_real_T *x)
{
  real_T y;
  int32_T n;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  double * xix0_t;
  if ((x->size[0] == 1) || (x->size[1] == 1)) {
    emlrtPushRtStackR2012b(&ii_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ki_emlrtRSI, emlrtRootTLSGlobal);
    n = x->size[0] * x->size[1];
    emlrtPushRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > n) {
      y = 0.0;
    } else {
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(n);
      emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      xix0_t = (double *)(&x->data[0]);
      emlrtPopRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      y = dnrm2(&n_t, xix0_t, &incx_t);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ki_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ii_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    emlrtPushRtStackR2012b(&ji_emlrtRSI, emlrtRootTLSGlobal);
    n = x->size[0] * x->size[1];
    emlrtPushRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > n) {
      y = 0.0;
    } else {
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(n);
      emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      xix0_t = (double *)(&x->data[0]);
      emlrtPopRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      y = dnrm2(&n_t, xix0_t, &incx_t);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ji_emlrtRSI, emlrtRootTLSGlobal);
  }

  return y;
}

real_T c_norm(const emxArray_real_T *x)
{
  real_T y;
  int32_T j;
  int32_T i;
  boolean_T exitg1;
  real_T s;
  if ((x->size[0] == 1) || (x->size[1] == 1)) {
    y = 0.0;
    j = x->size[0] * x->size[1];
    for (i = 0; i < j; i++) {
      y += muDoubleScalarAbs(x->data[i]);
    }
  } else {
    y = 0.0;
    j = 0;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (j <= x->size[1] - 1)) {
      s = 0.0;
      for (i = 0; i < x->size[0]; i++) {
        s += muDoubleScalarAbs(x->data[i + x->size[0] * j]);
      }

      if (muDoubleScalarIsNaN(s)) {
        y = rtNaN;
        exitg1 = TRUE;
      } else {
        if (s > y) {
          y = s;
        }

        j++;
      }
    }
  }

  return y;
}

real_T d_norm(const emxArray_creal_T *x)
{
  real_T y;
  int32_T j;
  int32_T i;
  boolean_T exitg1;
  real_T s;
  if ((x->size[0] == 1) || (x->size[1] == 1)) {
    y = 0.0;
    j = x->size[0] * x->size[1];
    for (i = 0; i < j; i++) {
      y += muDoubleScalarHypot(x->data[i].re, x->data[i].im);
    }
  } else {
    y = 0.0;
    j = 0;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (j <= x->size[1] - 1)) {
      s = 0.0;
      for (i = 0; i < x->size[0]; i++) {
        s += muDoubleScalarHypot(x->data[i + x->size[0] * j].re, x->data[i +
          x->size[0] * j].im);
      }

      if (muDoubleScalarIsNaN(s)) {
        y = rtNaN;
        exitg1 = TRUE;
      } else {
        if (s > y) {
          y = s;
        }

        j++;
      }
    }
  }

  return y;
}

real_T e_norm(const real_T x[4])
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 4; k++) {
    absxk = muDoubleScalarAbs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

real_T f_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 3; k++) {
    absxk = muDoubleScalarAbs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

real_T norm(const emxArray_creal_T *x)
{
  real_T y;
  int32_T n;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  double * xix0_t;
  if ((x->size[0] == 1) || (x->size[1] == 1)) {
    emlrtPushRtStackR2012b(&ii_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ki_emlrtRSI, emlrtRootTLSGlobal);
    n = x->size[0] * x->size[1];
    emlrtPushRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > n) {
      y = 0.0;
    } else {
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(n);
      emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      xix0_t = (double *)(&x->data[0]);
      emlrtPopRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      y = dznrm2(&n_t, xix0_t, &incx_t);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ki_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ii_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    emlrtPushRtStackR2012b(&ji_emlrtRSI, emlrtRootTLSGlobal);
    n = x->size[0] * x->size[1];
    emlrtPushRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > n) {
      y = 0.0;
    } else {
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(n);
      emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&oc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      xix0_t = (double *)(&x->data[0]);
      emlrtPopRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      y = dznrm2(&n_t, xix0_t, &incx_t);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ji_emlrtRSI, emlrtRootTLSGlobal);
  }

  return y;
}

/* End of code generation (norm.c) */
