/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 * C source code generated on: Tue Dec  9 10:58:58 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "abs.h"
#include "ukf_update_unknown_state_emxutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo hb_emlrtRTEI = { 16, 5, "abs",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elfun/abs.m"
};

/* Function Definitions */
void b_abs(const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T unnamed_idx_0;
  int32_T k;
  unnamed_idx_0 = (uint32_T)x->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &hb_emlrtRTEI);
  for (k = 0; k < x->size[0]; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
