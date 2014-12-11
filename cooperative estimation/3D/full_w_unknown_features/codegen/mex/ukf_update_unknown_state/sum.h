/*
 * sum.h
 *
 * Code generation for function 'sum'
 *
 * C source code generated on: Thu Dec 11 11:40:54 2014
 *
 */

#ifndef __SUM_H__
#define __SUM_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "ukf_update_unknown_state_types.h"

/* Function Declarations */
extern real_T b_sum(const real_T x[3]);
#ifdef __WATCOMC__
#pragma aux b_sum value [8087];
#endif
extern void sum(const emxArray_real_T *x, emxArray_real_T *y);
#endif
/* End of code generation (sum.h) */
