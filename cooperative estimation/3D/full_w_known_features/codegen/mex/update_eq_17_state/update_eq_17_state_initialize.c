/*
 * update_eq_17_state_initialize.c
 *
 * Code generation for function 'update_eq_17_state_initialize'
 *
 * C source code generated on: Thu Nov 20 12:06:54 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "update_eq_17_state.h"
#include "update_eq_17_state_initialize.h"
#include "update_eq_17_state_data.h"

/* Named Constants */
#define b_Ts                           (0.01)

/* Function Declarations */
static void update_eq_17_state_once(void);

/* Function Definitions */
static void update_eq_17_state_once(void)
{
  Ts = b_Ts;
  Ts_dirty = 1U;
}

void update_eq_17_state_initialize(emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    update_eq_17_state_once();
  }
}

/* End of code generation (update_eq_17_state_initialize.c) */
