/*
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "mldivide.h"
#include "ukf_update_10_state_emxutil.h"
#include "minangle.h"
#include "ukf_update_10_state_mexutil.h"
#include "colon.h"
#include "fprintf.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo ke_emlrtRSI = { 103, "eml_matlab_zlarf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m"
};

static emlrtRSInfo gm_emlrtRSI = { 1, "mldivide",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/mldivide.p"
};

static emlrtRSInfo hm_emlrtRSI = { 20, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRSInfo im_emlrtRSI = { 70, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRSInfo jm_emlrtRSI = { 68, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRSInfo km_emlrtRSI = { 77, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRSInfo lm_emlrtRSI = { 80, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRSInfo mm_emlrtRSI = { 88, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRSInfo nm_emlrtRSI = { 90, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRSInfo qm_emlrtRSI = { 8, "eml_xgetrf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"
};

static emlrtRSInfo rm_emlrtRSI = { 8, "eml_lapack_xgetrf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"
};

static emlrtRSInfo sm_emlrtRSI = { 23, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo tm_emlrtRSI = { 30, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo um_emlrtRSI = { 36, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo vm_emlrtRSI = { 44, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo wm_emlrtRSI = { 50, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo xm_emlrtRSI = { 58, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

static emlrtRSInfo ym_emlrtRSI = { 75, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo an_emlrtRSI = { 112, "colon",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/colon.m"
};

static emlrtRSInfo dn_emlrtRSI = { 20, "eml_ixamax",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"
};

static emlrtRSInfo fn_emlrtRSI = { 24, "eml_blas_ixamax",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m"
};

static emlrtRSInfo hn_emlrtRSI = { 69, "eml_blas_ixamax",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m"
};

static emlrtRSInfo in_emlrtRSI = { 70, "eml_blas_ixamax",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m"
};

static emlrtRSInfo jn_emlrtRSI = { 74, "eml_blas_ixamax",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m"
};

static emlrtRSInfo kn_emlrtRSI = { 80, "eml_blas_ixamax",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m"
};

static emlrtRSInfo ln_emlrtRSI = { 26, "eml_xswap",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"
};

static emlrtRSInfo mn_emlrtRSI = { 15, "eml_blas_xswap",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m"
};

static emlrtRSInfo nn_emlrtRSI = { 19, "eml_refblas_xswap",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m"
};

static emlrtRSInfo on_emlrtRSI = { 42, "eml_xgeru",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"
};

static emlrtRSInfo pn_emlrtRSI = { 105, "eml_blas_xger",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"
};

static emlrtRSInfo qn_emlrtRSI = { 108, "eml_blas_xger",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"
};

static emlrtRSInfo rn_emlrtRSI = { 110, "eml_blas_xger",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"
};

static emlrtRSInfo sn_emlrtRSI = { 54, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRSInfo tn_emlrtRSI = { 54, "eml_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"
};

static emlrtRSInfo vn_emlrtRSI = { 28, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo ao_emlrtRSI = { 87, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo bo_emlrtRSI = { 88, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo co_emlrtRSI = { 89, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo do_emlrtRSI = { 90, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo eo_emlrtRSI = { 94, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo fo_emlrtRSI = { 97, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo go_emlrtRSI = { 100, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo ho_emlrtRSI = { 103, "eml_blas_xtrsm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m"
};

static emlrtRSInfo ko_emlrtRSI = { 29, "eml_qrsolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_qrsolve.m"
};

static emlrtRSInfo lo_emlrtRSI = { 37, "eml_qrsolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_qrsolve.m"
};

static emlrtRSInfo mo_emlrtRSI = { 8, "eml_xgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m"
};

static emlrtRSInfo no_emlrtRSI = { 8, "eml_lapack_xgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m"
};

static emlrtRSInfo oo_emlrtRSI = { 19, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo po_emlrtRSI = { 25, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo qo_emlrtRSI = { 31, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo ro_emlrtRSI = { 32, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo so_emlrtRSI = { 37, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo to_emlrtRSI = { 47, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo uo_emlrtRSI = { 51, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo vo_emlrtRSI = { 64, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo wo_emlrtRSI = { 66, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo xo_emlrtRSI = { 74, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo yo_emlrtRSI = { 79, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo ap_emlrtRSI = { 93, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo bp_emlrtRSI = { 100, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRSInfo cp_emlrtRSI = { 29, "eml_flt2str",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_flt2str.m"
};

static emlrtMCInfo hb_emlrtMCI = { 1, 1, "mldivide",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/mldivide.p"
};

static emlrtMCInfo ib_emlrtMCI = { 29, 23, "eml_flt2str",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_flt2str.m"
};

static emlrtMCInfo jb_emlrtMCI = { 29, 15, "eml_flt2str",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_flt2str.m"
};

static emlrtRTEInfo qb_emlrtRTEI = { 1, 2, "mldivide",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/ops/mldivide.p"
};

static emlrtRTEInfo rb_emlrtRTEI = { 1, 19, "eml_lusolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_lusolve.m"
};

static emlrtRTEInfo tb_emlrtRTEI = { 1, 24, "eml_qrsolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_qrsolve.m"
};

static emlrtRTEInfo ub_emlrtRTEI = { 16, 1, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRTEInfo vb_emlrtRTEI = { 28, 5, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRTEInfo wb_emlrtRTEI = { 29, 5, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRTEInfo xb_emlrtRTEI = { 24, 1, "eml_matlab_zgeqp3",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m"
};

static emlrtRTEInfo fc_emlrtRTEI = { 106, 5, "eml_qrsolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_qrsolve.m"
};

static emlrtRTEInfo gc_emlrtRTEI = { 99, 5, "eml_qrsolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_qrsolve.m"
};

static emlrtRTEInfo hc_emlrtRTEI = { 82, 21, "eml_qrsolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_qrsolve.m"
};

static emlrtRTEInfo ic_emlrtRTEI = { 76, 17, "eml_qrsolve",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_qrsolve.m"
};

/* Function Declarations */
static void b_eml_warning(void);
static const mxArray *b_sprintf(const mxArray *b, const mxArray *c, const
  mxArray *d, emlrtMCInfo *location);
