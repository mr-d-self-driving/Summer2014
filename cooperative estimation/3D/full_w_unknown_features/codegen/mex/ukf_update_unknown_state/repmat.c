/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 * C source code generated on: Thu Dec 11 11:40:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "repmat.h"
#include "minangle.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "ukf_update_unknown_state_mexutil.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo pi_emlrtRSI = { 11, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

static emlrtRSInfo qi_emlrtRSI = { 58, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

static emlrtRSInfo ri_emlrtRSI = { 60, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

static emlrtRSInfo si_emlrtRSI = { 61, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

static emlrtRTEInfo y_emlrtRTEI = { 45, 1, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

/* Function Definitions */
void repmat(const real_T a_data[1001], const int32_T a_size[2], real_T m,
            emxArray_real_T *b)
{
  boolean_T p;
  const mxArray *y;
  static const int32_T iv50[2] = { 1, 28 };

  const mxArray *m7;
  char_T cv26[28];
  int32_T i;
  static const char_T cv27[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I',
    'n', 'p', 'u', 't' };

  real_T b_m;
  const mxArray *b_y;
  static const int32_T iv51[2] = { 1, 21 };

  char_T cv28[21];
  static const char_T cv29[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T mv[2];
  int32_T outsize[2];
  int32_T ib;
  int32_T iacol;
  int32_T jcol;
  boolean_T b1;
  int32_T itilerow;
  emlrtPushRtStackR2012b(&pi_emlrtRSI, emlrtRootTLSGlobal);
  if ((m != m) || muDoubleScalarIsInf(m)) {
    p = FALSE;
  } else {
    p = TRUE;
  }

  if (p) {
  } else {
    emlrtPushRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    y = NULL;
    m7 = mxCreateCharArray(2, iv50);
    for (i = 0; i < 28; i++) {
      cv26[i] = cv27[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 28, m7, cv26);
    emlrtAssign(&y, m7);
    error(message(y, &r_emlrtMCI), &s_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
  }

  if (m <= 0.0) {
    b_m = 0.0;
  } else {
    b_m = m;
  }

  if (2.147483647E+9 >= b_m) {
  } else {
    emlrtPushRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    b_y = NULL;
    m7 = mxCreateCharArray(2, iv51);
    for (i = 0; i < 21; i++) {
      cv28[i] = cv29[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m7, cv28);
    emlrtAssign(&b_y, m7);
    error(message(b_y, &t_emlrtMCI), &u_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&pi_emlrtRSI, emlrtRootTLSGlobal);
  mv[0] = (int32_T)m;
  mv[1] = 1;
  for (i = 0; i < 2; i++) {
    outsize[i] = a_size[i] * mv[i];
  }

  i = b->size[0] * b->size[1];
  b->size[0] = outsize[0];
  b->size[1] = outsize[1];
  emxEnsureCapacity((emxArray__common *)b, i, (int32_T)sizeof(real_T),
                    &y_emlrtRTEI);
  if (outsize[0] == 0) {
  } else {
    i = 0;
    ib = 0;
    emlrtPushRtStackR2012b(&qi_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&qi_emlrtRSI, emlrtRootTLSGlobal);
    iacol = 0;
    emlrtPushRtStackR2012b(&ri_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ri_emlrtRSI, emlrtRootTLSGlobal);
    for (jcol = 1; jcol <= a_size[1]; jcol++) {
      emlrtPushRtStackR2012b(&si_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > (int32_T)m) {
        b1 = FALSE;
      } else {
        b1 = ((int32_T)m > 2147483646);
      }

      if (b1) {
        emlrtPushRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&si_emlrtRSI, emlrtRootTLSGlobal);
      for (itilerow = 1; itilerow <= (int32_T)m; itilerow++) {
        b->data[ib] = a_data[iacol];
        i = iacol + 1;
        ib++;
      }

      iacol = i;
    }
  }
}

/* End of code generation (repmat.c) */
