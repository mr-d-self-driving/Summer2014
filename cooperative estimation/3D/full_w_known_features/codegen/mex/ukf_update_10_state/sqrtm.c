/*
 * sqrtm.c
 *
 * Code generation for function 'sqrtm'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "sqrtm.h"
#include "sqrt.h"
#include "ukf_update_10_state_emxutil.h"
#include "norm.h"
#include "ukf_update_10_state_mexutil.h"
#include "mtimes.h"
#include "schur.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 11, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo db_emlrtRSI = { 13, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo eb_emlrtRSI = { 16, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo fb_emlrtRSI = { 18, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo gb_emlrtRSI = { 23, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo hb_emlrtRSI = { 33, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo ib_emlrtRSI = { 40, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo jb_emlrtRSI = { 57, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo kb_emlrtRSI = { 84, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo lb_emlrtRSI = { 85, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo ch_emlrtRSI = { 160, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRSInfo dh_emlrtRSI = { 161, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtMCInfo g_emlrtMCI = { 12, 5, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtMCInfo h_emlrtMCI = { 11, 15, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 1, 29, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 15, 1, "sqrtm",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/sqrtm.m"
};

/* Function Declarations */
static void eml_xgemm(int32_T m, int32_T n, int32_T k, const emxArray_creal_T *A,
                      int32_T lda, const emxArray_creal_T *B, int32_T ldb,
                      emxArray_creal_T *C, int32_T ldc);
static boolean_T isUTmatD(const emxArray_creal_T *T);

