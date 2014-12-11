/*
 * update_eq_unknown_state.c
 *
 * Code generation for function 'update_eq_unknown_state'
 *
 * C source code generated on: Thu Dec 11 11:40:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "update_eq_unknown_state.h"
#include "norm.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "attparsilentmex.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo x_emlrtRTEI = { 1, 19, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 66, 18, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 66, 57, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 66, 36, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 65, 17, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 65, 54, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 65, 34, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtECInfo ic_emlrtECI = { -1, 63, 5, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 63, 14, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtECInfo jc_emlrtECI = { -1, 63, 19, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtECInfo kc_emlrtECI = { -1, 37, 17, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtECInfo lc_emlrtECI = { -1, 36, 17, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtECInfo mc_emlrtECI = { -1, 34, 10, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtECInfo nc_emlrtECI = { -1, 33, 10, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 30, 15, "vk",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtECInfo oc_emlrtECI = { -1, 27, 11, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtECInfo pc_emlrtECI = { -1, 25, 11, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtECInfo qc_emlrtECI = { -1, 23, 11, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtECInfo rc_emlrtECI = { -1, 21, 11, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtBCInfo id_emlrtBCI = { -1, -1, 19, 17, "xk",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtECInfo sc_emlrtECI = { -1, 15, 8, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtECInfo tc_emlrtECI = { -1, 14, 8, "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m"
};

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 14, 8, "uk",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 15, 8, "uk",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 21, 11, "xhat",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 23, 11, "xhat",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 25, 11, "xhat",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 27, 11, "xhat",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 33, 10, "vn",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 34, 10, "vn",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 36, 17, "vn",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 37, 17, "vn",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 42, 5, "xdot",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 44, 5, "xdot",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 48, 5, "xdot",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 58, 5, "xdot",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 61, 5, "xdot",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 65, 29, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 65, 49, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 65, 12, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 66, 30, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 66, 51, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 66, 12, "xkPlus",
  "update_eq_unknown_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m",
  0 };

/* Function Definitions */
void update_eq_unknown_state(const emxArray_real_T *xk, const emxArray_real_T
  *vk, const real_T uk_data[100], const int32_T uk_size[1], emxArray_real_T
  *xkPlus)
{
  int32_T i4;
  int32_T i5;
  int16_T iv48[2];
  int32_T loop_ub;
  int32_T k;
  emxArray_real_T *y;
  int32_T xk_idx_0;
  int32_T xdot_size_idx_0;
  real_T xdot_data[200];
  real_T vk_data[100];
  real_T wi[3];
  real_T ai[3];
  real_T xk_data[200];
  real_T b_xk[4];
  real_T dv1[9];
  real_T c_xk[3];
  real_T b_ai[3];
  real_T dv2[9];
  real_T d_xk;
  real_T dv3[9];
  real_T e_xk[12];
  real_T dv4[12];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T dv5[9];
  real_T b_xk_data[200];
  real_T dv6[9];
  int32_T tmp_data[200];
  int32_T iv49[1];
  int32_T f_xk[1];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /* xk: 17+5*Nf x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion ... then unknown feature parameters  */
  /* vk: 12 x 2N+1, noise on wi,(wj_est),ai,(vj_inertial) */
  /* uk[wi;ai;mag_i] : 9 x 2N+1 */
  /*  IMU measurements of me */
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &tc_emlrtECI,
    emlrtRootTLSGlobal);
  for (i4 = 0; i4 < 3; i4++) {
    i5 = 1 + i4;
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, uk_size[0], &jd_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &sc_emlrtECI,
    emlrtRootTLSGlobal);
  for (i4 = 0; i4 < 3; i4++) {
    i5 = 4 + i4;
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, uk_size[0], &kd_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i4 = 0; i4 < 2; i4++) {
    iv48[i4] = (int16_T)xk->size[i4];
  }

  i4 = xkPlus->size[0] * xkPlus->size[1];
  xkPlus->size[0] = iv48[0];
  emxEnsureCapacity((emxArray__common *)xkPlus, i4, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  i4 = xkPlus->size[0] * xkPlus->size[1];
  xkPlus->size[1] = iv48[1];
  emxEnsureCapacity((emxArray__common *)xkPlus, i4, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  loop_ub = iv48[0] * iv48[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    xkPlus->data[i4] = 0.0;
  }

  k = 0;
  b_emxInit_real_T(&y, 1, &x_emlrtRTEI, TRUE);
  while (k <= xk->size[1] - 1) {
    i4 = xk->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &id_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  hist position relative to my. My body frame */
    i4 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &rc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = xk->size[0];
    for (i5 = 0; i5 < 3; i5++) {
      xk_idx_0 = 11 + i5;
      emlrtDynamicBoundsCheckFastR2012b(xk_idx_0, 1, i4, &ld_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  my velocity */
    i4 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &qc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = xk->size[0];
    for (i5 = 0; i5 < 3; i5++) {
      xk_idx_0 = 4 + i5;
      emlrtDynamicBoundsCheckFastR2012b(xk_idx_0, 1, i4, &md_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  my attitude */
    i4 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 4, &pc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = xk->size[0];
    for (i5 = 0; i5 < 4; i5++) {
      xk_idx_0 = 7 + i5;
      emlrtDynamicBoundsCheckFastR2012b(xk_idx_0, 1, i4, &nd_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  his attitude relative to mine. His body frame */
    i4 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 4, &oc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = xk->size[0];
    for (i5 = 0; i5 < 4; i5++) {
      xk_idx_0 = 14 + i5;
      emlrtDynamicBoundsCheckFastR2012b(xk_idx_0, 1, i4, &od_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  the unknown feature locations are in the inertial frame and DO NOT update  */
    i4 = vk->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &hd_emlrtBCI,
      emlrtRootTLSGlobal);
    xdot_size_idx_0 = xk->size[0];
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xdot_data[i4] = 0.0;
    }

    i4 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &nc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = vk->size[0];
    for (i5 = 0; i5 < 3; i5++) {
      xk_idx_0 = 10 + i5;
      emlrtDynamicBoundsCheckFastR2012b(xk_idx_0, 1, i4, &pd_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &mc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = vk->size[0];
    for (i5 = 0; i5 < 3; i5++) {
      xk_idx_0 = 4 + i5;
      emlrtDynamicBoundsCheckFastR2012b(xk_idx_0, 1, i4, &qd_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &lc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = vk->size[0];
    loop_ub = vk->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      vk_data[i5] = vk->data[i5 + vk->size[0] * k];
    }

    for (i5 = 0; i5 < 3; i5++) {
      xk_idx_0 = 1 + i5;
      wi[i5] = uk_data[i5] + vk_data[emlrtDynamicBoundsCheckFastR2012b(xk_idx_0,
        1, i4, &rd_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    i4 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &kc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = vk->size[0];
    loop_ub = vk->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      vk_data[i5] = vk->data[i5 + vk->size[0] * k];
    }

    for (i5 = 0; i5 < 3; i5++) {
      xk_idx_0 = 7 + i5;
      ai[i5] = uk_data[i5 + 3] + vk_data[emlrtDynamicBoundsCheckFastR2012b
        (xk_idx_0, 1, i4, &sd_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    /*  cosine matrix */
    /*  time rate of my position */
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    for (i4 = 0; i4 < 4; i4++) {
      b_xk[i4] = xk_data[i4 + 6];
    }

    attparsilentmex(b_xk, dv1);
    xk_idx_0 = xk->size[0];
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    for (i4 = 0; i4 < 3; i4++) {
      c_xk[i4] = xk_data[i4 + 3];
    }

    for (i4 = 0; i4 < 3; i4++) {
      b_ai[i4] = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        b_ai[i4] += dv1[i5 + 3 * i4] * c_xk[i5];
      }
    }

    for (i4 = 0; i4 < 3; i4++) {
      i5 = 1 + i4;
      xdot_data[emlrtDynamicBoundsCheckFastR2012b(i5, 1, xk_idx_0, &td_emlrtBCI,
        emlrtRootTLSGlobal) - 1] = b_ai[i4];
    }

    /*  time rate of my velocity */
    /* returns the cross product matrix of the vector x */
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    dv2[0] = 0.0;
    dv2[3] = -wi[2];
    dv2[6] = wi[1];
    dv2[1] = wi[2];
    dv2[4] = 0.0;
    dv2[7] = -wi[0];
    dv2[2] = -wi[1];
    dv2[5] = wi[0];
    dv2[8] = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      c_xk[i4] = xk_data[i4 + 3];
    }

    for (i4 = 0; i4 < 3; i4++) {
      d_xk = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        d_xk += dv2[i4 + 3 * i5] * c_xk[i5];
      }

      b_ai[i4] = ai[i4] - d_xk;
    }

    for (i4 = 0; i4 < 3; i4++) {
      i5 = 4 + i4;
      xdot_data[emlrtDynamicBoundsCheckFastR2012b(i5, 1, xdot_size_idx_0,
        &ud_emlrtBCI, emlrtRootTLSGlobal) - 1] = b_ai[i4];
    }

    /*  time rate of my attitude */
    /*  A matrix for qin */
    /* returns the cross product matrix of the vector x */
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    d_xk = xk->data[xk->size[0] * k + 6];
    dv3[0] = 0.0;
    dv3[3] = -xk->data[xk->size[0] * k + 9];
    dv3[6] = xk->data[xk->size[0] * k + 8];
    dv3[1] = xk->data[xk->size[0] * k + 9];
    dv3[4] = 0.0;
    dv3[7] = -xk->data[xk->size[0] * k + 7];
    dv3[2] = -xk->data[xk->size[0] * k + 8];
    dv3[5] = xk->data[xk->size[0] * k + 7];
    dv3[8] = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      e_xk[i4 << 2] = -xk_data[i4 + 7];
      for (i5 = 0; i5 < 3; i5++) {
        e_xk[(i5 + (i4 << 2)) + 1] = d_xk * (real_T)b[i5 + 3 * i4] + dv3[i5 + 3 *
          i4];
      }

      for (i5 = 0; i5 < 4; i5++) {
        dv4[i5 + (i4 << 2)] = 0.5 * e_xk[i5 + (i4 << 2)];
      }
    }

    for (i4 = 0; i4 < 4; i4++) {
      b_xk[i4] = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        b_xk[i4] += dv4[i4 + (i5 << 2)] * wi[i5];
      }
    }

    for (i4 = 0; i4 < 4; i4++) {
      i5 = 7 + i4;
      xdot_data[emlrtDynamicBoundsCheckFastR2012b(i5, 1, xdot_size_idx_0,
        &vd_emlrtBCI, emlrtRootTLSGlobal) - 1] = b_xk[i4];
    }

    /*  relative attitude cosine matrix */
    /*  relative angular velocity in j frame */
    /*  A matrix for q_ji */
    /* returns the cross product matrix of the vector x */
    /*  time rate of relative attitude */
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    for (i4 = 0; i4 < 4; i4++) {
      b_xk[i4] = xk_data[i4 + 13];
    }

    attparsilentmex(b_xk, dv1);
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    d_xk = xk->data[xk->size[0] * k + 13];
    dv5[0] = 0.0;
    dv5[3] = -xk->data[xk->size[0] * k + 16];
    dv5[6] = xk->data[xk->size[0] * k + 15];
    dv5[1] = xk->data[xk->size[0] * k + 16];
    dv5[4] = 0.0;
    dv5[7] = -xk->data[xk->size[0] * k + 14];
    dv5[2] = -xk->data[xk->size[0] * k + 15];
    dv5[5] = xk->data[xk->size[0] * k + 14];
    dv5[8] = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      e_xk[i4 << 2] = -xk_data[i4 + 14];
      for (i5 = 0; i5 < 3; i5++) {
        e_xk[(i5 + (i4 << 2)) + 1] = d_xk * (real_T)b[i5 + 3 * i4] + dv5[i5 + 3 *
          i4];
      }
    }

    loop_ub = vk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      vk_data[i4] = vk->data[i4 + vk->size[0] * k];
    }

    for (i4 = 0; i4 < 3; i4++) {
      for (i5 = 0; i5 < 4; i5++) {
        dv4[i5 + (i4 << 2)] = 0.5 * e_xk[i5 + (i4 << 2)];
      }
    }

    for (i4 = 0; i4 < 3; i4++) {
      d_xk = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        d_xk += dv1[i4 + 3 * i5] * wi[i5];
      }

      b_ai[i4] = vk_data[i4 + 3] - d_xk;
    }

    for (i4 = 0; i4 < 4; i4++) {
      b_xk[i4] = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        b_xk[i4] += dv4[i4 + (i5 << 2)] * b_ai[i5];
      }
    }

    for (i4 = 0; i4 < 4; i4++) {
      i5 = 14 + i4;
      xdot_data[emlrtDynamicBoundsCheckFastR2012b(i5, 1, xdot_size_idx_0,
        &wd_emlrtBCI, emlrtRootTLSGlobal) - 1] = b_xk[i4];
    }

    /*  time rate of relative position */
    /* returns the cross product matrix of the vector x */
    loop_ub = vk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      vk_data[i4] = vk->data[i4 + vk->size[0] * k];
    }

    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    dv6[0] = 0.0;
    dv6[3] = -wi[2];
    dv6[6] = wi[1];
    dv6[1] = wi[2];
    dv6[4] = 0.0;
    dv6[7] = -wi[0];
    dv6[2] = -wi[1];
    dv6[5] = wi[0];
    dv6[8] = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      c_xk[i4] = b_xk_data[i4 + 10];
    }

    for (i4 = 0; i4 < 3; i4++) {
      d_xk = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        d_xk += dv6[i4 + 3 * i5] * c_xk[i5];
      }

      b_ai[i4] = (vk_data[i4 + 9] - xk_data[i4 + 3]) - d_xk;
    }

    for (i4 = 0; i4 < 3; i4++) {
      i5 = 11 + i4;
      xdot_data[emlrtDynamicBoundsCheckFastR2012b(i5, 1, xdot_size_idx_0,
        &xd_emlrtBCI, emlrtRootTLSGlobal) - 1] = b_ai[i4];
    }

    i4 = y->size[0];
    y->size[0] = xdot_size_idx_0;
    emxEnsureCapacity((emxArray__common *)y, i4, (int32_T)sizeof(real_T),
                      &x_emlrtRTEI);
    for (i4 = 0; i4 < xdot_size_idx_0; i4++) {
      y->data[i4] = Ts * xdot_data[i4];
    }

    i4 = xk->size[0];
    i5 = y->size[0];
    emlrtSizeEqCheck1DFastR2012b(i4, i5, &jc_emlrtECI, emlrtRootTLSGlobal);
    loop_ub = xkPlus->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      tmp_data[i4] = i4;
    }

    i4 = xkPlus->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &gd_emlrtBCI,
      emlrtRootTLSGlobal);
    iv49[0] = loop_ub;
    i4 = xk->size[0];
    f_xk[0] = i4;
    emlrtSubAssignSizeCheckR2012b(iv49, 1, f_xk, 1, &ic_emlrtECI,
      emlrtRootTLSGlobal);
    loop_ub = xk->size[0] - 1;
    for (i4 = 0; i4 <= loop_ub; i4++) {
      xkPlus->data[tmp_data[i4] + xkPlus->size[0] * k] = xk->data[i4 + xk->size
        [0] * k] + y->data[i4];
    }

    /* re-normalize quaternions */
    i4 = xkPlus->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &fd_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i4 = 0; i4 < 4; i4++) {
      i5 = xkPlus->size[0];
      xk_idx_0 = 7 + i4;
      emlrtDynamicBoundsCheckFastR2012b(xk_idx_0, 1, i5, &yd_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = xkPlus->size[1];
    i5 = 1 + k;
    i4 = emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &ed_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i5 = 0; i5 < 4; i5++) {
      xk_idx_0 = xkPlus->size[0];
      loop_ub = 7 + i5;
      b_xk[i5] = xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1,
        xk_idx_0, &ae_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * (i4 - 1))
        - 1];
    }

    d_xk = e_norm(b_xk);
    xk_idx_0 = xkPlus->size[0];
    loop_ub = xkPlus->size[1];
    i4 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i4, 1, loop_ub, &dd_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i4 = 0; i4 < 4; i4++) {
      b_xk[i4] = xkPlus->data[(i4 + xkPlus->size[0] * k) + 6] / d_xk;
    }

    for (i4 = 0; i4 < 4; i4++) {
      i5 = 7 + i4;
      xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(i5, 1, xk_idx_0,
        &be_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * k) - 1] = b_xk[i4];
    }

    i4 = xkPlus->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &cd_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i4 = 0; i4 < 4; i4++) {
      i5 = xkPlus->size[0];
      xk_idx_0 = 14 + i4;
      emlrtDynamicBoundsCheckFastR2012b(xk_idx_0, 1, i5, &ce_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = xkPlus->size[1];
    i5 = 1 + k;
    i4 = emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &bd_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i5 = 0; i5 < 4; i5++) {
      xk_idx_0 = xkPlus->size[0];
      loop_ub = 14 + i5;
      b_xk[i5] = xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1,
        xk_idx_0, &de_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * (i4 - 1))
        - 1];
    }

    d_xk = e_norm(b_xk);
    xk_idx_0 = xkPlus->size[0];
    loop_ub = xkPlus->size[1];
    i4 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i4, 1, loop_ub, &ad_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i4 = 0; i4 < 4; i4++) {
      b_xk[i4] = xkPlus->data[(i4 + xkPlus->size[0] * k) + 13] / d_xk;
    }

    for (i4 = 0; i4 < 4; i4++) {
      i5 = 14 + i4;
      xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(i5, 1, xk_idx_0,
        &ee_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * k) - 1] = b_xk[i4];
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (update_eq_unknown_state.c) */
