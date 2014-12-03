/*
 * measurement_eq_10_state.c
 *
 * Code generation for function 'measurement_eq_10_state'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "measurement_eq_10_state.h"
#include "mldivide.h"
#include "minangle.h"
#include "ukf_update_10_state_emxutil.h"
#include "ukf_update_10_state_mexutil.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 401, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo si_emlrtRSI = { 15, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtRSInfo ti_emlrtRSI = { 39, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtRSInfo ui_emlrtRSI = { 45, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtRSInfo vi_emlrtRSI = { 46, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtRSInfo wi_emlrtRSI = { 68, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo xi_emlrtRSI = { 66, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo yi_emlrtRSI = { 61, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo aj_emlrtRSI = { 49, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo bj_emlrtRSI = { 3, "vector2polar",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m"
};

static emlrtMCInfo c_emlrtMCI = { 402, 5, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtMCInfo d_emlrtMCI = { 401, 15, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtMCInfo w_emlrtMCI = { 49, 17, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtMCInfo x_emlrtMCI = { 67, 5, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtMCInfo y_emlrtMCI = { 66, 15, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRTEInfo cb_emlrtRTEI = { 1, 15, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtRTEInfo db_emlrtRTEI = { 65, 1, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRTEInfo eb_emlrtRTEI = { 15, 5, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtECInfo pb_emlrtECI = { -1, 46, 9, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 46, 24, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 46, 14, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtDCInfo m_emlrtDCI = { 46, 14, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  1 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 46, 60, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtDCInfo n_emlrtDCI = { 46, 60, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  1 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 46, 53, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 46, 43, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtDCInfo o_emlrtDCI = { 46, 43, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  1 };

static emlrtECInfo qb_emlrtECI = { -1, 45, 9, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 45, 24, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 45, 14, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtDCInfo p_emlrtDCI = { 45, 14, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  1 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 45, 60, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtDCInfo q_emlrtDCI = { 45, 60, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  1 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 45, 53, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 45, 43, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtDCInfo r_emlrtDCI = { 45, 43, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  1 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 40, 18, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtECInfo rb_emlrtECI = { -1, 34, 20, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 34, 26, "RKN_1",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtRTEInfo ec_emlrtRTEI = { 32, 5, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 28, 19, "xk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 26, 18, "xk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtECInfo sb_emlrtECI = { -1, 15, 21, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m"
};

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 10, 6, "uk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 15, 21, "uk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtDCInfo s_emlrtDCI = { 15, 21, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  1 };

static emlrtDCInfo t_emlrtDCI = { 23, 12, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  1 };

static emlrtDCInfo u_emlrtDCI = { 23, 12, "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  4 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 26, 14, "xk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 28, 14, "xk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 40, 12, "yk",
  "measurement_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_10_state.m",
  0 };

/* Function Declarations */
static void b_eml_error(void);
static int32_T div_s32(int32_T numerator, int32_T denominator);

/* Function Definitions */
static void b_eml_error(void)
{
  emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &dc_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
}

static int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  int32_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(0, emlrtRootTLSGlobal);
  } else {
    if (numerator >= 0) {
      absNumerator = (uint32_T)numerator;
    } else {
      absNumerator = (uint32_T)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (uint32_T)denominator;
    } else {
      absDenominator = (uint32_T)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if ((uint32_T)quotientNeedsNegation) {
      quotient = -(int32_T)absNumerator;
    } else {
      quotient = (int32_T)absNumerator;
    }
  }

  return quotient;
}

