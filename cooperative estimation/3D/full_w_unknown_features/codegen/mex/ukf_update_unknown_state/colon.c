/*
 * colon.c
 *
 * Code generation for function 'colon'
 *
 * C source code generated on: Tue Dec  9 10:58:58 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "colon.h"
#include "minangle.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo rk_emlrtRSI = { 238, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo sk_emlrtRSI = { 265, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo el_emlrtRSI = { 151, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo fl_emlrtRSI = { 156, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRTEInfo mb_emlrtRTEI = { 152, 1, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

/* Function Definitions */
void eml_signed_integer_colon(int32_T b, emxArray_int32_T *y)
{
  int32_T n;
  int32_T yk;
  boolean_T b3;
  int32_T k;
  emlrtPushRtStackR2012b(&el_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&rk_emlrtRSI, emlrtRootTLSGlobal);
  if (b < 1) {
    n = 0;
  } else {
    emlrtPushRtStackR2012b(&sk_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&sk_emlrtRSI, emlrtRootTLSGlobal);
    n = b;
  }

  emlrtPopRtStackR2012b(&rk_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&el_emlrtRSI, emlrtRootTLSGlobal);
  yk = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity((emxArray__common *)y, yk, (int32_T)sizeof(int32_T),
                    &mb_emlrtRTEI);
  if (n > 0) {
    y->data[0] = 1;
    yk = 1;
    emlrtPushRtStackR2012b(&fl_emlrtRSI, emlrtRootTLSGlobal);
    if (2 > n) {
      b3 = FALSE;
    } else {
      b3 = (n > 2147483646);
    }

    if (b3) {
      emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&fl_emlrtRSI, emlrtRootTLSGlobal);
    for (k = 2; k <= n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }
}

/* End of code generation (colon.c) */
