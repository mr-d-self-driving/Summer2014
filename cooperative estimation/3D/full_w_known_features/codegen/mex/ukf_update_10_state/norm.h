/*
 * norm.h
 *
 * Code generation for function 'norm'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

#ifndef __NORM_H__
#define __NORM_H__
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
#include "ukf_update_10_state_types.h"

/* Function Declarations */
extern real_T b_norm(const emxArray_real_T *x);
#ifdef __WATCOMC__
#pragma aux b_norm value [8087];
#endif
extern real_T c_norm(const emxArray_real_T *x);
#ifdef __WATCOMC__
#pragma aux c_norm value [8087];
#endif
extern real_T d_norm(const emxArray_creal_T *x);
#ifdef __WATCOMC__
#pragma aux d_norm value [8087];
#endif
extern real_T e_norm(const real_T x[4]);
#ifdef __WATCOMC__
#pragma aux e_norm value [8087];
#endif
extern real_T norm(const emxArray_creal_T *x);
#ifdef __WATCOMC__
#pragma aux norm value [8087];
#endif
#endif
/* End of code generation (norm.h) */
