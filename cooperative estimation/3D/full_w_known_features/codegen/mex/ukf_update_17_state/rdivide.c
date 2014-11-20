/*
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 * C source code generated on: Thu Nov 20 12:39:29 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_17_state.h"
#include "rdivide.h"
#include <stdio.h>

/* Function Definitions */
void rdivide(const real_T x[3], real_T y, real_T z[3])
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    z[i] = x[i] / y;
  }
}

/* End of code generation (rdivide.c) */
