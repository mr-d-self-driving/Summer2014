/*
 * ukf_update_unknown_state_terminate.c
 *
 * Code generation for function 'ukf_update_unknown_state_terminate'
 *
 * C source code generated on: Tue Dec  9 10:58:58 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "ukf_update_unknown_state_terminate.h"
#include <stdio.h>

/* Function Definitions */
void ukf_update_unknown_state_atexit(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void ukf_update_unknown_state_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (ukf_update_unknown_state_terminate.c) */
