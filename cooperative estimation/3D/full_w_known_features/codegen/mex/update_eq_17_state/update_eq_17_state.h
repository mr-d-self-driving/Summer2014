/*
 * update_eq_17_state.h
 *
 * Code generation for function 'update_eq_17_state'
 *
 * C source code generated on: Thu Nov 20 12:06:54 2014
 *
 */

#ifndef __UPDATE_EQ_17_STATE_H__
#define __UPDATE_EQ_17_STATE_H__
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
#include "update_eq_17_state_types.h"

/* Function Declarations */
extern void update_eq_17_state(const real_T xk_data[6250], const int32_T xk_size[2], const emxArray_real_T *vk, const real_T uk_data[250], const int32_T uk_size[1], real_T xkPlus_data[6250], int32_T xkPlus_size[2]);
#endif
/* End of code generation (update_eq_17_state.h) */
