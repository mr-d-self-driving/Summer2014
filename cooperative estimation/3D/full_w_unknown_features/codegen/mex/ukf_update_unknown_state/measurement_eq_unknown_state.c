/*
 * measurement_eq_unknown_state.c
 *
 * Code generation for function 'measurement_eq_unknown_state'
 *
 * C source code generated on: Tue Dec  9 10:58:59 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "measurement_eq_unknown_state.h"
#include "vector2polar.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "minangle.h"
#include "ukf_update_unknown_state_mexutil.h"
#include "sqrt.h"
#include "sum.h"
#include "power.h"
#include "attparsilentmex.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo vi_emlrtRSI = { 25, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo wi_emlrtRSI = { 31, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo xi_emlrtRSI = { 36, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo yi_emlrtRSI = { 38, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo aj_emlrtRSI = { 60, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo bj_emlrtRSI = { 65, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo cj_emlrtRSI = { 78, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo dj_emlrtRSI = { 90, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo ej_emlrtRSI = { 106, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo fj_emlrtRSI = { 112, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo gj_emlrtRSI = { 113, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo hj_emlrtRSI = { 114, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo ij_emlrtRSI = { 115, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo jj_emlrtRSI = { 116, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo kj_emlrtRSI = { 117, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo lj_emlrtRSI = { 118, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRSInfo mj_emlrtRSI = { 68, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo nj_emlrtRSI = { 66, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo oj_emlrtRSI = { 61, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo pj_emlrtRSI = { 49, "reshape",
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

static emlrtRTEInfo cb_emlrtRTEI = { 1, 15, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRTEInfo db_emlrtRTEI = { 65, 1, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRTEInfo eb_emlrtRTEI = { 25, 5, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtRTEInfo fb_emlrtRTEI = { 31, 5, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo oc_emlrtECI = { -1, 118, 9, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 118, 40, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 118, 86, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtECInfo pc_emlrtECI = { -1, 117, 9, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo be_emlrtBCI = { -1, -1, 117, 40, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 117, 86, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtECInfo qc_emlrtECI = { -1, 116, 9, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo de_emlrtBCI = { -1, -1, 116, 35, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 116, 77, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtECInfo rc_emlrtECI = { -1, 115, 9, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 115, 35, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 115, 77, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtECInfo sc_emlrtECI = { -1, 114, 9, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo he_emlrtBCI = { -1, -1, 114, 28, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 114, 61, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtECInfo tc_emlrtECI = { -1, 113, 9, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo je_emlrtBCI = { -1, -1, 113, 28, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 113, 61, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 112, 22, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 112, 49, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 107, 22, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 91, 22, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 79, 22, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 68, 12, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 65, 12, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 60, 12, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtECInfo uc_emlrtECI = { -1, 106, 38, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo vc_emlrtECI = { -1, 100, 23, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo te_emlrtBCI = { -1, -1, 99, 22, "feature_index_1",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtRTEInfo xb_emlrtRTEI = { 95, 5, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo wc_emlrtECI = { -1, 90, 36, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo xc_emlrtECI = { -1, 85, 24, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 85, 30, "RKN_2",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtRTEInfo yb_emlrtRTEI = { 83, 5, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo yc_emlrtECI = { -1, 78, 36, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo ad_emlrtECI = { -1, 73, 20, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 73, 26, "RKN_1",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtRTEInfo ac_emlrtRTEI = { 71, 5, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo bd_emlrtECI = { -1, 68, 41, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo cd_emlrtECI = { -1, 68, 30, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo dd_emlrtECI = { -1, 65, 127, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo ed_emlrtECI = { -1, 60, 127, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo we_emlrtBCI = { -1, -1, 56, 15, "nk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 53, 19, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 51, 18, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 49, 26, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 47, 21, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 45, 17, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtECInfo fd_emlrtECI = { -1, 38, 19, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo gd_emlrtECI = { -1, 36, 19, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo hd_emlrtECI = { -1, 31, 21, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtECInfo id_emlrtECI = { -1, 25, 21, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo df_emlrtBCI = { -1, -1, 21, 6, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo db_emlrtDCI = { 21, 6, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 20, 6, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo eb_emlrtDCI = { 20, 6, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 18, 6, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo fb_emlrtDCI = { 18, 6, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 17, 6, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtECInfo jd_emlrtECI = { -1, 15, 9, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m"
};

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 15, 9, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 25, 21, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo gb_emlrtDCI = { 25, 21, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 31, 21, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo hb_emlrtDCI = { 31, 21, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 36, 19, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo ib_emlrtDCI = { 36, 19, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 38, 19, "uk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo jb_emlrtDCI = { 38, 19, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtDCInfo kb_emlrtDCI = { 43, 12, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtDCInfo lb_emlrtDCI = { 43, 12, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  4 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 47, 15, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 49, 20, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 51, 14, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 53, 14, "xk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 60, 127, "nv",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 60, 8, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 65, 127, "nv",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 65, 8, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 68, 30, "nv",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 68, 41, "nv",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 68, 8, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 112, 39, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 112, 55, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 112, 12, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 113, 13, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo mb_emlrtDCI = { 113, 13, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 113, 46, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo nb_emlrtDCI = { 113, 46, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 113, 67, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo ob_emlrtDCI = { 113, 67, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 114, 13, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo pb_emlrtDCI = { 114, 13, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 114, 46, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo qb_emlrtDCI = { 114, 46, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 114, 67, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo rb_emlrtDCI = { 114, 67, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 115, 13, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo sb_emlrtDCI = { 115, 13, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 115, 55, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo tb_emlrtDCI = { 115, 55, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 115, 86, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo ub_emlrtDCI = { 115, 86, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 116, 13, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo vb_emlrtDCI = { 116, 13, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 116, 55, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo wb_emlrtDCI = { 116, 55, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 116, 86, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo xb_emlrtDCI = { 116, 86, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 117, 13, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo yb_emlrtDCI = { 117, 13, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 117, 59, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo ac_emlrtDCI = { 117, 59, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 117, 95, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo bc_emlrtDCI = { 117, 95, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 118, 13, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo cc_emlrtDCI = { 118, 13, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 118, 59, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo dc_emlrtDCI = { 118, 59, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 118, 95, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo ec_emlrtDCI = { 118, 95, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 100, 23, "xhat",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo fc_emlrtDCI = { 100, 23, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 106, 38, "nv",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo gc_emlrtDCI = { 106, 38, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 107, 12, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo hc_emlrtDCI = { 107, 12, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 90, 36, "nv",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo ic_emlrtDCI = { 90, 36, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 91, 12, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtDCInfo jc_emlrtDCI = { 91, 12, "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  1 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 78, 36, "nv",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 79, 12, "yk",
  "measurement_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m",
  0 };

/* Function Declarations */
static void b_eml_error(void);
static int32_T div_s32(int32_T numerator, int32_T denominator);

