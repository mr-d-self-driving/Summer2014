/*
 * schur.c
 *
 * Code generation for function 'schur'
 *
 * C source code generated on: Tue Dec  9 10:58:58 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "schur.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "ukf_update_unknown_state_mexutil.h"
#include "mldivide.h"
#include "minangle.h"
#include "rsf2csf.h"
#include "sqrt.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 17, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRSInfo qb_emlrtRSI = { 50, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRSInfo rb_emlrtRSI = { 56, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRSInfo sb_emlrtRSI = { 57, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRSInfo tb_emlrtRSI = { 58, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRSInfo ub_emlrtRSI = { 67, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRSInfo vb_emlrtRSI = { 8, "eml_xgehrd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/eml_xgehrd.m"
};

static emlrtRSInfo wb_emlrtRSI = { 8, "eml_lapack_xgehrd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgehrd.m"
};

static emlrtRSInfo xb_emlrtRSI = { 22, "eml_matlab_zgehrd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m"
};

static emlrtRSInfo yb_emlrtRSI = { 31, "eml_matlab_zgehrd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m"
};

static emlrtRSInfo ac_emlrtRSI = { 35, "eml_matlab_zgehrd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m"
};

static emlrtRSInfo bc_emlrtRSI = { 43, "eml_matlab_zgehrd",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m"
};

static emlrtRSInfo jc_emlrtRSI = { 18, "eml_blas_xnrm2",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m"
};

static emlrtRSInfo lc_emlrtRSI = { 35, "eml_refblas_xnrm2",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m"
};

static emlrtRSInfo rc_emlrtRSI = { 14, "eml_blas_xscal",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m"
};

static emlrtRSInfo tc_emlrtRSI = { 17, "eml_refblas_xscal",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m"
};

static emlrtRSInfo ad_emlrtRSI = { 53, "eml_matlab_zlarf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m"
};

static emlrtRSInfo bd_emlrtRSI = { 84, "eml_matlab_zlarf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m"
};

static emlrtRSInfo cd_emlrtRSI = { 91, "eml_matlab_zlarf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m"
};

static emlrtRSInfo dd_emlrtRSI = { 121, "eml_matlab_zlarf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m"
};

static emlrtRSInfo ke_emlrtRSI = { 127, "eml_blas_xger",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"
};

static emlrtRSInfo le_emlrtRSI = { 130, "eml_blas_xger",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"
};

static emlrtRSInfo me_emlrtRSI = { 132, "eml_blas_xger",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m"
};

static emlrtRSInfo we_emlrtRSI = { 8, "eml_xunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/eml_xunghr.m"
};

static emlrtRSInfo xe_emlrtRSI = { 8, "eml_lapack_xunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xunghr.m"
};

static emlrtRSInfo ye_emlrtRSI = { 15, "eml_matlab_zunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m"
};

static emlrtRSInfo af_emlrtRSI = { 20, "eml_matlab_zunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m"
};

static emlrtRSInfo bf_emlrtRSI = { 24, "eml_matlab_zunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m"
};

static emlrtRSInfo cf_emlrtRSI = { 31, "eml_matlab_zunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m"
};

static emlrtRSInfo df_emlrtRSI = { 38, "eml_matlab_zunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m"
};

static emlrtRSInfo ef_emlrtRSI = { 40, "eml_matlab_zunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m"
};

static emlrtRSInfo ff_emlrtRSI = { 53, "eml_matlab_zunghr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m"
};

static emlrtRSInfo gf_emlrtRSI = { 15, "eml_matlab_zungqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m"
};

static emlrtRSInfo hf_emlrtRSI = { 33, "eml_matlab_zungqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m"
};

static emlrtRSInfo if_emlrtRSI = { 40, "eml_matlab_zungqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m"
};

static emlrtRSInfo jf_emlrtRSI = { 45, "eml_matlab_zungqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m"
};

static emlrtRSInfo kf_emlrtRSI = { 9, "eml_xhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/eml_xhseqr.m"
};

static emlrtRSInfo lf_emlrtRSI = { 10, "eml_lapack_xhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xhseqr.m"
};

static emlrtRSInfo mf_emlrtRSI = { 11, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo nf_emlrtRSI = { 15, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo of_emlrtRSI = { 49, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo pf_emlrtRSI = { 187, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo qf_emlrtRSI = { 238, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo rf_emlrtRSI = { 257, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo sf_emlrtRSI = { 263, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo tf_emlrtRSI = { 285, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo uf_emlrtRSI = { 293, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo vf_emlrtRSI = { 301, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo wf_emlrtRSI = { 311, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo xf_emlrtRSI = { 318, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo yf_emlrtRSI = { 325, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo ag_emlrtRSI = { 350, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo bg_emlrtRSI = { 355, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo cg_emlrtRSI = { 361, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo dg_emlrtRSI = { 368, "eml_matlab_dhseqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m"
};

static emlrtRSInfo kg_emlrtRSI = { 28, "eml_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m"
};

static emlrtRSInfo lg_emlrtRSI = { 17, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo mg_emlrtRSI = { 24, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo ng_emlrtRSI = { 23, "eml_refblas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m"
};

static emlrtRSInfo og_emlrtRSI = { 68, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo pg_emlrtRSI = { 69, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo qg_emlrtRSI = { 70, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo rg_emlrtRSI = { 74, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo sg_emlrtRSI = { 77, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo tg_emlrtRSI = { 80, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo ug_emlrtRSI = { 85, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo vg_emlrtRSI = { 87, "eml_blas_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m"
};

static emlrtRSInfo wg_emlrtRSI = { 48, "triu",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/triu.m"
};

static emlrtRSInfo xg_emlrtRSI = { 47, "triu",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elmat/triu.m"
};

static emlrtMCInfo h_emlrtMCI = { 18, 5, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtMCInfo i_emlrtMCI = { 17, 15, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 1, 18, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 40, 14, "schur",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/schur.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 1, 21, "eml_matlab_zlarf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m"
};

static emlrtRTEInfo s_emlrtRTEI = { 1, 14, "eml_matlab_zungqr",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m"
};

static emlrtRTEInfo u_emlrtRTEI = { 1, 18, "eml_xrot",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m"
};

/* Function Declarations */
static void b_eml_matlab_zlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  emxArray_real_T *C, int32_T ic0, int32_T ldc, real_T work_data[500], int32_T
  work_size[1]);
static real_T b_eml_matlab_zlarfg(int32_T n, real_T *alpha1, real_T x[3]);
static real_T b_eml_xnrm2(int32_T n, const real_T x[3]);
static void b_eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static int32_T eml_dlahqr(emxArray_real_T *h, emxArray_real_T *z);
static void eml_dlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1r,
  real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn);
static void eml_matlab_zlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  emxArray_real_T *C, int32_T ic0, int32_T ldc, real_T work_data[500]);
static void eml_matlab_zungqr(int32_T m, int32_T n, int32_T k, emxArray_real_T
  *A, int32_T ia0, int32_T lda, const real_T tau_data[499]);
static boolean_T eml_use_refblas(void);
static void eml_warning(void);
static void eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T incx,
                     int32_T iy0, int32_T incy, real_T c, real_T s);

