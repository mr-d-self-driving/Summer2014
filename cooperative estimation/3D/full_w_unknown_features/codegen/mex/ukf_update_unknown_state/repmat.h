/*
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 * C source code generated on: Tue Dec  9 10:58:59 2014
 *
 */

#ifndef __REPMAT_H__
#define __REPMAT_H__
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
extern void repmat(const real_T a_data[1001], const int32_T a_size[2], real_T m, emxArray_real_T *b);
#endif
/* End of code generation (repmat.h) */