static void c_eml_matlab_zlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  emxArray_real_T *C, int32_T ic0, int32_T ldc, emxArray_real_T *work);
static void c_eml_warning(real_T varargin_2, const char_T varargin_3[14]);
static void c_emlrt_marshallIn(const mxArray *d_sprintf, const char_T
  *identifier, char_T y[14]);
static const mxArray *c_message(const mxArray *b, const mxArray *c, const
  mxArray *d, emlrtMCInfo *location);
static const mxArray *c_sprintf(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[14]);
static void eml_lusolve(const emxArray_real_T *A, const emxArray_real_T *B,
  emxArray_real_T *X);
static void eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B,
  emxArray_real_T *Y);
static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[14]);

/* Function Definitions */
static void b_eml_warning(void)
{
  const mxArray *y;
  static const int32_T iv41[2] = { 1, 27 };

  const mxArray *m13;
  char_T cv49[27];
  int32_T i;
  static const char_T cv50[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  emlrtPushRtStackR2012b(&bh_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_synchGlobalsToML();
  y = NULL;
  m13 = mxCreateCharArray(2, iv41);
  for (i = 0; i < 27; i++) {
    cv49[i] = cv50[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 27, m13, cv49);
  emlrtAssign(&y, m13);
  warning(message(y, &k_emlrtMCI), &l_emlrtMCI);
  emlrt_synchGlobalsFromML();
  emlrtPopRtStackR2012b(&bh_emlrtRSI, emlrtRootTLSGlobal);
}

static const mxArray *b_sprintf(const mxArray *b, const mxArray *c, const
  mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m23;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m23, 3, pArrays,
    "sprintf", TRUE, location);
}

static void c_eml_matlab_zlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  emxArray_real_T *C, int32_T ic0, int32_T ldc, emxArray_real_T *work)
{
  int32_T lastv;
  int32_T lastc;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * alpha1_t;
  double * beta1_t;
  double * yiy0_t;
  double * Aia0_t;
  double * xix0_t;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C->data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    emlrtPushRtStackR2012b(&le_emlrtRSI, emlrtRootTLSGlobal);
    lastc = ilazlc(lastv, n, C, ic0, ldc);
    emlrtPopRtStackR2012b(&le_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    emlrtPushRtStackR2012b(&me_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bd_emlrtRSI, emlrtRootTLSGlobal);
    if (lastc < 1) {
    } else {
      emlrtPushRtStackR2012b(&cd_emlrtRSI, emlrtRootTLSGlobal);
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSA = 'C';
      emlrtPushRtStackR2012b(&hd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      m_t = (ptrdiff_t)(lastv);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&hd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&id_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(lastc);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&id_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&jd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      lda_t = (ptrdiff_t)(ldc);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&jd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&kd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&kd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ld_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incy_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ld_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&md_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&md_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&nd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      beta1_t = (double *)(&beta1);
      emlrtPopRtStackR2012b(&nd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&od_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      yiy0_t = (double *)(&work->data[0]);
      emlrtPopRtStackR2012b(&od_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      Aia0_t = (double *)(&C->data[ic0 - 1]);
      emlrtPopRtStackR2012b(&pd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      xix0_t = (double *)(&C->data[iv0 - 1]);
      emlrtPopRtStackR2012b(&qd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      dgemv(&TRANSA, &m_t, &n_t, alpha1_t, Aia0_t, &lda_t, xix0_t, &incx_t,
            beta1_t, yiy0_t, &incy_t);
      emlrtPopRtStackR2012b(&rd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&cd_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&bd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&me_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ne_emlrtRSI, emlrtRootTLSGlobal);
    alpha1 = -tau;
    emlrtPushRtStackR2012b(&sd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&td_emlrtRSI, emlrtRootTLSGlobal);
    if (lastc < 1) {
    } else {
      emlrtPushRtStackR2012b(&ud_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ae_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      m_t = (ptrdiff_t)(lastv);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ae_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&be_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(lastc);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&be_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ce_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ce_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&de_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incy_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&de_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ee_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      lda_t = (ptrdiff_t)(ldc);
      emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ee_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&fe_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&fe_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ge_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      Aia0_t = (double *)(&C->data[ic0 - 1]);
      emlrtPopRtStackR2012b(&ge_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qe_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      beta1_t = (double *)(&C->data[iv0 - 1]);
      emlrtPopRtStackR2012b(&qe_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&re_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      yiy0_t = (double *)(&work->data[0]);
      emlrtPopRtStackR2012b(&re_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&se_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      dger(&m_t, &n_t, alpha1_t, beta1_t, &incx_t, yiy0_t, &incy_t, Aia0_t,
           &lda_t);
      emlrtPopRtStackR2012b(&se_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ud_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&td_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&sd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ne_emlrtRSI, emlrtRootTLSGlobal);
  }
}

static void c_eml_warning(real_T varargin_2, const char_T varargin_3[14])
{
  const mxArray *y;
  static const int32_T iv43[2] = { 1, 32 };

  const mxArray *m15;
  char_T cv53[32];
  int32_T i;
  static const char_T cv54[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e',
    'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  const mxArray *b_y;
  static const int32_T iv44[2] = { 1, 14 };

  char_T b_varargin_3[14];
  emlrtPushRtStackR2012b(&bh_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_synchGlobalsToML();
  y = NULL;
  m15 = mxCreateCharArray(2, iv43);
  for (i = 0; i < 32; i++) {
    cv53[i] = cv54[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 32, m15, cv53);
  emlrtAssign(&y, m15);
  b_y = NULL;
  m15 = mxCreateCharArray(2, iv44);
  for (i = 0; i < 14; i++) {
    b_varargin_3[i] = varargin_3[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 14, m15, b_varargin_3);
  emlrtAssign(&b_y, m15);
  warning(c_message(y, emlrt_marshallOut(varargin_2), b_y, &k_emlrtMCI),
          &l_emlrtMCI);
  emlrt_synchGlobalsFromML();
  emlrtPopRtStackR2012b(&bh_emlrtRSI, emlrtRootTLSGlobal);
}

static void c_emlrt_marshallIn(const mxArray *d_sprintf, const char_T
  *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(emlrtAlias(d_sprintf), &thisId, y);
  emlrtDestroyArray(&d_sprintf);
}

static const mxArray *c_message(const mxArray *b, const mxArray *c, const
  mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m25;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m25, 3, pArrays,
    "message", TRUE, location);
}

static const mxArray *c_sprintf(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[2];
  const mxArray *m24;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m24, 2, pArrays,
    "sprintf", TRUE, location);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, char_T y[14])
{
  l_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void eml_lusolve(const emxArray_real_T *A, const emxArray_real_T *B,
  emxArray_real_T *X)
{
  emxArray_real_T *b_A;
  int32_T k;
  int32_T iy;
  emxArray_int32_T *ipiv;
  int32_T info;
  int32_T b;
  int32_T j;
  int32_T mmj;
  int32_T c;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  double * xix0_t;
  int32_T ix;
  boolean_T overflow;
  real_T temp;
  boolean_T b_c;
  ptrdiff_t m_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  double * alpha1_t;
  double * Aia0_t;
  double * Aiy0_t;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&b_A, 2, &rb_emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&hm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&jm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&qm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&rm_emlrtRSI, emlrtRootTLSGlobal);
  k = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)b_A, k, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  iy = A->size[0] * A->size[1];
  for (k = 0; k < iy; k++) {
    b_A->data[k] = A->data[k];
  }

  emxInit_int32_T(&ipiv, 2, &rb_emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&sm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&ym_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&an_emlrtRSI, emlrtRootTLSGlobal);
  eml_signed_integer_colon(muIntScalarMin_sint32(A->size[1], A->size[1]), ipiv);
  emlrtPopRtStackR2012b(&an_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ym_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&sm_emlrtRSI, emlrtRootTLSGlobal);
  info = 0;
  if ((A->size[1] < 1) || (A->size[1] < 1)) {
  } else {
    b = muIntScalarMin_sint32(A->size[1] - 1, A->size[1]);
    emlrtPushRtStackR2012b(&tm_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&tm_emlrtRSI, emlrtRootTLSGlobal);
    for (j = 0; j + 1 <= b; j++) {
      mmj = A->size[1] - j;
      c = j * (A->size[1] + 1);
      emlrtPushRtStackR2012b(&um_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&dn_emlrtRSI, emlrtRootTLSGlobal);
      if (mmj < 1) {
        iy = -1;
      } else {
        emlrtPushRtStackR2012b(&fn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&hn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        n_t = (ptrdiff_t)(mmj);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&hn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&in_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        incx_t = (ptrdiff_t)(1);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&in_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&jn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        xix0_t = (double *)(&b_A->data[c]);
        emlrtPopRtStackR2012b(&jn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        emlrtPushRtStackR2012b(&kn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        iy = (int32_T)(idamax(&n_t, xix0_t, &incx_t)) - 1;
        emlrtPopRtStackR2012b(&kn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&fn_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&dn_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&um_emlrtRSI, emlrtRootTLSGlobal);
      if (b_A->data[c + iy] != 0.0) {
        if (iy != 0) {
          ipiv->data[j] = (j + iy) + 1;
          emlrtPushRtStackR2012b(&vm_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&ln_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&mn_emlrtRSI, emlrtRootTLSGlobal);
          ix = j;
          iy += j;
          emlrtPushRtStackR2012b(&nn_emlrtRSI, emlrtRootTLSGlobal);
          if (1 > A->size[1]) {
            overflow = FALSE;
          } else {
            overflow = (A->size[1] > 2147483646);
          }

          if (overflow) {
            emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
            check_forloop_overflow_error();
            emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
          }

          emlrtPopRtStackR2012b(&nn_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k <= A->size[1]; k++) {
            temp = b_A->data[ix];
            b_A->data[ix] = b_A->data[iy];
            b_A->data[iy] = temp;
            ix += A->size[1];
            iy += A->size[1];
          }

          emlrtPopRtStackR2012b(&mn_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ln_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&vm_emlrtRSI, emlrtRootTLSGlobal);
        }

        iy = c + mmj;
        emlrtPushRtStackR2012b(&wm_emlrtRSI, emlrtRootTLSGlobal);
        if (c + 2 > iy) {
          b_c = FALSE;
        } else {
          b_c = (iy > 2147483646);
        }

        if (b_c) {
          emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
          check_forloop_overflow_error();
          emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&wm_emlrtRSI, emlrtRootTLSGlobal);
        for (k = c + 1; k + 1 <= iy; k++) {
          b_A->data[k] /= b_A->data[c];
        }
      } else {
        info = j + 1;
      }

      emlrtPushRtStackR2012b(&xm_emlrtRSI, emlrtRootTLSGlobal);
      k = (A->size[1] - j) - 1;
      emlrtPushRtStackR2012b(&on_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&td_emlrtRSI, emlrtRootTLSGlobal);
      if ((mmj - 1 < 1) || (k < 1)) {
      } else {
        emlrtPushRtStackR2012b(&ud_emlrtRSI, emlrtRootTLSGlobal);
        temp = -1.0;
        emlrtPushRtStackR2012b(&ae_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        m_t = (ptrdiff_t)(mmj - 1);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&ae_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&be_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        n_t = (ptrdiff_t)(k);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&be_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&ce_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        incx_t = (ptrdiff_t)(1);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&ce_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&de_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        incy_t = (ptrdiff_t)(A->size[1]);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&de_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&ee_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        lda_t = (ptrdiff_t)(A->size[1]);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&ee_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&fe_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        alpha1_t = (double *)(&temp);
        emlrtPopRtStackR2012b(&fe_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&ge_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        Aia0_t = (double *)(&b_A->data[(c + A->size[1]) + 1]);
        emlrtPopRtStackR2012b(&ge_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&pn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        xix0_t = (double *)(&b_A->data[c + 1]);
        emlrtPopRtStackR2012b(&pn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&qn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        Aiy0_t = (double *)(&b_A->data[c + A->size[1]]);
        emlrtPopRtStackR2012b(&qn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&rn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        dger(&m_t, &n_t, alpha1_t, xix0_t, &incx_t, Aiy0_t, &incy_t, Aia0_t,
             &lda_t);
        emlrtPopRtStackR2012b(&rn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&ud_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&td_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&on_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&xm_emlrtRSI, emlrtRootTLSGlobal);
    }

    if ((info == 0) && (!(b_A->data[(A->size[1] + b_A->size[0] * (A->size[1] - 1))
                          - 1] != 0.0))) {
      info = A->size[1];
    }
  }

  emlrtPopRtStackR2012b(&rm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&qm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&jm_emlrtRSI, emlrtRootTLSGlobal);
  if (info > 0) {
    emlrtPushRtStackR2012b(&im_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&sn_emlrtRSI, emlrtRootTLSGlobal);
    b_eml_warning();
    emlrtPopRtStackR2012b(&sn_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&im_emlrtRSI, emlrtRootTLSGlobal);
  }

  k = X->size[0] * X->size[1];
  X->size[0] = B->size[0];
  X->size[1] = B->size[1];
  emxEnsureCapacity((emxArray__common *)X, k, (int32_T)sizeof(real_T),
                    &rb_emlrtRTEI);
  iy = B->size[0] * B->size[1];
  for (k = 0; k < iy; k++) {
    X->data[k] = B->data[k];
  }

  emlrtPushRtStackR2012b(&km_emlrtRSI, emlrtRootTLSGlobal);
  if (1 > A->size[1]) {
    overflow = FALSE;
  } else {
    overflow = (A->size[1] > 2147483646);
  }

  if (overflow) {
    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    check_forloop_overflow_error();
    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&km_emlrtRSI, emlrtRootTLSGlobal);
  for (k = 0; k + 1 <= A->size[1]; k++) {
    if (ipiv->data[k] != k + 1) {
      emlrtPushRtStackR2012b(&lm_emlrtRSI, emlrtRootTLSGlobal);
      if (1 > B->size[1]) {
        overflow = FALSE;
      } else {
        overflow = (B->size[1] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&lm_emlrtRSI, emlrtRootTLSGlobal);
      for (j = 0; j + 1 <= B->size[1]; j++) {
        temp = X->data[k + X->size[0] * j];
        X->data[k + X->size[0] * j] = X->data[(ipiv->data[k] + X->size[0] * j) -
          1];
        X->data[(ipiv->data[k] + X->size[0] * j) - 1] = temp;
      }
    }
  }

  emxFree_int32_T(&ipiv);
  emlrtPushRtStackR2012b(&mm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&tn_emlrtRSI, emlrtRootTLSGlobal);
  if ((A->size[1] < 1) || (B->size[1] < 1)) {
  } else {
    emlrtPushRtStackR2012b(&vn_emlrtRSI, emlrtRootTLSGlobal);
    temp = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'L';
    emlrtPushRtStackR2012b(&ao_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    m_t = (ptrdiff_t)(A->size[1]);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ao_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bo_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(B->size[1]);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&bo_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&co_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    lda_t = (ptrdiff_t)(A->size[1]);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&co_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&do_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(A->size[1]);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&do_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&eo_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    Aia0_t = (double *)(&b_A->data[0]);
    emlrtPopRtStackR2012b(&eo_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&fo_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&X->data[0]);
    emlrtPopRtStackR2012b(&fo_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&go_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    alpha1_t = (double *)(&temp);
    emlrtPopRtStackR2012b(&go_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ho_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, alpha1_t, Aia0_t, &lda_t,
          xix0_t, &incx_t);
    emlrtPopRtStackR2012b(&ho_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&vn_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&tn_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&mm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&tn_emlrtRSI, emlrtRootTLSGlobal);
  if ((A->size[1] < 1) || (B->size[1] < 1)) {
  } else {
    emlrtPushRtStackR2012b(&vn_emlrtRSI, emlrtRootTLSGlobal);
    temp = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'L';
    emlrtPushRtStackR2012b(&ao_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    m_t = (ptrdiff_t)(A->size[1]);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ao_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bo_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(B->size[1]);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&bo_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&co_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    lda_t = (ptrdiff_t)(A->size[1]);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&co_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&do_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(A->size[1]);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&do_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&eo_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    Aia0_t = (double *)(&b_A->data[0]);
    emlrtPopRtStackR2012b(&eo_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&fo_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&X->data[0]);
    emlrtPopRtStackR2012b(&fo_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&go_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    alpha1_t = (double *)(&temp);
    emlrtPopRtStackR2012b(&go_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ho_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, alpha1_t, Aia0_t, &lda_t,
          xix0_t, &incx_t);
    emlrtPopRtStackR2012b(&ho_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&vn_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&b_A);
  emlrtPopRtStackR2012b(&tn_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&hm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

static void eml_qrsolve(const emxArray_real_T *A, emxArray_real_T *B,
  emxArray_real_T *Y)
{
  emxArray_real_T *b_A;
  emxArray_real_T *work;
  int32_T nb;
  int32_T mn;
  int32_T ix;
  int32_T iy;
  emxArray_real_T *tau;
  emxArray_int32_T *jpvt;
  int32_T b_mn;
  emxArray_real_T *vn1;
  emxArray_real_T *vn2;
  int32_T k;
  boolean_T overflow;
  boolean_T b8;
  int32_T i;
  int32_T i_i;
  int32_T nmi;
  int32_T mmi;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  double * xix0_t;
  int32_T pvt;
  real_T temp2;
  real_T atmp;
  boolean_T exitg1;
  const mxArray *y;
  static const int32_T iv42[2] = { 1, 8 };

  const mxArray *m14;
  char_T cv51[8];
  static const char_T cv52[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T str[14];
  uint32_T unnamed_idx_0;
  uint32_T unnamed_idx_1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&b_A, 2, &tb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&work, 1, &xb_emlrtRTEI, TRUE);
  nb = B->size[1] - 1;
  mn = (int32_T)muDoubleScalarMin(A->size[0], A->size[1]);
  emlrtPushRtStackR2012b(&ko_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&mo_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&no_emlrtRSI, emlrtRootTLSGlobal);
  ix = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)b_A, ix, (int32_T)sizeof(real_T),
                    &tb_emlrtRTEI);
  iy = A->size[0] * A->size[1];
  for (ix = 0; ix < iy; ix++) {
    b_A->data[ix] = A->data[ix];
  }

  b_emxInit_real_T(&tau, 1, &tb_emlrtRTEI, TRUE);
  emxInit_int32_T(&jpvt, 2, &tb_emlrtRTEI, TRUE);
  b_mn = muIntScalarMin_sint32(A->size[0], A->size[1]);
  ix = tau->size[0];
  tau->size[0] = b_mn;
  emxEnsureCapacity((emxArray__common *)tau, ix, (int32_T)sizeof(real_T),
                    &ub_emlrtRTEI);
  emlrtPushRtStackR2012b(&oo_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&ym_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&an_emlrtRSI, emlrtRootTLSGlobal);
  eml_signed_integer_colon(A->size[1], jpvt);
  emlrtPopRtStackR2012b(&an_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ym_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&oo_emlrtRSI, emlrtRootTLSGlobal);
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
  } else {
    iy = A->size[1];
    ix = work->size[0];
    work->size[0] = iy;
    emxEnsureCapacity((emxArray__common *)work, ix, (int32_T)sizeof(real_T),
                      &tb_emlrtRTEI);
    for (ix = 0; ix < iy; ix++) {
      work->data[ix] = 0.0;
    }

    b_emxInit_real_T(&vn1, 1, &vb_emlrtRTEI, TRUE);
    b_emxInit_real_T(&vn2, 1, &wb_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&po_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&po_emlrtRSI, emlrtRootTLSGlobal);
    iy = A->size[1];
    ix = vn1->size[0];
    vn1->size[0] = iy;
    emxEnsureCapacity((emxArray__common *)vn1, ix, (int32_T)sizeof(real_T),
                      &vb_emlrtRTEI);
    ix = vn2->size[0];
    vn2->size[0] = iy;
    emxEnsureCapacity((emxArray__common *)vn2, ix, (int32_T)sizeof(real_T),
                      &wb_emlrtRTEI);
    k = 1;
    emlrtPushRtStackR2012b(&qo_emlrtRSI, emlrtRootTLSGlobal);
    overflow = (A->size[1] > 2147483646);
    if (overflow) {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&qo_emlrtRSI, emlrtRootTLSGlobal);
    for (iy = 0; iy + 1 <= A->size[1]; iy++) {
      emlrtPushRtStackR2012b(&ro_emlrtRSI, emlrtRootTLSGlobal);
      vn1->data[iy] = eml_xnrm2(A->size[0], A, k);
      emlrtPopRtStackR2012b(&ro_emlrtRSI, emlrtRootTLSGlobal);
      vn2->data[iy] = vn1->data[iy];
      k += A->size[0];
    }

    emlrtPushRtStackR2012b(&so_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > b_mn) {
      b8 = FALSE;
    } else {
      b8 = (b_mn > 2147483646);
    }

    if (b8) {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&so_emlrtRSI, emlrtRootTLSGlobal);
    for (i = 0; i + 1 <= b_mn; i++) {
      i_i = i + i * A->size[0];
      nmi = A->size[1] - i;
      mmi = (A->size[0] - i) - 1;
      emlrtPushRtStackR2012b(&to_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&dn_emlrtRSI, emlrtRootTLSGlobal);
      if (nmi < 1) {
        iy = 0;
      } else {
        emlrtPushRtStackR2012b(&fn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&hn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        n_t = (ptrdiff_t)(nmi);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&hn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&in_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        incx_t = (ptrdiff_t)(1);
        emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&in_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&jn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        xix0_t = (double *)(&vn1->data[i]);
        emlrtPopRtStackR2012b(&jn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        emlrtPushRtStackR2012b(&kn_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_checkEscapedGlobals();
        iy = (int32_T)(idamax(&n_t, xix0_t, &incx_t));
        emlrtPopRtStackR2012b(&kn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&fn_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&dn_emlrtRSI, emlrtRootTLSGlobal);
      pvt = (i + iy) - 1;
      emlrtPopRtStackR2012b(&to_emlrtRSI, emlrtRootTLSGlobal);
      if (pvt + 1 != i + 1) {
        emlrtPushRtStackR2012b(&uo_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&ln_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&mn_emlrtRSI, emlrtRootTLSGlobal);
        ix = A->size[0] * pvt;
        iy = A->size[0] * i;
        emlrtPushRtStackR2012b(&nn_emlrtRSI, emlrtRootTLSGlobal);
        overflow = (A->size[0] > 2147483646);
        if (overflow) {
          emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
          check_forloop_overflow_error();
          emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&nn_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k <= A->size[0]; k++) {
          temp2 = b_A->data[ix];
          b_A->data[ix] = b_A->data[iy];
          b_A->data[iy] = temp2;
          ix++;
          iy++;
        }

        emlrtPopRtStackR2012b(&mn_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&ln_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&uo_emlrtRSI, emlrtRootTLSGlobal);
        iy = jpvt->data[pvt];
        jpvt->data[pvt] = jpvt->data[i];
        jpvt->data[i] = iy;
        vn1->data[pvt] = vn1->data[i];
        vn2->data[pvt] = vn2->data[i];
      }

      if (i + 1 < A->size[0]) {
        emlrtPushRtStackR2012b(&vo_emlrtRSI, emlrtRootTLSGlobal);
        atmp = b_A->data[i_i];
        temp2 = eml_matlab_zlarfg(mmi + 1, &atmp, b_A, i_i + 2);
        emlrtPopRtStackR2012b(&vo_emlrtRSI, emlrtRootTLSGlobal);
        tau->data[i] = temp2;
      } else {
        emlrtPushRtStackR2012b(&wo_emlrtRSI, emlrtRootTLSGlobal);
        temp2 = b_A->data[i_i];
        atmp = b_A->data[i_i];
        emlrtPopRtStackR2012b(&wo_emlrtRSI, emlrtRootTLSGlobal);
        b_A->data[i_i] = temp2;
        tau->data[i] = 0.0;
      }

      b_A->data[i_i] = atmp;
      if (i + 1 < A->size[1]) {
        atmp = b_A->data[i_i];
        b_A->data[i_i] = 1.0;
        emlrtPushRtStackR2012b(&xo_emlrtRSI, emlrtRootTLSGlobal);
        c_eml_matlab_zlarf(mmi + 1, nmi - 1, i_i + 1, tau->data[i], b_A, (i + (i
          + 1) * A->size[0]) + 1, A->size[0], work);
        emlrtPopRtStackR2012b(&xo_emlrtRSI, emlrtRootTLSGlobal);
        b_A->data[i_i] = atmp;
      }

      emlrtPushRtStackR2012b(&yo_emlrtRSI, emlrtRootTLSGlobal);
      if (i + 2 > A->size[1]) {
        overflow = FALSE;
      } else {
        overflow = (A->size[1] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&yo_emlrtRSI, emlrtRootTLSGlobal);
      for (iy = i + 1; iy + 1 <= A->size[1]; iy++) {
        if (vn1->data[iy] != 0.0) {
          atmp = muDoubleScalarAbs(b_A->data[i + b_A->size[0] * iy]) / vn1->
            data[iy];
          temp2 = atmp * atmp;
          atmp = 1.0 - atmp * atmp;
          if (1.0 - temp2 < 0.0) {
            atmp = 0.0;
          }

          temp2 = vn1->data[iy] / vn2->data[iy];
          if (atmp * (temp2 * temp2) <= 1.4901161193847656E-8) {
            if (i + 1 < A->size[0]) {
              emlrtPushRtStackR2012b(&ap_emlrtRSI, emlrtRootTLSGlobal);
              vn1->data[iy] = c_eml_xnrm2(mmi, b_A, (i + A->size[0] * iy) + 2);
              emlrtPopRtStackR2012b(&ap_emlrtRSI, emlrtRootTLSGlobal);
              vn2->data[iy] = vn1->data[iy];
            } else {
              vn1->data[iy] = 0.0;
              vn2->data[iy] = 0.0;
            }
          } else {
            emlrtPushRtStackR2012b(&bp_emlrtRSI, emlrtRootTLSGlobal);
            if (atmp < 0.0) {
              emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
              eml_error();
              emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
            }

            vn1->data[iy] *= muDoubleScalarSqrt(atmp);
            emlrtPopRtStackR2012b(&bp_emlrtRSI, emlrtRootTLSGlobal);
          }
        }
      }
    }

    emxFree_real_T(&vn2);
    emxFree_real_T(&vn1);
  }

  emlrtPopRtStackR2012b(&no_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&mo_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ko_emlrtRSI, emlrtRootTLSGlobal);
  atmp = 0.0;
  if (mn > 0) {
    temp2 = muDoubleScalarMax(A->size[0], A->size[1]) * muDoubleScalarAbs
      (b_A->data[0]) * 2.2204460492503131E-16;
    k = 0;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (k <= mn - 1)) {
      if (muDoubleScalarAbs(b_A->data[k + b_A->size[0] * k]) <= temp2) {
        emlrtPushRtStackR2012b(&lo_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&cp_emlrtRSI, emlrtRootTLSGlobal);
        emlrt_synchGlobalsToML();
        y = NULL;
        m14 = mxCreateCharArray(2, iv42);
        for (i = 0; i < 8; i++) {
          cv51[i] = cv52[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m14, cv51);
        emlrtAssign(&y, m14);
        c_emlrt_marshallIn(c_sprintf(b_sprintf(y, emlrt_marshallOut(14.0),
          emlrt_marshallOut(6.0), &ib_emlrtMCI), emlrt_marshallOut(temp2),
          &jb_emlrtMCI), "sprintf", str);
        emlrt_synchGlobalsFromML();
        emlrtPopRtStackR2012b(&cp_emlrtRSI, emlrtRootTLSGlobal);
        c_eml_warning(atmp, str);
        emlrtPopRtStackR2012b(&lo_emlrtRSI, emlrtRootTLSGlobal);
        exitg1 = TRUE;
      } else {
        atmp++;
        k++;
      }
    }
  }

  unnamed_idx_0 = (uint32_T)A->size[1];
  unnamed_idx_1 = (uint32_T)B->size[1];
  ix = Y->size[0] * Y->size[1];
  Y->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)Y, ix, (int32_T)sizeof(real_T),
                    &tb_emlrtRTEI);
  ix = Y->size[0] * Y->size[1];
  Y->size[1] = (int32_T)unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)Y, ix, (int32_T)sizeof(real_T),
                    &tb_emlrtRTEI);
  iy = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
  for (ix = 0; ix < iy; ix++) {
    Y->data[ix] = 0.0;
  }

  for (iy = 0; iy < mn; iy++) {
    if (tau->data[iy] != 0.0) {
      for (k = 0; k <= nb; k++) {
        temp2 = B->data[iy + B->size[0] * k];
        ix = A->size[0] + (int32_T)(1.0 - ((1.0 + (real_T)iy) + 1.0));
        emlrtForLoopVectorCheckR2012b((1.0 + (real_T)iy) + 1.0, 1.0, A->size[0],
          mxDOUBLE_CLASS, ix, &ic_emlrtRTEI, emlrtRootTLSGlobal);
        for (i = 0; i < ix; i++) {
          unnamed_idx_0 = ((uint32_T)iy + i) + 2U;
          temp2 += b_A->data[((int32_T)unnamed_idx_0 + b_A->size[0] * iy) - 1] *
            B->data[((int32_T)unnamed_idx_0 + B->size[0] * k) - 1];
        }

        temp2 *= tau->data[iy];
        if (temp2 != 0.0) {
          B->data[iy + B->size[0] * k] -= temp2;
          ix = A->size[0] + (int32_T)(1.0 - ((1.0 + (real_T)iy) + 1.0));
          emlrtForLoopVectorCheckR2012b((1.0 + (real_T)iy) + 1.0, 1.0, A->size[0],
            mxDOUBLE_CLASS, ix, &hc_emlrtRTEI, emlrtRootTLSGlobal);
          for (i = 0; i < ix; i++) {
            unnamed_idx_0 = ((uint32_T)iy + i) + 2U;
            B->data[((int32_T)unnamed_idx_0 + B->size[0] * k) - 1] -= b_A->data
              [((int32_T)unnamed_idx_0 + b_A->size[0] * iy) - 1] * temp2;
          }
        }
      }
    }
  }

  emxFree_real_T(&tau);
  for (k = 0; k <= nb; k++) {
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, atmp, mxDOUBLE_CLASS, (int32_T)atmp,
      &gc_emlrtRTEI, emlrtRootTLSGlobal);
    for (i = 0; i < (int32_T)atmp; i++) {
      Y->data[(jpvt->data[(int32_T)(1.0 + (real_T)i) - 1] + Y->size[0] * k) - 1]
        = B->data[((int32_T)(1.0 + (real_T)i) + B->size[0] * k) - 1];
    }

    emlrtForLoopVectorCheckR2012b(atmp, -1.0, 1.0, mxDOUBLE_CLASS, (int32_T)
      -(1.0 + (-1.0 - atmp)), &fc_emlrtRTEI, emlrtRootTLSGlobal);
    for (iy = 0; iy < (int32_T)-(1.0 + (-1.0 - atmp)); iy++) {
      temp2 = atmp + -(real_T)iy;
      Y->data[(jpvt->data[(int32_T)temp2 - 1] + Y->size[0] * k) - 1] /=
        b_A->data[((int32_T)temp2 + b_A->size[0] * ((int32_T)temp2 - 1)) - 1];
      for (i = 0; i < (int32_T)(temp2 - 1.0); i++) {
        Y->data[(jpvt->data[(int32_T)(1.0 + (real_T)i) - 1] + Y->size[0] * k) -
          1] -= Y->data[(jpvt->data[(int32_T)temp2 - 1] + Y->size[0] * k) - 1] *
          b_A->data[((int32_T)(1.0 + (real_T)i) + b_A->size[0] * ((int32_T)temp2
          - 1)) - 1];
      }
    }
  }

  emxFree_int32_T(&jpvt);
  emxFree_real_T(&work);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

static real_T eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
  real_T y;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  double * xix0_t;
  emlrtPushRtStackR2012b(&fc_emlrtRSI, emlrtRootTLSGlobal);
  if (n < 1) {
    y = 0.0;
  } else {
    emlrtPushRtStackR2012b(&hc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&jc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&jc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&lc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&x->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&lc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    y = dnrm2(&n_t, xix0_t, &incx_t);
    emlrtPopRtStackR2012b(&hc_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&fc_emlrtRSI, emlrtRootTLSGlobal);
  return y;
}

static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, char_T ret[14])
{
  int32_T iv48[2];
  int32_T i16;
  for (i16 = 0; i16 < 2; i16++) {
    iv48[i16] = 1 + 13 * i16;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "char", FALSE, 2U,
    iv48);
  emlrtImportCharArray(src, ret, 14);
  emlrtDestroyArray(&src);
}

real_T c_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
  real_T y;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  double * xix0_t;
  emlrtPushRtStackR2012b(&fc_emlrtRSI, emlrtRootTLSGlobal);
  if (n < 1) {
    y = 0.0;
  } else {
    emlrtPushRtStackR2012b(&hc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&jc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&jc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&lc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&x->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&lc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    y = dnrm2(&n_t, xix0_t, &incx_t);
    emlrtPopRtStackR2012b(&hc_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&fc_emlrtRSI, emlrtRootTLSGlobal);
  return y;
}

void eml_error(void)
{
  static char_T cv8[4][1] = { { 's' }, { 'q' }, { 'r' }, { 't' } };

  emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &dc_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, cv8);
  emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
}

real_T eml_matlab_zlarfg(int32_T n, real_T *alpha1, emxArray_real_T *x, int32_T
  ix0)
{
  real_T tau;
  real_T xnorm;
  int32_T knt;
  real_T d2;
  boolean_T b9;
  int32_T k;
  tau = 0.0;
  if (n <= 0) {
  } else {
    emlrtPushRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
    xnorm = eml_xnrm2(n - 1, x, ix0);
    emlrtPopRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
    if (xnorm != 0.0) {
      xnorm = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          emlrtPushRtStackR2012b(&ac_emlrtRSI, emlrtRootTLSGlobal);
          eml_xscal(n - 1, 9.9792015476736E+291, x, ix0);
          emlrtPopRtStackR2012b(&ac_emlrtRSI, emlrtRootTLSGlobal);
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(muDoubleScalarAbs(xnorm) >= 1.0020841800044864E-292));

        emlrtPushRtStackR2012b(&bc_emlrtRSI, emlrtRootTLSGlobal);
        xnorm = eml_xnrm2(n - 1, x, ix0);
        emlrtPopRtStackR2012b(&bc_emlrtRSI, emlrtRootTLSGlobal);
        xnorm = muDoubleScalarHypot(*alpha1, xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        emlrtPushRtStackR2012b(&cc_emlrtRSI, emlrtRootTLSGlobal);
        d2 = 1.0 / (*alpha1 - xnorm);
        eml_xscal(n - 1, d2, x, ix0);
        emlrtPopRtStackR2012b(&cc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&dc_emlrtRSI, emlrtRootTLSGlobal);
        if (1 > knt) {
          b9 = FALSE;
        } else {
          b9 = (knt > 2147483646);
        }

        if (b9) {
          emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
          check_forloop_overflow_error();
          emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&dc_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k <= knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        emlrtPushRtStackR2012b(&ec_emlrtRSI, emlrtRootTLSGlobal);
        d2 = 1.0 / (*alpha1 - xnorm);
        eml_xscal(n - 1, d2, x, ix0);
        emlrtPopRtStackR2012b(&ec_emlrtRSI, emlrtRootTLSGlobal);
        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
{
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  double * xix0_t;
  double * a_t;
  emlrtPushRtStackR2012b(&nc_emlrtRSI, emlrtRootTLSGlobal);
  if (n < 1) {
  } else {
    emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&sc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&sc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&tc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&x->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&tc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&uc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    a_t = (double *)(&a);
    emlrtPopRtStackR2012b(&uc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&vc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    dscal(&n_t, a_t, xix0_t, &incx_t);
    emlrtPopRtStackR2012b(&vc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&nc_emlrtRSI, emlrtRootTLSGlobal);
}

int32_T ilazlc(int32_T m, int32_T n, const emxArray_real_T *A, int32_T ia0,
               int32_T lda)
{
  int32_T j;
  boolean_T exitg2;
  int32_T coltop;
  int32_T colbottom;
  boolean_T b_coltop;
  int32_T exitg1;
  j = n;
  exitg2 = FALSE;
  while ((exitg2 == FALSE) && (j > 0)) {
    coltop = ia0 + (j - 1) * lda;
    colbottom = (coltop + m) - 1;
    emlrtPushRtStackR2012b(&ke_emlrtRSI, emlrtRootTLSGlobal);
    if (coltop > colbottom) {
      b_coltop = FALSE;
    } else {
      b_coltop = (colbottom > 2147483646);
    }

    if (b_coltop) {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&ke_emlrtRSI, emlrtRootTLSGlobal);
    do {
      exitg1 = 0;
      if (coltop <= colbottom) {
        if (A->data[coltop - 1] != 0.0) {
          exitg1 = 1;
        } else {
          coltop++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = TRUE;
    }
  }

  return j;
}

void mldivide(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *Y)
{
  const mxArray *y;
  static const int32_T iv40[2] = { 1, 21 };

  const mxArray *m12;
  char_T cv47[21];
  int32_T i;
  static const char_T cv48[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'd', 'i', 'm', 'a', 'g', 'r', 'e', 'e' };

  emxArray_real_T *b_B;
  uint32_T unnamed_idx_0;
  uint32_T unnamed_idx_1;
  int32_T loop_ub;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  if (B->size[0] == A->size[0]) {
  } else {
    emlrtPushRtStackR2012b(&gm_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    y = NULL;
    m12 = mxCreateCharArray(2, iv40);
    for (i = 0; i < 21; i++) {
      cv47[i] = cv48[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m12, cv47);
    emlrtAssign(&y, m12);
    error(message(y, &hb_emlrtMCI), &hb_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&gm_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxInit_real_T(&b_B, 2, &qb_emlrtRTEI, TRUE);
  if ((A->size[0] == 0) || (A->size[1] == 0) || ((B->size[0] == 0) || (B->size[1]
        == 0))) {
    unnamed_idx_0 = (uint32_T)A->size[1];
    unnamed_idx_1 = (uint32_T)B->size[1];
    i = Y->size[0] * Y->size[1];
    Y->size[0] = (int32_T)unnamed_idx_0;
    emxEnsureCapacity((emxArray__common *)Y, i, (int32_T)sizeof(real_T),
                      &qb_emlrtRTEI);
    i = Y->size[0] * Y->size[1];
    Y->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity((emxArray__common *)Y, i, (int32_T)sizeof(real_T),
                      &qb_emlrtRTEI);
    loop_ub = (int32_T)unnamed_idx_0 * (int32_T)unnamed_idx_1;
    for (i = 0; i < loop_ub; i++) {
      Y->data[i] = 0.0;
    }
  } else if (A->size[0] == A->size[1]) {
    emlrtPushRtStackR2012b(&gm_emlrtRSI, emlrtRootTLSGlobal);
    eml_lusolve(A, B, Y);
    emlrtPopRtStackR2012b(&gm_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    emlrtPushRtStackR2012b(&gm_emlrtRSI, emlrtRootTLSGlobal);
    i = b_B->size[0] * b_B->size[1];
    b_B->size[0] = B->size[0];
    b_B->size[1] = B->size[1];
    emxEnsureCapacity((emxArray__common *)b_B, i, (int32_T)sizeof(real_T),
                      &qb_emlrtRTEI);
    loop_ub = B->size[0] * B->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_B->data[i] = B->data[i];
    }

    eml_qrsolve(A, b_B, Y);
    emlrtPopRtStackR2012b(&gm_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&b_B);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (mldivide.c) */