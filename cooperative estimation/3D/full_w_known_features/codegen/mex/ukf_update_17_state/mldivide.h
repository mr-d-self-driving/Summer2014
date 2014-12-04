/*
 * mldivide.h
 *
 * Code generation for function 'mldivide'
 *
 * C source code generated on: Thu Dec  4 12:26:47 2014
 *
 */

#ifndef __MLDIVIDE_H__
#define __MLDIVIDE_H__
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
#include "ukf_update_17_state_types.h"

/* Function Declarations */
extern void eml_error(void);
extern real_T eml_matlab_zlarfg(int32_T n, real_T *alpha1, emxArray_real_T *x, int32_T ix0);
#ifdef __WATCOMC__
#pragma aux eml_matlab_zlarfg value [8087];
#endif
extern void eml_xscal(int32_T n, real_T a, emxArray_real_T *x, int32_T ix0);
extern int32_T ilazlc(int32_T m, int32_T n, const emxArray_real_T *A, int32_T ia0, int32_T lda);
extern void mldivide(const emxArray_real_T *A, const emxArray_real_T *B, emxArray_real_T *Y);
#endif
/* End of code generation (mldivide.h) */
