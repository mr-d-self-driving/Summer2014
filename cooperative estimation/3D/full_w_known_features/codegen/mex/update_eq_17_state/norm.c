/*
 * norm.c
 *
 * Code generation for function 'norm'
 *
 * C source code generated on: Thu Nov 20 12:06:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "update_eq_17_state.h"
#include "norm.h"

/* Function Definitions */
real_T norm(const real_T x[4])
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 4; k++) {
    absxk = muDoubleScalarAbs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

/* End of code generation (norm.c) */