void measurement_eq_10_state(const emxArray_real_T *xk, const real_T uk_data[500],
  const int32_T uk_size[1], emxArray_real_T *yk)
{
  emxArray_real_T *RKN_1;
  real_T y;
  int32_T n;
  real_T anew;
  real_T apnd;
  boolean_T overflow;
  real_T ndbl;
  real_T cdiff;
  const mxArray *b_y;
  static const int32_T iv29[2] = { 1, 21 };

  const mxArray *m8;
  char_T cv31[21];
  int32_T i;
  static const char_T cv32[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *r10;
  int32_T i8;
  int32_T k;
  int32_T loop_ub;
  int32_T i9;
  int32_T sz[2];
  emxArray_int32_T *r11;
  emxArray_int32_T *r12;
  const mxArray *c_y;
  emxArray_int32_T *r13;
  emxArray_int32_T *r14;
  emxArray_int32_T *r15;
  emxArray_real_T *d_y;
  emxArray_int32_T *r16;
  const mxArray *e_y;
  static const int32_T iv30[2] = { 1, 40 };

  char_T cv33[40];
  static const char_T cv34[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  emxArray_int32_T *r17;
  emxArray_int32_T *r18;
  emxArray_int32_T *r19;
  int32_T exitg1;
  emxArray_int32_T *r20;
  emxArray_real_T *r21;
  emxArray_real_T *b_yk;
  emxArray_real_T *c_yk;
  real_T DCM[9];
  int32_T kk;
  real_T tmp_data[3];
  real_T f_y[3];
  real_T rki[3];
  real_T y_kk[3];
  int32_T i10;
  int32_T i11;
  int32_T i12;
  int32_T i13;
  int32_T i14;
  int32_T iv31[1];
  int32_T iv32[1];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /*  m1: # of features agent 1 sees */
  /* xk: 10 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion */
  /* nk: 3*m1 x 2N+1, feature range/bearing/azimuth errors FOR EACH FEATURE */
  /* uk[wi;ai;# of i features;rkn;...;# of j features;rkn;...] : 6+2+3*m x 2N+1, m being total # of features from i and j  */
  emlrtDynamicBoundsCheckFastR2012b(7, 1, uk_size[0], &uc_emlrtBCI,
    emlrtRootTLSGlobal);

  /*  total # of features */
  /*  3 x m1 array of known inertial position of features seen by agent 1 */
  emxInit_real_T(&RKN_1, 2, &eb_emlrtRTEI, TRUE);
  if (uk_data[6] > 0.0) {
    emlrtPushRtStackR2012b(&si_emlrtRSI, emlrtRootTLSGlobal);
    y = uk_data[6] * 3.0;
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    if (muDoubleScalarIsNaN(y)) {
      n = 0;
      anew = rtNaN;
      apnd = y;
      overflow = FALSE;
    } else if (y < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = y;
      overflow = FALSE;
    } else if (muDoubleScalarIsInf(y)) {
      n = 0;
      anew = rtNaN;
      apnd = y;
      overflow = !(1.0 == y);
    } else {
      anew = 1.0;
      ndbl = muDoubleScalarFloor((y - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - y;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * y) {
        ndbl++;
        apnd = y;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      overflow = (2.147483647E+9 < ndbl);
      n = (int32_T)ndbl - 1;
    }

    emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    if (!overflow) {
    } else {
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      b_y = NULL;
      m8 = mxCreateCharArray(2, iv29);
      for (i = 0; i < 21; i++) {
        cv31[i] = cv32[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv31);
      emlrtAssign(&b_y, m8);
      error(message(b_y, &c_emlrtMCI), &d_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_real_T(&r10, 2, &cb_emlrtRTEI, TRUE);
    emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    i8 = r10->size[0] * r10->size[1];
    r10->size[0] = 1;
    r10->size[1] = n + 1;
    emxEnsureCapacity((emxArray__common *)r10, i8, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (n + 1 > 0) {
      r10->data[0] = anew;
      if (n + 1 > 1) {
        r10->data[n] = apnd;
        i8 = n + (n < 0);
        if (i8 >= 0) {
          i = (int32_T)((uint32_T)i8 >> 1);
        } else {
          i = ~(int32_T)((uint32_T)~i8 >> 1);
        }

        emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k < i; k++) {
          r10->data[k] = anew + (real_T)k;
          r10->data[n - k] = apnd - (real_T)k;
        }

        if (i << 1 == n) {
          r10->data[i] = (anew + apnd) / 2.0;
        } else {
          r10->data[i] = anew + (real_T)i;
          r10->data[i + 1] = apnd - (real_T)i;
        }
      }
    }

    emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&si_emlrtRSI, emlrtRootTLSGlobal);
    emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, r10->size[1],
      &sb_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&si_emlrtRSI, emlrtRootTLSGlobal);
    loop_ub = r10->size[0] * r10->size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      anew = 7.0 + r10->data[i8];
      i9 = (int32_T)emlrtIntegerCheckFastR2012b(anew, &s_emlrtDCI,
        emlrtRootTLSGlobal);
      emlrtDynamicBoundsCheckFastR2012b(i9, 1, uk_size[0], &vc_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    sz[0] = 3;
    sz[1] = 1;
    i = 1;
    for (k = 0; k < 2; k++) {
      i *= sz[k];
    }

    if (i > 0) {
      emxInit_int32_T(&r11, 2, &cb_emlrtRTEI, TRUE);
      i8 = r11->size[0] * r11->size[1];
      r11->size[0] = 1;
      r11->size[1] = r10->size[1];
      emxEnsureCapacity((emxArray__common *)r11, i8, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r10->size[0] * r10->size[1];
      for (i8 = 0; i8 < loop_ub; i8++) {
        r11->data[i8] = (int32_T)(7.0 + r10->data[i8]);
      }

      emxInit_int32_T(&r12, 2, &cb_emlrtRTEI, TRUE);
      n = r11->size[1];
      i = div_s32(n, i);
      i8 = r12->size[0] * r12->size[1];
      r12->size[0] = 1;
      r12->size[1] = r10->size[1];
      emxEnsureCapacity((emxArray__common *)r12, i8, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r10->size[0] * r10->size[1];
      emxFree_int32_T(&r11);
      for (i8 = 0; i8 < loop_ub; i8++) {
        r12->data[i8] = (int32_T)(7.0 + r10->data[i8]);
      }

      n = r12->size[1];
      emxFree_int32_T(&r12);
      if (i <= n) {
      } else {
        emlrtPushRtStackR2012b(&aj_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        c_y = NULL;
        m8 = mxCreateString("Assertion failed.");
        emlrtAssign(&c_y, m8);
        error(c_y, &w_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&aj_emlrtRSI, emlrtRootTLSGlobal);
      }

      sz[1] = i;
    } else {
      sz[1] = 0;
    }

    emxInit_int32_T(&r13, 2, &cb_emlrtRTEI, TRUE);
    i8 = r13->size[0] * r13->size[1];
    r13->size[0] = 1;
    r13->size[1] = r10->size[1];
    emxEnsureCapacity((emxArray__common *)r13, i8, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r10->size[0] * r10->size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      r13->data[i8] = (int32_T)(7.0 + r10->data[i8]);
    }

    i = r13->size[1];
    emxFree_int32_T(&r13);
    if (1 > i) {
      i = 1;
    }

    emxInit_int32_T(&r14, 2, &cb_emlrtRTEI, TRUE);
    i8 = r14->size[0] * r14->size[1];
    r14->size[0] = 1;
    r14->size[1] = r10->size[1];
    emxEnsureCapacity((emxArray__common *)r14, i8, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r10->size[0] * r10->size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      r14->data[i8] = (int32_T)(7.0 + r10->data[i8]);
    }

    n = r14->size[1];
    emxFree_int32_T(&r14);
    if (n < i) {
    } else {
      emxInit_int32_T(&r15, 2, &cb_emlrtRTEI, TRUE);
      i8 = r15->size[0] * r15->size[1];
      r15->size[0] = 1;
      r15->size[1] = r10->size[1];
      emxEnsureCapacity((emxArray__common *)r15, i8, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r10->size[0] * r10->size[1];
      for (i8 = 0; i8 < loop_ub; i8++) {
        r15->data[i8] = (int32_T)(7.0 + r10->data[i8]);
      }

      i = r15->size[1];
      emxFree_int32_T(&r15);
    }

    if (3 > i) {
      emlrtPushRtStackR2012b(&yi_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&yi_emlrtRSI, emlrtRootTLSGlobal);
    }

    if (sz[1] > i) {
      emlrtPushRtStackR2012b(&yi_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&yi_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_real_T(&d_y, 2, &cb_emlrtRTEI, TRUE);
    emxInit_int32_T(&r16, 2, &cb_emlrtRTEI, TRUE);
    i8 = d_y->size[0] * d_y->size[1];
    d_y->size[0] = 3;
    d_y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)d_y, i8, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    i8 = r16->size[0] * r16->size[1];
    r16->size[0] = 1;
    r16->size[1] = r10->size[1];
    emxEnsureCapacity((emxArray__common *)r16, i8, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r10->size[0] * r10->size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      r16->data[i8] = (int32_T)(7.0 + r10->data[i8]);
    }

    n = r16->size[1];
    emxFree_int32_T(&r16);
    if (n == 3 * sz[1]) {
    } else {
      emlrtPushRtStackR2012b(&xi_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      e_y = NULL;
      m8 = mxCreateCharArray(2, iv30);
      for (i = 0; i < 40; i++) {
        cv33[i] = cv34[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 40, m8, cv33);
      emlrtAssign(&e_y, m8);
      error(message(e_y, &x_emlrtMCI), &y_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&xi_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r17, 2, &cb_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&wi_emlrtRSI, emlrtRootTLSGlobal);
    i8 = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    r17->size[1] = r10->size[1];
    emxEnsureCapacity((emxArray__common *)r17, i8, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r10->size[0] * r10->size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      r17->data[i8] = (int32_T)(7.0 + r10->data[i8]);
    }

    n = r17->size[1];
    emxFree_int32_T(&r17);
    if (1 > n) {
      overflow = FALSE;
    } else {
      emxInit_int32_T(&r18, 2, &cb_emlrtRTEI, TRUE);
      i8 = r18->size[0] * r18->size[1];
      r18->size[0] = 1;
      r18->size[1] = r10->size[1];
      emxEnsureCapacity((emxArray__common *)r18, i8, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r10->size[0] * r10->size[1];
      for (i8 = 0; i8 < loop_ub; i8++) {
        r18->data[i8] = (int32_T)(7.0 + r10->data[i8]);
      }

      n = r18->size[1];
      overflow = (n > 2147483646);
      emxFree_int32_T(&r18);
    }

    if (overflow) {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&wi_emlrtRSI, emlrtRootTLSGlobal);
    k = 0;
    emxInit_int32_T(&r19, 2, &cb_emlrtRTEI, TRUE);
    do {
      exitg1 = 0;
      i8 = r19->size[0] * r19->size[1];
      r19->size[0] = 1;
      r19->size[1] = r10->size[1];
      emxEnsureCapacity((emxArray__common *)r19, i8, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r10->size[0] * r10->size[1];
      for (i8 = 0; i8 < loop_ub; i8++) {
        r19->data[i8] = (int32_T)(7.0 + r10->data[i8]);
      }

      n = r19->size[1];
      if (k + 1 <= n) {
        d_y->data[k] = uk_data[(int32_T)(7.0 + r10->data[r10->size[0] * k]) - 1];
        k++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_int32_T(&r19);
    emxFree_real_T(&r10);
    i8 = RKN_1->size[0] * RKN_1->size[1];
    RKN_1->size[0] = d_y->size[1];
    RKN_1->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)RKN_1, i8, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
    for (i8 = 0; i8 < 3; i8++) {
      loop_ub = d_y->size[1];
      for (i9 = 0; i9 < loop_ub; i9++) {
        RKN_1->data[i9 + RKN_1->size[0] * i8] = d_y->data[i8 + d_y->size[0] * i9];
      }
    }

    emxFree_real_T(&d_y);
    emlrtPopRtStackR2012b(&si_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    i8 = RKN_1->size[0] * RKN_1->size[1];
    RKN_1->size[0] = 0;
    RKN_1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)RKN_1, i8, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
  }

  y = 3.0 * uk_data[6];
  anew = emlrtNonNegativeCheckFastR2012b(y, &u_emlrtDCI, emlrtRootTLSGlobal);
  emlrtIntegerCheckFastR2012b(anew, &t_emlrtDCI, emlrtRootTLSGlobal);
  i8 = yk->size[0] * yk->size[1];
  yk->size[0] = (int32_T)y;
  emxEnsureCapacity((emxArray__common *)yk, i8, (int32_T)sizeof(real_T),
                    &cb_emlrtRTEI);
  anew = emlrtNonNegativeCheckFastR2012b(y, &u_emlrtDCI, emlrtRootTLSGlobal);
  emlrtIntegerCheckFastR2012b(anew, &t_emlrtDCI, emlrtRootTLSGlobal);
  i = xk->size[1];
  i8 = yk->size[0] * yk->size[1];
  yk->size[1] = i;
  emxEnsureCapacity((emxArray__common *)yk, i8, (int32_T)sizeof(real_T),
                    &cb_emlrtRTEI);
  anew = emlrtNonNegativeCheckFastR2012b(y, &u_emlrtDCI, emlrtRootTLSGlobal);
  loop_ub = (int32_T)emlrtIntegerCheckFastR2012b(anew, &t_emlrtDCI,
    emlrtRootTLSGlobal) * xk->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    yk->data[i8] = 0.0;
  }

  k = 0;
  b_emxInit_int32_T(&r20, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r21, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&b_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&c_yk, 1, &cb_emlrtRTEI, TRUE);
  while (k <= xk->size[1] - 1) {
    /*  estimated my inertial position */
    for (i8 = 0; i8 < 3; i8++) {
      i9 = xk->size[0];
      n = 1 + i8;
      emlrtDynamicBoundsCheckFastR2012b(n, 1, i9, &wc_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i8 = xk->size[1];
    i9 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &tc_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  my estimated inertial attitude */
    for (i8 = 0; i8 < 4; i8++) {
      i9 = xk->size[0];
      n = 7 + i8;
      emlrtDynamicBoundsCheckFastR2012b(n, 1, i9, &xc_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i8 = xk->size[1];
    i9 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &sc_emlrtBCI,
      emlrtRootTLSGlobal);

    /* Tim Woodbury */
    /* modified for AERO 622 */
    /*  */
    /* [Y] = attpar(X,I,options) */
    /* Function to convert between attitude parametrizations */
    /*  */
    /* INPUTS: */
    /* X - matrix input of appropriate dimension (detailed later) */
    /* I - 2 x 1 indexing vector indicating the input (I(1)) and output (I(2)) */
    /*     attitude parametrizations, corresponding to the numbers in the section, */
    /*     "I/O SPECIFICATION PARAMETERS". */
    /* options - a data structure. Currently only allows output Euler angle */
    /*     sequence to be defined. Supported members are "seq" which should be a */
    /*     [3 x 1] vector describing the first, second, and third rotations in */
    /*     the desired output sequence. */
    /*  */
    /* OUTPUTS: */
    /* Y - output matrix of appropriate dimensions. */
    /*     All angles are in radians. */
    /*  */
    /* I/O SPECIFICATION PARAMETERS: */
    /* 1 - Direction cosine matrix, dimensions [3 x 3] */
    /* 2 - Euler principal axis/angle, [3 x 2]. [:,1] is the principal axis; */
    /*     [1,2] is the principal angle (rad). */
    /* 3 - 2-angle parametrization, [3 x 4] */
    /* 4 - Euler angle sequence, [3 x 2]. [:,1] are the rotation angles in radians,  */
    /*      and [2,1]-[2,2]-[2,3] is the rotation sequence.  */
    /*      [3-1-3] sequence is default for output. Other sequences may be specified */
    /*      by passing an optional data structure with a [3 x 1] member "seq" whose */
    /*      entries [a;b;c] correspond to the sequence a-b-c. Any input sequence */
    /*      may be used by specifying the second column of input appropriately. */
    /* 5 - Classical Rodrigues parameters [3 x 1] */
    /* 6 - quaternion [4 x 1]. The scalar part of the quaternion comes FIRST. */
    /* 7 - modified Rodrigues parameters [3 x 1] */
    /* 8 - exponential matrix, [3 x 3] */
    /* 9 - Cayley-Klein parameters, [2 x 2] */
    /* check if any options are passed */
    /* %check if output and inp are the same - if so do nothing */
    /* for each inp, convert to DCM */
    /* quaternion */
    /* disp('Input value specified as quaternion.'); */
    DCM[0] = ((xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 7] -
               xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k + 8]) -
              xk->data[xk->size[0] * k + 9] * xk->data[xk->size[0] * k + 9]) +
      xk->data[6 + xk->size[0] * k] * xk->data[6 + xk->size[0] * k];
    DCM[3] = 2.0 * (xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 8]
                    + xk->data[xk->size[0] * k + 9] * xk->data[6 + xk->size[0] *
                    k]);
    DCM[6] = 2.0 * (xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 9]
                    - xk->data[xk->size[0] * k + 8] * xk->data[6 + xk->size[0] *
                    k]);
    DCM[1] = 2.0 * (xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 8]
                    - xk->data[xk->size[0] * k + 9] * xk->data[6 + xk->size[0] *
                    k]);
    DCM[4] = ((xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k + 8] -
               xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 7]) -
              xk->data[xk->size[0] * k + 9] * xk->data[xk->size[0] * k + 9]) +
      xk->data[6 + xk->size[0] * k] * xk->data[6 + xk->size[0] * k];
    DCM[7] = 2.0 * (xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k + 9]
                    + xk->data[xk->size[0] * k + 7] * xk->data[6 + xk->size[0] *
                    k]);
    DCM[2] = 2.0 * (xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 9]
                    + xk->data[xk->size[0] * k + 8] * xk->data[6 + xk->size[0] *
                    k]);
    DCM[5] = 2.0 * (xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k + 9]
                    - xk->data[xk->size[0] * k + 7] * xk->data[6 + xk->size[0] *
                    k]);
    DCM[8] = ((xk->data[xk->size[0] * k + 9] * xk->data[xk->size[0] * k + 9] -
               xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 7]) -
              xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k + 8]) +
      xk->data[6 + xk->size[0] * k] * xk->data[6 + xk->size[0] * k];

    /* convert DCM to output form */
    /* DCM */
    /* disp('Output value specified as direction cosine matrix.'); */
    /*  feature measurements */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, uk_data[6], mxDOUBLE_CLASS, (int32_T)
      uk_data[6], &ec_emlrtRTEI, emlrtRootTLSGlobal);
    kk = 0;
    while (kk <= (int32_T)uk_data[6] - 1) {
      /*  get the i frame vector to the feature */
      loop_ub = RKN_1->size[1];
      i8 = RKN_1->size[0];
      i9 = (int32_T)(1.0 + (real_T)kk);
      i8 = emlrtDynamicBoundsCheckFastR2012b(i9, 1, i8, &rc_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i9 = 0; i9 < loop_ub; i9++) {
        tmp_data[i9] = RKN_1->data[(i8 + RKN_1->size[0] * i9) - 1];
      }

      emlrtSizeEqCheck1DFastR2012b(loop_ub, 3, &rb_emlrtECI, emlrtRootTLSGlobal);
      for (i8 = 0; i8 < 3; i8++) {
        f_y[i8] = tmp_data[i8] - xk->data[i8 + xk->size[0] * k];
      }

      for (i8 = 0; i8 < 3; i8++) {
        rki[i8] = 0.0;
        for (i9 = 0; i9 < 3; i9++) {
          rki[i8] += DCM[i8 + 3 * i9] * f_y[i9];
        }
      }

      /*  the index for now */
      y = ((1.0 + (real_T)kk) - 1.0) * 3.0;

      /*  compute range/bearing/declination */
      /* y_kk = [sqrt(sum(rki.^2));atan2(rki(2),rki(1));atan2(rki(3),sqrt(sum(rki(1:2).^2)))] + nk(index,k); */
      emlrtPushRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&bj_emlrtRSI, emlrtRootTLSGlobal);
      for (i = 0; i < 3; i++) {
        f_y[i] = rki[i] * rki[i];
      }

      anew = f_y[0];
      for (i = 0; i < 2; i++) {
        anew += f_y[i + 1];
      }

      if (anew < 0.0) {
        emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
        eml_error();
        emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      }

      y_kk[0] = muDoubleScalarSqrt(anew);
      emlrtPopRtStackR2012b(&bj_emlrtRSI, emlrtRootTLSGlobal);
      y_kk[1] = muDoubleScalarAtan2(rki[1], rki[0]);
      y_kk[2] = muDoubleScalarAtan2(rki[2], rki[0] * rki[0] + rki[1] * rki[1]);
      emlrtPopRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
      n = yk->size[0];
      i = yk->size[1];
      i8 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i8, 1, i, &qc_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i8 = 0; i8 < 3; i8++) {
        i9 = (int32_T)(y + (1.0 + (real_T)i8));
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i9, 1, n, &yc_emlrtBCI,
                   emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = y_kk[i8];
      }

      kk++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    if (1 + k > 1) {
      /*  minimize all angle differences */
      anew = 3.0 * uk_data[6];
      if (2.0 > anew) {
        i8 = 1;
        i9 = 1;
        n = 0;
      } else {
        i8 = yk->size[0];
        emlrtDynamicBoundsCheckFastR2012b(2, 1, i8, &pc_emlrtBCI,
          emlrtRootTLSGlobal);
        i8 = 2;
        i9 = 3;
        n = yk->size[0];
        kk = (int32_T)emlrtIntegerCheckFastR2012b(anew, &r_emlrtDCI,
          emlrtRootTLSGlobal);
        n = emlrtDynamicBoundsCheckFastR2012b(kk, 1, n, &pc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      anew = 3.0 * uk_data[6];
      if (2.0 > anew) {
        kk = 1;
        i10 = 1;
        i11 = 0;
      } else {
        kk = yk->size[0];
        emlrtDynamicBoundsCheckFastR2012b(2, 1, kk, &nc_emlrtBCI,
          emlrtRootTLSGlobal);
        kk = 2;
        i10 = 3;
        i11 = yk->size[0];
        i12 = (int32_T)emlrtIntegerCheckFastR2012b(anew, &q_emlrtDCI,
          emlrtRootTLSGlobal);
        i11 = emlrtDynamicBoundsCheckFastR2012b(i12, 1, i11, &nc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      anew = 3.0 * uk_data[6];
      if (2.0 > anew) {
        i12 = 1;
        i13 = 1;
        i14 = 0;
      } else {
        i12 = yk->size[0];
        emlrtDynamicBoundsCheckFastR2012b(2, 1, i12, &mc_emlrtBCI,
          emlrtRootTLSGlobal);
        i12 = 2;
        i13 = 3;
        i14 = yk->size[0];
        i = (int32_T)emlrtIntegerCheckFastR2012b(anew, &p_emlrtDCI,
          emlrtRootTLSGlobal);
        i14 = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &mc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i = r20->size[0];
      r20->size[0] = div_s32_floor(i14 - i12, i13) + 1;
      emxEnsureCapacity((emxArray__common *)r20, i, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = div_s32_floor(i14 - i12, i13);
      for (i14 = 0; i14 <= loop_ub; i14++) {
        r20->data[i14] = (i12 + i13 * i14) - 1;
      }

      i12 = yk->size[1];
      i13 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i13, 1, i12, &lc_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
      i12 = yk->size[1];
      i13 = 1 + k;
      i12 = emlrtDynamicBoundsCheckFastR2012b(i13, 1, i12, &oc_emlrtBCI,
        emlrtRootTLSGlobal);
      i13 = r21->size[0];
      r21->size[0] = div_s32_floor(n - i8, i9) + 1;
      emxEnsureCapacity((emxArray__common *)r21, i13, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = div_s32_floor(n - i8, i9);
      for (n = 0; n <= loop_ub; n++) {
        r21->data[n] = yk->data[((i8 + i9 * n) + yk->size[0] * (i12 - 1)) - 1];
      }

      i8 = c_yk->size[0];
      c_yk->size[0] = div_s32_floor(i11 - kk, i10) + 1;
      emxEnsureCapacity((emxArray__common *)c_yk, i8, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = div_s32_floor(i11 - kk, i10);
      for (i8 = 0; i8 <= loop_ub; i8++) {
        c_yk->data[i8] = yk->data[(kk + i10 * i8) - 1];
      }

      minangle(r21, c_yk);
      emlrtPopRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
      iv31[0] = r20->size[0];
      emlrtSubAssignSizeCheckR2012b(iv31, 1, *(int32_T (*)[1])r21->size, 1,
        &qb_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r21->size[0];
      for (i8 = 0; i8 < loop_ub; i8++) {
        yk->data[r20->data[i8] + yk->size[0] * k] = r21->data[i8];
      }

      anew = 3.0 * uk_data[6];
      if (3.0 > anew) {
        i8 = 1;
        i9 = 1;
        n = 0;
      } else {
        i8 = yk->size[0];
        emlrtDynamicBoundsCheckFastR2012b(3, 1, i8, &kc_emlrtBCI,
          emlrtRootTLSGlobal);
        i8 = 3;
        i9 = 3;
        n = yk->size[0];
        kk = (int32_T)emlrtIntegerCheckFastR2012b(anew, &o_emlrtDCI,
          emlrtRootTLSGlobal);
        n = emlrtDynamicBoundsCheckFastR2012b(kk, 1, n, &kc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      anew = 3.0 * uk_data[6];
      if (3.0 > anew) {
        kk = 1;
        i10 = 1;
        i11 = 0;
      } else {
        kk = yk->size[0];
        emlrtDynamicBoundsCheckFastR2012b(3, 1, kk, &ic_emlrtBCI,
          emlrtRootTLSGlobal);
        kk = 3;
        i10 = 3;
        i11 = yk->size[0];
        i12 = (int32_T)emlrtIntegerCheckFastR2012b(anew, &n_emlrtDCI,
          emlrtRootTLSGlobal);
        i11 = emlrtDynamicBoundsCheckFastR2012b(i12, 1, i11, &ic_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      anew = 3.0 * uk_data[6];
      if (3.0 > anew) {
        i12 = 1;
        i13 = 1;
        i14 = 0;
      } else {
        i12 = yk->size[0];
        emlrtDynamicBoundsCheckFastR2012b(3, 1, i12, &hc_emlrtBCI,
          emlrtRootTLSGlobal);
        i12 = 3;
        i13 = 3;
        i14 = yk->size[0];
        i = (int32_T)emlrtIntegerCheckFastR2012b(anew, &m_emlrtDCI,
          emlrtRootTLSGlobal);
        i14 = emlrtDynamicBoundsCheckFastR2012b(i, 1, i14, &hc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i = r20->size[0];
      r20->size[0] = div_s32_floor(i14 - i12, i13) + 1;
      emxEnsureCapacity((emxArray__common *)r20, i, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = div_s32_floor(i14 - i12, i13);
      for (i14 = 0; i14 <= loop_ub; i14++) {
        r20->data[i14] = (i12 + i13 * i14) - 1;
      }

      i12 = yk->size[1];
      i13 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i13, 1, i12, &gc_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&vi_emlrtRSI, emlrtRootTLSGlobal);
      i12 = yk->size[1];
      i13 = 1 + k;
      i12 = emlrtDynamicBoundsCheckFastR2012b(i13, 1, i12, &jc_emlrtBCI,
        emlrtRootTLSGlobal);
      i13 = r21->size[0];
      r21->size[0] = div_s32_floor(n - i8, i9) + 1;
      emxEnsureCapacity((emxArray__common *)r21, i13, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = div_s32_floor(n - i8, i9);
      for (n = 0; n <= loop_ub; n++) {
        r21->data[n] = yk->data[((i8 + i9 * n) + yk->size[0] * (i12 - 1)) - 1];
      }

      i8 = b_yk->size[0];
      b_yk->size[0] = div_s32_floor(i11 - kk, i10) + 1;
      emxEnsureCapacity((emxArray__common *)b_yk, i8, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = div_s32_floor(i11 - kk, i10);
      for (i8 = 0; i8 <= loop_ub; i8++) {
        b_yk->data[i8] = yk->data[(kk + i10 * i8) - 1];
      }

      minangle(r21, b_yk);
      emlrtPopRtStackR2012b(&vi_emlrtRSI, emlrtRootTLSGlobal);
      iv32[0] = r20->size[0];
      emlrtSubAssignSizeCheckR2012b(iv32, 1, *(int32_T (*)[1])r21->size, 1,
        &pb_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r21->size[0];
      for (i8 = 0; i8 < loop_ub; i8++) {
        yk->data[r20->data[i8] + yk->size[0] * k] = r21->data[i8];
      }
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&c_yk);
  emxFree_real_T(&b_yk);
  emxFree_real_T(&r21);
  emxFree_int32_T(&r20);
  emxFree_real_T(&RKN_1);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (measurement_eq_10_state.c) */
