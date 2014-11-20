/*
 * measurement_eq_17_state.c
 *
 * Code generation for function 'measurement_eq_17_state'
 *
 * C source code generated on: Thu Nov 20 11:58:35 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurement_eq_17_state.h"
#include "sqrt.h"
#include "sum.h"
#include "power.h"
#include "minangle.h"
#include "measurement_eq_17_state_emxutil.h"
#include "attparsilentmex.h"
#include "measurement_eq_17_state_mexutil.h"
#include "measurement_eq_17_state_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 19, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo b_emlrtRSI = { 21, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo c_emlrtRSI = { 40, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo d_emlrtRSI = { 45, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo e_emlrtRSI = { 57, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo f_emlrtRSI = { 67, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo g_emlrtRSI = { 73, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo h_emlrtRSI = { 74, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo i_emlrtRSI = { 75, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo j_emlrtRSI = { 76, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo k_emlrtRSI = { 77, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRSInfo l_emlrtRSI = { 21, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo m_emlrtRSI = { 79, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo n_emlrtRSI = { 280, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo o_emlrtRSI = { 288, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo p_emlrtRSI = { 401, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo s_emlrtRSI = { 68, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo t_emlrtRSI = { 66, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo u_emlrtRSI = { 61, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRSInfo v_emlrtRSI = { 49, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtMCInfo emlrtMCI = { 402, 5, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtMCInfo b_emlrtMCI = { 401, 15, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtMCInfo e_emlrtMCI = { 49, 17, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtMCInfo f_emlrtMCI = { 67, 5, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtMCInfo g_emlrtMCI = { 66, 15, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRTEInfo emlrtRTEI = { 281, 1, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 1, 15, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 65, 1, "reshape",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 19, 1, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 21, 1, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo emlrtECI = { -1, 77, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 77, 35, "yk", "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 77, 108, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 77, 77, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 76, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 76, 35, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 76, 108, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 76, 77, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo c_emlrtECI = { -1, 75, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo g_emlrtBCI = { -1, -1, 75, 28, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 75, 82, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 75, 61, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo d_emlrtECI = { -1, 74, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo j_emlrtBCI = { -1, -1, 74, 28, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 74, 82, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 74, 61, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 73, 22, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 73, 65, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 73, 49, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 68, 22, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 58, 22, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 48, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 45, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 40, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 67, 110, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 63, 30, "RKN_2",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtRTEInfo l_emlrtRTEI = { 61, 5, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo w_emlrtBCI = { -1, -1, 57, 110, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 53, 26, "RKN_1",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtRTEInfo m_emlrtRTEI = { 51, 5, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo y_emlrtBCI = { -1, -1, 48, 52, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 48, 37, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 45, 134, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 40, 134, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 35, 19, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 33, 18, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 31, 26, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 29, 21, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo e_emlrtECI = { -1, 21, 17, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtECInfo f_emlrtECI = { -1, 19, 17, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 15, 6, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo emlrtDCI = { 15, 6, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 14, 6, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtECInfo g_emlrtECI = { -1, 12, 9, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m"
};

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 12, 9, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 19, 17, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 19, 17, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 21, 17, "uk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo c_emlrtDCI = { 21, 17, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtDCInfo d_emlrtDCI = { 26, 12, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtDCInfo e_emlrtDCI = { 26, 12, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  4 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 29, 15, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 31, 20, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 33, 14, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 35, 14, "xk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 40, 130, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 40, 8, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 45, 130, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 45, 8, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 48, 33, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 48, 46, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 48, 8, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 73, 39, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 73, 55, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 73, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 74, 13, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo f_emlrtDCI = { 74, 13, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 74, 46, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo g_emlrtDCI = { 74, 46, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 74, 67, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo h_emlrtDCI = { 74, 67, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 75, 13, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo i_emlrtDCI = { 75, 13, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 75, 46, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo j_emlrtDCI = { 75, 46, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 75, 67, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo k_emlrtDCI = { 75, 67, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 76, 13, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo l_emlrtDCI = { 76, 13, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 76, 55, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo m_emlrtDCI = { 76, 55, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 76, 86, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo n_emlrtDCI = { 76, 86, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 77, 13, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo o_emlrtDCI = { 77, 13, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 77, 55, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo p_emlrtDCI = { 77, 55, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 77, 86, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo q_emlrtDCI = { 77, 86, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 67, 99, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo r_emlrtDCI = { 67, 99, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 68, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtDCInfo s_emlrtDCI = { 68, 12, "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  1 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 57, 99, "nk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 58, 12, "yk",
  "measurement_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/measurement_eq_17_state.m",
  0 };

/* Function Declarations */
static int32_T div_s32(int32_T numerator, int32_T denominator);
static void eml_error(void);

/* Function Definitions */
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

static void eml_error(void)
{
  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &n_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
}

