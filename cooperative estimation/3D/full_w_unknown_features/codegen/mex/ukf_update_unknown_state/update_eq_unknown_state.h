/*
 * update_eq_unknown_state.h
 *
 * Code generation for function 'update_eq_unknown_state'
 *
 * C source code generated on: Thu Dec 11 11:40:54 2014
 *
 */

#ifndef __UPDATE_EQ_UNKNOWN_STATE_H__
#define __UPDATE_EQ_UNKNOWN_STATE_H__
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
extern void update_eq_unknown_state(const emxArray_real_T *xk, const emxArray_real_T *vk, const real_T uk_data[100], const int32_T uk_size[1], emxArray_real_T *xkPlus);
#endif
/* End of code generation (update_eq_unknown_state.h) */
