/*
 * measurement_eq_17_state.c
 *
 * Code generation for function 'measurement_eq_17_state'
 *
 * C source code generated on: Thu Dec  4 12:26:46 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_17_state.h"
#include "measurement_eq_17_state.h"
#include "vector2polar.h"
#include "minangle.h"
#include "ukf_update_17_state_emxutil.h"
#include "ukf_update_17_state_mexutil.h"
#include "sqrt.h"
#include "sum.h"
#include "power.h"
#include "attparsilentmex.h"
#include "ukf_update_17_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo ti_emlrtRSI = { 20, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo ui_emlrtRSI = { 26, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo vi_emlrtRSI = { 50, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo wi_emlrtRSI = { 55, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo xi_emlrtRSI = { 68, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo yi_emlrtRSI = { 79, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo aj_emlrtRSI = { 85, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo bj_emlrtRSI = { 86, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo cj_emlrtRSI = { 87, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo dj_emlrtRSI = { 88, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo ej_emlrtRSI = { 89, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo fj_emlrtRSI = { 68, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo gj_emlrtRSI = { 66, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo hj_emlrtRSI = { 61, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo ij_emlrtRSI = { 49, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtMCInfo v_emlrtMCI = { 49, 17, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtMCInfo w_emlrtMCI = { 67, 5, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtMCInfo x_emlrtMCI = { 66, 15, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRTEInfo cb_emlrtRTEI = { 1, 15, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRTEInfo db_emlrtRTEI = { 65, 1, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRTEInfo eb_emlrtRTEI = { 20, 5, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRTEInfo fb_emlrtRTEI = { 26, 5, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo ic_emlrtECI = { -1, 89, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 89, 35, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 89, 77, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo jc_emlrtECI = { -1, 88, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 88, 35, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 88, 77, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo kc_emlrtECI = { -1, 87, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 87, 28, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 87, 61, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo lc_emlrtECI = { -1, 86, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 86, 28, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 86, 61, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 85, 22, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 85, 49, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 80, 22, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 69, 22, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 58, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 55, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 50, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo mc_emlrtECI = { -1, 79, 36, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo nc_emlrtECI = { -1, 74, 24, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo be_emlrtBCI = { -1, -1, 74, 30, "RKN_2",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtRTEInfo xb_emlrtRTEI = { 72, 5, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo oc_emlrtECI = { -1, 68, 36, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo pc_emlrtECI = { -1, 63, 20, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 63, 26, "RKN_1",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtRTEInfo yb_emlrtRTEI = { 61, 5, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo qc_emlrtECI = { -1, 58, 41, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo rc_emlrtECI = { -1, 58, 30, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo sc_emlrtECI = { -1, 55, 127, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo tc_emlrtECI = { -1, 50, 127, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo de_emlrtBCI = { -1, -1, 46, 15, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 43, 19, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 41, 18, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 39, 26, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 37, 21, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo uc_emlrtECI = { -1, 26, 21, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo vc_emlrtECI = { -1, 20, 21, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 15, 6, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo u_emlrtDCI = { 15, 6, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 14, 6, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo wc_emlrtECI = { -1, 12, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 12, 9, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 20, 21, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo v_emlrtDCI = { 20, 21, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 26, 21, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo w_emlrtDCI = { 26, 21, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtDCInfo x_emlrtDCI = { 34, 12, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtDCInfo y_emlrtDCI = { 34, 12, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  4 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 37, 15, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 39, 20, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 41, 14, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 43, 14, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 50, 127, "nv",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 50, 8, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 55, 127, "nv",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 55, 8, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 58, 30, "nv",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 58, 41, "nv",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 58, 8, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 85, 39, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 85, 55, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 85, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 86, 13, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo ab_emlrtDCI = { 86, 13, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 86, 46, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo bb_emlrtDCI = { 86, 46, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 86, 67, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo cb_emlrtDCI = { 86, 67, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 87, 13, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo db_emlrtDCI = { 87, 13, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 87, 46, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo eb_emlrtDCI = { 87, 46, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 87, 67, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo fb_emlrtDCI = { 87, 67, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 88, 13, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo gb_emlrtDCI = { 88, 13, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 88, 55, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo hb_emlrtDCI = { 88, 55, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 88, 86, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo ib_emlrtDCI = { 88, 86, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 89, 13, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo jb_emlrtDCI = { 89, 13, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 89, 55, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo kb_emlrtDCI = { 89, 55, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 89, 86, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo lb_emlrtDCI = { 89, 86, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 79, 36, "nv",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo mb_emlrtDCI = { 79, 36, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 80, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo nb_emlrtDCI = { 80, 12, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 68, 36, "nv",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 69, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

/* Function Declarations */
static void b_eml_error(void);
static int32_T div_s32(int32_T numerator, int32_T denominator);

