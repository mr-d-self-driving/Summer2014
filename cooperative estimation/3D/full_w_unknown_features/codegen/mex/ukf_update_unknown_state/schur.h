/*
 * schur.h
 *
 * Code generation for function 'schur'
 *
 * C source code generated on: Tue Dec  9 10:58:58 2014
 *
 */

#ifndef __SCHUR_H__
#define __SCHUR_H__
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
extern void schur(const emxArray_real_T *A, emxArray_creal_T *V, emxArray_creal_T *T);
#endif
/* End of code generation (schur.h) */