/* Function Definitions */
static void eml_xgemm(int32_T m, int32_T n, int32_T k, const emxArray_creal_T *A,
                      int32_T lda, const emxArray_creal_T *B, int32_T ldb,
                      emxArray_creal_T *C, int32_T ldc)
{
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  static const creal_T alpha1 = { 1.0, 0.0 };

  double * alpha1_t;
  double * Aia0_t;
  double * Bib0_t;
  static const creal_T beta1 = { 0.0, 0.0 };

  double * beta1_t;
  double * Cic0_t;
  emlrtPushRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
  if ((m < 1) || (n < 1) || (k < 1)) {
  } else {
    emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
    TRANSB = 'N';
    TRANSA = 'N';
    emlrtPushRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    m_t = (ptrdiff_t)(m);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&qh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    n_t = (ptrdiff_t)(n);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&rh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    k_t = (ptrdiff_t)(k);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&sh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    lda_t = (ptrdiff_t)(lda);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&th_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    ldb_t = (ptrdiff_t)(ldb);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&uh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    ldc_t = (ptrdiff_t)(ldc);
    emlrtPopRtStackR2012b(&mc_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&vh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    alpha1_t = (double *)(&alpha1);
    emlrtPopRtStackR2012b(&wh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    Aia0_t = (double *)(&A->data[0]);
    emlrtPopRtStackR2012b(&xh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    Bib0_t = (double *)(&B->data[0]);
    emlrtPopRtStackR2012b(&yh_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    beta1_t = (double *)(&beta1);
    emlrtPopRtStackR2012b(&ai_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    Cic0_t = (double *)(&C->data[0]);
    emlrtPopRtStackR2012b(&bi_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_checkEscapedGlobals();
    zgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t, Bib0_t,
          &ldb_t, beta1_t, Cic0_t, &ldc_t);
    emlrtPopRtStackR2012b(&ci_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&ih_emlrtRSI, emlrtRootTLSGlobal);
}

static boolean_T isUTmatD(const emxArray_creal_T *T)
{
  boolean_T p;
  int32_T j;
  int32_T exitg2;
  int32_T i;
  int32_T exitg1;
  boolean_T b_T;
  emlrtPushRtStackR2012b(&ch_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&ch_emlrtRSI, emlrtRootTLSGlobal);
  j = 0;
  do {
    exitg2 = 0;
    if (j + 1 <= T->size[1]) {
      emlrtPushRtStackR2012b(&dh_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&dh_emlrtRSI, emlrtRootTLSGlobal);
      i = 1;
      do {
        exitg1 = 0;
        if (i <= j) {
          b_T = ((T->data[(i + T->size[0] * j) - 1].re != 0.0) || (T->data[(i +
                   T->size[0] * j) - 1].im != 0.0));
          if (b_T) {
            p = FALSE;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = 1;
      }
    } else {
      p = TRUE;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  return p;
}

void sqrtm(const emxArray_real_T *A, emxArray_creal_T *X, real_T *arg2)
{
  emxArray_creal_T *T;
  emxArray_creal_T *y;
  boolean_T b1;
  const mxArray *b_y;
  static const int32_T iv16[2] = { 1, 19 };

  const mxArray *m2;
  char_T cv13[19];
  int32_T i;
  static const char_T cv14[19] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'q', 'u', 'a', 'r', 'e' };

  emxArray_creal_T *Q;
  emxArray_creal_T *r9;
  int32_T loop_ub;
  int16_T iv17[2];
  emxArray_creal_T *R;
  real_T s_re;
  real_T s_im;
  int32_T k;
  real_T R_re;
  real_T R_im;
  real_T T_re;
  real_T T_im;
  real_T brm;
  int32_T i3;
  int32_T b_loop_ub;
  int32_T i4;
  emxArray_creal_T *b_T;
  emxArray_real_T *b_X;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_creal_T(&T, 2, &k_emlrtRTEI, TRUE);
  emxInit_creal_T(&y, 2, &k_emlrtRTEI, TRUE);
  b1 = (A->size[0] == A->size[1]);
  if (b1) {
  } else {
    emlrtPushRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
    emlrt_synchGlobalsToML();
    b_y = NULL;
    m2 = mxCreateCharArray(2, iv16);
    for (i = 0; i < 19; i++) {
      cv13[i] = cv14[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 19, m2, cv13);
    emlrtAssign(&b_y, m2);
    error(message(b_y, &g_emlrtMCI), &h_emlrtMCI);
    emlrt_synchGlobalsFromML();
    emlrtPopRtStackR2012b(&cb_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxInit_creal_T(&Q, 2, &k_emlrtRTEI, TRUE);
  emxInit_creal_T(&r9, 2, &k_emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
  schur(A, Q, r9);
  i = T->size[0] * T->size[1];
  T->size[0] = r9->size[0];
  T->size[1] = r9->size[1];
  emxEnsureCapacity((emxArray__common *)T, i, (int32_T)sizeof(creal_T),
                    &k_emlrtRTEI);
  loop_ub = r9->size[0] * r9->size[1];
  for (i = 0; i < loop_ub; i++) {
    T->data[i] = r9->data[i];
  }

  emxFree_creal_T(&r9);
  emlrtPopRtStackR2012b(&db_emlrtRSI, emlrtRootTLSGlobal);
  for (i = 0; i < 2; i++) {
    iv17[i] = (int16_T)T->size[i];
  }

  emxInit_creal_T(&R, 2, &l_emlrtRTEI, TRUE);
  i = R->size[0] * R->size[1];
  R->size[0] = iv17[0];
  emxEnsureCapacity((emxArray__common *)R, i, (int32_T)sizeof(creal_T),
                    &k_emlrtRTEI);
  i = R->size[0] * R->size[1];
  R->size[1] = iv17[1];
  emxEnsureCapacity((emxArray__common *)R, i, (int32_T)sizeof(creal_T),
                    &k_emlrtRTEI);
  loop_ub = iv17[0] * iv17[1];
  for (i = 0; i < loop_ub; i++) {
    R->data[i].re = 0.0;
    R->data[i].im = 0.0;
  }

  emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
  b1 = isUTmatD(T);
  emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
  if (b1) {
    emlrtPushRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
    for (loop_ub = 0; loop_ub + 1 <= A->size[0]; loop_ub++) {
      R->data[loop_ub + R->size[0] * loop_ub] = T->data[loop_ub + T->size[0] *
        loop_ub];
      c_sqrt(&R->data[loop_ub + R->size[0] * loop_ub]);
    }
  } else {
    emlrtPushRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
    for (loop_ub = 0; loop_ub + 1 <= A->size[0]; loop_ub++) {
      R->data[loop_ub + R->size[0] * loop_ub] = T->data[loop_ub + T->size[0] *
        loop_ub];
      c_sqrt(&R->data[loop_ub + R->size[0] * loop_ub]);
      for (i = loop_ub - 1; i + 1 > 0; i--) {
        s_re = 0.0;
        s_im = 0.0;
        emlrtPushRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
        for (k = i + 1; k + 1 <= loop_ub; k++) {
          R_re = R->data[i + R->size[0] * k].re * R->data[k + R->size[0] *
            loop_ub].re - R->data[i + R->size[0] * k].im * R->data[k + R->size[0]
            * loop_ub].im;
          R_im = R->data[i + R->size[0] * k].re * R->data[k + R->size[0] *
            loop_ub].im + R->data[i + R->size[0] * k].im * R->data[k + R->size[0]
            * loop_ub].re;
          s_re += R_re;
          s_im += R_im;
        }

        T_re = T->data[i + T->size[0] * loop_ub].re - s_re;
        T_im = T->data[i + T->size[0] * loop_ub].im - s_im;
        R_re = R->data[i + R->size[0] * i].re + R->data[loop_ub + R->size[0] *
          loop_ub].re;
        R_im = R->data[i + R->size[0] * i].im + R->data[loop_ub + R->size[0] *
          loop_ub].im;
        if (R_im == 0.0) {
          if (T_im == 0.0) {
            R->data[i + R->size[0] * loop_ub].re = T_re / R_re;
            R->data[i + R->size[0] * loop_ub].im = 0.0;
          } else if (T_re == 0.0) {
            R->data[i + R->size[0] * loop_ub].re = 0.0;
            R->data[i + R->size[0] * loop_ub].im = T_im / R_re;
          } else {
            R->data[i + R->size[0] * loop_ub].re = T_re / R_re;
            R->data[i + R->size[0] * loop_ub].im = T_im / R_re;
          }
        } else if (R_re == 0.0) {
          if (T_re == 0.0) {
            R->data[i + R->size[0] * loop_ub].re = T_im / R_im;
            R->data[i + R->size[0] * loop_ub].im = 0.0;
          } else if (T_im == 0.0) {
            R->data[i + R->size[0] * loop_ub].re = 0.0;
            R->data[i + R->size[0] * loop_ub].im = -(T_re / R_im);
          } else {
            R->data[i + R->size[0] * loop_ub].re = T_im / R_im;
            R->data[i + R->size[0] * loop_ub].im = -(T_re / R_im);
          }
        } else {
          brm = muDoubleScalarAbs(R_re);
          s_re = muDoubleScalarAbs(R_im);
          if (brm > s_re) {
            s_re = R_im / R_re;
            s_im = R_re + s_re * R_im;
            R->data[i + R->size[0] * loop_ub].re = (T_re + s_re * T_im) / s_im;
            R->data[i + R->size[0] * loop_ub].im = (T_im - s_re * T_re) / s_im;
          } else if (s_re == brm) {
            if (R_re > 0.0) {
              s_im = 0.5;
            } else {
              s_im = -0.5;
            }

            if (R_im > 0.0) {
              s_re = 0.5;
            } else {
              s_re = -0.5;
            }

            R->data[i + R->size[0] * loop_ub].re = (T_re * s_im + T_im * s_re) /
              brm;
            R->data[i + R->size[0] * loop_ub].im = (T_im * s_im - T_re * s_re) /
              brm;
          } else {
            s_re = R_re / R_im;
            s_im = R_im + s_re * R_re;
            R->data[i + R->size[0] * loop_ub].re = (s_re * T_re + T_im) / s_im;
            R->data[i + R->size[0] * loop_ub].im = (s_re * T_im - T_re) / s_im;
          }
        }
      }
    }
  }

  emlrtPushRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
  dynamic_size_checks(Q, R);
  emlrtPopRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
  if ((Q->size[1] == 1) || (R->size[0] == 1)) {
    i = y->size[0] * y->size[1];
    y->size[0] = Q->size[0];
    y->size[1] = R->size[1];
    emxEnsureCapacity((emxArray__common *)y, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    loop_ub = Q->size[0];
    for (i = 0; i < loop_ub; i++) {
      k = R->size[1];
      for (i3 = 0; i3 < k; i3++) {
        y->data[i + y->size[0] * i3].re = 0.0;
        y->data[i + y->size[0] * i3].im = 0.0;
        b_loop_ub = Q->size[1];
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          s_re = Q->data[i + Q->size[0] * i4].re * R->data[i4 + R->size[0] * i3]
            .re - Q->data[i + Q->size[0] * i4].im * R->data[i4 + R->size[0] * i3]
            .im;
          s_im = Q->data[i + Q->size[0] * i4].re * R->data[i4 + R->size[0] * i3]
            .im + Q->data[i + Q->size[0] * i4].im * R->data[i4 + R->size[0] * i3]
            .re;
          y->data[i + y->size[0] * i3].re += s_re;
          y->data[i + y->size[0] * i3].im += s_im;
        }
      }
    }
  } else {
    iv17[0] = (int16_T)Q->size[0];
    iv17[1] = (int16_T)R->size[1];
    emlrtPushRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
    i = y->size[0] * y->size[1];
    y->size[0] = iv17[0];
    emxEnsureCapacity((emxArray__common *)y, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    i = y->size[0] * y->size[1];
    y->size[1] = iv17[1];
    emxEnsureCapacity((emxArray__common *)y, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    loop_ub = iv17[0] * iv17[1];
    for (i = 0; i < loop_ub; i++) {
      y->data[i].re = 0.0;
      y->data[i].im = 0.0;
    }

    eml_xgemm(Q->size[0], R->size[1], Q->size[1], Q, Q->size[0], R, Q->size[1],
              y, Q->size[0]);
    emlrtPopRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxFree_creal_T(&R);
  i = T->size[0] * T->size[1];
  T->size[0] = Q->size[1];
  T->size[1] = Q->size[0];
  emxEnsureCapacity((emxArray__common *)T, i, (int32_T)sizeof(creal_T),
                    &k_emlrtRTEI);
  loop_ub = Q->size[0];
  for (i = 0; i < loop_ub; i++) {
    k = Q->size[1];
    for (i3 = 0; i3 < k; i3++) {
      T->data[i3 + T->size[0] * i].re = Q->data[i + Q->size[0] * i3].re;
      T->data[i3 + T->size[0] * i].im = -Q->data[i + Q->size[0] * i3].im;
    }
  }

  emxFree_creal_T(&Q);
  emlrtPushRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
  dynamic_size_checks(y, T);
  emlrtPopRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
  if ((y->size[1] == 1) || (T->size[0] == 1)) {
    i = X->size[0] * X->size[1];
    X->size[0] = y->size[0];
    X->size[1] = T->size[1];
    emxEnsureCapacity((emxArray__common *)X, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    loop_ub = y->size[0];
    for (i = 0; i < loop_ub; i++) {
      k = T->size[1];
      for (i3 = 0; i3 < k; i3++) {
        X->data[i + X->size[0] * i3].re = 0.0;
        X->data[i + X->size[0] * i3].im = 0.0;
        b_loop_ub = y->size[1];
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          s_re = y->data[i + y->size[0] * i4].re * T->data[i4 + T->size[0] * i3]
            .re - y->data[i + y->size[0] * i4].im * T->data[i4 + T->size[0] * i3]
            .im;
          s_im = y->data[i + y->size[0] * i4].re * T->data[i4 + T->size[0] * i3]
            .im + y->data[i + y->size[0] * i4].im * T->data[i4 + T->size[0] * i3]
            .re;
          X->data[i + X->size[0] * i3].re += s_re;
          X->data[i + X->size[0] * i3].im += s_im;
        }
      }
    }
  } else {
    iv17[0] = (int16_T)y->size[0];
    iv17[1] = (int16_T)T->size[1];
    emlrtPushRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
    i = X->size[0] * X->size[1];
    X->size[0] = iv17[0];
    emxEnsureCapacity((emxArray__common *)X, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    i = X->size[0] * X->size[1];
    X->size[1] = iv17[1];
    emxEnsureCapacity((emxArray__common *)X, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    loop_ub = iv17[0] * iv17[1];
    for (i = 0; i < loop_ub; i++) {
      X->data[i].re = 0.0;
      X->data[i].im = 0.0;
    }

    eml_xgemm(y->size[0], T->size[1], y->size[1], y, y->size[0], T, y->size[1],
              X, y->size[0]);
    emlrtPopRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
  dynamic_size_checks(X, X);
  emlrtPopRtStackR2012b(&fh_emlrtRSI, emlrtRootTLSGlobal);
  if ((X->size[1] == 1) || (X->size[0] == 1)) {
    i = T->size[0] * T->size[1];
    T->size[0] = X->size[0];
    T->size[1] = X->size[1];
    emxEnsureCapacity((emxArray__common *)T, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    loop_ub = X->size[0];
    for (i = 0; i < loop_ub; i++) {
      k = X->size[1];
      for (i3 = 0; i3 < k; i3++) {
        T->data[i + T->size[0] * i3].re = 0.0;
        T->data[i + T->size[0] * i3].im = 0.0;
        b_loop_ub = X->size[1];
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          s_re = X->data[i + X->size[0] * i4].re * X->data[i4 + X->size[0] * i3]
            .re - X->data[i + X->size[0] * i4].im * X->data[i4 + X->size[0] * i3]
            .im;
          s_im = X->data[i + X->size[0] * i4].re * X->data[i4 + X->size[0] * i3]
            .im + X->data[i + X->size[0] * i4].im * X->data[i4 + X->size[0] * i3]
            .re;
          T->data[i + T->size[0] * i3].re += s_re;
          T->data[i + T->size[0] * i3].im += s_im;
        }
      }
    }
  } else {
    iv17[0] = (int16_T)X->size[0];
    iv17[1] = (int16_T)X->size[1];
    emlrtPushRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
    i = T->size[0] * T->size[1];
    T->size[0] = iv17[0];
    emxEnsureCapacity((emxArray__common *)T, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    i = T->size[0] * T->size[1];
    T->size[1] = iv17[1];
    emxEnsureCapacity((emxArray__common *)T, i, (int32_T)sizeof(creal_T),
                      &k_emlrtRTEI);
    loop_ub = iv17[0] * iv17[1];
    for (i = 0; i < loop_ub; i++) {
      T->data[i].re = 0.0;
      T->data[i].im = 0.0;
    }

    eml_xgemm(X->size[0], X->size[1], X->size[1], X, X->size[0], X, X->size[1],
              T, X->size[0]);
    emlrtPopRtStackR2012b(&eh_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxInit_creal_T(&b_T, 2, &k_emlrtRTEI, TRUE);
  emlrtPopRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
  i = b_T->size[0] * b_T->size[1];
  b_T->size[0] = T->size[0];
  b_T->size[1] = T->size[1];
  emxEnsureCapacity((emxArray__common *)b_T, i, (int32_T)sizeof(creal_T),
                    &k_emlrtRTEI);
  loop_ub = T->size[0] * T->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_T->data[i].re = T->data[i].re - A->data[i];
    b_T->data[i].im = T->data[i].im;
  }

  emxInit_real_T(&b_X, 2, &k_emlrtRTEI, TRUE);
  s_re = norm(b_T);
  s_im = b_norm(A);
  *arg2 = s_re / s_im;
  emlrtPopRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = X->size[0];
  b_X->size[1] = X->size[1];
  emxEnsureCapacity((emxArray__common *)b_X, i, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  loop_ub = X->size[0] * X->size[1];
  emxFree_creal_T(&b_T);
  for (i = 0; i < loop_ub; i++) {
    b_X->data[i] = X->data[i].im;
  }

  if (c_norm(b_X) <= 10.0 * (real_T)A->size[0] * 2.2204460492503131E-16 * d_norm
      (X)) {
    emlrtPushRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
    for (loop_ub = 0; loop_ub + 1 <= A->size[0]; loop_ub++) {
      emlrtPushRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      for (i = 0; i + 1 <= A->size[0]; i++) {
        s_re = X->data[i + X->size[0] * loop_ub].re;
        X->data[i + X->size[0] * loop_ub].re = s_re;
        X->data[i + X->size[0] * loop_ub].im = 0.0;
      }
    }
  }

  emxFree_real_T(&b_X);
  emxFree_creal_T(&y);
  emxFree_creal_T(&T);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (sqrtm.c) */
