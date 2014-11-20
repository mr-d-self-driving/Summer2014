/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 * C source code generated on: Thu Nov 20 12:39:30 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_17_state.h"
#include "sum.h"
#include "ukf_update_17_state_emxutil.h"
#include "minangle.h"
#include "ukf_update_17_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo ri_emlrtRSI = { 72, "sum",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/datafun/sum.m"
};

static emlrtRSInfo si_emlrtRSI = { 76, "sum",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/datafun/sum.m"
};

static emlrtRTEInfo ab_emlrtRTEI = { 55, 1, "sum",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/datafun/sum.m"
};

static emlrtRTEInfo bb_emlrtRTEI = { 1, 14, "sum",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/datafun/sum.m"
};

/* Function Definitions */
real_T b_sum(const real_T x[3])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 2; k++) {
    y += x[k + 1];
  }

  return y;
}

void sum(const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T sz[2];
  int32_T iy;
  int32_T ixstart;
  boolean_T overflow;
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  for (iy = 0; iy < 2; iy++) {
    sz[iy] = (uint32_T)x->size[iy];
  }

  iy = y->size[0];
  y->size[0] = (int32_T)sz[0];
  emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T),
                    &ab_emlrtRTEI);
  if (x->size[0] == 0) {
    iy = y->size[0];
    y->size[0] = (int32_T)sz[0];
    emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T),
                      &bb_emlrtRTEI);
    ixstart = (int32_T)sz[0];
    for (iy = 0; iy < ixstart; iy++) {
      y->data[iy] = 0.0;
    }
  } else {
    iy = -1;
    ixstart = -1;
    emlrtPushRtStackR2012b(&ri_emlrtRSI, emlrtRootTLSGlobal);
    overflow = (x->size[0] > 2147483646);
    if (overflow) {
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&ri_emlrtRSI, emlrtRootTLSGlobal);
    for (j = 1; j <= x->size[0]; j++) {
      ixstart++;
      ix = ixstart;
      s = x->data[ixstart];
      emlrtPushRtStackR2012b(&si_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&si_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 2; k <= x->size[1]; k++) {
        ix += x->size[0];
        s += x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

/* End of code generation (sum.c) */
