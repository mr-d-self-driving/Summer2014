/*
 * ukf_update_17_state_initialize.c
 *
 * Code generation for function 'ukf_update_17_state_initialize'
 *
 * C source code generated on: Thu Dec  4 12:26:46 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_17_state.h"
#include "ukf_update_17_state_initialize.h"
#include "ukf_update_17_state_data.h"
#include <stdio.h>

/* Named Constants */
#define b_Ts                           (0.01)

/* Function Declarations */
static void ukf_update_17_state_once(void);

/* Function Definitions */
static void ukf_update_17_state_once(void)
{
  Ts = b_Ts;
  Ts_dirty = 1U;
}

void ukf_update_17_state_initialize(emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    ukf_update_17_state_once();
  }
}

/* End of code generation (ukf_update_17_state_initialize.c) */
