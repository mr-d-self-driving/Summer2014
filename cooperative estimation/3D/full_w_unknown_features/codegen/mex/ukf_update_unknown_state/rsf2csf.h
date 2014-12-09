/*
 * rsf2csf.h
 *
 * Code generation for function 'rsf2csf'
 *
 * C source code generated on: Tue Dec  9 10:58:59 2014
 *
 */

#ifndef __RSF2CSF_H__
#define __RSF2CSF_H__
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
extern void rsf2csf(const emxArray_real_T *Ur, const emxArray_real_T *Tr, emxArray_creal_T *U, emxArray_creal_T *T);
#endif
/* End of code generation (rsf2csf.h) */