/* Function Definitions */
static void b_eml_error(void)
{
  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &wb_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
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

void measurement_eq_unknown_state(const emxArray_real_T *xk, const
  emxArray_real_T *nk, const real_T uk_data[100], const int32_T uk_size[1],
  emxArray_real_T *yk)
{
  int32_T i6;
  int32_T i7;
  real_T y;
  real_T absb;
  real_T b_y;
  real_T c_y;
  real_T d_y;
  real_T e_y;
  emxArray_real_T *RKN_1;
  emxArray_real_T *r22;
  emxArray_real_T *f_y;
  real_T g_y;
  int32_T n;
  real_T anew;
  real_T apnd;
  boolean_T overflow;
  real_T ndbl;
  real_T cdiff;
  const mxArray *h_y;
  static const int32_T iv46[2] = { 1, 21 };

  const mxArray *m8;
  char_T cv30[21];
  int32_T i;
  static const char_T cv31[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  int32_T k;
  int32_T loop_ub;
  int32_T sz[2];
  emxArray_int32_T *r23;
  emxArray_int32_T *r24;
  int32_T unnamed_idx_0;
  const mxArray *i_y;
  emxArray_int32_T *r25;
  emxArray_int32_T *r26;
  emxArray_int32_T *r27;
  emxArray_int32_T *r28;
  const mxArray *j_y;
  static const int32_T iv47[2] = { 1, 40 };

  char_T cv32[40];
  static const char_T cv33[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  emxArray_int32_T *r29;
  emxArray_int32_T *r30;
  emxArray_int32_T *r31;
  int32_T exitg2;
  emxArray_real_T *RKN_2;
  const mxArray *k_y;
  static const int32_T iv48[2] = { 1, 21 };

  int32_T b_sz[2];
  emxArray_int32_T *r32;
  emxArray_int32_T *r33;
  const mxArray *l_y;
  emxArray_int32_T *r34;
  emxArray_int32_T *r35;
  emxArray_int32_T *r36;
  emxArray_int32_T *r37;
  const mxArray *m_y;
  static const int32_T iv49[2] = { 1, 40 };

  emxArray_int32_T *r38;
  emxArray_int32_T *r39;
  emxArray_int32_T *r40;
  int32_T exitg1;
  real_T d1;
  const mxArray *n_y;
  static const int32_T iv50[2] = { 1, 21 };

  real_T d2;
  const mxArray *o_y;
  static const int32_T iv51[2] = { 1, 21 };

  emxArray_real_T *p_y;
  emxArray_int32_T *r41;
  emxArray_real_T *r42;
  emxArray_real_T *q_y;
  emxArray_real_T *b_yk;
  emxArray_real_T *c_yk;
  emxArray_real_T *d_yk;
  emxArray_real_T *e_yk;
  emxArray_real_T *f_yk;
  emxArray_real_T *g_yk;
  emxArray_int32_T *r43;
  emxArray_real_T *r44;
  emxArray_real_T *r45;
  emxArray_real_T *r46;
  emxArray_real_T *r47;
  emxArray_real_T *r48;
  emxArray_real_T *r49;
  emxArray_real_T *r50;
  emxArray_real_T *r51;
  emxArray_real_T *r52;
  emxArray_real_T *r53;
  emxArray_real_T *r54;
  emxArray_real_T *r55;
  emxArray_real_T *r56;
  emxArray_real_T *r57;
  emxArray_real_T *r58;
  emxArray_real_T *r59;
  emxArray_real_T *r60;
  emxArray_real_T *r61;
  real_T b_xk[4];
  real_T Cin[9];
  real_T Cji[9];
  real_T c_xk[3];
  real_T d_xk[2];
  real_T x[2];
  real_T dv7[3];
  real_T nk_data[200];
  real_T dv8[3];
  real_T b_Cji[9];
  real_T rij_j_hat[3];
  real_T dv9[3];
  real_T dv10[3];
  int32_T kk;
  real_T tmp_data[3];
  real_T b_index[3];
  real_T b_Cin[3];
  real_T dv11[3];
  int32_T iv52[6];
  real_T dv12[2];
  static const int8_T iv53[4] = { 2, 3, 5, 6 };

  real_T h_yk[4];
  real_T dv13[4];
  const mxArray *r_y;
  static const int32_T iv54[2] = { 1, 21 };

  uint32_T kd;
  const mxArray *s_y;
  static const int32_T iv55[2] = { 1, 21 };

  const mxArray *t_y;
  static const int32_T iv56[2] = { 1, 21 };

  int32_T iv57[1];
  const mxArray *u_y;
  static const int32_T iv58[2] = { 1, 21 };

  const mxArray *v_y;
  static const int32_T iv59[2] = { 1, 21 };

  const mxArray *w_y;
  static const int32_T iv60[2] = { 1, 21 };

  int32_T iv61[1];
  const mxArray *x_y;
  static const int32_T iv62[2] = { 1, 21 };

  const mxArray *y_y;
  static const int32_T iv63[2] = { 1, 21 };

  const mxArray *ab_y;
  static const int32_T iv64[2] = { 1, 21 };

  int32_T iv65[1];
  const mxArray *bb_y;
  static const int32_T iv66[2] = { 1, 21 };

  const mxArray *cb_y;
  static const int32_T iv67[2] = { 1, 21 };

  const mxArray *db_y;
  static const int32_T iv68[2] = { 1, 21 };

  int32_T iv69[1];
  const mxArray *eb_y;
  static const int32_T iv70[2] = { 1, 21 };

  const mxArray *fb_y;
  static const int32_T iv71[2] = { 1, 21 };

  const mxArray *gb_y;
  static const int32_T iv72[2] = { 1, 21 };

  int32_T iv73[1];
  const mxArray *hb_y;
  static const int32_T iv74[2] = { 1, 21 };

  const mxArray *ib_y;
  static const int32_T iv75[2] = { 1, 21 };

  const mxArray *jb_y;
  static const int32_T iv76[2] = { 1, 21 };

  int32_T iv77[1];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /*  m1: # of known features agent 1 sees */
  /*  m2: # of known features agent 2 sees */
  /*  m = m1 + m2 */
  /* xk: 17 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion */
  /* nk: 12+3*m1+3*m2+3*u1+3*u2 x 2N+1, error on range/bearing/azimuth for agent 1, then agent 2, then magnetometer errors for agent 1 then 2,  */
  /*        THEN feature range/bearing/azimuth errors FOR EACH KNOWN FEATURE */
  /*        for agent 1, then same for agent 2, THEN AGAIN for unknown features for 1, then 2  */
  /* uk[wi;ai;mag_i;# of i known features;rkn;...;# of j features;rkn;...; # of i unknown features; indices of i unknown features;  */
  /*    # of j unknown features; indices of j unknown features] : 9+2+3*m+3*w1+3*w2 x 2N+1, m being total # of features from i and j  */
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &jd_emlrtECI,
    emlrtRootTLSGlobal);
  for (i6 = 0; i6 < 3; i6++) {
    i7 = 7 + i6;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &hf_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  emlrtDynamicBoundsCheckFastR2012b(10, 1, uk_size[0], &gf_emlrtBCI,
    emlrtRootTLSGlobal);
  y = 3.0 * uk_data[9];
  absb = (10.0 + 3.0 * uk_data[9]) + 1.0;
  i6 = (int32_T)emlrtIntegerCheckFastR2012b(absb, &fb_emlrtDCI,
    emlrtRootTLSGlobal);
  emlrtDynamicBoundsCheckFastR2012b(i6, 1, uk_size[0], &ff_emlrtBCI,
    emlrtRootTLSGlobal);

  /*  total # of features */
  b_y = 3.0 * uk_data[9];
  c_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
  absb = (12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0 *
    uk_data[9]) + 1.0) - 1];
  i6 = (int32_T)emlrtIntegerCheckFastR2012b(absb, &eb_emlrtDCI,
    emlrtRootTLSGlobal);
  emlrtDynamicBoundsCheckFastR2012b(i6, 1, uk_size[0], &ef_emlrtBCI,
    emlrtRootTLSGlobal);
  d_y = 3.0 * uk_data[9];
  e_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
  absb = (((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0 *
             uk_data[9]) + 1.0) - 1]) + uk_data[(int32_T)((12.0 + b_y) + c_y) -
          1]) + 1.0;
  i6 = (int32_T)emlrtIntegerCheckFastR2012b(absb, &db_emlrtDCI,
    emlrtRootTLSGlobal);
  emlrtDynamicBoundsCheckFastR2012b(i6, 1, uk_size[0], &df_emlrtBCI,
    emlrtRootTLSGlobal);

  /*  3 x m1 array of known inertial position of features seen by agent 1 */
  emxInit_real_T(&RKN_1, 2, &eb_emlrtRTEI, TRUE);
  emxInit_real_T(&r22, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&f_y, 2, &cb_emlrtRTEI, TRUE);
  if (uk_data[9] > 0.0) {
    emlrtPushRtStackR2012b(&vi_emlrtRSI, emlrtRootTLSGlobal);
    g_y = uk_data[9] * 3.0;
    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
    if (muDoubleScalarIsNaN(g_y)) {
      n = 0;
      anew = rtNaN;
      apnd = g_y;
      overflow = FALSE;
    } else if (g_y < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = g_y;
      overflow = FALSE;
    } else if (muDoubleScalarIsInf(g_y)) {
      n = 0;
      anew = rtNaN;
      apnd = g_y;
      overflow = !(1.0 == g_y);
    } else {
      anew = 1.0;
      ndbl = muDoubleScalarFloor((g_y - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - g_y;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * g_y) {
        ndbl++;
        apnd = g_y;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      overflow = (2.147483647E+9 < ndbl);
      if (ndbl >= 0.0) {
        n = (int32_T)ndbl - 1;
      } else {
        n = -1;
      }
    }

    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    if (!overflow) {
    } else {
      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      h_y = NULL;
      m8 = mxCreateCharArray(2, iv46);
      for (i = 0; i < 21; i++) {
        cv30[i] = cv31[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
      emlrtAssign(&h_y, m8);
      error(message(h_y, &b_emlrtMCI), &c_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    i6 = r22->size[0] * r22->size[1];
    r22->size[0] = 1;
    r22->size[1] = n + 1;
    emxEnsureCapacity((emxArray__common *)r22, i6, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (n + 1 > 0) {
      r22->data[0] = anew;
      if (n + 1 > 1) {
        r22->data[n] = apnd;
        i6 = n + (n < 0);
        if (i6 >= 0) {
          i = (int32_T)((uint32_T)i6 >> 1);
        } else {
          i = ~(int32_T)((uint32_T)~i6 >> 1);
        }

        emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k < i; k++) {
          r22->data[k] = anew + (real_T)k;
          r22->data[n - k] = apnd - (real_T)k;
        }

        if (i << 1 == n) {
          r22->data[i] = (anew + apnd) / 2.0;
        } else {
          r22->data[i] = anew + (real_T)i;
          r22->data[i + 1] = apnd - (real_T)i;
        }
      }
    }

    emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&vi_emlrtRSI, emlrtRootTLSGlobal);
    emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, r22->size[1],
      &id_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&vi_emlrtRSI, emlrtRootTLSGlobal);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      absb = 10.0 + r22->data[i6];
      i7 = (int32_T)emlrtIntegerCheckFastR2012b(absb, &gb_emlrtDCI,
        emlrtRootTLSGlobal);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &if_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    sz[0] = 3;
    sz[1] = 1;
    i = 1;
    for (k = 0; k < 2; k++) {
      i *= sz[k];
    }

    if (i > 0) {
      emxInit_int32_T(&r23, 2, &cb_emlrtRTEI, TRUE);
      i6 = r23->size[0] * r23->size[1];
      r23->size[0] = 1;
      r23->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r23, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r23->data[i6] = (int32_T)(10.0 + r22->data[i6]);
      }

      emxInit_int32_T(&r24, 2, &cb_emlrtRTEI, TRUE);
      unnamed_idx_0 = r23->size[1];
      i = div_s32(unnamed_idx_0, i);
      i6 = r24->size[0] * r24->size[1];
      r24->size[0] = 1;
      r24->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r24, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      emxFree_int32_T(&r23);
      for (i6 = 0; i6 < loop_ub; i6++) {
        r24->data[i6] = (int32_T)(10.0 + r22->data[i6]);
      }

      unnamed_idx_0 = r24->size[1];
      emxFree_int32_T(&r24);
      if (i <= unnamed_idx_0) {
      } else {
        emlrtPushRtStackR2012b(&pj_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        i_y = NULL;
        m8 = mxCreateString("Assertion failed.");
        emlrtAssign(&i_y, m8);
        error(i_y, &v_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&pj_emlrtRSI, emlrtRootTLSGlobal);
      }

      sz[1] = i;
    } else {
      sz[1] = 0;
    }

    emxInit_int32_T(&r25, 2, &cb_emlrtRTEI, TRUE);
    i6 = r25->size[0] * r25->size[1];
    r25->size[0] = 1;
    r25->size[1] = r22->size[1];
    emxEnsureCapacity((emxArray__common *)r25, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r25->data[i6] = (int32_T)(10.0 + r22->data[i6]);
    }

    i = r25->size[1];
    emxFree_int32_T(&r25);
    if (1 > i) {
      i = 1;
    }

    emxInit_int32_T(&r26, 2, &cb_emlrtRTEI, TRUE);
    i6 = r26->size[0] * r26->size[1];
    r26->size[0] = 1;
    r26->size[1] = r22->size[1];
    emxEnsureCapacity((emxArray__common *)r26, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r26->data[i6] = (int32_T)(10.0 + r22->data[i6]);
    }

    unnamed_idx_0 = r26->size[1];
    emxFree_int32_T(&r26);
    if (unnamed_idx_0 < i) {
    } else {
      emxInit_int32_T(&r27, 2, &cb_emlrtRTEI, TRUE);
      i6 = r27->size[0] * r27->size[1];
      r27->size[0] = 1;
      r27->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r27, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r27->data[i6] = (int32_T)(10.0 + r22->data[i6]);
      }

      i = r27->size[1];
      emxFree_int32_T(&r27);
    }

    if (3 > i) {
      emlrtPushRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
    }

    if (sz[1] > i) {
      emlrtPushRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r28, 2, &cb_emlrtRTEI, TRUE);
    i6 = f_y->size[0] * f_y->size[1];
    f_y->size[0] = 3;
    f_y->size[1] = sz[1];
    emxEnsureCapacity((emxArray__common *)f_y, i6, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    i6 = r28->size[0] * r28->size[1];
    r28->size[0] = 1;
    r28->size[1] = r22->size[1];
    emxEnsureCapacity((emxArray__common *)r28, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r28->data[i6] = (int32_T)(10.0 + r22->data[i6]);
    }

    unnamed_idx_0 = r28->size[1];
    emxFree_int32_T(&r28);
    if (unnamed_idx_0 == 3 * sz[1]) {
    } else {
      emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      j_y = NULL;
      m8 = mxCreateCharArray(2, iv47);
      for (i = 0; i < 40; i++) {
        cv32[i] = cv33[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 40, m8, cv32);
      emlrtAssign(&j_y, m8);
      error(message(j_y, &w_emlrtMCI), &x_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r29, 2, &cb_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
    i6 = r29->size[0] * r29->size[1];
    r29->size[0] = 1;
    r29->size[1] = r22->size[1];
    emxEnsureCapacity((emxArray__common *)r29, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r29->data[i6] = (int32_T)(10.0 + r22->data[i6]);
    }

    unnamed_idx_0 = r29->size[1];
    emxFree_int32_T(&r29);
    if (1 > unnamed_idx_0) {
      overflow = FALSE;
    } else {
      emxInit_int32_T(&r30, 2, &cb_emlrtRTEI, TRUE);
      i6 = r30->size[0] * r30->size[1];
      r30->size[0] = 1;
      r30->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r30, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r30->data[i6] = (int32_T)(10.0 + r22->data[i6]);
      }

      unnamed_idx_0 = r30->size[1];
      overflow = (unnamed_idx_0 > 2147483646);
      emxFree_int32_T(&r30);
    }

    if (overflow) {
      emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
    k = 0;
    emxInit_int32_T(&r31, 2, &cb_emlrtRTEI, TRUE);
    do {
      exitg2 = 0;
      i6 = r31->size[0] * r31->size[1];
      r31->size[0] = 1;
      r31->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r31, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r31->data[i6] = (int32_T)(10.0 + r22->data[i6]);
      }

      unnamed_idx_0 = r31->size[1];
      if (k + 1 <= unnamed_idx_0) {
        f_y->data[k] = uk_data[(int32_T)(10.0 + r22->data[r22->size[0] * k]) - 1];
        k++;
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    emxFree_int32_T(&r31);
    i6 = RKN_1->size[0] * RKN_1->size[1];
    RKN_1->size[0] = f_y->size[1];
    RKN_1->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)RKN_1, i6, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
    for (i6 = 0; i6 < 3; i6++) {
      loop_ub = f_y->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        RKN_1->data[i7 + RKN_1->size[0] * i6] = f_y->data[i6 + f_y->size[0] * i7];
      }
    }

    emlrtPopRtStackR2012b(&vi_emlrtRSI, emlrtRootTLSGlobal);
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
    emlrtPushRtStackR2012b(&wi_emlrtRSI, emlrtRootTLSGlobal);
    g_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
    if (muDoubleScalarIsNaN(g_y)) {
      n = 0;
      anew = rtNaN;
      apnd = g_y;
      overflow = FALSE;
    } else if (g_y < 1.0) {
      n = -1;
      anew = 1.0;
      apnd = g_y;
      overflow = FALSE;
    } else if (muDoubleScalarIsInf(g_y)) {
      n = 0;
      anew = rtNaN;
      apnd = g_y;
      overflow = !(1.0 == g_y);
    } else {
      anew = 1.0;
      ndbl = muDoubleScalarFloor((g_y - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - g_y;
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * g_y) {
        ndbl++;
        apnd = g_y;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      overflow = (2.147483647E+9 < ndbl);
      if (ndbl >= 0.0) {
        n = (int32_T)ndbl - 1;
      } else {
        n = -1;
      }
    }

    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    if (!overflow) {
    } else {
      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      k_y = NULL;
      m8 = mxCreateCharArray(2, iv48);
      for (i = 0; i < 21; i++) {
        cv30[i] = cv31[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
      emlrtAssign(&k_y, m8);
      error(message(k_y, &b_emlrtMCI), &c_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    i6 = r22->size[0] * r22->size[1];
    r22->size[0] = 1;
    r22->size[1] = n + 1;
    emxEnsureCapacity((emxArray__common *)r22, i6, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (n + 1 > 0) {
      r22->data[0] = anew;
      if (n + 1 > 1) {
        r22->data[n] = apnd;
        i6 = n + (n < 0);
        if (i6 >= 0) {
          i = (int32_T)((uint32_T)i6 >> 1);
        } else {
          i = ~(int32_T)((uint32_T)~i6 >> 1);
        }

        emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k < i; k++) {
          r22->data[k] = anew + (real_T)k;
          r22->data[n - k] = apnd - (real_T)k;
        }

        if (i << 1 == n) {
          r22->data[i] = (anew + apnd) / 2.0;
        } else {
          r22->data[i] = anew + (real_T)i;
          r22->data[i + 1] = apnd - (real_T)i;
        }
      }
    }

    emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&wi_emlrtRSI, emlrtRootTLSGlobal);
    emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, r22->size[1],
      &hd_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&wi_emlrtRSI, emlrtRootTLSGlobal);
    g_y = 3.0 * uk_data[9];
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      absb = (11.0 + g_y) + r22->data[i6];
      i7 = (int32_T)emlrtIntegerCheckFastR2012b(absb, &hb_emlrtDCI,
        emlrtRootTLSGlobal);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &jf_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    b_sz[0] = 3;
    b_sz[1] = 1;
    i = 1;
    for (k = 0; k < 2; k++) {
      i *= b_sz[k];
    }

    if (i > 0) {
      emxInit_int32_T(&r32, 2, &cb_emlrtRTEI, TRUE);
      i6 = r32->size[0] * r32->size[1];
      r32->size[0] = 1;
      r32->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r32, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r32->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
      }

      emxInit_int32_T(&r33, 2, &cb_emlrtRTEI, TRUE);
      unnamed_idx_0 = r32->size[1];
      i = div_s32(unnamed_idx_0, i);
      i6 = r33->size[0] * r33->size[1];
      r33->size[0] = 1;
      r33->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r33, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      emxFree_int32_T(&r32);
      for (i6 = 0; i6 < loop_ub; i6++) {
        r33->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
      }

      unnamed_idx_0 = r33->size[1];
      emxFree_int32_T(&r33);
      if (i <= unnamed_idx_0) {
      } else {
        emlrtPushRtStackR2012b(&pj_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        l_y = NULL;
        m8 = mxCreateString("Assertion failed.");
        emlrtAssign(&l_y, m8);
        error(l_y, &v_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&pj_emlrtRSI, emlrtRootTLSGlobal);
      }

      b_sz[1] = i;
    } else {
      b_sz[1] = 0;
    }

    emxInit_int32_T(&r34, 2, &cb_emlrtRTEI, TRUE);
    i6 = r34->size[0] * r34->size[1];
    r34->size[0] = 1;
    r34->size[1] = r22->size[1];
    emxEnsureCapacity((emxArray__common *)r34, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r34->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
    }

    i = r34->size[1];
    emxFree_int32_T(&r34);
    if (1 > i) {
      i = 1;
    }

    emxInit_int32_T(&r35, 2, &cb_emlrtRTEI, TRUE);
    i6 = r35->size[0] * r35->size[1];
    r35->size[0] = 1;
    r35->size[1] = r22->size[1];
    emxEnsureCapacity((emxArray__common *)r35, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r35->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
    }

    unnamed_idx_0 = r35->size[1];
    emxFree_int32_T(&r35);
    if (unnamed_idx_0 < i) {
    } else {
      emxInit_int32_T(&r36, 2, &cb_emlrtRTEI, TRUE);
      i6 = r36->size[0] * r36->size[1];
      r36->size[0] = 1;
      r36->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r36, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r36->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
      }

      i = r36->size[1];
      emxFree_int32_T(&r36);
    }

    if (3 > i) {
      emlrtPushRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
    }

    if (b_sz[1] > i) {
      emlrtPushRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&oj_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r37, 2, &cb_emlrtRTEI, TRUE);
    i6 = f_y->size[0] * f_y->size[1];
    f_y->size[0] = 3;
    f_y->size[1] = b_sz[1];
    emxEnsureCapacity((emxArray__common *)f_y, i6, (int32_T)sizeof(real_T),
                      &db_emlrtRTEI);
    i6 = r37->size[0] * r37->size[1];
    r37->size[0] = 1;
    r37->size[1] = r22->size[1];
    emxEnsureCapacity((emxArray__common *)r37, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r37->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
    }

    unnamed_idx_0 = r37->size[1];
    emxFree_int32_T(&r37);
    if (unnamed_idx_0 == 3 * b_sz[1]) {
    } else {
      emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      m_y = NULL;
      m8 = mxCreateCharArray(2, iv49);
      for (i = 0; i < 40; i++) {
        cv32[i] = cv33[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 40, m8, cv32);
      emlrtAssign(&m_y, m8);
      error(message(m_y, &w_emlrtMCI), &x_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxInit_int32_T(&r38, 2, &cb_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
    i6 = r38->size[0] * r38->size[1];
    r38->size[0] = 1;
    r38->size[1] = r22->size[1];
    emxEnsureCapacity((emxArray__common *)r38, i6, (int32_T)sizeof(int32_T),
                      &cb_emlrtRTEI);
    loop_ub = r22->size[0] * r22->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      r38->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
    }

    unnamed_idx_0 = r38->size[1];
    emxFree_int32_T(&r38);
    if (1 > unnamed_idx_0) {
      overflow = FALSE;
    } else {
      emxInit_int32_T(&r39, 2, &cb_emlrtRTEI, TRUE);
      i6 = r39->size[0] * r39->size[1];
      r39->size[0] = 1;
      r39->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r39, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r39->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
      }

      unnamed_idx_0 = r39->size[1];
      overflow = (unnamed_idx_0 > 2147483646);
      emxFree_int32_T(&r39);
    }

    if (overflow) {
      emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&mj_emlrtRSI, emlrtRootTLSGlobal);
    k = 0;
    emxInit_int32_T(&r40, 2, &cb_emlrtRTEI, TRUE);
    do {
      exitg1 = 0;
      i6 = r40->size[0] * r40->size[1];
      r40->size[0] = 1;
      r40->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r40, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r40->data[i6] = (int32_T)((11.0 + g_y) + r22->data[i6]);
      }

      unnamed_idx_0 = r40->size[1];
      if (k + 1 <= unnamed_idx_0) {
        f_y->data[k] = uk_data[(int32_T)((11.0 + g_y) + r22->data[r22->size[0] *
          k]) - 1];
        k++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    emxFree_int32_T(&r40);
    i6 = RKN_2->size[0] * RKN_2->size[1];
    RKN_2->size[0] = f_y->size[1];
    RKN_2->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)RKN_2, i6, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
    for (i6 = 0; i6 < 3; i6++) {
      loop_ub = f_y->size[1];
      for (i7 = 0; i7 < loop_ub; i7++) {
        RKN_2->data[i7 + RKN_2->size[0] * i6] = f_y->data[i6 + f_y->size[0] * i7];
      }
    }

    emlrtPopRtStackR2012b(&wi_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    i6 = RKN_2->size[0] * RKN_2->size[1];
    RKN_2->size[0] = 0;
    RKN_2->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)RKN_2, i6, (int32_T)sizeof(real_T),
                      &cb_emlrtRTEI);
  }

  emxFree_real_T(&f_y);

  /*  feature indices of unknown features */
  emlrtPushRtStackR2012b(&xi_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
  if (muDoubleScalarIsNaN(uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 *
        uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) - 1])) {
    n = 0;
    anew = rtNaN;
    apnd = uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
    overflow = FALSE;
  } else if (uk_data[(int32_T)((12.0 + b_y) + c_y) - 1] < 1.0) {
    n = -1;
    anew = 1.0;
    apnd = uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
    overflow = FALSE;
  } else if (muDoubleScalarIsInf(uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) +
               3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) -
              1])) {
    n = 0;
    anew = rtNaN;
    apnd = uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
    overflow = !(1.0 == uk_data[(int32_T)((12.0 + b_y) + c_y) - 1]);
  } else {
    anew = 1.0;
    ndbl = muDoubleScalarFloor((uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) +
      3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) - 1] - 1.0)
      + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
    absb = muDoubleScalarAbs(uk_data[(int32_T)((12.0 + b_y) + c_y) - 1]);
    if (1.0 > absb) {
      d1 = 1.0;
    } else {
      d1 = absb;
    }

    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d1) {
      ndbl++;
      apnd = uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl - 1;
    } else {
      n = -1;
    }
  }

  emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  if (!overflow) {
  } else {
    emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    n_y = NULL;
    m8 = mxCreateCharArray(2, iv50);
    for (i = 0; i < 21; i++) {
      cv30[i] = cv31[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
    emlrtAssign(&n_y, m8);
    error(message(n_y, &b_emlrtMCI), &c_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  i6 = r22->size[0] * r22->size[1];
  r22->size[0] = 1;
  r22->size[1] = n + 1;
  emxEnsureCapacity((emxArray__common *)r22, i6, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (n + 1 > 0) {
    r22->data[0] = anew;
    if (n + 1 > 1) {
      r22->data[n] = apnd;
      i6 = n + (n < 0);
      if (i6 >= 0) {
        i = (int32_T)((uint32_T)i6 >> 1);
      } else {
        i = ~(int32_T)((uint32_T)~i6 >> 1);
      }

      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 1; k < i; k++) {
        r22->data[k] = anew + (real_T)k;
        r22->data[n - k] = apnd - (real_T)k;
      }

      if (i << 1 == n) {
        r22->data[i] = (anew + apnd) / 2.0;
      } else {
        r22->data[i] = anew + (real_T)i;
        r22->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&xi_emlrtRSI, emlrtRootTLSGlobal);
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, r22->size[1], &gd_emlrtECI,
    emlrtRootTLSGlobal);
  g_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) -
               1]);
  loop_ub = r22->size[0] * r22->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    absb = (12.0 + g_y) + r22->data[i6];
    i7 = (int32_T)emlrtIntegerCheckFastR2012b(absb, &ib_emlrtDCI,
      emlrtRootTLSGlobal);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &kf_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  /*  feature indices of other agent's unknown features */
  emlrtPushRtStackR2012b(&yi_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
  if (muDoubleScalarIsNaN(uk_data[(int32_T)((((12.0 + 3.0 * uk_data[9]) + 3.0 *
          uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) + uk_data
         [(int32_T)((12.0 + b_y) + c_y) - 1]) + 1.0) - 1])) {
    n = 0;
    anew = rtNaN;
    apnd = uk_data[(int32_T)((((12.0 + d_y) + e_y) + uk_data[(int32_T)((12.0 +
      3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
      1.0) - 1]) - 1]) + 1.0) - 1];
    overflow = FALSE;
  } else if (uk_data[(int32_T)((((12.0 + d_y) + e_y) + uk_data[(int32_T)((12.0 +
    3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0)
    - 1]) - 1]) + 1.0) - 1] < 1.0) {
    n = -1;
    anew = 1.0;
    apnd = uk_data[(int32_T)((((12.0 + d_y) + e_y) + uk_data[(int32_T)((12.0 +
      3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
      1.0) - 1]) - 1]) + 1.0) - 1];
    overflow = FALSE;
  } else if (muDoubleScalarIsInf(uk_data[(int32_T)((((12.0 + 3.0 * uk_data[9]) +
    3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) + uk_data
                [(int32_T)((12.0 + b_y) + c_y) - 1]) + 1.0) - 1])) {
    n = 0;
    anew = rtNaN;
    apnd = uk_data[(int32_T)((((12.0 + d_y) + e_y) + uk_data[(int32_T)((12.0 +
      3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
      1.0) - 1]) - 1]) + 1.0) - 1];
    overflow = !(1.0 == uk_data[(int32_T)((((12.0 + d_y) + e_y) + uk_data
      [(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0
      * uk_data[9]) + 1.0) - 1]) - 1]) + 1.0) - 1]);
  } else {
    anew = 1.0;
    ndbl = muDoubleScalarFloor((uk_data[(int32_T)((((12.0 + 3.0 * uk_data[9]) +
      3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) + uk_data
      [(int32_T)((12.0 + b_y) + c_y) - 1]) + 1.0) - 1] - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - uk_data[(int32_T)((((12.0 + d_y) + e_y) + uk_data
      [(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0
      * uk_data[9]) + 1.0) - 1]) - 1]) + 1.0) - 1];
    absb = muDoubleScalarAbs(uk_data[(int32_T)((((12.0 + d_y) + e_y) + uk_data
      [(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0
      * uk_data[9]) + 1.0) - 1]) - 1]) + 1.0) - 1]);
    if (1.0 > absb) {
      d2 = 1.0;
    } else {
      d2 = absb;
    }

    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d2) {
      ndbl++;
      apnd = uk_data[(int32_T)((((12.0 + d_y) + e_y) + uk_data[(int32_T)((12.0 +
        3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]) - 1]) + 1.0) - 1];
    } else if (cdiff > 0.0) {
      apnd = 1.0 + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    overflow = (2.147483647E+9 < ndbl);
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl - 1;
    } else {
      n = -1;
    }
  }

  emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  if (!overflow) {
  } else {
    emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    o_y = NULL;
    m8 = mxCreateCharArray(2, iv51);
    for (i = 0; i < 21; i++) {
      cv30[i] = cv31[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
    emlrtAssign(&o_y, m8);
    error(message(o_y, &b_emlrtMCI), &c_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxInit_real_T(&p_y, 2, &cb_emlrtRTEI, TRUE);
  emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  i6 = p_y->size[0] * p_y->size[1];
  p_y->size[0] = 1;
  p_y->size[1] = n + 1;
  emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (n + 1 > 0) {
    p_y->data[0] = anew;
    if (n + 1 > 1) {
      p_y->data[n] = apnd;
      i6 = n + (n < 0);
      if (i6 >= 0) {
        i = (int32_T)((uint32_T)i6 >> 1);
      } else {
        i = ~(int32_T)((uint32_T)~i6 >> 1);
      }

      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 1; k < i; k++) {
        p_y->data[k] = anew + (real_T)k;
        p_y->data[n - k] = apnd - (real_T)k;
      }

      if (i << 1 == n) {
        p_y->data[i] = (anew + apnd) / 2.0;
      } else {
        p_y->data[i] = anew + (real_T)i;
        p_y->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&yi_emlrtRSI, emlrtRootTLSGlobal);
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, p_y->size[1], &fd_emlrtECI,
    emlrtRootTLSGlobal);
  absb = ((12.0 + 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9])
             + 1.0) - 1])) + 1.0) + uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
  loop_ub = p_y->size[0] * p_y->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    apnd = absb + p_y->data[i6];
    i7 = (int32_T)emlrtIntegerCheckFastR2012b(apnd, &jb_emlrtDCI,
      emlrtRootTLSGlobal);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &lf_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  d_y = 3.0 * (((uk_data[9] + uk_data[(int32_T)((10.0 + y) + 1.0) - 1]) +
                uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data
    [(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) - 1]) + uk_data[(int32_T)
               ((((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)((10.0 +
    3.0 * uk_data[9]) + 1.0) - 1]) + uk_data[(int32_T)((12.0 + b_y) + c_y) - 1])
                + 1.0) - 1]);
  absb = 9.0 + d_y;
  absb = emlrtNonNegativeCheckFastR2012b(absb, &lb_emlrtDCI, emlrtRootTLSGlobal);
  emlrtIntegerCheckFastR2012b(absb, &kb_emlrtDCI, emlrtRootTLSGlobal);
  i6 = yk->size[0] * yk->size[1];
  yk->size[0] = (int32_T)(9.0 + d_y);
  emxEnsureCapacity((emxArray__common *)yk, i6, (int32_T)sizeof(real_T),
                    &cb_emlrtRTEI);
  absb = 9.0 + d_y;
  absb = emlrtNonNegativeCheckFastR2012b(absb, &lb_emlrtDCI, emlrtRootTLSGlobal);
  emlrtIntegerCheckFastR2012b(absb, &kb_emlrtDCI, emlrtRootTLSGlobal);
  i = xk->size[1];
  i6 = yk->size[0] * yk->size[1];
  yk->size[1] = i;
  emxEnsureCapacity((emxArray__common *)yk, i6, (int32_T)sizeof(real_T),
                    &cb_emlrtRTEI);
  absb = 9.0 + d_y;
  absb = emlrtNonNegativeCheckFastR2012b(absb, &lb_emlrtDCI, emlrtRootTLSGlobal);
  loop_ub = (int32_T)emlrtIntegerCheckFastR2012b(absb, &kb_emlrtDCI,
    emlrtRootTLSGlobal) * xk->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    yk->data[i6] = 0.0;
  }

  k = 0;
  b_emxInit_int32_T(&r41, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r42, 1, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&q_y, 2, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&b_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&c_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&d_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&e_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&f_yk, 1, &cb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&g_yk, 1, &cb_emlrtRTEI, TRUE);
  emxInit_int32_T(&r43, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r44, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r45, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r46, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r47, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r48, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r49, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r50, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r51, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r52, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r53, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r54, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r55, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r56, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r57, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r58, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r59, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r60, 2, &cb_emlrtRTEI, TRUE);
  emxInit_real_T(&r61, 2, &cb_emlrtRTEI, TRUE);
  while (k <= xk->size[1] - 1) {
    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &cf_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  i to j frame transform */
    for (i6 = 0; i6 < 4; i6++) {
      i7 = xk->size[0];
      n = 14 + i6;
      emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &mf_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &bf_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  est relative position in my (i) frame */
    for (i6 = 0; i6 < 3; i6++) {
      i7 = xk->size[0];
      n = 11 + i6;
      emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &nf_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &af_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  estimated my inertial position */
    for (i6 = 0; i6 < 3; i6++) {
      i7 = xk->size[0];
      n = 1 + i6;
      emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &of_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ye_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  my estimated inertial attitude */
    for (i6 = 0; i6 < 4; i6++) {
      i7 = xk->size[0];
      n = 7 + i6;
      emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &pf_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &xe_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i6 = 0; i6 < 4; i6++) {
      b_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 6];
    }

    attparsilentmex(b_xk, Cin);
    i6 = nk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &we_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i6 = 0; i6 < 4; i6++) {
      b_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 13];
    }

    attparsilentmex(b_xk, Cji);

    /*  expected range/bearing/azimuth from agent i's measurement */
    i6 = nk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &ed_emlrtECI,
      emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&aj_emlrtRSI, emlrtRootTLSGlobal);
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

    power(c_xk, dv7);
    absb = b_sum(dv7);
    b_sqrt(&absb);
    i6 = nk->size[0];
    unnamed_idx_0 = yk->size[0];
    i = yk->size[1];
    i7 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &se_emlrtBCI, emlrtRootTLSGlobal);
    loop_ub = nk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      nk_data[i7] = nk->data[i7 + nk->size[0] * k];
    }

    dv8[0] = absb;
    dv8[1] = muDoubleScalarAtan2(xk->data[xk->size[0] * k + 11], xk->data[10 +
      xk->size[0] * k]);
    dv8[2] = muDoubleScalarAtan2(xk->data[xk->size[0] * k + 12], apnd);
    for (i7 = 0; i7 < 3; i7++) {
      n = 1 + i7;
      i = 1 + i7;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, unnamed_idx_0,
                 &rf_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * k) - 1] =
        dv8[i7] + nk_data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i6,
        &qf_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    emlrtPopRtStackR2012b(&aj_emlrtRSI, emlrtRootTLSGlobal);

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
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &dd_emlrtECI,
      emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bj_emlrtRSI, emlrtRootTLSGlobal);
    b_power(*(real_T (*)[2])&rij_j_hat[0], x);
    apnd = x[0] + x[1];
    b_sqrt(&apnd);
    power(rij_j_hat, dv9);
    absb = b_sum(dv9);
    b_sqrt(&absb);
    i6 = nk->size[0];
    unnamed_idx_0 = yk->size[0];
    i = yk->size[1];
    i7 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &re_emlrtBCI, emlrtRootTLSGlobal);
    loop_ub = nk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      nk_data[i7] = nk->data[i7 + nk->size[0] * k];
    }

    dv10[0] = absb;
    dv10[1] = muDoubleScalarAtan2(rij_j_hat[1], rij_j_hat[0]);
    dv10[2] = muDoubleScalarAtan2(rij_j_hat[2], apnd);
    for (i7 = 0; i7 < 3; i7++) {
      n = 4 + i7;
      i = 4 + i7;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, unnamed_idx_0,
                 &tf_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * k) - 1] =
        dv10[i7] + nk_data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i6,
        &sf_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    emlrtPopRtStackR2012b(&bj_emlrtRSI, emlrtRootTLSGlobal);

    /*  expected magnetometer measurement */
    i6 = nk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &cd_emlrtECI,
      emlrtRootTLSGlobal);
    i6 = nk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &bd_emlrtECI,
      emlrtRootTLSGlobal);
    i6 = nk->size[0];
    loop_ub = nk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      nk_data[i7] = nk->data[i7 + nk->size[0] * k];
    }

    for (i7 = 0; i7 < 3; i7++) {
      n = 7 + i7;
      rij_j_hat[i7] = uk_data[i7 + 6] +
        nk_data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i6, &uf_emlrtBCI,
        emlrtRootTLSGlobal) - 1];
    }

    i6 = nk->size[0];
    unnamed_idx_0 = yk->size[0];
    i = yk->size[1];
    i7 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i, &qe_emlrtBCI, emlrtRootTLSGlobal);
    loop_ub = nk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      nk_data[i7] = nk->data[i7 + nk->size[0] * k];
    }

    for (i7 = 0; i7 < 3; i7++) {
      absb = 0.0;
      for (n = 0; n < 3; n++) {
        absb += Cji[i7 + 3 * n] * rij_j_hat[n];
      }

      n = 10 + i7;
      i = 7 + i7;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, unnamed_idx_0,
                 &wf_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * k) - 1] =
        absb - nk_data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i6, &vf_emlrtBCI,
        emlrtRootTLSGlobal) - 1];
    }

    /*  known feature measurements agent 1 */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, uk_data[9], mxDOUBLE_CLASS, (int32_T)
      uk_data[9], &ac_emlrtRTEI, emlrtRootTLSGlobal);
    kk = 0;
    while (kk <= (int32_T)uk_data[9] - 1) {
      /*  get the i frame vector to the feature */
      loop_ub = RKN_1->size[1];
      i6 = RKN_1->size[0];
      i7 = (int32_T)(1.0 + (real_T)kk);
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ve_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i7 = 0; i7 < loop_ub; i7++) {
        tmp_data[i7] = RKN_1->data[(i6 + RKN_1->size[0] * i7) - 1];
      }

      emlrtSizeEqCheck1DFastR2012b(loop_ub, 3, &ad_emlrtECI, emlrtRootTLSGlobal);

      /*  the index for now */
      d_y = ((1.0 + (real_T)kk) - 1.0) * 3.0;
      for (i6 = 0; i6 < 3; i6++) {
        b_index[i6] = d_y + (1.0 + (real_T)i6);
      }

      /*  compute range/bearing/declination */
      /* y_kk = [sqrt(sum(rki.^2));atan2(rki(2),rki(1));atan2(rki(3),sqrt(sum(rki(1:2).^2)))] + nv(12 + index); */
      i6 = nk->size[0];
      emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &yc_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&cj_emlrtRSI, emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        dv11[i6] = tmp_data[i6] - xk->data[i6 + xk->size[0] * k];
      }

      for (i6 = 0; i6 < 3; i6++) {
        b_Cin[i6] = 0.0;
        for (i7 = 0; i7 < 3; i7++) {
          b_Cin[i6] += Cin[i6 + 3 * i7] * dv11[i7];
        }
      }

      vector2polar(b_Cin, dv11);
      i6 = nk->size[0];
      loop_ub = nk->size[0];
      for (i7 = 0; i7 < loop_ub; i7++) {
        nk_data[i7] = nk->data[i7 + nk->size[0] * k];
      }

      for (i7 = 0; i7 < 3; i7++) {
        n = (int32_T)(12.0 + b_index[i7]);
        rij_j_hat[i7] = dv11[i7] + nk_data[emlrtDynamicBoundsCheckFastR2012b(n,
          1, i6, &yg_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      emlrtPopRtStackR2012b(&cj_emlrtRSI, emlrtRootTLSGlobal);
      unnamed_idx_0 = yk->size[0];
      i = yk->size[1];
      i6 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &pe_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        i7 = (int32_T)(9.0 + b_index[i6]);
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i7, 1, unnamed_idx_0,
                   &ah_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * k) - 1] =
          rij_j_hat[i6];
      }

      kk++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    /*  known feature measurements agent 2 */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, uk_data[(int32_T)((10.0 + y) + 1.0)
      - 1], mxDOUBLE_CLASS, (int32_T)uk_data[(int32_T)((10.0 + 3.0 * uk_data[9])
      + 1.0) - 1], &yb_emlrtRTEI, emlrtRootTLSGlobal);
    kk = 0;
    while (kk <= (int32_T)uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]
           - 1) {
      /*  get the j frame vector to the feature */
      loop_ub = RKN_2->size[1];
      i6 = RKN_2->size[0];
      i7 = (int32_T)(1.0 + (real_T)kk);
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ue_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i7 = 0; i7 < loop_ub; i7++) {
        tmp_data[i7] = RKN_2->data[(i6 + RKN_2->size[0] * i7) - 1];
      }

      emlrtSizeEqCheck1DFastR2012b(loop_ub, 3, &xc_emlrtECI, emlrtRootTLSGlobal);

      /*  the index for now */
      d_y = ((1.0 + (real_T)kk) - 1.0) * 3.0;
      e_y = uk_data[9] * 3.0;
      for (i6 = 0; i6 < 3; i6++) {
        b_index[i6] = (d_y + (1.0 + (real_T)i6)) + e_y;
      }

      /*  compute range/bearing/declination */
      /* y_kk = [sqrt(sum(rkj.^2));atan2(rkj(2),rkj(1));atan2(rkj(3),sqrt(sum(rkj(1:2).^2)))] + nv(12 + index); */
      i6 = nk->size[0];
      emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &wc_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&dj_emlrtRSI, emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        c_xk[i6] = xk->data[(i6 + xk->size[0] * k) + 10];
      }

      for (i6 = 0; i6 < 3; i6++) {
        for (i7 = 0; i7 < 3; i7++) {
          b_Cji[i6 + 3 * i7] = 0.0;
          for (n = 0; n < 3; n++) {
            b_Cji[i6 + 3 * i7] += Cji[i6 + 3 * n] * Cin[n + 3 * i7];
          }
        }
      }

      for (i6 = 0; i6 < 3; i6++) {
        absb = 0.0;
        for (i7 = 0; i7 < 3; i7++) {
          absb += Cin[i7 + 3 * i6] * c_xk[i7];
        }

        dv11[i6] = (tmp_data[i6] - absb) - xk->data[i6 + xk->size[0] * k];
      }

      for (i6 = 0; i6 < 3; i6++) {
        rij_j_hat[i6] = 0.0;
        for (i7 = 0; i7 < 3; i7++) {
          rij_j_hat[i6] += b_Cji[i6 + 3 * i7] * dv11[i7];
        }
      }

      vector2polar(rij_j_hat, dv11);
      i6 = nk->size[0];
      loop_ub = nk->size[0];
      for (i7 = 0; i7 < loop_ub; i7++) {
        nk_data[i7] = nk->data[i7 + nk->size[0] * k];
      }

      for (i7 = 0; i7 < 3; i7++) {
        absb = 12.0 + b_index[i7];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &ic_emlrtDCI,
          emlrtRootTLSGlobal);
        rij_j_hat[i7] = dv11[i7] + nk_data[emlrtDynamicBoundsCheckFastR2012b(n,
          1, i6, &wg_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      emlrtPopRtStackR2012b(&dj_emlrtRSI, emlrtRootTLSGlobal);
      unnamed_idx_0 = yk->size[0];
      i = yk->size[1];
      i6 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &oe_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        absb = 9.0 + b_index[i6];
        i7 = (int32_T)emlrtIntegerCheckFastR2012b(absb, &jc_emlrtDCI,
          emlrtRootTLSGlobal);
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i7, 1, unnamed_idx_0,
                   &xg_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * k) - 1] =
          rij_j_hat[i6];
      }

      kk++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    /*  unknown feature measurements agent 1 */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, uk_data[(int32_T)((12.0 + b_y) + c_y)
      - 1], mxDOUBLE_CLASS, (int32_T)uk_data[(int32_T)((12.0 + 3.0 * uk_data[9])
      + 3.0 * uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) - 1],
      &xb_emlrtRTEI, emlrtRootTLSGlobal);
    kk = 0;
    while (kk <= (int32_T)uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 *
            uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]) - 1] - 1) {
      /*  the index for where to store these data */
      d_y = ((1.0 + (real_T)kk) - 1.0) * 3.0;
      e_y = (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1])
        * 3.0;
      for (i6 = 0; i6 < 3; i6++) {
        b_index[i6] = (d_y + (1.0 + (real_T)i6)) + e_y;
      }

      /*  the label for this feature */
      i6 = r43->size[0] * r43->size[1];
      r43->size[0] = 1;
      r43->size[1] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)r43, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r22->size[0] * r22->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r43->data[i6] = (int32_T)((12.0 + g_y) + r22->data[i6]);
      }

      unnamed_idx_0 = r43->size[1];
      i6 = (int32_T)(1.0 + (real_T)kk);
      emlrtDynamicBoundsCheckFastR2012b(i6, 1, unnamed_idx_0, &te_emlrtBCI,
        emlrtRootTLSGlobal);
      i6 = xk->size[0];
      emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 6, &vc_emlrtECI,
        emlrtRootTLSGlobal);
      d_y = (uk_data[(int32_T)((12.0 + g_y) + r22->data[r22->size[0] * ((int32_T)
               (1.0 + (real_T)kk) - 1)]) - 1] - 1.0) * 6.0;
      i6 = xk->size[0];
      for (i7 = 0; i7 < 6; i7++) {
        absb = (17.0 + d_y) + (1.0 + (real_T)i7);
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &fc_emlrtDCI,
          emlrtRootTLSGlobal);
        emlrtDynamicBoundsCheckFastR2012b(n, 1, i6, &tg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      /* xyz,rho,bearing,azimuth */
      /*  the inertial vector to the feature, in inertial frame */
      e_y = 1.0 / xk->data[((int32_T)((17.0 + d_y) + 4.0) + xk->size[0] * k) - 1];
      apnd = muDoubleScalarCos(xk->data[((int32_T)((17.0 + d_y) + 6.0) +
        xk->size[0] * k) - 1]);

      /*  the body-frame vector to the feature */
      /*  extract range/bearing/azimuth */
      i6 = nk->size[0];
      emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &uc_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ej_emlrtRSI, emlrtRootTLSGlobal);
      loop_ub = xk->size[0];
      for (i6 = 0; i6 < 6; i6++) {
        iv52[i6] = (int32_T)((17.0 + d_y) + (1.0 + (real_T)i6));
      }

      for (i6 = 0; i6 < loop_ub; i6++) {
        nk_data[i6] = xk->data[i6 + xk->size[0] * k];
      }

      dv12[0] = muDoubleScalarCos(xk->data[((int32_T)((17.0 + d_y) + 6.0) +
        xk->size[0] * k) - 1]);
      dv12[1] = muDoubleScalarSin(xk->data[((int32_T)((17.0 + d_y) + 6.0) +
        xk->size[0] * k) - 1]);
      for (i6 = 0; i6 < 2; i6++) {
        rij_j_hat[i6] = apnd * dv12[i6];
      }

      rij_j_hat[2] = muDoubleScalarSin(xk->data[((int32_T)((17.0 + d_y) + 6.0) +
        xk->size[0] * k) - 1]);
      for (i6 = 0; i6 < 3; i6++) {
        c_xk[i6] = (nk_data[iv52[i6] - 1] + e_y * rij_j_hat[i6]) - xk->data[i6 +
          xk->size[0] * k];
      }

      for (i6 = 0; i6 < 3; i6++) {
        b_Cin[i6] = 0.0;
        for (i7 = 0; i7 < 3; i7++) {
          b_Cin[i6] += Cin[i6 + 3 * i7] * c_xk[i7];
        }
      }

      vector2polar(b_Cin, dv11);
      i6 = nk->size[0];
      loop_ub = nk->size[0];
      for (i7 = 0; i7 < loop_ub; i7++) {
        nk_data[i7] = nk->data[i7 + nk->size[0] * k];
      }

      for (i7 = 0; i7 < 3; i7++) {
        absb = 12.0 + b_index[i7];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &gc_emlrtDCI,
          emlrtRootTLSGlobal);
        rij_j_hat[i7] = dv11[i7] + nk_data[emlrtDynamicBoundsCheckFastR2012b(n,
          1, i6, &ug_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      emlrtPopRtStackR2012b(&ej_emlrtRSI, emlrtRootTLSGlobal);
      unnamed_idx_0 = yk->size[0];
      i = yk->size[1];
      i6 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &ne_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 3; i6++) {
        absb = 9.0 + b_index[i6];
        i7 = (int32_T)emlrtIntegerCheckFastR2012b(absb, &hc_emlrtDCI,
          emlrtRootTLSGlobal);
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i7, 1, unnamed_idx_0,
                   &vg_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * k) - 1] =
          rij_j_hat[i6];
      }

      kk++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    if (1 + k > 1) {
      /*  minimize all angle differences */
      emlrtPushRtStackR2012b(&fj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &me_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i7 = 0; i7 < 4; i7++) {
        n = yk->size[0];
        i = iv53[i7];
        b_xk[i7] = yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, n,
          &xf_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * (i6 - 1)) - 1];
      }

      for (i6 = 0; i6 < 4; i6++) {
        i7 = yk->size[0];
        n = iv53[i6];
        h_yk[i6] = yk->data[emlrtDynamicBoundsCheckFastR2012b(n, 1, i7,
          &yf_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      minangle(b_xk, h_yk, dv13);
      unnamed_idx_0 = yk->size[0];
      i = yk->size[1];
      i6 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i6, 1, i, &le_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i6 = 0; i6 < 4; i6++) {
        i7 = iv53[i6];
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i7, 1, unnamed_idx_0,
                   &ag_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * k) - 1] =
          dv13[i6];
      }

      emlrtPopRtStackR2012b(&fj_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (d_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == d_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((d_y - 2.0) / 3.0 + 0.5);
        e_y = ndbl * 3.0;
        cdiff = (2.0 + e_y) - d_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          d_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          d_y = 2.0 + e_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        r_y = NULL;
        m8 = mxCreateCharArray(2, iv54);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&r_y, m8);
        error(message(r_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = d_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = d_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + d_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = d_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r44->size[0] * r44->size[1];
      r44->size[0] = 1;
      r44->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r44, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = 9.0 + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &mb_emlrtDCI,
          emlrtRootTLSGlobal);
        r44->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &bg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i6 = r41->size[0];
      r41->size[0] = r44->size[1];
      emxEnsureCapacity((emxArray__common *)r41, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r44->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r41->data[i6] = (int32_T)r44->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &je_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (d_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == d_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((d_y - 2.0) / 3.0 + 0.5);
        e_y = ndbl * 3.0;
        cdiff = (2.0 + e_y) - d_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          d_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          d_y = 2.0 + e_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        s_y = NULL;
        m8 = mxCreateCharArray(2, iv55);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&s_y, m8);
        error(message(s_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = d_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = d_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + d_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = d_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (d_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == d_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((d_y - 2.0) / 3.0 + 0.5);
        e_y = ndbl * 3.0;
        cdiff = (2.0 + e_y) - d_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          d_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          d_y = 2.0 + e_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        t_y = NULL;
        m8 = mxCreateCharArray(2, iv56);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&t_y, m8);
        error(message(t_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = q_y->size[0] * q_y->size[1];
      q_y->size[0] = 1;
      q_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)q_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        q_y->data[0] = anew;
        if (n + 1 > 1) {
          q_y->data[n] = d_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            q_y->data[unnamed_idx_0] = anew + (real_T)kd;
            q_y->data[n - unnamed_idx_0] = d_y - (real_T)kd;
          }

          if (i << 1 == n) {
            q_y->data[i] = (anew + d_y) / 2.0;
          } else {
            kd = i * 3U;
            q_y->data[i] = anew + (real_T)kd;
            q_y->data[i + 1] = d_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r45->size[0] * r45->size[1];
      r45->size[0] = 1;
      r45->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r45, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = 9.0 + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &nb_emlrtDCI,
          emlrtRootTLSGlobal);
        r45->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &cg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r45->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ke_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r42->size[0];
      r42->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r42, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r42->data[i7] = yk->data[((int32_T)r45->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r46->size[0] * r46->size[1];
      r46->size[0] = 1;
      r46->size[1] = q_y->size[1];
      emxEnsureCapacity((emxArray__common *)r46, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = q_y->size[0] * q_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = 9.0 + q_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &ob_emlrtDCI,
          emlrtRootTLSGlobal);
        r46->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &dg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r46->size[1];
      i6 = g_yk->size[0];
      g_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)g_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        g_yk->data[i6] = yk->data[(int32_T)r46->data[i6] - 1];
      }

      c_minangle(r42, g_yk);
      emlrtPopRtStackR2012b(&gj_emlrtRSI, emlrtRootTLSGlobal);
      iv57[0] = r41->size[0];
      emlrtSubAssignSizeCheckR2012b(iv57, 1, *(int32_T (*)[1])r42->size, 1,
        &tc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r42->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r41->data[i6] + yk->size[0] * k] = r42->data[i6];
      }

      emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (d_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == d_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((d_y - 3.0) / 3.0 + 0.5);
        e_y = ndbl * 3.0;
        cdiff = (3.0 + e_y) - d_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          d_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          d_y = 3.0 + e_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        u_y = NULL;
        m8 = mxCreateCharArray(2, iv58);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&u_y, m8);
        error(message(u_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = d_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = d_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + d_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = d_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r47->size[0] * r47->size[1];
      r47->size[0] = 1;
      r47->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r47, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = 9.0 + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &pb_emlrtDCI,
          emlrtRootTLSGlobal);
        r47->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &eg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i6 = r41->size[0];
      r41->size[0] = r47->size[1];
      emxEnsureCapacity((emxArray__common *)r41, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r47->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r41->data[i6] = (int32_T)r47->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &he_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (d_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == d_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((d_y - 3.0) / 3.0 + 0.5);
        e_y = ndbl * 3.0;
        cdiff = (3.0 + e_y) - d_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          d_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          d_y = 3.0 + e_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        v_y = NULL;
        m8 = mxCreateCharArray(2, iv59);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&v_y, m8);
        error(message(v_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = d_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = d_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + d_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = d_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (d_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(d_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == d_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((d_y - 3.0) / 3.0 + 0.5);
        e_y = ndbl * 3.0;
        cdiff = (3.0 + e_y) - d_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * d_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          d_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          d_y = 3.0 + e_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        w_y = NULL;
        m8 = mxCreateCharArray(2, iv60);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&w_y, m8);
        error(message(w_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = q_y->size[0] * q_y->size[1];
      q_y->size[0] = 1;
      q_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)q_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        q_y->data[0] = anew;
        if (n + 1 > 1) {
          q_y->data[n] = d_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            q_y->data[unnamed_idx_0] = anew + (real_T)kd;
            q_y->data[n - unnamed_idx_0] = d_y - (real_T)kd;
          }

          if (i << 1 == n) {
            q_y->data[i] = (anew + d_y) / 2.0;
          } else {
            kd = i * 3U;
            q_y->data[i] = anew + (real_T)kd;
            q_y->data[i + 1] = d_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r48->size[0] * r48->size[1];
      r48->size[0] = 1;
      r48->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r48, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = 9.0 + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &qb_emlrtDCI,
          emlrtRootTLSGlobal);
        r48->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &fg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r48->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ie_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r42->size[0];
      r42->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r42, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r42->data[i7] = yk->data[((int32_T)r48->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r49->size[0] * r49->size[1];
      r49->size[0] = 1;
      r49->size[1] = q_y->size[1];
      emxEnsureCapacity((emxArray__common *)r49, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = q_y->size[0] * q_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = 9.0 + q_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &rb_emlrtDCI,
          emlrtRootTLSGlobal);
        r49->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &gg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r49->size[1];
      i6 = f_yk->size[0];
      f_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)f_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        f_yk->data[i6] = yk->data[(int32_T)r49->data[i6] - 1];
      }

      c_minangle(r42, f_yk);
      emlrtPopRtStackR2012b(&hj_emlrtRSI, emlrtRootTLSGlobal);
      iv61[0] = r41->size[0];
      emlrtSubAssignSizeCheckR2012b(iv61, 1, *(int32_T (*)[1])r42->size, 1,
        &sc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r42->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r41->data[i6] + yk->size[0] * k] = r42->data[i6];
      }

      emlrtPushRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      e_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
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
        apnd = ndbl * 3.0;
        cdiff = (2.0 + apnd) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 2.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        x_y = NULL;
        m8 = mxCreateCharArray(2, iv62);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&x_y, m8);
        error(message(x_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r50->size[0] * r50->size[1];
      r50->size[0] = 1;
      r50->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r50, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + d_y) + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &sb_emlrtDCI,
          emlrtRootTLSGlobal);
        r50->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &hg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i6 = r41->size[0];
      r41->size[0] = r50->size[1];
      emxEnsureCapacity((emxArray__common *)r41, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r50->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r41->data[i6] = (int32_T)r50->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &fe_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      e_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
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
        apnd = ndbl * 3.0;
        cdiff = (2.0 + apnd) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 2.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        y_y = NULL;
        m8 = mxCreateCharArray(2, iv63);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&y_y, m8);
        error(message(y_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      apnd = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(apnd)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (apnd < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(apnd)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == apnd);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((apnd - 2.0) / 3.0 + 0.5);
        absb = ndbl * 3.0;
        cdiff = (2.0 + absb) - apnd;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * apnd) {
          ndbl++;
        } else if (cdiff > 0.0) {
          apnd = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          apnd = 2.0 + absb;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        ab_y = NULL;
        m8 = mxCreateCharArray(2, iv64);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&ab_y, m8);
        error(message(ab_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = q_y->size[0] * q_y->size[1];
      q_y->size[0] = 1;
      q_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)q_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        q_y->data[0] = anew;
        if (n + 1 > 1) {
          q_y->data[n] = apnd;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            q_y->data[unnamed_idx_0] = anew + (real_T)kd;
            q_y->data[n - unnamed_idx_0] = apnd - (real_T)kd;
          }

          if (i << 1 == n) {
            q_y->data[i] = (anew + apnd) / 2.0;
          } else {
            kd = i * 3U;
            q_y->data[i] = anew + (real_T)kd;
            q_y->data[i + 1] = apnd - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r51->size[0] * r51->size[1];
      r51->size[0] = 1;
      r51->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r51, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + d_y) + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &tb_emlrtDCI,
          emlrtRootTLSGlobal);
        r51->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &ig_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r51->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ge_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r42->size[0];
      r42->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r42, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r42->data[i7] = yk->data[((int32_T)r51->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r52->size[0] * r52->size[1];
      r52->size[0] = 1;
      r52->size[1] = q_y->size[1];
      emxEnsureCapacity((emxArray__common *)r52, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = q_y->size[0] * q_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + e_y) + q_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &ub_emlrtDCI,
          emlrtRootTLSGlobal);
        r52->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &jg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r52->size[1];
      i6 = e_yk->size[0];
      e_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)e_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        e_yk->data[i6] = yk->data[(int32_T)r52->data[i6] - 1];
      }

      c_minangle(r42, e_yk);
      emlrtPopRtStackR2012b(&ij_emlrtRSI, emlrtRootTLSGlobal);
      iv65[0] = r41->size[0];
      emlrtSubAssignSizeCheckR2012b(iv65, 1, *(int32_T (*)[1])r42->size, 1,
        &rc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r42->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r41->data[i6] + yk->size[0] * k] = r42->data[i6];
      }

      emlrtPushRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      e_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
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
        apnd = ndbl * 3.0;
        cdiff = (3.0 + apnd) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 3.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        bb_y = NULL;
        m8 = mxCreateCharArray(2, iv66);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&bb_y, m8);
        error(message(bb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r53->size[0] * r53->size[1];
      r53->size[0] = 1;
      r53->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r53, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + d_y) + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &vb_emlrtDCI,
          emlrtRootTLSGlobal);
        r53->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &kg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i6 = r41->size[0];
      r41->size[0] = r53->size[1];
      emxEnsureCapacity((emxArray__common *)r41, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r53->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r41->data[i6] = (int32_T)r53->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &de_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * uk_data[9];
      e_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
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
        apnd = ndbl * 3.0;
        cdiff = (3.0 + apnd) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 3.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        cb_y = NULL;
        m8 = mxCreateCharArray(2, iv67);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&cb_y, m8);
        error(message(cb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * uk_data[9];
      apnd = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(apnd)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (apnd < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(apnd)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == apnd);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((apnd - 3.0) / 3.0 + 0.5);
        absb = ndbl * 3.0;
        cdiff = (3.0 + absb) - apnd;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * apnd) {
          ndbl++;
        } else if (cdiff > 0.0) {
          apnd = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          apnd = 3.0 + absb;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        db_y = NULL;
        m8 = mxCreateCharArray(2, iv68);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&db_y, m8);
        error(message(db_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = q_y->size[0] * q_y->size[1];
      q_y->size[0] = 1;
      q_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)q_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        q_y->data[0] = anew;
        if (n + 1 > 1) {
          q_y->data[n] = apnd;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            q_y->data[unnamed_idx_0] = anew + (real_T)kd;
            q_y->data[n - unnamed_idx_0] = apnd - (real_T)kd;
          }

          if (i << 1 == n) {
            q_y->data[i] = (anew + apnd) / 2.0;
          } else {
            kd = i * 3U;
            q_y->data[i] = anew + (real_T)kd;
            q_y->data[i + 1] = apnd - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r54->size[0] * r54->size[1];
      r54->size[0] = 1;
      r54->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r54, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + d_y) + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &wb_emlrtDCI,
          emlrtRootTLSGlobal);
        r54->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &lg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r54->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ee_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r42->size[0];
      r42->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r42, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r42->data[i7] = yk->data[((int32_T)r54->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r55->size[0] * r55->size[1];
      r55->size[0] = 1;
      r55->size[1] = q_y->size[1];
      emxEnsureCapacity((emxArray__common *)r55, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = q_y->size[0] * q_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + e_y) + q_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &xb_emlrtDCI,
          emlrtRootTLSGlobal);
        r55->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &mg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r55->size[1];
      i6 = d_yk->size[0];
      d_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)d_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        d_yk->data[i6] = yk->data[(int32_T)r55->data[i6] - 1];
      }

      c_minangle(r42, d_yk);
      emlrtPopRtStackR2012b(&jj_emlrtRSI, emlrtRootTLSGlobal);
      iv69[0] = r41->size[0];
      emlrtSubAssignSizeCheckR2012b(iv69, 1, *(int32_T (*)[1])r42->size, 1,
        &qc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r42->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r41->data[i6] + yk->size[0] * k] = r42->data[i6];
      }

      emlrtPushRtStackR2012b(&kj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      e_y = 3.0 * uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
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
        apnd = ndbl * 3.0;
        cdiff = (2.0 + apnd) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 2.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        eb_y = NULL;
        m8 = mxCreateCharArray(2, iv70);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&eb_y, m8);
        error(message(eb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r56->size[0] * r56->size[1];
      r56->size[0] = 1;
      r56->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r56, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + d_y) + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &yb_emlrtDCI,
          emlrtRootTLSGlobal);
        r56->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &ng_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i6 = r41->size[0];
      r41->size[0] = r56->size[1];
      emxEnsureCapacity((emxArray__common *)r41, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r56->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r41->data[i6] = (int32_T)r56->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&kj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &be_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&kj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      e_y = 3.0 * uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
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
        apnd = ndbl * 3.0;
        cdiff = (2.0 + apnd) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 2.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        fb_y = NULL;
        m8 = mxCreateCharArray(2, iv71);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&fb_y, m8);
        error(message(fb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      apnd = 3.0 * uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(apnd)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (apnd < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(apnd)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == apnd);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((apnd - 2.0) / 3.0 + 0.5);
        absb = ndbl * 3.0;
        cdiff = (2.0 + absb) - apnd;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * apnd) {
          ndbl++;
        } else if (cdiff > 0.0) {
          apnd = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          apnd = 2.0 + absb;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        gb_y = NULL;
        m8 = mxCreateCharArray(2, iv72);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&gb_y, m8);
        error(message(gb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = q_y->size[0] * q_y->size[1];
      q_y->size[0] = 1;
      q_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)q_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        q_y->data[0] = anew;
        if (n + 1 > 1) {
          q_y->data[n] = apnd;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            q_y->data[unnamed_idx_0] = anew + (real_T)kd;
            q_y->data[n - unnamed_idx_0] = apnd - (real_T)kd;
          }

          if (i << 1 == n) {
            q_y->data[i] = (anew + apnd) / 2.0;
          } else {
            kd = i * 3U;
            q_y->data[i] = anew + (real_T)kd;
            q_y->data[i + 1] = apnd - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r57->size[0] * r57->size[1];
      r57->size[0] = 1;
      r57->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r57, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + d_y) + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &ac_emlrtDCI,
          emlrtRootTLSGlobal);
        r57->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &og_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r57->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ce_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r42->size[0];
      r42->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r42, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r42->data[i7] = yk->data[((int32_T)r57->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r58->size[0] * r58->size[1];
      r58->size[0] = 1;
      r58->size[1] = q_y->size[1];
      emxEnsureCapacity((emxArray__common *)r58, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = q_y->size[0] * q_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + e_y) + q_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &bc_emlrtDCI,
          emlrtRootTLSGlobal);
        r58->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &pg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r58->size[1];
      i6 = c_yk->size[0];
      c_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)c_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        c_yk->data[i6] = yk->data[(int32_T)r58->data[i6] - 1];
      }

      c_minangle(r42, c_yk);
      emlrtPopRtStackR2012b(&kj_emlrtRSI, emlrtRootTLSGlobal);
      iv73[0] = r41->size[0];
      emlrtSubAssignSizeCheckR2012b(iv73, 1, *(int32_T (*)[1])r42->size, 1,
        &pc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r42->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r41->data[i6] + yk->size[0] * k] = r42->data[i6];
      }

      emlrtPushRtStackR2012b(&lj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      e_y = 3.0 * uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
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
        apnd = ndbl * 3.0;
        cdiff = (3.0 + apnd) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 3.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        hb_y = NULL;
        m8 = mxCreateCharArray(2, iv74);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&hb_y, m8);
        error(message(hb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r59->size[0] * r59->size[1];
      r59->size[0] = 1;
      r59->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r59, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + d_y) + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &cc_emlrtDCI,
          emlrtRootTLSGlobal);
        r59->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &qg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i6 = r41->size[0];
      r41->size[0] = r59->size[1];
      emxEnsureCapacity((emxArray__common *)r41, i6, (int32_T)sizeof(int32_T),
                        &cb_emlrtRTEI);
      loop_ub = r59->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        r41->data[i6] = (int32_T)r59->data[i6] - 1;
      }

      emlrtPopRtStackR2012b(&lj_emlrtRSI, emlrtRootTLSGlobal);
      i6 = yk->size[1];
      i7 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &yd_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&lj_emlrtRSI, emlrtRootTLSGlobal);
      d_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      e_y = 3.0 * uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
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
        apnd = ndbl * 3.0;
        cdiff = (3.0 + apnd) - e_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * e_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          e_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          e_y = 3.0 + apnd;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        ib_y = NULL;
        m8 = mxCreateCharArray(2, iv75);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&ib_y, m8);
        error(message(ib_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = p_y->size[0] * p_y->size[1];
      p_y->size[0] = 1;
      p_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)p_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        p_y->data[0] = anew;
        if (n + 1 > 1) {
          p_y->data[n] = e_y;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            p_y->data[unnamed_idx_0] = anew + (real_T)kd;
            p_y->data[n - unnamed_idx_0] = e_y - (real_T)kd;
          }

          if (i << 1 == n) {
            p_y->data[i] = (anew + e_y) / 2.0;
          } else {
            kd = i * 3U;
            p_y->data[i] = anew + (real_T)kd;
            p_y->data[i + 1] = e_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      e_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      apnd = 3.0 * uk_data[(int32_T)((12.0 + b_y) + c_y) - 1];
      emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(apnd)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (apnd < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(apnd)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == apnd);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((apnd - 3.0) / 3.0 + 0.5);
        absb = ndbl * 3.0;
        cdiff = (3.0 + absb) - apnd;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * apnd) {
          ndbl++;
        } else if (cdiff > 0.0) {
          apnd = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          apnd = 3.0 + absb;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        jb_y = NULL;
        m8 = mxCreateCharArray(2, iv76);
        for (i = 0; i < 21; i++) {
          cv30[i] = cv31[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv30);
        emlrtAssign(&jb_y, m8);
        error(message(jb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      i6 = q_y->size[0] * q_y->size[1];
      q_y->size[0] = 1;
      q_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)q_y, i6, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (n + 1 > 0) {
        q_y->data[0] = anew;
        if (n + 1 > 1) {
          q_y->data[n] = apnd;
          i6 = n + (n < 0);
          if (i6 >= 0) {
            i = (int32_T)((uint32_T)i6 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i6 >> 1);
          }

          emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            q_y->data[unnamed_idx_0] = anew + (real_T)kd;
            q_y->data[n - unnamed_idx_0] = apnd - (real_T)kd;
          }

          if (i << 1 == n) {
            q_y->data[i] = (anew + apnd) / 2.0;
          } else {
            kd = i * 3U;
            q_y->data[i] = anew + (real_T)kd;
            q_y->data[i + 1] = apnd - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
      i6 = r60->size[0] * r60->size[1];
      r60->size[0] = 1;
      r60->size[1] = p_y->size[1];
      emxEnsureCapacity((emxArray__common *)r60, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = p_y->size[0] * p_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + d_y) + p_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &dc_emlrtDCI,
          emlrtRootTLSGlobal);
        r60->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &rg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r60->size[1];
      i6 = yk->size[1];
      i7 = 1 + k;
      i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ae_emlrtBCI,
        emlrtRootTLSGlobal);
      i7 = r42->size[0];
      r42->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r42, i7, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i7 = 0; i7 < unnamed_idx_0; i7++) {
        r42->data[i7] = yk->data[((int32_T)r60->data[i7] + yk->size[0] * (i6 - 1))
          - 1];
      }

      i6 = r61->size[0] * r61->size[1];
      r61->size[0] = 1;
      r61->size[1] = q_y->size[1];
      emxEnsureCapacity((emxArray__common *)r61, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      loop_ub = q_y->size[0] * q_y->size[1];
      for (i6 = 0; i6 < loop_ub; i6++) {
        i7 = yk->size[0];
        absb = (9.0 + e_y) + q_y->data[i6];
        n = (int32_T)emlrtIntegerCheckFastR2012b(absb, &ec_emlrtDCI,
          emlrtRootTLSGlobal);
        r61->data[i6] = emlrtDynamicBoundsCheckFastR2012b(n, 1, i7, &sg_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r61->size[1];
      i6 = b_yk->size[0];
      b_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)b_yk, i6, (int32_T)sizeof(real_T),
                        &cb_emlrtRTEI);
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        b_yk->data[i6] = yk->data[(int32_T)r61->data[i6] - 1];
      }

      c_minangle(r42, b_yk);
      emlrtPopRtStackR2012b(&lj_emlrtRSI, emlrtRootTLSGlobal);
      iv77[0] = r41->size[0];
      emlrtSubAssignSizeCheckR2012b(iv77, 1, *(int32_T (*)[1])r42->size, 1,
        &oc_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r42->size[0];
      for (i6 = 0; i6 < loop_ub; i6++) {
        yk->data[r41->data[i6] + yk->size[0] * k] = r42->data[i6];
      }
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&r61);
  emxFree_real_T(&r60);
  emxFree_real_T(&r59);
  emxFree_real_T(&r58);
  emxFree_real_T(&r57);
  emxFree_real_T(&r56);
  emxFree_real_T(&r55);
  emxFree_real_T(&r54);
  emxFree_real_T(&r53);
  emxFree_real_T(&r52);
  emxFree_real_T(&r51);
  emxFree_real_T(&r50);
  emxFree_real_T(&r49);
  emxFree_real_T(&r48);
  emxFree_real_T(&r47);
  emxFree_real_T(&r46);
  emxFree_real_T(&r45);
  emxFree_real_T(&r44);
  emxFree_int32_T(&r43);
  emxFree_real_T(&g_yk);
  emxFree_real_T(&f_yk);
  emxFree_real_T(&e_yk);
  emxFree_real_T(&d_yk);
  emxFree_real_T(&c_yk);
  emxFree_real_T(&b_yk);
  emxFree_real_T(&q_y);
  emxFree_real_T(&p_y);
  emxFree_real_T(&r42);
  emxFree_int32_T(&r41);
  emxFree_real_T(&r22);
  emxFree_real_T(&RKN_2);
  emxFree_real_T(&RKN_1);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (measurement_eq_unknown_state.c) */
