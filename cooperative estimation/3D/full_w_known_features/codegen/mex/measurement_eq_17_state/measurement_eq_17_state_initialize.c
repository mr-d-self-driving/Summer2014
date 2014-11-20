/*
 * measurement_eq_17_state_initialize.c
 *
 * Code generation for function 'measurement_eq_17_state_initialize'
 *
 * C source code generated on: Thu Nov 20 11:58:35 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurement_eq_17_state.h"
#include "measurement_eq_17_state_initialize.h"
#include "measurement_eq_17_state_data.h"

/* Function Definitions */
void measurement_eq_17_state_initialize(emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (measurement_eq_17_state_initialize.c) */
