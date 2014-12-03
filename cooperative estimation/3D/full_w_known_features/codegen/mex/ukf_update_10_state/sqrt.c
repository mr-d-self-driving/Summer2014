/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "sqrt.h"
#include "mldivide.h"
#include "ukf_update_10_state_data.h"
#include <stdio.h>

/* Function Definitions */
void b_sqrt(real_T *x)
{
  if (*x < 0.0) {
    emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
    eml_error();
    emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
  }

  *x = muDoubleScalarSqrt(*x);
}

void c_sqrt(creal_T *x)
{
  real_T absxi;
  real_T absxr;
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      absxi = 0.0;
      absxr = muDoubleScalarSqrt(muDoubleScalarAbs(x->re));
    } else {
      absxi = muDoubleScalarSqrt(x->re);
      absxr = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      absxi = muDoubleScalarSqrt(-x->im / 2.0);
      absxr = -absxi;
    } else {
      absxi = muDoubleScalarSqrt(x->im / 2.0);
      absxr = absxi;
    }
  } else if (muDoubleScalarIsNaN(x->re) || muDoubleScalarIsNaN(x->im)) {
    absxi = rtNaN;
    absxr = rtNaN;
  } else if (muDoubleScalarIsInf(x->im)) {
    absxi = rtInf;
    absxr = x->im;
  } else if (muDoubleScalarIsInf(x->re)) {
    if (x->re < 0.0) {
      absxi = 0.0;
      absxr = rtInf;
    } else {
      absxi = rtInf;
      absxr = 0.0;
    }
  } else {
    absxr = muDoubleScalarAbs(x->re);
    absxi = muDoubleScalarAbs(x->im);
    if ((absxr > 4.4942328371557893E+307) || (absxi > 4.4942328371557893E+307))
    {
      absxr *= 0.5;
      absxi *= 0.5;
      absxi = muDoubleScalarHypot(absxr, absxi);
      if (absxi > absxr) {
        absxi = muDoubleScalarSqrt(absxi) * muDoubleScalarSqrt(1.0 + absxr /
          absxi);
      } else {
        absxi = muDoubleScalarSqrt(absxi) * 1.4142135623730951;
      }
    } else {
      absxi = muDoubleScalarSqrt((muDoubleScalarHypot(absxr, absxi) + absxr) *
        0.5);
    }

    if (x->re > 0.0) {
      absxr = 0.5 * (x->im / absxi);
    } else {
      if (x->im < 0.0) {
        absxr = -absxi;
      } else {
        absxr = absxi;
      }

      absxi = 0.5 * (x->im / absxr);
    }
  }

  x->re = absxi;
  x->im = absxr;
}

/* End of code generation (sqrt.c) */
