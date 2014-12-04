/*
 * update_eq_17_state.c
 *
 * Code generation for function 'update_eq_17_state'
 *
 * C source code generated on: Thu Dec  4 12:26:46 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_17_state.h"
#include "update_eq_17_state.h"
#include "norm.h"
#include "ukf_update_17_state_emxutil.h"
#include "ukf_update_17_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo x_emlrtRTEI = { 1, 19, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 65, 18, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 65, 57, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 65, 36, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 64, 17, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 64, 54, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 64, 34, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtECInfo vb_emlrtECI = { -1, 62, 5, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 62, 14, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtECInfo wb_emlrtECI = { -1, 62, 19, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo xb_emlrtECI = { -1, 36, 17, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo yb_emlrtECI = { -1, 35, 17, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo ac_emlrtECI = { -1, 33, 10, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo bc_emlrtECI = { -1, 32, 10, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 29, 15, "vk", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtECInfo cc_emlrtECI = { -1, 27, 11, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo dc_emlrtECI = { -1, 25, 11, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo ec_emlrtECI = { -1, 23, 11, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo fc_emlrtECI = { -1, 21, 11, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 19, 17, "xk", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtECInfo gc_emlrtECI = { -1, 15, 8, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo hc_emlrtECI = { -1, 14, 8, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 14, 8, "uk", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 15, 8, "uk", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 21, 11, "xhat", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 23, 11, "xhat", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 25, 11, "xhat", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 27, 11, "xhat", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 32, 10, "vn", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 33, 10, "vn", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 35, 17, "vn", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 36, 17, "vn", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 64, 29, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 64, 49, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 64, 12, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 65, 30, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 65, 51, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 65, 12, "xkPlus",
  "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

/* Function Definitions */
void update_eq_17_state(const emxArray_real_T *xk, const emxArray_real_T *vk,
  const real_T uk_data[250], const int32_T uk_size[1], emxArray_real_T *xkPlus)
{
  int32_T i4;
  int32_T i5;
  int16_T iv36[2];
  int32_T loop_ub;
  int32_T k;
  int32_T b_loop_ub;
  real_T xdot[17];
  real_T vk_data[25];
  real_T wi[3];
  real_T ai[3];
  real_T xk_data[25];
  real_T b_xk[9];
  real_T c_xk[3];
  real_T d_xk[3];
  real_T dv1[9];
  real_T e_xk;
  real_T dv2[9];
  real_T f_xk[12];
  real_T dv3[12];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T b_xkPlus[4];
  real_T dv4[9];
  real_T g_xk[9];
  real_T b_xk_data[25];
  real_T dv5[9];
  int32_T tmp_data[25];
  int32_T iv37[1];
  static const int32_T iv38[1] = { 17 };

  int32_T c_loop_ub;
  real_T h_xk[17];

  /* xk: 17 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion */
  /* vk: 12 x 2N+1, noise on wi,(wj_est),ai,(vj_inertial) */
  /* uk[wi;ai;mag_i] : 9 x 2N+1 */
  /*  IMU measurements of me */
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &hc_emlrtECI,
    emlrtRootTLSGlobal);
  for (i4 = 0; i4 < 3; i4++) {
    i5 = 1 + i4;
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, uk_size[0], &uc_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &gc_emlrtECI,
    emlrtRootTLSGlobal);
  for (i4 = 0; i4 < 3; i4++) {
    i5 = 4 + i4;
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, uk_size[0], &vc_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i4 = 0; i4 < 2; i4++) {
    iv36[i4] = (int16_T)xk->size[i4];
  }

  i4 = xkPlus->size[0] * xkPlus->size[1];
  xkPlus->size[0] = iv36[0];
  emxEnsureCapacity((emxArray__common *)xkPlus, i4, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  i4 = xkPlus->size[0] * xkPlus->size[1];
  xkPlus->size[1] = iv36[1];
  emxEnsureCapacity((emxArray__common *)xkPlus, i4, (int32_T)sizeof(real_T),
                    &x_emlrtRTEI);
  loop_ub = iv36[0] * iv36[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    xkPlus->data[i4] = 0.0;
  }

  k = 0;
  while (k <= xk->size[1] - 1) {
    i4 = xk->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &tc_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  hist position relative to my. My body frame */
    i4 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &fc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = xk->size[0];
    for (i5 = 0; i5 < 3; i5++) {
      b_loop_ub = 11 + i5;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i4, &wc_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  my velocity */
    i4 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &ec_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = xk->size[0];
    for (i5 = 0; i5 < 3; i5++) {
      b_loop_ub = 4 + i5;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i4, &xc_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  my attitude */
    i4 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 4, &dc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = xk->size[0];
    for (i5 = 0; i5 < 4; i5++) {
      b_loop_ub = 7 + i5;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i4, &yc_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  his attitude relative to mine. His body frame */
    i4 = xk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 4, &cc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = xk->size[0];
    for (i5 = 0; i5 < 4; i5++) {
      b_loop_ub = 14 + i5;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i4, &ad_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = vk->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &sc_emlrtBCI,
      emlrtRootTLSGlobal);
    memset(&xdot[0], 0, 17U * sizeof(real_T));
    i4 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &bc_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = vk->size[0];
    for (i5 = 0; i5 < 3; i5++) {
      b_loop_ub = 10 + i5;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i4, &bd_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &ac_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = vk->size[0];
    for (i5 = 0; i5 < 3; i5++) {
      b_loop_ub = 4 + i5;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i4, &cd_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &yb_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = vk->size[0];
    loop_ub = vk->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      vk_data[i5] = vk->data[i5 + vk->size[0] * k];
    }

    for (i5 = 0; i5 < 3; i5++) {
      b_loop_ub = 1 + i5;
      wi[i5] = uk_data[i5] + vk_data[emlrtDynamicBoundsCheckFastR2012b(b_loop_ub,
        1, i4, &dd_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    i4 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i4, 1, 1, 3, &xb_emlrtECI,
      emlrtRootTLSGlobal);
    i4 = vk->size[0];
    loop_ub = vk->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      vk_data[i5] = vk->data[i5 + vk->size[0] * k];
    }

    for (i5 = 0; i5 < 3; i5++) {
      b_loop_ub = 7 + i5;
      ai[i5] = uk_data[i5 + 3] + vk_data[emlrtDynamicBoundsCheckFastR2012b
        (b_loop_ub, 1, i4, &ed_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    /*  cosine matrix */
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
    /* convert DCM to output form */
    /* DCM */
    /* disp('Output value specified as direction cosine matrix.'); */
    /*  time rate of my position */
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    b_xk[0] = ((xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 7] -
                xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k + 8]) -
               xk->data[xk->size[0] * k + 9] * xk->data[xk->size[0] * k + 9]) +
      xk->data[xk->size[0] * k + 6] * xk->data[xk->size[0] * k + 6];
    b_xk[1] = 2.0 * (xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k +
                     8] + xk->data[xk->size[0] * k + 9] * xk->data[xk->size[0] *
                     k + 6]);
    b_xk[2] = 2.0 * (xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k +
                     9] - xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] *
                     k + 6]);
    b_xk[3] = 2.0 * (xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k +
                     8] - xk->data[xk->size[0] * k + 9] * xk->data[xk->size[0] *
                     k + 6]);
    b_xk[4] = ((xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k + 8] -
                xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 7]) -
               xk->data[xk->size[0] * k + 9] * xk->data[xk->size[0] * k + 9]) +
      xk->data[xk->size[0] * k + 6] * xk->data[xk->size[0] * k + 6];
    b_xk[5] = 2.0 * (xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k +
                     9] + xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] *
                     k + 6]);
    b_xk[6] = 2.0 * (xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k +
                     9] + xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] *
                     k + 6]);
    b_xk[7] = 2.0 * (xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k +
                     9] - xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] *
                     k + 6]);
    b_xk[8] = ((xk->data[xk->size[0] * k + 9] * xk->data[xk->size[0] * k + 9] -
                xk->data[xk->size[0] * k + 7] * xk->data[xk->size[0] * k + 7]) -
               xk->data[xk->size[0] * k + 8] * xk->data[xk->size[0] * k + 8]) +
      xk->data[xk->size[0] * k + 6] * xk->data[xk->size[0] * k + 6];
    for (i4 = 0; i4 < 3; i4++) {
      c_xk[i4] = xk_data[i4 + 3];
    }

    for (i4 = 0; i4 < 3; i4++) {
      d_xk[i4] = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        d_xk[i4] += b_xk[i4 + 3 * i5] * c_xk[i5];
      }

      xdot[i4] = d_xk[i4];
    }

    /*  time rate of my velocity */
    /* returns the cross product matrix of the vector x */
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
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
    for (i4 = 0; i4 < 3; i4++) {
      c_xk[i4] = xk_data[i4 + 3];
    }

    for (i4 = 0; i4 < 3; i4++) {
      e_xk = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        e_xk += dv1[i4 + 3 * i5] * c_xk[i5];
      }

      d_xk[i4] = ai[i4] - e_xk;
    }

    for (i4 = 0; i4 < 3; i4++) {
      xdot[3 + i4] = d_xk[i4];
    }

    /*  time rate of my attitude */
    /*  A matrix for qin */
    /* returns the cross product matrix of the vector x */
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    e_xk = xk->data[xk->size[0] * k + 6];
    dv2[0] = 0.0;
    dv2[3] = -xk->data[xk->size[0] * k + 9];
    dv2[6] = xk->data[xk->size[0] * k + 8];
    dv2[1] = xk->data[xk->size[0] * k + 9];
    dv2[4] = 0.0;
    dv2[7] = -xk->data[xk->size[0] * k + 7];
    dv2[2] = -xk->data[xk->size[0] * k + 8];
    dv2[5] = xk->data[xk->size[0] * k + 7];
    dv2[8] = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      f_xk[i4 << 2] = -xk_data[i4 + 7];
      for (i5 = 0; i5 < 3; i5++) {
        f_xk[(i5 + (i4 << 2)) + 1] = e_xk * (real_T)b[i5 + 3 * i4] + dv2[i5 + 3 *
          i4];
      }

      for (i5 = 0; i5 < 4; i5++) {
        dv3[i5 + (i4 << 2)] = 0.5 * f_xk[i5 + (i4 << 2)];
      }
    }

    for (i4 = 0; i4 < 4; i4++) {
      b_xkPlus[i4] = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        b_xkPlus[i4] += dv3[i4 + (i5 << 2)] * wi[i5];
      }

      xdot[6 + i4] = b_xkPlus[i4];
    }

    /*  relative attitude cosine matrix */
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
    /* convert DCM to output form */
    /* DCM */
    /* disp('Output value specified as direction cosine matrix.'); */
    /*  relative angular velocity in j frame */
    /*  A matrix for q_ji */
    /* returns the cross product matrix of the vector x */
    /*  time rate of relative attitude */
    loop_ub = xk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    e_xk = xk->data[xk->size[0] * k + 13];
    dv4[0] = 0.0;
    dv4[3] = -xk->data[xk->size[0] * k + 16];
    dv4[6] = xk->data[xk->size[0] * k + 15];
    dv4[1] = xk->data[xk->size[0] * k + 16];
    dv4[4] = 0.0;
    dv4[7] = -xk->data[xk->size[0] * k + 14];
    dv4[2] = -xk->data[xk->size[0] * k + 15];
    dv4[5] = xk->data[xk->size[0] * k + 14];
    dv4[8] = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      f_xk[i4 << 2] = -xk_data[i4 + 14];
      for (i5 = 0; i5 < 3; i5++) {
        f_xk[(i5 + (i4 << 2)) + 1] = e_xk * (real_T)b[i5 + 3 * i4] + dv4[i5 + 3 *
          i4];
      }
    }

    loop_ub = vk->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      vk_data[i4] = vk->data[i4 + vk->size[0] * k];
    }

    g_xk[0] = ((xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0] * k + 14]
                - xk->data[xk->size[0] * k + 15] * xk->data[xk->size[0] * k + 15])
               - xk->data[xk->size[0] * k + 16] * xk->data[xk->size[0] * k + 16])
      + xk->data[xk->size[0] * k + 13] * xk->data[xk->size[0] * k + 13];
    g_xk[3] = 2.0 * (xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0] * k +
                     15] + xk->data[xk->size[0] * k + 16] * xk->data[xk->size[0]
                     * k + 13]);
    g_xk[6] = 2.0 * (xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0] * k +
                     16] - xk->data[xk->size[0] * k + 15] * xk->data[xk->size[0]
                     * k + 13]);
    g_xk[1] = 2.0 * (xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0] * k +
                     15] - xk->data[xk->size[0] * k + 16] * xk->data[xk->size[0]
                     * k + 13]);
    g_xk[4] = ((xk->data[xk->size[0] * k + 15] * xk->data[xk->size[0] * k + 15]
                - xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0] * k + 14])
               - xk->data[xk->size[0] * k + 16] * xk->data[xk->size[0] * k + 16])
      + xk->data[xk->size[0] * k + 13] * xk->data[xk->size[0] * k + 13];
    g_xk[7] = 2.0 * (xk->data[xk->size[0] * k + 15] * xk->data[xk->size[0] * k +
                     16] + xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0]
                     * k + 13]);
    g_xk[2] = 2.0 * (xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0] * k +
                     16] + xk->data[xk->size[0] * k + 15] * xk->data[xk->size[0]
                     * k + 13]);
    g_xk[5] = 2.0 * (xk->data[xk->size[0] * k + 15] * xk->data[xk->size[0] * k +
                     16] - xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0]
                     * k + 13]);
    g_xk[8] = ((xk->data[xk->size[0] * k + 16] * xk->data[xk->size[0] * k + 16]
                - xk->data[xk->size[0] * k + 14] * xk->data[xk->size[0] * k + 14])
               - xk->data[xk->size[0] * k + 15] * xk->data[xk->size[0] * k + 15])
      + xk->data[xk->size[0] * k + 13] * xk->data[xk->size[0] * k + 13];
    for (i4 = 0; i4 < 3; i4++) {
      for (i5 = 0; i5 < 4; i5++) {
        dv3[i5 + (i4 << 2)] = 0.5 * f_xk[i5 + (i4 << 2)];
      }
    }

    for (i4 = 0; i4 < 3; i4++) {
      e_xk = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        e_xk += g_xk[i4 + 3 * i5] * wi[i5];
      }

      d_xk[i4] = vk_data[i4 + 3] - e_xk;
    }

    for (i4 = 0; i4 < 4; i4++) {
      b_xkPlus[i4] = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        b_xkPlus[i4] += dv3[i4 + (i5 << 2)] * d_xk[i5];
      }

      xdot[13 + i4] = b_xkPlus[i4];
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

    dv5[0] = 0.0;
    dv5[3] = -wi[2];
    dv5[6] = wi[1];
    dv5[1] = wi[2];
    dv5[4] = 0.0;
    dv5[7] = -wi[0];
    dv5[2] = -wi[1];
    dv5[5] = wi[0];
    dv5[8] = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      c_xk[i4] = b_xk_data[i4 + 10];
    }

    for (i4 = 0; i4 < 3; i4++) {
      e_xk = 0.0;
      for (i5 = 0; i5 < 3; i5++) {
        e_xk += dv5[i4 + 3 * i5] * c_xk[i5];
      }

      d_xk[i4] = (vk_data[i4 + 9] - xk_data[i4 + 3]) - e_xk;
    }

    for (i4 = 0; i4 < 3; i4++) {
      xdot[10 + i4] = d_xk[i4];
    }

    i4 = xk->size[0];
    emlrtSizeEqCheck1DFastR2012b(i4, 17, &wb_emlrtECI, emlrtRootTLSGlobal);
    loop_ub = xkPlus->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      tmp_data[i4] = i4;
    }

    i4 = xkPlus->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &rc_emlrtBCI,
      emlrtRootTLSGlobal);
    iv37[0] = loop_ub;
    emlrtSubAssignSizeCheckR2012b(iv37, 1, iv38, 1, &vb_emlrtECI,
      emlrtRootTLSGlobal);
    b_loop_ub = xk->size[0];
    c_loop_ub = xk->size[0];
    for (i4 = 0; i4 < c_loop_ub; i4++) {
      xk_data[i4] = xk->data[i4 + xk->size[0] * k];
    }

    for (i4 = 0; i4 < b_loop_ub; i4++) {
      b_xk_data[i4] = xk_data[i4];
    }

    for (i4 = 0; i4 < 17; i4++) {
      h_xk[i4] = b_xk_data[i4] + Ts * xdot[i4];
    }

    for (i4 = 0; i4 < loop_ub; i4++) {
      xkPlus->data[tmp_data[i4] + xkPlus->size[0] * k] = h_xk[i4];
    }

    /* re-normalize */
    i4 = xkPlus->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &qc_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i4 = 0; i4 < 4; i4++) {
      i5 = xkPlus->size[0];
      b_loop_ub = 7 + i4;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i5, &fd_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = xkPlus->size[1];
    i5 = 1 + k;
    i4 = emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &pc_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i5 = 0; i5 < 4; i5++) {
      b_loop_ub = xkPlus->size[0];
      c_loop_ub = 7 + i5;
      b_xkPlus[i5] = xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(c_loop_ub,
        1, b_loop_ub, &gd_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * (i4
        - 1)) - 1];
    }

    e_xk = e_norm(b_xkPlus);
    c_loop_ub = xkPlus->size[0];
    b_loop_ub = xkPlus->size[1];
    i4 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i4, 1, b_loop_ub, &oc_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i4 = 0; i4 < 4; i4++) {
      b_xkPlus[i4] = xkPlus->data[(i4 + xkPlus->size[0] * k) + 6] / e_xk;
    }

    for (i4 = 0; i4 < 4; i4++) {
      i5 = 7 + i4;
      xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(i5, 1, c_loop_ub,
        &hd_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * k) - 1] =
        b_xkPlus[i4];
    }

    i4 = xkPlus->size[1];
    i5 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &nc_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i4 = 0; i4 < 4; i4++) {
      i5 = xkPlus->size[0];
      b_loop_ub = 14 + i4;
      emlrtDynamicBoundsCheckFastR2012b(b_loop_ub, 1, i5, &id_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i4 = xkPlus->size[1];
    i5 = 1 + k;
    i4 = emlrtDynamicBoundsCheckFastR2012b(i5, 1, i4, &mc_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i5 = 0; i5 < 4; i5++) {
      b_loop_ub = xkPlus->size[0];
      c_loop_ub = 14 + i5;
      b_xkPlus[i5] = xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(c_loop_ub,
        1, b_loop_ub, &jd_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * (i4
        - 1)) - 1];
    }

    e_xk = e_norm(b_xkPlus);
    c_loop_ub = xkPlus->size[0];
    b_loop_ub = xkPlus->size[1];
    i4 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i4, 1, b_loop_ub, &lc_emlrtBCI,
      emlrtRootTLSGlobal);
    for (i4 = 0; i4 < 4; i4++) {
      b_xkPlus[i4] = xkPlus->data[(i4 + xkPlus->size[0] * k) + 13] / e_xk;
    }

    for (i4 = 0; i4 < 4; i4++) {
      i5 = 14 + i4;
      xkPlus->data[(emlrtDynamicBoundsCheckFastR2012b(i5, 1, c_loop_ub,
        &kd_emlrtBCI, emlrtRootTLSGlobal) + xkPlus->size[0] * k) - 1] =
        b_xkPlus[i4];
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }
}

/* End of code generation (update_eq_17_state.c) */
