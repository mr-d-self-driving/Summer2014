/*
 * rsf2csf.c
 *
 * Code generation for function 'rsf2csf'
 *
 * C source code generated on: Tue Dec  9 10:58:59 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "rsf2csf.h"
#include "mldivide.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo yg_emlrtRSI = { 15, "rsf2csf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/rsf2csf.m"
};

static emlrtRSInfo ah_emlrtRSI = { 31, "eml_rsf2csf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m"
};

static emlrtRSInfo bh_emlrtRSI = { 41, "eml_rsf2csf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m"
};

static emlrtRSInfo ch_emlrtRSI = { 49, "eml_rsf2csf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m"
};

static emlrtRSInfo dh_emlrtRSI = { 56, "eml_rsf2csf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 1, 18, "rsf2csf",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/matfun/rsf2csf.m"
};

/* Function Definitions */
void rsf2csf(const emxArray_real_T *Ur, const emxArray_real_T *Tr,
             emxArray_creal_T *U, emxArray_creal_T *T)
{
  int32_T y;
  int32_T loop_ub;
  int16_T varargin_1[2];
  int32_T mtmp;
  int32_T m;
  real_T c;
  real_T b;
  real_T temp;
  real_T p;
  real_T bcmax;
  real_T scale;
  real_T bb;
  real_T b_p;
  real_T cs;
  int32_T b_scale;
  real_T b_c;
  real_T mu1_re;
  emlrtPushRtStackR2012b(&yg_emlrtRSI, emlrtRootTLSGlobal);
  y = T->size[0] * T->size[1];
  T->size[0] = Tr->size[0];
  T->size[1] = Tr->size[1];
  emxEnsureCapacity((emxArray__common *)T, y, (int32_T)sizeof(creal_T),
                    &v_emlrtRTEI);
  loop_ub = Tr->size[0] * Tr->size[1];
  for (y = 0; y < loop_ub; y++) {
    T->data[y].re = Tr->data[y];
    T->data[y].im = 0.0;
  }

  y = U->size[0] * U->size[1];
  U->size[0] = Ur->size[0];
  U->size[1] = Ur->size[1];
  emxEnsureCapacity((emxArray__common *)U, y, (int32_T)sizeof(creal_T),
                    &v_emlrtRTEI);
  loop_ub = Ur->size[0] * Ur->size[1];
  for (y = 0; y < loop_ub; y++) {
    U->data[y].re = Ur->data[y];
    U->data[y].im = 0.0;
  }

  for (y = 0; y < 2; y++) {
    varargin_1[y] = (int16_T)Tr->size[y];
  }

  mtmp = varargin_1[0];
  if (varargin_1[1] < varargin_1[0]) {
    mtmp = varargin_1[1];
  }

  for (y = 0; y < 2; y++) {
    varargin_1[y] = (int16_T)Ur->size[y];
  }

  loop_ub = varargin_1[0];
  if (varargin_1[1] < varargin_1[0]) {
    loop_ub = varargin_1[1];
  }

  mtmp = (int32_T)muDoubleScalarMin(mtmp, loop_ub);
  if (mtmp == 0) {
  } else {
    for (m = mtmp - 1; m + 1 >= 2; m--) {
      if (Tr->data[m + Tr->size[0] * (m - 1)] != 0.0) {
        emlrtPushRtStackR2012b(&ah_emlrtRSI, emlrtRootTLSGlobal);
        c = Tr->data[m + Tr->size[0] * (m - 1)];
        b = Tr->data[(m + Tr->size[0] * m) - 1];
        temp = Tr->data[(m + Tr->size[0] * (m - 1)) - 1];
        if (Tr->data[m + Tr->size[0] * (m - 1)] == 0.0) {
        } else if (Tr->data[(m + Tr->size[0] * m) - 1] == 0.0) {
          temp = Tr->data[m + Tr->size[0] * m];
          b = -Tr->data[m + Tr->size[0] * (m - 1)];
          c = 0.0;
        } else if ((Tr->data[(m + Tr->size[0] * (m - 1)) - 1] - Tr->data[m +
                    Tr->size[0] * m] == 0.0) && ((Tr->data[(m + Tr->size[0] * m)
          - 1] < 0.0) != (Tr->data[m + Tr->size[0] * (m - 1)] < 0.0))) {
        } else {
          temp = Tr->data[(m + Tr->size[0] * (m - 1)) - 1] - Tr->data[m +
            Tr->size[0] * m];
          p = 0.5 * temp;
          bcmax = muDoubleScalarMax(muDoubleScalarAbs(Tr->data[(m + Tr->size[0] *
            m) - 1]), muDoubleScalarAbs(Tr->data[m + Tr->size[0] * (m - 1)]));
          if (!(Tr->data[(m + Tr->size[0] * m) - 1] < 0.0)) {
            loop_ub = 1;
          } else {
            loop_ub = -1;
          }

          if (!(Tr->data[m + Tr->size[0] * (m - 1)] < 0.0)) {
            y = 1;
          } else {
            y = -1;
          }

          scale = muDoubleScalarMax(muDoubleScalarAbs(p), bcmax);
          bcmax = p / scale * p + bcmax / scale * (muDoubleScalarMin
            (muDoubleScalarAbs(Tr->data[(m + Tr->size[0] * m) - 1]),
             muDoubleScalarAbs(Tr->data[m + Tr->size[0] * (m - 1)])) * (real_T)
            loop_ub * (real_T)y);
          if (bcmax >= 8.8817841970012523E-16) {
            emlrtPushRtStackR2012b(&eg_emlrtRSI, emlrtRootTLSGlobal);
            bb = muDoubleScalarSqrt(scale) * muDoubleScalarSqrt(bcmax);
            emlrtPopRtStackR2012b(&eg_emlrtRSI, emlrtRootTLSGlobal);
            if (!(p < 0.0)) {
              b_p = bb;
            } else {
              b_p = -bb;
            }

            temp = Tr->data[m + Tr->size[0] * m] + (p + b_p);
            b = Tr->data[(m + Tr->size[0] * m) - 1] - Tr->data[m + Tr->size[0] *
              (m - 1)];
            c = 0.0;
          } else {
            scale = Tr->data[(m + Tr->size[0] * m) - 1] + Tr->data[m + Tr->size
              [0] * (m - 1)];
            bcmax = muDoubleScalarHypot(scale, temp);
            emlrtPushRtStackR2012b(&fg_emlrtRSI, emlrtRootTLSGlobal);
            bb = 0.5 * (1.0 + muDoubleScalarAbs(scale) / bcmax);
            if (bb < 0.0) {
              emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
              eml_error();
              emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
            }

            cs = muDoubleScalarSqrt(bb);
            emlrtPopRtStackR2012b(&fg_emlrtRSI, emlrtRootTLSGlobal);
            if (!(scale < 0.0)) {
              b_scale = 1;
            } else {
              b_scale = -1;
            }

            bcmax = -(p / (bcmax * cs)) * (real_T)b_scale;
            scale = Tr->data[(m + Tr->size[0] * (m - 1)) - 1] * cs + Tr->data[(m
              + Tr->size[0] * m) - 1] * bcmax;
            bb = -Tr->data[(m + Tr->size[0] * (m - 1)) - 1] * bcmax + Tr->data
              [(m + Tr->size[0] * m) - 1] * cs;
            p = Tr->data[m + Tr->size[0] * (m - 1)] * cs + Tr->data[m + Tr->
              size[0] * m] * bcmax;
            temp = -Tr->data[m + Tr->size[0] * (m - 1)] * bcmax + Tr->data[m +
              Tr->size[0] * m] * cs;
            b = bb * cs + temp * bcmax;
            c = -scale * bcmax + p * cs;
            temp = 0.5 * ((scale * cs + p * bcmax) + (-bb * bcmax + temp * cs));
            if (c != 0.0) {
              if (b != 0.0) {
                if ((b < 0.0) == (c < 0.0)) {
                  emlrtPushRtStackR2012b(&gg_emlrtRSI, emlrtRootTLSGlobal);
                  emlrtPopRtStackR2012b(&gg_emlrtRSI, emlrtRootTLSGlobal);
                  emlrtPushRtStackR2012b(&hg_emlrtRSI, emlrtRootTLSGlobal);
                  emlrtPopRtStackR2012b(&hg_emlrtRSI, emlrtRootTLSGlobal);
                  bb = muDoubleScalarSqrt(muDoubleScalarAbs(b)) *
                    muDoubleScalarSqrt(muDoubleScalarAbs(c));
                  emlrtPushRtStackR2012b(&ig_emlrtRSI, emlrtRootTLSGlobal);
                  emlrtPopRtStackR2012b(&ig_emlrtRSI, emlrtRootTLSGlobal);
                  if (!(c < 0.0)) {
                    b_c = bb;
                  } else {
                    b_c = -bb;
                  }

                  temp += b_c;
                  b -= c;
                  c = 0.0;
                }
              } else {
                b = -c;
                c = 0.0;
              }
            }
          }
        }

        if (c == 0.0) {
          bcmax = 0.0;
        } else {
          emlrtPushRtStackR2012b(&jg_emlrtRSI, emlrtRootTLSGlobal);
          bcmax = muDoubleScalarSqrt(muDoubleScalarAbs(b)) * muDoubleScalarSqrt
            (muDoubleScalarAbs(c));
          emlrtPopRtStackR2012b(&jg_emlrtRSI, emlrtRootTLSGlobal);
        }

        emlrtPopRtStackR2012b(&ah_emlrtRSI, emlrtRootTLSGlobal);
        mu1_re = temp - Tr->data[m + Tr->size[0] * m];
        scale = muDoubleScalarHypot(muDoubleScalarHypot(mu1_re, bcmax), Tr->
          data[m + Tr->size[0] * (m - 1)]);
        if (bcmax == 0.0) {
          mu1_re /= scale;
          cs = 0.0;
        } else if (mu1_re == 0.0) {
          mu1_re = 0.0;
          cs = bcmax / scale;
        } else {
          mu1_re /= scale;
          cs = bcmax / scale;
        }

        c = Tr->data[m + Tr->size[0] * (m - 1)] / scale;
        emlrtPushRtStackR2012b(&bh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&bh_emlrtRSI, emlrtRootTLSGlobal);
        for (loop_ub = m - 1; loop_ub + 1 <= mtmp; loop_ub++) {
          b = T->data[(m + T->size[0] * loop_ub) - 1].re;
          temp = T->data[(m + T->size[0] * loop_ub) - 1].im;
          bb = T->data[(m + T->size[0] * loop_ub) - 1].re;
          p = T->data[(m + T->size[0] * loop_ub) - 1].im;
          bcmax = T->data[(m + T->size[0] * loop_ub) - 1].im;
          scale = T->data[(m + T->size[0] * loop_ub) - 1].re;
          T->data[(m + T->size[0] * loop_ub) - 1].re = (mu1_re * bb + cs * p) +
            c * T->data[m + T->size[0] * loop_ub].re;
          T->data[(m + T->size[0] * loop_ub) - 1].im = (mu1_re * bcmax - cs *
            scale) + c * T->data[m + T->size[0] * loop_ub].im;
          bcmax = mu1_re * T->data[m + T->size[0] * loop_ub].re - cs * T->data[m
            + T->size[0] * loop_ub].im;
          scale = mu1_re * T->data[m + T->size[0] * loop_ub].im + cs * T->data[m
            + T->size[0] * loop_ub].re;
          T->data[m + T->size[0] * loop_ub].re = bcmax - c * b;
          T->data[m + T->size[0] * loop_ub].im = scale - c * temp;
        }

        emlrtPushRtStackR2012b(&ch_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&ch_emlrtRSI, emlrtRootTLSGlobal);
        for (loop_ub = 0; loop_ub + 1 <= m + 1; loop_ub++) {
          b = T->data[loop_ub + T->size[0] * (m - 1)].re;
          temp = T->data[loop_ub + T->size[0] * (m - 1)].im;
          bcmax = mu1_re * T->data[loop_ub + T->size[0] * (m - 1)].re - cs *
            T->data[loop_ub + T->size[0] * (m - 1)].im;
          scale = mu1_re * T->data[loop_ub + T->size[0] * (m - 1)].im + cs *
            T->data[loop_ub + T->size[0] * (m - 1)].re;
          bb = T->data[loop_ub + T->size[0] * m].re;
          p = T->data[loop_ub + T->size[0] * m].im;
          T->data[loop_ub + T->size[0] * (m - 1)].re = bcmax + c * bb;
          T->data[loop_ub + T->size[0] * (m - 1)].im = scale + c * p;
          bb = T->data[loop_ub + T->size[0] * m].re;
          p = T->data[loop_ub + T->size[0] * m].im;
          bcmax = T->data[loop_ub + T->size[0] * m].im;
          scale = T->data[loop_ub + T->size[0] * m].re;
          T->data[loop_ub + T->size[0] * m].re = (mu1_re * bb + cs * p) - c * b;
          T->data[loop_ub + T->size[0] * m].im = (mu1_re * bcmax - cs * scale) -
            c * temp;
        }

        emlrtPushRtStackR2012b(&dh_emlrtRSI, emlrtRootTLSGlobal);
        emlrtPopRtStackR2012b(&dh_emlrtRSI, emlrtRootTLSGlobal);
        for (loop_ub = 0; loop_ub + 1 <= mtmp; loop_ub++) {
          b = U->data[loop_ub + U->size[0] * (m - 1)].re;
          temp = U->data[loop_ub + U->size[0] * (m - 1)].im;
          bcmax = mu1_re * U->data[loop_ub + U->size[0] * (m - 1)].re - cs *
            U->data[loop_ub + U->size[0] * (m - 1)].im;
          scale = mu1_re * U->data[loop_ub + U->size[0] * (m - 1)].im + cs *
            U->data[loop_ub + U->size[0] * (m - 1)].re;
          bb = U->data[loop_ub + U->size[0] * m].re;
          p = U->data[loop_ub + U->size[0] * m].im;
          U->data[loop_ub + U->size[0] * (m - 1)].re = bcmax + c * bb;
          U->data[loop_ub + U->size[0] * (m - 1)].im = scale + c * p;
          bb = U->data[loop_ub + U->size[0] * m].re;
          p = U->data[loop_ub + U->size[0] * m].im;
          bcmax = U->data[loop_ub + U->size[0] * m].im;
          scale = U->data[loop_ub + U->size[0] * m].re;
          U->data[loop_ub + U->size[0] * m].re = (mu1_re * bb + cs * p) - c * b;
          U->data[loop_ub + U->size[0] * m].im = (mu1_re * bcmax - cs * scale) -
            c * temp;
        }

        T->data[m + T->size[0] * (m - 1)].re = 0.0;
        T->data[m + T->size[0] * (m - 1)].im = 0.0;
      }
    }
  }

  emlrtPopRtStackR2012b(&yg_emlrtRSI, emlrtRootTLSGlobal);
}

/* End of code generation (rsf2csf.c) */
