/*
 * ukf_update_unknown_state.c
 *
 * Code generation for function 'ukf_update_unknown_state'
 *
 * C source code generated on: Thu Dec 11 11:40:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "fprintf.h"
#include "ukf_update_unknown_state_mexutil.h"
#include "norm.h"
#include "minangle.h"
#include "rdivide.h"
#include "mldivide.h"
#include "eye.h"
#include "any.h"
#include "sum.h"
#include "repmat.h"
#include "measurement_eq_unknown_state.h"
#include "update_eq_unknown_state.h"
#include "sqrtm.h"
#include "sqrt.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 93, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo b_emlrtRSI = { 25, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo c_emlrtRSI = { 30, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo d_emlrtRSI = { 31, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo e_emlrtRSI = { 35, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo f_emlrtRSI = { 37, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo g_emlrtRSI = { 53, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo h_emlrtRSI = { 63, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo i_emlrtRSI = { 75, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo j_emlrtRSI = { 79, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo k_emlrtRSI = { 92, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo l_emlrtRSI = { 99, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo m_emlrtRSI = { 104, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo n_emlrtRSI = { 110, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo o_emlrtRSI = { 111, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo p_emlrtRSI = { 112, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo q_emlrtRSI = { 113, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo r_emlrtRSI = { 114, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo s_emlrtRSI = { 115, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo t_emlrtRSI = { 116, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo u_emlrtRSI = { 117, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo v_emlrtRSI = { 118, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRSInfo w_emlrtRSI = { 124, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtMCInfo emlrtMCI = { 93, 5, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 24, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 28, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 45, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 53, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 75, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 79, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 83, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 85, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 99, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo emlrtECI = { 2, 124, 8, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo b_emlrtECI = { -1, 122, 28, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo c_emlrtECI = { -1, 122, 13, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo d_emlrtECI = { -1, 121, 26, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo e_emlrtECI = { -1, 121, 12, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo f_emlrtECI = { -1, 118, 6, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo g_emlrtECI = { -1, 118, 15, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo h_emlrtECI = { -1, 117, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo i_emlrtECI = { -1, 117, 88, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo j_emlrtECI = { -1, 117, 50, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo k_emlrtECI = { -1, 116, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo l_emlrtECI = { -1, 116, 88, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo m_emlrtECI = { -1, 116, 50, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo n_emlrtECI = { -1, 115, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo o_emlrtECI = { -1, 115, 82, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo p_emlrtECI = { -1, 115, 47, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo q_emlrtECI = { -1, 114, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo r_emlrtECI = { -1, 114, 82, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo s_emlrtECI = { -1, 114, 47, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo t_emlrtECI = { -1, 113, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo u_emlrtECI = { -1, 113, 72, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo v_emlrtECI = { -1, 113, 42, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo w_emlrtECI = { -1, 112, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo x_emlrtECI = { -1, 112, 72, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo y_emlrtECI = { -1, 112, 42, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo ab_emlrtECI = { -1, 111, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo bb_emlrtECI = { -1, 111, 60, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo cb_emlrtECI = { -1, 111, 36, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo db_emlrtECI = { -1, 110, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo eb_emlrtECI = { -1, 110, 60, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo fb_emlrtECI = { -1, 110, 36, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 109, 6, "uk", "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo emlrtDCI = { 109, 6, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 108, 6, "uk",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo gb_emlrtECI = { -1, 106, 29, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo hb_emlrtECI = { -1, 106, 13, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo ib_emlrtECI = { -1, 104, 44, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo jb_emlrtECI = { -1, 104, 28, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo kb_emlrtECI = { 2, 88, 13, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo lb_emlrtECI = { -1, 88, 49, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo c_emlrtBCI = { -1, -1, 88, 57, "YKAUG",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo mb_emlrtECI = { -1, 88, 28, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 88, 41, "XAUGPLUS",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 88, 37, "XAUGPLUS",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 88, 21, "wc",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo nb_emlrtECI = { 2, 87, 11, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo ob_emlrtECI = { -1, 87, 42, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo g_emlrtBCI = { -1, -1, 87, 50, "YKAUG",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo pb_emlrtECI = { -1, 87, 24, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo h_emlrtBCI = { -1, -1, 87, 32, "YKAUG",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 87, 17, "wc",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo qb_emlrtECI = { 2, 79, 12, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo j_emlrtBCI = { -1, -1, 75, 47, "XAUGPLUS",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo rb_emlrtECI = { 2, 71, 10, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo sb_emlrtECI = { -1, 71, 43, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo k_emlrtBCI = { -1, -1, 71, 56, "XAUGPLUS",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 71, 52, "XAUGPLUS",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo tb_emlrtECI = { -1, 71, 22, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo m_emlrtBCI = { -1, -1, 71, 35, "XAUGPLUS",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 71, 31, "XAUGPLUS",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 71, 15, "wc",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo ub_emlrtECI = { -1, 67, 28, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo vb_emlrtECI = { -1, 67, 13, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo wb_emlrtECI = { -1, 66, 26, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo xb_emlrtECI = { -1, 66, 12, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo yb_emlrtECI = { 2, 63, 10, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo p_emlrtBCI = { -1, -1, 63, 19, "XAUGPLUS",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 53, 41, "XAUG",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo ac_emlrtECI = { -1, 49, 5, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo r_emlrtBCI = { -1, -1, 49, 12, "XAUG",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo bc_emlrtECI = { -1, 48, 5, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo s_emlrtBCI = { -1, -1, 48, 12, "XAUG",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo cc_emlrtECI = { -1, 46, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo dc_emlrtECI = { -1, 49, 21, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo t_emlrtBCI = { -1, -1, 49, 39, "Psq",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo ec_emlrtECI = { -1, 48, 19, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo u_emlrtBCI = { -1, -1, 48, 37, "Psq",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtECInfo fc_emlrtECI = { -1, 31, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo gc_emlrtECI = { -1, 30, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtECInfo hc_emlrtECI = { -1, 29, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m"
};

static emlrtBCInfo v_emlrtBCI = { -1, -1, 29, 10, "Paug",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 29, 6, "Paug",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 17, 6, "uk",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 17, 6, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 16, 6, "uk",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo c_emlrtDCI = { 16, 6, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 15, 6, "uk",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo d_emlrtDCI = { 15, 6, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 14, 6, "uk",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 30, 6, "Paug",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo e_emlrtDCI = { 30, 6, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 30, 15, "Paug",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo f_emlrtDCI = { 30, 15, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 31, 6, "Paug",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo g_emlrtDCI = { 31, 6, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 31, 18, "Paug",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo h_emlrtDCI = { 31, 18, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 53, 53, "XAUG",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo i_emlrtDCI = { 53, 53, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 66, 12, "xp",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 66, 26, "xp",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 66, 1, "xp",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 67, 13, "xp",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 67, 28, "xp",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 67, 1, "xp",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 75, 59, "XAUG",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo j_emlrtDCI = { 75, 59, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 104, 28, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 104, 44, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 104, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 106, 29, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 106, 13, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 106, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 110, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo k_emlrtDCI = { 110, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 110, 36, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo l_emlrtDCI = { 110, 36, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 110, 60, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo m_emlrtDCI = { 110, 60, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 111, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo n_emlrtDCI = { 111, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 111, 36, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo o_emlrtDCI = { 111, 36, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 111, 60, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo p_emlrtDCI = { 111, 60, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 112, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo q_emlrtDCI = { 112, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 112, 42, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo r_emlrtDCI = { 112, 42, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 112, 72, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo s_emlrtDCI = { 112, 72, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 113, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo t_emlrtDCI = { 113, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 113, 42, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo u_emlrtDCI = { 113, 42, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 113, 72, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo v_emlrtDCI = { 113, 72, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 114, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo w_emlrtDCI = { 114, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 114, 47, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo x_emlrtDCI = { 114, 47, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 114, 82, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo y_emlrtDCI = { 114, 82, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 115, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo ab_emlrtDCI = { 115, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 115, 47, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo bb_emlrtDCI = { 115, 47, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 115, 82, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo cb_emlrtDCI = { 115, 82, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 116, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo db_emlrtDCI = { 116, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 116, 50, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo eb_emlrtDCI = { 116, 50, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 116, 88, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo fb_emlrtDCI = { 116, 88, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 117, 1, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo gb_emlrtDCI = { 117, 1, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 117, 50, "yhat",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo hb_emlrtDCI = { 117, 50, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 117, 88, "ytilde",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtDCInfo ib_emlrtDCI = { 117, 88, "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  1 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 121, 12, "xn",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 121, 26, "xn",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 121, 1, "xn",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 122, 13, "xn",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 122, 28, "xn",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 122, 1, "xn",
  "ukf_update_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m",
  0 };

/* Function Definitions */
void ukf_update_unknown_state(const real_T xk_data[200], const int32_T xk_size[1],
  const emxArray_real_T *Pxk, const emxArray_real_T *Pvk, const emxArray_real_T *
  Pnk, const real_T uk_data[100], const int32_T uk_size[1], const real_T
  ytilde_data[200], const int32_T ytilde_size[1], real_T alpha, real_T
  xnew_data[200], int32_T xnew_size[1], emxArray_real_T *Pnew)
{
  emxArray_real_T *Paug;
  int32_T N;
  real_T y;
  real_T b_y;
  int32_T i0;
  real_T c_y;
  real_T d_y;
  real_T e_y;
  real_T lambda;
  real_T gamm;
  int32_T loop_ub;
  int32_T cdiff;
  int32_T tmp_data[200];
  int32_T b_tmp_data[200];
  int32_T iv0[2];
  int32_T apnd;
  int32_T ndbl;
  int32_T absb;
  emxArray_real_T *f_y;
  int32_T k;
  int32_T c_tmp_data[100];
  int32_T tmp_size_idx_1;
  int32_T d_tmp_data[100];
  int32_T e_tmp_data[100];
  int32_T XAUGPLUS[2];
  int32_T f_tmp_data[200];
  int32_T b_Pnew[2];
  int32_T xaug_size[1];
  real_T xaug_data[500];
  emxArray_creal_T *Psq;
  real_T b_ndbl;
  emxArray_real_T *XAUG;
  int32_T g_y;
  int32_T g_tmp_data[500];
  int32_T iv1[1];
  emxArray_real_T *h_y;
  int32_T iv2[1];
  int32_T iv3[1];
  emxArray_real_T *b_XAUG;
  emxArray_real_T *c_XAUG;
  emxArray_real_T *b_XAUGPLUS;
  real_T i_y;
  real_T wc_data[1001];
  real_T wm_data[1001];
  real_T b_wm_data[1001];
  int32_T wm_size[2];
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  emxArray_real_T *c_XAUGPLUS;
  emxArray_real_T *d_XAUGPLUS;
  emxArray_real_T *r2;
  real_T xnew[4];
  emxArray_real_T *b;
  emxArray_real_T *wc;
  emxArray_real_T *e_XAUGPLUS;
  emxArray_real_T *f_XAUGPLUS;
  emxArray_real_T *d_XAUG;
  emxArray_real_T *YKAUG;
  int32_T b_wm_size[2];
  emxArray_real_T *b_YKAUG;
  emxArray_real_T *yhat;
  emxArray_real_T *Pyk;
  emxArray_real_T *Pxkyk;
  emxArray_real_T *b_wc;
  emxArray_real_T *c_YKAUG;
  emxArray_real_T *c_wc;
  emxArray_real_T *d_YKAUG;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r4;
  boolean_T n_too_large;
  const mxArray *j_y;
  static const int32_T iv4[2] = { 1, 31 };

  const mxArray *m0;
  char_T cv0[31];
  static const char_T cv1[31] = { 'S', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ',
    'm', 'e', 'a', 's', 'u', 'r', 'e', 'm', 'e', 'n', 't', ' ', 'c', 'o', 'v',
    'a', 'r', 'i', 'a', 'n', 'c', 'e' };

  emxArray_real_T *b_b;
  const mxArray *k_y;
  static const int32_T iv5[2] = { 1, 45 };

  char_T cv2[45];
  static const char_T cv3[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D',
    'y', 'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p',
    'a', 'n', 's', 'i', 'o', 'n' };

  const mxArray *l_y;
  static const int32_T iv6[2] = { 1, 21 };

  char_T cv4[21];
  static const char_T cv5[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  emxArray_real_T *Kk;
  emxArray_real_T *r5;
  uint32_T kd;
  uint32_T unnamed_idx_1;
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  double * alpha1_t;
  double * Aia0_t;
  double * Bib0_t;
  double * beta1_t;
  double * Cic0_t;
  static const int8_T iv7[4] = { 2, 3, 5, 6 };

  real_T ytilde[4];
  real_T b_yhat[3];
  real_T c_yhat[3];
  real_T dv0[3];
  real_T m_y;
  real_T n_y;
  const mxArray *o_y;
  static const int32_T iv8[2] = { 1, 21 };

  static const char_T cv6[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *r6;
  const mxArray *p_y;
  static const int32_T iv9[2] = { 1, 21 };

  emxArray_real_T *r7;
  const mxArray *q_y;
  static const int32_T iv10[2] = { 1, 21 };

  emxArray_int32_T *r8;
  emxArray_int32_T *r9;
  emxArray_real_T *b_ytilde;
  emxArray_int32_T *r10;
  const mxArray *r_y;
  static const int32_T iv11[2] = { 1, 21 };

  const mxArray *s_y;
  static const int32_T iv12[2] = { 1, 21 };

  const mxArray *t_y;
  static const int32_T iv13[2] = { 1, 21 };

  emxArray_int32_T *r11;
  emxArray_real_T *c_ytilde;
  emxArray_int32_T *r12;
  const mxArray *u_y;
  static const int32_T iv14[2] = { 1, 21 };

  const mxArray *v_y;
  static const int32_T iv15[2] = { 1, 21 };

  const mxArray *w_y;
  static const int32_T iv16[2] = { 1, 21 };

  emxArray_int32_T *r13;
  emxArray_real_T *d_ytilde;
  emxArray_int32_T *r14;
  const mxArray *x_y;
  static const int32_T iv17[2] = { 1, 21 };

  const mxArray *y_y;
  static const int32_T iv18[2] = { 1, 21 };

  const mxArray *ab_y;
  static const int32_T iv19[2] = { 1, 21 };

  emxArray_int32_T *r15;
  emxArray_real_T *e_ytilde;
  emxArray_int32_T *r16;
  const mxArray *bb_y;
  static const int32_T iv20[2] = { 1, 21 };

  const mxArray *cb_y;
  static const int32_T iv21[2] = { 1, 21 };

  const mxArray *db_y;
  static const int32_T iv22[2] = { 1, 21 };

  emxArray_int32_T *r17;
  emxArray_real_T *f_ytilde;
  emxArray_int32_T *r18;
  const mxArray *eb_y;
  static const int32_T iv23[2] = { 1, 21 };

  const mxArray *fb_y;
  static const int32_T iv24[2] = { 1, 21 };

  const mxArray *gb_y;
  static const int32_T iv25[2] = { 1, 21 };

  emxArray_int32_T *r19;
  emxArray_real_T *g_ytilde;
  emxArray_int32_T *r20;
  const mxArray *hb_y;
  static const int32_T iv26[2] = { 1, 21 };

  const mxArray *ib_y;
  static const int32_T iv27[2] = { 1, 21 };

  const mxArray *jb_y;
  static const int32_T iv28[2] = { 1, 21 };

  emxArray_int32_T *r21;
  emxArray_real_T *h_ytilde;
  emxArray_int32_T *r22;
  const mxArray *kb_y;
  static const int32_T iv29[2] = { 1, 21 };

  const mxArray *lb_y;
  static const int32_T iv30[2] = { 1, 21 };

  const mxArray *mb_y;
  static const int32_T iv31[2] = { 1, 21 };

  emxArray_int32_T *r23;
  emxArray_real_T *i_ytilde;
  emxArray_int32_T *r24;
  real_T b_data[200];
  const mxArray *nb_y;
  static const int32_T iv32[2] = { 1, 45 };

  const mxArray *ob_y;
  static const int32_T iv33[2] = { 1, 21 };

  real_T C_data[200];
  const mxArray *pb_y;
  static const int32_T iv34[2] = { 1, 45 };

  const mxArray *qb_y;
  static const int32_T iv35[2] = { 1, 21 };

  emxArray_real_T *rb_y;
  const mxArray *sb_y;
  static const int32_T iv36[2] = { 1, 45 };

  const mxArray *tb_y;
  static const int32_T iv37[2] = { 1, 21 };

  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&Paug, 2, &c_emlrtRTEI, TRUE);

  /*  Pxk: covariance associated with state */
  /*  Pvk: covariance associated with process noise */
  /*  Pnk: covariance assocaited with measurement noise */
  /*  vector lengths */
  N = (xk_size[0] + Pnk->size[0]) + Pvk->size[0];

  /*  number of known features seen by agents i and j (1 and 2) */
  emlrtDynamicBoundsCheckFastR2012b(10, 1, uk_size[0], &bb_emlrtBCI,
    emlrtRootTLSGlobal);
  y = 3.0 * uk_data[9];
  b_y = 11.0 + 3.0 * uk_data[9];
  i0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &d_emlrtDCI, emlrtRootTLSGlobal);
  emlrtDynamicBoundsCheckFastR2012b(i0, 1, uk_size[0], &ab_emlrtBCI,
    emlrtRootTLSGlobal);
  c_y = 3.0 * uk_data[9];
  d_y = 3.0 * uk_data[(int32_T)(11.0 + y) - 1];
  b_y = (12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)(11.0 + 3.0 *
    uk_data[9]) - 1];
  i0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &c_emlrtDCI, emlrtRootTLSGlobal);
  emlrtDynamicBoundsCheckFastR2012b(i0, 1, uk_size[0], &y_emlrtBCI,
    emlrtRootTLSGlobal);
  e_y = 3.0 * uk_data[9];
  y = 3.0 * uk_data[(int32_T)(11.0 + y) - 1];
  b_y = (((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)(11.0 + 3.0 *
           uk_data[9]) - 1]) + uk_data[(int32_T)((12.0 + c_y) + d_y) - 1]) + 1.0;
  i0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &b_emlrtDCI, emlrtRootTLSGlobal);
  emlrtDynamicBoundsCheckFastR2012b(i0, 1, uk_size[0], &x_emlrtBCI,
    emlrtRootTLSGlobal);

  /*  constant gamma that influences sigma points */
  lambda = alpha * alpha * (real_T)N - (real_T)N;
  emlrtPushRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
  gamm = (real_T)N + lambda;
  b_sqrt(&gamm);
  emlrtPopRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);

  /* augmented covariance and state */
  i0 = Paug->size[0] * Paug->size[1];
  Paug->size[0] = N;
  Paug->size[1] = N;
  emxEnsureCapacity((emxArray__common *)Paug, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = N * N;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Paug->data[i0] = 0.0;
  }

  if (1 > xk_size[0]) {
    loop_ub = 0;
  } else {
    emlrtDynamicBoundsCheckFastR2012b(1, 1, N, &w_emlrtBCI, emlrtRootTLSGlobal);
    loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, N, &w_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  if (1 > xk_size[0]) {
    cdiff = 0;
  } else {
    emlrtDynamicBoundsCheckFastR2012b(1, 1, N, &v_emlrtBCI, emlrtRootTLSGlobal);
    cdiff = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, N, &v_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < loop_ub; i0++) {
    tmp_data[i0] = i0;
  }

  for (i0 = 0; i0 < cdiff; i0++) {
    b_tmp_data[i0] = i0;
  }

  iv0[0] = loop_ub;
  iv0[1] = cdiff;
  emlrtSubAssignSizeCheckR2012b(iv0, 2, *(int32_T (*)[2])Pxk->size, 2,
    &hc_emlrtECI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < cdiff; i0++) {
    for (apnd = 0; apnd < loop_ub; apnd++) {
      Paug->data[tmp_data[apnd] + Paug->size[0] * b_tmp_data[i0]] = Pxk->
        data[apnd + loop_ub * i0];
    }
  }

  emlrtPushRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  if (Pvk->size[0] < 1) {
    cdiff = -1;
    apnd = 0;
  } else {
    ndbl = (int32_T)muDoubleScalarFloor(((real_T)Pvk->size[0] - 1.0) + 0.5);
    apnd = ndbl + 1;
    cdiff = (ndbl - Pvk->size[0]) + 1;
    absb = Pvk->size[0];
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)absb) {
      ndbl++;
      apnd = Pvk->size[0];
    } else if (cdiff > 0) {
      apnd = ndbl;
    } else {
      ndbl++;
    }

    cdiff = ndbl - 1;
  }

  emxInit_real_T(&f_y, 2, &emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  i0 = f_y->size[0] * f_y->size[1];
  f_y->size[0] = 1;
  f_y->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (cdiff + 1 > 0) {
    f_y->data[0] = 1.0;
    if (cdiff + 1 > 1) {
      f_y->data[cdiff] = apnd;
      i0 = cdiff + (cdiff < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 1; k < ndbl; k++) {
        f_y->data[k] = 1.0 + (real_T)k;
        f_y->data[cdiff - k] = apnd - k;
      }

      if (ndbl << 1 == cdiff) {
        f_y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        f_y->data[ndbl] = 1.0 + (real_T)ndbl;
        f_y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  tmp_size_idx_1 = f_y->size[1];
  loop_ub = f_y->size[0] * f_y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    apnd = Paug->size[0];
    b_y = (real_T)xk_size[0] + f_y->data[i0];
    absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &e_emlrtDCI,
      emlrtRootTLSGlobal);
    c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
      &cb_emlrtBCI, emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < tmp_size_idx_1; i0++) {
    d_tmp_data[i0] = c_tmp_data[i0] - 1;
  }

  emlrtPopRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  if (Pvk->size[0] < 1) {
    cdiff = -1;
    apnd = 0;
  } else {
    ndbl = (int32_T)muDoubleScalarFloor(((real_T)Pvk->size[0] - 1.0) + 0.5);
    apnd = ndbl + 1;
    cdiff = (ndbl - Pvk->size[0]) + 1;
    absb = Pvk->size[0];
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)absb) {
      ndbl++;
      apnd = Pvk->size[0];
    } else if (cdiff > 0) {
      apnd = ndbl;
    } else {
      ndbl++;
    }

    cdiff = ndbl - 1;
  }

  emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  i0 = f_y->size[0] * f_y->size[1];
  f_y->size[0] = 1;
  f_y->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (cdiff + 1 > 0) {
    f_y->data[0] = 1.0;
    if (cdiff + 1 > 1) {
      f_y->data[cdiff] = apnd;
      i0 = cdiff + (cdiff < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 1; k < ndbl; k++) {
        f_y->data[k] = 1.0 + (real_T)k;
        f_y->data[cdiff - k] = apnd - k;
      }

      if (ndbl << 1 == cdiff) {
        f_y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        f_y->data[ndbl] = 1.0 + (real_T)ndbl;
        f_y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  ndbl = f_y->size[1];
  loop_ub = f_y->size[0] * f_y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    apnd = Paug->size[1];
    b_y = (real_T)xk_size[0] + f_y->data[i0];
    absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &f_emlrtDCI,
      emlrtRootTLSGlobal);
    c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
      &db_emlrtBCI, emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < ndbl; i0++) {
    e_tmp_data[i0] = c_tmp_data[i0] - 1;
  }

  emlrtPopRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  XAUGPLUS[0] = tmp_size_idx_1;
  XAUGPLUS[1] = ndbl;
  emlrtSubAssignSizeCheckR2012b(XAUGPLUS, 2, *(int32_T (*)[2])Pvk->size, 2,
    &gc_emlrtECI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < ndbl; i0++) {
    for (apnd = 0; apnd < tmp_size_idx_1; apnd++) {
      Paug->data[d_tmp_data[apnd] + Paug->size[0] * e_tmp_data[i0]] = Pvk->
        data[apnd + tmp_size_idx_1 * i0];
    }
  }

  emlrtPushRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  if (Pnk->size[0] < 1) {
    cdiff = -1;
    apnd = 0;
  } else {
    ndbl = (int32_T)muDoubleScalarFloor(((real_T)Pnk->size[0] - 1.0) + 0.5);
    apnd = ndbl + 1;
    cdiff = (ndbl - Pnk->size[0]) + 1;
    absb = Pnk->size[0];
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)absb) {
      ndbl++;
      apnd = Pnk->size[0];
    } else if (cdiff > 0) {
      apnd = ndbl;
    } else {
      ndbl++;
    }

    cdiff = ndbl - 1;
  }

  emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  i0 = f_y->size[0] * f_y->size[1];
  f_y->size[0] = 1;
  f_y->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (cdiff + 1 > 0) {
    f_y->data[0] = 1.0;
    if (cdiff + 1 > 1) {
      f_y->data[cdiff] = apnd;
      i0 = cdiff + (cdiff < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 1; k < ndbl; k++) {
        f_y->data[k] = 1.0 + (real_T)k;
        f_y->data[cdiff - k] = apnd - k;
      }

      if (ndbl << 1 == cdiff) {
        f_y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        f_y->data[ndbl] = 1.0 + (real_T)ndbl;
        f_y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  tmp_size_idx_1 = f_y->size[1];
  cdiff = (int16_T)((int16_T)xk_size[0] + (int16_T)Pvk->size[0]);
  loop_ub = f_y->size[0] * f_y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    apnd = Paug->size[0];
    b_y = (real_T)cdiff + f_y->data[i0];
    absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &g_emlrtDCI,
      emlrtRootTLSGlobal);
    f_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
      &eb_emlrtBCI, emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < tmp_size_idx_1; i0++) {
    tmp_data[i0] = f_tmp_data[i0] - 1;
  }

  emlrtPopRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  if (Pnk->size[0] < 1) {
    cdiff = -1;
    apnd = 0;
  } else {
    ndbl = (int32_T)muDoubleScalarFloor(((real_T)Pnk->size[0] - 1.0) + 0.5);
    apnd = ndbl + 1;
    cdiff = (ndbl - Pnk->size[0]) + 1;
    absb = Pnk->size[0];
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)absb) {
      ndbl++;
      apnd = Pnk->size[0];
    } else if (cdiff > 0) {
      apnd = ndbl;
    } else {
      ndbl++;
    }

    cdiff = ndbl - 1;
  }

  emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  i0 = f_y->size[0] * f_y->size[1];
  f_y->size[0] = 1;
  f_y->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (cdiff + 1 > 0) {
    f_y->data[0] = 1.0;
    if (cdiff + 1 > 1) {
      f_y->data[cdiff] = apnd;
      i0 = cdiff + (cdiff < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 1; k < ndbl; k++) {
        f_y->data[k] = 1.0 + (real_T)k;
        f_y->data[cdiff - k] = apnd - k;
      }

      if (ndbl << 1 == cdiff) {
        f_y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        f_y->data[ndbl] = 1.0 + (real_T)ndbl;
        f_y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  ndbl = f_y->size[1];
  cdiff = (int16_T)((int16_T)xk_size[0] + (int16_T)Pvk->size[0]);
  loop_ub = f_y->size[0] * f_y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    apnd = Paug->size[1];
    b_y = (real_T)cdiff + f_y->data[i0];
    absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &h_emlrtDCI,
      emlrtRootTLSGlobal);
    f_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
      &fb_emlrtBCI, emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < ndbl; i0++) {
    b_tmp_data[i0] = f_tmp_data[i0] - 1;
  }

  emlrtPopRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  b_Pnew[0] = tmp_size_idx_1;
  b_Pnew[1] = ndbl;
  emlrtSubAssignSizeCheckR2012b(b_Pnew, 2, *(int32_T (*)[2])Pnk->size, 2,
    &fc_emlrtECI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < ndbl; i0++) {
    for (apnd = 0; apnd < tmp_size_idx_1; apnd++) {
      Paug->data[tmp_data[apnd] + Paug->size[0] * b_tmp_data[i0]] = Pnk->
        data[apnd + tmp_size_idx_1 * i0];
    }
  }

  xaug_size[0] = (xk_size[0] + Pnk->size[0]) + Pvk->size[0];
  loop_ub = xk_size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    xaug_data[i0] = xk_data[i0];
  }

  loop_ub = Pnk->size[0] + Pvk->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    xaug_data[i0 + xk_size[0]] = 0.0;
  }

  emxInit_creal_T(&Psq, 2, &emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
  sqrtm(Paug, Psq, &b_ndbl);
  emlrtPopRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
  if (muDoubleScalarAbs(b_ndbl) > 1.0E-14) {
    emlrtPushRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
    b_fprintf(b_ndbl);
    emlrtPopRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
    xnew_size[0] = 1;
    xnew_data[0] = 0.0;
    i0 = Pnew->size[0] * Pnew->size[1];
    Pnew->size[0] = 1;
    Pnew->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)Pnew, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    Pnew->data[0] = 0.0;
  } else {
    i0 = Paug->size[0] * Paug->size[1];
    Paug->size[0] = Psq->size[0];
    Paug->size[1] = Psq->size[1];
    emxEnsureCapacity((emxArray__common *)Paug, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = Psq->size[0] * Psq->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      Paug->data[i0] = Psq->data[i0].re;
    }

    emxInit_real_T(&XAUG, 2, &d_emlrtRTEI, TRUE);

    /*  compute the sigma points */
    g_y = (N << 1) + 1;
    i0 = XAUG->size[0] * XAUG->size[1];
    XAUG->size[0] = N;
    XAUG->size[1] = g_y;
    emxEnsureCapacity((emxArray__common *)XAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = N * g_y;
    for (i0 = 0; i0 < loop_ub; i0++) {
      XAUG->data[i0] = 0.0;
    }

    for (i0 = 0; i0 < N; i0++) {
      g_tmp_data[i0] = i0;
    }

    iv1[0] = N;
    emlrtSubAssignSizeCheckR2012b(iv1, 1, xaug_size, 1, &cc_emlrtECI,
      emlrtRootTLSGlobal);
    loop_ub = xaug_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      XAUG->data[g_tmp_data[i0]] = xaug_data[i0];
    }

    k = 0;
    b_emxInit_real_T(&h_y, 1, &emlrtRTEI, TRUE);
    while (k <= N - 1) {
      i0 = Paug->size[1];
      apnd = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(apnd, 1, i0, &u_emlrtBCI,
        emlrtRootTLSGlobal);
      loop_ub = Paug->size[0];
      i0 = h_y->size[0];
      h_y->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)h_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < loop_ub; i0++) {
        h_y->data[i0] = gamm * Paug->data[i0 + Paug->size[0] * k];
      }

      i0 = h_y->size[0];
      emlrtSizeEqCheck1DFastR2012b(xaug_size[0], i0, &ec_emlrtECI,
        emlrtRootTLSGlobal);
      loop_ub = XAUG->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        g_tmp_data[i0] = i0;
      }

      i0 = XAUG->size[1];
      apnd = (int32_T)((1.0 + (real_T)k) + 1.0);
      emlrtDynamicBoundsCheckFastR2012b(apnd, 1, i0, &s_emlrtBCI,
        emlrtRootTLSGlobal);
      iv2[0] = loop_ub;
      emlrtSubAssignSizeCheckR2012b(iv2, 1, xaug_size, 1, &bc_emlrtECI,
        emlrtRootTLSGlobal);
      loop_ub = xaug_size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        XAUG->data[g_tmp_data[i0] + XAUG->size[0] * (k + 1)] = xaug_data[i0] +
          h_y->data[i0];
      }

      i0 = Paug->size[1];
      apnd = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(apnd, 1, i0, &t_emlrtBCI,
        emlrtRootTLSGlobal);
      loop_ub = Paug->size[0];
      i0 = h_y->size[0];
      h_y->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)h_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < loop_ub; i0++) {
        h_y->data[i0] = gamm * Paug->data[i0 + Paug->size[0] * k];
      }

      i0 = h_y->size[0];
      emlrtSizeEqCheck1DFastR2012b(xaug_size[0], i0, &dc_emlrtECI,
        emlrtRootTLSGlobal);
      loop_ub = XAUG->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        g_tmp_data[i0] = i0;
      }

      i0 = XAUG->size[1];
      apnd = (N + k) + 2;
      i0 = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, i0, &r_emlrtBCI,
        emlrtRootTLSGlobal) - 1;
      iv3[0] = loop_ub;
      emlrtSubAssignSizeCheckR2012b(iv3, 1, xaug_size, 1, &ac_emlrtECI,
        emlrtRootTLSGlobal);
      loop_ub = xaug_size[0];
      for (apnd = 0; apnd < loop_ub; apnd++) {
        XAUG->data[g_tmp_data[apnd] + XAUG->size[0] * i0] = xaug_data[apnd] -
          h_y->data[apnd];
      }

      k++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    /*  propagate the sigma points */
    if (1 > xk_size[0]) {
      loop_ub = 0;
    } else {
      i0 = XAUG->size[0];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &q_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = XAUG->size[0];
      loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i0, &q_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    emlrtPushRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    if (Pvk->size[0] < 1) {
      cdiff = -1;
      apnd = 0;
    } else {
      ndbl = (int32_T)muDoubleScalarFloor(((real_T)Pvk->size[0] - 1.0) + 0.5);
      apnd = ndbl + 1;
      cdiff = (ndbl - Pvk->size[0]) + 1;
      absb = Pvk->size[0];
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)absb) {
        ndbl++;
        apnd = Pvk->size[0];
      } else if (cdiff > 0) {
        apnd = ndbl;
      } else {
        ndbl++;
      }

      cdiff = ndbl - 1;
    }

    emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    i0 = f_y->size[0] * f_y->size[1];
    f_y->size[0] = 1;
    f_y->size[1] = cdiff + 1;
    emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (cdiff + 1 > 0) {
      f_y->data[0] = 1.0;
      if (cdiff + 1 > 1) {
        f_y->data[cdiff] = apnd;
        i0 = cdiff + (cdiff < 0);
        if (i0 >= 0) {
          ndbl = (int32_T)((uint32_T)i0 >> 1);
        } else {
          ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
        }

        emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k < ndbl; k++) {
          f_y->data[k] = 1.0 + (real_T)k;
          f_y->data[cdiff - k] = apnd - k;
        }

        if (ndbl << 1 == cdiff) {
          f_y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
        } else {
          f_y->data[ndbl] = 1.0 + (real_T)ndbl;
          f_y->data[ndbl + 1] = apnd - ndbl;
        }
      }
    }

    emxInit_real_T(&b_XAUG, 2, &emlrtRTEI, TRUE);
    emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    cdiff = XAUG->size[1];
    i0 = b_XAUG->size[0] * b_XAUG->size[1];
    b_XAUG->size[0] = loop_ub;
    b_XAUG->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)b_XAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < cdiff; i0++) {
      for (apnd = 0; apnd < loop_ub; apnd++) {
        b_XAUG->data[apnd + b_XAUG->size[0] * i0] = XAUG->data[apnd + XAUG->
          size[0] * i0];
      }
    }

    emxInit_real_T(&c_XAUG, 2, &emlrtRTEI, TRUE);
    tmp_size_idx_1 = f_y->size[1];
    loop_ub = f_y->size[0] * f_y->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = XAUG->size[0];
      b_y = (real_T)xk_size[0] + f_y->data[i0];
      absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &i_emlrtDCI,
        emlrtRootTLSGlobal);
      c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
        &gb_emlrtBCI, emlrtRootTLSGlobal);
    }

    loop_ub = XAUG->size[1];
    i0 = c_XAUG->size[0] * c_XAUG->size[1];
    c_XAUG->size[0] = tmp_size_idx_1;
    c_XAUG->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)c_XAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (apnd = 0; apnd < tmp_size_idx_1; apnd++) {
        c_XAUG->data[apnd + c_XAUG->size[0] * i0] = XAUG->data[(c_tmp_data[apnd]
          + XAUG->size[0] * i0) - 1];
      }
    }

    emxInit_real_T(&b_XAUGPLUS, 2, &e_emlrtRTEI, TRUE);
    update_eq_unknown_state(b_XAUG, c_XAUG, uk_data, uk_size, b_XAUGPLUS);
    emlrtPopRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);

    /*  weights */
    /*  optimal for Gaussian */
    i_y = 0.5 / ((real_T)N + lambda);
    g_y = N << 1;
    i0 = h_y->size[0];
    h_y->size[0] = g_y + 1;
    emxEnsureCapacity((emxArray__common *)h_y, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    emxFree_real_T(&c_XAUG);
    emxFree_real_T(&b_XAUG);
    for (i0 = 0; i0 <= g_y; i0++) {
      h_y->data[i0] = i_y;
    }

    for (i0 = 0; i0 <= g_y; i0++) {
      wc_data[i0] = i_y;
    }

    i_y = 0.5 / ((real_T)N + lambda);
    g_y = N << 1;
    for (i0 = 0; i0 <= g_y; i0++) {
      wm_data[i0] = i_y;
    }

    wm_data[0] = lambda / ((real_T)N + lambda);
    wc_data[0] = ((lambda / ((real_T)N + lambda) + 1.0) - alpha * alpha) + 2.0;

    /*  calculate the update */
    if (1 > xk_size[0]) {
      loop_ub = 0;
    } else {
      i0 = b_XAUGPLUS->size[0];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &p_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = b_XAUGPLUS->size[0];
      loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i0, &p_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    emlrtPushRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
    wm_size[0] = 1;
    wm_size[1] = g_y + 1;
    cdiff = g_y + 1;
    for (i0 = 0; i0 < cdiff; i0++) {
      b_wm_data[i0] = wm_data[i0];
    }

    emxInit_real_T(&r0, 2, &emlrtRTEI, TRUE);
    emxInit_real_T(&r1, 2, &emlrtRTEI, TRUE);
    repmat(b_wm_data, wm_size, xk_size[0], r1);
    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = r1->size[0];
    r0->size[1] = r1->size[1];
    emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    cdiff = r1->size[0] * r1->size[1];
    for (i0 = 0; i0 < cdiff; i0++) {
      r0->data[i0] = r1->data[i0];
    }

    emxInit_real_T(&c_XAUGPLUS, 2, &emlrtRTEI, TRUE);
    emlrtPopRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
    cdiff = b_XAUGPLUS->size[1];
    i0 = c_XAUGPLUS->size[0] * c_XAUGPLUS->size[1];
    c_XAUGPLUS->size[0] = loop_ub;
    c_XAUGPLUS->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)c_XAUGPLUS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < cdiff; i0++) {
      for (apnd = 0; apnd < loop_ub; apnd++) {
        c_XAUGPLUS->data[apnd + c_XAUGPLUS->size[0] * i0] = b_XAUGPLUS->
          data[apnd + b_XAUGPLUS->size[0] * i0];
      }
    }

    for (i0 = 0; i0 < 2; i0++) {
      XAUGPLUS[i0] = c_XAUGPLUS->size[i0];
    }

    emxFree_real_T(&c_XAUGPLUS);
    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = r0->size[i0];
    }

    emxInit_real_T(&d_XAUGPLUS, 2, &emlrtRTEI, TRUE);
    emlrtSizeEqCheck2DFastR2012b(XAUGPLUS, iv0, &yb_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
    cdiff = b_XAUGPLUS->size[1];
    i0 = d_XAUGPLUS->size[0] * d_XAUGPLUS->size[1];
    d_XAUGPLUS->size[0] = loop_ub;
    d_XAUGPLUS->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)d_XAUGPLUS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < cdiff; i0++) {
      for (apnd = 0; apnd < loop_ub; apnd++) {
        d_XAUGPLUS->data[apnd + d_XAUGPLUS->size[0] * i0] = b_XAUGPLUS->
          data[apnd + b_XAUGPLUS->size[0] * i0] * r0->data[apnd + r0->size[0] *
          i0];
      }
    }

    emxFree_real_T(&r0);
    b_emxInit_real_T(&r2, 1, &emlrtRTEI, TRUE);
    sum(d_XAUGPLUS, r2);
    xnew_size[0] = r2->size[0];
    loop_ub = r2->size[0];
    emxFree_real_T(&d_XAUGPLUS);
    for (i0 = 0; i0 < loop_ub; i0++) {
      xnew_data[i0] = r2->data[i0];
    }

    emlrtPopRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);

    /*  re-normalize */
    emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &xb_emlrtECI,
      emlrtRootTLSGlobal);
    emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &wb_emlrtECI,
      emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      apnd = xnew_size[0];
      absb = 7 + i0;
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &hb_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    for (i0 = 0; i0 < 4; i0++) {
      apnd = xnew_size[0];
      absb = 7 + i0;
      xnew[i0] = xnew_data[emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
        &ib_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    gamm = e_norm(xnew);
    ndbl = xnew_size[0];
    for (i0 = 0; i0 < 4; i0++) {
      xnew[i0] = xnew_data[i0 + 6] / gamm;
    }

    for (i0 = 0; i0 < 4; i0++) {
      apnd = 7 + i0;
      xnew_data[emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ndbl, &jb_emlrtBCI,
        emlrtRootTLSGlobal) - 1] = xnew[i0];
    }

    emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &vb_emlrtECI,
      emlrtRootTLSGlobal);
    emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &ub_emlrtECI,
      emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      apnd = xnew_size[0];
      absb = 14 + i0;
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &kb_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    for (i0 = 0; i0 < 4; i0++) {
      apnd = xnew_size[0];
      absb = 14 + i0;
      xnew[i0] = xnew_data[emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
        &lb_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    gamm = e_norm(xnew);
    ndbl = xnew_size[0];
    for (i0 = 0; i0 < 4; i0++) {
      xnew[i0] = xnew_data[i0 + 13] / gamm;
    }

    for (i0 = 0; i0 < 4; i0++) {
      apnd = 14 + i0;
      xnew_data[emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ndbl, &mb_emlrtBCI,
        emlrtRootTLSGlobal) - 1] = xnew[i0];
    }

    i0 = Pnew->size[0] * Pnew->size[1];
    Pnew->size[0] = xk_size[0];
    emxEnsureCapacity((emxArray__common *)Pnew, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i0 = Pnew->size[0] * Pnew->size[1];
    Pnew->size[1] = xk_size[0];
    emxEnsureCapacity((emxArray__common *)Pnew, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = xk_size[0] * xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      Pnew->data[i0] = 0.0;
    }

    i0 = N << 1;
    k = 0;
    emxInit_real_T(&b, 2, &emlrtRTEI, TRUE);
    b_emxInit_real_T(&wc, 1, &emlrtRTEI, TRUE);
    emxInit_real_T(&e_XAUGPLUS, 2, &emlrtRTEI, TRUE);
    while (k <= i0) {
      if (1 > xk_size[0]) {
        loop_ub = 0;
      } else {
        apnd = b_XAUGPLUS->size[0];
        emlrtDynamicBoundsCheckFastR2012b(1, 1, apnd, &n_emlrtBCI,
          emlrtRootTLSGlobal);
        apnd = b_XAUGPLUS->size[0];
        loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, apnd,
          &n_emlrtBCI, emlrtRootTLSGlobal);
      }

      apnd = b_XAUGPLUS->size[1];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &m_emlrtBCI,
        emlrtRootTLSGlobal);
      apnd = xnew_size[0];
      emlrtSizeEqCheck1DFastR2012b(loop_ub, apnd, &tb_emlrtECI,
        emlrtRootTLSGlobal);
      if (1 > xk_size[0]) {
        cdiff = 0;
      } else {
        apnd = b_XAUGPLUS->size[0];
        emlrtDynamicBoundsCheckFastR2012b(1, 1, apnd, &l_emlrtBCI,
          emlrtRootTLSGlobal);
        apnd = b_XAUGPLUS->size[0];
        cdiff = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, apnd,
          &l_emlrtBCI, emlrtRootTLSGlobal);
      }

      apnd = b_XAUGPLUS->size[1];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &k_emlrtBCI,
        emlrtRootTLSGlobal);
      apnd = xnew_size[0];
      emlrtSizeEqCheck1DFastR2012b(cdiff, apnd, &sb_emlrtECI, emlrtRootTLSGlobal);
      apnd = h_y->size[0];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &o_emlrtBCI,
        emlrtRootTLSGlobal);
      apnd = wc->size[0];
      wc->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)wc, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (apnd = 0; apnd < loop_ub; apnd++) {
        wc->data[apnd] = wc_data[k] * (b_XAUGPLUS->data[apnd + b_XAUGPLUS->size
          [0] * k] - xnew_data[apnd]);
      }

      apnd = e_XAUGPLUS->size[0] * e_XAUGPLUS->size[1];
      e_XAUGPLUS->size[0] = 1;
      e_XAUGPLUS->size[1] = cdiff;
      emxEnsureCapacity((emxArray__common *)e_XAUGPLUS, apnd, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (apnd = 0; apnd < cdiff; apnd++) {
        e_XAUGPLUS->data[e_XAUGPLUS->size[0] * apnd] = b_XAUGPLUS->data[apnd +
          b_XAUGPLUS->size[0] * k] - xnew_data[apnd];
      }

      apnd = b->size[0] * b->size[1];
      b->size[0] = wc->size[0];
      b->size[1] = e_XAUGPLUS->size[1];
      emxEnsureCapacity((emxArray__common *)b, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = wc->size[0];
      for (apnd = 0; apnd < loop_ub; apnd++) {
        cdiff = e_XAUGPLUS->size[1];
        for (absb = 0; absb < cdiff; absb++) {
          b->data[apnd + b->size[0] * absb] = wc->data[apnd] * e_XAUGPLUS->
            data[e_XAUGPLUS->size[0] * absb];
        }
      }

      for (apnd = 0; apnd < 2; apnd++) {
        b_Pnew[apnd] = Pnew->size[apnd];
      }

      for (apnd = 0; apnd < 2; apnd++) {
        wm_size[apnd] = b->size[apnd];
      }

      emlrtSizeEqCheck2DFastR2012b(b_Pnew, wm_size, &rb_emlrtECI,
        emlrtRootTLSGlobal);
      apnd = Pnew->size[0] * Pnew->size[1];
      emxEnsureCapacity((emxArray__common *)Pnew, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ndbl = Pnew->size[0];
      cdiff = Pnew->size[1];
      loop_ub = ndbl * cdiff;
      for (apnd = 0; apnd < loop_ub; apnd++) {
        Pnew->data[apnd] += b->data[apnd];
      }

      k++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    emxFree_real_T(&e_XAUGPLUS);
    emxFree_real_T(&wc);

    /*  pass the sigma points through the measurement function */
    if (1 > xk_size[0]) {
      loop_ub = 0;
    } else {
      i0 = b_XAUGPLUS->size[0];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &j_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = b_XAUGPLUS->size[0];
      loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i0, &j_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    emlrtPushRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    if (Pnk->size[0] < 1) {
      cdiff = -1;
      apnd = 0;
    } else {
      ndbl = (int32_T)muDoubleScalarFloor(((real_T)Pnk->size[0] - 1.0) + 0.5);
      apnd = ndbl + 1;
      cdiff = (ndbl - Pnk->size[0]) + 1;
      absb = Pnk->size[0];
      if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * (real_T)absb) {
        ndbl++;
        apnd = Pnk->size[0];
      } else if (cdiff > 0) {
        apnd = ndbl;
      } else {
        ndbl++;
      }

      cdiff = ndbl - 1;
    }

    emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    i0 = f_y->size[0] * f_y->size[1];
    f_y->size[0] = 1;
    f_y->size[1] = cdiff + 1;
    emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (cdiff + 1 > 0) {
      f_y->data[0] = 1.0;
      if (cdiff + 1 > 1) {
        f_y->data[cdiff] = apnd;
        i0 = cdiff + (cdiff < 0);
        if (i0 >= 0) {
          ndbl = (int32_T)((uint32_T)i0 >> 1);
        } else {
          ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
        }

        emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k < ndbl; k++) {
          f_y->data[k] = 1.0 + (real_T)k;
          f_y->data[cdiff - k] = apnd - k;
        }

        if (ndbl << 1 == cdiff) {
          f_y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
        } else {
          f_y->data[ndbl] = 1.0 + (real_T)ndbl;
          f_y->data[ndbl + 1] = apnd - ndbl;
        }
      }
    }

    emxInit_real_T(&f_XAUGPLUS, 2, &emlrtRTEI, TRUE);
    emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    cdiff = b_XAUGPLUS->size[1];
    i0 = f_XAUGPLUS->size[0] * f_XAUGPLUS->size[1];
    f_XAUGPLUS->size[0] = loop_ub;
    f_XAUGPLUS->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)f_XAUGPLUS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < cdiff; i0++) {
      for (apnd = 0; apnd < loop_ub; apnd++) {
        f_XAUGPLUS->data[apnd + f_XAUGPLUS->size[0] * i0] = b_XAUGPLUS->
          data[apnd + b_XAUGPLUS->size[0] * i0];
      }
    }

    emxInit_real_T(&d_XAUG, 2, &emlrtRTEI, TRUE);
    tmp_size_idx_1 = f_y->size[1];
    cdiff = (int16_T)((int16_T)xk_size[0] + (int16_T)Pvk->size[0]);
    loop_ub = f_y->size[0] * f_y->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      apnd = XAUG->size[0];
      b_y = (real_T)cdiff + f_y->data[i0];
      absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &j_emlrtDCI,
        emlrtRootTLSGlobal);
      f_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
        &nb_emlrtBCI, emlrtRootTLSGlobal);
    }

    loop_ub = XAUG->size[1];
    i0 = d_XAUG->size[0] * d_XAUG->size[1];
    d_XAUG->size[0] = tmp_size_idx_1;
    d_XAUG->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)d_XAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (apnd = 0; apnd < tmp_size_idx_1; apnd++) {
        d_XAUG->data[apnd + d_XAUG->size[0] * i0] = XAUG->data[(f_tmp_data[apnd]
          + XAUG->size[0] * i0) - 1];
      }
    }

    emxFree_real_T(&XAUG);
    emxInit_real_T(&YKAUG, 2, &f_emlrtRTEI, TRUE);
    measurement_eq_unknown_state(f_XAUGPLUS, d_XAUG, uk_data, uk_size, YKAUG);
    emlrtPopRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
    b_wm_size[0] = 1;
    b_wm_size[1] = g_y + 1;
    loop_ub = g_y + 1;
    emxFree_real_T(&d_XAUG);
    emxFree_real_T(&f_XAUGPLUS);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_wm_data[i0] = wm_data[i0];
    }

    repmat(b_wm_data, b_wm_size, YKAUG->size[0], r1);
    emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 2; i0++) {
      XAUGPLUS[i0] = YKAUG->size[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = r1->size[i0];
    }

    emxInit_real_T(&b_YKAUG, 2, &emlrtRTEI, TRUE);
    emlrtSizeEqCheck2DFastR2012b(XAUGPLUS, iv0, &qb_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
    i0 = b_YKAUG->size[0] * b_YKAUG->size[1];
    b_YKAUG->size[0] = YKAUG->size[0];
    b_YKAUG->size[1] = YKAUG->size[1];
    emxEnsureCapacity((emxArray__common *)b_YKAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = YKAUG->size[0] * YKAUG->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_YKAUG->data[i0] = YKAUG->data[i0] * r1->data[i0];
    }

    emxFree_real_T(&r1);
    b_emxInit_real_T(&yhat, 1, &g_emlrtRTEI, TRUE);
    emxInit_real_T(&Pyk, 2, &h_emlrtRTEI, TRUE);
    sum(b_YKAUG, yhat);
    emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);

    /*  add something to handle magnetometer normalization if necessary here */
    /*  measurement covariance */
    ndbl = YKAUG->size[0];
    i0 = Pyk->size[0] * Pyk->size[1];
    Pyk->size[0] = ndbl;
    emxEnsureCapacity((emxArray__common *)Pyk, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    ndbl = YKAUG->size[0];
    i0 = Pyk->size[0] * Pyk->size[1];
    Pyk->size[1] = ndbl;
    emxEnsureCapacity((emxArray__common *)Pyk, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = YKAUG->size[0] * YKAUG->size[0];
    emxFree_real_T(&b_YKAUG);
    for (i0 = 0; i0 < loop_ub; i0++) {
      Pyk->data[i0] = 0.0;
    }

    emxInit_real_T(&Pxkyk, 2, &i_emlrtRTEI, TRUE);

    /*  cross covariance */
    i0 = Pxkyk->size[0] * Pxkyk->size[1];
    Pxkyk->size[0] = xk_size[0];
    emxEnsureCapacity((emxArray__common *)Pxkyk, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    ndbl = YKAUG->size[0];
    i0 = Pxkyk->size[0] * Pxkyk->size[1];
    Pxkyk->size[1] = ndbl;
    emxEnsureCapacity((emxArray__common *)Pxkyk, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = xk_size[0] * YKAUG->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      Pxkyk->data[i0] = 0.0;
    }

    i0 = N << 1;
    k = 0;
    b_emxInit_real_T(&b_wc, 1, &emlrtRTEI, TRUE);
    emxInit_real_T(&c_YKAUG, 2, &emlrtRTEI, TRUE);
    b_emxInit_real_T(&c_wc, 1, &emlrtRTEI, TRUE);
    emxInit_real_T(&d_YKAUG, 2, &emlrtRTEI, TRUE);
    while (k <= i0) {
      apnd = YKAUG->size[1];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &h_emlrtBCI,
        emlrtRootTLSGlobal);
      apnd = YKAUG->size[0];
      absb = yhat->size[0];
      emlrtSizeEqCheck1DFastR2012b(apnd, absb, &pb_emlrtECI, emlrtRootTLSGlobal);
      apnd = YKAUG->size[1];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &g_emlrtBCI,
        emlrtRootTLSGlobal);
      apnd = YKAUG->size[0];
      absb = yhat->size[0];
      emlrtSizeEqCheck1DFastR2012b(apnd, absb, &ob_emlrtECI, emlrtRootTLSGlobal);
      apnd = h_y->size[0];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &i_emlrtBCI,
        emlrtRootTLSGlobal);
      loop_ub = YKAUG->size[0];
      cdiff = YKAUG->size[0];
      apnd = b_wc->size[0];
      b_wc->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)b_wc, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (apnd = 0; apnd < loop_ub; apnd++) {
        b_wc->data[apnd] = wc_data[k] * (YKAUG->data[apnd + YKAUG->size[0] * k]
          - yhat->data[apnd]);
      }

      apnd = c_YKAUG->size[0] * c_YKAUG->size[1];
      c_YKAUG->size[0] = 1;
      c_YKAUG->size[1] = cdiff;
      emxEnsureCapacity((emxArray__common *)c_YKAUG, apnd, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (apnd = 0; apnd < cdiff; apnd++) {
        c_YKAUG->data[c_YKAUG->size[0] * apnd] = YKAUG->data[apnd + YKAUG->size
          [0] * k] - yhat->data[apnd];
      }

      apnd = b->size[0] * b->size[1];
      b->size[0] = b_wc->size[0];
      b->size[1] = c_YKAUG->size[1];
      emxEnsureCapacity((emxArray__common *)b, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = b_wc->size[0];
      for (apnd = 0; apnd < loop_ub; apnd++) {
        cdiff = c_YKAUG->size[1];
        for (absb = 0; absb < cdiff; absb++) {
          b->data[apnd + b->size[0] * absb] = b_wc->data[apnd] * c_YKAUG->
            data[c_YKAUG->size[0] * absb];
        }
      }

      for (apnd = 0; apnd < 2; apnd++) {
        XAUGPLUS[apnd] = Pyk->size[apnd];
      }

      for (apnd = 0; apnd < 2; apnd++) {
        wm_size[apnd] = b->size[apnd];
      }

      emlrtSizeEqCheck2DFastR2012b(XAUGPLUS, wm_size, &nb_emlrtECI,
        emlrtRootTLSGlobal);
      apnd = Pyk->size[0] * Pyk->size[1];
      emxEnsureCapacity((emxArray__common *)Pyk, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ndbl = Pyk->size[0];
      cdiff = Pyk->size[1];
      loop_ub = ndbl * cdiff;
      for (apnd = 0; apnd < loop_ub; apnd++) {
        Pyk->data[apnd] += b->data[apnd];
      }

      if (1 > xk_size[0]) {
        loop_ub = 0;
      } else {
        apnd = b_XAUGPLUS->size[0];
        emlrtDynamicBoundsCheckFastR2012b(1, 1, apnd, &e_emlrtBCI,
          emlrtRootTLSGlobal);
        apnd = b_XAUGPLUS->size[0];
        loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, apnd,
          &e_emlrtBCI, emlrtRootTLSGlobal);
      }

      apnd = b_XAUGPLUS->size[1];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &d_emlrtBCI,
        emlrtRootTLSGlobal);
      apnd = xnew_size[0];
      emlrtSizeEqCheck1DFastR2012b(loop_ub, apnd, &mb_emlrtECI,
        emlrtRootTLSGlobal);
      apnd = YKAUG->size[1];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &c_emlrtBCI,
        emlrtRootTLSGlobal);
      apnd = YKAUG->size[0];
      absb = yhat->size[0];
      emlrtSizeEqCheck1DFastR2012b(apnd, absb, &lb_emlrtECI, emlrtRootTLSGlobal);
      apnd = h_y->size[0];
      absb = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &f_emlrtBCI,
        emlrtRootTLSGlobal);
      cdiff = YKAUG->size[0];
      apnd = c_wc->size[0];
      c_wc->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)c_wc, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (apnd = 0; apnd < loop_ub; apnd++) {
        c_wc->data[apnd] = wc_data[k] * (b_XAUGPLUS->data[apnd +
          b_XAUGPLUS->size[0] * k] - xnew_data[apnd]);
      }

      apnd = d_YKAUG->size[0] * d_YKAUG->size[1];
      d_YKAUG->size[0] = 1;
      d_YKAUG->size[1] = cdiff;
      emxEnsureCapacity((emxArray__common *)d_YKAUG, apnd, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (apnd = 0; apnd < cdiff; apnd++) {
        d_YKAUG->data[d_YKAUG->size[0] * apnd] = YKAUG->data[apnd + YKAUG->size
          [0] * k] - yhat->data[apnd];
      }

      apnd = b->size[0] * b->size[1];
      b->size[0] = c_wc->size[0];
      b->size[1] = d_YKAUG->size[1];
      emxEnsureCapacity((emxArray__common *)b, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = c_wc->size[0];
      for (apnd = 0; apnd < loop_ub; apnd++) {
        cdiff = d_YKAUG->size[1];
        for (absb = 0; absb < cdiff; absb++) {
          b->data[apnd + b->size[0] * absb] = c_wc->data[apnd] * d_YKAUG->
            data[d_YKAUG->size[0] * absb];
        }
      }

      for (apnd = 0; apnd < 2; apnd++) {
        XAUGPLUS[apnd] = Pxkyk->size[apnd];
      }

      for (apnd = 0; apnd < 2; apnd++) {
        wm_size[apnd] = b->size[apnd];
      }

      emlrtSizeEqCheck2DFastR2012b(XAUGPLUS, wm_size, &kb_emlrtECI,
        emlrtRootTLSGlobal);
      apnd = Pxkyk->size[0] * Pxkyk->size[1];
      emxEnsureCapacity((emxArray__common *)Pxkyk, apnd, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ndbl = Pxkyk->size[0];
      cdiff = Pxkyk->size[1];
      loop_ub = ndbl * cdiff;
      for (apnd = 0; apnd < loop_ub; apnd++) {
        Pxkyk->data[apnd] += b->data[apnd];
      }

      k++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    emxFree_real_T(&d_YKAUG);
    emxFree_real_T(&c_wc);
    emxFree_real_T(&c_YKAUG);
    emxFree_real_T(&b_wc);
    emxFree_real_T(&h_y);
    emxFree_real_T(&b_XAUGPLUS);
    emxInit_boolean_T(&r3, 2, &emlrtRTEI, TRUE);

    /*  Kalman gain */
    emlrtPushRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
    i0 = r3->size[0] * r3->size[1];
    r3->size[0] = Pyk->size[0];
    r3->size[1] = Pyk->size[1];
    emxEnsureCapacity((emxArray__common *)r3, i0, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    loop_ub = Pyk->size[0] * Pyk->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      r3->data[i0] = muDoubleScalarIsNaN(Pyk->data[i0]);
    }

    emxInit_boolean_T(&r4, 2, &emlrtRTEI, TRUE);
    any(r3, r4);
    n_too_large = b_any(r4);
    emlrtPopRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
    emxFree_boolean_T(&r3);
    emxFree_boolean_T(&r4);
    if (n_too_large) {
      emlrtPushRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
      j_y = NULL;
      m0 = mxCreateCharArray(2, iv4);
      for (ndbl = 0; ndbl < 31; ndbl++) {
        cv0[ndbl] = cv1[ndbl];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 31, m0, cv0);
      emlrtAssign(&j_y, m0);
      disp(j_y, &emlrtMCI);
      emlrtPopRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
      xnew_size[0] = 1;
      xnew_data[0] = 0.0;
      i0 = Pnew->size[0] * Pnew->size[1];
      Pnew->size[0] = 1;
      Pnew->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)Pnew, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      Pnew->data[0] = 0.0;
    } else {
      emxInit_real_T(&b_b, 2, &emlrtRTEI, TRUE);
      emlrtPushRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
      eye(YKAUG->size[0], b);
      i0 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = b->size[0];
      b_b->size[1] = b->size[1];
      emxEnsureCapacity((emxArray__common *)b_b, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = b->size[0] * b->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_b->data[i0] = b->data[i0];
      }

      mldivide(Pyk, b_b, b);
      emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      emxFree_real_T(&b_b);
      if (!(Pxkyk->size[1] == b->size[0])) {
        if (((Pxkyk->size[0] == 1) && (Pxkyk->size[1] == 1)) || ((b->size[0] ==
              1) && (b->size[1] == 1))) {
          emlrtPushRtStackR2012b(&mh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          k_y = NULL;
          m0 = mxCreateCharArray(2, iv5);
          for (ndbl = 0; ndbl < 45; ndbl++) {
            cv2[ndbl] = cv3[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m0, cv2);
          emlrtAssign(&k_y, m0);
          error(message(k_y, &l_emlrtMCI), &m_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&mh_emlrtRSI, emlrtRootTLSGlobal);
        } else {
          emlrtPushRtStackR2012b(&lh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          l_y = NULL;
          m0 = mxCreateCharArray(2, iv6);
          for (ndbl = 0; ndbl < 21; ndbl++) {
            cv4[ndbl] = cv5[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
          emlrtAssign(&l_y, m0);
          error(message(l_y, &n_emlrtMCI), &o_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&lh_emlrtRSI, emlrtRootTLSGlobal);
        }
      }

      emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      emxInit_real_T(&Kk, 2, &j_emlrtRTEI, TRUE);
      emxInit_real_T(&r5, 2, &emlrtRTEI, TRUE);
      if ((Pxkyk->size[1] == 1) || (b->size[0] == 1)) {
        i0 = Kk->size[0] * Kk->size[1];
        Kk->size[0] = Pxkyk->size[0];
        Kk->size[1] = b->size[1];
        emxEnsureCapacity((emxArray__common *)Kk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = Pxkyk->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          cdiff = b->size[1];
          for (apnd = 0; apnd < cdiff; apnd++) {
            Kk->data[i0 + Kk->size[0] * apnd] = 0.0;
            ndbl = Pxkyk->size[1];
            for (absb = 0; absb < ndbl; absb++) {
              Kk->data[i0 + Kk->size[0] * apnd] += Pxkyk->data[i0 + Pxkyk->size
                [0] * absb] * b->data[absb + b->size[0] * apnd];
            }
          }
        }
      } else {
        kd = (uint32_T)Pxkyk->size[0];
        unnamed_idx_1 = (uint32_T)b->size[1];
        i0 = r5->size[0] * r5->size[1];
        r5->size[0] = (int32_T)kd;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = r5->size[0] * r5->size[1];
        r5->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)kd * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          r5->data[i0] = 0.0;
        }

        emlrtPushRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&nh_emlrtRSI, emlrtRootTLSGlobal);
        i0 = Kk->size[0] * Kk->size[1];
        Kk->size[0] = (int32_T)kd;
        emxEnsureCapacity((emxArray__common *)Kk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = Kk->size[0] * Kk->size[1];
        Kk->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)Kk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)kd * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          Kk->data[i0] = 0.0;
        }

        if ((Pxkyk->size[0] < 1) || (b->size[1] < 1) || (Pxkyk->size[1] < 1)) {
        } else {
          emlrtPushRtStackR2012b(&ph_emlrtRSI, emlrtRootTLSGlobal);
          gamm = 1.0;
          b_ndbl = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          m_t = (ptrdiff_t)(Pxkyk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          n_t = (ptrdiff_t)(b->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          k_t = (ptrdiff_t)(Pxkyk->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          lda_t = (ptrdiff_t)(Pxkyk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldb_t = (ptrdiff_t)(Pxkyk->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldc_t = (ptrdiff_t)(Pxkyk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          alpha1_t = (double *)(&gamm);
          emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&di_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Aia0_t = (double *)(&Pxkyk->data[0]);
          emlrtPopRtStackR2012b(&di_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ei_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Bib0_t = (double *)(&b->data[0]);
          emlrtPopRtStackR2012b(&ei_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&fi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          beta1_t = (double *)(&b_ndbl);
          emlrtPopRtStackR2012b(&fi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Cic0_t = (double *)(&Kk->data[0]);
          emlrtPopRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t,
                Bib0_t, &ldb_t, beta1_t, Cic0_t, &ldc_t);
          emlrtPopRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ph_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&nh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);

      /*  handle special cases by examining the input function names */
      /*  minimize angle difference */
      /* minimize diff between bearing/declination angles to agents */
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, 4, &jb_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, 4, &ib_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 4; i0++) {
        apnd = yhat->size[0];
        absb = iv7[i0];
        xnew[i0] = yhat->data[emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &ob_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      for (i0 = 0; i0 < 4; i0++) {
        apnd = iv7[i0];
        ytilde[i0] = ytilde_data[emlrtDynamicBoundsCheckFastR2012b(apnd, 1,
          ytilde_size[0], &pb_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      b_minangle(xnew, ytilde);
      ndbl = yhat->size[0];
      for (i0 = 0; i0 < 4; i0++) {
        apnd = iv7[i0];
        yhat->data[emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ndbl, &qb_emlrtBCI,
          emlrtRootTLSGlobal) - 1] = xnew[i0];
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);

      /*  normalize magnetometer */
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, 3, &hb_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, 3, &gb_emlrtECI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 3; i0++) {
        apnd = yhat->size[0];
        absb = 7 + i0;
        b_yhat[i0] = yhat->data[emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &rb_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      for (i0 = 0; i0 < 3; i0++) {
        apnd = yhat->size[0];
        absb = 7 + i0;
        c_yhat[i0] = yhat->data[emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &sb_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      rdivide(c_yhat, f_norm(b_yhat), dv0);
      ndbl = yhat->size[0];
      for (i0 = 0; i0 < 3; i0++) {
        apnd = 7 + i0;
        yhat->data[emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ndbl, &tb_emlrtBCI,
          emlrtRootTLSGlobal) - 1] = dv0[i0];
      }

      /*  minimize diff between bearing/declination to features */
      emlrtDynamicBoundsCheckFastR2012b(10, 1, uk_size[0], &b_emlrtBCI,
        emlrtRootTLSGlobal);
      i_y = 3.0 * uk_data[9];
      b_y = (10.0 + 3.0 * uk_data[9]) + 1.0;
      i0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &emlrtDCI,
        emlrtRootTLSGlobal);
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, uk_size[0], &emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == m_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((m_y - 2.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (2.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 2.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        o_y = NULL;
        m0 = mxCreateCharArray(2, iv8);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&o_y, m0);
        error(message(o_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emxInit_real_T(&r6, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r6->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r6->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r6->data[k] = gamm + (real_T)kd;
            r6->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r6->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r6->data[ndbl] = gamm + (real_T)kd;
            r6->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, r6->size[1],
        &fb_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == m_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((m_y - 2.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (2.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 2.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        p_y = NULL;
        m0 = mxCreateCharArray(2, iv9);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&p_y, m0);
        error(message(p_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emxInit_real_T(&r7, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r7->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r7->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r7->data[k] = gamm + (real_T)kd;
            r7->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r7->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r7->data[ndbl] = gamm + (real_T)kd;
            r7->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, r7->size[1],
        &eb_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == m_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((m_y - 2.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (2.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 2.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        q_y = NULL;
        m0 = mxCreateCharArray(2, iv10);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&q_y, m0);
        error(message(q_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = f_y->size[0] * f_y->size[1];
      f_y->size[0] = 1;
      f_y->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        f_y->data[0] = gamm;
        if (cdiff + 1 > 1) {
          f_y->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            f_y->data[k] = gamm + (real_T)kd;
            f_y->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            f_y->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            f_y->data[ndbl] = gamm + (real_T)kd;
            f_y->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emxInit_int32_T(&r8, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = f_y->size[1];
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = f_y->size[0] * f_y->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = f_y->data[i0] + 9.0;
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &k_emlrtDCI,
          emlrtRootTLSGlobal);
        r8->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &ub_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxInit_int32_T(&r9, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r9->size[0] * r9->size[1];
      r9->size[0] = 1;
      r9->size[1] = r6->size[1];
      emxEnsureCapacity((emxArray__common *)r9, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = r6->data[i0] + 9.0;
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &l_emlrtDCI,
          emlrtRootTLSGlobal);
        r9->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &vb_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r2->size[0];
      r2->size[0] = r9->size[1];
      emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r9->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r2->data[i0] = yhat->data[r9->data[i0] - 1];
      }

      emxFree_int32_T(&r9);
      b_emxInit_real_T(&b_ytilde, 1, &emlrtRTEI, TRUE);
      emxInit_int32_T(&r10, 2, &emlrtRTEI, TRUE);
      i0 = r10->size[0] * r10->size[1];
      r10->size[0] = 1;
      r10->size[1] = r7->size[1];
      emxEnsureCapacity((emxArray__common *)r10, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y = r7->data[i0] + 9.0;
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &m_emlrtDCI,
          emlrtRootTLSGlobal);
        r10->data[i0] = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &wb_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = b_ytilde->size[0];
      b_ytilde->size[0] = r10->size[1];
      emxEnsureCapacity((emxArray__common *)b_ytilde, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r10->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_ytilde->data[i0] = ytilde_data[r10->data[i0] - 1];
      }

      emxFree_int32_T(&r10);
      c_minangle(r2, b_ytilde);
      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[1];
      apnd = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, apnd, &db_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r8->size[0] * r8->size[1];
      emxFree_real_T(&b_ytilde);
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r8->data[i0] - 1] = r2->data[i0];
      }

      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == m_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((m_y - 3.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (3.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 3.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        r_y = NULL;
        m0 = mxCreateCharArray(2, iv11);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&r_y, m0);
        error(message(r_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r6->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r6->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r6->data[k] = gamm + (real_T)kd;
            r6->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r6->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r6->data[ndbl] = gamm + (real_T)kd;
            r6->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, r6->size[1],
        &cb_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == m_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((m_y - 3.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (3.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 3.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        s_y = NULL;
        m0 = mxCreateCharArray(2, iv12);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&s_y, m0);
        error(message(s_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r7->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r7->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r7->data[k] = gamm + (real_T)kd;
            r7->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r7->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r7->data[ndbl] = gamm + (real_T)kd;
            r7->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, r7->size[1],
        &bb_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == m_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((m_y - 3.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (3.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 3.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        t_y = NULL;
        m0 = mxCreateCharArray(2, iv13);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&t_y, m0);
        error(message(t_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = f_y->size[0] * f_y->size[1];
      f_y->size[0] = 1;
      f_y->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        f_y->data[0] = gamm;
        if (cdiff + 1 > 1) {
          f_y->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            f_y->data[k] = gamm + (real_T)kd;
            f_y->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            f_y->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            f_y->data[ndbl] = gamm + (real_T)kd;
            f_y->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = f_y->size[1];
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = f_y->size[0] * f_y->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = f_y->data[i0] + 9.0;
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &n_emlrtDCI,
          emlrtRootTLSGlobal);
        r8->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &xb_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxInit_int32_T(&r11, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r11->size[0] * r11->size[1];
      r11->size[0] = 1;
      r11->size[1] = r6->size[1];
      emxEnsureCapacity((emxArray__common *)r11, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = r6->data[i0] + 9.0;
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &o_emlrtDCI,
          emlrtRootTLSGlobal);
        r11->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &yb_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r2->size[0];
      r2->size[0] = r11->size[1];
      emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r11->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r2->data[i0] = yhat->data[r11->data[i0] - 1];
      }

      emxFree_int32_T(&r11);
      b_emxInit_real_T(&c_ytilde, 1, &emlrtRTEI, TRUE);
      emxInit_int32_T(&r12, 2, &emlrtRTEI, TRUE);
      i0 = r12->size[0] * r12->size[1];
      r12->size[0] = 1;
      r12->size[1] = r7->size[1];
      emxEnsureCapacity((emxArray__common *)r12, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y = r7->data[i0] + 9.0;
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &p_emlrtDCI,
          emlrtRootTLSGlobal);
        r12->data[i0] = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &ac_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = c_ytilde->size[0];
      c_ytilde->size[0] = r12->size[1];
      emxEnsureCapacity((emxArray__common *)c_ytilde, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r12->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_ytilde->data[i0] = ytilde_data[r12->data[i0] - 1];
      }

      emxFree_int32_T(&r12);
      c_minangle(r2, c_ytilde);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[1];
      apnd = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, apnd, &ab_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r8->size[0] * r8->size[1];
      emxFree_real_T(&c_ytilde);
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r8->data[i0] - 1] = r2->data[i0];
      }

      emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[(int32_T)((10.0 + i_y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == m_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((m_y - 2.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (2.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 2.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        u_y = NULL;
        m0 = mxCreateCharArray(2, iv14);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&u_y, m0);
        error(message(u_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r6->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r6->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r6->data[k] = gamm + (real_T)kd;
            r6->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r6->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r6->data[ndbl] = gamm + (real_T)kd;
            r6->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, r6->size[1],
        &y_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[(int32_T)((10.0 + i_y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == m_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((m_y - 2.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (2.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 2.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        v_y = NULL;
        m0 = mxCreateCharArray(2, iv15);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&v_y, m0);
        error(message(v_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r7->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r7->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r7->data[k] = gamm + (real_T)kd;
            r7->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r7->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r7->data[ndbl] = gamm + (real_T)kd;
            r7->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, r7->size[1],
        &x_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      n_y = 3.0 * uk_data[(int32_T)((10.0 + i_y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(n_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (n_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(n_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == n_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((n_y - 2.0) / 3.0 + 0.5);
        b_y = b_ndbl * 3.0;
        lambda = (2.0 + b_y) - n_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * n_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          n_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          n_y = 2.0 + b_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        w_y = NULL;
        m0 = mxCreateCharArray(2, iv16);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&w_y, m0);
        error(message(w_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = f_y->size[0] * f_y->size[1];
      f_y->size[0] = 1;
      f_y->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        f_y->data[0] = gamm;
        if (cdiff + 1 > 1) {
          f_y->data[cdiff] = n_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            f_y->data[k] = gamm + (real_T)kd;
            f_y->data[cdiff - k] = n_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            f_y->data[ndbl] = (gamm + n_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            f_y->data[ndbl] = gamm + (real_T)kd;
            f_y->data[ndbl + 1] = n_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = f_y->size[1];
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = f_y->size[0] * f_y->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + m_y) + f_y->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &q_emlrtDCI,
          emlrtRootTLSGlobal);
        r8->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &bc_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxInit_int32_T(&r13, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      n_y = 3.0 * uk_data[9];
      i0 = r13->size[0] * r13->size[1];
      r13->size[0] = 1;
      r13->size[1] = r6->size[1];
      emxEnsureCapacity((emxArray__common *)r13, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + m_y) + r6->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &r_emlrtDCI,
          emlrtRootTLSGlobal);
        r13->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &cc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r2->size[0];
      r2->size[0] = r13->size[1];
      emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r13->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r2->data[i0] = yhat->data[r13->data[i0] - 1];
      }

      emxFree_int32_T(&r13);
      b_emxInit_real_T(&d_ytilde, 1, &emlrtRTEI, TRUE);
      emxInit_int32_T(&r14, 2, &emlrtRTEI, TRUE);
      i0 = r14->size[0] * r14->size[1];
      r14->size[0] = 1;
      r14->size[1] = r7->size[1];
      emxEnsureCapacity((emxArray__common *)r14, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y = (9.0 + n_y) + r7->data[i0];
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &s_emlrtDCI,
          emlrtRootTLSGlobal);
        r14->data[i0] = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &dc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = d_ytilde->size[0];
      d_ytilde->size[0] = r14->size[1];
      emxEnsureCapacity((emxArray__common *)d_ytilde, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r14->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        d_ytilde->data[i0] = ytilde_data[r14->data[i0] - 1];
      }

      emxFree_int32_T(&r14);
      c_minangle(r2, d_ytilde);
      emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[1];
      apnd = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, apnd, &w_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r8->size[0] * r8->size[1];
      emxFree_real_T(&d_ytilde);
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r8->data[i0] - 1] = r2->data[i0];
      }

      emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[(int32_T)((10.0 + i_y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == m_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((m_y - 3.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (3.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 3.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        x_y = NULL;
        m0 = mxCreateCharArray(2, iv17);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&x_y, m0);
        error(message(x_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r6->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r6->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r6->data[k] = gamm + (real_T)kd;
            r6->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r6->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r6->data[ndbl] = gamm + (real_T)kd;
            r6->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, r6->size[1],
        &v_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[(int32_T)((10.0 + i_y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == m_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((m_y - 3.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (3.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 3.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        y_y = NULL;
        m0 = mxCreateCharArray(2, iv18);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&y_y, m0);
        error(message(y_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r7->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r7->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r7->data[k] = gamm + (real_T)kd;
            r7->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r7->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r7->data[ndbl] = gamm + (real_T)kd;
            r7->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, r7->size[1],
        &u_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      i_y = 3.0 * uk_data[(int32_T)((10.0 + i_y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (i_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == i_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((i_y - 3.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (3.0 + n_y) - i_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * i_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          i_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          i_y = 3.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        ab_y = NULL;
        m0 = mxCreateCharArray(2, iv19);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&ab_y, m0);
        error(message(ab_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = f_y->size[0] * f_y->size[1];
      f_y->size[0] = 1;
      f_y->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        f_y->data[0] = gamm;
        if (cdiff + 1 > 1) {
          f_y->data[cdiff] = i_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            f_y->data[k] = gamm + (real_T)kd;
            f_y->data[cdiff - k] = i_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            f_y->data[ndbl] = (gamm + i_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            f_y->data[ndbl] = gamm + (real_T)kd;
            f_y->data[ndbl + 1] = i_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = f_y->size[1];
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = f_y->size[0] * f_y->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + m_y) + f_y->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &t_emlrtDCI,
          emlrtRootTLSGlobal);
        r8->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &ec_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxInit_int32_T(&r15, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      i_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[9];
      i0 = r15->size[0] * r15->size[1];
      r15->size[0] = 1;
      r15->size[1] = r6->size[1];
      emxEnsureCapacity((emxArray__common *)r15, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + i_y) + r6->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &u_emlrtDCI,
          emlrtRootTLSGlobal);
        r15->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &fc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r2->size[0];
      r2->size[0] = r15->size[1];
      emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r15->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r2->data[i0] = yhat->data[r15->data[i0] - 1];
      }

      emxFree_int32_T(&r15);
      b_emxInit_real_T(&e_ytilde, 1, &emlrtRTEI, TRUE);
      emxInit_int32_T(&r16, 2, &emlrtRTEI, TRUE);
      i0 = r16->size[0] * r16->size[1];
      r16->size[0] = 1;
      r16->size[1] = r7->size[1];
      emxEnsureCapacity((emxArray__common *)r16, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y = (9.0 + m_y) + r7->data[i0];
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &v_emlrtDCI,
          emlrtRootTLSGlobal);
        r16->data[i0] = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &gc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = e_ytilde->size[0];
      e_ytilde->size[0] = r16->size[1];
      emxEnsureCapacity((emxArray__common *)e_ytilde, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r16->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        e_ytilde->data[i0] = ytilde_data[r16->data[i0] - 1];
      }

      emxFree_int32_T(&r16);
      c_minangle(r2, e_ytilde);
      emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[1];
      apnd = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, apnd, &t_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r8->size[0] * r8->size[1];
      emxFree_real_T(&e_ytilde);
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r8->data[i0] - 1] = r2->data[i0];
      }

      emlrtPushRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      i_y = 3.0 * uk_data[(int32_T)((12.0 + c_y) + d_y) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (i_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == i_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((i_y - 2.0) / 3.0 + 0.5);
        m_y = b_ndbl * 3.0;
        lambda = (2.0 + m_y) - i_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * i_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          i_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          i_y = 2.0 + m_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        bb_y = NULL;
        m0 = mxCreateCharArray(2, iv20);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&bb_y, m0);
        error(message(bb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r6->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r6->data[cdiff] = i_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r6->data[k] = gamm + (real_T)kd;
            r6->data[cdiff - k] = i_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r6->data[ndbl] = (gamm + i_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r6->data[ndbl] = gamm + (real_T)kd;
            r6->data[ndbl + 1] = i_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, r6->size[1],
        &s_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      i_y = 3.0 * uk_data[(int32_T)((12.0 + c_y) + d_y) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (i_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == i_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((i_y - 2.0) / 3.0 + 0.5);
        m_y = b_ndbl * 3.0;
        lambda = (2.0 + m_y) - i_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * i_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          i_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          i_y = 2.0 + m_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        cb_y = NULL;
        m0 = mxCreateCharArray(2, iv21);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&cb_y, m0);
        error(message(cb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r7->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r7->data[cdiff] = i_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r7->data[k] = gamm + (real_T)kd;
            r7->data[cdiff - k] = i_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r7->data[ndbl] = (gamm + i_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r7->data[ndbl] = gamm + (real_T)kd;
            r7->data[ndbl + 1] = i_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, r7->size[1],
        &r_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      i_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      m_y = 3.0 * uk_data[(int32_T)((12.0 + c_y) + d_y) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (m_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(m_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == m_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((m_y - 2.0) / 3.0 + 0.5);
        n_y = b_ndbl * 3.0;
        lambda = (2.0 + n_y) - m_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * m_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          m_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          m_y = 2.0 + n_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        db_y = NULL;
        m0 = mxCreateCharArray(2, iv22);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&db_y, m0);
        error(message(db_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = f_y->size[0] * f_y->size[1];
      f_y->size[0] = 1;
      f_y->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        f_y->data[0] = gamm;
        if (cdiff + 1 > 1) {
          f_y->data[cdiff] = m_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            f_y->data[k] = gamm + (real_T)kd;
            f_y->data[cdiff - k] = m_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            f_y->data[ndbl] = (gamm + m_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            f_y->data[ndbl] = gamm + (real_T)kd;
            f_y->data[ndbl + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = f_y->size[1];
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = f_y->size[0] * f_y->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + i_y) + f_y->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &w_emlrtDCI,
          emlrtRootTLSGlobal);
        r8->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &hc_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxInit_int32_T(&r17, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      i_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      m_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      i0 = r17->size[0] * r17->size[1];
      r17->size[0] = 1;
      r17->size[1] = r6->size[1];
      emxEnsureCapacity((emxArray__common *)r17, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + i_y) + r6->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &x_emlrtDCI,
          emlrtRootTLSGlobal);
        r17->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &ic_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r2->size[0];
      r2->size[0] = r17->size[1];
      emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r17->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r2->data[i0] = yhat->data[r17->data[i0] - 1];
      }

      emxFree_int32_T(&r17);
      b_emxInit_real_T(&f_ytilde, 1, &emlrtRTEI, TRUE);
      emxInit_int32_T(&r18, 2, &emlrtRTEI, TRUE);
      i0 = r18->size[0] * r18->size[1];
      r18->size[0] = 1;
      r18->size[1] = r7->size[1];
      emxEnsureCapacity((emxArray__common *)r18, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y = (9.0 + m_y) + r7->data[i0];
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &y_emlrtDCI,
          emlrtRootTLSGlobal);
        r18->data[i0] = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &jc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = f_ytilde->size[0];
      f_ytilde->size[0] = r18->size[1];
      emxEnsureCapacity((emxArray__common *)f_ytilde, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r18->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        f_ytilde->data[i0] = ytilde_data[r18->data[i0] - 1];
      }

      emxFree_int32_T(&r18);
      c_minangle(r2, f_ytilde);
      emlrtPopRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[1];
      apnd = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, apnd, &q_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r8->size[0] * r8->size[1];
      emxFree_real_T(&f_ytilde);
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r8->data[i0] - 1] = r2->data[i0];
      }

      emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      i_y = 3.0 * uk_data[(int32_T)((12.0 + c_y) + d_y) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (i_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == i_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((i_y - 3.0) / 3.0 + 0.5);
        m_y = b_ndbl * 3.0;
        lambda = (3.0 + m_y) - i_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * i_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          i_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          i_y = 3.0 + m_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        eb_y = NULL;
        m0 = mxCreateCharArray(2, iv23);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&eb_y, m0);
        error(message(eb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r6->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r6->data[cdiff] = i_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r6->data[k] = gamm + (real_T)kd;
            r6->data[cdiff - k] = i_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r6->data[ndbl] = (gamm + i_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r6->data[ndbl] = gamm + (real_T)kd;
            r6->data[ndbl + 1] = i_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, r6->size[1],
        &p_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      i_y = 3.0 * uk_data[(int32_T)((12.0 + c_y) + d_y) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (i_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(i_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == i_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((i_y - 3.0) / 3.0 + 0.5);
        m_y = b_ndbl * 3.0;
        lambda = (3.0 + m_y) - i_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * i_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          i_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          i_y = 3.0 + m_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        fb_y = NULL;
        m0 = mxCreateCharArray(2, iv24);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&fb_y, m0);
        error(message(fb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r7->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r7->data[cdiff] = i_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r7->data[k] = gamm + (real_T)kd;
            r7->data[cdiff - k] = i_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r7->data[ndbl] = (gamm + i_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r7->data[ndbl] = gamm + (real_T)kd;
            r7->data[ndbl + 1] = i_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, r7->size[1],
        &o_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      i_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      c_y = 3.0 * uk_data[(int32_T)((12.0 + c_y) + d_y) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (c_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == c_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((c_y - 3.0) / 3.0 + 0.5);
        d_y = b_ndbl * 3.0;
        lambda = (3.0 + d_y) - c_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * c_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          c_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          c_y = 3.0 + d_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        gb_y = NULL;
        m0 = mxCreateCharArray(2, iv25);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&gb_y, m0);
        error(message(gb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = f_y->size[0] * f_y->size[1];
      f_y->size[0] = 1;
      f_y->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        f_y->data[0] = gamm;
        if (cdiff + 1 > 1) {
          f_y->data[cdiff] = c_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            f_y->data[k] = gamm + (real_T)kd;
            f_y->data[cdiff - k] = c_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            f_y->data[ndbl] = (gamm + c_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            f_y->data[ndbl] = gamm + (real_T)kd;
            f_y->data[ndbl + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = f_y->size[1];
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = f_y->size[0] * f_y->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + i_y) + f_y->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &ab_emlrtDCI,
          emlrtRootTLSGlobal);
        r8->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &kc_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxInit_int32_T(&r19, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      d_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]);
      i0 = r19->size[0] * r19->size[1];
      r19->size[0] = 1;
      r19->size[1] = r6->size[1];
      emxEnsureCapacity((emxArray__common *)r19, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + c_y) + r6->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &bb_emlrtDCI,
          emlrtRootTLSGlobal);
        r19->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &lc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r2->size[0];
      r2->size[0] = r19->size[1];
      emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r19->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r2->data[i0] = yhat->data[r19->data[i0] - 1];
      }

      emxFree_int32_T(&r19);
      b_emxInit_real_T(&g_ytilde, 1, &emlrtRTEI, TRUE);
      emxInit_int32_T(&r20, 2, &emlrtRTEI, TRUE);
      i0 = r20->size[0] * r20->size[1];
      r20->size[0] = 1;
      r20->size[1] = r7->size[1];
      emxEnsureCapacity((emxArray__common *)r20, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y = (9.0 + d_y) + r7->data[i0];
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &cb_emlrtDCI,
          emlrtRootTLSGlobal);
        r20->data[i0] = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &mc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = g_ytilde->size[0];
      g_ytilde->size[0] = r20->size[1];
      emxEnsureCapacity((emxArray__common *)g_ytilde, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r20->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        g_ytilde->data[i0] = ytilde_data[r20->data[i0] - 1];
      }

      emxFree_int32_T(&r20);
      c_minangle(r2, g_ytilde);
      emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[1];
      apnd = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, apnd, &n_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r8->size[0] * r8->size[1];
      emxFree_real_T(&g_ytilde);
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r8->data[i0] - 1] = r2->data[i0];
      }

      emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[(int32_T)((((12.0 + e_y) + y) + uk_data[(int32_T)
        ((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)(11.0 + 3.0 *
        uk_data[9]) - 1]) - 1]) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (c_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == c_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((c_y - 2.0) / 3.0 + 0.5);
        d_y = b_ndbl * 3.0;
        lambda = (2.0 + d_y) - c_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * c_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          c_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          c_y = 2.0 + d_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        hb_y = NULL;
        m0 = mxCreateCharArray(2, iv26);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&hb_y, m0);
        error(message(hb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r6->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r6->data[cdiff] = c_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r6->data[k] = gamm + (real_T)kd;
            r6->data[cdiff - k] = c_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r6->data[ndbl] = (gamm + c_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r6->data[ndbl] = gamm + (real_T)kd;
            r6->data[ndbl + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, r6->size[1],
        &m_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[(int32_T)((((12.0 + e_y) + y) + uk_data[(int32_T)
        ((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)(11.0 + 3.0 *
        uk_data[9]) - 1]) - 1]) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (c_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == c_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((c_y - 2.0) / 3.0 + 0.5);
        d_y = b_ndbl * 3.0;
        lambda = (2.0 + d_y) - c_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * c_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          c_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          c_y = 2.0 + d_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        ib_y = NULL;
        m0 = mxCreateCharArray(2, iv27);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&ib_y, m0);
        error(message(ib_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r7->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r7->data[cdiff] = c_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r7->data[k] = gamm + (real_T)kd;
            r7->data[cdiff - k] = c_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r7->data[ndbl] = (gamm + c_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r7->data[ndbl] = gamm + (real_T)kd;
            r7->data[ndbl + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, r7->size[1],
        &l_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * ((uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]) + uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 *
        uk_data[(int32_T)(11.0 + 3.0 * uk_data[9]) - 1]) - 1]);
      d_y = 3.0 * uk_data[(int32_T)((((12.0 + e_y) + y) + uk_data[(int32_T)
        ((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)(11.0 + 3.0 *
        uk_data[9]) - 1]) - 1]) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(d_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (d_y < 2.0) {
        cdiff = -1;
        gamm = 2.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(d_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(2.0 == d_y);
      } else {
        gamm = 2.0;
        b_ndbl = muDoubleScalarFloor((d_y - 2.0) / 3.0 + 0.5);
        i_y = b_ndbl * 3.0;
        lambda = (2.0 + i_y) - d_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * d_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          d_y = 2.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          d_y = 2.0 + i_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        jb_y = NULL;
        m0 = mxCreateCharArray(2, iv28);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&jb_y, m0);
        error(message(jb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = f_y->size[0] * f_y->size[1];
      f_y->size[0] = 1;
      f_y->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        f_y->data[0] = gamm;
        if (cdiff + 1 > 1) {
          f_y->data[cdiff] = d_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            f_y->data[k] = gamm + (real_T)kd;
            f_y->data[cdiff - k] = d_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            f_y->data[ndbl] = (gamm + d_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            f_y->data[ndbl] = gamm + (real_T)kd;
            f_y->data[ndbl + 1] = d_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = f_y->size[1];
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = f_y->size[0] * f_y->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + c_y) + f_y->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &db_emlrtDCI,
          emlrtRootTLSGlobal);
        r8->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &nc_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxInit_int32_T(&r21, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * ((uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]) + uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 *
        uk_data[(int32_T)(11.0 + 3.0 * uk_data[9]) - 1]) - 1]);
      d_y = 3.0 * ((uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]) + uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 *
        uk_data[(int32_T)(11.0 + 3.0 * uk_data[9]) - 1]) - 1]);
      i0 = r21->size[0] * r21->size[1];
      r21->size[0] = 1;
      r21->size[1] = r6->size[1];
      emxEnsureCapacity((emxArray__common *)r21, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + c_y) + r6->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &eb_emlrtDCI,
          emlrtRootTLSGlobal);
        r21->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &oc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r2->size[0];
      r2->size[0] = r21->size[1];
      emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r21->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r2->data[i0] = yhat->data[r21->data[i0] - 1];
      }

      emxFree_int32_T(&r21);
      b_emxInit_real_T(&h_ytilde, 1, &emlrtRTEI, TRUE);
      emxInit_int32_T(&r22, 2, &emlrtRTEI, TRUE);
      i0 = r22->size[0] * r22->size[1];
      r22->size[0] = 1;
      r22->size[1] = r7->size[1];
      emxEnsureCapacity((emxArray__common *)r22, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y = (9.0 + d_y) + r7->data[i0];
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &fb_emlrtDCI,
          emlrtRootTLSGlobal);
        r22->data[i0] = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &pc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = h_ytilde->size[0];
      h_ytilde->size[0] = r22->size[1];
      emxEnsureCapacity((emxArray__common *)h_ytilde, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r22->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        h_ytilde->data[i0] = ytilde_data[r22->data[i0] - 1];
      }

      emxFree_int32_T(&r22);
      c_minangle(r2, h_ytilde);
      emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[1];
      apnd = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, apnd, &k_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r8->size[0] * r8->size[1];
      emxFree_real_T(&h_ytilde);
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r8->data[i0] - 1] = r2->data[i0];
      }

      emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[(int32_T)((((12.0 + e_y) + y) + uk_data[(int32_T)
        ((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)(11.0 + 3.0 *
        uk_data[9]) - 1]) - 1]) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (c_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == c_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((c_y - 3.0) / 3.0 + 0.5);
        d_y = b_ndbl * 3.0;
        lambda = (3.0 + d_y) - c_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * c_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          c_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          c_y = 3.0 + d_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        kb_y = NULL;
        m0 = mxCreateCharArray(2, iv29);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&kb_y, m0);
        error(message(kb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r6->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r6->data[cdiff] = c_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r6->data[k] = gamm + (real_T)kd;
            r6->data[cdiff - k] = c_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r6->data[ndbl] = (gamm + c_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r6->data[ndbl] = gamm + (real_T)kd;
            r6->data[ndbl + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, r6->size[1],
        &j_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[(int32_T)((((12.0 + e_y) + y) + uk_data[(int32_T)
        ((12.0 + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)(11.0 + 3.0 *
        uk_data[9]) - 1]) - 1]) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (c_y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == c_y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((c_y - 3.0) / 3.0 + 0.5);
        d_y = b_ndbl * 3.0;
        lambda = (3.0 + d_y) - c_y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * c_y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          c_y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          c_y = 3.0 + d_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        lb_y = NULL;
        m0 = mxCreateCharArray(2, iv30);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&lb_y, m0);
        error(message(lb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        r7->data[0] = gamm;
        if (cdiff + 1 > 1) {
          r7->data[cdiff] = c_y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            r7->data[k] = gamm + (real_T)kd;
            r7->data[cdiff - k] = c_y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            r7->data[ndbl] = (gamm + c_y) / 2.0;
          } else {
            kd = ndbl * 3U;
            r7->data[ndbl] = gamm + (real_T)kd;
            r7->data[ndbl + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, r7->size[1],
        &i_emlrtECI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * ((uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]) + uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 *
        uk_data[(int32_T)(11.0 + 3.0 * uk_data[9]) - 1]) - 1]);
      y = 3.0 * uk_data[(int32_T)((((12.0 + e_y) + y) + uk_data[(int32_T)((12.0
        + 3.0 * uk_data[9]) + 3.0 * uk_data[(int32_T)(11.0 + 3.0 * uk_data[9]) -
        1]) - 1]) + 1.0) - 1];
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = FALSE;
      } else if (y < 3.0) {
        cdiff = -1;
        gamm = 3.0;
        n_too_large = FALSE;
      } else if (muDoubleScalarIsInf(y)) {
        cdiff = 0;
        gamm = rtNaN;
        n_too_large = !(3.0 == y);
      } else {
        gamm = 3.0;
        b_ndbl = muDoubleScalarFloor((y - 3.0) / 3.0 + 0.5);
        d_y = b_ndbl * 3.0;
        lambda = (3.0 + d_y) - y;
        if (muDoubleScalarAbs(lambda) < 4.4408920985006262E-16 * y) {
          b_ndbl++;
        } else if (lambda > 0.0) {
          y = 3.0 + (b_ndbl - 1.0) * 3.0;
        } else {
          b_ndbl++;
          y = 3.0 + d_y;
        }

        n_too_large = (2.147483647E+9 < b_ndbl);
        if (b_ndbl >= 0.0) {
          cdiff = (int32_T)b_ndbl - 1;
        } else {
          cdiff = -1;
        }
      }

      emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      if (!n_too_large) {
      } else {
        emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        mb_y = NULL;
        m0 = mxCreateCharArray(2, iv31);
        for (ndbl = 0; ndbl < 21; ndbl++) {
          cv4[ndbl] = cv6[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
        emlrtAssign(&mb_y, m0);
        error(message(mb_y, &b_emlrtMCI), &c_emlrtMCI);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = f_y->size[0] * f_y->size[1];
      f_y->size[0] = 1;
      f_y->size[1] = cdiff + 1;
      emxEnsureCapacity((emxArray__common *)f_y, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      if (cdiff + 1 > 0) {
        f_y->data[0] = gamm;
        if (cdiff + 1 > 1) {
          f_y->data[cdiff] = y;
          i0 = cdiff + (cdiff < 0);
          if (i0 >= 0) {
            ndbl = (int32_T)((uint32_T)i0 >> 1);
          } else {
            ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k < ndbl; k++) {
            kd = k * 3U;
            f_y->data[k] = gamm + (real_T)kd;
            f_y->data[cdiff - k] = y - (real_T)kd;
          }

          if (ndbl << 1 == cdiff) {
            f_y->data[ndbl] = (gamm + y) / 2.0;
          } else {
            kd = ndbl * 3U;
            f_y->data[ndbl] = gamm + (real_T)kd;
            f_y->data[ndbl + 1] = y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = f_y->size[1];
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = f_y->size[0] * f_y->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + c_y) + f_y->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &gb_emlrtDCI,
          emlrtRootTLSGlobal);
        r8->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &qc_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxInit_int32_T(&r23, 2, &emlrtRTEI, TRUE);
      emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
      y = 3.0 * ((uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0)
                  - 1]) + uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 *
                  uk_data[(int32_T)(11.0 + 3.0 * uk_data[9]) - 1]) - 1]);
      c_y = 3.0 * ((uk_data[9] + uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) +
        1.0) - 1]) + uk_data[(int32_T)((12.0 + 3.0 * uk_data[9]) + 3.0 *
        uk_data[(int32_T)(11.0 + 3.0 * uk_data[9]) - 1]) - 1]);
      i0 = r23->size[0] * r23->size[1];
      r23->size[0] = 1;
      r23->size[1] = r6->size[1];
      emxEnsureCapacity((emxArray__common *)r23, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        apnd = yhat->size[0];
        b_y = (9.0 + y) + r6->data[i0];
        absb = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &hb_emlrtDCI,
          emlrtRootTLSGlobal);
        r23->data[i0] = emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &rc_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxFree_real_T(&r6);
      i0 = r2->size[0];
      r2->size[0] = r23->size[1];
      emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r23->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r2->data[i0] = yhat->data[r23->data[i0] - 1];
      }

      emxFree_int32_T(&r23);
      b_emxInit_real_T(&i_ytilde, 1, &emlrtRTEI, TRUE);
      emxInit_int32_T(&r24, 2, &emlrtRTEI, TRUE);
      i0 = r24->size[0] * r24->size[1];
      r24->size[0] = 1;
      r24->size[1] = r7->size[1];
      emxEnsureCapacity((emxArray__common *)r24, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y = (9.0 + c_y) + r7->data[i0];
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &ib_emlrtDCI,
          emlrtRootTLSGlobal);
        r24->data[i0] = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &sc_emlrtBCI, emlrtRootTLSGlobal);
      }

      emxFree_real_T(&r7);
      i0 = i_ytilde->size[0];
      i_ytilde->size[0] = r24->size[1];
      emxEnsureCapacity((emxArray__common *)i_ytilde, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = r24->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        i_ytilde->data[i0] = ytilde_data[r24->data[i0] - 1];
      }

      emxFree_int32_T(&r24);
      c_minangle(r2, i_ytilde);
      emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r8->size[1];
      apnd = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, apnd, &h_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = r8->size[0] * r8->size[1];
      emxFree_real_T(&i_ytilde);
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r8->data[i0] - 1] = r2->data[i0];
      }

      emxFree_int32_T(&r8);
      i0 = yhat->size[0];
      emlrtSizeEqCheck1DFastR2012b(ytilde_size[0], i0, &g_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
      loop_ub = ytilde_size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_data[i0] = ytilde_data[i0] - yhat->data[i0];
      }

      emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      if (!(Kk->size[1] == ytilde_size[0])) {
        if (((Kk->size[0] == 1) && (Kk->size[1] == 1)) || (ytilde_size[0] == 1))
        {
          emlrtPushRtStackR2012b(&mh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          nb_y = NULL;
          m0 = mxCreateCharArray(2, iv32);
          for (ndbl = 0; ndbl < 45; ndbl++) {
            cv2[ndbl] = cv3[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m0, cv2);
          emlrtAssign(&nb_y, m0);
          error(message(nb_y, &l_emlrtMCI), &m_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&mh_emlrtRSI, emlrtRootTLSGlobal);
        } else {
          emlrtPushRtStackR2012b(&lh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          ob_y = NULL;
          m0 = mxCreateCharArray(2, iv33);
          for (ndbl = 0; ndbl < 21; ndbl++) {
            cv4[ndbl] = cv5[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
          emlrtAssign(&ob_y, m0);
          error(message(ob_y, &n_emlrtMCI), &o_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&lh_emlrtRSI, emlrtRootTLSGlobal);
        }
      }

      emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      if ((Kk->size[1] == 1) || (ytilde_size[0] == 1)) {
        ndbl = Kk->size[0];
        loop_ub = Kk->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          C_data[i0] = 0.0;
          cdiff = Kk->size[1];
          for (apnd = 0; apnd < cdiff; apnd++) {
            gamm = C_data[i0] + Kk->data[i0 + Kk->size[0] * apnd] * b_data[apnd];
            C_data[i0] = gamm;
          }
        }
      } else {
        kd = (uint32_T)Kk->size[0];
        emlrtPushRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&nh_emlrtRSI, emlrtRootTLSGlobal);
        ndbl = (int32_T)kd;
        loop_ub = (int32_T)kd;
        for (i0 = 0; i0 < loop_ub; i0++) {
          C_data[i0] = 0.0;
        }

        if ((Kk->size[0] < 1) || (Kk->size[1] < 1)) {
        } else {
          emlrtPushRtStackR2012b(&ph_emlrtRSI, emlrtRootTLSGlobal);
          gamm = 1.0;
          b_ndbl = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          m_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          n_t = (ptrdiff_t)(1);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          k_t = (ptrdiff_t)(Kk->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          lda_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldb_t = (ptrdiff_t)(Kk->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldc_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          alpha1_t = (double *)(&gamm);
          emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&di_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Aia0_t = (double *)(&Kk->data[0]);
          emlrtPopRtStackR2012b(&di_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ei_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Bib0_t = (double *)(&b_data[0]);
          emlrtPopRtStackR2012b(&ei_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&fi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          beta1_t = (double *)(&b_ndbl);
          emlrtPopRtStackR2012b(&fi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Cic0_t = (double *)(&C_data[0]);
          emlrtPopRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t,
                Bib0_t, &ldb_t, beta1_t, Cic0_t, &ldc_t);
          emlrtPopRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ph_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&nh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
      i0 = xnew_size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, ndbl, &f_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = xnew_size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        xnew_data[i0] += C_data[i0];
      }

      /*  renormalize quaternions as necessary */
      emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &e_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &d_emlrtECI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 4; i0++) {
        apnd = xnew_size[0];
        absb = 7 + i0;
        emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &tc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      for (i0 = 0; i0 < 4; i0++) {
        apnd = xnew_size[0];
        absb = 7 + i0;
        xnew[i0] = xnew_data[emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &uc_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      gamm = e_norm(xnew);
      ndbl = xnew_size[0];
      for (i0 = 0; i0 < 4; i0++) {
        xnew[i0] = xnew_data[i0 + 6] / gamm;
      }

      for (i0 = 0; i0 < 4; i0++) {
        apnd = 7 + i0;
        xnew_data[emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ndbl, &vc_emlrtBCI,
          emlrtRootTLSGlobal) - 1] = xnew[i0];
      }

      emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &c_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &b_emlrtECI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 4; i0++) {
        apnd = xnew_size[0];
        absb = 14 + i0;
        emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd, &wc_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      for (i0 = 0; i0 < 4; i0++) {
        apnd = xnew_size[0];
        absb = 14 + i0;
        xnew[i0] = xnew_data[emlrtDynamicBoundsCheckFastR2012b(absb, 1, apnd,
          &xc_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      gamm = e_norm(xnew);
      ndbl = xnew_size[0];
      for (i0 = 0; i0 < 4; i0++) {
        xnew[i0] = xnew_data[i0 + 13] / gamm;
      }

      for (i0 = 0; i0 < 4; i0++) {
        apnd = 14 + i0;
        xnew_data[emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ndbl, &yc_emlrtBCI,
          emlrtRootTLSGlobal) - 1] = xnew[i0];
      }

      emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      if (!(Kk->size[1] == Pyk->size[0])) {
        if (((Kk->size[0] == 1) && (Kk->size[1] == 1)) || ((Pyk->size[0] == 1) &&
             (Pyk->size[1] == 1))) {
          emlrtPushRtStackR2012b(&mh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          pb_y = NULL;
          m0 = mxCreateCharArray(2, iv34);
          for (ndbl = 0; ndbl < 45; ndbl++) {
            cv2[ndbl] = cv3[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m0, cv2);
          emlrtAssign(&pb_y, m0);
          error(message(pb_y, &l_emlrtMCI), &m_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&mh_emlrtRSI, emlrtRootTLSGlobal);
        } else {
          emlrtPushRtStackR2012b(&lh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          qb_y = NULL;
          m0 = mxCreateCharArray(2, iv35);
          for (ndbl = 0; ndbl < 21; ndbl++) {
            cv4[ndbl] = cv5[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
          emlrtAssign(&qb_y, m0);
          error(message(qb_y, &n_emlrtMCI), &o_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&lh_emlrtRSI, emlrtRootTLSGlobal);
        }
      }

      emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      emxInit_real_T(&rb_y, 2, &emlrtRTEI, TRUE);
      if ((Kk->size[1] == 1) || (Pyk->size[0] == 1)) {
        i0 = rb_y->size[0] * rb_y->size[1];
        rb_y->size[0] = Kk->size[0];
        rb_y->size[1] = Pyk->size[1];
        emxEnsureCapacity((emxArray__common *)rb_y, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = Kk->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          cdiff = Pyk->size[1];
          for (apnd = 0; apnd < cdiff; apnd++) {
            rb_y->data[i0 + rb_y->size[0] * apnd] = 0.0;
            ndbl = Kk->size[1];
            for (absb = 0; absb < ndbl; absb++) {
              rb_y->data[i0 + rb_y->size[0] * apnd] += Kk->data[i0 + Kk->size[0]
                * absb] * Pyk->data[absb + Pyk->size[0] * apnd];
            }
          }
        }
      } else {
        kd = (uint32_T)Kk->size[0];
        unnamed_idx_1 = (uint32_T)Pyk->size[1];
        i0 = r5->size[0] * r5->size[1];
        r5->size[0] = (int32_T)kd;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = r5->size[0] * r5->size[1];
        r5->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)kd * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          r5->data[i0] = 0.0;
        }

        emlrtPushRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&nh_emlrtRSI, emlrtRootTLSGlobal);
        i0 = rb_y->size[0] * rb_y->size[1];
        rb_y->size[0] = (int32_T)kd;
        emxEnsureCapacity((emxArray__common *)rb_y, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = rb_y->size[0] * rb_y->size[1];
        rb_y->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)rb_y, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)kd * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          rb_y->data[i0] = 0.0;
        }

        if ((Kk->size[0] < 1) || (Pyk->size[1] < 1) || (Kk->size[1] < 1)) {
        } else {
          emlrtPushRtStackR2012b(&ph_emlrtRSI, emlrtRootTLSGlobal);
          gamm = 1.0;
          b_ndbl = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          m_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          n_t = (ptrdiff_t)(Pyk->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          k_t = (ptrdiff_t)(Kk->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          lda_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldb_t = (ptrdiff_t)(Kk->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldc_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          alpha1_t = (double *)(&gamm);
          emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&di_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Aia0_t = (double *)(&Kk->data[0]);
          emlrtPopRtStackR2012b(&di_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ei_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Bib0_t = (double *)(&Pyk->data[0]);
          emlrtPopRtStackR2012b(&ei_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&fi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          beta1_t = (double *)(&b_ndbl);
          emlrtPopRtStackR2012b(&fi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Cic0_t = (double *)(&rb_y->data[0]);
          emlrtPopRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t,
                Bib0_t, &ldb_t, beta1_t, Cic0_t, &ldc_t);
          emlrtPopRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ph_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&nh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
      }

      i0 = b->size[0] * b->size[1];
      b->size[0] = Kk->size[1];
      b->size[1] = Kk->size[0];
      emxEnsureCapacity((emxArray__common *)b, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = Kk->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        cdiff = Kk->size[1];
        for (apnd = 0; apnd < cdiff; apnd++) {
          b->data[apnd + b->size[0] * i0] = Kk->data[i0 + Kk->size[0] * apnd];
        }
      }

      emxFree_real_T(&Kk);
      emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      if (!(rb_y->size[1] == b->size[0])) {
        if (((rb_y->size[0] == 1) && (rb_y->size[1] == 1)) || ((b->size[0] == 1)
             && (b->size[1] == 1))) {
          emlrtPushRtStackR2012b(&mh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          sb_y = NULL;
          m0 = mxCreateCharArray(2, iv36);
          for (ndbl = 0; ndbl < 45; ndbl++) {
            cv2[ndbl] = cv3[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m0, cv2);
          emlrtAssign(&sb_y, m0);
          error(message(sb_y, &l_emlrtMCI), &m_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&mh_emlrtRSI, emlrtRootTLSGlobal);
        } else {
          emlrtPushRtStackR2012b(&lh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          tb_y = NULL;
          m0 = mxCreateCharArray(2, iv37);
          for (ndbl = 0; ndbl < 21; ndbl++) {
            cv4[ndbl] = cv5[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv4);
          emlrtAssign(&tb_y, m0);
          error(message(tb_y, &n_emlrtMCI), &o_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&lh_emlrtRSI, emlrtRootTLSGlobal);
        }
      }

      emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      if ((rb_y->size[1] == 1) || (b->size[0] == 1)) {
        i0 = Pxkyk->size[0] * Pxkyk->size[1];
        Pxkyk->size[0] = rb_y->size[0];
        Pxkyk->size[1] = b->size[1];
        emxEnsureCapacity((emxArray__common *)Pxkyk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = rb_y->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          cdiff = b->size[1];
          for (apnd = 0; apnd < cdiff; apnd++) {
            Pxkyk->data[i0 + Pxkyk->size[0] * apnd] = 0.0;
            ndbl = rb_y->size[1];
            for (absb = 0; absb < ndbl; absb++) {
              Pxkyk->data[i0 + Pxkyk->size[0] * apnd] += rb_y->data[i0 +
                rb_y->size[0] * absb] * b->data[absb + b->size[0] * apnd];
            }
          }
        }
      } else {
        kd = (uint32_T)rb_y->size[0];
        unnamed_idx_1 = (uint32_T)b->size[1];
        i0 = r5->size[0] * r5->size[1];
        r5->size[0] = (int32_T)kd;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = r5->size[0] * r5->size[1];
        r5->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)kd * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          r5->data[i0] = 0.0;
        }

        emlrtPushRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&nh_emlrtRSI, emlrtRootTLSGlobal);
        i0 = Pxkyk->size[0] * Pxkyk->size[1];
        Pxkyk->size[0] = (int32_T)kd;
        emxEnsureCapacity((emxArray__common *)Pxkyk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = Pxkyk->size[0] * Pxkyk->size[1];
        Pxkyk->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)Pxkyk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)kd * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          Pxkyk->data[i0] = 0.0;
        }

        if ((rb_y->size[0] < 1) || (b->size[1] < 1) || (rb_y->size[1] < 1)) {
        } else {
          emlrtPushRtStackR2012b(&ph_emlrtRSI, emlrtRootTLSGlobal);
          gamm = 1.0;
          b_ndbl = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          m_t = (ptrdiff_t)(rb_y->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          n_t = (ptrdiff_t)(b->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          k_t = (ptrdiff_t)(rb_y->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          lda_t = (ptrdiff_t)(rb_y->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldb_t = (ptrdiff_t)(rb_y->size[1]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldc_t = (ptrdiff_t)(rb_y->size[0]);
          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          alpha1_t = (double *)(&gamm);
          emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&di_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Aia0_t = (double *)(&rb_y->data[0]);
          emlrtPopRtStackR2012b(&di_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ei_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Bib0_t = (double *)(&b->data[0]);
          emlrtPopRtStackR2012b(&ei_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&fi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          beta1_t = (double *)(&b_ndbl);
          emlrtPopRtStackR2012b(&fi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Cic0_t = (double *)(&Pxkyk->data[0]);
          emlrtPopRtStackR2012b(&gi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t,
                Bib0_t, &ldb_t, beta1_t, Cic0_t, &ldc_t);
          emlrtPopRtStackR2012b(&hi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ph_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&nh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
      }

      emxFree_real_T(&r5);
      emxFree_real_T(&rb_y);
      emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 2; i0++) {
        b_Pnew[i0] = Pnew->size[i0];
      }

      for (i0 = 0; i0 < 2; i0++) {
        XAUGPLUS[i0] = Pxkyk->size[i0];
      }

      emlrtSizeEqCheck2DFastR2012b(b_Pnew, XAUGPLUS, &emlrtECI,
        emlrtRootTLSGlobal);
      i0 = Pnew->size[0] * Pnew->size[1];
      emxEnsureCapacity((emxArray__common *)Pnew, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ndbl = Pnew->size[0];
      cdiff = Pnew->size[1];
      loop_ub = ndbl * cdiff;
      for (i0 = 0; i0 < loop_ub; i0++) {
        Pnew->data[i0] -= Pxkyk->data[i0];
      }
    }

    emxFree_real_T(&r2);
    emxFree_real_T(&b);
    emxFree_real_T(&Pxkyk);
    emxFree_real_T(&Pyk);
    emxFree_real_T(&yhat);
    emxFree_real_T(&YKAUG);
  }

  emxFree_real_T(&f_y);
  emxFree_creal_T(&Psq);
  emxFree_real_T(&Paug);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (ukf_update_unknown_state.c) */
