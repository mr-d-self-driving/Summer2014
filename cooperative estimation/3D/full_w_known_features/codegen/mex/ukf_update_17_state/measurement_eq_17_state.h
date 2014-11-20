/*
 * measurement_eq_17_state.h
 *
 * Code generation for function 'measurement_eq_17_state'
 *
 * C source code generated on: Thu Nov 20 12:39:30 2014
 *
 */

#ifndef __MEASUREMENT_EQ_17_STATE_H__
#define __MEASUREMENT_EQ_17_STATE_H__
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
extern void measurement_eq_17_state(const emxArray_real_T *xk, const emxArray_real_T *nk, const real_T uk_data[250], const int32_T uk_size[1], emxArray_real_T *yk);
#endif
/* End of code generation (measurement_eq_17_state.h) */
