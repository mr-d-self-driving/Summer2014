/*
 * ukf_update_unknown_state_mexutil.h
 *
 * Code generation for function 'ukf_update_unknown_state_mexutil'
 *
 * C source code generated on: Thu Dec 11 11:40:53 2014
 *
 */

#ifndef __UKF_UPDATE_UNKNOWN_STATE_MEXUTIL_H__
#define __UKF_UPDATE_UNKNOWN_STATE_MEXUTIL_H__
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
extern void disp(const mxArray *b, emlrtMCInfo *location);
extern void emlrt_checkEscapedGlobals(void);
extern real_T emlrt_marshallIn(const mxArray *b_feval, const char_T *identifier);
#ifdef __WATCOMC__
#pragma aux emlrt_marshallIn value [8087];
#endif
extern const mxArray *emlrt_marshallOut(real_T u);
extern void emlrt_synchGlobalsFromML(void);
extern void emlrt_synchGlobalsToML(void);
extern void error(const mxArray *b, emlrtMCInfo *location);
extern const mxArray *message(const mxArray *b, emlrtMCInfo *location);
extern void warning(const mxArray *b, emlrtMCInfo *location);
#endif
/* End of code generation (ukf_update_unknown_state_mexutil.h) */
