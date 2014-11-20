/*
 * power.c
 *
 * Code generation for function 'power'
 *
 * C source code generated on: Thu Nov 20 11:58:36 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurement_eq_17_state.h"
#include "power.h"

/* Function Definitions */
void b_power(const real_T a[2], real_T y[2])
{
  int32_T k;
  for (k = 0; k < 2; k++) {
    y[k] = a[k] * a[k];
  }
}

void power(const real_T a[3], real_T y[3])
{
  int32_T k;
  for (k = 0; k < 3; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
