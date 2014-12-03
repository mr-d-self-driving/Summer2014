/*
 * ukf_update_10_state.c
 *
 * Code generation for function 'ukf_update_10_state'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "ukf_update_10_state_emxutil.h"
#include "fprintf.h"
#include "ukf_update_10_state_mexutil.h"
#include "norm.h"
#include "minangle.h"
#include "mldivide.h"
#include "eye.h"
#include "rank.h"
#include "any.h"
#include "sum.h"
#include "repmat.h"
#include "measurement_eq_10_state.h"
#include "update_eq_10_state.h"
#include "sqrtm.h"
#include "sqrt.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 89, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo b_emlrtRSI = { 96, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo c_emlrtRSI = { 22, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo d_emlrtRSI = { 27, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo e_emlrtRSI = { 28, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo f_emlrtRSI = { 32, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo g_emlrtRSI = { 34, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo h_emlrtRSI = { 50, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo i_emlrtRSI = { 60, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo j_emlrtRSI = { 71, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo k_emlrtRSI = { 75, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo l_emlrtRSI = { 88, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo m_emlrtRSI = { 95, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo n_emlrtRSI = { 99, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo o_emlrtRSI = { 103, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo p_emlrtRSI = { 104, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo q_emlrtRSI = { 105, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRSInfo r_emlrtRSI = { 110, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtMCInfo emlrtMCI = { 89, 5, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtMCInfo b_emlrtMCI = { 96, 5, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 24, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 25, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 42, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 50, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 71, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 75, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 79, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 81, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 99, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo emlrtECI = { 2, 110, 8, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo b_emlrtECI = { -1, 108, 26, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo c_emlrtECI = { -1, 108, 12, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo d_emlrtECI = { -1, 105, 6, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo e_emlrtECI = { -1, 105, 15, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo f_emlrtECI = { -1, 104, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 104, 1, "yhat", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo emlrtDCI = { 104, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtECInfo g_emlrtECI = { -1, 104, 52, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo b_emlrtBCI = { -1, -1, 104, 52, "ytilde",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 104, 52, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtECInfo h_emlrtECI = { -1, 104, 32, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo c_emlrtBCI = { -1, -1, 104, 32, "yhat", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo c_emlrtDCI = { 104, 32, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtECInfo i_emlrtECI = { -1, 103, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 103, 1, "yhat", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo d_emlrtDCI = { 103, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtECInfo j_emlrtECI = { -1, 103, 52, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo e_emlrtBCI = { -1, -1, 103, 52, "ytilde",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo e_emlrtDCI = { 103, 52, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtECInfo k_emlrtECI = { -1, 103, 32, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo f_emlrtBCI = { -1, -1, 103, 32, "yhat", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo f_emlrtDCI = { 103, 32, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 102, 6, "uk", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo l_emlrtECI = { 2, 84, 13, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo m_emlrtECI = { -1, 84, 49, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo h_emlrtBCI = { -1, -1, 84, 57, "YKAUG", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo n_emlrtECI = { -1, 84, 28, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo i_emlrtBCI = { -1, -1, 84, 41, "XAUGPLUS",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 84, 37, "XAUGPLUS",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 84, 21, "wc", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo o_emlrtECI = { 2, 83, 11, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo p_emlrtECI = { -1, 83, 42, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo l_emlrtBCI = { -1, -1, 83, 50, "YKAUG", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo q_emlrtECI = { -1, 83, 24, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo m_emlrtBCI = { -1, -1, 83, 32, "YKAUG", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 83, 17, "wc", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo r_emlrtECI = { 2, 75, 12, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo o_emlrtBCI = { -1, -1, 71, 42, "XAUGPLUS",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo s_emlrtECI = { 2, 67, 10, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo t_emlrtECI = { -1, 67, 43, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo p_emlrtBCI = { -1, -1, 67, 56, "XAUGPLUS",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 67, 52, "XAUGPLUS",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo u_emlrtECI = { -1, 67, 22, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo r_emlrtBCI = { -1, -1, 67, 35, "XAUGPLUS",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 67, 31, "XAUGPLUS",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 67, 15, "wc", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo v_emlrtECI = { -1, 63, 26, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo w_emlrtECI = { -1, 63, 12, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo x_emlrtECI = { 2, 60, 10, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo u_emlrtBCI = { -1, -1, 60, 19, "XAUGPLUS",
  "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 50, 36, "XAUG", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo y_emlrtECI = { -1, 46, 5, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo w_emlrtBCI = { -1, -1, 46, 12, "XAUG", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo ab_emlrtECI = { -1, 45, 5, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo x_emlrtBCI = { -1, -1, 45, 12, "XAUG", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo bb_emlrtECI = { -1, 43, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo cb_emlrtECI = { -1, 46, 21, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo y_emlrtBCI = { -1, -1, 46, 39, "Psq", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo db_emlrtECI = { -1, 45, 19, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 45, 37, "Psq", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtECInfo eb_emlrtECI = { -1, 28, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo fb_emlrtECI = { -1, 27, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtECInfo gb_emlrtECI = { -1, 26, 1, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m"
};

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 26, 10, "Paug", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 26, 6, "Paug", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 14, 6, "uk", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 27, 6, "Paug", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo g_emlrtDCI = { 27, 6, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 27, 15, "Paug", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo h_emlrtDCI = { 27, 15, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 28, 6, "Paug", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo i_emlrtDCI = { 28, 6, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 28, 18, "Paug", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo j_emlrtDCI = { 28, 18, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 50, 48, "XAUG", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo k_emlrtDCI = { 50, 48, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 63, 12, "xp", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 63, 26, "xp", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 63, 1, "xp", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 71, 54, "XAUG", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtDCInfo l_emlrtDCI = { 71, 54, "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  1 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 108, 12, "xn", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 108, 26, "xn", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 108, 1, "xn", "ukf_update_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/ukf_update_10_state.m",
  0 };

/* Function Definitions */
void ukf_update_10_state(const real_T xk_data[100], const int32_T xk_size[1],
  const emxArray_real_T *Pxk, const emxArray_real_T *Pvk, const emxArray_real_T *
  Pnk, const real_T uk_data[500], const int32_T uk_size[1], const real_T
  ytilde_data[500], const int32_T ytilde_size[1], real_T alpha, real_T
  xnew_data[100], int32_T xnew_size[1], emxArray_real_T *Pnew)
{
  emxArray_real_T *Paug;
  int32_T N;
  real_T lambda;
  real_T gamm;
  int32_T i0;
  int32_T loop_ub;
  int32_T cdiff;
  int32_T tmp_data[100];
  int32_T b_tmp_data[100];
  int32_T iv0[2];
  int32_T i1;
  int32_T apnd;
  int32_T ndbl;
  int32_T absb;
  emxArray_real_T *y;
  int32_T c_tmp_data[500];
  int32_T tmp_size_idx_1;
  real_T d0;
  int32_T i2;
  int32_T d_tmp_data[500];
  int32_T e_tmp_data[500];
  int32_T XAUGPLUS[2];
  int32_T b_Pnew[2];
  int32_T xaug_size[1];
  real_T xaug_data[1100];
  emxArray_creal_T *Psq;
  real_T resnorm;
  emxArray_real_T *XAUG;
  int32_T b_y;
  int32_T f_tmp_data[1100];
  int32_T iv1[1];
  emxArray_real_T *c_y;
  int32_T iv2[1];
  int32_T iv3[1];
  emxArray_real_T *b_XAUG;
  emxArray_real_T *c_XAUG;
  emxArray_real_T *b_XAUGPLUS;
  real_T wc_data[2201];
  real_T wm_data[2201];
  real_T b_wm_data[2201];
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
  boolean_T b0;
  const mxArray *d_y;
  static const int32_T iv4[2] = { 1, 31 };

  const mxArray *m0;
  char_T cv0[31];
  static const char_T cv1[31] = { 'S', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ',
    'm', 'e', 'a', 's', 'u', 'r', 'e', 'm', 'e', 'n', 't', ' ', 'c', 'o', 'v',
    'a', 'r', 'i', 'a', 'n', 'c', 'e' };

  const mxArray *e_y;
  static const int32_T iv5[2] = { 1, 5 };

  char_T cv2[5];
  static const char_T cv3[5] = { 'p', 'a', 'u', 's', 'e' };

  emxArray_real_T *b_b;
  const mxArray *f_y;
  static const int32_T iv6[2] = { 1, 45 };

  char_T cv4[45];
  static const char_T cv5[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D',
    'y', 'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p',
    'a', 'n', 's', 'i', 'o', 'n' };

  const mxArray *g_y;
  static const int32_T iv7[2] = { 1, 21 };

  char_T cv6[21];
  static const char_T cv7[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  emxArray_real_T *Kk;
  emxArray_real_T *r5;
  uint32_T unnamed_idx_0;
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
  real_T b_ytilde_data[500];
  int32_T b_ytilde_size[1];
  emxArray_int32_T *r6;
  emxArray_real_T c_ytilde_data;
  emxArray_int32_T *r7;
  real_T d_ytilde_data[500];
  int32_T c_ytilde_size[1];
  emxArray_int32_T *r8;
  emxArray_real_T e_ytilde_data;
  real_T b_data[500];
  const mxArray *h_y;
  static const int32_T iv8[2] = { 1, 45 };

  const mxArray *i_y;
  static const int32_T iv9[2] = { 1, 21 };

  real_T C_data[100];
  const mxArray *j_y;
  static const int32_T iv10[2] = { 1, 45 };

  const mxArray *k_y;
  static const int32_T iv11[2] = { 1, 21 };

  emxArray_real_T *l_y;
  const mxArray *m_y;
  static const int32_T iv12[2] = { 1, 45 };

  const mxArray *n_y;
  static const int32_T iv13[2] = { 1, 21 };

  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&Paug, 2, &c_emlrtRTEI, TRUE);

  /*  Pxk: covariance associated with state */
  /*  Pvk: covariance associated with process noise */
  /*  Pnk: covariance assocaited with measurement noise */
  /*  vector lengths */
  N = (xk_size[0] + Pnk->size[0]) + Pvk->size[0];

  /*  number of known features seen by agents i and j (1 and 2) */
  emlrtDynamicBoundsCheckFastR2012b(7, 1, uk_size[0], &db_emlrtBCI,
    emlrtRootTLSGlobal);

  /*  constant gamma that influences sigma points */
  lambda = alpha * alpha * (real_T)N - (real_T)N;
  emlrtPushRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  gamm = (real_T)N + lambda;
  b_sqrt(&gamm);
  emlrtPopRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);

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
    emlrtDynamicBoundsCheckFastR2012b(1, 1, N, &cb_emlrtBCI, emlrtRootTLSGlobal);
    loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, N, &cb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  if (1 > xk_size[0]) {
    cdiff = 0;
  } else {
    emlrtDynamicBoundsCheckFastR2012b(1, 1, N, &bb_emlrtBCI, emlrtRootTLSGlobal);
    cdiff = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, N, &bb_emlrtBCI,
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
    &gb_emlrtECI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < cdiff; i0++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      Paug->data[tmp_data[i1] + Paug->size[0] * b_tmp_data[i0]] = Pxk->data[i1 +
        loop_ub * i0];
    }
  }

  emlrtPushRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
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

  emxInit_real_T(&y, 2, &emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  i0 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (cdiff + 1 > 0) {
    y->data[0] = 1.0;
    if (cdiff + 1 > 1) {
      y->data[cdiff] = apnd;
      i0 = cdiff + (cdiff < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      for (absb = 1; absb < ndbl; absb++) {
        y->data[absb] = 1.0 + (real_T)absb;
        y->data[cdiff - absb] = apnd - absb;
      }

      if (ndbl << 1 == cdiff) {
        y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[ndbl] = 1.0 + (real_T)ndbl;
        y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  tmp_size_idx_1 = y->size[1];
  loop_ub = y->size[0] * y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = Paug->size[0];
    d0 = (real_T)xk_size[0] + y->data[i0];
    i2 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &g_emlrtDCI,
      emlrtRootTLSGlobal);
    c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &eb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < tmp_size_idx_1; i0++) {
    d_tmp_data[i0] = c_tmp_data[i0] - 1;
  }

  emlrtPopRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
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

  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  i0 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (cdiff + 1 > 0) {
    y->data[0] = 1.0;
    if (cdiff + 1 > 1) {
      y->data[cdiff] = apnd;
      i0 = cdiff + (cdiff < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      for (absb = 1; absb < ndbl; absb++) {
        y->data[absb] = 1.0 + (real_T)absb;
        y->data[cdiff - absb] = apnd - absb;
      }

      if (ndbl << 1 == cdiff) {
        y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[ndbl] = 1.0 + (real_T)ndbl;
        y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  ndbl = y->size[1];
  loop_ub = y->size[0] * y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = Paug->size[1];
    d0 = (real_T)xk_size[0] + y->data[i0];
    i2 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &h_emlrtDCI,
      emlrtRootTLSGlobal);
    c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &fb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < ndbl; i0++) {
    e_tmp_data[i0] = c_tmp_data[i0] - 1;
  }

  emlrtPopRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  XAUGPLUS[0] = tmp_size_idx_1;
  XAUGPLUS[1] = ndbl;
  emlrtSubAssignSizeCheckR2012b(XAUGPLUS, 2, *(int32_T (*)[2])Pvk->size, 2,
    &fb_emlrtECI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < ndbl; i0++) {
    for (i1 = 0; i1 < tmp_size_idx_1; i1++) {
      Paug->data[d_tmp_data[i1] + Paug->size[0] * e_tmp_data[i0]] = Pvk->data[i1
        + tmp_size_idx_1 * i0];
    }
  }

  emlrtPushRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
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

  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  i0 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (cdiff + 1 > 0) {
    y->data[0] = 1.0;
    if (cdiff + 1 > 1) {
      y->data[cdiff] = apnd;
      i0 = cdiff + (cdiff < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      for (absb = 1; absb < ndbl; absb++) {
        y->data[absb] = 1.0 + (real_T)absb;
        y->data[cdiff - absb] = apnd - absb;
      }

      if (ndbl << 1 == cdiff) {
        y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[ndbl] = 1.0 + (real_T)ndbl;
        y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  tmp_size_idx_1 = y->size[1];
  cdiff = (int16_T)((int16_T)xk_size[0] + (int16_T)Pvk->size[0]);
  loop_ub = y->size[0] * y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = Paug->size[0];
    d0 = (real_T)cdiff + y->data[i0];
    i2 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &i_emlrtDCI,
      emlrtRootTLSGlobal);
    c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &gb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < tmp_size_idx_1; i0++) {
    d_tmp_data[i0] = c_tmp_data[i0] - 1;
  }

  emlrtPopRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
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

  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  i0 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = cdiff + 1;
  emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  if (cdiff + 1 > 0) {
    y->data[0] = 1.0;
    if (cdiff + 1 > 1) {
      y->data[cdiff] = apnd;
      i0 = cdiff + (cdiff < 0);
      if (i0 >= 0) {
        ndbl = (int32_T)((uint32_T)i0 >> 1);
      } else {
        ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
      for (absb = 1; absb < ndbl; absb++) {
        y->data[absb] = 1.0 + (real_T)absb;
        y->data[cdiff - absb] = apnd - absb;
      }

      if (ndbl << 1 == cdiff) {
        y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
      } else {
        y->data[ndbl] = 1.0 + (real_T)ndbl;
        y->data[ndbl + 1] = apnd - ndbl;
      }
    }
  }

  emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  ndbl = y->size[1];
  cdiff = (int16_T)((int16_T)xk_size[0] + (int16_T)Pvk->size[0]);
  loop_ub = y->size[0] * y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = Paug->size[1];
    d0 = (real_T)cdiff + y->data[i0];
    i2 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &j_emlrtDCI,
      emlrtRootTLSGlobal);
    c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &hb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < ndbl; i0++) {
    e_tmp_data[i0] = c_tmp_data[i0] - 1;
  }

  emlrtPopRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
  b_Pnew[0] = tmp_size_idx_1;
  b_Pnew[1] = ndbl;
  emlrtSubAssignSizeCheckR2012b(b_Pnew, 2, *(int32_T (*)[2])Pnk->size, 2,
    &eb_emlrtECI, emlrtRootTLSGlobal);
  for (i0 = 0; i0 < ndbl; i0++) {
    for (i1 = 0; i1 < tmp_size_idx_1; i1++) {
      Paug->data[d_tmp_data[i1] + Paug->size[0] * e_tmp_data[i0]] = Pnk->data[i1
        + tmp_size_idx_1 * i0];
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
  emlrtPushRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
  sqrtm(Paug, Psq, &resnorm);
  emlrtPopRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
  if (muDoubleScalarAbs(resnorm) > 1.0E-14) {
    emlrtPushRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
    b_fprintf(resnorm);
    emlrtPopRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
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
    b_y = (N << 1) + 1;
    i0 = XAUG->size[0] * XAUG->size[1];
    XAUG->size[0] = N;
    XAUG->size[1] = b_y;
    emxEnsureCapacity((emxArray__common *)XAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = N * b_y;
    for (i0 = 0; i0 < loop_ub; i0++) {
      XAUG->data[i0] = 0.0;
    }

    for (i0 = 0; i0 < N; i0++) {
      f_tmp_data[i0] = i0;
    }

    iv1[0] = N;
    emlrtSubAssignSizeCheckR2012b(iv1, 1, xaug_size, 1, &bb_emlrtECI,
      emlrtRootTLSGlobal);
    loop_ub = xaug_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      XAUG->data[f_tmp_data[i0]] = xaug_data[i0];
    }

    absb = 0;
    b_emxInit_real_T(&c_y, 1, &emlrtRTEI, TRUE);
    while (absb <= N - 1) {
      i0 = Paug->size[1];
      i1 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &ab_emlrtBCI,
        emlrtRootTLSGlobal);
      loop_ub = Paug->size[0];
      i0 = c_y->size[0];
      c_y->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)c_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_y->data[i0] = gamm * Paug->data[i0 + Paug->size[0] * absb];
      }

      i0 = c_y->size[0];
      emlrtSizeEqCheck1DFastR2012b(xaug_size[0], i0, &db_emlrtECI,
        emlrtRootTLSGlobal);
      loop_ub = XAUG->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        f_tmp_data[i0] = i0;
      }

      i0 = XAUG->size[1];
      i1 = (int32_T)((1.0 + (real_T)absb) + 1.0);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &x_emlrtBCI,
        emlrtRootTLSGlobal);
      iv2[0] = loop_ub;
      emlrtSubAssignSizeCheckR2012b(iv2, 1, xaug_size, 1, &ab_emlrtECI,
        emlrtRootTLSGlobal);
      loop_ub = xaug_size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        XAUG->data[f_tmp_data[i0] + XAUG->size[0] * (absb + 1)] = xaug_data[i0]
          + c_y->data[i0];
      }

      i0 = Paug->size[1];
      i1 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &y_emlrtBCI,
        emlrtRootTLSGlobal);
      loop_ub = Paug->size[0];
      i0 = c_y->size[0];
      c_y->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)c_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_y->data[i0] = gamm * Paug->data[i0 + Paug->size[0] * absb];
      }

      i0 = c_y->size[0];
      emlrtSizeEqCheck1DFastR2012b(xaug_size[0], i0, &cb_emlrtECI,
        emlrtRootTLSGlobal);
      loop_ub = XAUG->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        f_tmp_data[i0] = i0;
      }

      i0 = XAUG->size[1];
      i1 = (N + absb) + 2;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &w_emlrtBCI,
        emlrtRootTLSGlobal) - 1;
      iv3[0] = loop_ub;
      emlrtSubAssignSizeCheckR2012b(iv3, 1, xaug_size, 1, &y_emlrtECI,
        emlrtRootTLSGlobal);
      loop_ub = xaug_size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        XAUG->data[f_tmp_data[i1] + XAUG->size[0] * i0] = xaug_data[i1] -
          c_y->data[i1];
      }

      absb++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    /*  propagate the sigma points */
    if (1 > xk_size[0]) {
      loop_ub = 0;
    } else {
      i0 = XAUG->size[0];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &v_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = XAUG->size[0];
      loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i0, &v_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    emlrtPushRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
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

    emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = cdiff + 1;
    emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (cdiff + 1 > 0) {
      y->data[0] = 1.0;
      if (cdiff + 1 > 1) {
        y->data[cdiff] = apnd;
        i0 = cdiff + (cdiff < 0);
        if (i0 >= 0) {
          ndbl = (int32_T)((uint32_T)i0 >> 1);
        } else {
          ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
        }

        emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
        for (absb = 1; absb < ndbl; absb++) {
          y->data[absb] = 1.0 + (real_T)absb;
          y->data[cdiff - absb] = apnd - absb;
        }

        if (ndbl << 1 == cdiff) {
          y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
        } else {
          y->data[ndbl] = 1.0 + (real_T)ndbl;
          y->data[ndbl + 1] = apnd - ndbl;
        }
      }
    }

    emxInit_real_T(&b_XAUG, 2, &emlrtRTEI, TRUE);
    emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    cdiff = XAUG->size[1];
    i0 = b_XAUG->size[0] * b_XAUG->size[1];
    b_XAUG->size[0] = loop_ub;
    b_XAUG->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)b_XAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < cdiff; i0++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_XAUG->data[i1 + b_XAUG->size[0] * i0] = XAUG->data[i1 + XAUG->size[0] *
          i0];
      }
    }

    emxInit_real_T(&c_XAUG, 2, &emlrtRTEI, TRUE);
    tmp_size_idx_1 = y->size[1];
    loop_ub = y->size[0] * y->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = XAUG->size[0];
      d0 = (real_T)xk_size[0] + y->data[i0];
      i2 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &k_emlrtDCI,
        emlrtRootTLSGlobal);
      c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &ib_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    loop_ub = XAUG->size[1];
    i0 = c_XAUG->size[0] * c_XAUG->size[1];
    c_XAUG->size[0] = tmp_size_idx_1;
    c_XAUG->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)c_XAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < tmp_size_idx_1; i1++) {
        c_XAUG->data[i1 + c_XAUG->size[0] * i0] = XAUG->data[(c_tmp_data[i1] +
          XAUG->size[0] * i0) - 1];
      }
    }

    emxInit_real_T(&b_XAUGPLUS, 2, &e_emlrtRTEI, TRUE);
    update_eq_10_state(b_XAUG, c_XAUG, uk_data, uk_size, b_XAUGPLUS);
    emlrtPopRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);

    /*  weights */
    /*  optimal for Gaussian */
    gamm = 0.5 / ((real_T)N + lambda);
    b_y = N << 1;
    i0 = c_y->size[0];
    c_y->size[0] = b_y + 1;
    emxEnsureCapacity((emxArray__common *)c_y, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    emxFree_real_T(&c_XAUG);
    emxFree_real_T(&b_XAUG);
    for (i0 = 0; i0 <= b_y; i0++) {
      c_y->data[i0] = gamm;
    }

    for (i0 = 0; i0 <= b_y; i0++) {
      wc_data[i0] = gamm;
    }

    gamm = 0.5 / ((real_T)N + lambda);
    b_y = N << 1;
    for (i0 = 0; i0 <= b_y; i0++) {
      wm_data[i0] = gamm;
    }

    wm_data[0] = lambda / ((real_T)N + lambda);
    wc_data[0] = ((lambda / ((real_T)N + lambda) + 1.0) - alpha * alpha) + 2.0;

    /*  calculate the update */
    if (1 > xk_size[0]) {
      loop_ub = 0;
    } else {
      i0 = b_XAUGPLUS->size[0];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &u_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = b_XAUGPLUS->size[0];
      loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i0, &u_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    emlrtPushRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
    wm_size[0] = 1;
    wm_size[1] = b_y + 1;
    cdiff = b_y + 1;
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
    emlrtPopRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
    cdiff = b_XAUGPLUS->size[1];
    i0 = c_XAUGPLUS->size[0] * c_XAUGPLUS->size[1];
    c_XAUGPLUS->size[0] = loop_ub;
    c_XAUGPLUS->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)c_XAUGPLUS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < cdiff; i0++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_XAUGPLUS->data[i1 + c_XAUGPLUS->size[0] * i0] = b_XAUGPLUS->data[i1 +
          b_XAUGPLUS->size[0] * i0];
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
    emlrtSizeEqCheck2DFastR2012b(XAUGPLUS, iv0, &x_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
    cdiff = b_XAUGPLUS->size[1];
    i0 = d_XAUGPLUS->size[0] * d_XAUGPLUS->size[1];
    d_XAUGPLUS->size[0] = loop_ub;
    d_XAUGPLUS->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)d_XAUGPLUS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < cdiff; i0++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        d_XAUGPLUS->data[i1 + d_XAUGPLUS->size[0] * i0] = b_XAUGPLUS->data[i1 +
          b_XAUGPLUS->size[0] * i0] * r0->data[i1 + r0->size[0] * i0];
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

    emlrtPopRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);

    /*  re-normalize */
    emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &w_emlrtECI,
      emlrtRootTLSGlobal);
    emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &v_emlrtECI,
      emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      i1 = xnew_size[0];
      i2 = 7 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &jb_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    for (i0 = 0; i0 < 4; i0++) {
      i1 = xnew_size[0];
      i2 = 7 + i0;
      xnew[i0] = xnew_data[emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
        &kb_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    gamm = e_norm(xnew);
    ndbl = xnew_size[0];
    for (i0 = 0; i0 < 4; i0++) {
      xnew[i0] = xnew_data[i0 + 6] / gamm;
    }

    for (i0 = 0; i0 < 4; i0++) {
      i1 = 7 + i0;
      xnew_data[emlrtDynamicBoundsCheckFastR2012b(i1, 1, ndbl, &lb_emlrtBCI,
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
    absb = 0;
    emxInit_real_T(&b, 2, &emlrtRTEI, TRUE);
    b_emxInit_real_T(&wc, 1, &emlrtRTEI, TRUE);
    emxInit_real_T(&e_XAUGPLUS, 2, &emlrtRTEI, TRUE);
    while (absb <= i0) {
      if (1 > xk_size[0]) {
        loop_ub = 0;
      } else {
        i1 = b_XAUGPLUS->size[0];
        emlrtDynamicBoundsCheckFastR2012b(1, 1, i1, &s_emlrtBCI,
          emlrtRootTLSGlobal);
        i1 = b_XAUGPLUS->size[0];
        loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i1,
          &s_emlrtBCI, emlrtRootTLSGlobal);
      }

      i1 = b_XAUGPLUS->size[1];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &r_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = xnew_size[0];
      emlrtSizeEqCheck1DFastR2012b(loop_ub, i1, &u_emlrtECI, emlrtRootTLSGlobal);
      if (1 > xk_size[0]) {
        cdiff = 0;
      } else {
        i1 = b_XAUGPLUS->size[0];
        emlrtDynamicBoundsCheckFastR2012b(1, 1, i1, &q_emlrtBCI,
          emlrtRootTLSGlobal);
        i1 = b_XAUGPLUS->size[0];
        cdiff = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i1, &q_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      i1 = b_XAUGPLUS->size[1];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &p_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = xnew_size[0];
      emlrtSizeEqCheck1DFastR2012b(cdiff, i1, &t_emlrtECI, emlrtRootTLSGlobal);
      i1 = c_y->size[0];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &t_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = wc->size[0];
      wc->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)wc, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        wc->data[i1] = wc_data[absb] * (b_XAUGPLUS->data[i1 + b_XAUGPLUS->size[0]
          * absb] - xnew_data[i1]);
      }

      i1 = e_XAUGPLUS->size[0] * e_XAUGPLUS->size[1];
      e_XAUGPLUS->size[0] = 1;
      e_XAUGPLUS->size[1] = cdiff;
      emxEnsureCapacity((emxArray__common *)e_XAUGPLUS, i1, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i1 = 0; i1 < cdiff; i1++) {
        e_XAUGPLUS->data[e_XAUGPLUS->size[0] * i1] = b_XAUGPLUS->data[i1 +
          b_XAUGPLUS->size[0] * absb] - xnew_data[i1];
      }

      i1 = b->size[0] * b->size[1];
      b->size[0] = wc->size[0];
      b->size[1] = e_XAUGPLUS->size[1];
      emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = wc->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        cdiff = e_XAUGPLUS->size[1];
        for (i2 = 0; i2 < cdiff; i2++) {
          b->data[i1 + b->size[0] * i2] = wc->data[i1] * e_XAUGPLUS->
            data[e_XAUGPLUS->size[0] * i2];
        }
      }

      for (i1 = 0; i1 < 2; i1++) {
        b_Pnew[i1] = Pnew->size[i1];
      }

      for (i1 = 0; i1 < 2; i1++) {
        wm_size[i1] = b->size[i1];
      }

      emlrtSizeEqCheck2DFastR2012b(b_Pnew, wm_size, &s_emlrtECI,
        emlrtRootTLSGlobal);
      i1 = Pnew->size[0] * Pnew->size[1];
      emxEnsureCapacity((emxArray__common *)Pnew, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ndbl = Pnew->size[0];
      cdiff = Pnew->size[1];
      loop_ub = ndbl * cdiff;
      for (i1 = 0; i1 < loop_ub; i1++) {
        Pnew->data[i1] += b->data[i1];
      }

      absb++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    emxFree_real_T(&e_XAUGPLUS);
    emxFree_real_T(&wc);

    /*  pass the sigma points through the measurement function */
    if (1 > xk_size[0]) {
      loop_ub = 0;
    } else {
      i0 = b_XAUGPLUS->size[0];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &o_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = b_XAUGPLUS->size[0];
      loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i0, &o_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
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

    emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = cdiff + 1;
    emxEnsureCapacity((emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    if (cdiff + 1 > 0) {
      y->data[0] = 1.0;
      if (cdiff + 1 > 1) {
        y->data[cdiff] = apnd;
        i0 = cdiff + (cdiff < 0);
        if (i0 >= 0) {
          ndbl = (int32_T)((uint32_T)i0 >> 1);
        } else {
          ndbl = ~(int32_T)((uint32_T)~i0 >> 1);
        }

        emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
        for (absb = 1; absb < ndbl; absb++) {
          y->data[absb] = 1.0 + (real_T)absb;
          y->data[cdiff - absb] = apnd - absb;
        }

        if (ndbl << 1 == cdiff) {
          y->data[ndbl] = (1.0 + (real_T)apnd) / 2.0;
        } else {
          y->data[ndbl] = 1.0 + (real_T)ndbl;
          y->data[ndbl + 1] = apnd - ndbl;
        }
      }
    }

    emxInit_real_T(&f_XAUGPLUS, 2, &emlrtRTEI, TRUE);
    emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    cdiff = b_XAUGPLUS->size[1];
    i0 = f_XAUGPLUS->size[0] * f_XAUGPLUS->size[1];
    f_XAUGPLUS->size[0] = loop_ub;
    f_XAUGPLUS->size[1] = cdiff;
    emxEnsureCapacity((emxArray__common *)f_XAUGPLUS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < cdiff; i0++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        f_XAUGPLUS->data[i1 + f_XAUGPLUS->size[0] * i0] = b_XAUGPLUS->data[i1 +
          b_XAUGPLUS->size[0] * i0];
      }
    }

    emxInit_real_T(&d_XAUG, 2, &emlrtRTEI, TRUE);
    tmp_size_idx_1 = y->size[1];
    cdiff = (int16_T)((int16_T)xk_size[0] + (int16_T)Pvk->size[0]);
    loop_ub = y->size[0] * y->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = XAUG->size[0];
      d0 = (real_T)cdiff + y->data[i0];
      i2 = (int32_T)emlrtIntegerCheckFastR2012b(d0, &l_emlrtDCI,
        emlrtRootTLSGlobal);
      c_tmp_data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &mb_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    loop_ub = XAUG->size[1];
    i0 = d_XAUG->size[0] * d_XAUG->size[1];
    d_XAUG->size[0] = tmp_size_idx_1;
    d_XAUG->size[1] = loop_ub;
    emxEnsureCapacity((emxArray__common *)d_XAUG, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < tmp_size_idx_1; i1++) {
        d_XAUG->data[i1 + d_XAUG->size[0] * i0] = XAUG->data[(c_tmp_data[i1] +
          XAUG->size[0] * i0) - 1];
      }
    }

    emxFree_real_T(&XAUG);
    emxInit_real_T(&YKAUG, 2, &f_emlrtRTEI, TRUE);
    measurement_eq_10_state(f_XAUGPLUS, uk_data, uk_size, YKAUG);
    emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
    b_wm_size[0] = 1;
    b_wm_size[1] = b_y + 1;
    loop_ub = b_y + 1;
    emxFree_real_T(&d_XAUG);
    emxFree_real_T(&f_XAUGPLUS);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_wm_data[i0] = wm_data[i0];
    }

    repmat(b_wm_data, b_wm_size, YKAUG->size[0], r1);
    emlrtPopRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 2; i0++) {
      XAUGPLUS[i0] = YKAUG->size[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = r1->size[i0];
    }

    emxInit_real_T(&b_YKAUG, 2, &emlrtRTEI, TRUE);
    emlrtSizeEqCheck2DFastR2012b(XAUGPLUS, iv0, &r_emlrtECI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
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
    emlrtPopRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);

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
    absb = 0;
    b_emxInit_real_T(&b_wc, 1, &emlrtRTEI, TRUE);
    emxInit_real_T(&c_YKAUG, 2, &emlrtRTEI, TRUE);
    b_emxInit_real_T(&c_wc, 1, &emlrtRTEI, TRUE);
    emxInit_real_T(&d_YKAUG, 2, &emlrtRTEI, TRUE);
    while (absb <= i0) {
      i1 = YKAUG->size[1];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &m_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = YKAUG->size[0];
      i2 = yhat->size[0];
      emlrtSizeEqCheck1DFastR2012b(i1, i2, &q_emlrtECI, emlrtRootTLSGlobal);
      i1 = YKAUG->size[1];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &l_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = YKAUG->size[0];
      i2 = yhat->size[0];
      emlrtSizeEqCheck1DFastR2012b(i1, i2, &p_emlrtECI, emlrtRootTLSGlobal);
      i1 = c_y->size[0];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &n_emlrtBCI,
        emlrtRootTLSGlobal);
      loop_ub = YKAUG->size[0];
      cdiff = YKAUG->size[0];
      i1 = b_wc->size[0];
      b_wc->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)b_wc, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_wc->data[i1] = wc_data[absb] * (YKAUG->data[i1 + YKAUG->size[0] * absb]
          - yhat->data[i1]);
      }

      i1 = c_YKAUG->size[0] * c_YKAUG->size[1];
      c_YKAUG->size[0] = 1;
      c_YKAUG->size[1] = cdiff;
      emxEnsureCapacity((emxArray__common *)c_YKAUG, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i1 = 0; i1 < cdiff; i1++) {
        c_YKAUG->data[c_YKAUG->size[0] * i1] = YKAUG->data[i1 + YKAUG->size[0] *
          absb] - yhat->data[i1];
      }

      i1 = b->size[0] * b->size[1];
      b->size[0] = b_wc->size[0];
      b->size[1] = c_YKAUG->size[1];
      emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = b_wc->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        cdiff = c_YKAUG->size[1];
        for (i2 = 0; i2 < cdiff; i2++) {
          b->data[i1 + b->size[0] * i2] = b_wc->data[i1] * c_YKAUG->data
            [c_YKAUG->size[0] * i2];
        }
      }

      for (i1 = 0; i1 < 2; i1++) {
        XAUGPLUS[i1] = Pyk->size[i1];
      }

      for (i1 = 0; i1 < 2; i1++) {
        wm_size[i1] = b->size[i1];
      }

      emlrtSizeEqCheck2DFastR2012b(XAUGPLUS, wm_size, &o_emlrtECI,
        emlrtRootTLSGlobal);
      i1 = Pyk->size[0] * Pyk->size[1];
      emxEnsureCapacity((emxArray__common *)Pyk, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ndbl = Pyk->size[0];
      cdiff = Pyk->size[1];
      loop_ub = ndbl * cdiff;
      for (i1 = 0; i1 < loop_ub; i1++) {
        Pyk->data[i1] += b->data[i1];
      }

      if (1 > xk_size[0]) {
        loop_ub = 0;
      } else {
        i1 = b_XAUGPLUS->size[0];
        emlrtDynamicBoundsCheckFastR2012b(1, 1, i1, &j_emlrtBCI,
          emlrtRootTLSGlobal);
        i1 = b_XAUGPLUS->size[0];
        loop_ub = emlrtDynamicBoundsCheckFastR2012b(xk_size[0], 1, i1,
          &j_emlrtBCI, emlrtRootTLSGlobal);
      }

      i1 = b_XAUGPLUS->size[1];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &i_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = xnew_size[0];
      emlrtSizeEqCheck1DFastR2012b(loop_ub, i1, &n_emlrtECI, emlrtRootTLSGlobal);
      i1 = YKAUG->size[1];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &h_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = YKAUG->size[0];
      i2 = yhat->size[0];
      emlrtSizeEqCheck1DFastR2012b(i1, i2, &m_emlrtECI, emlrtRootTLSGlobal);
      i1 = c_y->size[0];
      i2 = (int32_T)(1.0 + (real_T)absb);
      emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &k_emlrtBCI,
        emlrtRootTLSGlobal);
      cdiff = YKAUG->size[0];
      i1 = c_wc->size[0];
      c_wc->size[0] = loop_ub;
      emxEnsureCapacity((emxArray__common *)c_wc, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_wc->data[i1] = wc_data[absb] * (b_XAUGPLUS->data[i1 + b_XAUGPLUS->
          size[0] * absb] - xnew_data[i1]);
      }

      i1 = d_YKAUG->size[0] * d_YKAUG->size[1];
      d_YKAUG->size[0] = 1;
      d_YKAUG->size[1] = cdiff;
      emxEnsureCapacity((emxArray__common *)d_YKAUG, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i1 = 0; i1 < cdiff; i1++) {
        d_YKAUG->data[d_YKAUG->size[0] * i1] = YKAUG->data[i1 + YKAUG->size[0] *
          absb] - yhat->data[i1];
      }

      i1 = b->size[0] * b->size[1];
      b->size[0] = c_wc->size[0];
      b->size[1] = d_YKAUG->size[1];
      emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = c_wc->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        cdiff = d_YKAUG->size[1];
        for (i2 = 0; i2 < cdiff; i2++) {
          b->data[i1 + b->size[0] * i2] = c_wc->data[i1] * d_YKAUG->data
            [d_YKAUG->size[0] * i2];
        }
      }

      for (i1 = 0; i1 < 2; i1++) {
        XAUGPLUS[i1] = Pxkyk->size[i1];
      }

      for (i1 = 0; i1 < 2; i1++) {
        wm_size[i1] = b->size[i1];
      }

      emlrtSizeEqCheck2DFastR2012b(XAUGPLUS, wm_size, &l_emlrtECI,
        emlrtRootTLSGlobal);
      i1 = Pxkyk->size[0] * Pxkyk->size[1];
      emxEnsureCapacity((emxArray__common *)Pxkyk, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ndbl = Pxkyk->size[0];
      cdiff = Pxkyk->size[1];
      loop_ub = ndbl * cdiff;
      for (i1 = 0; i1 < loop_ub; i1++) {
        Pxkyk->data[i1] += b->data[i1];
      }

      absb++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    emxFree_real_T(&d_YKAUG);
    emxFree_real_T(&c_wc);
    emxFree_real_T(&c_YKAUG);
    emxFree_real_T(&b_wc);
    emxFree_real_T(&c_y);
    emxFree_real_T(&b_XAUGPLUS);
    emxInit_boolean_T(&r3, 2, &emlrtRTEI, TRUE);

    /*  Kalman gain */
    emlrtPushRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
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
    b0 = b_any(r4);
    emlrtPopRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
    emxFree_boolean_T(&r3);
    emxFree_boolean_T(&r4);
    if (b0) {
      emlrtPushRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
      d_y = NULL;
      m0 = mxCreateCharArray(2, iv4);
      for (ndbl = 0; ndbl < 31; ndbl++) {
        cv0[ndbl] = cv1[ndbl];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 31, m0, cv0);
      emlrtAssign(&d_y, m0);
      disp(d_y, &emlrtMCI);
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
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      if ((0 == Pyk->size[0]) || (0 == Pyk->size[1])) {
        cdiff = 0;
      } else if (Pyk->size[0] > Pyk->size[1]) {
        cdiff = Pyk->size[0];
      } else {
        cdiff = Pyk->size[1];
      }

      b0 = (rank(Pyk) < cdiff);
      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      if (b0) {
        emlrtPushRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
        e_y = NULL;
        m0 = mxCreateCharArray(2, iv5);
        for (ndbl = 0; ndbl < 5; ndbl++) {
          cv2[ndbl] = cv3[ndbl];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m0, cv2);
        emlrtAssign(&e_y, m0);
        disp(e_y, &b_emlrtMCI);
        emlrtPopRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
      }

      emxInit_real_T(&b_b, 2, &emlrtRTEI, TRUE);
      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
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
      emlrtPushRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
      emxFree_real_T(&b_b);
      if (!(Pxkyk->size[1] == b->size[0])) {
        if (((Pxkyk->size[0] == 1) && (Pxkyk->size[1] == 1)) || ((b->size[0] ==
              1) && (b->size[1] == 1))) {
          emlrtPushRtStackR2012b(&hh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          f_y = NULL;
          m0 = mxCreateCharArray(2, iv6);
          for (ndbl = 0; ndbl < 45; ndbl++) {
            cv4[ndbl] = cv5[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m0, cv4);
          emlrtAssign(&f_y, m0);
          error(message(f_y, &m_emlrtMCI), &n_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&hh_emlrtRSI, emlrtRootTLSGlobal);
        } else {
          emlrtPushRtStackR2012b(&gh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          g_y = NULL;
          m0 = mxCreateCharArray(2, iv7);
          for (ndbl = 0; ndbl < 21; ndbl++) {
            cv6[ndbl] = cv7[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv6);
          emlrtAssign(&g_y, m0);
          error(message(g_y, &o_emlrtMCI), &p_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&gh_emlrtRSI, emlrtRootTLSGlobal);
        }
      }

      emlrtPopRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
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
          for (i1 = 0; i1 < cdiff; i1++) {
            Kk->data[i0 + Kk->size[0] * i1] = 0.0;
            ndbl = Pxkyk->size[1];
            for (i2 = 0; i2 < ndbl; i2++) {
              Kk->data[i0 + Kk->size[0] * i1] += Pxkyk->data[i0 + Pxkyk->size[0]
                * i2] * b->data[i2 + b->size[0] * i1];
            }
          }
        }
      } else {
        unnamed_idx_0 = (uint32_T)Pxkyk->size[0];
        unnamed_idx_1 = (uint32_T)b->size[1];
        i0 = r5->size[0] * r5->size[1];
        r5->size[0] = (int32_T)unnamed_idx_0;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = r5->size[0] * r5->size[1];
        r5->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          r5->data[i0] = 0.0;
        }

        emlrtPushRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
        i0 = Kk->size[0] * Kk->size[1];
        Kk->size[0] = (int32_T)unnamed_idx_0;
        emxEnsureCapacity((emxArray__common *)Kk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = Kk->size[0] * Kk->size[1];
        Kk->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)Kk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          Kk->data[i0] = 0.0;
        }

        if ((Pxkyk->size[0] < 1) || (b->size[1] < 1) || (Pxkyk->size[1] < 1)) {
        } else {
          emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
          gamm = 1.0;
          resnorm = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          emlrtPushRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          m_t = (ptrdiff_t)(Pxkyk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          n_t = (ptrdiff_t)(b->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          k_t = (ptrdiff_t)(Pxkyk->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          lda_t = (ptrdiff_t)(Pxkyk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldb_t = (ptrdiff_t)(Pxkyk->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldc_t = (ptrdiff_t)(Pxkyk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          alpha1_t = (double *)(&gamm);
          emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Aia0_t = (double *)(&Pxkyk->data[0]);
          emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Bib0_t = (double *)(&b->data[0]);
          emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          beta1_t = (double *)(&resnorm);
          emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Cic0_t = (double *)(&Kk->data[0]);
          emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t,
                Bib0_t, &ldb_t, beta1_t, Cic0_t, &ldc_t);
          emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);

      /*  minimize diff between bearing/declination to features */
      emlrtDynamicBoundsCheckFastR2012b(7, 1, uk_size[0], &g_emlrtBCI,
        emlrtRootTLSGlobal);
      d0 = 3.0 * uk_data[6];
      if (2.0 > d0) {
        i0 = 1;
        i1 = 1;
        i2 = 0;
      } else {
        i0 = yhat->size[0];
        emlrtDynamicBoundsCheckFastR2012b(2, 1, i0, &f_emlrtBCI,
          emlrtRootTLSGlobal);
        i0 = 2;
        i1 = 3;
        i2 = yhat->size[0];
        cdiff = (int32_T)emlrtIntegerCheckFastR2012b(d0, &f_emlrtDCI,
          emlrtRootTLSGlobal);
        i2 = emlrtDynamicBoundsCheckFastR2012b(cdiff, 1, i2, &f_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, div_s32_floor(i2 -
        i0, i1) + 1, &k_emlrtECI, emlrtRootTLSGlobal);
      d0 = 3.0 * uk_data[6];
      if (2.0 > d0) {
        cdiff = 1;
        absb = 1;
        apnd = 0;
      } else {
        emlrtDynamicBoundsCheckFastR2012b(2, 1, ytilde_size[0], &e_emlrtBCI,
          emlrtRootTLSGlobal);
        cdiff = 2;
        absb = 3;
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(d0, &e_emlrtDCI,
          emlrtRootTLSGlobal);
        apnd = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &e_emlrtBCI, emlrtRootTLSGlobal);
      }

      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, div_s32_floor(apnd
        - cdiff, absb) + 1, &j_emlrtECI, emlrtRootTLSGlobal);
      d0 = 3.0 * uk_data[6];
      if (2.0 > d0) {
        tmp_size_idx_1 = 1;
        b_y = 1;
        N = 0;
      } else {
        tmp_size_idx_1 = yhat->size[0];
        emlrtDynamicBoundsCheckFastR2012b(2, 1, tmp_size_idx_1, &d_emlrtBCI,
          emlrtRootTLSGlobal);
        tmp_size_idx_1 = 2;
        b_y = 3;
        N = yhat->size[0];
        ndbl = (int32_T)emlrtIntegerCheckFastR2012b(d0, &d_emlrtDCI,
          emlrtRootTLSGlobal);
        N = emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, N, &d_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      ndbl = r2->size[0];
      r2->size[0] = div_s32_floor(i2 - i0, i1) + 1;
      emxEnsureCapacity((emxArray__common *)r2, ndbl, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = div_s32_floor(i2 - i0, i1);
      for (i2 = 0; i2 <= loop_ub; i2++) {
        r2->data[i2] = yhat->data[(i0 + i1 * i2) - 1];
      }

      b_ytilde_size[0] = div_s32_floor(apnd - cdiff, absb) + 1;
      loop_ub = div_s32_floor(apnd - cdiff, absb);
      for (i0 = 0; i0 <= loop_ub; i0++) {
        b_ytilde_data[i0] = ytilde_data[(cdiff + absb * i0) - 1];
      }

      b_emxInit_int32_T(&r6, 1, &emlrtRTEI, TRUE);
      c_ytilde_data.data = (real_T *)&b_ytilde_data;
      c_ytilde_data.size = (int32_T *)&b_ytilde_size;
      c_ytilde_data.allocatedSize = 500;
      c_ytilde_data.numDimensions = 1;
      c_ytilde_data.canFreeData = FALSE;
      minangle(r2, &c_ytilde_data);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      i0 = div_s32_floor(N - tmp_size_idx_1, b_y) + 1;
      i1 = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, i1, &i_emlrtECI, emlrtRootTLSGlobal);
      i0 = r6->size[0];
      r6->size[0] = div_s32_floor(N - tmp_size_idx_1, b_y) + 1;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = div_s32_floor(N - tmp_size_idx_1, b_y);
      for (i0 = 0; i0 <= loop_ub; i0++) {
        r6->data[i0] = tmp_size_idx_1 + b_y * i0;
      }

      emxInit_int32_T(&r7, 2, &emlrtRTEI, TRUE);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      ndbl = r6->size[0];
      i0 = r7->size[0] * r7->size[1];
      r7->size[1] = ndbl;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r6->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r7->data[i0] = r6->data[i0] - 1;
      }

      emxFree_int32_T(&r6);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r7->data[i0]] = r2->data[i0];
      }

      d0 = 3.0 * uk_data[6];
      if (3.0 > d0) {
        i0 = 1;
        i1 = 1;
        i2 = 0;
      } else {
        i0 = yhat->size[0];
        emlrtDynamicBoundsCheckFastR2012b(3, 1, i0, &c_emlrtBCI,
          emlrtRootTLSGlobal);
        i0 = 3;
        i1 = 3;
        i2 = yhat->size[0];
        cdiff = (int32_T)emlrtIntegerCheckFastR2012b(d0, &c_emlrtDCI,
          emlrtRootTLSGlobal);
        i2 = emlrtDynamicBoundsCheckFastR2012b(cdiff, 1, i2, &c_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      emlrtVectorVectorIndexCheckR2012b(yhat->size[0], 1, 1, div_s32_floor(i2 -
        i0, i1) + 1, &h_emlrtECI, emlrtRootTLSGlobal);
      d0 = 3.0 * uk_data[6];
      if (3.0 > d0) {
        cdiff = 1;
        absb = 1;
        apnd = 0;
      } else {
        emlrtDynamicBoundsCheckFastR2012b(3, 1, ytilde_size[0], &b_emlrtBCI,
          emlrtRootTLSGlobal);
        cdiff = 3;
        absb = 3;
        apnd = (int32_T)emlrtIntegerCheckFastR2012b(d0, &b_emlrtDCI,
          emlrtRootTLSGlobal);
        apnd = emlrtDynamicBoundsCheckFastR2012b(apnd, 1, ytilde_size[0],
          &b_emlrtBCI, emlrtRootTLSGlobal);
      }

      emlrtVectorVectorIndexCheckR2012b(ytilde_size[0], 1, 1, div_s32_floor(apnd
        - cdiff, absb) + 1, &g_emlrtECI, emlrtRootTLSGlobal);
      d0 = 3.0 * uk_data[6];
      if (3.0 > d0) {
        tmp_size_idx_1 = 1;
        b_y = 1;
        N = 0;
      } else {
        tmp_size_idx_1 = yhat->size[0];
        emlrtDynamicBoundsCheckFastR2012b(3, 1, tmp_size_idx_1, &emlrtBCI,
          emlrtRootTLSGlobal);
        tmp_size_idx_1 = 3;
        b_y = 3;
        N = yhat->size[0];
        ndbl = (int32_T)emlrtIntegerCheckFastR2012b(d0, &emlrtDCI,
          emlrtRootTLSGlobal);
        N = emlrtDynamicBoundsCheckFastR2012b(ndbl, 1, N, &emlrtBCI,
          emlrtRootTLSGlobal);
      }

      emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      ndbl = r2->size[0];
      r2->size[0] = div_s32_floor(i2 - i0, i1) + 1;
      emxEnsureCapacity((emxArray__common *)r2, ndbl, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = div_s32_floor(i2 - i0, i1);
      for (i2 = 0; i2 <= loop_ub; i2++) {
        r2->data[i2] = yhat->data[(i0 + i1 * i2) - 1];
      }

      c_ytilde_size[0] = div_s32_floor(apnd - cdiff, absb) + 1;
      loop_ub = div_s32_floor(apnd - cdiff, absb);
      for (i0 = 0; i0 <= loop_ub; i0++) {
        d_ytilde_data[i0] = ytilde_data[(cdiff + absb * i0) - 1];
      }

      b_emxInit_int32_T(&r8, 1, &emlrtRTEI, TRUE);
      e_ytilde_data.data = (real_T *)&d_ytilde_data;
      e_ytilde_data.size = (int32_T *)&c_ytilde_size;
      e_ytilde_data.allocatedSize = 500;
      e_ytilde_data.numDimensions = 1;
      e_ytilde_data.canFreeData = FALSE;
      minangle(r2, &e_ytilde_data);
      emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      i0 = div_s32_floor(N - tmp_size_idx_1, b_y) + 1;
      i1 = r2->size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, i1, &f_emlrtECI, emlrtRootTLSGlobal);
      i0 = r8->size[0];
      r8->size[0] = div_s32_floor(N - tmp_size_idx_1, b_y) + 1;
      emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = div_s32_floor(N - tmp_size_idx_1, b_y);
      for (i0 = 0; i0 <= loop_ub; i0++) {
        r8->data[i0] = tmp_size_idx_1 + b_y * i0;
      }

      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      ndbl = r8->size[0];
      i0 = r7->size[0] * r7->size[1];
      r7->size[1] = ndbl;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      loop_ub = r8->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r7->data[i0] = r8->data[i0] - 1;
      }

      emxFree_int32_T(&r8);
      loop_ub = r7->size[0] * r7->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        yhat->data[r7->data[i0]] = r2->data[i0];
      }

      emxFree_int32_T(&r7);
      i0 = yhat->size[0];
      emlrtSizeEqCheck1DFastR2012b(ytilde_size[0], i0, &e_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      loop_ub = ytilde_size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_data[i0] = ytilde_data[i0] - yhat->data[i0];
      }

      emlrtPushRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
      if (!(Kk->size[1] == ytilde_size[0])) {
        if (((Kk->size[0] == 1) && (Kk->size[1] == 1)) || (ytilde_size[0] == 1))
        {
          emlrtPushRtStackR2012b(&hh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          h_y = NULL;
          m0 = mxCreateCharArray(2, iv8);
          for (ndbl = 0; ndbl < 45; ndbl++) {
            cv4[ndbl] = cv5[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m0, cv4);
          emlrtAssign(&h_y, m0);
          error(message(h_y, &m_emlrtMCI), &n_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&hh_emlrtRSI, emlrtRootTLSGlobal);
        } else {
          emlrtPushRtStackR2012b(&gh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          i_y = NULL;
          m0 = mxCreateCharArray(2, iv9);
          for (ndbl = 0; ndbl < 21; ndbl++) {
            cv6[ndbl] = cv7[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv6);
          emlrtAssign(&i_y, m0);
          error(message(i_y, &o_emlrtMCI), &p_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&gh_emlrtRSI, emlrtRootTLSGlobal);
        }
      }

      emlrtPopRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
      if ((Kk->size[1] == 1) || (ytilde_size[0] == 1)) {
        ndbl = Kk->size[0];
        loop_ub = Kk->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          C_data[i0] = 0.0;
          cdiff = Kk->size[1];
          for (i1 = 0; i1 < cdiff; i1++) {
            gamm = C_data[i0] + Kk->data[i0 + Kk->size[0] * i1] * b_data[i1];
            C_data[i0] = gamm;
          }
        }
      } else {
        unnamed_idx_0 = (uint32_T)Kk->size[0];
        emlrtPushRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
        ndbl = (int32_T)unnamed_idx_0;
        loop_ub = (int32_T)unnamed_idx_0;
        for (i0 = 0; i0 < loop_ub; i0++) {
          C_data[i0] = 0.0;
        }

        if ((Kk->size[0] < 1) || (Kk->size[1] < 1)) {
        } else {
          emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
          gamm = 1.0;
          resnorm = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          emlrtPushRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          m_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          n_t = (ptrdiff_t)(1);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          k_t = (ptrdiff_t)(Kk->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          lda_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldb_t = (ptrdiff_t)(Kk->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldc_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          alpha1_t = (double *)(&gamm);
          emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Aia0_t = (double *)(&Kk->data[0]);
          emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Bib0_t = (double *)(&b_data[0]);
          emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          beta1_t = (double *)(&resnorm);
          emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Cic0_t = (double *)(&C_data[0]);
          emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t,
                Bib0_t, &ldb_t, beta1_t, Cic0_t, &ldc_t);
          emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
      i0 = xnew_size[0];
      emlrtSizeEqCheck1DFastR2012b(i0, ndbl, &d_emlrtECI, emlrtRootTLSGlobal);
      loop_ub = xnew_size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        xnew_data[i0] += C_data[i0];
      }

      /*  renormalize quaternions as necessary */
      emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &c_emlrtECI,
        emlrtRootTLSGlobal);
      emlrtVectorVectorIndexCheckR2012b(xnew_size[0], 1, 1, 4, &b_emlrtECI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 4; i0++) {
        i1 = xnew_size[0];
        i2 = 7 + i0;
        emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &nb_emlrtBCI,
          emlrtRootTLSGlobal);
      }

      for (i0 = 0; i0 < 4; i0++) {
        i1 = xnew_size[0];
        i2 = 7 + i0;
        xnew[i0] = xnew_data[emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &ob_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      gamm = e_norm(xnew);
      ndbl = xnew_size[0];
      for (i0 = 0; i0 < 4; i0++) {
        xnew[i0] = xnew_data[i0 + 6] / gamm;
      }

      for (i0 = 0; i0 < 4; i0++) {
        i1 = 7 + i0;
        xnew_data[emlrtDynamicBoundsCheckFastR2012b(i1, 1, ndbl, &pb_emlrtBCI,
          emlrtRootTLSGlobal) - 1] = xnew[i0];
      }

      emlrtPushRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
      if (!(Kk->size[1] == Pyk->size[0])) {
        if (((Kk->size[0] == 1) && (Kk->size[1] == 1)) || ((Pyk->size[0] == 1) &&
             (Pyk->size[1] == 1))) {
          emlrtPushRtStackR2012b(&hh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          j_y = NULL;
          m0 = mxCreateCharArray(2, iv10);
          for (ndbl = 0; ndbl < 45; ndbl++) {
            cv4[ndbl] = cv5[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m0, cv4);
          emlrtAssign(&j_y, m0);
          error(message(j_y, &m_emlrtMCI), &n_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&hh_emlrtRSI, emlrtRootTLSGlobal);
        } else {
          emlrtPushRtStackR2012b(&gh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          k_y = NULL;
          m0 = mxCreateCharArray(2, iv11);
          for (ndbl = 0; ndbl < 21; ndbl++) {
            cv6[ndbl] = cv7[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv6);
          emlrtAssign(&k_y, m0);
          error(message(k_y, &o_emlrtMCI), &p_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&gh_emlrtRSI, emlrtRootTLSGlobal);
        }
      }

      emlrtPopRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
      emxInit_real_T(&l_y, 2, &emlrtRTEI, TRUE);
      if ((Kk->size[1] == 1) || (Pyk->size[0] == 1)) {
        i0 = l_y->size[0] * l_y->size[1];
        l_y->size[0] = Kk->size[0];
        l_y->size[1] = Pyk->size[1];
        emxEnsureCapacity((emxArray__common *)l_y, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = Kk->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          cdiff = Pyk->size[1];
          for (i1 = 0; i1 < cdiff; i1++) {
            l_y->data[i0 + l_y->size[0] * i1] = 0.0;
            ndbl = Kk->size[1];
            for (i2 = 0; i2 < ndbl; i2++) {
              l_y->data[i0 + l_y->size[0] * i1] += Kk->data[i0 + Kk->size[0] *
                i2] * Pyk->data[i2 + Pyk->size[0] * i1];
            }
          }
        }
      } else {
        unnamed_idx_0 = (uint32_T)Kk->size[0];
        unnamed_idx_1 = (uint32_T)Pyk->size[1];
        i0 = r5->size[0] * r5->size[1];
        r5->size[0] = (int32_T)unnamed_idx_0;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = r5->size[0] * r5->size[1];
        r5->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          r5->data[i0] = 0.0;
        }

        emlrtPushRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
        i0 = l_y->size[0] * l_y->size[1];
        l_y->size[0] = (int32_T)unnamed_idx_0;
        emxEnsureCapacity((emxArray__common *)l_y, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = l_y->size[0] * l_y->size[1];
        l_y->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)l_y, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          l_y->data[i0] = 0.0;
        }

        if ((Kk->size[0] < 1) || (Pyk->size[1] < 1) || (Kk->size[1] < 1)) {
        } else {
          emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
          gamm = 1.0;
          resnorm = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          emlrtPushRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          m_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          n_t = (ptrdiff_t)(Pyk->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          k_t = (ptrdiff_t)(Kk->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          lda_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldb_t = (ptrdiff_t)(Kk->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldc_t = (ptrdiff_t)(Kk->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          alpha1_t = (double *)(&gamm);
          emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Aia0_t = (double *)(&Kk->data[0]);
          emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Bib0_t = (double *)(&Pyk->data[0]);
          emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          beta1_t = (double *)(&resnorm);
          emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Cic0_t = (double *)(&l_y->data[0]);
          emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t,
                Bib0_t, &ldb_t, beta1_t, Cic0_t, &ldc_t);
          emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
      }

      i0 = b->size[0] * b->size[1];
      b->size[0] = Kk->size[1];
      b->size[1] = Kk->size[0];
      emxEnsureCapacity((emxArray__common *)b, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      loop_ub = Kk->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        cdiff = Kk->size[1];
        for (i1 = 0; i1 < cdiff; i1++) {
          b->data[i1 + b->size[0] * i0] = Kk->data[i0 + Kk->size[0] * i1];
        }
      }

      emxFree_real_T(&Kk);
      emlrtPushRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
      if (!(l_y->size[1] == b->size[0])) {
        if (((l_y->size[0] == 1) && (l_y->size[1] == 1)) || ((b->size[0] == 1) &&
             (b->size[1] == 1))) {
          emlrtPushRtStackR2012b(&hh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          m_y = NULL;
          m0 = mxCreateCharArray(2, iv12);
          for (ndbl = 0; ndbl < 45; ndbl++) {
            cv4[ndbl] = cv5[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m0, cv4);
          emlrtAssign(&m_y, m0);
          error(message(m_y, &m_emlrtMCI), &n_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&hh_emlrtRSI, emlrtRootTLSGlobal);
        } else {
          emlrtPushRtStackR2012b(&gh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_synchGlobalsToML();
          n_y = NULL;
          m0 = mxCreateCharArray(2, iv13);
          for (ndbl = 0; ndbl < 21; ndbl++) {
            cv6[ndbl] = cv7[ndbl];
          }

          emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv6);
          emlrtAssign(&n_y, m0);
          error(message(n_y, &o_emlrtMCI), &p_emlrtMCI);
          emlrt_synchGlobalsFromML();
          emlrtPopRtStackR2012b(&gh_emlrtRSI, emlrtRootTLSGlobal);
        }
      }

      emlrtPopRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
      if ((l_y->size[1] == 1) || (b->size[0] == 1)) {
        i0 = Pxkyk->size[0] * Pxkyk->size[1];
        Pxkyk->size[0] = l_y->size[0];
        Pxkyk->size[1] = b->size[1];
        emxEnsureCapacity((emxArray__common *)Pxkyk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = l_y->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          cdiff = b->size[1];
          for (i1 = 0; i1 < cdiff; i1++) {
            Pxkyk->data[i0 + Pxkyk->size[0] * i1] = 0.0;
            ndbl = l_y->size[1];
            for (i2 = 0; i2 < ndbl; i2++) {
              Pxkyk->data[i0 + Pxkyk->size[0] * i1] += l_y->data[i0 + l_y->size
                [0] * i2] * b->data[i2 + b->size[0] * i1];
            }
          }
        }
      } else {
        unnamed_idx_0 = (uint32_T)l_y->size[0];
        unnamed_idx_1 = (uint32_T)b->size[1];
        i0 = r5->size[0] * r5->size[1];
        r5->size[0] = (int32_T)unnamed_idx_0;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = r5->size[0] * r5->size[1];
        r5->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          r5->data[i0] = 0.0;
        }

        emlrtPushRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
        i0 = Pxkyk->size[0] * Pxkyk->size[1];
        Pxkyk->size[0] = (int32_T)unnamed_idx_0;
        emxEnsureCapacity((emxArray__common *)Pxkyk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        i0 = Pxkyk->size[0] * Pxkyk->size[1];
        Pxkyk->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity((emxArray__common *)Pxkyk, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          Pxkyk->data[i0] = 0.0;
        }

        if ((l_y->size[0] < 1) || (b->size[1] < 1) || (l_y->size[1] < 1)) {
        } else {
          emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
          gamm = 1.0;
          resnorm = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          emlrtPushRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          m_t = (ptrdiff_t)(l_y->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          n_t = (ptrdiff_t)(b->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          k_t = (ptrdiff_t)(l_y->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          lda_t = (ptrdiff_t)(l_y->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldb_t = (ptrdiff_t)(l_y->size[1]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          ldc_t = (ptrdiff_t)(l_y->size[0]);
          emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          alpha1_t = (double *)(&gamm);
          emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Aia0_t = (double *)(&l_y->data[0]);
          emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Bib0_t = (double *)(&b->data[0]);
          emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          beta1_t = (double *)(&resnorm);
          emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          Cic0_t = (double *)(&Pxkyk->data[0]);
          emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrt_checkEscapedGlobals();
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t,
                Bib0_t, &ldb_t, beta1_t, Cic0_t, &ldc_t);
          emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
      }

      emxFree_real_T(&r5);
      emxFree_real_T(&l_y);
      emlrtPopRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
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

  emxFree_real_T(&y);
  emxFree_creal_T(&Psq);
  emxFree_real_T(&Paug);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (ukf_update_10_state.c) */
