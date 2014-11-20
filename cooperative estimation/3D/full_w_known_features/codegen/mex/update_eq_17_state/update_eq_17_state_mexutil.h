/*
 * update_eq_17_state_mexutil.h
 *
 * Code generation for function 'update_eq_17_state_mexutil'
 *
 * C source code generated on: Thu Nov 20 12:06:54 2014
 *
 */

#ifndef __UPDATE_EQ_17_STATE_MEXUTIL_H__
#define __UPDATE_EQ_17_STATE_MEXUTIL_H__
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
extern void emlrt_checkEscapedGlobals(void);
extern const mxArray *emlrt_marshallOut(real_T u);
extern void emlrt_synchGlobalsFromML(void);
extern void emlrt_synchGlobalsToML(void);
extern real_T g_emlrt_marshallIn(const mxArray *c_Ts, const char_T *identifier);
#ifdef __WATCOMC__
#pragma aux g_emlrt_marshallIn value [8087];
#endif
#endif
/* End of code generation (update_eq_17_state_mexutil.h) */
