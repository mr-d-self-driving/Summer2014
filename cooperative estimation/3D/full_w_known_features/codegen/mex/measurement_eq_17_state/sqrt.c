/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 * C source code generated on: Thu Nov 20 11:58:36 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "measurement_eq_17_state.h"
#include "sqrt.h"
#include "measurement_eq_17_state_data.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 14, "sqrt",
  "/usr/local/MATLAB/MATLAB_Production_Server/R2013a/toolbox/eml/lib/matlab/elfun/sqrt.m"
};

/* Function Declarations */
static void b_eml_error(void);

/* Function Definitions */
static void b_eml_error(void)
{
  static char_T cv8[4][1] = { { 's' }, { 'q' }, { 'r' }, { 't' } };

  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &n_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, cv8);
  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
}

void b_sqrt(real_T *x)
{
  if (*x < 0.0) {
    emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
    b_eml_error();
    emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
  }

  *x = muDoubleScalarSqrt(*x);
}

/* End of code generation (sqrt.c) */
