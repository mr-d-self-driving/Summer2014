/*
 * update_eq_17_state.c
 *
 * Code generation for function 'update_eq_17_state'
 *
 * C source code generated on: Thu Nov 20 12:06:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "update_eq_17_state.h"
#include "norm.h"
#include "update_eq_17_state_data.h"

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = { -1, -1, 65, 18, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 65, 57, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 65, 36, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 64, 17, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 64, 54, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 64, 34, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtECInfo emlrtECI = { -1, 62, 5, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo g_emlrtBCI = { -1, -1, 62, 14, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 62, 19, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo c_emlrtECI = { -1, 36, 17, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo d_emlrtECI = { -1, 35, 17, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo e_emlrtECI = { -1, 33, 10, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo f_emlrtECI = { -1, 32, 10, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo h_emlrtBCI = { -1, -1, 29, 15, "vk", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtECInfo g_emlrtECI = { -1, 27, 11, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo h_emlrtECI = { -1, 25, 11, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo i_emlrtECI = { -1, 23, 11, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo j_emlrtECI = { -1, 21, 11, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo i_emlrtBCI = { -1, -1, 19, 17, "xk", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtECInfo k_emlrtECI = { -1, 15, 8, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtECInfo l_emlrtECI = { -1, 14, 8, "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m"
};

static emlrtBCInfo j_emlrtBCI = { -1, -1, 14, 8, "uk", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 15, 8, "uk", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 21, 11, "xhat", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 23, 11, "xhat", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 25, 11, "xhat", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 27, 11, "xhat", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 32, 10, "vn", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 33, 10, "vn", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 35, 17, "vn", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 36, 17, "vn", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 64, 29, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 64, 49, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 64, 12, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 65, 30, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 65, 51, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 65, 12, "xkPlus", "update_eq_17_state",
  "/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/update_eq_17_state.m",
  0 };

/* Function Definitions */
void update_eq_17_state(const real_T xk_data[6250], const int32_T xk_size[2],
  const emxArray_real_T *vk, const real_T uk_data[250], const int32_T uk_size[1],
  real_T xkPlus_data[6250], int32_T xkPlus_size[2])
{
  int32_T i0;
  int32_T i1;
  uint8_T uv0[2];
  int32_T loop_ub;
  int32_T k;
  real_T xdot[17];
  real_T vk_data[100];
  real_T wi[3];
  real_T ai[3];
  real_T b_xk_data[25];
  real_T xk[9];
  real_T b_xk[3];
  real_T c_xk[3];
  real_T dv0[9];
  real_T B;
  real_T dv1[9];
  real_T d_xk[12];
  real_T dv2[12];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T xkPlus[4];
  real_T dv3[9];
  real_T e_xk[9];
  real_T c_xk_data[25];
  real_T dv4[9];
  uint8_T tmp_data[25];
  int32_T iv0[1];
  static const int32_T iv1[1] = { 17 };

  real_T f_xk[17];

  /* xk: 17 x 2N+1, inertial position, inertial velocity, inertial quaternion, relative position, and relative quaternion */
  /* vk: 12 x 2N+1, noise on wi,(wj_est),ai,(vj_inertial) */
  /* uk[wi;ai;mag_i] : 9 x 2N+1 */
  /*  IMU measurements of me */
  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &l_emlrtECI,
    emlrtRootTLSGlobal);
  for (i0 = 0; i0 < 3; i0++) {
    i1 = 1 + i0;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, uk_size[0], &j_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  emlrtVectorVectorIndexCheckR2012b(uk_size[0], 1, 1, 3, &k_emlrtECI,
    emlrtRootTLSGlobal);
  for (i0 = 0; i0 < 3; i0++) {
    i1 = 4 + i0;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, uk_size[0], &k_emlrtBCI,
      emlrtRootTLSGlobal);
  }

  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint8_T)xk_size[i0];
  }

  xkPlus_size[0] = uv0[0];
  xkPlus_size[1] = uv0[1];
  loop_ub = uv0[0] * uv0[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    xkPlus_data[i0] = 0.0;
  }

  k = 0;
  while (k <= xk_size[1] - 1) {
    i0 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i0, 1, xk_size[1], &i_emlrtBCI,
      emlrtRootTLSGlobal);

    /*  hist position relative to my. My body frame */
    emlrtVectorVectorIndexCheckR2012b(xk_size[0], 1, 1, 3, &j_emlrtECI,
      emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 3; i0++) {
      i1 = 11 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, xk_size[0], &l_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  my velocity */
    emlrtVectorVectorIndexCheckR2012b(xk_size[0], 1, 1, 3, &i_emlrtECI,
      emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 3; i0++) {
      i1 = 4 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, xk_size[0], &m_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  my attitude */
    emlrtVectorVectorIndexCheckR2012b(xk_size[0], 1, 1, 4, &h_emlrtECI,
      emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      i1 = 7 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, xk_size[0], &n_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    /*  his attitude relative to mine. His body frame */
    emlrtVectorVectorIndexCheckR2012b(xk_size[0], 1, 1, 4, &g_emlrtECI,
      emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      i1 = 14 + i0;
      emlrtDynamicBoundsCheckFastR2012b(i1, 1, xk_size[0], &o_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = vk->size[1];
    i1 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &h_emlrtBCI, emlrtRootTLSGlobal);
    memset(&xdot[0], 0, 17U * sizeof(real_T));
    i0 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i0, 1, 1, 3, &f_emlrtECI,
      emlrtRootTLSGlobal);
    i0 = vk->size[0];
    for (i1 = 0; i1 < 3; i1++) {
      loop_ub = 10 + i1;
      emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i0, &p_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i0, 1, 1, 3, &e_emlrtECI,
      emlrtRootTLSGlobal);
    i0 = vk->size[0];
    for (i1 = 0; i1 < 3; i1++) {
      loop_ub = 4 + i1;
      emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i0, &q_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i0, 1, 1, 3, &d_emlrtECI,
      emlrtRootTLSGlobal);
    i0 = vk->size[0];
    loop_ub = vk->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      vk_data[i1] = vk->data[i1 + vk->size[0] * k];
    }

    for (i1 = 0; i1 < 3; i1++) {
      loop_ub = 1 + i1;
      wi[i1] = uk_data[i1] + vk_data[emlrtDynamicBoundsCheckFastR2012b(loop_ub,
        1, i0, &r_emlrtBCI, emlrtRootTLSGlobal) - 1];
    }

    i0 = vk->size[0];
    emlrtVectorVectorIndexCheckR2012b(i0, 1, 1, 3, &c_emlrtECI,
      emlrtRootTLSGlobal);
    i0 = vk->size[0];
    loop_ub = vk->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      vk_data[i1] = vk->data[i1 + vk->size[0] * k];
    }

    for (i1 = 0; i1 < 3; i1++) {
      loop_ub = 7 + i1;
      ai[i1] = uk_data[i1 + 3] + vk_data[emlrtDynamicBoundsCheckFastR2012b
        (loop_ub, 1, i0, &s_emlrtBCI, emlrtRootTLSGlobal) - 1];
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
    loop_ub = xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_xk_data[i0] = xk_data[i0 + xk_size[0] * k];
    }

    xk[0] = ((xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 7] -
              xk_data[xk_size[0] * k + 8] * xk_data[xk_size[0] * k + 8]) -
             xk_data[xk_size[0] * k + 9] * xk_data[xk_size[0] * k + 9]) +
      xk_data[xk_size[0] * k + 6] * xk_data[xk_size[0] * k + 6];
    xk[1] = 2.0 * (xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 8] +
                   xk_data[xk_size[0] * k + 9] * xk_data[xk_size[0] * k + 6]);
    xk[2] = 2.0 * (xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 9] -
                   xk_data[xk_size[0] * k + 8] * xk_data[xk_size[0] * k + 6]);
    xk[3] = 2.0 * (xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 8] -
                   xk_data[xk_size[0] * k + 9] * xk_data[xk_size[0] * k + 6]);
    xk[4] = ((xk_data[xk_size[0] * k + 8] * xk_data[xk_size[0] * k + 8] -
              xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 7]) -
             xk_data[xk_size[0] * k + 9] * xk_data[xk_size[0] * k + 9]) +
      xk_data[xk_size[0] * k + 6] * xk_data[xk_size[0] * k + 6];
    xk[5] = 2.0 * (xk_data[xk_size[0] * k + 8] * xk_data[xk_size[0] * k + 9] +
                   xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 6]);
    xk[6] = 2.0 * (xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 9] +
                   xk_data[xk_size[0] * k + 8] * xk_data[xk_size[0] * k + 6]);
    xk[7] = 2.0 * (xk_data[xk_size[0] * k + 8] * xk_data[xk_size[0] * k + 9] -
                   xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 6]);
    xk[8] = ((xk_data[xk_size[0] * k + 9] * xk_data[xk_size[0] * k + 9] -
              xk_data[xk_size[0] * k + 7] * xk_data[xk_size[0] * k + 7]) -
             xk_data[xk_size[0] * k + 8] * xk_data[xk_size[0] * k + 8]) +
      xk_data[xk_size[0] * k + 6] * xk_data[xk_size[0] * k + 6];
    for (i0 = 0; i0 < 3; i0++) {
      b_xk[i0] = b_xk_data[i0 + 3];
    }

    for (i0 = 0; i0 < 3; i0++) {
      c_xk[i0] = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        c_xk[i0] += xk[i0 + 3 * i1] * b_xk[i1];
      }

      xdot[i0] = c_xk[i0];
    }

    /*  time rate of my velocity */
    /* returns the cross product matrix of the vector x */
    loop_ub = xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_xk_data[i0] = xk_data[i0 + xk_size[0] * k];
    }

    dv0[0] = 0.0;
    dv0[3] = -wi[2];
    dv0[6] = wi[1];
    dv0[1] = wi[2];
    dv0[4] = 0.0;
    dv0[7] = -wi[0];
    dv0[2] = -wi[1];
    dv0[5] = wi[0];
    dv0[8] = 0.0;
    for (i0 = 0; i0 < 3; i0++) {
      b_xk[i0] = b_xk_data[i0 + 3];
    }

    for (i0 = 0; i0 < 3; i0++) {
      B = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        B += dv0[i0 + 3 * i1] * b_xk[i1];
      }

      c_xk[i0] = ai[i0] - B;
    }

    for (i0 = 0; i0 < 3; i0++) {
      xdot[3 + i0] = c_xk[i0];
    }

    /*  time rate of my attitude */
    /*  A matrix for qin */
    /* returns the cross product matrix of the vector x */
    loop_ub = xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_xk_data[i0] = xk_data[i0 + xk_size[0] * k];
    }

    dv1[0] = 0.0;
    dv1[3] = -xk_data[xk_size[0] * k + 9];
    dv1[6] = xk_data[xk_size[0] * k + 8];
    dv1[1] = xk_data[xk_size[0] * k + 9];
    dv1[4] = 0.0;
    dv1[7] = -xk_data[xk_size[0] * k + 7];
    dv1[2] = -xk_data[xk_size[0] * k + 8];
    dv1[5] = xk_data[xk_size[0] * k + 7];
    dv1[8] = 0.0;
    for (i0 = 0; i0 < 3; i0++) {
      d_xk[i0 << 2] = -b_xk_data[i0 + 7];
      for (i1 = 0; i1 < 3; i1++) {
        d_xk[(i1 + (i0 << 2)) + 1] = xk_data[xk_size[0] * k + 6] * (real_T)b[i1
          + 3 * i0] + dv1[i1 + 3 * i0];
      }

      for (i1 = 0; i1 < 4; i1++) {
        dv2[i1 + (i0 << 2)] = 0.5 * d_xk[i1 + (i0 << 2)];
      }
    }

    for (i0 = 0; i0 < 4; i0++) {
      xkPlus[i0] = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        xkPlus[i0] += dv2[i0 + (i1 << 2)] * wi[i1];
      }

      xdot[6 + i0] = xkPlus[i0];
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
    loop_ub = xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_xk_data[i0] = xk_data[i0 + xk_size[0] * k];
    }

    dv3[0] = 0.0;
    dv3[3] = -xk_data[xk_size[0] * k + 16];
    dv3[6] = xk_data[xk_size[0] * k + 15];
    dv3[1] = xk_data[xk_size[0] * k + 16];
    dv3[4] = 0.0;
    dv3[7] = -xk_data[xk_size[0] * k + 14];
    dv3[2] = -xk_data[xk_size[0] * k + 15];
    dv3[5] = xk_data[xk_size[0] * k + 14];
    dv3[8] = 0.0;
    for (i0 = 0; i0 < 3; i0++) {
      d_xk[i0 << 2] = -b_xk_data[i0 + 14];
      for (i1 = 0; i1 < 3; i1++) {
        d_xk[(i1 + (i0 << 2)) + 1] = xk_data[xk_size[0] * k + 13] * (real_T)b[i1
          + 3 * i0] + dv3[i1 + 3 * i0];
      }
    }

    loop_ub = vk->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      vk_data[i0] = vk->data[i0 + vk->size[0] * k];
    }

    e_xk[0] = ((xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k + 14] -
                xk_data[xk_size[0] * k + 15] * xk_data[xk_size[0] * k + 15]) -
               xk_data[xk_size[0] * k + 16] * xk_data[xk_size[0] * k + 16]) +
      xk_data[xk_size[0] * k + 13] * xk_data[xk_size[0] * k + 13];
    e_xk[3] = 2.0 * (xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k + 15]
                     + xk_data[xk_size[0] * k + 16] * xk_data[xk_size[0] * k +
                     13]);
    e_xk[6] = 2.0 * (xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k + 16]
                     - xk_data[xk_size[0] * k + 15] * xk_data[xk_size[0] * k +
                     13]);
    e_xk[1] = 2.0 * (xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k + 15]
                     - xk_data[xk_size[0] * k + 16] * xk_data[xk_size[0] * k +
                     13]);
    e_xk[4] = ((xk_data[xk_size[0] * k + 15] * xk_data[xk_size[0] * k + 15] -
                xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k + 14]) -
               xk_data[xk_size[0] * k + 16] * xk_data[xk_size[0] * k + 16]) +
      xk_data[xk_size[0] * k + 13] * xk_data[xk_size[0] * k + 13];
    e_xk[7] = 2.0 * (xk_data[xk_size[0] * k + 15] * xk_data[xk_size[0] * k + 16]
                     + xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k +
                     13]);
    e_xk[2] = 2.0 * (xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k + 16]
                     + xk_data[xk_size[0] * k + 15] * xk_data[xk_size[0] * k +
                     13]);
    e_xk[5] = 2.0 * (xk_data[xk_size[0] * k + 15] * xk_data[xk_size[0] * k + 16]
                     - xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k +
                     13]);
    e_xk[8] = ((xk_data[xk_size[0] * k + 16] * xk_data[xk_size[0] * k + 16] -
                xk_data[xk_size[0] * k + 14] * xk_data[xk_size[0] * k + 14]) -
               xk_data[xk_size[0] * k + 15] * xk_data[xk_size[0] * k + 15]) +
      xk_data[xk_size[0] * k + 13] * xk_data[xk_size[0] * k + 13];
    for (i0 = 0; i0 < 3; i0++) {
      for (i1 = 0; i1 < 4; i1++) {
        dv2[i1 + (i0 << 2)] = 0.5 * d_xk[i1 + (i0 << 2)];
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      B = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        B += e_xk[i0 + 3 * i1] * wi[i1];
      }

      c_xk[i0] = vk_data[i0 + 3] - B;
    }

    for (i0 = 0; i0 < 4; i0++) {
      xkPlus[i0] = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        xkPlus[i0] += dv2[i0 + (i1 << 2)] * c_xk[i1];
      }

      xdot[13 + i0] = xkPlus[i0];
    }

    /*  time rate of relative position */
    /* returns the cross product matrix of the vector x */
    loop_ub = vk->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      vk_data[i0] = vk->data[i0 + vk->size[0] * k];
    }

    loop_ub = xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_xk_data[i0] = xk_data[i0 + xk_size[0] * k];
    }

    loop_ub = xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_xk_data[i0] = xk_data[i0 + xk_size[0] * k];
    }

    dv4[0] = 0.0;
    dv4[3] = -wi[2];
    dv4[6] = wi[1];
    dv4[1] = wi[2];
    dv4[4] = 0.0;
    dv4[7] = -wi[0];
    dv4[2] = -wi[1];
    dv4[5] = wi[0];
    dv4[8] = 0.0;
    for (i0 = 0; i0 < 3; i0++) {
      b_xk[i0] = c_xk_data[i0 + 10];
    }

    for (i0 = 0; i0 < 3; i0++) {
      B = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        B += dv4[i0 + 3 * i1] * b_xk[i1];
      }

      c_xk[i0] = (vk_data[i0 + 9] - b_xk_data[i0 + 3]) - B;
    }

    for (i0 = 0; i0 < 3; i0++) {
      xdot[10 + i0] = c_xk[i0];
    }

    emlrtSizeEqCheck1DFastR2012b(xk_size[0], 17, &b_emlrtECI, emlrtRootTLSGlobal);
    loop_ub = uv0[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      tmp_data[i0] = (uint8_T)i0;
    }

    i0 = uv0[1];
    i1 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &g_emlrtBCI, emlrtRootTLSGlobal);
    iv0[0] = uv0[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 1, iv1, 1, &emlrtECI, emlrtRootTLSGlobal);
    loop_ub = xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_xk_data[i0] = xk_data[i0 + xk_size[0] * k];
    }

    loop_ub = xk_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_xk_data[i0] = b_xk_data[i0];
    }

    for (i0 = 0; i0 < 17; i0++) {
      f_xk[i0] = c_xk_data[i0] + Ts * xdot[i0];
    }

    loop_ub = uv0[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      xkPlus_data[tmp_data[i0] + uv0[0] * k] = f_xk[i0];
    }

    /* re-normalize */
    i0 = uv0[1];
    i1 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &f_emlrtBCI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      i1 = uv0[0];
      loop_ub = 7 + i0;
      emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i1, &t_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = uv0[1];
    i1 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &e_emlrtBCI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      i1 = uv0[0];
      loop_ub = 7 + i0;
      xkPlus[i0] = xkPlus_data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i1,
        &u_emlrtBCI, emlrtRootTLSGlobal) + uv0[0] * k) - 1];
    }

    B = norm(xkPlus);
    i0 = uv0[1];
    i1 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &d_emlrtBCI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      xkPlus[i0] = xkPlus_data[(i0 + uv0[0] * k) + 6] / B;
    }

    for (i0 = 0; i0 < 4; i0++) {
      i1 = uv0[0];
      loop_ub = 7 + i0;
      xkPlus_data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i1, &v_emlrtBCI,
        emlrtRootTLSGlobal) + uv0[0] * k) - 1] = xkPlus[i0];
    }

    i0 = uv0[1];
    i1 = (int32_T)(1.0 + (real_T)k);
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &c_emlrtBCI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      i1 = uv0[0];
      loop_ub = 14 + i0;
      emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i1, &w_emlrtBCI,
        emlrtRootTLSGlobal);
    }

    i0 = uv0[1];
    i1 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &b_emlrtBCI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      i1 = uv0[0];
      loop_ub = 14 + i0;
      xkPlus[i0] = xkPlus_data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i1,
        &x_emlrtBCI, emlrtRootTLSGlobal) + uv0[0] * k) - 1];
    }

    B = norm(xkPlus);
    i0 = uv0[1];
    i1 = 1 + k;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, i0, &emlrtBCI, emlrtRootTLSGlobal);
    for (i0 = 0; i0 < 4; i0++) {
      xkPlus[i0] = xkPlus_data[(i0 + uv0[0] * k) + 13] / B;
    }

    for (i0 = 0; i0 < 4; i0++) {
      i1 = uv0[0];
      loop_ub = 14 + i0;
      xkPlus_data[(emlrtDynamicBoundsCheckFastR2012b(loop_ub, 1, i1, &y_emlrtBCI,
        emlrtRootTLSGlobal) + uv0[0] * k) - 1] = xkPlus[i0];
    }

    k++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }
}

/* End of code generation (update_eq_17_state.c) */
