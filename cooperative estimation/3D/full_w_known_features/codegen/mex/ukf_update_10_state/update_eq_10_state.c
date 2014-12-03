/*
 * update_eq_10_state.c
 *
 * Code generation for function 'update_eq_10_state'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "update_eq_10_state.h"
#include "norm.h"
#include "attparsilentmex.h"
#include "ukf_update_10_state_emxutil.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo x_emlrtRTEI = { 1, 19, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 44, 17, "xkPlus",
  "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 44, 54, "xkPlus",
  "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 44, 34, "xkPlus",
  "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtECInfo hb_emlrtECI = { -1, 42, 5, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 42, 14, "xkPlus",
  "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtECInfo ib_emlrtECI = { -1, 42, 19, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtECInfo jb_emlrtECI = { -1, 29, 17, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtECInfo kb_emlrtECI = { -1, 28, 17, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 25, 15, "vk", "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtECInfo lb_emlrtECI = { -1, 23, 11, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtECInfo mb_emlrtECI = { -1, 21, 11, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 19, 17, "xk", "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtECInfo nb_emlrtECI = { -1, 15, 8, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtECInfo ob_emlrtECI = { -1, 14, 8, "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m"
};

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 14, 8, "uk", "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 15, 8, "uk", "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 21, 11, "xhat", "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 23, 11, "xhat", "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 28, 17, "vn", "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 29, 17, "vn", "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 44, 29, "xkPlus",
  "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 44, 49, "xkPlus",
  "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 44, 12, "xkPlus",
  "update_eq_10_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_10_state.m",
  0 };

/* Function Definitions */
void update_eq_10_state(const emxArray_real_T *xk, const emxArray_real_T *vk,
  const real_T uk_data[500], const int32_T uk_size[1], emxArray_real_T *xkPlus)
{
  int32_T i6;
  int32_T i7;
  int16_T iv24[2];
  int32_T loop_ub;
  int32_T k;
  int32_T b_loop_ub;
  real_T xdot[10];
  real_T vk_data[500];
  real_T wi[3];
  real_T ai[3];
  real_T xk_data[100];
  real_T b_xk[4];
  real_T dv0[9];
  real_T c_xk[3];
  real_T b_ai[3];
  real_T dv1[9];
  real_T d_xk;
  real_T dv2[9];
  real_T e_xk[12];
  real_T dv3[12];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  int32_T tmp_data[100];
  int32_T iv25[1];
  static const int32_T iv26[1] = { 10 };

  int32_T c_loop_ub;
  real_T b_xk_data[100];
  real_T f_xk[10];

  /* xk: 10 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion */
  /* vk: 6 x 2N+1, noise on wi,ai */
  /* uk[wi;ai] : 6 x 2N+1 */
  /*  IMU measurements of me */
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &ob_emlrtECI,
    emlrtRootTLSGlobal);
  for (i6 = 0; i6 < 3; i6++) {
    i7 = 1 + i6;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &wb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &nb_emlrtECI,
    emlrtRootTLSGlobal);
  for (i6 = 0; i6 < 3; i6++) {
    i7 = 4 + i6;
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, uk_size[0], &xb_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i6 = 0; i6 < 2; i6++) {
    iv24[i6] = (int16_T)xk->size[i6];
  }

  i6 = xkPlus->size[0] * xkPlus->size[1];
  xkPlus->size[0] = iv24[0];
  emxEnsureCapacity((emxArray__common *)xkPlus, i6, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  i6 = xkPlus->size[0] * xkPlus->size[1];
  xkPlus->size[1] = iv24[1];
  emxEnsureCapacity((emxArray__common *)xkPlus, i6, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  loop_ub = iv24[0] * iv24[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    xkPlus->data[i6] = 0.0;
  }

  k = 0;
  while (k <= xk->size[1] - 1) {
    i6 = xk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &vb_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  my velocity */
    i6 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &mb_emlrtECI,
      emlrtRootTLSGlobal);
    i6 = xk->size[0];
    for (i7 = 0; i7 < 3; i7++) {
      b_loop_ub = 4 + i7;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i6, &yb_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  my attitude */
    i6 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 4, &lb_emlrtECI,
      emlrtRootTLSGlobal);
    i6 = xk->size[0];
    for (i7 = 0; i7 < 4; i7++) {
      b_loop_ub = 7 + i7;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i6, &ac_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = vk->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &ub_emlrtBCI,
      emlrtRootTLSGlobal);
    memset(&xdot[0], 0, 10U * sizeof(real_T));
    i6 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &kb_emlrtECI,
      emlrtRootTLSGlobal);
    i6 = vk->size[0];
    loop_ub = vk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      vk_data[i7] = vk->data[i7 + vk->size[0] * k];
    }

    for (i7 = 0; i7 < 3; i7++) {
      b_loop_ub = 1 + i7;
      wi[i7] = uk_data[i7] + vk_data[emlrtDynamicBoundsCheckFastR2012b(b_loop_ub,
        1, i6, &bc_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    i6 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i6, 1, 1, 3, &jb_emlrtECI,
      emlrtRootTLSGlobal);
    i6 = vk->size[0];
    loop_ub = vk->size[0];
    for (i7 = 0; i7 < loop_ub; i7++) {
      vk_data[i7] = vk->data[i7 + vk->size[0] * k];
    }

    for (i7 = 0; i7 < 3; i7++) {
      b_loop_ub = 4 + i7;
      ai[i7] = uk_data[i7 + 3] + vk_data[emlrtDynamicBoundsCheckFastR2012b
        (b_loop_ub, 1, i6, &cc_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    /*  cosine matrix */
    /*  time rate of my position */
    loop_ub = xk->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      xk_data[i6] = xk->data[i6 + xk->size[0] * k];
    }

    for (i6 = 0; i6 < 4; i6++) {
      b_xk[i6] = xk_data[i6 + 6];
    }

    attparsilentmex(b_xk, dv0);
    loop_ub = xk->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      xk_data[i6] = xk->data[i6 + xk->size[0] * k];
    }

    for (i6 = 0; i6 < 3; i6++) {
      c_xk[i6] = xk_data[i6 + 3];
    }

    for (i6 = 0; i6 < 3; i6++) {
      b_ai[i6] = 0.0;
      for (i7 = 0; i7 < 3; i7++) {
        b_ai[i6] += dv0[i7 + 3 * i6] * c_xk[i7];
      }

      xdot[i6] = b_ai[i6];
    }

    /*  time rate of my velocity */
    /* returns the cross product matrix of the vector x */
    loop_ub = xk->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      xk_data[i6] = xk->data[i6 + xk->size[0] * k];
    }

    dv1[0] = 0.0;
    dv1[3] = -wi[2];
    dv1[6] = wi[1];
    dv1[1] = wi[2];
    dv1[4] = 0.0;
    dv1[7] = -wi[0];
    dv1[2] = -wi[1];
    dv1[5] = wi[0];
    dv1[8] = 0.0;
    for (i6 = 0; i6 < 3; i6++) {
      c_xk[i6] = xk_data[i6 + 3];
    }

    for (i6 = 0; i6 < 3; i6++) {
      d_xk = 0.0;
      for (i7 = 0; i7 < 3; i7++) {
        d_xk += dv1[i6 + 3 * i7] * c_xk[i7];
      }

      b_ai[i6] = ai[i6] - d_xk;
    }

    for (i6 = 0; i6 < 3; i6++) {
      xdot[3 + i6] = b_ai[i6];
    }

    /*  time rate of my attitude */
    /*  A matrix for qin */
    /* returns the cross product matrix of the vector x */
    loop_ub = xk->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      xk_data[i6] = xk->data[i6 + xk->size[0] * k];
    }

    d_xk = xk->data[xk->size[0] * k + 6];
    dv2[0] = 0.0;
    dv2[3] = -xk->data[xk->size[0] * k + 9];
    dv2[6] = xk->data[xk->size[0] * k + 8];
    dv2[1] = xk->data[xk->size[0] * k + 9];
    dv2[4] = 0.0;
    dv2[7] = -xk->data[xk->size[0] * k + 7];
    dv2[2] = -xk->data[xk->size[0] * k + 8];
    dv2[5] = xk->data[xk->size[0] * k + 7];
    dv2[8] = 0.0;
    for (i6 = 0; i6 < 3; i6++) {
      e_xk[i6 << 2] = -xk_data[i6 + 7];
      for (i7 = 0; i7 < 3; i7++) {
        e_xk[(i7 + (i6 << 2)) + 1] = d_xk * (real_T)b[i7 + 3 * i6] + dv2[i7 + 3 *
          i6];
      }

      for (i7 = 0; i7 < 4; i7++) {
        dv3[i7 + (i6 << 2)] = 0.5 * e_xk[i7 + (i6 << 2)];
      }
    }

    for (i6 = 0; i6 < 4; i6++) {
      b_xk[i6] = 0.0;
      for (i7 = 0; i7 < 3; i7++) {
        b_xk[i6] += dv3[i6 + (i7 << 2)] * wi[i7];
      }

      xdot[6 + i6] = b_xk[i6];
    }

    i6 = xk->size[0];
    emlrtSizeEqCheck1DFastR2012b(i6, 10, &ib_emlrtECI, emlrtRootTLSGlobal);
    loop_ub = xkPlus->size[0];
    for (i6 = 0; i6 < loop_ub; i6++) {
      tmp_data[i6] = i6;
    }

    i6 = xkPlus->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &tb_emlrtBCI,
      emlrtRootTLSGlobal);
    iv25[0] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(iv25, 1, iv26, 1, &hb_emlrtECI,
      emlrtRootTLSGlobal);
    b_loop_ub = xk->size[0];
    c_loop_ub = xk->size[0];
    for (i6 = 0; i6 < c_loop_ub; i6++) {
      xk_data[i6] = xk->data[i6 + xk->size[0] * k];
    }

    for (i6 = 0; i6 < b_loop_ub; i6++) {
      b_xk_data[i6] = xk_data[i6];
    }

    for (i6 = 0; i6 < 10; i6++) {
      f_xk[i6] = b_xk_data[i6] + Ts * xdot[i6];
    }

    for (i6 = 0; i6 < loop_ub; i6++) {
      xkPlus->data[tmp_data[i6] + xkPlus->size[0] * k] = f_xk[i6];
    }

    /* re-normalize */
    i6 = xkPlus->size[1];
    i7 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &sb_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i6 = 0; i6 < 4; i6++) {
      i7 = xkPlus->size[0];
      b_loop_ub = 7 + i6;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i7, &dc_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i6 = xkPlus->size[1];
    i7 = 1 + k;
    i6 = emlrtDynamicBoundsCheckFastR2012b(i7, 1, i6, &rb_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i7 = 0; i7 < 4; i7++) {
      b_loop_ub = xkPlus->size[0];
      c_loop_ub = 7 + i7;
      b_xk[i7] = xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(c_loop_ub, 1,
        b_loop_ub, &ec_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * (i6 - 1))
        - 1];
    }

    d_xk = e_norm(b_xk);
    c_loop_ub = xkPlus->size[0];
    b_loop_ub = xkPlus->size[1];
    i6 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i6, 1, b_loop_ub, &qb_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i6 = 0; i6 < 4; i6++) {
      b_xk[i6] = xkPlus->data[(i6 + xkPlus->size[0] * k) + 6] / d_xk;
    }

    for (i6 = 0; i6 < 4; i6++) {
      i7 = 7 + i6;
      xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(i7, 1, c_loop_ub,
        &fc_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * k) - 1] = b_xk[i6];
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }
}

/* End of code generation (update_eq_10_state.c) */
