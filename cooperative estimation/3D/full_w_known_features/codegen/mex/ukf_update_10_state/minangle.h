/*
 * minangle.h
 *
 * Code generation for function 'minangle'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

#ifndef __MINANGLE_H__
#define __MINANGLE_H__
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
extern void check_forloop_overflow_error(void);
extern void minangle(emxArray_real_T *x1, const emxArray_real_T *x2);
#endif
/* End of code generation (minangle.h) */