/* Function Definitions */
static void b_eml_error(void)
{
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &wb_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
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

void measurement_eq_17_state(const emxArray_real_T *xk, const emxArray_real_T
  *nk, const real_T uk_data[250], const int32_T uk_size[1], emxArray_real_T *yk)
{
  int32_T i6;
  int32_T i7;
  real_T y;
  real_T b_y;
  emxArray_real_T *RKN_1;
  emxArray_real_T *c_y;
  emxArray_real_T *d_y;
  real_T e_y;
  int32_T n;
  real_T anew;
  real_T apnd;
  boolean_T overflow;
  real_T ndbl;
  real_T cdiff;
  const mxArray *f_y;
  static const int32_T iv41[2] = { 1, 21 };

  const mxArray *m8;
  char_T cv30[21];
  int32_T i;
  static const char_T cv31[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T k;
  int32_T loop_ub;
  int32_T sz[2];
  emxArray_int32_T *r18;
  emxArray_int32_T *r19;
  int32_T unnamed_idx_0;
  const mxArray *g_y;
  emxArray_int32_T *r20;
  emxArray_int32_T *r21;
  emxArray_int32_T *r22;
  emxArray_int32_T *r23;
  const mxArray *h_y;
  static const int32_T iv42[2] = { 1, 40 };

  char_T cv32[40];
  static const char_T cv33[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  emxArray_int32_T *r24;
  emxArray_int32_T *r25;
  emxArray_int32_T *r26;
  int32_T exitg2;
  emxArray_real_T *RKN_2;
  const mxArray *i_y;
  static const int32_T iv43[2] = { 1, 21 };

  int32_T b_sz[2];
  emxArray_int32_T *r27;
  emxArray_int32_T *r28;
  const mxArray *j_y;
  emxArray_int32_T *r29;
  emxArray_int32_T *r30;
  emxArray_int32_T *r31;
  emxArray_int32_T *r32;
  const mxArray *k_y;
  static const int32_T iv44[2] = { 1, 40 };

  emxArray_int32_T *r33;
  emxArray_int32_T *r34;
  emxArray_int32_T *r35;
  int32_T exitg1;
  emxArray_int32_T *r36;
  emxArray_real_T *r37;
  emxArray_real_T *l_y;
  emxArray_real_T *b_yk;
  emxArray_real_T *c_yk;
  emxArray_real_T *d_yk;
  emxArray_real_T *e_yk;
  emxArray_real_T *r38;
  emxArray_real_T *r39;
  emxArray_real_T *r40;
  emxArray_real_T *r41;
  emxArray_real_T *r42;
  emxArray_real_T *r43;
  emxArray_real_T *r44;
  emxArray_real_T *r45;
  emxArray_real_T *r46;
  emxArray_real_T *r47;
  emxArray_real_T *r48;
  emxArray_real_T *r49;
  real_T b_xk[4];
  real_T Cin[9];
  real_T Cji[9];
  real_T c_xk[3];
  real_T d_xk[2];
  real_T x[2];
  real_T dv6[3];
  int32_T f_yk;
  real_T nk_data[250];
  real_T dv7[3];
  real_T b_Cji[9];
  real_T rij_j_hat[3];
  real_T dv8[3];
  real_T dv9[3];
  real_T tmp_data[3];
  real_T b_index[3];
  real_T dv10[3];
  real_T m_y;
  static const int8_T iv45[4] = { 2, 3, 5, 6 };

  real_T g_yk[4];
  real_T dv11[4];
  const mxArray *n_y;
  static const int32_T iv46[2] = { 1, 21 };

  uint32_T kd;
  const mxArray *o_y;
  static const int32_T iv47[2] = { 1, 21 };

  const mxArray *p_y;
  static const int32_T iv48[2] = { 1, 21 };

  int32_T iv49[1];
  const mxArray *q_y;
  static const int32_T iv50[2] = { 1, 21 };

  const mxArray *r_y;
  static const int32_T iv51[2] = { 1, 21 };

  const mxArray *s_y;
  static const int32_T iv52[2] = { 1, 21 };

  int32_T iv53[1];
  const mxArray *t_y;
  static const int32_T iv54[2] = { 1, 21 };

  const mxArray *u_y;
  static const int32_T iv55[2] = { 1, 21 };

  const mxArray *v_y;
  static const int32_T iv56[2] = { 1, 21 };

  int32_T iv57[1];
  const mxArray *w_y;
  static const int32_T iv58[2] = { 1, 21 };

  const mxArray *x_y;
  static const int32_T iv59[2] = { 1, 21 };

  const mxArray *y_y;
  static const int32_T iv60[2] = { 1, 21 };

  int32_T iv61[1];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /*  m1: # of features agent 1 sees */
  /*  m2: # of features agent 2 sees */
  /* xk: 17 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion */
  /* nk: 12+3*m1+3*m2 x 2N+1, error on range/bearing/azimuth for agent 1, then agent 2, then magnetometer errors for agent 1 then 2,  */
  /*        THEN feature range/bearing/azimuth errors FOR EACH FEATURE for agent 1, then same for agent 2  */
  /* uk[wi;ai;mag_i;# of i features;rkn;...;# of j features;rkn;...] : 9+2+3*m x 2N+1, m being total # of features from i and j  */
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &wc_emlrtECI,
    emlrtRootTLSGlobal);
  for (i6 = 0; i6 < 3; i6++) {
    i7 = 7 + i6;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &ke_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  emlrtDynamicBoundsCheckFastR2012b(10, 1, uk_size[0], &je_emlrtBCI,
    emlrtRootTLSGlobal);
  y = 3.0 * uk_data[9];
  b_y = (10.0 + 3.0 * uk_data[9]) + 1.0;
  i6 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &u_emlrtDCI, emlrtRootTLSGlobal);
  emlrtDynamicBoundsCheckFastR2012b(i6, 1, uk_size[0], &ie_emlrtBCI,
    emlrtRootTLSGlobal);

  /*  total # of features */
  /*  3 x m1 array of known inertial position of features seen by agent 1 */
  emxInit_real_T(&RKN_1, 2, &eb_emlrtRTEI, TRUE);
  emxInit_real_T(&c_y, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&d_y, 2, &cb_emlrtRTEI, TRUE);
  if (uk_data[9] > 0.0) {
    emlrtPushRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
    e_y = uk_data[9] * 3.0;
    emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    if (muDoubleScalarIsNaN(e_y)) {
      n = 0;
      anew = rtNaN;
      apnd = e_y;
      overflow = FALSE;
    } else if (e_y < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = e_y;
      overflow = FALSE;
    } else if (muDoubleScalarIsInf(e_y)) {
      n = 0;
      anew = rtNaN;
      apnd = e_y;
      overflow = !(1.0 == e_y);
    } else {
      anew = 1.0;
      ndbl = muDoubleScalarFloor((e_y - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - e_y;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
        ndbl++;
        apnd = e_y;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      overflow = (2.147483647E+9 < ndbl);
      n = (int32_T)ndbl - 1;
    }

    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    if (!overflow) {
    } else {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      f_y = NULL;
      m8 = mxCreateCharArray(2, iv41);
      for (i = 0; i < 21; i++) {
        cv30[i] = cv31[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
      emlrtAssign(&f_y, m8);
      error(message(f_y, &b_emlrtMCI), &c_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    i6 = d_y->size[0] * d_y->size[1];
    d_y->size[0] = 1;
    d_y->size[1] = n + 1;
    emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (n + 1 > 0) {
      d_y->data[0] = anew;
      if (n + 1 > 1) {
        d_y->data[n] = apnd;
        i6 = n + (n < 0);
        if (i6 >= 0) {
          i = (int32_T)((uint32_T)i6 >> 1);
        } else {
          i = ~(int32_T)((uint32_T)~i6 >> 1);
        }

        emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k < i; k++) {
          d_y->data[k] = anew + (real_T)k;
          d_y->data[n - k] = apnd - (real_T)k;
        }

        if (i << 1 == n) {
          d_y->data[i] = (anew + apnd) / 2.0;
        } else {
          d_y->data[i] = anew + (real_T)i;
          d_y->data[i + 1] = apnd - (real_T)i;
        }
      }
    }

    emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
    emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, d_y->size[1],
      &vc_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_y = 10.0 + d_y->data[i6];
      i7 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &v_emlrtDCI,
        emlrtRootTLSGlobal);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &le_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    sz[0] = 3;
    sz[1] = 1;
    i = 1;
    for (k = 0; k < 2; k++) {
      i *= sz[k];
    }

    if (i > 0) {
      emxInit_int32_T(&r18, 2, &cb_emlrtRTEI, TRUE);
      i6 = r18->size[0] * r18->size[1];
      r18->size[0] = 1;
      r18->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r18, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r18->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
      }

      emxInit_int32_T(&r19, 2, &cb_emlrtRTEI, TRUE);
      unnamed_idx_0 = r18->size[1];
      i = div_s32(unnamed_idx_0, i);
      i6 = r19->size[0] * r19->size[1];
      r19->size[0] = 1;
      r19->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r19, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      emxFree_int32_T(&r18);
      for (i6 = 0; i6 < loop_ub; i6++) {
        r19->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
      }

      unnamed_idx_0 = r19->size[1];
      emxFree_int32_T(&r19);
      if (i <= unnamed_idx_0) {
      } else {
        emlrtPushRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        g_y = NULL;
        m8 = mxCreateString("Assertion failed.");
        emlrtAssign(&g_y, m8);
        error(g_y, &v_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
      }

      sz[1] = i;
    } else {
      sz[1] = 0;
    }

    emxInit_int32_T(&r20, 2, &cb_emlrtRTEI, TRUE);
    i6 = r20->size[0] * r20->size[1];
    r20->size[0] = 1;
    r20->size[1] = d_y->size[1];
    emxEnsureCapacity((emxArray__common *)r20, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r20->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
    }

    i = r20->size[1];
    emxFree_int32_T(&r20);
    if (1 > i) {
      i = 1;
    }

    emxInit_int32_T(&r21, 2, &cb_emlrtRTEI, TRUE);
    i6 = r21->size[0] * r21->size[1];
    r21->size[0] = 1;
    r21->size[1] = d_y->size[1];
    emxEnsureCapacity((emxArray__common *)r21, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r21->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
    }

    unnamed_idx_0 = r21->size[1];
    emxFree_int32_T(&r21);
    if (unnamed_idx_0 < i) {
    } else {
      emxInit_int32_T(&r22, 2, &cb_emlrtRTEI, TRUE);
      i6 = r22->size[0] * r22->size[1];
      r22->size[0] = 1;
      r22->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r22, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r22->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
      }

      i = r22->size[1];
      emxFree_int32_T(&r22);
    }

    if (3 > i) {
      emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
    }

    if (sz[1] > i) {
      emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r23, 2, &cb_emlrtRTEI, TRUE);
    i6 = c_y->size[0] * c_y->size[1];
    c_y->size[0] = 3;
    c_y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)c_y, i6, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    i6 = r23->size[0] * r23->size[1];
    r23->size[0] = 1;
    r23->size[1] = d_y->size[1];
    emxEnsureCapacity((emxArray__common *)r23, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r23->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
    }

    unnamed_idx_0 = r23->size[1];
    emxFree_int32_T(&r23);
    if (unnamed_idx_0 == 3 * sz[1]) {
    } else {
      emlrtPushRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      h_y = NULL;
      m8 = mxCreateCharArray(2, iv42);
      for (i = 0; i < 40; i++) {
        cv32[i] = cv33[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 40, m8, cv32);
      emlrtAssign(&h_y, m8);
      error(message(h_y, &w_emlrtMCI), &x_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r24, 2, &cb_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&fj_emlrtRSI, emlrtRootTLSGlobal);
    i6 = r24->size[0] * r24->size[1];
    r24->size[0] = 1;
    r24->size[1] = d_y->size[1];
    emxEnsureCapacity((emxArray__common *)r24, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r24->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
    }

    unnamed_idx_0 = r24->size[1];
    emxFree_int32_T(&r24);
    if (1 > unnamed_idx_0) {
      overflow = FALSE;
    } else {
      emxInit_int32_T(&r25, 2, &cb_emlrtRTEI, TRUE);
      i6 = r25->size[0] * r25->size[1];
      r25->size[0] = 1;
      r25->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r25, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r25->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
      }

      unnamed_idx_0 = r25->size[1];
      overflow = (unnamed_idx_0 > 2147483646);
      emxFree_int32_T(&r25);
    }

    if (overflow) {
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&fj_emlrtRSI, emlrtRootTLSGlobal);
    k = 0;
    emxInit_int32_T(&r26, 2, &cb_emlrtRTEI, TRUE);
    do {
      exitg2 = 0;
      i6 = r26->size[0] * r26->size[1];
      r26->size[0] = 1;
      r26->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r26, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r26->data[i6] = (int32_T)(10.0 + d_y->data[i6]);
      }

      unnamed_idx_0 = r26->size[1];
      if (k + 1 <= unnamed_idx_0) {
        c_y->data[k] = uk_data[(int32_T)(10.0 + d_y->data[d_y->size[0] * k]) - 1];
        k++;
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    emxFree_int32_T(&r26);
    i6 = RKN_1->size[0] * RKN_1->size[1];
    RKN_1->size[0] = c_y->size[1];
    RKN_1->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)RKN_1, i6, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
    for (i6 = 0; i6 < 3; i6++) {
      loop_ub = c_y->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        RKN_1->data[i7 + RKN_1->size[0] * i6] = c_y->data[i6 + c_y->size[0] * i7];
      }
    }

    emlrtPopRtStackR2012b(&ti_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    i6 = RKN_1->size[0] * RKN_1->size[1];
    RKN_1->size[0] = 0;
    RKN_1->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)RKN_1, i6, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
  }

  /*  3 x m2 array of known inertial position of features seen by agent 2 */
  emxInit_real_T(&RKN_2, 2, &fb_emlrtRTEI, TRUE);
  if (uk_data[(int32_T)((10.0 + y) + 1.0) - 1] > 0.0) {
    emlrtPushRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
    e_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
    emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    if (muDoubleScalarIsNaN(e_y)) {
      n = 0;
      anew = rtNaN;
      apnd = e_y;
      overflow = FALSE;
    } else if (e_y < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = e_y;
      overflow = FALSE;
    } else if (muDoubleScalarIsInf(e_y)) {
      n = 0;
      anew = rtNaN;
      apnd = e_y;
      overflow = !(1.0 == e_y);
    } else {
      anew = 1.0;
      ndbl = muDoubleScalarFloor((e_y - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - e_y;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
        ndbl++;
        apnd = e_y;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      overflow = (2.147483647E+9 < ndbl);
      n = (int32_T)ndbl - 1;
    }

    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    if (!overflow) {
    } else {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      i_y = NULL;
      m8 = mxCreateCharArray(2, iv43);
      for (i = 0; i < 21; i++) {
        cv30[i] = cv31[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
      emlrtAssign(&i_y, m8);
      error(message(i_y, &b_emlrtMCI), &c_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    i6 = d_y->size[0] * d_y->size[1];
    d_y->size[0] = 1;
    d_y->size[1] = n + 1;
    emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (n + 1 > 0) {
      d_y->data[0] = anew;
      if (n + 1 > 1) {
        d_y->data[n] = apnd;
        i6 = n + (n < 0);
        if (i6 >= 0) {
          i = (int32_T)((uint32_T)i6 >> 1);
        } else {
          i = ~(int32_T)((uint32_T)~i6 >> 1);
        }

        emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k < i; k++) {
          d_y->data[k] = anew + (real_T)k;
          d_y->data[n - k] = apnd - (real_T)k;
        }

        if (i << 1 == n) {
          d_y->data[i] = (anew + apnd) / 2.0;
        } else {
          d_y->data[i] = anew + (real_T)i;
          d_y->data[i + 1] = apnd - (real_T)i;
        }
      }
    }

    emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
    emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, d_y->size[1],
      &uc_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
    e_y = 3.0 * uk_data[9];
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_y = (11.0 + e_y) + d_y->data[i6];
      i7 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &w_emlrtDCI,
        emlrtRootTLSGlobal);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &me_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    b_sz[0] = 3;
    b_sz[1] = 1;
    i = 1;
    for (k = 0; k < 2; k++) {
      i *= b_sz[k];
    }

    if (i > 0) {
      emxInit_int32_T(&r27, 2, &cb_emlrtRTEI, TRUE);
      i6 = r27->size[0] * r27->size[1];
      r27->size[0] = 1;
      r27->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r27, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r27->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
      }

      emxInit_int32_T(&r28, 2, &cb_emlrtRTEI, TRUE);
      unnamed_idx_0 = r27->size[1];
      i = div_s32(unnamed_idx_0, i);
      i6 = r28->size[0] * r28->size[1];
      r28->size[0] = 1;
      r28->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r28, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      emxFree_int32_T(&r27);
      for (i6 = 0; i6 < loop_ub; i6++) {
        r28->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
      }

      unnamed_idx_0 = r28->size[1];
      emxFree_int32_T(&r28);
      if (i <= unnamed_idx_0) {
      } else {
        emlrtPushRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        j_y = NULL;
        m8 = mxCreateString("Assertion failed.");
        emlrtAssign(&j_y, m8);
        error(j_y, &v_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
      }

      b_sz[1] = i;
    } else {
      b_sz[1] = 0;
    }

    emxInit_int32_T(&r29, 2, &cb_emlrtRTEI, TRUE);
    i6 = r29->size[0] * r29->size[1];
    r29->size[0] = 1;
    r29->size[1] = d_y->size[1];
    emxEnsureCapacity((emxArray__common *)r29, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r29->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
    }

    i = r29->size[1];
    emxFree_int32_T(&r29);
    if (1 > i) {
      i = 1;
    }

    emxInit_int32_T(&r30, 2, &cb_emlrtRTEI, TRUE);
    i6 = r30->size[0] * r30->size[1];
    r30->size[0] = 1;
    r30->size[1] = d_y->size[1];
    emxEnsureCapacity((emxArray__common *)r30, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r30->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
    }

    unnamed_idx_0 = r30->size[1];
    emxFree_int32_T(&r30);
    if (unnamed_idx_0 < i) {
    } else {
      emxInit_int32_T(&r31, 2, &cb_emlrtRTEI, TRUE);
      i6 = r31->size[0] * r31->size[1];
      r31->size[0] = 1;
      r31->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r31, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r31->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
      }

      i = r31->size[1];
      emxFree_int32_T(&r31);
    }

    if (3 > i) {
      emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
    }

    if (b_sz[1] > i) {
      emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r32, 2, &cb_emlrtRTEI, TRUE);
    i6 = c_y->size[0] * c_y->size[1];
    c_y->size[0] = 3;
    c_y->size[1] = b_sz[1];
    emxEnsureCapacity((emxArray__common *)c_y, i6, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    i6 = r32->size[0] * r32->size[1];
    r32->size[0] = 1;
    r32->size[1] = d_y->size[1];
    emxEnsureCapacity((emxArray__common *)r32, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r32->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
    }

    unnamed_idx_0 = r32->size[1];
    emxFree_int32_T(&r32);
    if (unnamed_idx_0 == 3 * b_sz[1]) {
    } else {
      emlrtPushRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      k_y = NULL;
      m8 = mxCreateCharArray(2, iv44);
      for (i = 0; i < 40; i++) {
        cv32[i] = cv33[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 40, m8, cv32);
      emlrtAssign(&k_y, m8);
      error(message(k_y, &w_emlrtMCI), &x_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r33, 2, &cb_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&fj_emlrtRSI, emlrtRootTLSGlobal);
    i6 = r33->size[0] * r33->size[1];
    r33->size[0] = 1;
    r33->size[1] = d_y->size[1];
    emxEnsureCapacity((emxArray__common *)r33, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = d_y->size[0] * d_y->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r33->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
    }

    unnamed_idx_0 = r33->size[1];
    emxFree_int32_T(&r33);
    if (1 > unnamed_idx_0) {
      overflow = FALSE;
    } else {
      emxInit_int32_T(&r34, 2, &cb_emlrtRTEI, TRUE);
      i6 = r34->size[0] * r34->size[1];
      r34->size[0] = 1;
      r34->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r34, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r34->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
      }

      unnamed_idx_0 = r34->size[1];
      overflow = (unnamed_idx_0 > 2147483646);
      emxFree_int32_T(&r34);
    }

    if (overflow) {
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&fj_emlrtRSI, emlrtRootTLSGlobal);
    k = 0;
    emxInit_int32_T(&r35, 2, &cb_emlrtRTEI, TRUE);
    do {
      exitg1 = 0;
      i6 = r35->size[0] * r35->size[1];
      r35->size[0] = 1;
      r35->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r35, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r35->data[i6] = (int32_T)((11.0 + e_y) + d_y->data[i6]);
      }

      unnamed_idx_0 = r35->size[1];
      if (k + 1 <= unnamed_idx_0) {
        c_y->data[k] = uk_data[(int32_T)((11.0 + e_y) + d_y->data[d_y->size[0] *
          k]) - 1];
        k++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_int32_T(&r35);
    i6 = RKN_2->size[0] * RKN_2->size[1];
    RKN_2->size[0] = c_y->size[1];
    RKN_2->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)RKN_2, i6, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
    for (i6 = 0; i6 < 3; i6++) {
      loop_ub = c_y->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        RKN_2->data[i7 + RKN_2->size[0] * i6] = c_y->data[i6 + c_y->size[0] * i7];
      }
    }

    emlrtPopRtStackR2012b(&ui_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    i6 = RKN_2->size[0] * RKN_2->size[1];
    RKN_2->size[0] = 0;
    RKN_2->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)RKN_2, i6, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
  }

  emxFree_real_T(&c_y);
  e_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + y) + 1.0) - 1]);
  b_y = 9.0 + e_y;
  b_y = emlrtNonNegativeCheckFastR2012b(b_y, &y_emlrtDCI, emlrtRootTLSGlobal);
  emlrtIntegerCheckFastR2012b(b_y, &x_emlrtDCI, emlrtRootTLSGlobal);
  i6 = yk->size[0] * yk->size[1];
  yk->size[0] = (int32_T)(9.0 + e_y);
  emxEnsureCapacity((emxArray__common *)yk, i6, (int32_T)sizeof(real_T),
                    &cb_emlrtRTEI);
  b_y = 9.0 + e_y;
  b_y = emlrtNonNegativeCheckFastR2012b(b_y, &y_emlrtDCI, emlrtRootTLSGlobal);
  emlrtIntegerCheckFastR2012b(b_y, &x_emlrtDCI, emlrtRootTLSGlobal);
  i = xk->size[1];
  i6 = yk->size[0] * yk->size[1];
  yk->size[1] = i;
  emxEnsureCapacity((emxArray__common *)yk, i6, (int32_T)sizeof(real_T),
                    &cb_emlrtRTEI);
  b_y = 9.0 + e_y;
  b_y = emlrtNonNegativeCheckFastR2012b(b_y, &y_emlrtDCI, emlrtRootTLSGlobal);
  loop_ub = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &x_emlrtDCI,
    emlrtRootTLSGlobal) * xk->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    yk->data[i6] = 0.0;
  }

  k = 0;
  b_emxInit_int32_T(&r36, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r37, 1, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&l_y, 2, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&b_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&c_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&d_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&e_yk, 1, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r38, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r39, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r40, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r41, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r42, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r43, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r44, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r45, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r46, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r47, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r48, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r49, 2, &cb_emlrtRTEI, TRUE);
  while (k <= xk->size[1] - 1) {
    /*  i to j frame transform */
    for (i6 = 0; i6 < 4; i6++) {
      i7 = xk->size[0];
      unnamed_idx_0 = 14 + i6;
      emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7, &ne_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &he_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  est relative position in my (i) frame */
    for (i6 = 0; i6 < 3; i6++) {
      i7 = xk->size[0];
      unnamed_idx_0 = 11 + i6;
      emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7, &oe_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ge_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  estimated my inertial position */
    for (i6 = 0; i6 < 3; i6++) {
      i7 = xk->size[0];
      unnamed_idx_0 = 1 + i6;
      emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7, &pe_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &fe_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  my estimated inertial attitude */
    for (i6 = 0; i6 < 4; i6++) {
      i7 = xk->size[0];
      unnamed_idx_0 = 7 + i6;
      emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7, &qe_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ee_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i6 = 0; i6 < 4; i6++) {
      b_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 6];
    }

    attparsilentmex(b_xk, Cin);
    i6 = nk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &de_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i6 = 0; i6 < 4; i6++) {
      b_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 13];
    }

    attparsilentmex(b_xk, Cji);

    /*  expected range/bearing/azimuth from agent i's measurement */
    i6 = nk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &tc_emlrtECI,
      emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&vi_emlrtRSI, emlrtRootTLSGlobal);
    for (i6 = 0; i6 < 3; i6++) {
      c_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 10];
    }

    for (i6 = 0; i6 < 2; i6++) {
      d_xk[i6] = c_xk[i6];
    }

    b_power(d_xk, x);
    apnd = x[0] + x[1];
    b_sqrt(&apnd);
    for (i6 = 0; i6 < 3; i6++) {
      c_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 10];
    }

    power(c_xk, dv6);
    b_y = b_sum(dv6);
    b_sqrt(&b_y);
    i6 = nk->size[0];
    f_yk = yk->size[0];
    i = yk->size[1];
    i7 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &ae_emlrtBCI, emlrtRootTLSGlobal);
    loop_ub = nk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      nk_data[i7] = nk->data[i7 + nk->size[0] * k];
    }

    dv7[0] = b_y;
    dv7[1] = muDoubleScalarAtan2(xk->data[xk->size[0] * k + 11], xk->data[10 +
      xk->size[0] * k]);
    dv7[2] = muDoubleScalarAtan2(xk->data[xk->size[0] * k + 12], apnd);
    for (i7 = 0; i7 < 3; i7++) {
      unnamed_idx_0 = 1 + i7;
      i = 1 + i7;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, f_yk, &se_emlrtBCI,
                 emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = dv7[i7] +
        nk_data[emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i6,
        &re_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    emlrtPopRtStackR2012b(&vi_emlrtRSI, emlrtRootTLSGlobal);

    /*  expectated relative vector from agent j's measurement */
    for (i6 = 0; i6 < 3; i6++) {
      for (i7 = 0; i7 < 3; i7++) {
        b_Cji[i7 + 3 * i6] = -Cji[i7 + 3 * i6];
      }
    }

    for (i6 = 0; i6 < 3; i6++) {
      c_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 10];
    }

    for (i6 = 0; i6 < 3; i6++) {
      rij_j_hat[i6] = 0.0;
      for (i7 = 0; i7 < 3; i7++) {
        rij_j_hat[i6] += b_Cji[i6 + 3 * i7] * c_xk[i7];
      }
    }

    /*  expected range/bearing/azimuth from agent j's measurement */
    i6 = nk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &sc_emlrtECI,
      emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&wi_emlrtRSI, emlrtRootTLSGlobal);
    b_power(*(real_T (*)[2])&rij_j_hat[0], x);
    apnd = x[0] + x[1];
    b_sqrt(&apnd);
    power(rij_j_hat, dv8);
    b_y = b_sum(dv8);
    b_sqrt(&b_y);
    i6 = nk->size[0];
    f_yk = yk->size[0];
    i = yk->size[1];
    i7 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &yd_emlrtBCI, emlrtRootTLSGlobal);
    loop_ub = nk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      nk_data[i7] = nk->data[i7 + nk->size[0] * k];
    }

    dv9[0] = b_y;
    dv9[1] = muDoubleScalarAtan2(rij_j_hat[1], rij_j_hat[0]);
    dv9[2] = muDoubleScalarAtan2(rij_j_hat[2], apnd);
    for (i7 = 0; i7 < 3; i7++) {
      unnamed_idx_0 = 4 + i7;
      i = 4 + i7;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, f_yk, &ue_emlrtBCI,
                 emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = dv9[i7] +
        nk_data[emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i6,
        &te_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    emlrtPopRtStackR2012b(&wi_emlrtRSI, emlrtRootTLSGlobal);

    /*  expected magnetometer measurement */
    i6 = nk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &rc_emlrtECI,
      emlrtRootTLSGlobal);
    i6 = nk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &qc_emlrtECI,
      emlrtRootTLSGlobal);
    i6 = nk->size[0];
    loop_ub = nk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      nk_data[i7] = nk->data[i7 + nk->size[0] * k];
    }

    for (i7 = 0; i7 < 3; i7++) {
      unnamed_idx_0 = 7 + i7;
      rij_j_hat[i7] = uk_data[i7 + 6] +
        nk_data[emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i6,
        &ve_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    i6 = nk->size[0];
    f_yk = yk->size[0];
    i = yk->size[1];
    i7 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &xd_emlrtBCI, emlrtRootTLSGlobal);
    loop_ub = nk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      nk_data[i7] = nk->data[i7 + nk->size[0] * k];
    }

    for (i7 = 0; i7 < 3; i7++) {
      b_y = 0.0;
      for (unnamed_idx_0 = 0; unnamed_idx_0 < 3; unnamed_idx_0++) {
        b_y += Cji[i7 + 3 * unnamed_idx_0] * rij_j_hat[unnamed_idx_0];
      }

      unnamed_idx_0 = 10 + i7;
      i = 7 + i7;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, f_yk, &xe_emlrtBCI,
                 emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = b_y -
        nk_data[emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i6,
        &we_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    /*  feature measurements */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, uk_data[9], mxDOUBLE_CLASS, (int32_T)
      uk_data[9], &yb_emlrtRTEI, emlrtRootTLSGlobal);
    n = 0;
    while (n <= (int32_T)uk_data[9] - 1) {
      /*  get the i frame vector to the feature */
      loop_ub = RKN_1->size[1];
      i6 = RKN_1->size[0];
      i7 = (int32_T)(1.0 + (real_T)n);
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ce_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i7 = 0; i7 < loop_ub; i7++) {
        tmp_data[i7] = RKN_1->data[(i6 + RKN_1->size[0] * i7) - 1];
      }

      emlrtSizeEqCheck1DFastR2012b(loop_ub, 3, &pc_emlrtECI, emlrtRootTLSGlobal);

      /*  the index for now */
      e_y = ((1.0 + (real_T)n) - 1.0) * 3.0;
      for (i6 = 0; i6 < 3; i6++) {
        b_index[i6] = e_y + (1.0 + (real_T)i6);
      }

      /*  compute range/bearing/declination */
      /* y_kk = [sqrt(sum(rki.^2));atan2(rki(2),rki(1));atan2(rki(3),sqrt(sum(rki(1:2).^2)))] + nv(12 + index); */
      i6 = nk->size[0];
      emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &oc_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&xi_emlrtRSI, emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        dv10[i6] = tmp_data[i6] - xk->data[i6 + xk->size[0] * k];
      }

      for (i6 = 0; i6 < 3; i6++) {
        rij_j_hat[i6] = 0.0;
        for (i7 = 0; i7 < 3; i7++) {
          rij_j_hat[i6] += Cin[i6 + 3 * i7] * dv10[i7];
        }
      }

      vector2polar(rij_j_hat, dv10);
      i6 = nk->size[0];
      loop_ub = nk->size[0];
      for (i7 = 0; i7 < loop_ub; i7++) {
        nk_data[i7] = nk->data[i7 + nk->size[0] * k];
      }

      for (i7 = 0; i7 < 3; i7++) {
        unnamed_idx_0 = (int32_T)(12.0 + b_index[i7]);
        rij_j_hat[i7] = dv10[i7] + nk_data[emlrtDynamicBoundsCheckFastR2012b
          (unnamed_idx_0, 1, i6, &qf_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      emlrtPopRtStackR2012b(&xi_emlrtRSI, emlrtRootTLSGlobal);
      f_yk = yk->size[0];
      i = yk->size[1];
      i6 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &wd_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        i7 = (int32_T)(9.0 + b_index[i6]);
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i7, 1, f_yk, &rf_emlrtBCI,
                   emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = rij_j_hat[i6];
      }

      n++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, uk_data[(int32_T)((10.0 + y) + 1.0)
      - 1], mxDOUBLE_CLASS, (int32_T)uk_data[(int32_T)((10.0 + 3.0 * uk_data[9])
      + 1.0) - 1], &xb_emlrtRTEI, emlrtRootTLSGlobal);
    n = 0;
    while (n <= (int32_T)uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]
           - 1) {
      /*  get the j frame vector to the feature */
      loop_ub = RKN_2->size[1];
      i6 = RKN_2->size[0];
      i7 = (int32_T)(1.0 + (real_T)n);
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &be_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i7 = 0; i7 < loop_ub; i7++) {
        tmp_data[i7] = RKN_2->data[(i6 + RKN_2->size[0] * i7) - 1];
      }

      emlrtSizeEqCheck1DFastR2012b(loop_ub, 3, &nc_emlrtECI, emlrtRootTLSGlobal);

      /*  the index for now */
      e_y = ((1.0 + (real_T)n) - 1.0) * 3.0;
      m_y = uk_data[9] * 3.0;
      for (i6 = 0; i6 < 3; i6++) {
        b_index[i6] = (e_y + (1.0 + (real_T)i6)) + m_y;
      }

      /*  compute range/bearing/declination */
      /* y_kk = [sqrt(sum(rkj.^2));atan2(rkj(2),rkj(1));atan2(rkj(3),sqrt(sum(rkj(1:2).^2)))] + nv(12 + index); */
      i6 = nk->size[0];
      emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &mc_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&yi_emlrtRSI, emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        c_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 10];
      }

      for (i6 = 0; i6 < 3; i6++) {
        for (i7 = 0; i7 < 3; i7++) {
          b_Cji[i6 + 3 * i7] = 0.0;
          for (unnamed_idx_0 = 0; unnamed_idx_0 < 3; unnamed_idx_0++) {
            b_Cji[i6 + 3 * i7] += Cji[i6 + 3 * unnamed_idx_0] *
              Cin[unnamed_idx_0 + 3 * i7];
          }
        }
      }

      for (i6 = 0; i6 < 3; i6++) {
        b_y = 0.0;
        for (i7 = 0; i7 < 3; i7++) {
          b_y += Cin[i7 + 3 * i6] * c_xk[i7];
        }

        dv10[i6] = (tmp_data[i6] - b_y) - xk->data[i6 + xk->size[0] * k];
      }

      for (i6 = 0; i6 < 3; i6++) {
        rij_j_hat[i6] = 0.0;
        for (i7 = 0; i7 < 3; i7++) {
          rij_j_hat[i6] += b_Cji[i6 + 3 * i7] * dv10[i7];
        }
      }

      vector2polar(rij_j_hat, dv10);
      i6 = nk->size[0];
      loop_ub = nk->size[0];
      for (i7 = 0; i7 < loop_ub; i7++) {
        nk_data[i7] = nk->data[i7 + nk->size[0] * k];
      }

      for (i7 = 0; i7 < 3; i7++) {
        b_y = 12.0 + b_index[i7];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &mb_emlrtDCI,
          emlrtRootTLSGlobal);
        rij_j_hat[i7] = dv10[i7] + nk_data[emlrtDynamicBoundsCheckFastR2012b
          (unnamed_idx_0, 1, i6, &of_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      emlrtPopRtStackR2012b(&yi_emlrtRSI, emlrtRootTLSGlobal);
      f_yk = yk->size[0];
      i = yk->size[1];
      i6 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &vd_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        b_y = 9.0 + b_index[i6];
        i7 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &nb_emlrtDCI,
          emlrtRootTLSGlobal);
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i7, 1, f_yk, &pf_emlrtBCI,
                   emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = rij_j_hat[i6];
      }

      n++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    if (1 + k > 1) {
      /*  minimize all angle differences */
      emlrtPushRtStackR2012b(&aj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ud_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i7 = 0; i7 < 4; i7++) {
        unnamed_idx_0 = yk->size[0];
        i = iv45[i7];
        b_xk[i7] = yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1,
          unnamed_idx_0, &ye_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * (i6 -
          1)) - 1];
      }

      for (i6 = 0; i6 < 4; i6++) {
        i7 = yk->size[0];
        unnamed_idx_0 = iv45[i6];
        g_yk[i6] = yk->data[emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1,
          i7, &af_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      minangle(b_xk, g_yk, dv11);
      f_yk = yk->size[0];
      i = yk->size[1];
      i6 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &td_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 4; i6++) {
        i7 = iv45[i6];
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i7, 1, f_yk, &bf_emlrtBCI,
                   emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = dv11[i6];
      }

      emlrtPopRtStackR2012b(&aj_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&bj_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (e_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == e_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((e_y - 2.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (2.0 + m_y) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 2.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        n_y = NULL;
        m8 = mxCreateCharArray(2, iv46);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&n_y, m8);
        error(message(n_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        d_y->data[0] = anew;
        if (n + 1 > 1) {
          d_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            d_y->data[unnamed_idx_0] = anew + (real_T)kd;
            d_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            d_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            d_y->data[i] = anew + (real_T)kd;
            d_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r38->size[0] * r38->size[1];
      r38->size[0] = 1;
      r38->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r38, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = 9.0 + d_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &ab_emlrtDCI,
          emlrtRootTLSGlobal);
        r38->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &cf_emlrtBCI, emlrtRootTLSGlobal);
      }

      i6 = r36->size[0];
      r36->size[0] = r38->size[1];
      emxEnsureCapacity((emxArray__common *)r36, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r38->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r36->data[i6] = (int32_T)r38->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&bj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &rd_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&bj_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (e_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == e_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((e_y - 2.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (2.0 + m_y) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 2.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        o_y = NULL;
        m8 = mxCreateCharArray(2, iv47);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&o_y, m8);
        error(message(o_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        d_y->data[0] = anew;
        if (n + 1 > 1) {
          d_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            d_y->data[unnamed_idx_0] = anew + (real_T)kd;
            d_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            d_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            d_y->data[i] = anew + (real_T)kd;
            d_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (e_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == e_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((e_y - 2.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (2.0 + m_y) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 2.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        p_y = NULL;
        m8 = mxCreateCharArray(2, iv48);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&p_y, m8);
        error(message(p_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = l_y->size[0] * l_y->size[1];
      l_y->size[0] = 1;
      l_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)l_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        l_y->data[0] = anew;
        if (n + 1 > 1) {
          l_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            l_y->data[unnamed_idx_0] = anew + (real_T)kd;
            l_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            l_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            l_y->data[i] = anew + (real_T)kd;
            l_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r39->size[0] * r39->size[1];
      r39->size[0] = 1;
      r39->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r39, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = 9.0 + d_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &bb_emlrtDCI,
          emlrtRootTLSGlobal);
        r39->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &df_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r39->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &sd_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r37->size[0];
      r37->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r37, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r37->data[i7] = yk->data[((int32_T)r39->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r40->size[0] * r40->size[1];
      r40->size[0] = 1;
      r40->size[1] = l_y->size[1];
      emxEnsureCapacity((emxArray__common *)r40, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = l_y->size[0] * l_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = 9.0 + l_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &cb_emlrtDCI,
          emlrtRootTLSGlobal);
        r40->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &ef_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r40->size[1];
      i6 = e_yk->size[0];
      e_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)e_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        e_yk->data[i6] = yk->data[(int32_T)r40->data[i6] - 1];
      }

      c_minangle(r37, e_yk);
      emlrtPopRtStackR2012b(&bj_emlrtRSI, emlrtRootTLSGlobal);
      iv49[0] = r36->size[0];
      emlrtSubAssignSizeCheckR2012b(iv49, 1, *(int32_T (*)[1])r37->size, 1,
        &lc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r37->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r36->data[i6] + yk->size[0] * k] = r37->data[i6];
      }

      emlrtPushRtStackR2012b(&cj_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (e_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == e_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((e_y - 3.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (3.0 + m_y) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 3.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        q_y = NULL;
        m8 = mxCreateCharArray(2, iv50);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&q_y, m8);
        error(message(q_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        d_y->data[0] = anew;
        if (n + 1 > 1) {
          d_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            d_y->data[unnamed_idx_0] = anew + (real_T)kd;
            d_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            d_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            d_y->data[i] = anew + (real_T)kd;
            d_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r41->size[0] * r41->size[1];
      r41->size[0] = 1;
      r41->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r41, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = 9.0 + d_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &db_emlrtDCI,
          emlrtRootTLSGlobal);
        r41->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &ff_emlrtBCI, emlrtRootTLSGlobal);
      }

      i6 = r36->size[0];
      r36->size[0] = r41->size[1];
      emxEnsureCapacity((emxArray__common *)r36, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r41->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r36->data[i6] = (int32_T)r41->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&cj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &pd_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&cj_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (e_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == e_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((e_y - 3.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (3.0 + m_y) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 3.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        r_y = NULL;
        m8 = mxCreateCharArray(2, iv51);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&r_y, m8);
        error(message(r_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        d_y->data[0] = anew;
        if (n + 1 > 1) {
          d_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            d_y->data[unnamed_idx_0] = anew + (real_T)kd;
            d_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            d_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            d_y->data[i] = anew + (real_T)kd;
            d_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (e_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(e_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == e_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((e_y - 3.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (3.0 + m_y) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 3.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        s_y = NULL;
        m8 = mxCreateCharArray(2, iv52);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&s_y, m8);
        error(message(s_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = l_y->size[0] * l_y->size[1];
      l_y->size[0] = 1;
      l_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)l_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        l_y->data[0] = anew;
        if (n + 1 > 1) {
          l_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            l_y->data[unnamed_idx_0] = anew + (real_T)kd;
            l_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            l_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            l_y->data[i] = anew + (real_T)kd;
            l_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r42->size[0] * r42->size[1];
      r42->size[0] = 1;
      r42->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r42, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = 9.0 + d_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &eb_emlrtDCI,
          emlrtRootTLSGlobal);
        r42->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &gf_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r42->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &qd_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r37->size[0];
      r37->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r37, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r37->data[i7] = yk->data[((int32_T)r42->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r43->size[0] * r43->size[1];
      r43->size[0] = 1;
      r43->size[1] = l_y->size[1];
      emxEnsureCapacity((emxArray__common *)r43, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = l_y->size[0] * l_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = 9.0 + l_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &fb_emlrtDCI,
          emlrtRootTLSGlobal);
        r43->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &hf_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r43->size[1];
      i6 = d_yk->size[0];
      d_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)d_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        d_yk->data[i6] = yk->data[(int32_T)r43->data[i6] - 1];
      }

      c_minangle(r37, d_yk);
      emlrtPopRtStackR2012b(&cj_emlrtRSI, emlrtRootTLSGlobal);
      iv53[0] = r36->size[0];
      emlrtSubAssignSizeCheckR2012b(iv53, 1, *(int32_T (*)[1])r37->size, 1,
        &kc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r37->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r36->data[i6] + yk->size[0] * k] = r37->data[i6];
      }

      emlrtPushRtStackR2012b(&dj_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (m_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == m_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((m_y - 2.0) / 3.0 + 0.5);
        b_y = ndbl * 3.0;
        cdiff = (2.0 + b_y) - m_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * m_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          m_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          m_y = 2.0 + b_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        t_y = NULL;
        m8 = mxCreateCharArray(2, iv54);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&t_y, m8);
        error(message(t_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        d_y->data[0] = anew;
        if (n + 1 > 1) {
          d_y->data[n] = m_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            d_y->data[unnamed_idx_0] = anew + (real_T)kd;
            d_y->data[n - unnamed_idx_0] = m_y - (real_T)kd;
          }

          if (i << 1 == n) {
            d_y->data[i] = (anew + m_y) / 2.0;
          } else {
            kd = i * 3U;
            d_y->data[i] = anew + (real_T)kd;
            d_y->data[i + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r44->size[0] * r44->size[1];
      r44->size[0] = 1;
      r44->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r44, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = (9.0 + e_y) + d_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &gb_emlrtDCI,
          emlrtRootTLSGlobal);
        r44->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &if_emlrtBCI, emlrtRootTLSGlobal);
      }

      i6 = r36->size[0];
      r36->size[0] = r44->size[1];
      emxEnsureCapacity((emxArray__common *)r36, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r44->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r36->data[i6] = (int32_T)r44->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&dj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &nd_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&dj_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (m_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == m_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((m_y - 2.0) / 3.0 + 0.5);
        b_y = ndbl * 3.0;
        cdiff = (2.0 + b_y) - m_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * m_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          m_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          m_y = 2.0 + b_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        u_y = NULL;
        m8 = mxCreateCharArray(2, iv55);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&u_y, m8);
        error(message(u_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        d_y->data[0] = anew;
        if (n + 1 > 1) {
          d_y->data[n] = m_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            d_y->data[unnamed_idx_0] = anew + (real_T)kd;
            d_y->data[n - unnamed_idx_0] = m_y - (real_T)kd;
          }

          if (i << 1 == n) {
            d_y->data[i] = (anew + m_y) / 2.0;
          } else {
            kd = i * 3U;
            d_y->data[i] = anew + (real_T)kd;
            d_y->data[i + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      b_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(b_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (b_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(b_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == b_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((b_y - 2.0) / 3.0 + 0.5);
        apnd = ndbl * 3.0;
        cdiff = (2.0 + apnd) - b_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * b_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          b_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          b_y = 2.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        v_y = NULL;
        m8 = mxCreateCharArray(2, iv56);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&v_y, m8);
        error(message(v_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = l_y->size[0] * l_y->size[1];
      l_y->size[0] = 1;
      l_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)l_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        l_y->data[0] = anew;
        if (n + 1 > 1) {
          l_y->data[n] = b_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            l_y->data[unnamed_idx_0] = anew + (real_T)kd;
            l_y->data[n - unnamed_idx_0] = b_y - (real_T)kd;
          }

          if (i << 1 == n) {
            l_y->data[i] = (anew + b_y) / 2.0;
          } else {
            kd = i * 3U;
            l_y->data[i] = anew + (real_T)kd;
            l_y->data[i + 1] = b_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r45->size[0] * r45->size[1];
      r45->size[0] = 1;
      r45->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r45, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = (9.0 + e_y) + d_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &hb_emlrtDCI,
          emlrtRootTLSGlobal);
        r45->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &jf_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r45->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &od_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r37->size[0];
      r37->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r37, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r37->data[i7] = yk->data[((int32_T)r45->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r46->size[0] * r46->size[1];
      r46->size[0] = 1;
      r46->size[1] = l_y->size[1];
      emxEnsureCapacity((emxArray__common *)r46, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = l_y->size[0] * l_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = (9.0 + m_y) + l_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &ib_emlrtDCI,
          emlrtRootTLSGlobal);
        r46->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &kf_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r46->size[1];
      i6 = c_yk->size[0];
      c_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)c_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        c_yk->data[i6] = yk->data[(int32_T)r46->data[i6] - 1];
      }

      c_minangle(r37, c_yk);
      emlrtPopRtStackR2012b(&dj_emlrtRSI, emlrtRootTLSGlobal);
      iv57[0] = r36->size[0];
      emlrtSubAssignSizeCheckR2012b(iv57, 1, *(int32_T (*)[1])r37->size, 1,
        &jc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r37->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r36->data[i6] + yk->size[0] * k] = r37->data[i6];
      }

      emlrtPushRtStackR2012b(&ej_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (m_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == m_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((m_y - 3.0) / 3.0 + 0.5);
        b_y = ndbl * 3.0;
        cdiff = (3.0 + b_y) - m_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * m_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          m_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          m_y = 3.0 + b_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        w_y = NULL;
        m8 = mxCreateCharArray(2, iv58);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&w_y, m8);
        error(message(w_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        d_y->data[0] = anew;
        if (n + 1 > 1) {
          d_y->data[n] = m_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            d_y->data[unnamed_idx_0] = anew + (real_T)kd;
            d_y->data[n - unnamed_idx_0] = m_y - (real_T)kd;
          }

          if (i << 1 == n) {
            d_y->data[i] = (anew + m_y) / 2.0;
          } else {
            kd = i * 3U;
            d_y->data[i] = anew + (real_T)kd;
            d_y->data[i + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r47->size[0] * r47->size[1];
      r47->size[0] = 1;
      r47->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r47, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = (9.0 + e_y) + d_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &jb_emlrtDCI,
          emlrtRootTLSGlobal);
        r47->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &lf_emlrtBCI, emlrtRootTLSGlobal);
      }

      i6 = r36->size[0];
      r36->size[0] = r47->size[1];
      emxEnsureCapacity((emxArray__common *)r36, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r47->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r36->data[i6] = (int32_T)r47->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&ej_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ld_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ej_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (m_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == m_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((m_y - 3.0) / 3.0 + 0.5);
        b_y = ndbl * 3.0;
        cdiff = (3.0 + b_y) - m_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * m_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          m_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          m_y = 3.0 + b_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        x_y = NULL;
        m8 = mxCreateCharArray(2, iv59);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&x_y, m8);
        error(message(x_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = d_y->size[0] * d_y->size[1];
      d_y->size[0] = 1;
      d_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)d_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        d_y->data[0] = anew;
        if (n + 1 > 1) {
          d_y->data[n] = m_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            d_y->data[unnamed_idx_0] = anew + (real_T)kd;
            d_y->data[n - unnamed_idx_0] = m_y - (real_T)kd;
          }

          if (i << 1 == n) {
            d_y->data[i] = (anew + m_y) / 2.0;
          } else {
            kd = i * 3U;
            d_y->data[i] = anew + (real_T)kd;
            d_y->data[i + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      b_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(b_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (b_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(b_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == b_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((b_y - 3.0) / 3.0 + 0.5);
        apnd = ndbl * 3.0;
        cdiff = (3.0 + apnd) - b_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * b_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          b_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          b_y = 3.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        y_y = NULL;
        m8 = mxCreateCharArray(2, iv60);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&y_y, m8);
        error(message(y_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      i6 = l_y->size[0] * l_y->size[1];
      l_y->size[0] = 1;
      l_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)l_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        l_y->data[0] = anew;
        if (n + 1 > 1) {
          l_y->data[n] = b_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            l_y->data[unnamed_idx_0] = anew + (real_T)kd;
            l_y->data[n - unnamed_idx_0] = b_y - (real_T)kd;
          }

          if (i << 1 == n) {
            l_y->data[i] = (anew + b_y) / 2.0;
          } else {
            kd = i * 3U;
            l_y->data[i] = anew + (real_T)kd;
            l_y->data[i + 1] = b_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r48->size[0] * r48->size[1];
      r48->size[0] = 1;
      r48->size[1] = d_y->size[1];
      emxEnsureCapacity((emxArray__common *)r48, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = d_y->size[0] * d_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = (9.0 + e_y) + d_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &kb_emlrtDCI,
          emlrtRootTLSGlobal);
        r48->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &mf_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r48->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &md_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r37->size[0];
      r37->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r37, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r37->data[i7] = yk->data[((int32_T)r48->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r49->size[0] * r49->size[1];
      r49->size[0] = 1;
      r49->size[1] = l_y->size[1];
      emxEnsureCapacity((emxArray__common *)r49, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = l_y->size[0] * l_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        b_y = (9.0 + m_y) + l_y->data[i6];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &lb_emlrtDCI,
          emlrtRootTLSGlobal);
        r49->data[i6] = emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i7,
          &nf_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r49->size[1];
      i6 = b_yk->size[0];
      b_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)b_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        b_yk->data[i6] = yk->data[(int32_T)r49->data[i6] - 1];
      }

      c_minangle(r37, b_yk);
      emlrtPopRtStackR2012b(&ej_emlrtRSI, emlrtRootTLSGlobal);
      iv61[0] = r36->size[0];
      emlrtSubAssignSizeCheckR2012b(iv61, 1, *(int32_T (*)[1])r37->size, 1,
        &ic_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r37->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r36->data[i6] + yk->size[0] * k] = r37->data[i6];
      }
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&r49);
  emxFree_real_T(&r48);
  emxFree_real_T(&r47);
  emxFree_real_T(&r46);
  emxFree_real_T(&r45);
  emxFree_real_T(&r44);
  emxFree_real_T(&r43);
  emxFree_real_T(&r42);
  emxFree_real_T(&r41);
  emxFree_real_T(&r40);
  emxFree_real_T(&r39);
  emxFree_real_T(&r38);
  emxFree_real_T(&e_yk);
  emxFree_real_T(&d_yk);
  emxFree_real_T(&c_yk);
  emxFree_real_T(&b_yk);
  emxFree_real_T(&l_y);
  emxFree_real_T(&d_y);
  emxFree_real_T(&r37);
  emxFree_int32_T(&r36);
  emxFree_real_T(&RKN_2);
  emxFree_real_T(&RKN_1);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (measurement_eq_17_state.c) */