void measurement_eq_17_state(const real_T xk_data[6250], const int32_T xk_size[2],
  const emxArray_real_T *nk, const real_T uk_data[100], const int32_T uk_size[1],
  emxArray_real_T *yk)
{
  int32_T i0;
  int32_T i1;
  real_T y;
  real_T b_y;
  real_T c_y;
  int32_T n;
  real_T anew;
  real_T apnd;
  boolean_T overflow;
  real_T ndbl;
  real_T cdiff;
  const mxArray *d_y;
  static const int32_T iv0[2] = { 1, 21 };

  const mxArray *m0;
  char_T cv0[21];
  int32_T i;
  static const char_T cv1[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  emxArray_real_T *e_y;
  int32_T k;
  int32_T sz[2];
  emxArray_int32_T *r0;
  emxArray_int32_T *r1;
  int32_T unnamed_idx_0;
  const mxArray *f_y;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *g_y;
  emxArray_int32_T *r5;
  const mxArray *h_y;
  static const int32_T iv1[2] = { 1, 40 };

  char_T cv2[40];
  static const char_T cv3[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  emxArray_int32_T *r6;
  emxArray_int32_T *r7;
  emxArray_int32_T *r8;
  int32_T exitg2;
  emxArray_real_T *RKN_1;
  const mxArray *i_y;
  static const int32_T iv2[2] = { 1, 21 };

  int32_T b_sz[2];
  emxArray_int32_T *r9;
  emxArray_int32_T *r10;
  const mxArray *j_y;
  emxArray_int32_T *r11;
  emxArray_int32_T *r12;
  emxArray_int32_T *r13;
  emxArray_int32_T *r14;
  const mxArray *k_y;
  static const int32_T iv3[2] = { 1, 40 };

  emxArray_int32_T *r15;
  emxArray_int32_T *r16;
  emxArray_int32_T *r17;
  int32_T exitg1;
  emxArray_real_T *RKN_2;
  emxArray_int32_T *r18;
  emxArray_real_T *r19;
  emxArray_real_T *l_y;
  emxArray_real_T *b_yk;
  emxArray_real_T *c_yk;
  emxArray_real_T *d_yk;
  emxArray_real_T *e_yk;
  emxArray_real_T *r20;
  emxArray_real_T *r21;
  emxArray_real_T *r22;
  emxArray_real_T *r23;
  emxArray_real_T *r24;
  emxArray_real_T *r25;
  emxArray_real_T *r26;
  emxArray_real_T *r27;
  emxArray_real_T *r28;
  emxArray_real_T *r29;
  emxArray_real_T *r30;
  emxArray_real_T *r31;
  real_T xk[4];
  real_T b_xk[4];
  real_T Cin[9];
  real_T Cji[9];
  real_T y_kk[3];
  real_T c_xk[2];
  real_T x[2];
  real_T dv0[3];
  int32_T f_yk;
  real_T dv1[3];
  int32_T i2;
  real_T b_Cji[9];
  real_T rij_j_hat[3];
  real_T dv2[3];
  real_T dv3[3];
  real_T b_index[3];
  real_T dv4[3];
  real_T dv5[3];
  real_T dv6[3];
  real_T m_y;
  real_T dv7[3];
  real_T dv8[3];
  static const int8_T iv4[4] = { 2, 3, 5, 6 };

  real_T dv9[4];
  const mxArray *n_y;
  static const int32_T iv5[2] = { 1, 21 };

  uint32_T kd;
  const mxArray *o_y;
  static const int32_T iv6[2] = { 1, 21 };

  const mxArray *p_y;
  static const int32_T iv7[2] = { 1, 21 };

  int32_T iv8[1];
  const mxArray *q_y;
  static const int32_T iv9[2] = { 1, 21 };

  const mxArray *r_y;
  static const int32_T iv10[2] = { 1, 21 };

  const mxArray *s_y;
  static const int32_T iv11[2] = { 1, 21 };

  int32_T iv12[1];
  const mxArray *t_y;
  static const int32_T iv13[2] = { 1, 21 };

  const mxArray *u_y;
  static const int32_T iv14[2] = { 1, 21 };

  const mxArray *v_y;
  static const int32_T iv15[2] = { 1, 21 };

  int32_T iv16[1];
  const mxArray *w_y;
  static const int32_T iv17[2] = { 1, 21 };

  const mxArray *x_y;
  static const int32_T iv18[2] = { 1, 21 };

  const mxArray *y_y;
  static const int32_T iv19[2] = { 1, 21 };

  int32_T iv20[1];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /*  m1: # of features agent 1 sees */
  /*  m2: # of features agent 2 sees */
  /* xk: 17 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion */
  /* nk: 12+3*m1+3*m2 x 2N+1, error on range/bearing/azimuth for agent 1, then agent 2, then magnetometer errors for agent 1 then 2,  */
  /*        THEN feature range/bearing/azimuth errors FOR EACH FEATURE for agent 1, then same for agent 2  */
  /* uk[wi;ai;mag_i;# of i features;rkn;...;# of j features;rkn;...] : 9+2+3*m x 2N+1, m being total # of features from i and j  */
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &g_emlrtECI,
    emlrtRootTLSGlobal);
  for (i0 = 0; i0 < 3; i0++) {
    i1 = 7 + i0;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, uk_size[0], &jb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  emlrtDynamicBoundsCheckFastR2012b(10, 1, uk_size[0], &ib_emlrtBCI,
    emlrtRootTLSGlobal);
  y = 3.0 * uk_data[9];
  b_y = (10.0 + 3.0 * uk_data[9]) + 1.0;
  i0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &emlrtDCI, emlrtRootTLSGlobal);
  emlrtDynamicBoundsCheckFastR2012b(i0, 1, uk_size[0], &hb_emlrtBCI,
    emlrtRootTLSGlobal);

  /*  total # of features */
  /*  3 x m1 array of known inertial position of features seen by agent 1 */
  emlrtPushRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
  c_y = uk_data[9] * 3.0;
  emlrtPushRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
  if (muDoubleScalarIsNaN(c_y)) {
    n = 0;
    anew = rtNaN;
    apnd = c_y;
    overflow = FALSE;
  } else if (c_y < 1.0) {
    n = -1;
    anew = 1.0;
    apnd = c_y;
    overflow = FALSE;
  } else if (muDoubleScalarIsInf(c_y)) {
    n = 0;
    anew = rtNaN;
    apnd = c_y;
    overflow = !(1.0 == c_y);
  } else {
    anew = 1.0;
    ndbl = muDoubleScalarFloor((c_y - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - c_y;
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * c_y) {
      ndbl++;
      apnd = c_y;
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

  emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  if (!overflow) {
  } else {
    emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
    d_y = NULL;
    m0 = mxCreateCharArray(2, iv0);
    for (i = 0; i < 21; i++) {
      cv0[i] = cv1[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
    emlrtAssign(&d_y, m0);
    error(message(d_y, &emlrtMCI), &b_emlrtMCI);
    emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxInit_real_T(&e_y, 2, &b_emlrtRTEI, TRUE);
  emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  i0 = e_y->size[0] * e_y->size[1];
  e_y->size[0] = 1;
  e_y->size[1] = n + 1;
  emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  if (n + 1 > 0) {
    e_y->data[0] = anew;
    if (n + 1 > 1) {
      e_y->data[n] = apnd;
      i0 = n + (n < 0);
      if (i0 >= 0) {
        i = (int32_T)((uint32_T)i0 >> 1);
      } else {
        i = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 1; k < i; k++) {
        e_y->data[k] = anew + (real_T)k;
        e_y->data[n - k] = apnd - (real_T)k;
      }

      if (i << 1 == n) {
        e_y->data[i] = (anew + apnd) / 2.0;
      } else {
        e_y->data[i] = anew + (real_T)i;
        e_y->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, e_y->size[1], &f_emlrtECI,
    emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    b_y = 10.0 + e_y->data[i0];
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &b_emlrtDCI,
      emlrtRootTLSGlobal);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, uk_size[0], &kb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  sz[0] = 3;
  sz[1] = 1;
  i = 1;
  for (k = 0; k < 2; k++) {
    i *= sz[k];
  }

  if (i > 0) {
    b_emxInit_int32_T(&r0, 2, &b_emlrtRTEI, TRUE);
    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    for (i0 = 0; i0 < n; i0++) {
      r0->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
    }

    b_emxInit_int32_T(&r1, 2, &b_emlrtRTEI, TRUE);
    unnamed_idx_0 = r0->size[1];
    i = div_s32(unnamed_idx_0, i);
    i0 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    emxFree_int32_T(&r0);
    for (i0 = 0; i0 < n; i0++) {
      r1->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
    }

    unnamed_idx_0 = r1->size[1];
    emxFree_int32_T(&r1);
    if (i <= unnamed_idx_0) {
    } else {
      emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
      f_y = NULL;
      m0 = mxCreateString("Assertion failed.");
      emlrtAssign(&f_y, m0);
      error(f_y, &e_emlrtMCI);
      emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    }

    sz[1] = i;
  } else {
    sz[1] = 0;
  }

  b_emxInit_int32_T(&r2, 2, &b_emlrtRTEI, TRUE);
  i0 = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = e_y->size[1];
  emxEnsureCapacity((emxArray__common *)r2, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    r2->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
  }

  i = r2->size[1];
  emxFree_int32_T(&r2);
  if (1 > i) {
    i = 1;
  }

  b_emxInit_int32_T(&r3, 2, &b_emlrtRTEI, TRUE);
  i0 = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = e_y->size[1];
  emxEnsureCapacity((emxArray__common *)r3, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    r3->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
  }

  unnamed_idx_0 = r3->size[1];
  emxFree_int32_T(&r3);
  if (unnamed_idx_0 < i) {
  } else {
    b_emxInit_int32_T(&r4, 2, &b_emlrtRTEI, TRUE);
    i0 = r4->size[0] * r4->size[1];
    r4->size[0] = 1;
    r4->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r4, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    for (i0 = 0; i0 < n; i0++) {
      r4->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
    }

    i = r4->size[1];
    emxFree_int32_T(&r4);
  }

  if (3 > i) {
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    eml_error();
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  }

  if (sz[1] > i) {
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    eml_error();
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxInit_real_T(&g_y, 2, &b_emlrtRTEI, TRUE);
  b_emxInit_int32_T(&r5, 2, &b_emlrtRTEI, TRUE);
  i0 = g_y->size[0] * g_y->size[1];
  g_y->size[0] = 3;
  g_y->size[1] = sz[1];
  emxEnsureCapacity((emxArray__common *)g_y, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  i0 = r5->size[0] * r5->size[1];
  r5->size[0] = 1;
  r5->size[1] = e_y->size[1];
  emxEnsureCapacity((emxArray__common *)r5, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    r5->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
  }

  unnamed_idx_0 = r5->size[1];
  emxFree_int32_T(&r5);
  if (unnamed_idx_0 == 3 * sz[1]) {
  } else {
    emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
    h_y = NULL;
    m0 = mxCreateCharArray(2, iv1);
    for (i = 0; i < 40; i++) {
      cv2[i] = cv3[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 40, m0, cv2);
    emlrtAssign(&h_y, m0);
    error(message(h_y, &f_emlrtMCI), &g_emlrtMCI);
    emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  }

  b_emxInit_int32_T(&r6, 2, &b_emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
  i0 = r6->size[0] * r6->size[1];
  r6->size[0] = 1;
  r6->size[1] = e_y->size[1];
  emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    r6->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
  }

  unnamed_idx_0 = r6->size[1];
  emxFree_int32_T(&r6);
  if (1 > unnamed_idx_0) {
    overflow = FALSE;
  } else {
    b_emxInit_int32_T(&r7, 2, &b_emlrtRTEI, TRUE);
    i0 = r7->size[0] * r7->size[1];
    r7->size[0] = 1;
    r7->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    for (i0 = 0; i0 < n; i0++) {
      r7->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
    }

    unnamed_idx_0 = r7->size[1];
    overflow = (unnamed_idx_0 > 2147483646);
    emxFree_int32_T(&r7);
  }

  if (overflow) {
    emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
    check_forloop_overflow_error();
    emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
  k = 0;
  b_emxInit_int32_T(&r8, 2, &b_emlrtRTEI, TRUE);
  do {
    exitg2 = 0;
    i0 = r8->size[0] * r8->size[1];
    r8->size[0] = 1;
    r8->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r8, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    for (i0 = 0; i0 < n; i0++) {
      r8->data[i0] = (int32_T)(10.0 + e_y->data[i0]);
    }

    unnamed_idx_0 = r8->size[1];
    if (k + 1 <= unnamed_idx_0) {
      g_y->data[k] = uk_data[(int32_T)(10.0 + e_y->data[e_y->size[0] * k]) - 1];
      k++;
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  emxFree_int32_T(&r8);
  emxInit_real_T(&RKN_1, 2, &d_emlrtRTEI, TRUE);
  i0 = RKN_1->size[0] * RKN_1->size[1];
  RKN_1->size[0] = g_y->size[1];
  RKN_1->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)RKN_1, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  for (i0 = 0; i0 < 3; i0++) {
    n = g_y->size[1];
    for (i1 = 0; i1 < n; i1++) {
      RKN_1->data[i1 + RKN_1->size[0] * i0] = g_y->data[i0 + g_y->size[0] * i1];
    }
  }

  emlrtPopRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);

  /*  3 x m2 array of known inertial position of features seen by agent 2 */
  emlrtPushRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
  c_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
  emlrtPushRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
  if (muDoubleScalarIsNaN(c_y)) {
    n = 0;
    anew = rtNaN;
    apnd = c_y;
    overflow = FALSE;
  } else if (c_y < 1.0) {
    n = -1;
    anew = 1.0;
    apnd = c_y;
    overflow = FALSE;
  } else if (muDoubleScalarIsInf(c_y)) {
    n = 0;
    anew = rtNaN;
    apnd = c_y;
    overflow = !(1.0 == c_y);
  } else {
    anew = 1.0;
    ndbl = muDoubleScalarFloor((c_y - 1.0) + 0.5);
    apnd = 1.0 + ndbl;
    cdiff = (1.0 + ndbl) - c_y;
    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * c_y) {
      ndbl++;
      apnd = c_y;
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

  emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  if (!overflow) {
  } else {
    emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
    i_y = NULL;
    m0 = mxCreateCharArray(2, iv2);
    for (i = 0; i < 21; i++) {
      cv0[i] = cv1[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
    emlrtAssign(&i_y, m0);
    error(message(i_y, &emlrtMCI), &b_emlrtMCI);
    emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  i0 = e_y->size[0] * e_y->size[1];
  e_y->size[0] = 1;
  e_y->size[1] = n + 1;
  emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  if (n + 1 > 0) {
    e_y->data[0] = anew;
    if (n + 1 > 1) {
      e_y->data[n] = apnd;
      i0 = n + (n < 0);
      if (i0 >= 0) {
        i = (int32_T)((uint32_T)i0 >> 1);
      } else {
        i = ~(int32_T)((uint32_T)~i0 >> 1);
      }

      emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      for (k = 1; k < i; k++) {
        e_y->data[k] = anew + (real_T)k;
        e_y->data[n - k] = apnd - (real_T)k;
      }

      if (i << 1 == n) {
        e_y->data[i] = (anew + apnd) / 2.0;
      } else {
        e_y->data[i] = anew + (real_T)i;
        e_y->data[i + 1] = apnd - (real_T)i;
      }
    }
  }

  emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, e_y->size[1], &e_emlrtECI,
    emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
  c_y = 3.0 * uk_data[9];
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    b_y = (10.0 + c_y) + e_y->data[i0];
    i1 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &c_emlrtDCI,
      emlrtRootTLSGlobal);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, uk_size[0], &lb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  b_sz[0] = 3;
  b_sz[1] = 1;
  i = 1;
  for (k = 0; k < 2; k++) {
    i *= b_sz[k];
  }

  if (i > 0) {
    b_emxInit_int32_T(&r9, 2, &b_emlrtRTEI, TRUE);
    i0 = r9->size[0] * r9->size[1];
    r9->size[0] = 1;
    r9->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r9, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    for (i0 = 0; i0 < n; i0++) {
      r9->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
    }

    b_emxInit_int32_T(&r10, 2, &b_emlrtRTEI, TRUE);
    unnamed_idx_0 = r9->size[1];
    i = div_s32(unnamed_idx_0, i);
    i0 = r10->size[0] * r10->size[1];
    r10->size[0] = 1;
    r10->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r10, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    emxFree_int32_T(&r9);
    for (i0 = 0; i0 < n; i0++) {
      r10->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
    }

    unnamed_idx_0 = r10->size[1];
    emxFree_int32_T(&r10);
    if (i <= unnamed_idx_0) {
    } else {
      emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
      j_y = NULL;
      m0 = mxCreateString("Assertion failed.");
      emlrtAssign(&j_y, m0);
      error(j_y, &e_emlrtMCI);
      emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    }

    b_sz[1] = i;
  } else {
    b_sz[1] = 0;
  }

  b_emxInit_int32_T(&r11, 2, &b_emlrtRTEI, TRUE);
  i0 = r11->size[0] * r11->size[1];
  r11->size[0] = 1;
  r11->size[1] = e_y->size[1];
  emxEnsureCapacity((emxArray__common *)r11, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    r11->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
  }

  i = r11->size[1];
  emxFree_int32_T(&r11);
  if (1 > i) {
    i = 1;
  }

  b_emxInit_int32_T(&r12, 2, &b_emlrtRTEI, TRUE);
  i0 = r12->size[0] * r12->size[1];
  r12->size[0] = 1;
  r12->size[1] = e_y->size[1];
  emxEnsureCapacity((emxArray__common *)r12, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    r12->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
  }

  unnamed_idx_0 = r12->size[1];
  emxFree_int32_T(&r12);
  if (unnamed_idx_0 < i) {
  } else {
    b_emxInit_int32_T(&r13, 2, &b_emlrtRTEI, TRUE);
    i0 = r13->size[0] * r13->size[1];
    r13->size[0] = 1;
    r13->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r13, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    for (i0 = 0; i0 < n; i0++) {
      r13->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
    }

    i = r13->size[1];
    emxFree_int32_T(&r13);
  }

  if (3 > i) {
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    eml_error();
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  }

  if (b_sz[1] > i) {
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    eml_error();
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  }

  b_emxInit_int32_T(&r14, 2, &b_emlrtRTEI, TRUE);
  i0 = g_y->size[0] * g_y->size[1];
  g_y->size[0] = 3;
  g_y->size[1] = b_sz[1];
  emxEnsureCapacity((emxArray__common *)g_y, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  i0 = r14->size[0] * r14->size[1];
  r14->size[0] = 1;
  r14->size[1] = e_y->size[1];
  emxEnsureCapacity((emxArray__common *)r14, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    r14->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
  }

  unnamed_idx_0 = r14->size[1];
  emxFree_int32_T(&r14);
  if (unnamed_idx_0 == 3 * b_sz[1]) {
  } else {
    emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
    k_y = NULL;
    m0 = mxCreateCharArray(2, iv3);
    for (i = 0; i < 40; i++) {
      cv2[i] = cv3[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 40, m0, cv2);
    emlrtAssign(&k_y, m0);
    error(message(k_y, &f_emlrtMCI), &g_emlrtMCI);
    emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  }

  b_emxInit_int32_T(&r15, 2, &b_emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
  i0 = r15->size[0] * r15->size[1];
  r15->size[0] = 1;
  r15->size[1] = e_y->size[1];
  emxEnsureCapacity((emxArray__common *)r15, i0, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  n = e_y->size[0] * e_y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    r15->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
  }

  unnamed_idx_0 = r15->size[1];
  emxFree_int32_T(&r15);
  if (1 > unnamed_idx_0) {
    overflow = FALSE;
  } else {
    b_emxInit_int32_T(&r16, 2, &b_emlrtRTEI, TRUE);
    i0 = r16->size[0] * r16->size[1];
    r16->size[0] = 1;
    r16->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r16, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    for (i0 = 0; i0 < n; i0++) {
      r16->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
    }

    unnamed_idx_0 = r16->size[1];
    overflow = (unnamed_idx_0 > 2147483646);
    emxFree_int32_T(&r16);
  }

  if (overflow) {
    emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
    check_forloop_overflow_error();
    emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
  k = 0;
  b_emxInit_int32_T(&r17, 2, &b_emlrtRTEI, TRUE);
  do {
    exitg1 = 0;
    i0 = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    r17->size[1] = e_y->size[1];
    emxEnsureCapacity((emxArray__common *)r17, i0, (int32_T)sizeof(int32_T),
                      &b_emlrtRTEI);
    n = e_y->size[0] * e_y->size[1];
    for (i0 = 0; i0 < n; i0++) {
      r17->data[i0] = (int32_T)((10.0 + c_y) + e_y->data[i0]);
    }

    unnamed_idx_0 = r17->size[1];
    if (k + 1 <= unnamed_idx_0) {
      g_y->data[k] = uk_data[(int32_T)((10.0 + c_y) + e_y->data[e_y->size[0] * k])
        - 1];
      k++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_int32_T(&r17);
  emxInit_real_T(&RKN_2, 2, &e_emlrtRTEI, TRUE);
  i0 = RKN_2->size[0] * RKN_2->size[1];
  RKN_2->size[0] = g_y->size[1];
  RKN_2->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)RKN_2, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  for (i0 = 0; i0 < 3; i0++) {
    n = g_y->size[1];
    for (i1 = 0; i1 < n; i1++) {
      RKN_2->data[i1 + RKN_2->size[0] * i0] = g_y->data[i0 + g_y->size[0] * i1];
    }
  }

  emxFree_real_T(&g_y);
  emlrtPopRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
  c_y = 3.0 * (uk_data[9] + uk_data[(int32_T)((10.0 + y) + 1.0) - 1]);
  b_y = 9.0 + c_y;
  b_y = emlrtNonNegativeCheckFastR2012b(b_y, &e_emlrtDCI, emlrtRootTLSGlobal);
  emlrtIntegerCheckFastR2012b(b_y, &d_emlrtDCI, emlrtRootTLSGlobal);
  i0 = yk->size[0] * yk->size[1];
  yk->size[0] = (int32_T)(9.0 + c_y);
  emxEnsureCapacity((emxArray__common *)yk, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  b_y = 9.0 + c_y;
  b_y = emlrtNonNegativeCheckFastR2012b(b_y, &e_emlrtDCI, emlrtRootTLSGlobal);
  emlrtIntegerCheckFastR2012b(b_y, &d_emlrtDCI, emlrtRootTLSGlobal);
  i0 = yk->size[0] * yk->size[1];
  yk->size[1] = xk_size[1];
  emxEnsureCapacity((emxArray__common *)yk, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  b_y = 9.0 + c_y;
  b_y = emlrtNonNegativeCheckFastR2012b(b_y, &e_emlrtDCI, emlrtRootTLSGlobal);
  n = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &d_emlrtDCI, emlrtRootTLSGlobal)
    * xk_size[1];
  for (i0 = 0; i0 < n; i0++) {
    yk->data[i0] = 0.0;
  }

  k = 0;
  emxInit_int32_T(&r18, 1, &b_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r19, 1, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&l_y, 2, &b_emlrtRTEI, TRUE);
  b_emxInit_real_T(&b_yk, 1, &b_emlrtRTEI, TRUE);
  b_emxInit_real_T(&c_yk, 1, &b_emlrtRTEI, TRUE);
  b_emxInit_real_T(&d_yk, 1, &b_emlrtRTEI, TRUE);
  b_emxInit_real_T(&e_yk, 1, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r20, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r21, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r22, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r23, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r24, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r25, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r26, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r27, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r28, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r29, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r30, 2, &b_emlrtRTEI, TRUE);
  emxInit_real_T(&r31, 2, &b_emlrtRTEI, TRUE);
  while (k <= xk_size[1] - 1) {
    /*  i to j frame transform */
    for (i0 = 0; i0 < 4; i0++) {
      i1 = 14 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, xk_size[0], &mb_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, xk_size[1], &gb_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  est relative position */
    for (i0 = 0; i0 < 3; i0++) {
      i1 = 11 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, xk_size[0], &nb_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, xk_size[1], &fb_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  estimated my inertial position */
    for (i0 = 0; i0 < 3; i0++) {
      i1 = 1 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, xk_size[0], &ob_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, xk_size[1], &eb_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  my estimated inertial attitude */
    for (i0 = 0; i0 < 4; i0++) {
      i1 = 7 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, xk_size[0], &pb_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, xk_size[1], &db_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      xk[i0] = xk_data[(i0 + xk_size[0] * k) + 6];
      b_xk[i0] = xk_data[(i0 + xk_size[0] * k) + 13];
    }

    attparsilentmex(xk, Cin);
    attparsilentmex(b_xk, Cji);

    /*  expected range/bearing/azimuth from agent i's measurement */
    emlrtPushRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 3; i0++) {
      y_kk[i0] = xk_data[(i0 + xk_size[0] * k) + 10];
    }

    for (i0 = 0; i0 < 2; i0++) {
      c_xk[i0] = y_kk[i0];
    }

    b_power(c_xk, x);
    apnd = x[0] + x[1];
    b_sqrt(&apnd);
    for (i0 = 0; i0 < 3; i0++) {
      y_kk[i0] = xk_data[(i0 + xk_size[0] * k) + 10];
    }

    power(y_kk, dv0);
    b_y = sum(dv0);
    b_sqrt(&b_y);
    f_yk = yk->size[0];
    i = yk->size[1];
    i0 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, i, &t_emlrtBCI, emlrtRootTLSGlobal);
    i0 = nk->size[1];
    i1 = 1 + k;
    i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &cb_emlrtBCI,
      emlrtRootTLSGlobal);
    dv1[0] = b_y;
    dv1[1] = muDoubleScalarAtan2(xk_data[xk_size[0] * k + 11], xk_data[10 +
      xk_size[0] * k]);
    dv1[2] = muDoubleScalarAtan2(xk_data[xk_size[0] * k + 12], apnd);
    for (i1 = 0; i1 < 3; i1++) {
      i2 = nk->size[0];
      unnamed_idx_0 = 1 + i1;
      i = 1 + i1;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, f_yk, &rb_emlrtBCI,
                 emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = dv1[i1] +
        nk->data[(emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i2,
        &qb_emlrtBCI, emlrtRootTLSGlobal) + nk->size[0] * (i0 - 1)) - 1];
    }

    emlrtPopRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);

    /*  expectated relative vector from agent j's measurement */
    for (i0 = 0; i0 < 3; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_Cji[i1 + 3 * i0] = -Cji[i1 + 3 * i0];
      }

      y_kk[i0] = xk_data[(i0 + xk_size[0] * k) + 10];
    }

    for (i0 = 0; i0 < 3; i0++) {
      rij_j_hat[i0] = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        rij_j_hat[i0] += b_Cji[i0 + 3 * i1] * y_kk[i1];
      }
    }

    /*  expected range/bearing/azimuth from agent j's measurement */
    emlrtPushRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
    b_power(*(real_T (*)[2])&rij_j_hat[0], x);
    apnd = x[0] + x[1];
    b_sqrt(&apnd);
    power(rij_j_hat, dv2);
    b_y = sum(dv2);
    b_sqrt(&b_y);
    f_yk = yk->size[0];
    i = yk->size[1];
    i0 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, i, &s_emlrtBCI, emlrtRootTLSGlobal);
    i0 = nk->size[1];
    i1 = 1 + k;
    i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &bb_emlrtBCI,
      emlrtRootTLSGlobal);
    dv3[0] = b_y;
    dv3[1] = muDoubleScalarAtan2(rij_j_hat[1], rij_j_hat[0]);
    dv3[2] = muDoubleScalarAtan2(rij_j_hat[2], apnd);
    for (i1 = 0; i1 < 3; i1++) {
      i2 = nk->size[0];
      unnamed_idx_0 = 4 + i1;
      i = 4 + i1;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, f_yk, &tb_emlrtBCI,
                 emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = dv3[i1] +
        nk->data[(emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i2,
        &sb_emlrtBCI, emlrtRootTLSGlobal) + nk->size[0] * (i0 - 1)) - 1];
    }

    emlrtPopRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);

    /*  expected magnetometer measurement */
    i0 = nk->size[1];
    i1 = 1 + k;
    i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &ab_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i1 = 0; i1 < 3; i1++) {
      i2 = nk->size[0];
      unnamed_idx_0 = 7 + i1;
      rij_j_hat[i1] = uk_data[i1 + 6] + nk->data
        [(emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i2, &ub_emlrtBCI,
           emlrtRootTLSGlobal) + nk->size[0] * (i0 - 1)) - 1];
    }

    f_yk = yk->size[0];
    i = yk->size[1];
    i0 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, i, &r_emlrtBCI, emlrtRootTLSGlobal);
    i0 = nk->size[1];
    i1 = 1 + k;
    i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &y_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i1 = 0; i1 < 3; i1++) {
      b_y = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_y += Cji[i1 + 3 * i2] * rij_j_hat[i2];
      }

      i2 = nk->size[0];
      unnamed_idx_0 = 10 + i1;
      i = 7 + i1;
      yk->data[(emlrtDynamicBoundsCheckFastR2012b(i, 1, f_yk, &wb_emlrtBCI,
                 emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = b_y - nk->data
        [(emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1, i2, &vb_emlrtBCI,
           emlrtRootTLSGlobal) + nk->size[0] * (i0 - 1)) - 1];
    }

    /*  feature measurements */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, uk_data[9], mxDOUBLE_CLASS, (int32_T)
      uk_data[9], &m_emlrtRTEI, emlrtRootTLSGlobal);
    n = 0;
    while (n <= (int32_T)uk_data[9] - 1) {
      /*  get the i frame vector to the feature */
      i0 = RKN_1->size[0];
      i1 = (int32_T)(1.0 + (real_T)n);
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &x_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i1 = 0; i1 < 3; i1++) {
        b_index[i1] = RKN_1->data[(i0 + RKN_1->size[0] * i1) - 1];
      }

      for (i0 = 0; i0 < 3; i0++) {
        dv4[i0] = b_index[i0] - xk_data[i0 + xk_size[0] * k];
      }

      /*  the index for now */
      c_y = ((1.0 + (real_T)n) - 1.0) * 3.0;
      for (i0 = 0; i0 < 3; i0++) {
        rij_j_hat[i0] = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          rij_j_hat[i0] += Cin[i0 + 3 * i1] * dv4[i1];
        }

        b_index[i0] = c_y + (1.0 + (real_T)i0);
      }

      /*  compute range/bearing/declination */
      emlrtPushRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
      b_power(*(real_T (*)[2])&rij_j_hat[0], x);
      apnd = x[0] + x[1];
      b_sqrt(&apnd);
      power(rij_j_hat, dv5);
      b_y = sum(dv5);
      b_sqrt(&b_y);
      i0 = nk->size[1];
      i1 = 1 + k;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &w_emlrtBCI,
        emlrtRootTLSGlobal);
      dv6[0] = b_y;
      dv6[1] = muDoubleScalarAtan2(rij_j_hat[1], rij_j_hat[0]);
      dv6[2] = muDoubleScalarAtan2(rij_j_hat[2], apnd);
      for (i1 = 0; i1 < 3; i1++) {
        i2 = nk->size[0];
        unnamed_idx_0 = (int32_T)(12.0 + b_index[i1]);
        y_kk[i1] = dv6[i1] + nk->data[(emlrtDynamicBoundsCheckFastR2012b
          (unnamed_idx_0, 1, i2, &pc_emlrtBCI, emlrtRootTLSGlobal) + nk->size[0]
          * (i0 - 1)) - 1];
      }

      emlrtPopRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
      f_yk = yk->size[0];
      i = yk->size[1];
      i0 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, i, &q_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 3; i0++) {
        i1 = (int32_T)(9.0 + b_index[i0]);
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, f_yk, &qc_emlrtBCI,
                   emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = y_kk[i0];
      }

      n++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, uk_data[(int32_T)((10.0 + y) + 1.0)
      - 1], mxDOUBLE_CLASS, (int32_T)uk_data[(int32_T)((10.0 + 3.0 * uk_data[9])
      + 1.0) - 1], &l_emlrtRTEI, emlrtRootTLSGlobal);
    n = 0;
    while (n <= (int32_T)uk_data[(int32_T)((10.0 + 3.0 * uk_data[9]) + 1.0) - 1]
           - 1) {
      /*  get the j frame vector to the feature */
      i0 = RKN_2->size[0];
      i1 = (int32_T)(1.0 + (real_T)n);
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &v_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i1 = 0; i1 < 3; i1++) {
        b_index[i1] = RKN_2->data[(i0 + RKN_2->size[0] * i1) - 1];
      }

      for (i0 = 0; i0 < 3; i0++) {
        y_kk[i0] = xk_data[(i0 + xk_size[0] * k) + 10];
        for (i1 = 0; i1 < 3; i1++) {
          b_Cji[i0 + 3 * i1] = 0.0;
          for (i2 = 0; i2 < 3; i2++) {
            b_Cji[i0 + 3 * i1] += Cji[i0 + 3 * i2] * Cin[i2 + 3 * i1];
          }
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        b_y = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          b_y += Cin[i1 + 3 * i0] * y_kk[i1];
        }

        dv4[i0] = (b_index[i0] - b_y) - xk_data[i0 + xk_size[0] * k];
      }

      /*  the index for now */
      c_y = ((1.0 + (real_T)n) - 1.0) * 3.0;
      m_y = uk_data[9] * 3.0;
      for (i0 = 0; i0 < 3; i0++) {
        rij_j_hat[i0] = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          rij_j_hat[i0] += b_Cji[i0 + 3 * i1] * dv4[i1];
        }

        b_index[i0] = (c_y + (1.0 + (real_T)i0)) + m_y;
      }

      /*  compute range/bearing/declination */
      emlrtPushRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
      b_power(*(real_T (*)[2])&rij_j_hat[0], x);
      apnd = x[0] + x[1];
      b_sqrt(&apnd);
      power(rij_j_hat, dv7);
      b_y = sum(dv7);
      b_sqrt(&b_y);
      i0 = nk->size[1];
      i1 = 1 + k;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &u_emlrtBCI,
        emlrtRootTLSGlobal);
      dv8[0] = b_y;
      dv8[1] = muDoubleScalarAtan2(rij_j_hat[1], rij_j_hat[0]);
      dv8[2] = muDoubleScalarAtan2(rij_j_hat[2], apnd);
      for (i1 = 0; i1 < 3; i1++) {
        i2 = nk->size[0];
        b_y = 12.0 + b_index[i1];
        unnamed_idx_0 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &r_emlrtDCI,
          emlrtRootTLSGlobal);
        y_kk[i1] = dv8[i1] + nk->data[(emlrtDynamicBoundsCheckFastR2012b
          (unnamed_idx_0, 1, i2, &nc_emlrtBCI, emlrtRootTLSGlobal) + nk->size[0]
          * (i0 - 1)) - 1];
      }

      emlrtPopRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
      f_yk = yk->size[0];
      i = yk->size[1];
      i0 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, i, &p_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 3; i0++) {
        b_y = 9.0 + b_index[i0];
        i1 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &s_emlrtDCI,
          emlrtRootTLSGlobal);
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, f_yk, &oc_emlrtBCI,
                   emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = y_kk[i0];
      }

      n++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    if (1 + k > 1) {
      /*  minimize all angle differences */
      i0 = yk->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &n_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
      i0 = yk->size[1];
      i1 = 1 + k;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &o_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i1 = 0; i1 < 4; i1++) {
        i2 = yk->size[0];
        unnamed_idx_0 = iv4[i1];
        xk[i1] = yk->data[(emlrtDynamicBoundsCheckFastR2012b(unnamed_idx_0, 1,
          i2, &xb_emlrtBCI, emlrtRootTLSGlobal) + yk->size[0] * (i0 - 1)) - 1];
      }

      for (i0 = 0; i0 < 4; i0++) {
        i1 = yk->size[0];
        i2 = iv4[i0];
        b_xk[i0] = yk->data[emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &yb_emlrtBCI, emlrtRootTLSGlobal) - 1];
      }

      minangle(xk, b_xk, dv9);
      f_yk = yk->size[0];
      i = yk->size[1];
      i0 = 1 + k;
      emlrtDynamicBoundsCheckFastR2012b(i0, 1, i, &m_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 4; i0++) {
        i1 = iv4[i0];
        yk->data[(emlrtDynamicBoundsCheckFastR2012b(i1, 1, f_yk, &ac_emlrtBCI,
                   emlrtRootTLSGlobal) + yk->size[0] * k) - 1] = dv9[i0];
      }

      emlrtPopRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (c_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == c_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((c_y - 2.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (2.0 + m_y) - c_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * c_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          c_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          c_y = 2.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        n_y = NULL;
        m0 = mxCreateCharArray(2, iv5);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&n_y, m0);
        error(message(n_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        e_y->data[0] = anew;
        if (n + 1 > 1) {
          e_y->data[n] = c_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            e_y->data[unnamed_idx_0] = anew + (real_T)kd;
            e_y->data[n - unnamed_idx_0] = c_y - (real_T)kd;
          }

          if (i << 1 == n) {
            e_y->data[i] = (anew + c_y) / 2.0;
          } else {
            kd = i * 3U;
            e_y->data[i] = anew + (real_T)kd;
            e_y->data[i + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r20->size[0] * r20->size[1];
      r20->size[0] = 1;
      r20->size[1] = e_y->size[1];
      emxEnsureCapacity((emxArray__common *)r20, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = e_y->size[0] * e_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = 9.0 + e_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &f_emlrtDCI,
          emlrtRootTLSGlobal);
        r20->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &bc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r18->size[0];
      r18->size[0] = r20->size[1];
      emxEnsureCapacity((emxArray__common *)r18, i0, (int32_T)sizeof(int32_T),
                        &b_emlrtRTEI);
      n = r20->size[1];
      for (i0 = 0; i0 < n; i0++) {
        r18->data[i0] = (int32_T)r20->data[i0] - 1;
      }

      emlrtPopRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
      i0 = yk->size[1];
      i1 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &j_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = yk->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &k_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (c_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == c_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((c_y - 2.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (2.0 + m_y) - c_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * c_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          c_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          c_y = 2.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        o_y = NULL;
        m0 = mxCreateCharArray(2, iv6);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&o_y, m0);
        error(message(o_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        e_y->data[0] = anew;
        if (n + 1 > 1) {
          e_y->data[n] = c_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            e_y->data[unnamed_idx_0] = anew + (real_T)kd;
            e_y->data[n - unnamed_idx_0] = c_y - (real_T)kd;
          }

          if (i << 1 == n) {
            e_y->data[i] = (anew + c_y) / 2.0;
          } else {
            kd = i * 3U;
            e_y->data[i] = anew + (real_T)kd;
            e_y->data[i + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (c_y < 2.0) {
        n = -1;
        anew = 2.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(2.0 == c_y);
      } else {
        anew = 2.0;
        ndbl = muDoubleScalarFloor((c_y - 2.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (2.0 + m_y) - c_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * c_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          c_y = 2.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          c_y = 2.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        p_y = NULL;
        m0 = mxCreateCharArray(2, iv7);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&p_y, m0);
        error(message(p_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = l_y->size[0] * l_y->size[1];
      l_y->size[0] = 1;
      l_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)l_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        l_y->data[0] = anew;
        if (n + 1 > 1) {
          l_y->data[n] = c_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            l_y->data[unnamed_idx_0] = anew + (real_T)kd;
            l_y->data[n - unnamed_idx_0] = c_y - (real_T)kd;
          }

          if (i << 1 == n) {
            l_y->data[i] = (anew + c_y) / 2.0;
          } else {
            kd = i * 3U;
            l_y->data[i] = anew + (real_T)kd;
            l_y->data[i + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r21->size[0] * r21->size[1];
      r21->size[0] = 1;
      r21->size[1] = e_y->size[1];
      emxEnsureCapacity((emxArray__common *)r21, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = e_y->size[0] * e_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = 9.0 + e_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &g_emlrtDCI,
          emlrtRootTLSGlobal);
        r21->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &cc_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r21->size[1];
      i0 = yk->size[1];
      i1 = 1 + k;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &l_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = r19->size[0];
      r19->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r19, i1, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i1 = 0; i1 < unnamed_idx_0; i1++) {
        r19->data[i1] = yk->data[((int32_T)r21->data[i1] + yk->size[0] * (i0 - 1))
          - 1];
      }

      i0 = r22->size[0] * r22->size[1];
      r22->size[0] = 1;
      r22->size[1] = l_y->size[1];
      emxEnsureCapacity((emxArray__common *)r22, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = l_y->size[0] * l_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = 9.0 + l_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &h_emlrtDCI,
          emlrtRootTLSGlobal);
        r22->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &dc_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r22->size[1];
      i0 = e_yk->size[0];
      e_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)e_yk, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i0 = 0; i0 < unnamed_idx_0; i0++) {
        e_yk->data[i0] = yk->data[(int32_T)r22->data[i0] - 1];
      }

      c_minangle(r19, e_yk);
      emlrtPopRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
      iv8[0] = r18->size[0];
      emlrtSubAssignSizeCheckR2012b(iv8, 1, *(int32_T (*)[1])r19->size, 1,
        &d_emlrtECI, emlrtRootTLSGlobal);
      n = r19->size[0];
      for (i0 = 0; i0 < n; i0++) {
        yk->data[r18->data[i0] + yk->size[0] * k] = r19->data[i0];
      }

      emlrtPushRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (c_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == c_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((c_y - 3.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (3.0 + m_y) - c_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * c_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          c_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          c_y = 3.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        q_y = NULL;
        m0 = mxCreateCharArray(2, iv9);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&q_y, m0);
        error(message(q_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        e_y->data[0] = anew;
        if (n + 1 > 1) {
          e_y->data[n] = c_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            e_y->data[unnamed_idx_0] = anew + (real_T)kd;
            e_y->data[n - unnamed_idx_0] = c_y - (real_T)kd;
          }

          if (i << 1 == n) {
            e_y->data[i] = (anew + c_y) / 2.0;
          } else {
            kd = i * 3U;
            e_y->data[i] = anew + (real_T)kd;
            e_y->data[i + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r23->size[0] * r23->size[1];
      r23->size[0] = 1;
      r23->size[1] = e_y->size[1];
      emxEnsureCapacity((emxArray__common *)r23, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = e_y->size[0] * e_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = 9.0 + e_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &i_emlrtDCI,
          emlrtRootTLSGlobal);
        r23->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &ec_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r18->size[0];
      r18->size[0] = r23->size[1];
      emxEnsureCapacity((emxArray__common *)r18, i0, (int32_T)sizeof(int32_T),
                        &b_emlrtRTEI);
      n = r23->size[1];
      for (i0 = 0; i0 < n; i0++) {
        r18->data[i0] = (int32_T)r23->data[i0] - 1;
      }

      emlrtPopRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
      i0 = yk->size[1];
      i1 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &g_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = yk->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &h_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (c_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == c_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((c_y - 3.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (3.0 + m_y) - c_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * c_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          c_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          c_y = 3.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        r_y = NULL;
        m0 = mxCreateCharArray(2, iv10);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&r_y, m0);
        error(message(r_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        e_y->data[0] = anew;
        if (n + 1 > 1) {
          e_y->data[n] = c_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            e_y->data[unnamed_idx_0] = anew + (real_T)kd;
            e_y->data[n - unnamed_idx_0] = c_y - (real_T)kd;
          }

          if (i << 1 == n) {
            e_y->data[i] = (anew + c_y) / 2.0;
          } else {
            kd = i * 3U;
            e_y->data[i] = anew + (real_T)kd;
            e_y->data[i + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      if (muDoubleScalarIsNaN(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = FALSE;
      } else if (c_y < 3.0) {
        n = -1;
        anew = 3.0;
        overflow = FALSE;
      } else if (muDoubleScalarIsInf(c_y)) {
        n = 0;
        anew = rtNaN;
        overflow = !(3.0 == c_y);
      } else {
        anew = 3.0;
        ndbl = muDoubleScalarFloor((c_y - 3.0) / 3.0 + 0.5);
        m_y = ndbl * 3.0;
        cdiff = (3.0 + m_y) - c_y;
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * c_y) {
          ndbl++;
        } else if (cdiff > 0.0) {
          c_y = 3.0 + (ndbl - 1.0) * 3.0;
        } else {
          ndbl++;
          c_y = 3.0 + m_y;
        }

        overflow = (2.147483647E+9 < ndbl);
        if (ndbl >= 0.0) {
          n = (int32_T)ndbl - 1;
        } else {
          n = -1;
        }
      }

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        s_y = NULL;
        m0 = mxCreateCharArray(2, iv11);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&s_y, m0);
        error(message(s_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = l_y->size[0] * l_y->size[1];
      l_y->size[0] = 1;
      l_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)l_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        l_y->data[0] = anew;
        if (n + 1 > 1) {
          l_y->data[n] = c_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            l_y->data[unnamed_idx_0] = anew + (real_T)kd;
            l_y->data[n - unnamed_idx_0] = c_y - (real_T)kd;
          }

          if (i << 1 == n) {
            l_y->data[i] = (anew + c_y) / 2.0;
          } else {
            kd = i * 3U;
            l_y->data[i] = anew + (real_T)kd;
            l_y->data[i + 1] = c_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r24->size[0] * r24->size[1];
      r24->size[0] = 1;
      r24->size[1] = e_y->size[1];
      emxEnsureCapacity((emxArray__common *)r24, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = e_y->size[0] * e_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = 9.0 + e_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &j_emlrtDCI,
          emlrtRootTLSGlobal);
        r24->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &fc_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r24->size[1];
      i0 = yk->size[1];
      i1 = 1 + k;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &i_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = r19->size[0];
      r19->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r19, i1, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i1 = 0; i1 < unnamed_idx_0; i1++) {
        r19->data[i1] = yk->data[((int32_T)r24->data[i1] + yk->size[0] * (i0 - 1))
          - 1];
      }

      i0 = r25->size[0] * r25->size[1];
      r25->size[0] = 1;
      r25->size[1] = l_y->size[1];
      emxEnsureCapacity((emxArray__common *)r25, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = l_y->size[0] * l_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = 9.0 + l_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &k_emlrtDCI,
          emlrtRootTLSGlobal);
        r25->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &gc_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r25->size[1];
      i0 = d_yk->size[0];
      d_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)d_yk, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i0 = 0; i0 < unnamed_idx_0; i0++) {
        d_yk->data[i0] = yk->data[(int32_T)r25->data[i0] - 1];
      }

      c_minangle(r19, d_yk);
      emlrtPopRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
      iv12[0] = r18->size[0];
      emlrtSubAssignSizeCheckR2012b(iv12, 1, *(int32_T (*)[1])r19->size, 1,
        &c_emlrtECI, emlrtRootTLSGlobal);
      n = r19->size[0];
      for (i0 = 0; i0 < n; i0++) {
        yk->data[r18->data[i0] + yk->size[0] * k] = r19->data[i0];
      }

      emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
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

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        t_y = NULL;
        m0 = mxCreateCharArray(2, iv13);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&t_y, m0);
        error(message(t_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        e_y->data[0] = anew;
        if (n + 1 > 1) {
          e_y->data[n] = m_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            e_y->data[unnamed_idx_0] = anew + (real_T)kd;
            e_y->data[n - unnamed_idx_0] = m_y - (real_T)kd;
          }

          if (i << 1 == n) {
            e_y->data[i] = (anew + m_y) / 2.0;
          } else {
            kd = i * 3U;
            e_y->data[i] = anew + (real_T)kd;
            e_y->data[i + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r26->size[0] * r26->size[1];
      r26->size[0] = 1;
      r26->size[1] = e_y->size[1];
      emxEnsureCapacity((emxArray__common *)r26, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = e_y->size[0] * e_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = (9.0 + c_y) + e_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &l_emlrtDCI,
          emlrtRootTLSGlobal);
        r26->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &hc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r18->size[0];
      r18->size[0] = r26->size[1];
      emxEnsureCapacity((emxArray__common *)r18, i0, (int32_T)sizeof(int32_T),
                        &b_emlrtRTEI);
      n = r26->size[1];
      for (i0 = 0; i0 < n; i0++) {
        r18->data[i0] = (int32_T)r26->data[i0] - 1;
      }

      emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
      i0 = yk->size[1];
      i1 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &d_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = yk->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &e_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
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

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        u_y = NULL;
        m0 = mxCreateCharArray(2, iv14);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&u_y, m0);
        error(message(u_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        e_y->data[0] = anew;
        if (n + 1 > 1) {
          e_y->data[n] = m_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            e_y->data[unnamed_idx_0] = anew + (real_T)kd;
            e_y->data[n - unnamed_idx_0] = m_y - (real_T)kd;
          }

          if (i << 1 == n) {
            e_y->data[i] = (anew + m_y) / 2.0;
          } else {
            kd = i * 3U;
            e_y->data[i] = anew + (real_T)kd;
            e_y->data[i + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      b_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
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

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        v_y = NULL;
        m0 = mxCreateCharArray(2, iv15);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&v_y, m0);
        error(message(v_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = l_y->size[0] * l_y->size[1];
      l_y->size[0] = 1;
      l_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)l_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        l_y->data[0] = anew;
        if (n + 1 > 1) {
          l_y->data[n] = b_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
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

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r27->size[0] * r27->size[1];
      r27->size[0] = 1;
      r27->size[1] = e_y->size[1];
      emxEnsureCapacity((emxArray__common *)r27, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = e_y->size[0] * e_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = (9.0 + c_y) + e_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &m_emlrtDCI,
          emlrtRootTLSGlobal);
        r27->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &ic_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r27->size[1];
      i0 = yk->size[1];
      i1 = 1 + k;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &f_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = r19->size[0];
      r19->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r19, i1, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i1 = 0; i1 < unnamed_idx_0; i1++) {
        r19->data[i1] = yk->data[((int32_T)r27->data[i1] + yk->size[0] * (i0 - 1))
          - 1];
      }

      i0 = r28->size[0] * r28->size[1];
      r28->size[0] = 1;
      r28->size[1] = l_y->size[1];
      emxEnsureCapacity((emxArray__common *)r28, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = l_y->size[0] * l_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = (9.0 + m_y) + l_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &n_emlrtDCI,
          emlrtRootTLSGlobal);
        r28->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &jc_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r28->size[1];
      i0 = c_yk->size[0];
      c_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)c_yk, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i0 = 0; i0 < unnamed_idx_0; i0++) {
        c_yk->data[i0] = yk->data[(int32_T)r28->data[i0] - 1];
      }

      c_minangle(r19, c_yk);
      emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
      iv16[0] = r18->size[0];
      emlrtSubAssignSizeCheckR2012b(iv16, 1, *(int32_T (*)[1])r19->size, 1,
        &b_emlrtECI, emlrtRootTLSGlobal);
      n = r19->size[0];
      for (i0 = 0; i0 < n; i0++) {
        yk->data[r18->data[i0] + yk->size[0] * k] = r19->data[i0];
      }

      emlrtPushRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
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

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        w_y = NULL;
        m0 = mxCreateCharArray(2, iv17);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&w_y, m0);
        error(message(w_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        e_y->data[0] = anew;
        if (n + 1 > 1) {
          e_y->data[n] = m_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            e_y->data[unnamed_idx_0] = anew + (real_T)kd;
            e_y->data[n - unnamed_idx_0] = m_y - (real_T)kd;
          }

          if (i << 1 == n) {
            e_y->data[i] = (anew + m_y) / 2.0;
          } else {
            kd = i * 3U;
            e_y->data[i] = anew + (real_T)kd;
            e_y->data[i + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r29->size[0] * r29->size[1];
      r29->size[0] = 1;
      r29->size[1] = e_y->size[1];
      emxEnsureCapacity((emxArray__common *)r29, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = e_y->size[0] * e_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = (9.0 + c_y) + e_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &o_emlrtDCI,
          emlrtRootTLSGlobal);
        r29->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &kc_emlrtBCI, emlrtRootTLSGlobal);
      }

      i0 = r18->size[0];
      r18->size[0] = r29->size[1];
      emxEnsureCapacity((emxArray__common *)r18, i0, (int32_T)sizeof(int32_T),
                        &b_emlrtRTEI);
      n = r29->size[1];
      for (i0 = 0; i0 < n; i0++) {
        r18->data[i0] = (int32_T)r29->data[i0] - 1;
      }

      emlrtPopRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
      i0 = yk->size[1];
      i1 = (int32_T)(1.0 + (real_T)k);
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &emlrtBCI, emlrtRootTLSGlobal);
      i0 = yk->size[1];
      emlrtDynamicBoundsCheckFastR2012b(1, 1, i0, &b_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
      c_y = 3.0 * uk_data[9];
      m_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
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

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        x_y = NULL;
        m0 = mxCreateCharArray(2, iv18);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&x_y, m0);
        error(message(x_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = e_y->size[0] * e_y->size[1];
      e_y->size[0] = 1;
      e_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)e_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        e_y->data[0] = anew;
        if (n + 1 > 1) {
          e_y->data[n] = m_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          for (unnamed_idx_0 = 1; unnamed_idx_0 < i; unnamed_idx_0++) {
            kd = unnamed_idx_0 * 3U;
            e_y->data[unnamed_idx_0] = anew + (real_T)kd;
            e_y->data[n - unnamed_idx_0] = m_y - (real_T)kd;
          }

          if (i << 1 == n) {
            e_y->data[i] = (anew + m_y) / 2.0;
          } else {
            kd = i * 3U;
            e_y->data[i] = anew + (real_T)kd;
            e_y->data[i + 1] = m_y - (real_T)kd;
          }
        }
      }

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      m_y = 3.0 * uk_data[9];
      b_y = 3.0 * uk_data[(int32_T)((10.0 + y) + 1.0) - 1];
      emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
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

      emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      if (!overflow) {
      } else {
        emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
        y_y = NULL;
        m0 = mxCreateCharArray(2, iv19);
        for (i = 0; i < 21; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m0, cv0);
        emlrtAssign(&y_y, m0);
        error(message(y_y, &emlrtMCI), &b_emlrtMCI);
        emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
      i0 = l_y->size[0] * l_y->size[1];
      l_y->size[0] = 1;
      l_y->size[1] = n + 1;
      emxEnsureCapacity((emxArray__common *)l_y, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      if (n + 1 > 0) {
        l_y->data[0] = anew;
        if (n + 1 > 1) {
          l_y->data[n] = b_y;
          i0 = n + (n < 0);
          if (i0 >= 0) {
            i = (int32_T)((uint32_T)i0 >> 1);
          } else {
            i = ~(int32_T)((uint32_T)~i0 >> 1);
          }

          emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
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

      emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
      i0 = r30->size[0] * r30->size[1];
      r30->size[0] = 1;
      r30->size[1] = e_y->size[1];
      emxEnsureCapacity((emxArray__common *)r30, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = e_y->size[0] * e_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = (9.0 + c_y) + e_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &p_emlrtDCI,
          emlrtRootTLSGlobal);
        r30->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &lc_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r30->size[1];
      i0 = yk->size[1];
      i1 = 1 + k;
      i0 = emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &c_emlrtBCI,
        emlrtRootTLSGlobal);
      i1 = r19->size[0];
      r19->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)r19, i1, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i1 = 0; i1 < unnamed_idx_0; i1++) {
        r19->data[i1] = yk->data[((int32_T)r30->data[i1] + yk->size[0] * (i0 - 1))
          - 1];
      }

      i0 = r31->size[0] * r31->size[1];
      r31->size[0] = 1;
      r31->size[1] = l_y->size[1];
      emxEnsureCapacity((emxArray__common *)r31, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      n = l_y->size[0] * l_y->size[1];
      for (i0 = 0; i0 < n; i0++) {
        i1 = yk->size[0];
        b_y = (9.0 + m_y) + l_y->data[i0];
        i2 = (int32_T)emlrtIntegerCheckFastR2012b(b_y, &q_emlrtDCI,
          emlrtRootTLSGlobal);
        r31->data[i0] = emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
          &mc_emlrtBCI, emlrtRootTLSGlobal);
      }

      unnamed_idx_0 = r31->size[1];
      i0 = b_yk->size[0];
      b_yk->size[0] = unnamed_idx_0;
      emxEnsureCapacity((emxArray__common *)b_yk, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i0 = 0; i0 < unnamed_idx_0; i0++) {
        b_yk->data[i0] = yk->data[(int32_T)r31->data[i0] - 1];
      }

      c_minangle(r19, b_yk);
      emlrtPopRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
      iv20[0] = r18->size[0];
      emlrtSubAssignSizeCheckR2012b(iv20, 1, *(int32_T (*)[1])r19->size, 1,
        &emlrtECI, emlrtRootTLSGlobal);
      n = r19->size[0];
      for (i0 = 0; i0 < n; i0++) {
        yk->data[r18->data[i0] + yk->size[0] * k] = r19->data[i0];
      }
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&r31);
  emxFree_real_T(&r30);
  emxFree_real_T(&r29);
  emxFree_real_T(&r28);
  emxFree_real_T(&r27);
  emxFree_real_T(&r26);
  emxFree_real_T(&r25);
  emxFree_real_T(&r24);
  emxFree_real_T(&r23);
  emxFree_real_T(&r22);
  emxFree_real_T(&r21);
  emxFree_real_T(&r20);
  emxFree_real_T(&e_yk);
  emxFree_real_T(&d_yk);
  emxFree_real_T(&c_yk);
  emxFree_real_T(&b_yk);
  emxFree_real_T(&l_y);
  emxFree_real_T(&e_y);
  emxFree_real_T(&r19);
  emxFree_int32_T(&r18);
  emxFree_real_T(&RKN_2);
  emxFree_real_T(&RKN_1);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (measurement_eq_17_state.c) */
