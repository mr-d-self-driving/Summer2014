/*
 * measurement_eq_17_state_terminate.c
 *
 * Code generation for function 'measurement_eq_17_state_terminate'
 *
 * C source code generated on: Thu Nov 20 11:58:35 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurement_eq_17_state.h"
#include "measurement_eq_17_state_terminate.h"

/* Function Definitions */
void measurement_eq_17_state_atexit(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void measurement_eq_17_state_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (measurement_eq_17_state_terminate.c) */
