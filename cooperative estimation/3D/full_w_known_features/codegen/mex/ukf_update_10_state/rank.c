/*
 * rank.c
 *
 * Code generation for function 'rank'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "rank.h"
#include "ukf_update_10_state_emxutil.h"
#include "minangle.h"
#include "ukf_update_10_state_mexutil.h"
#include "mldivide.h"
#include "sqrt.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo pj_emlrtRSI = { 15, "rank",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/rank.m"
};

static emlrtRSInfo qj_emlrtRSI = { 12, "svd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/svd.m"
};

static emlrtRSInfo rj_emlrtRSI = { 14, "svd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/svd.m"
};

static emlrtRSInfo sj_emlrtRSI = { 34, "svd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/svd.m"
};

static emlrtRSInfo tj_emlrtRSI = { 19, "eml_xgesvd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"
};

static emlrtRSInfo uj_emlrtRSI = { 9, "eml_lapack_xgesvd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"
};

static emlrtRSInfo vj_emlrtRSI = { 61, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo wj_emlrtRSI = { 71, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo xj_emlrtRSI = { 75, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo yj_emlrtRSI = { 82, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo ak_emlrtRSI = { 87, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo bk_emlrtRSI = { 90, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo ck_emlrtRSI = { 107, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo dk_emlrtRSI = { 113, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo ek_emlrtRSI = { 123, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo fk_emlrtRSI = { 126, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo gk_emlrtRSI = { 129, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo hk_emlrtRSI = { 131, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo ik_emlrtRSI = { 135, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo jk_emlrtRSI = { 221, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo kk_emlrtRSI = { 255, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo lk_emlrtRSI = { 261, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo mk_emlrtRSI = { 291, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo nk_emlrtRSI = { 371, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo ok_emlrtRSI = { 380, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo pk_emlrtRSI = { 383, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo qk_emlrtRSI = { 396, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo rk_emlrtRSI = { 343, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo sk_emlrtRSI = { 345, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo tk_emlrtRSI = { 324, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo uk_emlrtRSI = { 326, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo vk_emlrtRSI = { 448, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo wk_emlrtRSI = { 31, "eml_xdotc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"
};

static emlrtRSInfo xk_emlrtRSI = { 28, "eml_xdot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"
};

static emlrtRSInfo al_emlrtRSI = { 28, "eml_blas_xdot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

static emlrtRSInfo dl_emlrtRSI = { 64, "eml_blas_xdot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

static emlrtRSInfo el_emlrtRSI = { 65, "eml_blas_xdot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

static emlrtRSInfo fl_emlrtRSI = { 66, "eml_blas_xdot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

static emlrtRSInfo gl_emlrtRSI = { 70, "eml_blas_xdot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

static emlrtRSInfo hl_emlrtRSI = { 73, "eml_blas_xdot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

static emlrtRSInfo il_emlrtRSI = { 42, "eml_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"
};

static emlrtRSInfo jl_emlrtRSI = { 25, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo kl_emlrtRSI = { 68, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo ll_emlrtRSI = { 69, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo ml_emlrtRSI = { 70, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo nl_emlrtRSI = { 74, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo ol_emlrtRSI = { 77, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo pl_emlrtRSI = { 83, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo ql_emlrtRSI = { 85, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo rl_emlrtRSI = { 89, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo sl_emlrtRSI = { 91, "eml_blas_xaxpy",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo tl_emlrtRSI = { 18, "eml_xrotg",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"
};

static emlrtRSInfo vl_emlrtRSI = { 13, "eml_blas_xrotg",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo xl_emlrtRSI = { 47, "eml_blas_xrotg",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo yl_emlrtRSI = { 50, "eml_blas_xrotg",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo am_emlrtRSI = { 53, "eml_blas_xrotg",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo bm_emlrtRSI = { 56, "eml_blas_xrotg",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRSInfo cm_emlrtRSI = { 59, "eml_blas_xrotg",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m"
};

static emlrtRTEInfo ib_emlrtRTEI = { 1, 14, "rank",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/rank.m"
};

static emlrtRTEInfo jb_emlrtRTEI = { 1, 20, "eml_xgesvd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"
};

static emlrtRTEInfo kb_emlrtRTEI = { 447, 1, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRTEInfo lb_emlrtRTEI = { 32, 1, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRTEInfo mb_emlrtRTEI = { 33, 1, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRTEInfo nb_emlrtRTEI = { 34, 1, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

/* Function Declarations */
static void b_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, emxArray_real_T *y, int32_T iy0);
static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
static void c_eml_error(void);
static void c_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, emxArray_real_T *y, int32_T iy0);
static void d_eml_error(void);
static real_T d_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static real_T eml_div(real_T x, real_T y);
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
                      int32_T iy0);
