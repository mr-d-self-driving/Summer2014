/*
 * ukf_update_17_state.h
 *
 * Code generation for function 'ukf_update_17_state'
 *
 * C source code generated on: Thu Dec  4 12:26:46 2014
 *
 */

#ifndef __UKF_UPDATE_17_STATE_H__
#define __UKF_UPDATE_17_STATE_H__
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
extern void ukf_update_17_state(const real_T xk_data[25], const int32_T xk_size[1], const real_T Pxk_data[625], const int32_T Pxk_size[2], const real_T Pvk_data[625], const int32_T Pvk_size[2], const emxArray_real_T *Pnk, const real_T uk_data[250], const int32_T uk_size[1], const real_T ytilde_data[250], const int32_T ytilde_size[1], real_T alpha, real_T xnew_data[25], int32_T xnew_size[1], real_T Pnew_data[625], int32_T Pnew_size[2]);
#endif
/* End of code generation (ukf_update_17_state.h) */
