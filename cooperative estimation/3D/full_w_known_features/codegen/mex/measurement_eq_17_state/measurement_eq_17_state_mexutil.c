/*
 * measurement_eq_17_state_mexutil.c
 *
 * Code generation for function 'measurement_eq_17_state_mexutil'
 *
 * C source code generated on: Thu Nov 20 11:58:35 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurement_eq_17_state.h"
#include "measurement_eq_17_state_mexutil.h"

/* Function Definitions */
void error(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", TRUE,
                        location);
}

const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m4;
  pArray = b;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m4, 1, &pArray, "message",
    TRUE, location);
}

/* End of code generation (measurement_eq_17_state_mexutil.c) */