static real_T eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const
  emxArray_real_T *y, int32_T iy0);
static void eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *S);
static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);

/* Function Definitions */
static void b_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, emxArray_real_T *y, int32_T iy0)
{
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * a_t;
  double * yiy0_t;
  double * xix0_t;
  emlrtPushRtStackR2012b(&il_emlrtRSI, emlrtRootTLSGlobal);
  if (n < 1) {
  } else {
    emlrtPushRtStackR2012b(&jl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&kl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ll_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ll_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ml_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incy_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ml_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&nl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    a_t = (double *)(&a);
    emlrtPopRtStackR2012b(&nl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ol_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    yiy0_t = (double *)(&y->data[iy0 - 1]);
    emlrtPopRtStackR2012b(&ol_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&rl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&x->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&rl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&sl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    daxpy(&n_t, a_t, xix0_t, &incx_t, yiy0_t, &incy_t);
    emlrtPopRtStackR2012b(&sl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&jl_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&il_emlrtRSI, emlrtRootTLSGlobal);
}

static void b_eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0)
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

static void c_eml_error(void)
{
  emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &dc_emlrtRTEI,
    "Coder:MATLAB:svd_matrixWithNaNInf", 0);
  emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
}

static void c_eml_xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T
  ix0, emxArray_real_T *y, int32_T iy0)
{
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * a_t;
  double * yiy0_t;
  double * xix0_t;
  emlrtPushRtStackR2012b(&il_emlrtRSI, emlrtRootTLSGlobal);
  if (n < 1) {
  } else {
    emlrtPushRtStackR2012b(&jl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&kl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ll_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ll_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ml_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incy_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ml_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&nl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    a_t = (double *)(&a);
    emlrtPopRtStackR2012b(&nl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ol_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    yiy0_t = (double *)(&y->data[iy0 - 1]);
    emlrtPopRtStackR2012b(&ol_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&rl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&x->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&rl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&sl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    daxpy(&n_t, a_t, xix0_t, &incx_t, yiy0_t, &incy_t);
    emlrtPopRtStackR2012b(&sl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&jl_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&il_emlrtRSI, emlrtRootTLSGlobal);
}

static void d_eml_error(void)
{
  emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &dc_emlrtRTEI,
    "Coder:MATLAB:svd_NoConvergence", 0);
  emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
}

static real_T d_eml_xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
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

static real_T eml_div(real_T x, real_T y)
{
  return x / y;
}

static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, emxArray_real_T *y,
                      int32_T iy0)
{
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * a_t;
  double * yiy0_t;
  double * yix0_t;
  emlrtPushRtStackR2012b(&il_emlrtRSI, emlrtRootTLSGlobal);
  if (n < 1) {
  } else {
    emlrtPushRtStackR2012b(&jl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&kl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ll_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ll_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ml_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incy_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&ml_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&nl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    a_t = (double *)(&a);
    emlrtPopRtStackR2012b(&nl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ol_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    yiy0_t = (double *)(&y->data[iy0 - 1]);
    emlrtPopRtStackR2012b(&ol_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    yix0_t = (double *)(&y->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&pl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ql_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    daxpy(&n_t, a_t, yix0_t, &incx_t, yiy0_t, &incy_t);
    emlrtPopRtStackR2012b(&ql_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&jl_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&il_emlrtRSI, emlrtRootTLSGlobal);
}

static real_T eml_xdotc(int32_T n, const emxArray_real_T *x, int32_T ix0, const
  emxArray_real_T *y, int32_T iy0)
{
  real_T d;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * xix0_t;
  double * yiy0_t;
  emlrtPushRtStackR2012b(&wk_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&xk_emlrtRSI, emlrtRootTLSGlobal);
  if (n < 1) {
    d = 0.0;
  } else {
    emlrtPushRtStackR2012b(&al_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&dl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&dl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&el_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&el_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&fl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incy_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&fl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&gl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&x->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&gl_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&hl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    yiy0_t = (double *)(&y->data[iy0 - 1]);
    emlrtPopRtStackR2012b(&hl_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    d = ddot(&n_t, xix0_t, &incx_t, yiy0_t, &incy_t);
    emlrtPopRtStackR2012b(&al_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&xk_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&wk_emlrtRSI, emlrtRootTLSGlobal);
  return d;
}

static void eml_xgesvd(const emxArray_real_T *A, emxArray_real_T *S)
{
  emxArray_real_T *b_A;
  emxArray_real_T *e;
  emxArray_real_T *work;
  int32_T qs;
  int32_T kase;
  emxArray_real_T *s;
  int32_T minnp;
  int32_T nrt;
  int32_T nct;
  int32_T mm;
  int32_T q;
  int32_T m;
  real_T ztest0;
  boolean_T overflow;
  int32_T iter;
  boolean_T b4;
  real_T ztest;
  real_T tiny;
  real_T snorm;
  boolean_T exitg1;
  boolean_T exitg4;
  boolean_T exitg3;
  real_T sn;
  real_T sm;
  real_T varargin_1[5];
  boolean_T exitg2;
  real_T sqds;
  real_T b;
  boolean_T b5;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&b_A, 2, &jb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&e, 1, &mb_emlrtRTEI, TRUE);
  b_emxInit_real_T(&work, 1, &nb_emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&tj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&uj_emlrtRSI, emlrtRootTLSGlobal);
  qs = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)b_A, qs, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  kase = A->size[0] * A->size[1];
  for (qs = 0; qs < kase; qs++) {
    b_A->data[qs] = A->data[qs];
  }

  b_emxInit_real_T(&s, 1, &lb_emlrtRTEI, TRUE);
  minnp = muIntScalarMin_sint32(A->size[0], A->size[1]);
  kase = muIntScalarMin_sint32(A->size[0] + 1, A->size[1]);
  qs = s->size[0];
  s->size[0] = kase;
  emxEnsureCapacity((emxArray__common *)s, qs, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  for (qs = 0; qs < kase; qs++) {
    s->data[qs] = 0.0;
  }

  kase = A->size[1];
  qs = e->size[0];
  e->size[0] = kase;
  emxEnsureCapacity((emxArray__common *)e, qs, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  for (qs = 0; qs < kase; qs++) {
    e->data[qs] = 0.0;
  }

  kase = A->size[0];
  qs = work->size[0];
  work->size[0] = kase;
  emxEnsureCapacity((emxArray__common *)work, qs, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  for (qs = 0; qs < kase; qs++) {
    work->data[qs] = 0.0;
  }

  if ((A->size[0] == 0) || (A->size[1] == 0)) {
  } else {
    if (A->size[1] < 2) {
      kase = 2;
    } else {
      kase = A->size[1];
    }

    nrt = muIntScalarMin_sint32(kase - 2, A->size[0]);
    kase = A->size[0];
    nct = muIntScalarMin_sint32(kase - 1, A->size[1]);
    mm = muIntScalarMax_sint32(nct, nrt);
    emlrtPushRtStackR2012b(&vj_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&vj_emlrtRSI, emlrtRootTLSGlobal);
    for (q = 0; q + 1 <= mm; q++) {
      kase = q + A->size[0] * q;
      m = A->size[0] - q;
      if (q + 1 <= nct) {
        emlrtPushRtStackR2012b(&wj_emlrtRSI, emlrtRootTLSGlobal);
        ztest0 = c_eml_xnrm2(m, b_A, kase + 1);
        emlrtPopRtStackR2012b(&wj_emlrtRSI, emlrtRootTLSGlobal);
        if (ztest0 > 0.0) {
          if (b_A->data[kase] < 0.0) {
            ztest0 = -ztest0;
          }

          s->data[q] = ztest0;
          emlrtPushRtStackR2012b(&xj_emlrtRSI, emlrtRootTLSGlobal);
          ztest0 = eml_div(1.0, s->data[q]);
          eml_xscal(m, ztest0, b_A, kase + 1);
          emlrtPopRtStackR2012b(&xj_emlrtRSI, emlrtRootTLSGlobal);
          b_A->data[kase]++;
          s->data[q] = -s->data[q];
        } else {
          s->data[q] = 0.0;
        }
      }

      emlrtPushRtStackR2012b(&yj_emlrtRSI, emlrtRootTLSGlobal);
      if (q + 2 > A->size[1]) {
        overflow = FALSE;
      } else {
        overflow = (A->size[1] > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&yj_emlrtRSI, emlrtRootTLSGlobal);
      for (qs = q + 1; qs + 1 <= A->size[1]; qs++) {
        iter = q + A->size[0] * qs;
        if ((q + 1 <= nct) && (s->data[q] != 0.0)) {
          emlrtPushRtStackR2012b(&ak_emlrtRSI, emlrtRootTLSGlobal);
          ztest0 = eml_xdotc(m, b_A, kase + 1, b_A, iter + 1);
          emlrtPopRtStackR2012b(&ak_emlrtRSI, emlrtRootTLSGlobal);
          ztest0 = -eml_div(ztest0, b_A->data[q + b_A->size[0] * q]);
          emlrtPushRtStackR2012b(&bk_emlrtRSI, emlrtRootTLSGlobal);
          eml_xaxpy(m, ztest0, kase + 1, b_A, iter + 1);
          emlrtPopRtStackR2012b(&bk_emlrtRSI, emlrtRootTLSGlobal);
        }

        e->data[qs] = b_A->data[iter];
      }

      if (q + 1 <= nrt) {
        kase = (A->size[1] - q) - 1;
        emlrtPushRtStackR2012b(&ck_emlrtRSI, emlrtRootTLSGlobal);
        ztest0 = d_eml_xnrm2(kase, e, q + 2);
        emlrtPopRtStackR2012b(&ck_emlrtRSI, emlrtRootTLSGlobal);
        if (ztest0 == 0.0) {
          e->data[q] = 0.0;
        } else {
          if (e->data[q + 1] < 0.0) {
            ztest0 = -ztest0;
          }

          e->data[q] = ztest0;
          emlrtPushRtStackR2012b(&dk_emlrtRSI, emlrtRootTLSGlobal);
          ztest0 = eml_div(1.0, e->data[q]);
          b_eml_xscal(kase, ztest0, e, q + 2);
          emlrtPopRtStackR2012b(&dk_emlrtRSI, emlrtRootTLSGlobal);
          e->data[q + 1]++;
        }

        e->data[q] = -e->data[q];
        if ((q + 2 <= A->size[0]) && (e->data[q] != 0.0)) {
          emlrtPushRtStackR2012b(&ek_emlrtRSI, emlrtRootTLSGlobal);
          if (q + 2 > A->size[0]) {
            overflow = FALSE;
          } else {
            overflow = (A->size[0] > 2147483646);
          }

          if (overflow) {
            emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
            check_forloop_overflow_error();
            emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
          }

          emlrtPopRtStackR2012b(&ek_emlrtRSI, emlrtRootTLSGlobal);
          for (kase = q + 1; kase + 1 <= A->size[0]; kase++) {
            work->data[kase] = 0.0;
          }

          emlrtPushRtStackR2012b(&fk_emlrtRSI, emlrtRootTLSGlobal);
          if (q + 2 > A->size[1]) {
            overflow = FALSE;
          } else {
            overflow = (A->size[1] > 2147483646);
          }

          if (overflow) {
            emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
            check_forloop_overflow_error();
            emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
          }

          emlrtPopRtStackR2012b(&fk_emlrtRSI, emlrtRootTLSGlobal);
          for (qs = q + 1; qs + 1 <= A->size[1]; qs++) {
            emlrtPushRtStackR2012b(&gk_emlrtRSI, emlrtRootTLSGlobal);
            b_eml_xaxpy(m - 1, e->data[qs], b_A, (q + A->size[0] * qs) + 2, work,
                        q + 2);
            emlrtPopRtStackR2012b(&gk_emlrtRSI, emlrtRootTLSGlobal);
          }

          emlrtPushRtStackR2012b(&hk_emlrtRSI, emlrtRootTLSGlobal);
          if (q + 2 > A->size[1]) {
            overflow = FALSE;
          } else {
            overflow = (A->size[1] > 2147483646);
          }

          if (overflow) {
            emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
            check_forloop_overflow_error();
            emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
          }

          emlrtPopRtStackR2012b(&hk_emlrtRSI, emlrtRootTLSGlobal);
          for (qs = q + 1; qs + 1 <= A->size[1]; qs++) {
            emlrtPushRtStackR2012b(&ik_emlrtRSI, emlrtRootTLSGlobal);
            ztest0 = eml_div(-e->data[qs], e->data[q + 1]);
            c_eml_xaxpy(m - 1, ztest0, work, q + 2, b_A, (q + A->size[0] * qs) +
                        2);
            emlrtPopRtStackR2012b(&ik_emlrtRSI, emlrtRootTLSGlobal);
          }
        }
      }
    }

    m = muIntScalarMin_sint32(A->size[1], A->size[0] + 1);
    if (nct < A->size[1]) {
      s->data[nct] = b_A->data[nct + b_A->size[0] * nct];
    }

    if (A->size[0] < m) {
      s->data[m - 1] = 0.0;
    }

    if (nrt + 1 < m) {
      e->data[nrt] = b_A->data[nrt + b_A->size[0] * (m - 1)];
    }

    e->data[m - 1] = 0.0;
    emlrtPushRtStackR2012b(&jk_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > m) {
      b4 = FALSE;
    } else {
      b4 = (m > 2147483646);
    }

    if (b4) {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&jk_emlrtRSI, emlrtRootTLSGlobal);
    for (q = 0; q + 1 <= m; q++) {
      if (s->data[q] != 0.0) {
        ztest = muDoubleScalarAbs(s->data[q]);
        ztest0 = eml_div(s->data[q], ztest);
        s->data[q] = ztest;
        if (q + 1 < m) {
          e->data[q] = eml_div(e->data[q], ztest0);
        }
      }

      if ((q + 1 < m) && (e->data[q] != 0.0)) {
        ztest = muDoubleScalarAbs(e->data[q]);
        ztest0 = eml_div(ztest, e->data[q]);
        e->data[q] = ztest;
        s->data[q + 1] *= ztest0;
      }
    }

    mm = m;
    iter = 0;
    tiny = eml_div(2.2250738585072014E-308, 2.2204460492503131E-16);
    snorm = 0.0;
    emlrtPushRtStackR2012b(&kk_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kk_emlrtRSI, emlrtRootTLSGlobal);
    for (kase = 0; kase + 1 <= m; kase++) {
      snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs
        (s->data[kase]), muDoubleScalarAbs(e->data[kase])));
    }

    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (m > 0)) {
      if (iter >= 75) {
        emlrtPushRtStackR2012b(&lk_emlrtRSI, emlrtRootTLSGlobal);
        d_eml_error();
        emlrtPopRtStackR2012b(&lk_emlrtRSI, emlrtRootTLSGlobal);
        exitg1 = TRUE;
      } else {
        q = m - 1;
        exitg4 = FALSE;
        while (!((exitg4 == TRUE) || (q == 0))) {
          ztest0 = muDoubleScalarAbs(e->data[q - 1]);
          if ((ztest0 <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s->data[q -
                 1]) + muDoubleScalarAbs(s->data[q]))) || (ztest0 <= tiny) ||
              ((iter > 20) && (ztest0 <= 2.2204460492503131E-16 * snorm))) {
            e->data[q - 1] = 0.0;
            exitg4 = TRUE;
          } else {
            q--;
          }
        }

        if (q == m - 1) {
          kase = 4;
        } else {
          qs = m;
          emlrtPushRtStackR2012b(&mk_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&mk_emlrtRSI, emlrtRootTLSGlobal);
          kase = m;
          exitg3 = FALSE;
          while ((exitg3 == FALSE) && (kase >= q)) {
            qs = kase;
            if (kase == q) {
              exitg3 = TRUE;
            } else {
              ztest0 = 0.0;
              if (kase < m) {
                ztest0 = muDoubleScalarAbs(e->data[kase - 1]);
              }

              if (kase > q + 1) {
                ztest0 += muDoubleScalarAbs(e->data[kase - 2]);
              }

              ztest = muDoubleScalarAbs(s->data[kase - 1]);
              if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <= tiny))
              {
                s->data[kase - 1] = 0.0;
                exitg3 = TRUE;
              } else {
                kase--;
              }
            }
          }

          if (qs == q) {
            kase = 3;
          } else if (qs == m) {
            kase = 1;
          } else {
            kase = 2;
            q = qs;
          }
        }

        switch (kase) {
         case 1:
          ztest = e->data[m - 2];
          e->data[m - 2] = 0.0;
          emlrtPushRtStackR2012b(&tk_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&tk_emlrtRSI, emlrtRootTLSGlobal);
          for (qs = m - 3; qs + 2 >= q + 1; qs--) {
            emlrtPushRtStackR2012b(&uk_emlrtRSI, emlrtRootTLSGlobal);
            ztest0 = s->data[qs + 1];
            eml_xrotg(&ztest0, &ztest, &sm, &sn);
            emlrtPopRtStackR2012b(&uk_emlrtRSI, emlrtRootTLSGlobal);
            s->data[qs + 1] = ztest0;
            if (qs + 2 > q + 1) {
              ztest = -sn * e->data[qs];
              e->data[qs] *= sm;
            }
          }
          break;

         case 2:
          ztest = e->data[q - 1];
          e->data[q - 1] = 0.0;
          emlrtPushRtStackR2012b(&rk_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&rk_emlrtRSI, emlrtRootTLSGlobal);
          while (q + 1 <= m) {
            emlrtPushRtStackR2012b(&sk_emlrtRSI, emlrtRootTLSGlobal);
            ztest0 = s->data[q];
            eml_xrotg(&ztest0, &ztest, &sm, &sn);
            emlrtPopRtStackR2012b(&sk_emlrtRSI, emlrtRootTLSGlobal);
            s->data[q] = ztest0;
            ztest = -sn * e->data[q];
            e->data[q] *= sm;
            q++;
          }
          break;

         case 3:
          varargin_1[0] = muDoubleScalarAbs(s->data[m - 1]);
          varargin_1[1] = muDoubleScalarAbs(s->data[m - 2]);
          varargin_1[2] = muDoubleScalarAbs(e->data[m - 2]);
          varargin_1[3] = muDoubleScalarAbs(s->data[q]);
          varargin_1[4] = muDoubleScalarAbs(e->data[q]);
          qs = 1;
          sn = varargin_1[0];
          if (muDoubleScalarIsNaN(varargin_1[0])) {
            kase = 2;
            exitg2 = FALSE;
            while ((exitg2 == FALSE) && (kase < 6)) {
              qs = kase;
              if (!muDoubleScalarIsNaN(varargin_1[kase - 1])) {
                sn = varargin_1[kase - 1];
                exitg2 = TRUE;
              } else {
                kase++;
              }
            }
          }

          if (qs < 5) {
            while (qs + 1 < 6) {
              if (varargin_1[qs] > sn) {
                sn = varargin_1[qs];
              }

              qs++;
            }
          }

          sm = eml_div(s->data[m - 1], sn);
          ztest0 = eml_div(s->data[m - 2], sn);
          ztest = eml_div(e->data[m - 2], sn);
          sqds = eml_div(s->data[q], sn);
          b = eml_div((ztest0 + sm) * (ztest0 - sm) + ztest * ztest, 2.0);
          ztest0 = sm * ztest;
          ztest0 *= ztest0;
          ztest = 0.0;
          if ((b != 0.0) || (ztest0 != 0.0)) {
            emlrtPushRtStackR2012b(&nk_emlrtRSI, emlrtRootTLSGlobal);
            ztest = b * b + ztest0;
            b_sqrt(&ztest);
            emlrtPopRtStackR2012b(&nk_emlrtRSI, emlrtRootTLSGlobal);
            if (b < 0.0) {
              ztest = -ztest;
            }

            ztest = eml_div(ztest0, b + ztest);
          }

          ztest += (sqds + sm) * (sqds - sm);
          ztest0 = sqds * eml_div(e->data[q], sn);
          emlrtPushRtStackR2012b(&ok_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&ok_emlrtRSI, emlrtRootTLSGlobal);
          for (qs = q + 1; qs < m; qs++) {
            emlrtPushRtStackR2012b(&pk_emlrtRSI, emlrtRootTLSGlobal);
            eml_xrotg(&ztest, &ztest0, &sm, &sn);
            emlrtPopRtStackR2012b(&pk_emlrtRSI, emlrtRootTLSGlobal);
            if (qs > q + 1) {
              e->data[qs - 2] = ztest;
            }

            ztest0 = sm * s->data[qs - 1];
            ztest = sn * e->data[qs - 1];
            e->data[qs - 1] = sm * e->data[qs - 1] - sn * s->data[qs - 1];
            b = s->data[qs];
            s->data[qs] *= sm;
            emlrtPushRtStackR2012b(&qk_emlrtRSI, emlrtRootTLSGlobal);
            ztest += ztest0;
            ztest0 = sn * b;
            eml_xrotg(&ztest, &ztest0, &sm, &sn);
            emlrtPopRtStackR2012b(&qk_emlrtRSI, emlrtRootTLSGlobal);
            s->data[qs - 1] = ztest;
            ztest = sm * e->data[qs - 1] + sn * s->data[qs];
            s->data[qs] = -sn * e->data[qs - 1] + sm * s->data[qs];
            ztest0 = sn * e->data[qs];
            e->data[qs] *= sm;
          }

          e->data[m - 2] = ztest;
          iter++;
          break;

         default:
          if (s->data[q] < 0.0) {
            s->data[q] = -s->data[q];
          }

          kase = q + 1;
          while ((q + 1 < mm) && (s->data[q] < s->data[kase])) {
            ztest = s->data[q];
            s->data[q] = s->data[kase];
            s->data[kase] = ztest;
            q = kase;
            kase++;
          }

          iter = 0;
          m--;
          break;
        }
      }
    }
  }

  qs = S->size[0];
  S->size[0] = minnp;
  emxEnsureCapacity((emxArray__common *)S, qs, (int32_T)sizeof(real_T),
                    &kb_emlrtRTEI);
  emlrtPushRtStackR2012b(&vk_emlrtRSI, emlrtRootTLSGlobal);
  if (1 > minnp) {
    b5 = FALSE;
  } else {
    b5 = (minnp > 2147483646);
  }

  if (b5) {
    emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    check_forloop_overflow_error();
    emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&vk_emlrtRSI, emlrtRootTLSGlobal);
  for (qs = 0; qs + 1 <= minnp; qs++) {
    S->data[qs] = s->data[qs];
  }

  emxFree_real_T(&s);
  emlrtPopRtStackR2012b(&uj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&tj_emlrtRSI, emlrtRootTLSGlobal);
  emxFree_real_T(&work);
  emxFree_real_T(&e);
  emxFree_real_T(&b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

static void eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T b_b;
  real_T b_a;
  double * a_t;
  double * b_t;
  double * c_t;
  double * s_t;
  emlrtPushRtStackR2012b(&tl_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&vl_emlrtRSI, emlrtRootTLSGlobal);
  b_b = *b;
  b_a = *a;
  *c = 0.0;
  *s = 0.0;
  emlrtPushRtStackR2012b(&xl_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_checkEscapedGlobals();
  a_t = (double *)(&b_a);
  emlrtPopRtStackR2012b(&xl_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&yl_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_checkEscapedGlobals();
  b_t = (double *)(&b_b);
  emlrtPopRtStackR2012b(&yl_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&am_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_checkEscapedGlobals();
  c_t = (double *)(c);
  emlrtPopRtStackR2012b(&am_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&bm_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_checkEscapedGlobals();
  s_t = (double *)(s);
  emlrtPopRtStackR2012b(&bm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&cm_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_checkEscapedGlobals();
  drotg(a_t, b_t, c_t, s_t);
  emlrtPopRtStackR2012b(&cm_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&vl_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&tl_emlrtRSI, emlrtRootTLSGlobal);
  *a = b_a;
  *b = b_b;
}

real_T rank(const emxArray_real_T *A)
{
  real_T r;
  int32_T b;
  boolean_T b3;
  int32_T k;
  emxArray_real_T *U;
  real_T absxk;
  int32_T exponent;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  r = 0.0;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
  } else {
    emlrtPushRtStackR2012b(&pj_emlrtRSI, emlrtRootTLSGlobal);
    b = A->size[0] * A->size[1];
    emlrtPushRtStackR2012b(&qj_emlrtRSI, emlrtRootTLSGlobal);
    if (1 > b) {
      b3 = FALSE;
    } else {
      b3 = (b > 2147483646);
    }

    if (b3) {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      check_forloop_overflow_error();
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&qj_emlrtRSI, emlrtRootTLSGlobal);
    for (k = 0; k + 1 <= b; k++) {
      if (!((!muDoubleScalarIsInf(A->data[k])) && (!muDoubleScalarIsNaN(A->
             data[k])))) {
        emlrtPushRtStackR2012b(&rj_emlrtRSI, emlrtRootTLSGlobal);
        c_eml_error();
        emlrtPopRtStackR2012b(&rj_emlrtRSI, emlrtRootTLSGlobal);
      }
    }

    b_emxInit_real_T(&U, 1, &ib_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&sj_emlrtRSI, emlrtRootTLSGlobal);
    eml_xgesvd(A, U);
    emlrtPopRtStackR2012b(&sj_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&pj_emlrtRSI, emlrtRootTLSGlobal);
    if (A->size[0] > A->size[1]) {
      b = A->size[0];
    } else {
      b = A->size[1];
    }

    absxk = muDoubleScalarAbs(U->data[0]);
    if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    k = 0;
    while ((k <= U->size[0] - 1) && (U->data[(int32_T)(1.0 + (real_T)k) - 1] >
            (real_T)b * absxk)) {
      r++;
      k++;
    }

    emxFree_real_T(&U);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return r;
}

/* End of code generation (rank.c) */