/* Function Definitions */
static void b_eml_matlab_zlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  emxArray_real_T *C, int32_T ic0, int32_T ldc, real_T work_data[500], int32_T
  work_size[1])
{
  int32_T lastv;
  int32_T lastc;
  emxArray_real_T *y;
  emxArray_real_T *A;
  real_T alpha1;
  int32_T i10;
  int32_T loop_ub;
  int32_T b_loop_ub;
  int32_T i11;
  emxArray_real_T *x;
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
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C->data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    emlrtPushRtStackR2012b(&oe_emlrtRSI, emlrtRootTLSGlobal);
    lastc = ilazlc(lastv, n, C, ic0, ldc);
    emlrtPopRtStackR2012b(&oe_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    emlrtPushRtStackR2012b(&pe_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ed_emlrtRSI, emlrtRootTLSGlobal);
    b_emxInit_real_T(&y, 1, &r_emlrtRTEI, TRUE);
    emxInit_real_T(&A, 2, &r_emlrtRTEI, TRUE);
    if (lastc < 1) {
    } else {
      emlrtPushRtStackR2012b(&fd_emlrtRSI, emlrtRootTLSGlobal);
      alpha1 = 1.0;
      i10 = A->size[0] * A->size[1];
      A->size[0] = C->size[0];
      A->size[1] = C->size[1];
      emxEnsureCapacity((emxArray__common *)A, i10, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      loop_ub = C->size[1];
      for (i10 = 0; i10 < loop_ub; i10++) {
        b_loop_ub = C->size[0];
        for (i11 = 0; i11 < b_loop_ub; i11++) {
          A->data[i11 + A->size[0] * i10] = C->data[i11 + C->size[0] * i10];
        }
      }

      emxInit_real_T(&x, 2, &r_emlrtRTEI, TRUE);
      i10 = x->size[0] * x->size[1];
      x->size[0] = C->size[0];
      x->size[1] = C->size[1];
      emxEnsureCapacity((emxArray__common *)x, i10, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      loop_ub = C->size[1];
      for (i10 = 0; i10 < loop_ub; i10++) {
        b_loop_ub = C->size[0];
        for (i11 = 0; i11 < b_loop_ub; i11++) {
          x->data[i11 + x->size[0] * i10] = C->data[i11 + C->size[0] * i10];
        }
      }

      beta1 = 0.0;
      TRANSA = 'C';
      i10 = y->size[0];
      y->size[0] = work_size[0];
      emxEnsureCapacity((emxArray__common *)y, i10, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      loop_ub = work_size[0];
      for (i10 = 0; i10 < loop_ub; i10++) {
        y->data[i10] = work_data[i10];
      }

      emlrtPushRtStackR2012b(&kd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      m_t = (ptrdiff_t)(lastv);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&kd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ld_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(lastc);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ld_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&md_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      lda_t = (ptrdiff_t)(ldc);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&md_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&nd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&nd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&od_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incy_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&od_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&pd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      beta1_t = (double *)(&beta1);
      emlrtPopRtStackR2012b(&qd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      yiy0_t = (double *)(&y->data[0]);
      emlrtPopRtStackR2012b(&rd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&sd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      Aia0_t = (double *)(&A->data[ic0 - 1]);
      emlrtPopRtStackR2012b(&sd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&td_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      xix0_t = (double *)(&x->data[iv0 - 1]);
      emlrtPopRtStackR2012b(&td_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ud_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      dgemv(&TRANSA, &m_t, &n_t, alpha1_t, Aia0_t, &lda_t, xix0_t, &incx_t,
            beta1_t, yiy0_t, &incy_t);
      emlrtPopRtStackR2012b(&ud_emlrtRSI, emlrtRootTLSGlobal);
      work_size[0] = y->size[0];
      loop_ub = y->size[0];
      emxFree_real_T(&x);
      for (i10 = 0; i10 < loop_ub; i10++) {
        work_data[i10] = y->data[i10];
      }

      emlrtPopRtStackR2012b(&fd_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&ed_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&pe_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&qe_emlrtRSI, emlrtRootTLSGlobal);
    alpha1 = -tau;
    emlrtPushRtStackR2012b(&vd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&wd_emlrtRSI, emlrtRootTLSGlobal);
    if (lastc < 1) {
    } else {
      emlrtPushRtStackR2012b(&xd_emlrtRSI, emlrtRootTLSGlobal);
      i10 = y->size[0];
      y->size[0] = work_size[0];
      emxEnsureCapacity((emxArray__common *)y, i10, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      loop_ub = work_size[0];
      for (i10 = 0; i10 < loop_ub; i10++) {
        y->data[i10] = work_data[i10];
      }

      i10 = A->size[0] * A->size[1];
      A->size[0] = C->size[0];
      A->size[1] = C->size[1];
      emxEnsureCapacity((emxArray__common *)A, i10, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      loop_ub = C->size[1];
      for (i10 = 0; i10 < loop_ub; i10++) {
        b_loop_ub = C->size[0];
        for (i11 = 0; i11 < b_loop_ub; i11++) {
          A->data[i11 + A->size[0] * i10] = C->data[i11 + C->size[0] * i10];
        }
      }

      emlrtPushRtStackR2012b(&de_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      m_t = (ptrdiff_t)(lastv);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&de_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ee_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(lastc);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ee_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&fe_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&fe_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ge_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incy_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ge_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&he_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      lda_t = (ptrdiff_t)(ldc);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&he_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ie_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&ie_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&je_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      Aia0_t = (double *)(&A->data[ic0 - 1]);
      emlrtPopRtStackR2012b(&je_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&te_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      beta1_t = (double *)(&A->data[iv0 - 1]);
      emlrtPopRtStackR2012b(&te_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ue_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      yiy0_t = (double *)(&y->data[0]);
      emlrtPopRtStackR2012b(&ue_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ve_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      dger(&m_t, &n_t, alpha1_t, beta1_t, &incx_t, yiy0_t, &incy_t, Aia0_t,
           &lda_t);
      emlrtPopRtStackR2012b(&ve_emlrtRSI, emlrtRootTLSGlobal);
      i10 = C->size[0] * C->size[1];
      C->size[0] = A->size[0];
      C->size[1] = A->size[1];
      emxEnsureCapacity((emxArray__common *)C, i10, (int32_T)sizeof(real_T),
                        &r_emlrtRTEI);
      loop_ub = A->size[1];
      for (i10 = 0; i10 < loop_ub; i10++) {
        b_loop_ub = A->size[0];
        for (i11 = 0; i11 < b_loop_ub; i11++) {
          C->data[i11 + C->size[0] * i10] = A->data[i11 + A->size[0] * i10];
        }
      }

      emlrtPopRtStackR2012b(&xd_emlrtRSI, emlrtRootTLSGlobal);
    }

    emxFree_real_T(&A);
    emxFree_real_T(&y);
    emlrtPopRtStackR2012b(&wd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&vd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&qe_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

static real_T b_eml_matlab_zlarfg(int32_T n, real_T *alpha1, real_T x[3])
{
  real_T tau;
  real_T xnorm;
  int32_T knt;
  boolean_T b6;
  int32_T k;
  boolean_T b7;
  boolean_T b8;
  tau = 0.0;
  if (n <= 0) {
  } else {
    emlrtPushRtStackR2012b(&cc_emlrtRSI, emlrtRootTLSGlobal);
    xnorm = b_eml_xnrm2(n - 1, x);
    emlrtPopRtStackR2012b(&cc_emlrtRSI, emlrtRootTLSGlobal);
    if (xnorm != 0.0) {
      xnorm = muDoubleScalarHypot(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          emlrtPushRtStackR2012b(&dc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&tc_emlrtRSI, emlrtRootTLSGlobal);
          if (2 > n) {
            b6 = FALSE;
          } else {
            b6 = (n > 2147483646);
          }

          if (b6) {
            emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
            check_forloop_overflow_error();
            emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          }

          emlrtPopRtStackR2012b(&tc_emlrtRSI, emlrtRootTLSGlobal);
          for (k = 1; k + 1 <= n; k++) {
            x[k] *= 9.9792015476736E+291;
          }

          emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&dc_emlrtRSI, emlrtRootTLSGlobal);
          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(muDoubleScalarAbs(xnorm) >= 1.0020841800044864E-292));

        emlrtPushRtStackR2012b(&ec_emlrtRSI, emlrtRootTLSGlobal);
        xnorm = b_eml_xnrm2(n - 1, x);
        emlrtPopRtStackR2012b(&ec_emlrtRSI, emlrtRootTLSGlobal);
        xnorm = muDoubleScalarHypot(*alpha1, xnorm);
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        *alpha1 = 1.0 / (*alpha1 - xnorm);
        emlrtPushRtStackR2012b(&fc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&tc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&tc_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k + 1 <= n; k++) {
          x[k] *= *alpha1;
        }

        emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&fc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&gc_emlrtRSI, emlrtRootTLSGlobal);
        if (1 > knt) {
          b7 = FALSE;
        } else {
          b7 = (knt > 2147483646);
        }

        if (b7) {
          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          check_forloop_overflow_error();
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&gc_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k <= knt; k++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        *alpha1 = 1.0 / (*alpha1 - xnorm);
        emlrtPushRtStackR2012b(&hc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPushRtStackR2012b(&tc_emlrtRSI, emlrtRootTLSGlobal);
        if (2 > n) {
          b8 = FALSE;
        } else {
          b8 = (n > 2147483646);
        }

        if (b8) {
          emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
          check_forloop_overflow_error();
          emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&tc_emlrtRSI, emlrtRootTLSGlobal);
        for (k = 1; k + 1 <= n; k++) {
          x[k] *= *alpha1;
        }

        emlrtPopRtStackR2012b(&rc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&qc_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&hc_emlrtRSI, emlrtRootTLSGlobal);
        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

static real_T b_eml_xnrm2(int32_T n, const real_T x[3])
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtPushRtStackR2012b(&ic_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&jc_emlrtRSI, emlrtRootTLSGlobal);
  y = 0.0;
  if (n < 1) {
  } else if (n == 1) {
    y = muDoubleScalarAbs(x[1]);
  } else {
    scale = 2.2250738585072014E-308;
    emlrtPushRtStackR2012b(&lc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&lc_emlrtRSI, emlrtRootTLSGlobal);
    for (k = 0; k < 2; k++) {
      absxk = muDoubleScalarAbs(x[k + 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = 1.0 + y * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * muDoubleScalarSqrt(y);
  }

  emlrtPopRtStackR2012b(&jc_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ic_emlrtRSI, emlrtRootTLSGlobal);
  return y;
}

static void b_eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  int32_T loop_ub;
  real_T y;
  real_T b_y;
  emxArray_real_T *b_x;
  int32_T i14;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * xix0_t;
  double * c_t;
  double * s_t;
  double * xiy0_t;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&kg_emlrtRSI, emlrtRootTLSGlobal);
  if (eml_use_refblas()) {
    emlrtPushRtStackR2012b(&lg_emlrtRSI, emlrtRootTLSGlobal);
    if (n < 1) {
    } else {
      ix = ix0 - 1;
      iy = iy0 - 1;
      emlrtPushRtStackR2012b(&ng_emlrtRSI, emlrtRootTLSGlobal);
      if (n > 2147483646) {
        emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ng_emlrtRSI, emlrtRootTLSGlobal);
      for (loop_ub = 1; loop_ub <= n; loop_ub++) {
        y = c * x->data[ix];
        b_y = s * x->data[iy];
        x->data[iy] = c * x->data[iy] - s * x->data[ix];
        x->data[ix] = y + b_y;
        iy++;
        ix++;
      }
    }

    emlrtPopRtStackR2012b(&lg_emlrtRSI, emlrtRootTLSGlobal);
  } else if (n < 1) {
  } else {
    emxInit_real_T(&b_x, 2, &u_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&mg_emlrtRSI, emlrtRootTLSGlobal);
    ix = b_x->size[0] * b_x->size[1];
    b_x->size[0] = x->size[0];
    b_x->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)b_x, ix, (int32_T)sizeof(real_T),
                      &u_emlrtRTEI);
    iy = x->size[1];
    for (ix = 0; ix < iy; ix++) {
      loop_ub = x->size[0];
      for (i14 = 0; i14 < loop_ub; i14++) {
        b_x->data[i14 + b_x->size[0] * ix] = x->data[i14 + x->size[0] * ix];
      }
    }

    emlrtPushRtStackR2012b(&og_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&og_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&pg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&qg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incy_t = (ptrdiff_t)(1);
    emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&qg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&rg_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&b_x->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&rg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&sg_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    c_t = (double *)(&c);
    emlrtPopRtStackR2012b(&sg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&tg_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    s_t = (double *)(&s);
    emlrtPopRtStackR2012b(&tg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ug_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xiy0_t = (double *)(&b_x->data[iy0 - 1]);
    emlrtPopRtStackR2012b(&ug_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&vg_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    drot(&n_t, xix0_t, &incx_t, xiy0_t, &incy_t, c_t, s_t);
    emlrtPopRtStackR2012b(&vg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&mg_emlrtRSI, emlrtRootTLSGlobal);
    ix = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity((emxArray__common *)x, ix, (int32_T)sizeof(real_T),
                      &u_emlrtRTEI);
    iy = b_x->size[1];
    for (ix = 0; ix < iy; ix++) {
      loop_ub = b_x->size[0];
      for (i14 = 0; i14 < loop_ub; i14++) {
        x->data[i14 + x->size[0] * ix] = b_x->data[i14 + b_x->size[0] * ix];
      }
    }

    emxFree_real_T(&b_x);
  }

  emlrtPopRtStackR2012b(&kg_emlrtRSI, emlrtRootTLSGlobal);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

static int32_T eml_dlahqr(emxArray_real_T *h, emxArray_real_T *z)
{
  int32_T info;
  int32_T n;
  int32_T ldh;
  int32_T ldz;
  real_T v[3];
  int32_T j;
  real_T SMLNUM;
  int32_T i;
  boolean_T exitg1;
  int32_T L;
  boolean_T goto150;
  int32_T its;
  boolean_T exitg2;
  int32_T k;
  boolean_T exitg4;
  real_T tst;
  boolean_T guard1 = FALSE;
  real_T htmp1;
  real_T ab;
  real_T ba;
  real_T aa;
  real_T s;
  real_T rt1r;
  real_T rt2r;
  int32_T m;
  boolean_T exitg3;
  int32_T b_k;
  int32_T nr;
  int32_T hoffset;
  real_T b_v[3];
  real_T sn;
  real_T cs;
  n = h->size[0];
  ldh = h->size[0];
  ldz = z->size[0];
  info = 0;
  if ((h->size[0] == 0) || (1 == h->size[0])) {
  } else {
    emlrtPushRtStackR2012b(&of_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&of_emlrtRSI, emlrtRootTLSGlobal);
    for (j = 0; j + 1 <= n - 3; j++) {
      h->data[(j + h->size[0] * j) + 2] = 0.0;
      h->data[(j + h->size[0] * j) + 3] = 0.0;
    }

    if (1 <= n - 2) {
      h->data[(n + h->size[0] * (n - 3)) - 1] = 0.0;
    }

    SMLNUM = 2.2250738585072014E-308 * ((real_T)n / 2.2204460492503131E-16);
    i = n - 1;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (i + 1 >= 1)) {
      L = 1;
      goto150 = FALSE;
      its = 0;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (its < 31)) {
        k = i;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && ((k + 1 > L) && (!(muDoubleScalarAbs(h->
                   data[k + h->size[0] * (k - 1)]) <= SMLNUM)))) {
          tst = muDoubleScalarAbs(h->data[(k + h->size[0] * (k - 1)) - 1]) +
            muDoubleScalarAbs(h->data[k + h->size[0] * k]);
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = muDoubleScalarAbs(h->data[(k + h->size[0] * (k - 2)) - 1]);
            }

            if (k + 2 <= n) {
              tst += muDoubleScalarAbs(h->data[(k + h->size[0] * k) + 1]);
            }
          }

          guard1 = FALSE;
          if (muDoubleScalarAbs(h->data[k + h->size[0] * (k - 1)]) <=
              2.2204460492503131E-16 * tst) {
            htmp1 = muDoubleScalarAbs(h->data[k + h->size[0] * (k - 1)]);
            tst = muDoubleScalarAbs(h->data[(k + h->size[0] * k) - 1]);
            if (htmp1 > tst) {
              ab = htmp1;
              ba = tst;
            } else {
              ab = tst;
              ba = htmp1;
            }

            htmp1 = muDoubleScalarAbs(h->data[k + h->size[0] * k]);
            tst = muDoubleScalarAbs(h->data[(k + h->size[0] * (k - 1)) - 1] -
              h->data[k + h->size[0] * k]);
            if (htmp1 > tst) {
              aa = htmp1;
              htmp1 = tst;
            } else {
              aa = tst;
            }

            s = aa + ab;
            if (ba * (ab / s) <= muDoubleScalarMax(SMLNUM,
                 2.2204460492503131E-16 * (htmp1 * (aa / s)))) {
              exitg4 = TRUE;
            } else {
              guard1 = TRUE;
            }
          } else {
            guard1 = TRUE;
          }

          if (guard1 == TRUE) {
            k--;
          }
        }

        L = k + 1;
        if (k + 1 > 1) {
          h->data[k + h->size[0] * (k - 1)] = 0.0;
        }

        if (k + 1 >= i) {
          goto150 = TRUE;
          exitg2 = TRUE;
        } else {
          if (its == 10) {
            s = muDoubleScalarAbs(h->data[(k + h->size[0] * k) + 1]) +
              muDoubleScalarAbs(h->data[(k + h->size[0] * (k + 1)) + 2]);
            tst = 0.75 * s + h->data[k + h->size[0] * k];
            ab = -0.4375 * s;
            htmp1 = s;
            aa = tst;
          } else if (its == 20) {
            s = muDoubleScalarAbs(h->data[i + h->size[0] * (i - 1)]) +
              muDoubleScalarAbs(h->data[(i + h->size[0] * (i - 2)) - 1]);
            tst = 0.75 * s + h->data[i + h->size[0] * i];
            ab = -0.4375 * s;
            htmp1 = s;
            aa = tst;
          } else {
            tst = h->data[(i + h->size[0] * (i - 1)) - 1];
            htmp1 = h->data[i + h->size[0] * (i - 1)];
            ab = h->data[(i + h->size[0] * i) - 1];
            aa = h->data[i + h->size[0] * i];
          }

          s = ((muDoubleScalarAbs(tst) + muDoubleScalarAbs(ab)) +
               muDoubleScalarAbs(htmp1)) + muDoubleScalarAbs(aa);
          if (s == 0.0) {
            rt1r = 0.0;
            htmp1 = 0.0;
            rt2r = 0.0;
            ab = 0.0;
          } else {
            tst /= s;
            htmp1 /= s;
            ab /= s;
            aa /= s;
            ba = (tst + aa) / 2.0;
            tst = (tst - ba) * (aa - ba) - ab * htmp1;
            emlrtPushRtStackR2012b(&pf_emlrtRSI, emlrtRootTLSGlobal);
            htmp1 = muDoubleScalarAbs(tst);
            b_sqrt(&htmp1);
            emlrtPopRtStackR2012b(&pf_emlrtRSI, emlrtRootTLSGlobal);
            if (tst >= 0.0) {
              rt1r = ba * s;
              rt2r = rt1r;
              htmp1 *= s;
              ab = -htmp1;
            } else {
              rt1r = ba + htmp1;
              rt2r = ba - htmp1;
              if (muDoubleScalarAbs(rt1r - aa) <= muDoubleScalarAbs(rt2r - aa))
              {
                rt1r *= s;
                rt2r = rt1r;
              } else {
                rt2r *= s;
                rt1r = rt2r;
              }

              htmp1 = 0.0;
              ab = 0.0;
            }
          }

          m = i - 1;
          exitg3 = FALSE;
          while ((exitg3 == FALSE) && (m >= k + 1)) {
            s = (muDoubleScalarAbs(h->data[(m + h->size[0] * (m - 1)) - 1] -
                  rt2r) + muDoubleScalarAbs(ab)) + muDoubleScalarAbs(h->data[m +
              h->size[0] * (m - 1)]);
            tst = h->data[m + h->size[0] * (m - 1)] / s;
            v[0] = (tst * h->data[(m + h->size[0] * m) - 1] + (h->data[(m +
                      h->size[0] * (m - 1)) - 1] - rt1r) * ((h->data[(m +
                       h->size[0] * (m - 1)) - 1] - rt2r) / s)) - htmp1 * (ab /
              s);
            ba = tst * (((h->data[(m + h->size[0] * (m - 1)) - 1] + h->data[m +
                          h->size[0] * m]) - rt1r) - rt2r);
            v[1] = tst * (((h->data[(m + h->size[0] * (m - 1)) - 1] + h->data[m
                            + h->size[0] * m]) - rt1r) - rt2r);
            aa = tst * h->data[(m + h->size[0] * m) + 1];
            v[2] = tst * h->data[(m + h->size[0] * m) + 1];
            s = (muDoubleScalarAbs(v[0]) + muDoubleScalarAbs(ba)) +
              muDoubleScalarAbs(aa);
            v[0] /= s;
            tst = v[1] / s;
            v[1] = ba / s;
            ba = v[2] / s;
            v[2] = aa / s;
            if ((m == k + 1) || (muDoubleScalarAbs(h->data[(m + h->size[0] * (m
                    - 2)) - 1]) * (muDoubleScalarAbs(tst) + muDoubleScalarAbs(ba))
                                 <= 2.2204460492503131E-16 * muDoubleScalarAbs
                                 (v[0]) * ((muDoubleScalarAbs(h->data[(m +
                     h->size[0] * (m - 2)) - 2]) + muDoubleScalarAbs(h->data[(m
                     + h->size[0] * (m - 1)) - 1])) + muDoubleScalarAbs(h->
                   data[m + h->size[0] * m])))) {
              exitg3 = TRUE;
            } else {
              m--;
            }
          }

          emlrtPushRtStackR2012b(&qf_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPopRtStackR2012b(&qf_emlrtRSI, emlrtRootTLSGlobal);
          for (b_k = m; b_k <= i; b_k++) {
            nr = muIntScalarMin_sint32(3, (i - b_k) + 2);
            if (b_k > m) {
              hoffset = b_k + ldh * (b_k - 2);
              emlrtPushRtStackR2012b(&rf_emlrtRSI, emlrtRootTLSGlobal);
              emlrtPopRtStackR2012b(&rf_emlrtRSI, emlrtRootTLSGlobal);
              for (j = 1; j <= nr; j++) {
                v[j - 1] = h->data[(j + hoffset) - 2];
              }
            }

            emlrtPushRtStackR2012b(&sf_emlrtRSI, emlrtRootTLSGlobal);
            tst = v[0];
            for (hoffset = 0; hoffset < 3; hoffset++) {
              b_v[hoffset] = v[hoffset];
            }

            ba = b_eml_matlab_zlarfg(nr, &tst, b_v);
            emlrtPopRtStackR2012b(&sf_emlrtRSI, emlrtRootTLSGlobal);
            for (hoffset = 0; hoffset < 3; hoffset++) {
              v[hoffset] = b_v[hoffset];
            }

            v[0] = tst;
            if (b_k > m) {
              h->data[(b_k + h->size[0] * (b_k - 2)) - 1] = tst;
              h->data[b_k + h->size[0] * (b_k - 2)] = 0.0;
              if (b_k < i) {
                h->data[(b_k + h->size[0] * (b_k - 2)) + 1] = 0.0;
              }
            } else {
              if (m > k + 1) {
                h->data[(b_k + h->size[0] * (b_k - 2)) - 1] *= 1.0 - ba;
              }
            }

            tst = ba * b_v[1];
            if (nr == 3) {
              ab = ba * b_v[2];
              emlrtPushRtStackR2012b(&tf_emlrtRSI, emlrtRootTLSGlobal);
              emlrtPopRtStackR2012b(&tf_emlrtRSI, emlrtRootTLSGlobal);
              for (j = b_k - 1; j + 1 <= n; j++) {
                htmp1 = (h->data[(b_k + h->size[0] * j) - 1] + b_v[1] * h->
                         data[b_k + h->size[0] * j]) + b_v[2] * h->data[(b_k +
                  h->size[0] * j) + 1];
                h->data[(b_k + h->size[0] * j) - 1] -= htmp1 * ba;
                h->data[b_k + h->size[0] * j] -= htmp1 * tst;
                h->data[(b_k + h->size[0] * j) + 1] -= htmp1 * ab;
              }

              hoffset = muIntScalarMin_sint32(b_k + 3, i + 1);
              emlrtPushRtStackR2012b(&uf_emlrtRSI, emlrtRootTLSGlobal);
              emlrtPopRtStackR2012b(&uf_emlrtRSI, emlrtRootTLSGlobal);
              for (j = 0; j + 1 <= hoffset; j++) {
                htmp1 = (h->data[j + h->size[0] * (b_k - 1)] + b_v[1] * h->
                         data[j + h->size[0] * b_k]) + b_v[2] * h->data[j +
                  h->size[0] * (b_k + 1)];
                h->data[j + h->size[0] * (b_k - 1)] -= htmp1 * ba;
                h->data[j + h->size[0] * b_k] -= htmp1 * tst;
                h->data[j + h->size[0] * (b_k + 1)] -= htmp1 * ab;
              }

              emlrtPushRtStackR2012b(&vf_emlrtRSI, emlrtRootTLSGlobal);
              emlrtPopRtStackR2012b(&vf_emlrtRSI, emlrtRootTLSGlobal);
              for (j = 0; j + 1 <= n; j++) {
                htmp1 = (z->data[j + z->size[0] * (b_k - 1)] + b_v[1] * z->
                         data[j + z->size[0] * b_k]) + b_v[2] * z->data[j +
                  z->size[0] * (b_k + 1)];
                z->data[j + z->size[0] * (b_k - 1)] -= htmp1 * ba;
                z->data[j + z->size[0] * b_k] -= htmp1 * tst;
                z->data[j + z->size[0] * (b_k + 1)] -= htmp1 * ab;
              }
            } else {
              if (nr == 2) {
                emlrtPushRtStackR2012b(&wf_emlrtRSI, emlrtRootTLSGlobal);
                emlrtPopRtStackR2012b(&wf_emlrtRSI, emlrtRootTLSGlobal);
                for (j = b_k - 1; j + 1 <= n; j++) {
                  htmp1 = h->data[(b_k + h->size[0] * j) - 1] + b_v[1] * h->
                    data[b_k + h->size[0] * j];
                  h->data[(b_k + h->size[0] * j) - 1] -= htmp1 * ba;
                  h->data[b_k + h->size[0] * j] -= htmp1 * tst;
                }

                emlrtPushRtStackR2012b(&xf_emlrtRSI, emlrtRootTLSGlobal);
                emlrtPopRtStackR2012b(&xf_emlrtRSI, emlrtRootTLSGlobal);
                for (j = 0; j + 1 <= i + 1; j++) {
                  htmp1 = h->data[j + h->size[0] * (b_k - 1)] + b_v[1] * h->
                    data[j + h->size[0] * b_k];
                  h->data[j + h->size[0] * (b_k - 1)] -= htmp1 * ba;
                  h->data[j + h->size[0] * b_k] -= htmp1 * tst;
                }

                emlrtPushRtStackR2012b(&yf_emlrtRSI, emlrtRootTLSGlobal);
                emlrtPopRtStackR2012b(&yf_emlrtRSI, emlrtRootTLSGlobal);
                for (j = 0; j + 1 <= n; j++) {
                  htmp1 = z->data[j + z->size[0] * (b_k - 1)] + b_v[1] * z->
                    data[j + z->size[0] * b_k];
                  z->data[j + z->size[0] * (b_k - 1)] -= htmp1 * ba;
                  z->data[j + z->size[0] * b_k] -= htmp1 * tst;
                }
              }
            }
          }

          its++;
        }
      }

      if (!goto150) {
        info = i + 1;
        exitg1 = TRUE;
      } else {
        if ((L == i + 1) || (!(L == i))) {
        } else {
          emlrtPushRtStackR2012b(&ag_emlrtRSI, emlrtRootTLSGlobal);
          tst = h->data[(i + h->size[0] * (i - 1)) - 1];
          htmp1 = h->data[(i + h->size[0] * i) - 1];
          ab = h->data[i + h->size[0] * (i - 1)];
          ba = h->data[i + h->size[0] * i];
          eml_dlanv2(&tst, &htmp1, &ab, &ba, &aa, &rt2r, &rt1r, &s, &cs, &sn);
          emlrtPopRtStackR2012b(&ag_emlrtRSI, emlrtRootTLSGlobal);
          h->data[(i + h->size[0] * (i - 1)) - 1] = tst;
          h->data[(i + h->size[0] * i) - 1] = htmp1;
          h->data[i + h->size[0] * (i - 1)] = ab;
          h->data[i + h->size[0] * i] = ba;
          if (n > i + 1) {
            emlrtPushRtStackR2012b(&bg_emlrtRSI, emlrtRootTLSGlobal);
            eml_xrot((n - i) - 1, h, i + (i + 1) * ldh, ldh, (i + (i + 1) * ldh)
                     + 1, ldh, cs, sn);
            emlrtPopRtStackR2012b(&bg_emlrtRSI, emlrtRootTLSGlobal);
          }

          emlrtPushRtStackR2012b(&cg_emlrtRSI, emlrtRootTLSGlobal);
          b_eml_xrot(i - 1, h, (i - 1) * ldh + 1, i * ldh + 1, cs, sn);
          emlrtPopRtStackR2012b(&cg_emlrtRSI, emlrtRootTLSGlobal);
          emlrtPushRtStackR2012b(&dg_emlrtRSI, emlrtRootTLSGlobal);
          b_eml_xrot(n, z, (i - 1) * ldz + 1, i * ldz + 1, cs, sn);
          emlrtPopRtStackR2012b(&dg_emlrtRSI, emlrtRootTLSGlobal);
        }

        i = L - 2;
      }
    }
  }

  return info;
}

static void eml_dlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1r,
  real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn)
{
  real_T temp;
  real_T p;
  real_T bcmax;
  int32_T y;
  int32_T b_y;
  real_T bcmis;
  real_T scale;
  real_T z;
  real_T b_p;
  real_T tau;
  int32_T b_scale;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    temp = *d;
    *d = *a;
    *a = temp;
    *b = -*c;
    *c = 0.0;
  } else if ((*a - *d == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
    *cs = 1.0;
    *sn = 0.0;
  } else {
    temp = *a - *d;
    p = 0.5 * temp;
    bcmax = muDoubleScalarMax(muDoubleScalarAbs(*b), muDoubleScalarAbs(*c));
    if (!(*b < 0.0)) {
      y = 1;
    } else {
      y = -1;
    }

    if (!(*c < 0.0)) {
      b_y = 1;
    } else {
      b_y = -1;
    }

    bcmis = muDoubleScalarMin(muDoubleScalarAbs(*b), muDoubleScalarAbs(*c)) *
      (real_T)y * (real_T)b_y;
    scale = muDoubleScalarMax(muDoubleScalarAbs(p), bcmax);
    z = p / scale * p + bcmax / scale * bcmis;
    if (z >= 8.8817841970012523E-16) {
      emlrtPushRtStackR2012b(&eg_emlrtRSI, emlrtRootTLSGlobal);
      z = muDoubleScalarSqrt(scale) * muDoubleScalarSqrt(z);
      if (!(p < 0.0)) {
        b_p = z;
      } else {
        b_p = -z;
      }

      z = p + b_p;
      emlrtPopRtStackR2012b(&eg_emlrtRSI, emlrtRootTLSGlobal);
      *a = *d + z;
      *d -= bcmax / z * bcmis;
      tau = muDoubleScalarHypot(*c, z);
      *cs = z / tau;
      *sn = *c / tau;
      *b -= *c;
      *c = 0.0;
    } else {
      scale = *b + *c;
      tau = muDoubleScalarHypot(scale, temp);
      emlrtPushRtStackR2012b(&fg_emlrtRSI, emlrtRootTLSGlobal);
      z = 0.5 * (1.0 + muDoubleScalarAbs(scale) / tau);
      if (z < 0.0) {
        emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
        eml_error();
        emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
      }

      *cs = muDoubleScalarSqrt(z);
      emlrtPopRtStackR2012b(&fg_emlrtRSI, emlrtRootTLSGlobal);
      if (!(scale < 0.0)) {
        b_scale = 1;
      } else {
        b_scale = -1;
      }

      *sn = -(p / (tau * *cs)) * (real_T)b_scale;
      scale = *a * *cs + *b * *sn;
      bcmax = -*a * *sn + *b * *cs;
      bcmis = *c * *cs + *d * *sn;
      z = -*c * *sn + *d * *cs;
      *b = bcmax * *cs + z * *sn;
      *c = -scale * *sn + bcmis * *cs;
      temp = 0.5 * ((scale * *cs + bcmis * *sn) + (-bcmax * *sn + z * *cs));
      *a = temp;
      *d = temp;
      if (*c != 0.0) {
        if (*b != 0.0) {
          if ((*b < 0.0) == (*c < 0.0)) {
            emlrtPushRtStackR2012b(&gg_emlrtRSI, emlrtRootTLSGlobal);
            z = muDoubleScalarAbs(*b);
            scale = muDoubleScalarSqrt(z);
            emlrtPopRtStackR2012b(&gg_emlrtRSI, emlrtRootTLSGlobal);
            emlrtPushRtStackR2012b(&hg_emlrtRSI, emlrtRootTLSGlobal);
            z = muDoubleScalarAbs(*c);
            bcmis = muDoubleScalarSqrt(z);
            emlrtPopRtStackR2012b(&hg_emlrtRSI, emlrtRootTLSGlobal);
            z = scale * bcmis;
            if (!(*c < 0.0)) {
              p = z;
            } else {
              p = -z;
            }

            emlrtPushRtStackR2012b(&ig_emlrtRSI, emlrtRootTLSGlobal);
            z = muDoubleScalarAbs(*b + *c);
            tau = 1.0 / muDoubleScalarSqrt(z);
            emlrtPopRtStackR2012b(&ig_emlrtRSI, emlrtRootTLSGlobal);
            *a = temp + p;
            *d = temp - p;
            *b -= *c;
            *c = 0.0;
            bcmax = scale * tau;
            scale = bcmis * tau;
            z = *sn * scale;
            *sn = *cs * scale + *sn * bcmax;
            *cs = *cs * bcmax - z;
          }
        } else {
          *b = -*c;
          *c = 0.0;
          temp = *cs;
          *cs = -*sn;
          *sn = temp;
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    emlrtPushRtStackR2012b(&jg_emlrtRSI, emlrtRootTLSGlobal);
    z = muDoubleScalarAbs(*b);
    scale = muDoubleScalarAbs(*c);
    *rt1i = muDoubleScalarSqrt(z) * muDoubleScalarSqrt(scale);
    emlrtPopRtStackR2012b(&jg_emlrtRSI, emlrtRootTLSGlobal);
    *rt2i = -*rt1i;
  }
}

static void eml_matlab_zlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  emxArray_real_T *C, int32_T ic0, int32_T ldc, real_T work_data[500])
{
  int32_T lastv;
  int32_T lastc;
  boolean_T exitg2;
  int32_T rowleft;
  int32_T rowright;
  boolean_T overflow;
  int32_T exitg1;
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
    lastv = n;
    lastc = iv0 + n;
    while ((lastv > 0) && (C->data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    emlrtPushRtStackR2012b(&ad_emlrtRSI, emlrtRootTLSGlobal);
    lastc = m;
    exitg2 = FALSE;
    while ((exitg2 == FALSE) && (lastc > 0)) {
      rowleft = (ic0 + lastc) - 1;
      rowright = rowleft + (lastv - 1) * ldc;
      emlrtPushRtStackR2012b(&dd_emlrtRSI, emlrtRootTLSGlobal);
      if ((ldc == 0) || (rowleft > rowright)) {
        overflow = FALSE;
      } else {
        overflow = (rowright > MAX_int32_T - ldc);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&dd_emlrtRSI, emlrtRootTLSGlobal);
      do {
        exitg1 = 0;
        if ((ldc > 0) && (rowleft <= rowright)) {
          if (C->data[rowleft - 1] != 0.0) {
            exitg1 = 1;
          } else {
            rowleft += ldc;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = TRUE;
      }
    }

    emlrtPopRtStackR2012b(&ad_emlrtRSI, emlrtRootTLSGlobal);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    emlrtPushRtStackR2012b(&bd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ed_emlrtRSI, emlrtRootTLSGlobal);
    if (lastc < 1) {
    } else {
      emlrtPushRtStackR2012b(&fd_emlrtRSI, emlrtRootTLSGlobal);
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSA = 'N';
      emlrtPushRtStackR2012b(&kd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      m_t = (ptrdiff_t)(lastc);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&kd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ld_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(lastv);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ld_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&md_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      lda_t = (ptrdiff_t)(ldc);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&md_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&nd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&nd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&od_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incy_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&od_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&pd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      beta1_t = (double *)(&beta1);
      emlrtPopRtStackR2012b(&qd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      yiy0_t = (double *)(&work_data[0]);
      emlrtPopRtStackR2012b(&rd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&sd_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      Aia0_t = (double *)(&C->data[ic0 - 1]);
      emlrtPopRtStackR2012b(&sd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&td_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      xix0_t = (double *)(&C->data[iv0 - 1]);
      emlrtPopRtStackR2012b(&td_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ud_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      dgemv(&TRANSA, &m_t, &n_t, alpha1_t, Aia0_t, &lda_t, xix0_t, &incx_t,
            beta1_t, yiy0_t, &incy_t);
      emlrtPopRtStackR2012b(&ud_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&fd_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&ed_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&bd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&cd_emlrtRSI, emlrtRootTLSGlobal);
    alpha1 = -tau;
    emlrtPushRtStackR2012b(&vd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&wd_emlrtRSI, emlrtRootTLSGlobal);
    if (lastc < 1) {
    } else {
      emlrtPushRtStackR2012b(&xd_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&de_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      m_t = (ptrdiff_t)(lastc);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&de_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ee_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      n_t = (ptrdiff_t)(lastv);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ee_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&fe_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incx_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&fe_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ge_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      incy_t = (ptrdiff_t)(1);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ge_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&he_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      lda_t = (ptrdiff_t)(ldc);
      emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&he_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ie_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&ie_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&je_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      Aia0_t = (double *)(&C->data[ic0 - 1]);
      emlrtPopRtStackR2012b(&je_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ke_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      xix0_t = (double *)(&work_data[0]);
      emlrtPopRtStackR2012b(&ke_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&le_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      beta1_t = (double *)(&C->data[iv0 - 1]);
      emlrtPopRtStackR2012b(&le_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&me_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_checkEscapedGlobals();
      dger(&m_t, &n_t, alpha1_t, xix0_t, &incx_t, beta1_t, &incy_t, Aia0_t,
           &lda_t);
      emlrtPopRtStackR2012b(&me_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&xd_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&wd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&vd_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&cd_emlrtRSI, emlrtRootTLSGlobal);
  }
}

static void eml_matlab_zungqr(int32_T m, int32_T n, int32_T k, emxArray_real_T
  *A, int32_T ia0, int32_T lda, const real_T tau_data[499])
{
  emxArray_real_T *r63;
  int32_T j;
  int32_T ia;
  int32_T i;
  int32_T itau;
  int16_T unnamed_idx_0;
  int32_T work_size[1];
  real_T work_data[500];
  emxArray_real_T *b_A;
  emxArray_real_T *r64;
  int32_T iaii;
  int32_T loop_ub;
  int32_T i12;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&r63, 2, &s_emlrtRTEI, TRUE);
  if (n < 1) {
  } else {
    emlrtPushRtStackR2012b(&gf_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&gf_emlrtRSI, emlrtRootTLSGlobal);
    for (j = k; j < n; j++) {
      ia = ia0 + j * lda;
      for (i = 0; i < m; i++) {
        A->data[(ia + i) - 1] = 0.0;
      }

      A->data[(ia + j) - 1] = 1.0;
    }

    itau = k - 1;
    unnamed_idx_0 = (int16_T)A->size[1];
    work_size[0] = unnamed_idx_0;
    ia = unnamed_idx_0;
    for (j = 0; j < ia; j++) {
      work_data[j] = 0.0;
    }

    i = k;
    emxInit_real_T(&b_A, 2, &s_emlrtRTEI, TRUE);
    emxInit_real_T(&r64, 2, &s_emlrtRTEI, TRUE);
    while (i >= 1) {
      iaii = ((ia0 + i) + (i - 1) * lda) - 1;
      if (i < n) {
        A->data[iaii - 1] = 1.0;
        emlrtPushRtStackR2012b(&hf_emlrtRSI, emlrtRootTLSGlobal);
        b_eml_matlab_zlarf((m - i) + 1, n - i, iaii, tau_data[itau], A, iaii +
                           lda, lda, work_data, work_size);
        emlrtPopRtStackR2012b(&hf_emlrtRSI, emlrtRootTLSGlobal);
      }

      if (i < m) {
        emlrtPushRtStackR2012b(&if_emlrtRSI, emlrtRootTLSGlobal);
        j = b_A->size[0] * b_A->size[1];
        b_A->size[0] = A->size[0];
        b_A->size[1] = A->size[1];
        emxEnsureCapacity((emxArray__common *)b_A, j, (int32_T)sizeof(real_T),
                          &s_emlrtRTEI);
        ia = A->size[1];
        for (j = 0; j < ia; j++) {
          loop_ub = A->size[0];
          for (i12 = 0; i12 < loop_ub; i12++) {
            b_A->data[i12 + b_A->size[0] * j] = A->data[i12 + A->size[0] * j];
          }
        }

        j = r63->size[0] * r63->size[1];
        r63->size[0] = b_A->size[0];
        r63->size[1] = b_A->size[1];
        emxEnsureCapacity((emxArray__common *)r63, j, (int32_T)sizeof(real_T),
                          &s_emlrtRTEI);
        ia = b_A->size[1];
        for (j = 0; j < ia; j++) {
          loop_ub = b_A->size[0];
          for (i12 = 0; i12 < loop_ub; i12++) {
            r63->data[i12 + r63->size[0] * j] = b_A->data[i12 + b_A->size[0] * j];
          }
        }

        eml_xscal(m - i, -tau_data[itau], r63, iaii + 1);
        j = r64->size[0] * r64->size[1];
        r64->size[0] = r63->size[0];
        r64->size[1] = r63->size[1];
        emxEnsureCapacity((emxArray__common *)r64, j, (int32_T)sizeof(real_T),
                          &s_emlrtRTEI);
        ia = r63->size[1];
        for (j = 0; j < ia; j++) {
          loop_ub = r63->size[0];
          for (i12 = 0; i12 < loop_ub; i12++) {
            r64->data[i12 + r64->size[0] * j] = r63->data[i12 + r63->size[0] * j];
          }
        }

        j = A->size[0] * A->size[1];
        A->size[0] = r64->size[0];
        A->size[1] = r64->size[1];
        emxEnsureCapacity((emxArray__common *)A, j, (int32_T)sizeof(real_T),
                          &s_emlrtRTEI);
        ia = r64->size[1];
        for (j = 0; j < ia; j++) {
          loop_ub = r64->size[0];
          for (i12 = 0; i12 < loop_ub; i12++) {
            A->data[i12 + A->size[0] * j] = r64->data[i12 + r64->size[0] * j];
          }
        }

        emlrtPopRtStackR2012b(&if_emlrtRSI, emlrtRootTLSGlobal);
      }

      A->data[iaii - 1] = 1.0 - tau_data[itau];
      emlrtPushRtStackR2012b(&jf_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&jf_emlrtRSI, emlrtRootTLSGlobal);
      for (j = 1; j < i; j++) {
        A->data[(iaii - j) - 1] = 0.0;
      }

      itau--;
      i--;
    }

    emxFree_real_T(&r64);
    emxFree_real_T(&b_A);
  }

  emxFree_real_T(&r63);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

static boolean_T eml_use_refblas(void)
{
  return FALSE;
}

static void eml_warning(void)
{
  const mxArray *y;
  static const int32_T iv37[2] = { 1, 26 };

  const mxArray *m4;
  char_T cv16[26];
  int32_T i;
  static const char_T cv17[26] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 's', 'c', 'h', 'u', 'r', '_', 'f', 'a', 'i', 'l',
    'e', 'd' };

  emlrtPushRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
  emlrt_synchGlobalsToML();
  y = NULL;
  m4 = mxCreateCharArray(2, iv37);
  for (i = 0; i < 26; i++) {
    cv16[i] = cv17[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 26, m4, cv16);
  emlrtAssign(&y, m4);
  warning(message(y, &j_emlrtMCI), &k_emlrtMCI);
  emlrt_synchGlobalsFromML();
  emlrtPopRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
}

static void eml_xrot(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T incx,
                     int32_T iy0, int32_T incy, real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  int32_T loop_ub;
  real_T y;
  real_T b_y;
  emxArray_real_T *b_x;
  int32_T i13;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * xix0_t;
  double * c_t;
  double * s_t;
  double * xiy0_t;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&kg_emlrtRSI, emlrtRootTLSGlobal);
  if (eml_use_refblas()) {
    emlrtPushRtStackR2012b(&lg_emlrtRSI, emlrtRootTLSGlobal);
    if (n < 1) {
    } else {
      ix = ix0 - 1;
      iy = iy0 - 1;
      emlrtPushRtStackR2012b(&ng_emlrtRSI, emlrtRootTLSGlobal);
      if (n > 2147483646) {
        emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&ng_emlrtRSI, emlrtRootTLSGlobal);
      for (loop_ub = 1; loop_ub <= n; loop_ub++) {
        y = c * x->data[ix];
        b_y = s * x->data[iy];
        x->data[iy] = c * x->data[iy] - s * x->data[ix];
        x->data[ix] = y + b_y;
        iy += incx;
        ix += incy;
      }
    }

    emlrtPopRtStackR2012b(&lg_emlrtRSI, emlrtRootTLSGlobal);
  } else if (n < 1) {
  } else {
    emxInit_real_T(&b_x, 2, &u_emlrtRTEI, TRUE);
    emlrtPushRtStackR2012b(&mg_emlrtRSI, emlrtRootTLSGlobal);
    ix = b_x->size[0] * b_x->size[1];
    b_x->size[0] = x->size[0];
    b_x->size[1] = x->size[1];
    emxEnsureCapacity((emxArray__common *)b_x, ix, (int32_T)sizeof(real_T),
                      &u_emlrtRTEI);
    iy = x->size[1];
    for (ix = 0; ix < iy; ix++) {
      loop_ub = x->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        b_x->data[i13 + b_x->size[0] * ix] = x->data[i13 + x->size[0] * ix];
      }
    }

    emlrtPushRtStackR2012b(&og_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&og_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incx_t = (ptrdiff_t)(incx);
    emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&pg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&qg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    incy_t = (ptrdiff_t)(incy);
    emlrtPopRtStackR2012b(&pc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&qg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&rg_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xix0_t = (double *)(&b_x->data[ix0 - 1]);
    emlrtPopRtStackR2012b(&rg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&sg_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    c_t = (double *)(&c);
    emlrtPopRtStackR2012b(&sg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&tg_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    s_t = (double *)(&s);
    emlrtPopRtStackR2012b(&tg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ug_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    xiy0_t = (double *)(&b_x->data[iy0 - 1]);
    emlrtPopRtStackR2012b(&ug_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&vg_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    drot(&n_t, xix0_t, &incx_t, xiy0_t, &incy_t, c_t, s_t);
    emlrtPopRtStackR2012b(&vg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&mg_emlrtRSI, emlrtRootTLSGlobal);
    ix = x->size[0] * x->size[1];
    x->size[0] = b_x->size[0];
    x->size[1] = b_x->size[1];
    emxEnsureCapacity((emxArray__common *)x, ix, (int32_T)sizeof(real_T),
                      &u_emlrtRTEI);
    iy = b_x->size[1];
    for (ix = 0; ix < iy; ix++) {
      loop_ub = b_x->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        x->data[i13 + x->size[0] * ix] = b_x->data[i13 + b_x->size[0] * ix];
      }
    }

    emxFree_real_T(&b_x);
  }

  emlrtPopRtStackR2012b(&kg_emlrtRSI, emlrtRootTLSGlobal);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

void schur(const emxArray_real_T *A, emxArray_creal_T *V, emxArray_creal_T *T)
{
  emxArray_real_T *a;
  emxArray_real_T *b_a;
  const mxArray *y;
  static const int32_T iv36[2] = { 1, 19 };

  const mxArray *m3;
  char_T cv14[19];
  int32_T i;
  static const char_T cv15[19] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'q', 'u', 'a', 'r', 'e' };

  int32_T i3;
  int32_T loop_ub;
  real_T tau_data[499];
  int16_T unnamed_idx_0;
  int32_T work_size[1];
  real_T work_data[500];
  int32_T iajm1;
  int32_T istart;
  real_T alpha1;
  int32_T j;
  real_T d0;
  emxArray_real_T *Vr;
  emxArray_real_T *h;
  int32_T info;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&a, 2, &m_emlrtRTEI, TRUE);
  emxInit_real_T(&b_a, 2, &m_emlrtRTEI, TRUE);
  if (A->size[0] == A->size[1]) {
  } else {
    emlrtPushRtStackR2012b(&pb_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    y = NULL;
    m3 = mxCreateCharArray(2, iv36);
    for (i = 0; i < 19; i++) {
      cv14[i] = cv15[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 19, m3, cv14);
    emlrtAssign(&y, m3);
    error(message(y, &h_emlrtMCI), &i_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&pb_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&vb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&wb_emlrtRSI, emlrtRootTLSGlobal);
  i3 = a->size[0] * a->size[1];
  a->size[0] = A->size[0];
  a->size[1] = A->size[1];
  emxEnsureCapacity((emxArray__common *)a, i3, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  loop_ub = A->size[0] * A->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    a->data[i3] = A->data[i3];
  }

  unnamed_idx_0 = (int16_T)A->size[0];
  work_size[0] = unnamed_idx_0;
  loop_ub = unnamed_idx_0;
  for (i3 = 0; i3 < loop_ub; i3++) {
    work_data[i3] = 0.0;
  }

  emlrtPushRtStackR2012b(&xb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&xb_emlrtRSI, emlrtRootTLSGlobal);
  for (i = 1; i < A->size[0]; i++) {
    iajm1 = (i - 1) * A->size[0] + 1;
    istart = i * A->size[0] + 1;
    emlrtPushRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
    i3 = muIntScalarMin_sint32(i + 2, A->size[0]) + (i - 1) * A->size[0];
    alpha1 = a->data[i + a->size[0] * (i - 1)];
    j = b_a->size[0] * b_a->size[1];
    b_a->size[0] = a->size[0];
    b_a->size[1] = a->size[1];
    emxEnsureCapacity((emxArray__common *)b_a, j, (int32_T)sizeof(real_T),
                      &m_emlrtRTEI);
    loop_ub = a->size[0] * a->size[1];
    for (j = 0; j < loop_ub; j++) {
      b_a->data[j] = a->data[j];
    }

    d0 = eml_matlab_zlarfg(A->size[0] - i, &alpha1, b_a, i3);
    emlrtPopRtStackR2012b(&yb_emlrtRSI, emlrtRootTLSGlobal);
    i3 = a->size[0] * a->size[1];
    a->size[0] = b_a->size[0];
    a->size[1] = b_a->size[1];
    emxEnsureCapacity((emxArray__common *)a, i3, (int32_T)sizeof(real_T),
                      &m_emlrtRTEI);
    loop_ub = b_a->size[0] * b_a->size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      a->data[i3] = b_a->data[i3];
    }

    tau_data[i - 1] = d0;
    a->data[i + a->size[0] * (i - 1)] = 1.0;
    emlrtPushRtStackR2012b(&ac_emlrtRSI, emlrtRootTLSGlobal);
    eml_matlab_zlarf(A->size[0], A->size[0] - i, i + iajm1, tau_data[i - 1], a,
                     istart, A->size[0], work_data);
    emlrtPopRtStackR2012b(&ac_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bc_emlrtRSI, emlrtRootTLSGlobal);
    b_eml_matlab_zlarf(A->size[0] - i, A->size[0] - i, i + iajm1, tau_data[i - 1],
                       a, i + istart, A->size[0], work_data, work_size);
    emlrtPopRtStackR2012b(&bc_emlrtRSI, emlrtRootTLSGlobal);
    a->data[i + a->size[0] * (i - 1)] = alpha1;
  }

  emxInit_real_T(&Vr, 2, &o_emlrtRTEI, TRUE);
  emlrtPopRtStackR2012b(&wb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&vb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&we_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&xe_emlrtRSI, emlrtRootTLSGlobal);
  i3 = Vr->size[0] * Vr->size[1];
  Vr->size[0] = a->size[0];
  Vr->size[1] = a->size[1];
  emxEnsureCapacity((emxArray__common *)Vr, i3, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  loop_ub = a->size[0] * a->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    Vr->data[i3] = a->data[i3];
  }

  if (A->size[0] == 0) {
  } else {
    for (j = A->size[0]; j > 1; j--) {
      istart = (j - 1) * A->size[0];
      emlrtPushRtStackR2012b(&ye_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ye_emlrtRSI, emlrtRootTLSGlobal);
      for (i = 1; i < j; i++) {
        Vr->data[(istart + i) - 1] = 0.0;
      }

      iajm1 = istart - A->size[0];
      emlrtPushRtStackR2012b(&af_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&af_emlrtRSI, emlrtRootTLSGlobal);
      for (i = j; i + 1 <= A->size[0]; i++) {
        Vr->data[istart + i] = Vr->data[iajm1 + i];
      }

      emlrtPushRtStackR2012b(&bf_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&bf_emlrtRSI, emlrtRootTLSGlobal);
      for (i = A->size[0]; i + 1 <= A->size[0]; i++) {
        Vr->data[istart + i] = 0.0;
      }
    }

    emlrtPushRtStackR2012b(&cf_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&cf_emlrtRSI, emlrtRootTLSGlobal);
    for (i = 1; i <= A->size[0]; i++) {
      Vr->data[i - 1] = 0.0;
    }

    Vr->data[0] = 1.0;
    emlrtPushRtStackR2012b(&df_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&df_emlrtRSI, emlrtRootTLSGlobal);
    for (j = A->size[0]; j + 1 <= A->size[0]; j++) {
      istart = j * A->size[0];
      emlrtPushRtStackR2012b(&ef_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ef_emlrtRSI, emlrtRootTLSGlobal);
      for (i = 1; i <= A->size[0]; i++) {
        Vr->data[(istart + i) - 1] = 0.0;
      }

      Vr->data[istart + j] = 1.0;
    }

    emlrtPushRtStackR2012b(&ff_emlrtRSI, emlrtRootTLSGlobal);
    i3 = A->size[0] + 2;
    eml_matlab_zungqr(A->size[0] - 1, A->size[0] - 1, A->size[0] - 1, Vr, i3,
                      A->size[0], tau_data);
    emlrtPopRtStackR2012b(&ff_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxInit_real_T(&h, 2, &m_emlrtRTEI, TRUE);
  emlrtPopRtStackR2012b(&xe_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&we_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&sb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&kf_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&lf_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&mf_emlrtRSI, emlrtRootTLSGlobal);
  info = eml_dlahqr(a, Vr);
  emlrtPopRtStackR2012b(&mf_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nf_emlrtRSI, emlrtRootTLSGlobal);
  i3 = h->size[0] * h->size[1];
  h->size[0] = a->size[0];
  h->size[1] = a->size[1];
  emxEnsureCapacity((emxArray__common *)h, i3, (int32_T)sizeof(real_T),
                    &m_emlrtRTEI);
  loop_ub = a->size[0] * a->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    h->data[i3] = a->data[i3];
  }

  if ((a->size[0] == 0) || (a->size[1] == 0) || (3 >= a->size[0])) {
  } else {
    istart = 4;
    if (a->size[0] - 4 < a->size[1] - 1) {
      iajm1 = a->size[0] - 3;
    } else {
      iajm1 = a->size[1];
    }

    emlrtPushRtStackR2012b(&xg_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&xg_emlrtRSI, emlrtRootTLSGlobal);
    for (j = 1; j <= iajm1; j++) {
      emlrtPushRtStackR2012b(&wg_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&wg_emlrtRSI, emlrtRootTLSGlobal);
      for (i = istart; i <= a->size[0]; i++) {
        h->data[(i + h->size[0] * (j - 1)) - 1] = 0.0;
      }

      istart++;
    }
  }

  emlrtPopRtStackR2012b(&nf_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&lf_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&kf_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&sb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&tb_emlrtRSI, emlrtRootTLSGlobal);
  rsf2csf(Vr, h, V, T);
  emlrtPopRtStackR2012b(&tb_emlrtRSI, emlrtRootTLSGlobal);
  emxFree_real_T(&h);
  emxFree_real_T(&Vr);
  if (info != 0) {
    emlrtPushRtStackR2012b(&ub_emlrtRSI, emlrtRootTLSGlobal);
    eml_warning();
    emlrtPopRtStackR2012b(&ub_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&b_a);
  emxFree_real_T(&a);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (schur.c) */
