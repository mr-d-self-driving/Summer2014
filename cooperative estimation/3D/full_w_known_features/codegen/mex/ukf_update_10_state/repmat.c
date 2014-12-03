/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "repmat.h"
#include "minangle.h"
#include "ukf_update_10_state_emxutil.h"
#include "ukf_update_10_state_mexutil.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo ki_emlrtRSI = { 11, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

static emlrtRSInfo li_emlrtRSI = { 58, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

static emlrtRSInfo mi_emlrtRSI = { 60, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

static emlrtRSInfo ni_emlrtRSI = { 61, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

static emlrtRTEInfo y_emlrtRTEI = { 45, 1, "repmat",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m"
};

/* Function Definitions */
void repmat(const real_T a_data[2201], const int32_T a_size[2], real_T m,
            emxArray_real_T *b)
{
  boolean_T p;
  const mxArray *y;
  static const int32_T iv27[2] = { 1, 28 };

  const mxArray *m7;
  char_T cv27[28];
  int32_T i;
  static const char_T cv28[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I',
    'n', 'p', 'u', 't' };

  real_T b_m;
  const mxArray *b_y;
  static const int32_T iv28[2] = { 1, 21 };

  char_T cv29[21];
  static const char_T cv30[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T mv[2];
  int32_T outsize[2];
  int32_T ib;
  int32_T iacol;
  int32_T jcol;
  boolean_T b2;
  int32_T itilerow;
  emlrtPushRtStackR2012b(&ki_emlrtRSI, emlrtRootTLSGlobal);
  if ((m != m) || muDoubleScalarIsInf(m)) {
    p = FALSE;
  } else {
    p = TRUE;
  }

  if (p) {
  } else {
    emlrtPushRtStackR2012b(&oi_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    y = NULL;
    m7 = mxCreateCharArray(2, iv27);
    for (i = 0; i < 28; i++) {
      cv27[i] = cv28[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 28, m7, cv27);
    emlrtAssign(&y, m7);
    error(message(y, &s_emlrtMCI), &t_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&oi_emlrtRSI, emlrtRootTLSGlobal);
  }

  if (m <= 0.0) {
    b_m = 0.0;
  } else {
    b_m = m;
  }

  if (2.147483647E+9 >= b_m) {
  } else {
    emlrtPushRtStackR2012b(&pi_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    b_y = NULL;
    m7 = mxCreateCharArray(2, iv28);
    for (i = 0; i < 21; i++) {
      cv29[i] = cv30[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m7, cv29);
    emlrtAssign(&b_y, m7);
    error(message(b_y, &u_emlrtMCI), &v_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&pi_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&ki_emlrtRSI, emlrtRootTLSGlobal);
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
    emlrtPushRtStackR2012b(&li_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&li_emlrtRSI, emlrtRootTLSGlobal);
    iacol = 0;
    emlrtPushRtStackR2012b(&mi_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&mi_emlrtRSI, emlrtRootTLSGlobal);
    for (jcol = 1; jcol <= a_size[1]; jcol++) {
      emlrtPushRtStackR2012b(&ni_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > (int32_T)m) {
        b2 = FALSE;
      } else {
        b2 = ((int32_T)m > 2147483646);
      }

      if (b2) {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ni_emlrtRSI, emlrtRootTLSGlobal);
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
