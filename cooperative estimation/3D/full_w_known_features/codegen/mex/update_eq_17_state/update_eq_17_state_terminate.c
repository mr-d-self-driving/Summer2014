/*
 * update_eq_17_state_terminate.c
 *
 * Code generation for function 'update_eq_17_state_terminate'
 *
 * C source code generated on: Thu Nov 20 12:06:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "update_eq_17_state.h"
#include "update_eq_17_state_terminate.h"

/* Function Definitions */
void update_eq_17_state_atexit(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void update_eq_17_state_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (update_eq_17_state_terminate.c) */
