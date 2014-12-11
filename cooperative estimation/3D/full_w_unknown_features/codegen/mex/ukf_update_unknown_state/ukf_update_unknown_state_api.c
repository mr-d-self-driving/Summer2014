/*
 * ukf_update_unknown_state_api.c
 *
 * Code generation for function 'ukf_update_unknown_state_api'
 *
 * C source code generated on: Thu Dec 11 11:40:55 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "ukf_update_unknown_state_api.h"
#include "ukf_update_unknown_state_emxutil.h"
#include "fprintf.h"
#include "ukf_update_unknown_state_mexutil.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo sb_emlrtRTEI = { 1, 1, "ukf_update_unknown_state_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(ResolvedFunctionInfo u[567]);
static void b_info_helper(ResolvedFunctionInfo info[567]);
static const mxArray *c_emlrt_marshallOut(real_T u_data[200], int32_T u_size[1]);
static void c_info_helper(ResolvedFunctionInfo info[567]);
static const mxArray *d_emlrt_marshallOut(emxArray_real_T *u);
static void d_info_helper(ResolvedFunctionInfo info[567]);
static void e_emlrt_marshallIn(const mxArray *xk, const char_T *identifier,
  real_T (**y_data)[200], int32_T y_size[1]);
static void e_info_helper(ResolvedFunctionInfo info[567]);
static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T (**y_data)[200], int32_T y_size[1]);
static void f_info_helper(ResolvedFunctionInfo info[567]);
static void g_emlrt_marshallIn(const mxArray *Pxk, const char_T *identifier,
  emxArray_real_T *y);
static void g_info_helper(ResolvedFunctionInfo info[567]);
static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static void h_info_helper(ResolvedFunctionInfo info[567]);
static void i_emlrt_marshallIn(const mxArray *Pvk, const char_T *identifier,
  emxArray_real_T *y);
static void i_info_helper(ResolvedFunctionInfo info[567]);
static void info_helper(ResolvedFunctionInfo info[567]);
static void j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static void k_emlrt_marshallIn(const mxArray *uk, const char_T *identifier,
  real_T (**y_data)[100], int32_T y_size[1]);
static void l_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T (**y_data)[100], int32_T y_size[1]);
static void o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T (**ret_data)[200], int32_T ret_size[1]);
static void p_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static void q_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static void r_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T (**ret_data)[100], int32_T ret_size[1]);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(ResolvedFunctionInfo u[567])
{
  const mxArray *y;
  int32_T iv104[1];
  int32_T i8;
  ResolvedFunctionInfo *r74;
  const char * b_u;
  const mxArray *b_y;
  const mxArray *m17;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  uint32_T c_u;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  y = NULL;
  iv104[0] = 567;
  emlrtAssign(&y, mxCreateStructArray(1, iv104, 0, NULL));
  for (i8 = 0; i8 < 567; i8++) {
    r74 = &u[i8];
    b_u = r74->context;
    b_y = NULL;
    m17 = mxCreateString(b_u);
    emlrtAssign(&b_y, m17);
    emlrtAddField(y, b_y, "context", i8);
    b_u = r74->name;
    c_y = NULL;
    m17 = mxCreateString(b_u);
    emlrtAssign(&c_y, m17);
    emlrtAddField(y, c_y, "name", i8);
    b_u = r74->dominantType;
    d_y = NULL;
    m17 = mxCreateString(b_u);
    emlrtAssign(&d_y, m17);
    emlrtAddField(y, d_y, "dominantType", i8);
    b_u = r74->resolved;
    e_y = NULL;
    m17 = mxCreateString(b_u);
    emlrtAssign(&e_y, m17);
    emlrtAddField(y, e_y, "resolved", i8);
    c_u = r74->fileTimeLo;
    f_y = NULL;
    m17 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m17) = c_u;
    emlrtAssign(&f_y, m17);
    emlrtAddField(y, f_y, "fileTimeLo", i8);
    c_u = r74->fileTimeHi;
    g_y = NULL;
    m17 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m17) = c_u;
    emlrtAssign(&g_y, m17);
    emlrtAddField(y, g_y, "fileTimeHi", i8);
    c_u = r74->mFileTimeLo;
    h_y = NULL;
    m17 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m17) = c_u;
    emlrtAssign(&h_y, m17);
    emlrtAddField(y, h_y, "mFileTimeLo", i8);
    c_u = r74->mFileTimeHi;
    i_y = NULL;
    m17 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m17) = c_u;
    emlrtAssign(&i_y, m17);
    emlrtAddField(y, i_y, "mFileTimeHi", i8);
  }

  return y;
}

static void b_info_helper(ResolvedFunctionInfo info[567])
{
  info[64].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[64].name = "schur";
  info[64].dominantType = "double";
  info[64].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/schur.m";
  info[64].fileTimeLo = 1305343202U;
  info[64].fileTimeHi = 0U;
  info[64].mFileTimeLo = 0U;
  info[64].mFileTimeHi = 0U;
  info[65].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/schur.m";
  info[65].name = "eml_index_class";
  info[65].dominantType = "";
  info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[65].fileTimeLo = 1323195778U;
  info[65].fileTimeHi = 0U;
  info[65].mFileTimeLo = 0U;
  info[65].mFileTimeHi = 0U;
  info[66].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/schur.m";
  info[66].name = "eml_xgehrd";
  info[66].dominantType = "double";
  info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgehrd.m";
  info[66].fileTimeLo = 1286844004U;
  info[66].fileTimeHi = 0U;
  info[66].mFileTimeLo = 0U;
  info[66].mFileTimeHi = 0U;
  info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgehrd.m";
  info[67].name = "eml_lapack_xgehrd";
  info[67].dominantType = "double";
  info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgehrd.m";
  info[67].fileTimeLo = 1286844008U;
  info[67].fileTimeHi = 0U;
  info[67].mFileTimeLo = 0U;
  info[67].mFileTimeHi = 0U;
  info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgehrd.m";
  info[68].name = "eml_matlab_zgehrd";
  info[68].dominantType = "double";
  info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[68].fileTimeLo = 1286844016U;
  info[68].fileTimeHi = 0U;
  info[68].mFileTimeLo = 0U;
  info[68].mFileTimeHi = 0U;
  info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[69].name = "eml_index_class";
  info[69].dominantType = "";
  info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[69].fileTimeLo = 1323195778U;
  info[69].fileTimeHi = 0U;
  info[69].mFileTimeLo = 0U;
  info[69].mFileTimeHi = 0U;
  info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[70].name = "eml_index_minus";
  info[70].dominantType = "double";
  info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[70].fileTimeLo = 1286843978U;
  info[70].fileTimeHi = 0U;
  info[70].mFileTimeLo = 0U;
  info[70].mFileTimeHi = 0U;
  info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[71].name = "eml_scalar_eg";
  info[71].dominantType = "double";
  info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[71].fileTimeLo = 1286843996U;
  info[71].fileTimeHi = 0U;
  info[71].mFileTimeLo = 0U;
  info[71].mFileTimeHi = 0U;
  info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[72].name = "eml_int_forloop_overflow_check";
  info[72].dominantType = "";
  info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[72].fileTimeLo = 1346535540U;
  info[72].fileTimeHi = 0U;
  info[72].mFileTimeLo = 0U;
  info[72].mFileTimeHi = 0U;
  info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[73].name = "eml_index_plus";
  info[73].dominantType = "double";
  info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[73].fileTimeLo = 1286843978U;
  info[73].fileTimeHi = 0U;
  info[73].mFileTimeLo = 0U;
  info[73].mFileTimeHi = 0U;
  info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[74].name = "eml_index_times";
  info[74].dominantType = "coder.internal.indexInt";
  info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[74].fileTimeLo = 1286843980U;
  info[74].fileTimeHi = 0U;
  info[74].mFileTimeLo = 0U;
  info[74].mFileTimeHi = 0U;
  info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[75].name = "min";
  info[75].dominantType = "coder.internal.indexInt";
  info[75].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[75].fileTimeLo = 1311280518U;
  info[75].fileTimeHi = 0U;
  info[75].mFileTimeLo = 0U;
  info[75].mFileTimeHi = 0U;
  info[76].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[76].name = "eml_min_or_max";
  info[76].dominantType = "char";
  info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  info[76].fileTimeLo = 1334096690U;
  info[76].fileTimeHi = 0U;
  info[76].mFileTimeLo = 0U;
  info[76].mFileTimeHi = 0U;
  info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[77].name = "eml_scalar_eg";
  info[77].dominantType = "coder.internal.indexInt";
  info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[77].fileTimeLo = 1286843996U;
  info[77].fileTimeHi = 0U;
  info[77].mFileTimeLo = 0U;
  info[77].mFileTimeHi = 0U;
  info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[78].name = "eml_scalexp_alloc";
  info[78].dominantType = "coder.internal.indexInt";
  info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[78].fileTimeLo = 1352450060U;
  info[78].fileTimeHi = 0U;
  info[78].mFileTimeLo = 0U;
  info[78].mFileTimeHi = 0U;
  info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[79].name = "eml_index_class";
  info[79].dominantType = "";
  info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[79].fileTimeLo = 1323195778U;
  info[79].fileTimeHi = 0U;
  info[79].mFileTimeLo = 0U;
  info[79].mFileTimeHi = 0U;
  info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  info[80].name = "eml_scalar_eg";
  info[80].dominantType = "coder.internal.indexInt";
  info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[80].fileTimeLo = 1286843996U;
  info[80].fileTimeHi = 0U;
  info[80].mFileTimeLo = 0U;
  info[80].mFileTimeHi = 0U;
  info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[81].name = "eml_index_plus";
  info[81].dominantType = "coder.internal.indexInt";
  info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[81].fileTimeLo = 1286843978U;
  info[81].fileTimeHi = 0U;
  info[81].mFileTimeLo = 0U;
  info[81].mFileTimeHi = 0U;
  info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[82].name = "eml_index_minus";
  info[82].dominantType = "coder.internal.indexInt";
  info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[82].fileTimeLo = 1286843978U;
  info[82].fileTimeHi = 0U;
  info[82].mFileTimeLo = 0U;
  info[82].mFileTimeHi = 0U;
  info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[83].name = "eml_matlab_zlarfg";
  info[83].dominantType = "double";
  info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[83].fileTimeLo = 1286844022U;
  info[83].fileTimeHi = 0U;
  info[83].mFileTimeLo = 0U;
  info[83].mFileTimeHi = 0U;
  info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[84].name = "eml_scalar_eg";
  info[84].dominantType = "double";
  info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[84].fileTimeLo = 1286843996U;
  info[84].fileTimeHi = 0U;
  info[84].mFileTimeLo = 0U;
  info[84].mFileTimeHi = 0U;
  info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[85].name = "eml_xnrm2";
  info[85].dominantType = "double";
  info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  info[85].fileTimeLo = 1299101976U;
  info[85].fileTimeHi = 0U;
  info[85].mFileTimeLo = 0U;
  info[85].mFileTimeHi = 0U;
  info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  info[86].name = "eml_blas_inline";
  info[86].dominantType = "";
  info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[86].fileTimeLo = 1299101968U;
  info[86].fileTimeHi = 0U;
  info[86].mFileTimeLo = 0U;
  info[86].mFileTimeHi = 0U;
  info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  info[87].name = "eml_index_class";
  info[87].dominantType = "";
  info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[87].fileTimeLo = 1323195778U;
  info[87].fileTimeHi = 0U;
  info[87].mFileTimeLo = 0U;
  info[87].mFileTimeHi = 0U;
  info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  info[88].name = "eml_refblas_xnrm2";
  info[88].dominantType = "double";
  info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  info[88].fileTimeLo = 1299101984U;
  info[88].fileTimeHi = 0U;
  info[88].mFileTimeLo = 0U;
  info[88].mFileTimeHi = 0U;
  info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  info[89].name = "abs";
  info[89].dominantType = "double";
  info[89].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[89].fileTimeLo = 1343855566U;
  info[89].fileTimeHi = 0U;
  info[89].mFileTimeLo = 0U;
  info[89].mFileTimeHi = 0U;
  info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  info[90].name = "realmin";
  info[90].dominantType = "char";
  info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  info[90].fileTimeLo = 1307676442U;
  info[90].fileTimeHi = 0U;
  info[90].mFileTimeLo = 0U;
  info[90].mFileTimeHi = 0U;
  info[91].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  info[91].name = "eml_realmin";
  info[91].dominantType = "char";
  info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  info[91].fileTimeLo = 1307676444U;
  info[91].fileTimeHi = 0U;
  info[91].mFileTimeLo = 0U;
  info[91].mFileTimeHi = 0U;
  info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  info[92].name = "eml_index_class";
  info[92].dominantType = "";
  info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[92].fileTimeLo = 1323195778U;
  info[92].fileTimeHi = 0U;
  info[92].mFileTimeLo = 0U;
  info[92].mFileTimeHi = 0U;
  info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  info[93].name = "eml_index_minus";
  info[93].dominantType = "double";
  info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[93].fileTimeLo = 1286843978U;
  info[93].fileTimeHi = 0U;
  info[93].mFileTimeLo = 0U;
  info[93].mFileTimeHi = 0U;
  info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  info[94].name = "eml_index_times";
  info[94].dominantType = "coder.internal.indexInt";
  info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[94].fileTimeLo = 1286843980U;
  info[94].fileTimeHi = 0U;
  info[94].mFileTimeLo = 0U;
  info[94].mFileTimeHi = 0U;
  info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  info[95].name = "eml_index_plus";
  info[95].dominantType = "coder.internal.indexInt";
  info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[95].fileTimeLo = 1286843978U;
  info[95].fileTimeHi = 0U;
  info[95].mFileTimeLo = 0U;
  info[95].mFileTimeHi = 0U;
  info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  info[96].name = "eml_int_forloop_overflow_check";
  info[96].dominantType = "";
  info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[96].fileTimeLo = 1346535540U;
  info[96].fileTimeHi = 0U;
  info[96].mFileTimeLo = 0U;
  info[96].mFileTimeHi = 0U;
  info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[97].name = "eml_dlapy2";
  info[97].dominantType = "double";
  info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  info[97].fileTimeLo = 1350435854U;
  info[97].fileTimeHi = 0U;
  info[97].mFileTimeLo = 0U;
  info[97].mFileTimeHi = 0U;
  info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[98].name = "realmin";
  info[98].dominantType = "char";
  info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  info[98].fileTimeLo = 1307676442U;
  info[98].fileTimeHi = 0U;
  info[98].mFileTimeLo = 0U;
  info[98].mFileTimeHi = 0U;
  info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[99].name = "eps";
  info[99].dominantType = "char";
  info[99].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[99].fileTimeLo = 1326753196U;
  info[99].fileTimeHi = 0U;
  info[99].mFileTimeLo = 0U;
  info[99].mFileTimeHi = 0U;
  info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[100].name = "abs";
  info[100].dominantType = "double";
  info[100].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[100].fileTimeLo = 1343855566U;
  info[100].fileTimeHi = 0U;
  info[100].mFileTimeLo = 0U;
  info[100].mFileTimeHi = 0U;
  info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[101].name = "eml_index_class";
  info[101].dominantType = "";
  info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[101].fileTimeLo = 1323195778U;
  info[101].fileTimeHi = 0U;
  info[101].mFileTimeLo = 0U;
  info[101].mFileTimeHi = 0U;
  info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[102].name = "eml_index_plus";
  info[102].dominantType = "double";
  info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[102].fileTimeLo = 1286843978U;
  info[102].fileTimeHi = 0U;
  info[102].mFileTimeLo = 0U;
  info[102].mFileTimeHi = 0U;
  info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[103].name = "eml_xscal";
  info[103].dominantType = "double";
  info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  info[103].fileTimeLo = 1299101976U;
  info[103].fileTimeHi = 0U;
  info[103].mFileTimeLo = 0U;
  info[103].mFileTimeHi = 0U;
  info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  info[104].name = "eml_blas_inline";
  info[104].dominantType = "";
  info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[104].fileTimeLo = 1299101968U;
  info[104].fileTimeHi = 0U;
  info[104].mFileTimeLo = 0U;
  info[104].mFileTimeHi = 0U;
  info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  info[105].name = "eml_index_class";
  info[105].dominantType = "";
  info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[105].fileTimeLo = 1323195778U;
  info[105].fileTimeHi = 0U;
  info[105].mFileTimeLo = 0U;
  info[105].mFileTimeHi = 0U;
  info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  info[106].name = "eml_scalar_eg";
  info[106].dominantType = "double";
  info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[106].fileTimeLo = 1286843996U;
  info[106].fileTimeHi = 0U;
  info[106].mFileTimeLo = 0U;
  info[106].mFileTimeHi = 0U;
  info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  info[107].name = "eml_refblas_xscal";
  info[107].dominantType = "double";
  info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  info[107].fileTimeLo = 1299101984U;
  info[107].fileTimeHi = 0U;
  info[107].mFileTimeLo = 0U;
  info[107].mFileTimeHi = 0U;
  info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  info[108].name = "eml_index_class";
  info[108].dominantType = "";
  info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[108].fileTimeLo = 1323195778U;
  info[108].fileTimeHi = 0U;
  info[108].mFileTimeLo = 0U;
  info[108].mFileTimeHi = 0U;
  info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  info[109].name = "eml_index_minus";
  info[109].dominantType = "double";
  info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[109].fileTimeLo = 1286843978U;
  info[109].fileTimeHi = 0U;
  info[109].mFileTimeLo = 0U;
  info[109].mFileTimeHi = 0U;
  info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  info[110].name = "eml_index_times";
  info[110].dominantType = "coder.internal.indexInt";
  info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[110].fileTimeLo = 1286843980U;
  info[110].fileTimeHi = 0U;
  info[110].mFileTimeLo = 0U;
  info[110].mFileTimeHi = 0U;
  info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  info[111].name = "eml_index_plus";
  info[111].dominantType = "coder.internal.indexInt";
  info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[111].fileTimeLo = 1286843978U;
  info[111].fileTimeHi = 0U;
  info[111].mFileTimeLo = 0U;
  info[111].mFileTimeHi = 0U;
  info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  info[112].name = "eml_int_forloop_overflow_check";
  info[112].dominantType = "";
  info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[112].fileTimeLo = 1346535540U;
  info[112].fileTimeHi = 0U;
  info[112].mFileTimeLo = 0U;
  info[112].mFileTimeHi = 0U;
  info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[113].name = "mtimes";
  info[113].dominantType = "double";
  info[113].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[113].fileTimeLo = 1289544892U;
  info[113].fileTimeHi = 0U;
  info[113].mFileTimeLo = 0U;
  info[113].mFileTimeHi = 0U;
  info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[114].name = "eml_div";
  info[114].dominantType = "double";
  info[114].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  info[114].fileTimeLo = 1313373010U;
  info[114].fileTimeHi = 0U;
  info[114].mFileTimeLo = 0U;
  info[114].mFileTimeHi = 0U;
  info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[115].name = "eml_int_forloop_overflow_check";
  info[115].dominantType = "";
  info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[115].fileTimeLo = 1346535540U;
  info[115].fileTimeHi = 0U;
  info[115].mFileTimeLo = 0U;
  info[115].mFileTimeHi = 0U;
  info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgehrd.m";
  info[116].name = "eml_matlab_zlarf";
  info[116].dominantType = "char";
  info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[116].fileTimeLo = 1286844022U;
  info[116].fileTimeHi = 0U;
  info[116].mFileTimeLo = 0U;
  info[116].mFileTimeHi = 0U;
  info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[117].name = "eml_scalar_eg";
  info[117].dominantType = "double";
  info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[117].fileTimeLo = 1286843996U;
  info[117].fileTimeHi = 0U;
  info[117].mFileTimeLo = 0U;
  info[117].mFileTimeHi = 0U;
  info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[118].name = "eml_index_class";
  info[118].dominantType = "";
  info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[118].fileTimeLo = 1323195778U;
  info[118].fileTimeHi = 0U;
  info[118].mFileTimeLo = 0U;
  info[118].mFileTimeHi = 0U;
  info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[119].name = "isequal";
  info[119].dominantType = "double";
  info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[119].fileTimeLo = 1286843958U;
  info[119].fileTimeHi = 0U;
  info[119].mFileTimeLo = 0U;
  info[119].mFileTimeHi = 0U;
  info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[120].name = "eml_isequal_core";
  info[120].dominantType = "double";
  info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  info[120].fileTimeLo = 1286843986U;
  info[120].fileTimeHi = 0U;
  info[120].mFileTimeLo = 0U;
  info[120].mFileTimeHi = 0U;
  info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[121].name = "eml_index_minus";
  info[121].dominantType = "double";
  info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[121].fileTimeLo = 1286843978U;
  info[121].fileTimeHi = 0U;
  info[121].mFileTimeLo = 0U;
  info[121].mFileTimeHi = 0U;
  info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[122].name = "eml_index_times";
  info[122].dominantType = "coder.internal.indexInt";
  info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[122].fileTimeLo = 1286843980U;
  info[122].fileTimeHi = 0U;
  info[122].mFileTimeLo = 0U;
  info[122].mFileTimeHi = 0U;
  info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[123].name = "eml_index_plus";
  info[123].dominantType = "coder.internal.indexInt";
  info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[123].fileTimeLo = 1286843978U;
  info[123].fileTimeHi = 0U;
  info[123].mFileTimeLo = 0U;
  info[123].mFileTimeHi = 0U;
  info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[124].name = "eml_index_minus";
  info[124].dominantType = "coder.internal.indexInt";
  info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[124].fileTimeLo = 1286843978U;
  info[124].fileTimeHi = 0U;
  info[124].mFileTimeLo = 0U;
  info[124].mFileTimeHi = 0U;
  info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlr";
  info[125].name = "eml_index_class";
  info[125].dominantType = "";
  info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[125].fileTimeLo = 1323195778U;
  info[125].fileTimeHi = 0U;
  info[125].mFileTimeLo = 0U;
  info[125].mFileTimeHi = 0U;
  info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlr";
  info[126].name = "eml_index_minus";
  info[126].dominantType = "double";
  info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[126].fileTimeLo = 1286843978U;
  info[126].fileTimeHi = 0U;
  info[126].mFileTimeLo = 0U;
  info[126].mFileTimeHi = 0U;
  info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlr";
  info[127].name = "eml_index_plus";
  info[127].dominantType = "coder.internal.indexInt";
  info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[127].fileTimeLo = 1286843978U;
  info[127].fileTimeHi = 0U;
  info[127].mFileTimeLo = 0U;
  info[127].mFileTimeHi = 0U;
}

static const mxArray *c_emlrt_marshallOut(real_T u_data[200], int32_T u_size[1])
{
  const mxArray *y;
  static const int32_T iv105[1] = { 0 };

  const mxArray *m18;
  y = NULL;
  m18 = mxCreateNumericArray(1, (int32_T *)&iv105, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m18, (void *)u_data);
  mxSetDimensions((mxArray *)m18, u_size, 1);
  emlrtAssign(&y, m18);
  return y;
}

static void c_info_helper(ResolvedFunctionInfo info[567])
{
  info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlr";
  info[128].name = "eml_index_times";
  info[128].dominantType = "coder.internal.indexInt";
  info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[128].fileTimeLo = 1286843980U;
  info[128].fileTimeHi = 0U;
  info[128].mFileTimeLo = 0U;
  info[128].mFileTimeHi = 0U;
  info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlr";
  info[129].name = "eml_int_forloop_overflow_check";
  info[129].dominantType = "";
  info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[129].fileTimeLo = 1346535540U;
  info[129].fileTimeHi = 0U;
  info[129].mFileTimeLo = 0U;
  info[129].mFileTimeHi = 0U;
  info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  info[130].name = "intmin";
  info[130].dominantType = "char";
  info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  info[130].fileTimeLo = 1311280518U;
  info[130].fileTimeHi = 0U;
  info[130].mFileTimeLo = 0U;
  info[130].mFileTimeHi = 0U;
  info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[131].name = "eml_xgemv";
  info[131].dominantType = "char";
  info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m";
  info[131].fileTimeLo = 1299101974U;
  info[131].fileTimeHi = 0U;
  info[131].mFileTimeLo = 0U;
  info[131].mFileTimeHi = 0U;
  info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m";
  info[132].name = "eml_blas_inline";
  info[132].dominantType = "";
  info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[132].fileTimeLo = 1299101968U;
  info[132].fileTimeHi = 0U;
  info[132].mFileTimeLo = 0U;
  info[132].mFileTimeHi = 0U;
  info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  info[133].name = "eml_index_class";
  info[133].dominantType = "";
  info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[133].fileTimeLo = 1323195778U;
  info[133].fileTimeHi = 0U;
  info[133].mFileTimeLo = 0U;
  info[133].mFileTimeHi = 0U;
  info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  info[134].name = "eml_scalar_eg";
  info[134].dominantType = "double";
  info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[134].fileTimeLo = 1286843996U;
  info[134].fileTimeHi = 0U;
  info[134].mFileTimeLo = 0U;
  info[134].mFileTimeHi = 0U;
  info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  info[135].name = "eml_refblas_xgemv";
  info[135].dominantType = "char";
  info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  info[135].fileTimeLo = 1299101976U;
  info[135].fileTimeHi = 0U;
  info[135].mFileTimeLo = 0U;
  info[135].mFileTimeHi = 0U;
  info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  info[136].name = "eml_index_minus";
  info[136].dominantType = "double";
  info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[136].fileTimeLo = 1286843978U;
  info[136].fileTimeHi = 0U;
  info[136].mFileTimeLo = 0U;
  info[136].mFileTimeHi = 0U;
  info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  info[137].name = "eml_index_class";
  info[137].dominantType = "";
  info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[137].fileTimeLo = 1323195778U;
  info[137].fileTimeHi = 0U;
  info[137].mFileTimeLo = 0U;
  info[137].mFileTimeHi = 0U;
  info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  info[138].name = "eml_index_times";
  info[138].dominantType = "coder.internal.indexInt";
  info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[138].fileTimeLo = 1286843980U;
  info[138].fileTimeHi = 0U;
  info[138].mFileTimeLo = 0U;
  info[138].mFileTimeHi = 0U;
  info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  info[139].name = "eml_index_plus";
  info[139].dominantType = "coder.internal.indexInt";
  info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[139].fileTimeLo = 1286843978U;
  info[139].fileTimeHi = 0U;
  info[139].mFileTimeLo = 0U;
  info[139].mFileTimeHi = 0U;
  info[140].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  info[140].name = "eml_int_forloop_overflow_check";
  info[140].dominantType = "";
  info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[140].fileTimeLo = 1346535540U;
  info[140].fileTimeHi = 0U;
  info[140].mFileTimeLo = 0U;
  info[140].mFileTimeHi = 0U;
  info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[141].name = "eml_xgerc";
  info[141].dominantType = "double";
  info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  info[141].fileTimeLo = 1299101974U;
  info[141].fileTimeHi = 0U;
  info[141].mFileTimeLo = 0U;
  info[141].mFileTimeHi = 0U;
  info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  info[142].name = "eml_blas_inline";
  info[142].dominantType = "";
  info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[142].fileTimeLo = 1299101968U;
  info[142].fileTimeHi = 0U;
  info[142].mFileTimeLo = 0U;
  info[142].mFileTimeHi = 0U;
  info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  info[143].name = "eml_xger";
  info[143].dominantType = "double";
  info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  info[143].fileTimeLo = 1299101974U;
  info[143].fileTimeHi = 0U;
  info[143].mFileTimeLo = 0U;
  info[143].mFileTimeHi = 0U;
  info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  info[144].name = "eml_blas_inline";
  info[144].dominantType = "";
  info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[144].fileTimeLo = 1299101968U;
  info[144].fileTimeHi = 0U;
  info[144].mFileTimeLo = 0U;
  info[144].mFileTimeHi = 0U;
  info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  info[145].name = "intmax";
  info[145].dominantType = "char";
  info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[145].fileTimeLo = 1311280516U;
  info[145].fileTimeHi = 0U;
  info[145].mFileTimeLo = 0U;
  info[145].mFileTimeHi = 0U;
  info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  info[146].name = "min";
  info[146].dominantType = "double";
  info[146].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[146].fileTimeLo = 1311280518U;
  info[146].fileTimeHi = 0U;
  info[146].mFileTimeLo = 0U;
  info[146].mFileTimeHi = 0U;
  info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[147].name = "eml_scalar_eg";
  info[147].dominantType = "double";
  info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[147].fileTimeLo = 1286843996U;
  info[147].fileTimeHi = 0U;
  info[147].mFileTimeLo = 0U;
  info[147].mFileTimeHi = 0U;
  info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[148].name = "eml_scalexp_alloc";
  info[148].dominantType = "double";
  info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[148].fileTimeLo = 1352450060U;
  info[148].fileTimeHi = 0U;
  info[148].mFileTimeLo = 0U;
  info[148].mFileTimeHi = 0U;
  info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  info[149].name = "eml_scalar_eg";
  info[149].dominantType = "double";
  info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[149].fileTimeLo = 1286843996U;
  info[149].fileTimeHi = 0U;
  info[149].mFileTimeLo = 0U;
  info[149].mFileTimeHi = 0U;
  info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  info[150].name = "mtimes";
  info[150].dominantType = "double";
  info[150].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[150].fileTimeLo = 1289544892U;
  info[150].fileTimeHi = 0U;
  info[150].mFileTimeLo = 0U;
  info[150].mFileTimeHi = 0U;
  info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  info[151].name = "eml_index_class";
  info[151].dominantType = "";
  info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[151].fileTimeLo = 1323195778U;
  info[151].fileTimeHi = 0U;
  info[151].mFileTimeLo = 0U;
  info[151].mFileTimeHi = 0U;
  info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  info[152].name = "eml_refblas_xger";
  info[152].dominantType = "double";
  info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  info[152].fileTimeLo = 1299101976U;
  info[152].fileTimeHi = 0U;
  info[152].mFileTimeLo = 0U;
  info[152].mFileTimeHi = 0U;
  info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  info[153].name = "eml_refblas_xgerx";
  info[153].dominantType = "char";
  info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  info[153].fileTimeLo = 1299101978U;
  info[153].fileTimeHi = 0U;
  info[153].mFileTimeLo = 0U;
  info[153].mFileTimeHi = 0U;
  info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  info[154].name = "eml_index_class";
  info[154].dominantType = "";
  info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[154].fileTimeLo = 1323195778U;
  info[154].fileTimeHi = 0U;
  info[154].mFileTimeLo = 0U;
  info[154].mFileTimeHi = 0U;
  info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  info[155].name = "abs";
  info[155].dominantType = "coder.internal.indexInt";
  info[155].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[155].fileTimeLo = 1343855566U;
  info[155].fileTimeHi = 0U;
  info[155].mFileTimeLo = 0U;
  info[155].mFileTimeHi = 0U;
  info[156].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[156].name = "eml_scalar_abs";
  info[156].dominantType = "coder.internal.indexInt";
  info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  info[156].fileTimeLo = 1286843912U;
  info[156].fileTimeHi = 0U;
  info[156].mFileTimeLo = 0U;
  info[156].mFileTimeHi = 0U;
  info[157].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  info[157].name = "eml_index_minus";
  info[157].dominantType = "double";
  info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[157].fileTimeLo = 1286843978U;
  info[157].fileTimeHi = 0U;
  info[157].mFileTimeLo = 0U;
  info[157].mFileTimeHi = 0U;
  info[158].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  info[158].name = "eml_int_forloop_overflow_check";
  info[158].dominantType = "";
  info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[158].fileTimeLo = 1346535540U;
  info[158].fileTimeHi = 0U;
  info[158].mFileTimeLo = 0U;
  info[158].mFileTimeHi = 0U;
  info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  info[159].name = "eml_index_plus";
  info[159].dominantType = "double";
  info[159].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[159].fileTimeLo = 1286843978U;
  info[159].fileTimeHi = 0U;
  info[159].mFileTimeLo = 0U;
  info[159].mFileTimeHi = 0U;
  info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  info[160].name = "eml_index_plus";
  info[160].dominantType = "coder.internal.indexInt";
  info[160].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[160].fileTimeLo = 1286843978U;
  info[160].fileTimeHi = 0U;
  info[160].mFileTimeLo = 0U;
  info[160].mFileTimeHi = 0U;
  info[161].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  info[161].name = "eml_index_class";
  info[161].dominantType = "";
  info[161].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[161].fileTimeLo = 1323195778U;
  info[161].fileTimeHi = 0U;
  info[161].mFileTimeLo = 0U;
  info[161].mFileTimeHi = 0U;
  info[162].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  info[162].name = "eml_index_minus";
  info[162].dominantType = "double";
  info[162].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[162].fileTimeLo = 1286843978U;
  info[162].fileTimeHi = 0U;
  info[162].mFileTimeLo = 0U;
  info[162].mFileTimeHi = 0U;
  info[163].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  info[163].name = "eml_index_times";
  info[163].dominantType = "coder.internal.indexInt";
  info[163].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[163].fileTimeLo = 1286843980U;
  info[163].fileTimeHi = 0U;
  info[163].mFileTimeLo = 0U;
  info[163].mFileTimeHi = 0U;
  info[164].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  info[164].name = "eml_index_plus";
  info[164].dominantType = "coder.internal.indexInt";
  info[164].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[164].fileTimeLo = 1286843978U;
  info[164].fileTimeHi = 0U;
  info[164].mFileTimeLo = 0U;
  info[164].mFileTimeHi = 0U;
  info[165].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  info[165].name = "eml_int_forloop_overflow_check";
  info[165].dominantType = "";
  info[165].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[165].fileTimeLo = 1346535540U;
  info[165].fileTimeHi = 0U;
  info[165].mFileTimeLo = 0U;
  info[165].mFileTimeHi = 0U;
  info[166].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  info[166].name = "eml_scalar_eg";
  info[166].dominantType = "double";
  info[166].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[166].fileTimeLo = 1286843996U;
  info[166].fileTimeHi = 0U;
  info[166].mFileTimeLo = 0U;
  info[166].mFileTimeHi = 0U;
  info[167].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  info[167].name = "eml_conjtimes";
  info[167].dominantType = "double";
  info[167].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  info[167].fileTimeLo = 1286843896U;
  info[167].fileTimeHi = 0U;
  info[167].mFileTimeLo = 0U;
  info[167].mFileTimeHi = 0U;
  info[168].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/schur.m";
  info[168].name = "eml_xunghr";
  info[168].dominantType = "double";
  info[168].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xunghr.m";
  info[168].fileTimeLo = 1286844008U;
  info[168].fileTimeHi = 0U;
  info[168].mFileTimeLo = 0U;
  info[168].mFileTimeHi = 0U;
  info[169].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xunghr.m";
  info[169].name = "eml_lapack_xunghr";
  info[169].dominantType = "double";
  info[169].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xunghr.m";
  info[169].fileTimeLo = 1286844012U;
  info[169].fileTimeHi = 0U;
  info[169].mFileTimeLo = 0U;
  info[169].mFileTimeHi = 0U;
  info[170].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xunghr.m";
  info[170].name = "eml_matlab_zunghr";
  info[170].dominantType = "double";
  info[170].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[170].fileTimeLo = 1286844026U;
  info[170].fileTimeHi = 0U;
  info[170].mFileTimeLo = 0U;
  info[170].mFileTimeHi = 0U;
  info[171].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[171].name = "eml_index_class";
  info[171].dominantType = "";
  info[171].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[171].fileTimeLo = 1323195778U;
  info[171].fileTimeHi = 0U;
  info[171].mFileTimeLo = 0U;
  info[171].mFileTimeHi = 0U;
  info[172].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[172].name = "eml_index_minus";
  info[172].dominantType = "coder.internal.indexInt";
  info[172].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[172].fileTimeLo = 1286843978U;
  info[172].fileTimeHi = 0U;
  info[172].mFileTimeLo = 0U;
  info[172].mFileTimeHi = 0U;
  info[173].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[173].name = "eml_index_minus";
  info[173].dominantType = "double";
  info[173].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[173].fileTimeLo = 1286843978U;
  info[173].fileTimeHi = 0U;
  info[173].mFileTimeLo = 0U;
  info[173].mFileTimeHi = 0U;
  info[174].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[174].name = "eml_index_plus";
  info[174].dominantType = "double";
  info[174].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[174].fileTimeLo = 1286843978U;
  info[174].fileTimeHi = 0U;
  info[174].mFileTimeLo = 0U;
  info[174].mFileTimeHi = 0U;
  info[175].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[175].name = "eml_int_forloop_overflow_check";
  info[175].dominantType = "";
  info[175].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[175].fileTimeLo = 1346535540U;
  info[175].fileTimeHi = 0U;
  info[175].mFileTimeLo = 0U;
  info[175].mFileTimeHi = 0U;
  info[176].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[176].name = "eml_index_times";
  info[176].dominantType = "coder.internal.indexInt";
  info[176].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[176].fileTimeLo = 1286843980U;
  info[176].fileTimeHi = 0U;
  info[176].mFileTimeLo = 0U;
  info[176].mFileTimeHi = 0U;
  info[177].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[177].name = "eml_index_plus";
  info[177].dominantType = "coder.internal.indexInt";
  info[177].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[177].fileTimeLo = 1286843978U;
  info[177].fileTimeHi = 0U;
  info[177].mFileTimeLo = 0U;
  info[177].mFileTimeHi = 0U;
  info[178].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zunghr.m";
  info[178].name = "eml_matlab_zungqr";
  info[178].dominantType = "double";
  info[178].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[178].fileTimeLo = 1286844026U;
  info[178].fileTimeHi = 0U;
  info[178].mFileTimeLo = 0U;
  info[178].mFileTimeHi = 0U;
  info[179].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[179].name = "eml_index_class";
  info[179].dominantType = "";
  info[179].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[179].fileTimeLo = 1323195778U;
  info[179].fileTimeHi = 0U;
  info[179].mFileTimeLo = 0U;
  info[179].mFileTimeHi = 0U;
  info[180].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[180].name = "eml_index_minus";
  info[180].dominantType = "double";
  info[180].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[180].fileTimeLo = 1286843978U;
  info[180].fileTimeHi = 0U;
  info[180].mFileTimeLo = 0U;
  info[180].mFileTimeHi = 0U;
  info[181].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[181].name = "eml_int_forloop_overflow_check";
  info[181].dominantType = "";
  info[181].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[181].fileTimeLo = 1346535540U;
  info[181].fileTimeHi = 0U;
  info[181].mFileTimeLo = 0U;
  info[181].mFileTimeHi = 0U;
  info[182].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[182].name = "eml_index_times";
  info[182].dominantType = "coder.internal.indexInt";
  info[182].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[182].fileTimeLo = 1286843980U;
  info[182].fileTimeHi = 0U;
  info[182].mFileTimeLo = 0U;
  info[182].mFileTimeHi = 0U;
  info[183].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[183].name = "eml_index_plus";
  info[183].dominantType = "coder.internal.indexInt";
  info[183].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[183].fileTimeLo = 1286843978U;
  info[183].fileTimeHi = 0U;
  info[183].mFileTimeLo = 0U;
  info[183].mFileTimeHi = 0U;
  info[184].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[184].name = "eml_scalar_eg";
  info[184].dominantType = "double";
  info[184].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[184].fileTimeLo = 1286843996U;
  info[184].fileTimeHi = 0U;
  info[184].mFileTimeLo = 0U;
  info[184].mFileTimeHi = 0U;
  info[185].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[185].name = "eml_index_minus";
  info[185].dominantType = "coder.internal.indexInt";
  info[185].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[185].fileTimeLo = 1286843978U;
  info[185].fileTimeHi = 0U;
  info[185].mFileTimeLo = 0U;
  info[185].mFileTimeHi = 0U;
  info[186].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[186].name = "eml_index_plus";
  info[186].dominantType = "double";
  info[186].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[186].fileTimeLo = 1286843978U;
  info[186].fileTimeHi = 0U;
  info[186].mFileTimeLo = 0U;
  info[186].mFileTimeHi = 0U;
  info[187].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[187].name = "eml_matlab_zlarf";
  info[187].dominantType = "char";
  info[187].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[187].fileTimeLo = 1286844022U;
  info[187].fileTimeHi = 0U;
  info[187].mFileTimeLo = 0U;
  info[187].mFileTimeHi = 0U;
  info[188].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zungqr.m";
  info[188].name = "eml_xscal";
  info[188].dominantType = "double";
  info[188].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  info[188].fileTimeLo = 1299101976U;
  info[188].fileTimeHi = 0U;
  info[188].mFileTimeLo = 0U;
  info[188].mFileTimeHi = 0U;
  info[189].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/schur.m";
  info[189].name = "eml_xhseqr";
  info[189].dominantType = "double";
  info[189].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xhseqr.m";
  info[189].fileTimeLo = 1286844008U;
  info[189].fileTimeHi = 0U;
  info[189].mFileTimeLo = 0U;
  info[189].mFileTimeHi = 0U;
  info[190].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xhseqr.m";
  info[190].name = "eml_lapack_xhseqr";
  info[190].dominantType = "double";
  info[190].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xhseqr.m";
  info[190].fileTimeLo = 1286844012U;
  info[190].fileTimeHi = 0U;
  info[190].mFileTimeLo = 0U;
  info[190].mFileTimeHi = 0U;
  info[191].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xhseqr.m";
  info[191].name = "eml_matlab_dhseqr";
  info[191].dominantType = "double";
  info[191].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m";
  info[191].fileTimeLo = 1286844014U;
  info[191].fileTimeHi = 0U;
  info[191].mFileTimeLo = 0U;
  info[191].mFileTimeHi = 0U;
}

static const mxArray *d_emlrt_marshallOut(emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv106[2] = { 0, 0 };

  const mxArray *m19;
  y = NULL;
  m19 = mxCreateNumericArray(2, (int32_T *)&iv106, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m19, (void *)u->data);
  mxSetDimensions((mxArray *)m19, u->size, 2);
  emlrtAssign(&y, m19);
  return y;
}

static void d_info_helper(ResolvedFunctionInfo info[567])
{
  info[192].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[192].name = "eml_index_class";
  info[192].dominantType = "";
  info[192].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[192].fileTimeLo = 1323195778U;
  info[192].fileTimeHi = 0U;
  info[192].mFileTimeLo = 0U;
  info[192].mFileTimeHi = 0U;
  info[193].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[193].name = "eml_index_minus";
  info[193].dominantType = "double";
  info[193].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[193].fileTimeLo = 1286843978U;
  info[193].fileTimeHi = 0U;
  info[193].mFileTimeLo = 0U;
  info[193].mFileTimeHi = 0U;
  info[194].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[194].name = "eml_int_forloop_overflow_check";
  info[194].dominantType = "";
  info[194].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[194].fileTimeLo = 1346535540U;
  info[194].fileTimeHi = 0U;
  info[194].mFileTimeLo = 0U;
  info[194].mFileTimeHi = 0U;
  info[195].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[195].name = "eml_index_plus";
  info[195].dominantType = "double";
  info[195].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[195].fileTimeLo = 1286843978U;
  info[195].fileTimeHi = 0U;
  info[195].mFileTimeLo = 0U;
  info[195].mFileTimeHi = 0U;
  info[196].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[196].name = "eml_index_minus";
  info[196].dominantType = "coder.internal.indexInt";
  info[196].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[196].fileTimeLo = 1286843978U;
  info[196].fileTimeHi = 0U;
  info[196].mFileTimeLo = 0U;
  info[196].mFileTimeHi = 0U;
  info[197].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[197].name = "realmin";
  info[197].dominantType = "char";
  info[197].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  info[197].fileTimeLo = 1307676442U;
  info[197].fileTimeHi = 0U;
  info[197].mFileTimeLo = 0U;
  info[197].mFileTimeHi = 0U;
  info[198].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[198].name = "eps";
  info[198].dominantType = "char";
  info[198].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[198].fileTimeLo = 1326753196U;
  info[198].fileTimeHi = 0U;
  info[198].mFileTimeLo = 0U;
  info[198].mFileTimeHi = 0U;
  info[199].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[199].name = "mrdivide";
  info[199].dominantType = "double";
  info[199].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[199].fileTimeLo = 1357976748U;
  info[199].fileTimeHi = 0U;
  info[199].mFileTimeLo = 1319755166U;
  info[199].mFileTimeHi = 0U;
  info[200].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[200].name = "rdivide";
  info[200].dominantType = "double";
  info[200].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[200].fileTimeLo = 1346535588U;
  info[200].fileTimeHi = 0U;
  info[200].mFileTimeLo = 0U;
  info[200].mFileTimeHi = 0U;
  info[201].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[201].name = "eml_scalexp_compatible";
  info[201].dominantType = "double";
  info[201].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  info[201].fileTimeLo = 1286843996U;
  info[201].fileTimeHi = 0U;
  info[201].mFileTimeLo = 0U;
  info[201].mFileTimeHi = 0U;
  info[202].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[202].name = "eml_div";
  info[202].dominantType = "double";
  info[202].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  info[202].fileTimeLo = 1313373010U;
  info[202].fileTimeHi = 0U;
  info[202].mFileTimeLo = 0U;
  info[202].mFileTimeHi = 0U;
  info[203].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[203].name = "mtimes";
  info[203].dominantType = "double";
  info[203].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[203].fileTimeLo = 1289544892U;
  info[203].fileTimeHi = 0U;
  info[203].mFileTimeLo = 0U;
  info[203].mFileTimeHi = 0U;
  info[204].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[204].name = "abs";
  info[204].dominantType = "double";
  info[204].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[204].fileTimeLo = 1343855566U;
  info[204].fileTimeHi = 0U;
  info[204].mFileTimeLo = 0U;
  info[204].mFileTimeHi = 0U;
  info[205].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[205].name = "max";
  info[205].dominantType = "double";
  info[205].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  info[205].fileTimeLo = 1311280516U;
  info[205].fileTimeHi = 0U;
  info[205].mFileTimeLo = 0U;
  info[205].mFileTimeHi = 0U;
  info[206].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  info[206].name = "eml_min_or_max";
  info[206].dominantType = "char";
  info[206].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  info[206].fileTimeLo = 1334096690U;
  info[206].fileTimeHi = 0U;
  info[206].mFileTimeLo = 0U;
  info[206].mFileTimeHi = 0U;
  info[207].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[207].name = "sqrt";
  info[207].dominantType = "double";
  info[207].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[207].fileTimeLo = 1343855586U;
  info[207].fileTimeHi = 0U;
  info[207].mFileTimeLo = 0U;
  info[207].mFileTimeHi = 0U;
  info[208].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[208].name = "min";
  info[208].dominantType = "coder.internal.indexInt";
  info[208].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[208].fileTimeLo = 1311280518U;
  info[208].fileTimeHi = 0U;
  info[208].mFileTimeLo = 0U;
  info[208].mFileTimeHi = 0U;
  info[209].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[209].name = "eml_index_times";
  info[209].dominantType = "coder.internal.indexInt";
  info[209].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[209].fileTimeLo = 1286843980U;
  info[209].fileTimeHi = 0U;
  info[209].mFileTimeLo = 0U;
  info[209].mFileTimeHi = 0U;
  info[210].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[210].name = "eml_index_plus";
  info[210].dominantType = "coder.internal.indexInt";
  info[210].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[210].fileTimeLo = 1286843978U;
  info[210].fileTimeHi = 0U;
  info[210].mFileTimeLo = 0U;
  info[210].mFileTimeHi = 0U;
  info[211].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[211].name = "eml_matlab_zlarfg";
  info[211].dominantType = "double";
  info[211].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[211].fileTimeLo = 1286844022U;
  info[211].fileTimeHi = 0U;
  info[211].mFileTimeLo = 0U;
  info[211].mFileTimeHi = 0U;
  info[212].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  info[212].name = "length";
  info[212].dominantType = "double";
  info[212].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  info[212].fileTimeLo = 1303171406U;
  info[212].fileTimeHi = 0U;
  info[212].mFileTimeLo = 0U;
  info[212].mFileTimeHi = 0U;
  info[213].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m!below_threshold";
  info[213].name = "length";
  info[213].dominantType = "double";
  info[213].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  info[213].fileTimeLo = 1303171406U;
  info[213].fileTimeHi = 0U;
  info[213].mFileTimeLo = 0U;
  info[213].mFileTimeHi = 0U;
  info[214].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[214].name = "eml_dlanv2";
  info[214].dominantType = "double";
  info[214].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[214].fileTimeLo = 1286843898U;
  info[214].fileTimeHi = 0U;
  info[214].mFileTimeLo = 0U;
  info[214].mFileTimeHi = 0U;
  info[215].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[215].name = "eml_scalar_eg";
  info[215].dominantType = "double";
  info[215].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[215].fileTimeLo = 1286843996U;
  info[215].fileTimeHi = 0U;
  info[215].mFileTimeLo = 0U;
  info[215].mFileTimeHi = 0U;
  info[216].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[216].name = "mtimes";
  info[216].dominantType = "double";
  info[216].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[216].fileTimeLo = 1289544892U;
  info[216].fileTimeHi = 0U;
  info[216].mFileTimeLo = 0U;
  info[216].mFileTimeHi = 0U;
  info[217].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[217].name = "abs";
  info[217].dominantType = "double";
  info[217].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[217].fileTimeLo = 1343855566U;
  info[217].fileTimeHi = 0U;
  info[217].mFileTimeLo = 0U;
  info[217].mFileTimeHi = 0U;
  info[218].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[218].name = "max";
  info[218].dominantType = "double";
  info[218].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  info[218].fileTimeLo = 1311280516U;
  info[218].fileTimeHi = 0U;
  info[218].mFileTimeLo = 0U;
  info[218].mFileTimeHi = 0U;
  info[219].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[219].name = "min";
  info[219].dominantType = "double";
  info[219].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[219].fileTimeLo = 1311280518U;
  info[219].fileTimeHi = 0U;
  info[219].mFileTimeLo = 0U;
  info[219].mFileTimeHi = 0U;
  info[220].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[220].name = "mrdivide";
  info[220].dominantType = "double";
  info[220].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[220].fileTimeLo = 1357976748U;
  info[220].fileTimeHi = 0U;
  info[220].mFileTimeLo = 1319755166U;
  info[220].mFileTimeHi = 0U;
  info[221].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[221].name = "eps";
  info[221].dominantType = "";
  info[221].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[221].fileTimeLo = 1326753196U;
  info[221].fileTimeHi = 0U;
  info[221].mFileTimeLo = 0U;
  info[221].mFileTimeHi = 0U;
  info[222].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[222].name = "sqrt";
  info[222].dominantType = "double";
  info[222].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[222].fileTimeLo = 1343855586U;
  info[222].fileTimeHi = 0U;
  info[222].mFileTimeLo = 0U;
  info[222].mFileTimeHi = 0U;
  info[223].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[223].name = "eml_dlapy2";
  info[223].dominantType = "double";
  info[223].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  info[223].fileTimeLo = 1350435854U;
  info[223].fileTimeHi = 0U;
  info[223].mFileTimeLo = 0U;
  info[223].mFileTimeHi = 0U;
  info[224].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m!eml_dlahqr";
  info[224].name = "eml_xrot";
  info[224].dominantType = "double";
  info[224].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  info[224].fileTimeLo = 1299101976U;
  info[224].fileTimeHi = 0U;
  info[224].mFileTimeLo = 0U;
  info[224].mFileTimeHi = 0U;
  info[225].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  info[225].name = "eml_blas_inline";
  info[225].dominantType = "";
  info[225].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[225].fileTimeLo = 1299101968U;
  info[225].fileTimeHi = 0U;
  info[225].mFileTimeLo = 0U;
  info[225].mFileTimeHi = 0U;
  info[226].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  info[226].name = "eml_index_class";
  info[226].dominantType = "";
  info[226].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[226].fileTimeLo = 1323195778U;
  info[226].fileTimeHi = 0U;
  info[226].mFileTimeLo = 0U;
  info[226].mFileTimeHi = 0U;
  info[227].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  info[227].name = "eml_scalar_eg";
  info[227].dominantType = "double";
  info[227].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[227].fileTimeLo = 1286843996U;
  info[227].fileTimeHi = 0U;
  info[227].mFileTimeLo = 0U;
  info[227].mFileTimeHi = 0U;
  info[228].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  info[228].name = "eml_refblas_xrot";
  info[228].dominantType = "double";
  info[228].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  info[228].fileTimeLo = 1299101984U;
  info[228].fileTimeHi = 0U;
  info[228].mFileTimeLo = 0U;
  info[228].mFileTimeHi = 0U;
  info[229].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  info[229].name = "eml_index_class";
  info[229].dominantType = "";
  info[229].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[229].fileTimeLo = 1323195778U;
  info[229].fileTimeHi = 0U;
  info[229].mFileTimeLo = 0U;
  info[229].mFileTimeHi = 0U;
  info[230].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  info[230].name = "eml_int_forloop_overflow_check";
  info[230].dominantType = "";
  info[230].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[230].fileTimeLo = 1346535540U;
  info[230].fileTimeHi = 0U;
  info[230].mFileTimeLo = 0U;
  info[230].mFileTimeHi = 0U;
  info[231].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  info[231].name = "mtimes";
  info[231].dominantType = "double";
  info[231].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[231].fileTimeLo = 1289544892U;
  info[231].fileTimeHi = 0U;
  info[231].mFileTimeLo = 0U;
  info[231].mFileTimeHi = 0U;
  info[232].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  info[232].name = "eml_index_plus";
  info[232].dominantType = "coder.internal.indexInt";
  info[232].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[232].fileTimeLo = 1286843978U;
  info[232].fileTimeHi = 0U;
  info[232].mFileTimeLo = 0U;
  info[232].mFileTimeHi = 0U;
  info[233].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_dhseqr.m";
  info[233].name = "triu";
  info[233].dominantType = "double";
  info[233].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/triu.m";
  info[233].fileTimeLo = 1286843972U;
  info[233].fileTimeHi = 0U;
  info[233].mFileTimeLo = 0U;
  info[233].mFileTimeHi = 0U;
  info[234].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/triu.m";
  info[234].name = "eml_index_class";
  info[234].dominantType = "";
  info[234].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[234].fileTimeLo = 1323195778U;
  info[234].fileTimeHi = 0U;
  info[234].mFileTimeLo = 0U;
  info[234].mFileTimeHi = 0U;
  info[235].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/triu.m";
  info[235].name = "floor";
  info[235].dominantType = "double";
  info[235].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[235].fileTimeLo = 1343855580U;
  info[235].fileTimeHi = 0U;
  info[235].mFileTimeLo = 0U;
  info[235].mFileTimeHi = 0U;
  info[236].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/triu.m";
  info[236].name = "eml_index_minus";
  info[236].dominantType = "coder.internal.indexInt";
  info[236].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[236].fileTimeLo = 1286843978U;
  info[236].fileTimeHi = 0U;
  info[236].mFileTimeLo = 0U;
  info[236].mFileTimeHi = 0U;
  info[237].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/triu.m";
  info[237].name = "eml_index_plus";
  info[237].dominantType = "coder.internal.indexInt";
  info[237].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[237].fileTimeLo = 1286843978U;
  info[237].fileTimeHi = 0U;
  info[237].mFileTimeLo = 0U;
  info[237].mFileTimeHi = 0U;
  info[238].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/triu.m";
  info[238].name = "eml_int_forloop_overflow_check";
  info[238].dominantType = "";
  info[238].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[238].fileTimeLo = 1346535540U;
  info[238].fileTimeHi = 0U;
  info[238].mFileTimeLo = 0U;
  info[238].mFileTimeHi = 0U;
  info[239].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/schur.m";
  info[239].name = "rsf2csf";
  info[239].dominantType = "double";
  info[239].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/rsf2csf.m";
  info[239].fileTimeLo = 1286844032U;
  info[239].fileTimeHi = 0U;
  info[239].mFileTimeLo = 0U;
  info[239].mFileTimeHi = 0U;
  info[240].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/rsf2csf.m";
  info[240].name = "eml_rsf2csf";
  info[240].dominantType = "double";
  info[240].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[240].fileTimeLo = 1286843994U;
  info[240].fileTimeHi = 0U;
  info[240].mFileTimeLo = 0U;
  info[240].mFileTimeHi = 0U;
  info[241].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[241].name = "min";
  info[241].dominantType = "double";
  info[241].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[241].fileTimeLo = 1311280518U;
  info[241].fileTimeHi = 0U;
  info[241].mFileTimeLo = 0U;
  info[241].mFileTimeHi = 0U;
  info[242].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  info[242].name = "eml_const_nonsingleton_dim";
  info[242].dominantType = "double";
  info[242].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  info[242].fileTimeLo = 1286843896U;
  info[242].fileTimeHi = 0U;
  info[242].mFileTimeLo = 0U;
  info[242].mFileTimeHi = 0U;
  info[243].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  info[243].name = "eml_scalar_eg";
  info[243].dominantType = "double";
  info[243].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[243].fileTimeLo = 1286843996U;
  info[243].fileTimeHi = 0U;
  info[243].mFileTimeLo = 0U;
  info[243].mFileTimeHi = 0U;
  info[244].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  info[244].name = "eml_index_class";
  info[244].dominantType = "";
  info[244].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[244].fileTimeLo = 1323195778U;
  info[244].fileTimeHi = 0U;
  info[244].mFileTimeLo = 0U;
  info[244].mFileTimeHi = 0U;
  info[245].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[245].name = "eml_index_class";
  info[245].dominantType = "";
  info[245].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[245].fileTimeLo = 1323195778U;
  info[245].fileTimeHi = 0U;
  info[245].mFileTimeLo = 0U;
  info[245].mFileTimeHi = 0U;
  info[246].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[246].name = "isnan";
  info[246].dominantType = "double";
  info[246].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[246].fileTimeLo = 1286843960U;
  info[246].fileTimeHi = 0U;
  info[246].mFileTimeLo = 0U;
  info[246].mFileTimeHi = 0U;
  info[247].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[247].name = "eml_index_plus";
  info[247].dominantType = "coder.internal.indexInt";
  info[247].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[247].fileTimeLo = 1286843978U;
  info[247].fileTimeHi = 0U;
  info[247].mFileTimeLo = 0U;
  info[247].mFileTimeHi = 0U;
  info[248].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[248].name = "eml_int_forloop_overflow_check";
  info[248].dominantType = "";
  info[248].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[248].fileTimeLo = 1346535540U;
  info[248].fileTimeHi = 0U;
  info[248].mFileTimeLo = 0U;
  info[248].mFileTimeHi = 0U;
  info[249].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[249].name = "eml_relop";
  info[249].dominantType = "function_handle";
  info[249].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  info[249].fileTimeLo = 1342476382U;
  info[249].fileTimeHi = 0U;
  info[249].mFileTimeLo = 0U;
  info[249].mFileTimeHi = 0U;
  info[250].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[250].name = "eml_index_class";
  info[250].dominantType = "";
  info[250].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[250].fileTimeLo = 1323195778U;
  info[250].fileTimeHi = 0U;
  info[250].mFileTimeLo = 0U;
  info[250].mFileTimeHi = 0U;
  info[251].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[251].name = "eml_index_minus";
  info[251].dominantType = "double";
  info[251].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[251].fileTimeLo = 1286843978U;
  info[251].fileTimeHi = 0U;
  info[251].mFileTimeLo = 0U;
  info[251].mFileTimeHi = 0U;
  info[252].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[252].name = "eml_dlanv2";
  info[252].dominantType = "double";
  info[252].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlanv2.m";
  info[252].fileTimeLo = 1286843898U;
  info[252].fileTimeHi = 0U;
  info[252].mFileTimeLo = 0U;
  info[252].mFileTimeHi = 0U;
  info[253].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[253].name = "hypot";
  info[253].dominantType = "double";
  info[253].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m";
  info[253].fileTimeLo = 1343855580U;
  info[253].fileTimeHi = 0U;
  info[253].mFileTimeLo = 0U;
  info[253].mFileTimeHi = 0U;
  info[254].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m";
  info[254].name = "eml_scalar_eg";
  info[254].dominantType = "double";
  info[254].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[254].fileTimeLo = 1286843996U;
  info[254].fileTimeHi = 0U;
  info[254].mFileTimeLo = 0U;
  info[254].mFileTimeHi = 0U;
  info[255].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m";
  info[255].name = "eml_scalexp_alloc";
  info[255].dominantType = "double";
  info[255].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[255].fileTimeLo = 1352450060U;
  info[255].fileTimeHi = 0U;
  info[255].mFileTimeLo = 0U;
  info[255].mFileTimeHi = 0U;
}

static void e_emlrt_marshallIn(const mxArray *xk, const char_T *identifier,
  real_T (**y_data)[200], int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  f_emlrt_marshallIn(emlrtAlias(xk), &thisId, y_data, y_size);
  emlrtDestroyArray(&xk);
}

static void e_info_helper(ResolvedFunctionInfo info[567])
{
  info[256].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m";
  info[256].name = "eml_scalar_hypot";
  info[256].dominantType = "double";
  info[256].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m";
  info[256].fileTimeLo = 1286843926U;
  info[256].fileTimeHi = 0U;
  info[256].mFileTimeLo = 0U;
  info[256].mFileTimeHi = 0U;
  info[257].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m";
  info[257].name = "eml_scalar_eg";
  info[257].dominantType = "double";
  info[257].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[257].fileTimeLo = 1286843996U;
  info[257].fileTimeHi = 0U;
  info[257].mFileTimeLo = 0U;
  info[257].mFileTimeHi = 0U;
  info[258].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m";
  info[258].name = "eml_dlapy2";
  info[258].dominantType = "double";
  info[258].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  info[258].fileTimeLo = 1350435854U;
  info[258].fileTimeHi = 0U;
  info[258].mFileTimeLo = 0U;
  info[258].mFileTimeHi = 0U;
  info[259].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[259].name = "mrdivide";
  info[259].dominantType = "double";
  info[259].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[259].fileTimeLo = 1357976748U;
  info[259].fileTimeHi = 0U;
  info[259].mFileTimeLo = 1319755166U;
  info[259].mFileTimeHi = 0U;
  info[260].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  info[260].name = "eml_scalar_eg";
  info[260].dominantType = "double";
  info[260].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[260].fileTimeLo = 1286843996U;
  info[260].fileTimeHi = 0U;
  info[260].mFileTimeLo = 0U;
  info[260].mFileTimeHi = 0U;
  info[261].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  info[261].name = "eml_scalexp_alloc";
  info[261].dominantType = "double";
  info[261].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[261].fileTimeLo = 1352450060U;
  info[261].fileTimeHi = 0U;
  info[261].mFileTimeLo = 0U;
  info[261].mFileTimeHi = 0U;
  info[262].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  info[262].name = "abs";
  info[262].dominantType = "double";
  info[262].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[262].fileTimeLo = 1343855566U;
  info[262].fileTimeHi = 0U;
  info[262].mFileTimeLo = 0U;
  info[262].mFileTimeHi = 0U;
  info[263].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  info[263].name = "mtimes";
  info[263].dominantType = "double";
  info[263].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[263].fileTimeLo = 1289544892U;
  info[263].fileTimeHi = 0U;
  info[263].mFileTimeLo = 0U;
  info[263].mFileTimeHi = 0U;
  info[264].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[264].name = "eml_int_forloop_overflow_check";
  info[264].dominantType = "";
  info[264].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[264].fileTimeLo = 1346535540U;
  info[264].fileTimeHi = 0U;
  info[264].mFileTimeLo = 0U;
  info[264].mFileTimeHi = 0U;
  info[265].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[265].name = "eml_conjtimes";
  info[265].dominantType = "double";
  info[265].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  info[265].fileTimeLo = 1286843896U;
  info[265].fileTimeHi = 0U;
  info[265].mFileTimeLo = 0U;
  info[265].mFileTimeHi = 0U;
  info[266].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_rsf2csf.m";
  info[266].name = "mtimes";
  info[266].dominantType = "double";
  info[266].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[266].fileTimeLo = 1289544892U;
  info[266].fileTimeHi = 0U;
  info[266].mFileTimeLo = 0U;
  info[266].mFileTimeHi = 0U;
  info[267].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/schur.m";
  info[267].name = "eml_warning";
  info[267].dominantType = "char";
  info[267].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  info[267].fileTimeLo = 1286844002U;
  info[267].fileTimeHi = 0U;
  info[267].mFileTimeLo = 0U;
  info[267].mFileTimeHi = 0U;
  info[268].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[268].name = "eml_index_class";
  info[268].dominantType = "";
  info[268].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[268].fileTimeLo = 1323195778U;
  info[268].fileTimeHi = 0U;
  info[268].mFileTimeLo = 0U;
  info[268].mFileTimeHi = 0U;
  info[269].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[269].name = "eml_scalar_eg";
  info[269].dominantType = "double";
  info[269].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[269].fileTimeLo = 1286843996U;
  info[269].fileTimeHi = 0U;
  info[269].mFileTimeLo = 0U;
  info[269].mFileTimeHi = 0U;
  info[270].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m!isUTmatD";
  info[270].name = "eml_index_class";
  info[270].dominantType = "";
  info[270].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[270].fileTimeLo = 1323195778U;
  info[270].fileTimeHi = 0U;
  info[270].mFileTimeLo = 0U;
  info[270].mFileTimeHi = 0U;
  info[271].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m!isUTmatD";
  info[271].name = "eml_int_forloop_overflow_check";
  info[271].dominantType = "";
  info[271].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[271].fileTimeLo = 1346535540U;
  info[271].fileTimeHi = 0U;
  info[271].mFileTimeLo = 0U;
  info[271].mFileTimeHi = 0U;
  info[272].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m!isUTmatD";
  info[272].name = "eml_index_minus";
  info[272].dominantType = "double";
  info[272].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[272].fileTimeLo = 1286843978U;
  info[272].fileTimeHi = 0U;
  info[272].mFileTimeLo = 0U;
  info[272].mFileTimeHi = 0U;
  info[273].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[273].name = "eml_int_forloop_overflow_check";
  info[273].dominantType = "";
  info[273].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[273].fileTimeLo = 1346535540U;
  info[273].fileTimeHi = 0U;
  info[273].mFileTimeLo = 0U;
  info[273].mFileTimeHi = 0U;
  info[274].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[274].name = "sqrt";
  info[274].dominantType = "double";
  info[274].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[274].fileTimeLo = 1343855586U;
  info[274].fileTimeHi = 0U;
  info[274].mFileTimeLo = 0U;
  info[274].mFileTimeHi = 0U;
  info[275].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[275].name = "rdivide";
  info[275].dominantType = "double";
  info[275].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[275].fileTimeLo = 1346535588U;
  info[275].fileTimeHi = 0U;
  info[275].mFileTimeLo = 0U;
  info[275].mFileTimeHi = 0U;
  info[276].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[276].name = "isnan";
  info[276].dominantType = "double";
  info[276].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[276].fileTimeLo = 1286843960U;
  info[276].fileTimeHi = 0U;
  info[276].mFileTimeLo = 0U;
  info[276].mFileTimeHi = 0U;
  info[277].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[277].name = "eml_guarded_nan";
  info[277].dominantType = "char";
  info[277].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  info[277].fileTimeLo = 1286843976U;
  info[277].fileTimeHi = 0U;
  info[277].mFileTimeLo = 0U;
  info[277].mFileTimeHi = 0U;
  info[278].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[278].name = "isinf";
  info[278].dominantType = "double";
  info[278].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  info[278].fileTimeLo = 1286843960U;
  info[278].fileTimeHi = 0U;
  info[278].mFileTimeLo = 0U;
  info[278].mFileTimeHi = 0U;
  info[279].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[279].name = "eml_guarded_inf";
  info[279].dominantType = "char";
  info[279].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m";
  info[279].fileTimeLo = 1286843976U;
  info[279].fileTimeHi = 0U;
  info[279].mFileTimeLo = 0U;
  info[279].mFileTimeHi = 0U;
  info[280].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m";
  info[280].name = "eml_is_float_class";
  info[280].dominantType = "char";
  info[280].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  info[280].fileTimeLo = 1286843982U;
  info[280].fileTimeHi = 0U;
  info[280].mFileTimeLo = 0U;
  info[280].mFileTimeHi = 0U;
  info[281].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[281].name = "realmax";
  info[281].dominantType = "char";
  info[281].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  info[281].fileTimeLo = 1307676442U;
  info[281].fileTimeHi = 0U;
  info[281].mFileTimeLo = 0U;
  info[281].mFileTimeHi = 0U;
  info[282].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[282].name = "mrdivide";
  info[282].dominantType = "double";
  info[282].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[282].fileTimeLo = 1357976748U;
  info[282].fileTimeHi = 0U;
  info[282].mFileTimeLo = 1319755166U;
  info[282].mFileTimeHi = 0U;
  info[283].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[283].name = "mtimes";
  info[283].dominantType = "double";
  info[283].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[283].fileTimeLo = 1289544892U;
  info[283].fileTimeHi = 0U;
  info[283].mFileTimeLo = 0U;
  info[283].mFileTimeHi = 0U;
  info[284].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  info[284].name = "eml_scalar_hypot";
  info[284].dominantType = "double";
  info[284].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m";
  info[284].fileTimeLo = 1286843926U;
  info[284].fileTimeHi = 0U;
  info[284].mFileTimeLo = 0U;
  info[284].mFileTimeHi = 0U;
  info[285].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[285].name = "eml_index_minus";
  info[285].dominantType = "double";
  info[285].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[285].fileTimeLo = 1286843978U;
  info[285].fileTimeHi = 0U;
  info[285].mFileTimeLo = 0U;
  info[285].mFileTimeHi = 0U;
  info[286].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[286].name = "eml_index_plus";
  info[286].dominantType = "double";
  info[286].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[286].fileTimeLo = 1286843978U;
  info[286].fileTimeHi = 0U;
  info[286].mFileTimeLo = 0U;
  info[286].mFileTimeHi = 0U;
  info[287].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[287].name = "mtimes";
  info[287].dominantType = "double";
  info[287].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[287].fileTimeLo = 1289544892U;
  info[287].fileTimeHi = 0U;
  info[287].mFileTimeLo = 0U;
  info[287].mFileTimeHi = 0U;
  info[288].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[288].name = "mrdivide";
  info[288].dominantType = "double";
  info[288].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[288].fileTimeLo = 1357976748U;
  info[288].fileTimeHi = 0U;
  info[288].mFileTimeLo = 1319755166U;
  info[288].mFileTimeHi = 0U;
  info[289].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[289].name = "eml_index_class";
  info[289].dominantType = "";
  info[289].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[289].fileTimeLo = 1323195778U;
  info[289].fileTimeHi = 0U;
  info[289].mFileTimeLo = 0U;
  info[289].mFileTimeHi = 0U;
  info[290].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[290].name = "eml_scalar_eg";
  info[290].dominantType = "double";
  info[290].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[290].fileTimeLo = 1286843996U;
  info[290].fileTimeHi = 0U;
  info[290].mFileTimeLo = 0U;
  info[290].mFileTimeHi = 0U;
  info[291].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[291].name = "eml_xgemm";
  info[291].dominantType = "char";
  info[291].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  info[291].fileTimeLo = 1299101972U;
  info[291].fileTimeHi = 0U;
  info[291].mFileTimeLo = 0U;
  info[291].mFileTimeHi = 0U;
  info[292].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  info[292].name = "eml_blas_inline";
  info[292].dominantType = "";
  info[292].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[292].fileTimeLo = 1299101968U;
  info[292].fileTimeHi = 0U;
  info[292].mFileTimeLo = 0U;
  info[292].mFileTimeHi = 0U;
  info[293].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  info[293].name = "eml_index_class";
  info[293].dominantType = "";
  info[293].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[293].fileTimeLo = 1323195778U;
  info[293].fileTimeHi = 0U;
  info[293].mFileTimeLo = 0U;
  info[293].mFileTimeHi = 0U;
  info[294].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  info[294].name = "eml_scalar_eg";
  info[294].dominantType = "double";
  info[294].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[294].fileTimeLo = 1286843996U;
  info[294].fileTimeHi = 0U;
  info[294].mFileTimeLo = 0U;
  info[294].mFileTimeHi = 0U;
  info[295].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  info[295].name = "eml_refblas_xgemm";
  info[295].dominantType = "char";
  info[295].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[295].fileTimeLo = 1299101974U;
  info[295].fileTimeHi = 0U;
  info[295].mFileTimeLo = 0U;
  info[295].mFileTimeHi = 0U;
  info[296].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[296].name = "eml_index_minus";
  info[296].dominantType = "double";
  info[296].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[296].fileTimeLo = 1286843978U;
  info[296].fileTimeHi = 0U;
  info[296].mFileTimeLo = 0U;
  info[296].mFileTimeHi = 0U;
  info[297].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[297].name = "eml_index_class";
  info[297].dominantType = "";
  info[297].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[297].fileTimeLo = 1323195778U;
  info[297].fileTimeHi = 0U;
  info[297].mFileTimeLo = 0U;
  info[297].mFileTimeHi = 0U;
  info[298].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[298].name = "eml_scalar_eg";
  info[298].dominantType = "double";
  info[298].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[298].fileTimeLo = 1286843996U;
  info[298].fileTimeHi = 0U;
  info[298].mFileTimeLo = 0U;
  info[298].mFileTimeHi = 0U;
  info[299].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[299].name = "eml_index_times";
  info[299].dominantType = "coder.internal.indexInt";
  info[299].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[299].fileTimeLo = 1286843980U;
  info[299].fileTimeHi = 0U;
  info[299].mFileTimeLo = 0U;
  info[299].mFileTimeHi = 0U;
  info[300].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[300].name = "eml_index_plus";
  info[300].dominantType = "coder.internal.indexInt";
  info[300].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[300].fileTimeLo = 1286843978U;
  info[300].fileTimeHi = 0U;
  info[300].mFileTimeLo = 0U;
  info[300].mFileTimeHi = 0U;
  info[301].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[301].name = "eml_int_forloop_overflow_check";
  info[301].dominantType = "";
  info[301].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[301].fileTimeLo = 1346535540U;
  info[301].fileTimeHi = 0U;
  info[301].mFileTimeLo = 0U;
  info[301].mFileTimeHi = 0U;
  info[302].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[302].name = "eml_index_plus";
  info[302].dominantType = "double";
  info[302].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[302].fileTimeLo = 1286843978U;
  info[302].fileTimeHi = 0U;
  info[302].mFileTimeLo = 0U;
  info[302].mFileTimeHi = 0U;
  info[303].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[303].name = "norm";
  info[303].dominantType = "double";
  info[303].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  info[303].fileTimeLo = 1336547294U;
  info[303].fileTimeHi = 0U;
  info[303].mFileTimeLo = 0U;
  info[303].mFileTimeHi = 0U;
  info[304].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  info[304].name = "eml_index_class";
  info[304].dominantType = "";
  info[304].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[304].fileTimeLo = 1323195778U;
  info[304].fileTimeHi = 0U;
  info[304].mFileTimeLo = 0U;
  info[304].mFileTimeHi = 0U;
  info[305].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  info[305].name = "eml_xnrm2";
  info[305].dominantType = "double";
  info[305].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  info[305].fileTimeLo = 1299101976U;
  info[305].fileTimeHi = 0U;
  info[305].mFileTimeLo = 0U;
  info[305].mFileTimeHi = 0U;
  info[306].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  info[306].name = "eml_dlapy2";
  info[306].dominantType = "double";
  info[306].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  info[306].fileTimeLo = 1350435854U;
  info[306].fileTimeHi = 0U;
  info[306].mFileTimeLo = 0U;
  info[306].mFileTimeHi = 0U;
  info[307].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  info[307].name = "coder.internal.indexIntRelop";
  info[307].dominantType = "";
  info[307].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[307].fileTimeLo = 1326753522U;
  info[307].fileTimeHi = 0U;
  info[307].mFileTimeLo = 0U;
  info[307].mFileTimeHi = 0U;
  info[308].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  info[308].name = "eml_xnrm2";
  info[308].dominantType = "double";
  info[308].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  info[308].fileTimeLo = 1299101976U;
  info[308].fileTimeHi = 0U;
  info[308].mFileTimeLo = 0U;
  info[308].mFileTimeHi = 0U;
  info[309].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  info[309].name = "abs";
  info[309].dominantType = "double";
  info[309].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[309].fileTimeLo = 1343855566U;
  info[309].fileTimeHi = 0U;
  info[309].mFileTimeLo = 0U;
  info[309].mFileTimeHi = 0U;
  info[310].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  info[310].name = "abs";
  info[310].dominantType = "double";
  info[310].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[310].fileTimeLo = 1343855566U;
  info[310].fileTimeHi = 0U;
  info[310].mFileTimeLo = 0U;
  info[310].mFileTimeHi = 0U;
  info[311].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  info[311].name = "isnan";
  info[311].dominantType = "double";
  info[311].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[311].fileTimeLo = 1286843960U;
  info[311].fileTimeHi = 0U;
  info[311].mFileTimeLo = 0U;
  info[311].mFileTimeHi = 0U;
  info[312].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  info[312].name = "eml_guarded_nan";
  info[312].dominantType = "char";
  info[312].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  info[312].fileTimeLo = 1286843976U;
  info[312].fileTimeHi = 0U;
  info[312].mFileTimeLo = 0U;
  info[312].mFileTimeHi = 0U;
  info[313].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[313].name = "eps";
  info[313].dominantType = "";
  info[313].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[313].fileTimeLo = 1326753196U;
  info[313].fileTimeHi = 0U;
  info[313].mFileTimeLo = 0U;
  info[313].mFileTimeHi = 0U;
  info[314].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[314].name = "abs";
  info[314].dominantType = "double";
  info[314].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[314].fileTimeLo = 1343855566U;
  info[314].fileTimeHi = 0U;
  info[314].mFileTimeLo = 0U;
  info[314].mFileTimeHi = 0U;
  info[315].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[315].name = "fprintf";
  info[315].dominantType = "char";
  info[315].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/fprintf.m";
  info[315].fileTimeLo = 1354865984U;
  info[315].fileTimeHi = 0U;
  info[315].mFileTimeLo = 0U;
  info[315].mFileTimeHi = 0U;
  info[316].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/fprintf.m";
  info[316].name = "isequal";
  info[316].dominantType = "char";
  info[316].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[316].fileTimeLo = 1286843958U;
  info[316].fileTimeHi = 0U;
  info[316].mFileTimeLo = 0U;
  info[316].mFileTimeHi = 0U;
  info[317].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[317].name = "eml_isequal_core";
  info[317].dominantType = "char";
  info[317].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  info[317].fileTimeLo = 1286843986U;
  info[317].fileTimeHi = 0U;
  info[317].mFileTimeLo = 0U;
  info[317].mFileTimeHi = 0U;
  info[318].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  info[318].name = "isnan";
  info[318].dominantType = "char";
  info[318].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[318].fileTimeLo = 1286843960U;
  info[318].fileTimeHi = 0U;
  info[318].mFileTimeLo = 0U;
  info[318].mFileTimeHi = 0U;
  info[319].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/fprintf.m";
  info[319].name = "fprintf";
  info[319].dominantType = "double";
  info[319].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/fprintf.m";
  info[319].fileTimeLo = 1354865984U;
  info[319].fileTimeHi = 0U;
  info[319].mFileTimeLo = 0U;
  info[319].mFileTimeHi = 0U;
}

static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T (**y_data)[200], int32_T y_size[1])
{
  o_emlrt_marshallIn(emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void f_info_helper(ResolvedFunctionInfo info[567])
{
  info[320].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/fprintf.m!validate_arguments";
  info[320].name = "coder.internal.assert";
  info[320].dominantType = "char";
  info[320].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m";
  info[320].fileTimeLo = 1334097138U;
  info[320].fileTimeHi = 0U;
  info[320].mFileTimeLo = 0U;
  info[320].mFileTimeHi = 0U;
  info[321].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/fprintf.m!check_type";
  info[321].name = "coder.internal.assert";
  info[321].dominantType = "char";
  info[321].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m";
  info[321].fileTimeLo = 1334097138U;
  info[321].fileTimeHi = 0U;
  info[321].mFileTimeLo = 0U;
  info[321].mFileTimeHi = 0U;
  info[322].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[322].name = "update_eq_unknown_state";
  info[322].dominantType = "double";
  info[322].resolved =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m";
  info[322].fileTimeLo = 1418080399U;
  info[322].fileTimeHi = 0U;
  info[322].mFileTimeLo = 0U;
  info[322].mFileTimeHi = 0U;
  info[323].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m";
  info[323].name = "attparsilentmex";
  info[323].dominantType = "double";
  info[323].resolved =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/attparsilentmex.m";
  info[323].fileTimeLo = 1416505945U;
  info[323].fileTimeHi = 0U;
  info[323].mFileTimeLo = 0U;
  info[323].mFileTimeHi = 0U;
  info[324].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/attparsilentmex.m";
  info[324].name = "floor";
  info[324].dominantType = "double";
  info[324].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[324].fileTimeLo = 1343855580U;
  info[324].fileTimeHi = 0U;
  info[324].mFileTimeLo = 0U;
  info[324].mFileTimeHi = 0U;
  info[325].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/attparsilentmex.m";
  info[325].name = "mod";
  info[325].dominantType = "double";
  info[325].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  info[325].fileTimeLo = 1343855582U;
  info[325].fileTimeHi = 0U;
  info[325].mFileTimeLo = 0U;
  info[325].mFileTimeHi = 0U;
  info[326].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  info[326].name = "eml_scalar_eg";
  info[326].dominantType = "double";
  info[326].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[326].fileTimeLo = 1286843996U;
  info[326].fileTimeHi = 0U;
  info[326].mFileTimeLo = 0U;
  info[326].mFileTimeHi = 0U;
  info[327].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  info[327].name = "eml_scalexp_alloc";
  info[327].dominantType = "double";
  info[327].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[327].fileTimeLo = 1352450060U;
  info[327].fileTimeHi = 0U;
  info[327].mFileTimeLo = 0U;
  info[327].mFileTimeHi = 0U;
  info[328].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  info[328].name = "eml_scalar_eg";
  info[328].dominantType = "double";
  info[328].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[328].fileTimeLo = 1286843996U;
  info[328].fileTimeHi = 0U;
  info[328].mFileTimeLo = 0U;
  info[328].mFileTimeHi = 0U;
  info[329].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  info[329].name = "eml_scalar_floor";
  info[329].dominantType = "double";
  info[329].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  info[329].fileTimeLo = 1286843926U;
  info[329].fileTimeHi = 0U;
  info[329].mFileTimeLo = 0U;
  info[329].mFileTimeHi = 0U;
  info[330].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  info[330].name = "eml_scalar_round";
  info[330].dominantType = "double";
  info[330].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  info[330].fileTimeLo = 1307676438U;
  info[330].fileTimeHi = 0U;
  info[330].mFileTimeLo = 0U;
  info[330].mFileTimeHi = 0U;
  info[331].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  info[331].name = "eml_scalar_abs";
  info[331].dominantType = "double";
  info[331].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  info[331].fileTimeLo = 1286843912U;
  info[331].fileTimeHi = 0U;
  info[331].mFileTimeLo = 0U;
  info[331].mFileTimeHi = 0U;
  info[332].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  info[332].name = "eps";
  info[332].dominantType = "char";
  info[332].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[332].fileTimeLo = 1326753196U;
  info[332].fileTimeHi = 0U;
  info[332].mFileTimeLo = 0U;
  info[332].mFileTimeHi = 0U;
  info[333].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  info[333].name = "mtimes";
  info[333].dominantType = "double";
  info[333].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[333].fileTimeLo = 1289544892U;
  info[333].fileTimeHi = 0U;
  info[333].mFileTimeLo = 0U;
  info[333].mFileTimeHi = 0U;
  info[334].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/attparsilentmex.m";
  info[334].name = "error";
  info[334].dominantType = "char";
  info[334].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/error.m";
  info[334].fileTimeLo = 1319755166U;
  info[334].fileTimeHi = 0U;
  info[334].mFileTimeLo = 0U;
  info[334].mFileTimeHi = 0U;
  info[335].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/attparsilentmex.m";
  info[335].name = "length";
  info[335].dominantType = "double";
  info[335].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  info[335].fileTimeLo = 1303171406U;
  info[335].fileTimeHi = 0U;
  info[335].mFileTimeLo = 0U;
  info[335].mFileTimeHi = 0U;
  info[336].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/attparsilentmex.m";
  info[336].name = "mpower";
  info[336].dominantType = "double";
  info[336].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  info[336].fileTimeLo = 1286844042U;
  info[336].fileTimeHi = 0U;
  info[336].mFileTimeLo = 0U;
  info[336].mFileTimeHi = 0U;
  info[337].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/attparsilentmex.m";
  info[337].name = "mtimes";
  info[337].dominantType = "double";
  info[337].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[337].fileTimeLo = 1289544892U;
  info[337].fileTimeHi = 0U;
  info[337].mFileTimeLo = 0U;
  info[337].mFileTimeHi = 0U;
  info[338].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m";
  info[338].name = "mtimes";
  info[338].dominantType = "double";
  info[338].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[338].fileTimeLo = 1289544892U;
  info[338].fileTimeHi = 0U;
  info[338].mFileTimeLo = 0U;
  info[338].mFileTimeHi = 0U;
  info[339].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  info[339].name = "mtimes";
  info[339].dominantType = "double";
  info[339].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[339].fileTimeLo = 1289544892U;
  info[339].fileTimeHi = 0U;
  info[339].mFileTimeLo = 0U;
  info[339].mFileTimeHi = 0U;
  info[340].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m";
  info[340].name = "squiggle";
  info[340].dominantType = "double";
  info[340].resolved = "[E]/home/tim/Documents/MATLAB/squiggle.m";
  info[340].fileTimeLo = 1368823946U;
  info[340].fileTimeHi = 0U;
  info[340].mFileTimeLo = 0U;
  info[340].mFileTimeHi = 0U;
  info[341].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m";
  info[341].name = "eye";
  info[341].dominantType = "double";
  info[341].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  info[341].fileTimeLo = 1286843888U;
  info[341].fileTimeHi = 0U;
  info[341].mFileTimeLo = 0U;
  info[341].mFileTimeHi = 0U;
  info[342].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  info[342].name = "eml_assert_valid_size_arg";
  info[342].dominantType = "double";
  info[342].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[342].fileTimeLo = 1286843894U;
  info[342].fileTimeHi = 0U;
  info[342].mFileTimeLo = 0U;
  info[342].mFileTimeHi = 0U;
  info[343].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  info[343].name = "isinf";
  info[343].dominantType = "double";
  info[343].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  info[343].fileTimeLo = 1286843960U;
  info[343].fileTimeHi = 0U;
  info[343].mFileTimeLo = 0U;
  info[343].mFileTimeHi = 0U;
  info[344].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  info[344].name = "mtimes";
  info[344].dominantType = "double";
  info[344].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[344].fileTimeLo = 1289544892U;
  info[344].fileTimeHi = 0U;
  info[344].mFileTimeLo = 0U;
  info[344].mFileTimeHi = 0U;
  info[345].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[345].name = "eml_index_class";
  info[345].dominantType = "";
  info[345].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[345].fileTimeLo = 1323195778U;
  info[345].fileTimeHi = 0U;
  info[345].mFileTimeLo = 0U;
  info[345].mFileTimeHi = 0U;
  info[346].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[346].name = "intmax";
  info[346].dominantType = "char";
  info[346].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[346].fileTimeLo = 1311280516U;
  info[346].fileTimeHi = 0U;
  info[346].mFileTimeLo = 0U;
  info[346].mFileTimeHi = 0U;
  info[347].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  info[347].name = "eml_is_float_class";
  info[347].dominantType = "char";
  info[347].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  info[347].fileTimeLo = 1286843982U;
  info[347].fileTimeHi = 0U;
  info[347].mFileTimeLo = 0U;
  info[347].mFileTimeHi = 0U;
  info[348].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  info[348].name = "min";
  info[348].dominantType = "double";
  info[348].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[348].fileTimeLo = 1311280518U;
  info[348].fileTimeHi = 0U;
  info[348].mFileTimeLo = 0U;
  info[348].mFileTimeHi = 0U;
  info[349].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  info[349].name = "eml_index_class";
  info[349].dominantType = "";
  info[349].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[349].fileTimeLo = 1323195778U;
  info[349].fileTimeHi = 0U;
  info[349].mFileTimeLo = 0U;
  info[349].mFileTimeHi = 0U;
  info[350].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  info[350].name = "eml_int_forloop_overflow_check";
  info[350].dominantType = "";
  info[350].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[350].fileTimeLo = 1346535540U;
  info[350].fileTimeHi = 0U;
  info[350].mFileTimeLo = 0U;
  info[350].mFileTimeHi = 0U;
  info[351].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m";
  info[351].name = "norm";
  info[351].dominantType = "double";
  info[351].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  info[351].fileTimeLo = 1336547294U;
  info[351].fileTimeHi = 0U;
  info[351].mFileTimeLo = 0U;
  info[351].mFileTimeHi = 0U;
  info[352].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/update_eq_unknown_state.m";
  info[352].name = "mrdivide";
  info[352].dominantType = "double";
  info[352].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[352].fileTimeLo = 1357976748U;
  info[352].fileTimeHi = 0U;
  info[352].mFileTimeLo = 1319755166U;
  info[352].mFileTimeHi = 0U;
  info[353].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[353].name = "mrdivide";
  info[353].dominantType = "double";
  info[353].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[353].fileTimeLo = 1357976748U;
  info[353].fileTimeHi = 0U;
  info[353].mFileTimeLo = 1319755166U;
  info[353].mFileTimeHi = 0U;
  info[354].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[354].name = "repmat";
  info[354].dominantType = "double";
  info[354].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[354].fileTimeLo = 1352450060U;
  info[354].fileTimeHi = 0U;
  info[354].mFileTimeLo = 0U;
  info[354].mFileTimeHi = 0U;
  info[355].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[355].name = "eml_assert_valid_size_arg";
  info[355].dominantType = "double";
  info[355].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[355].fileTimeLo = 1286843894U;
  info[355].fileTimeHi = 0U;
  info[355].mFileTimeLo = 0U;
  info[355].mFileTimeHi = 0U;
  info[356].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[356].name = "coder.internal.indexIntRelop";
  info[356].dominantType = "";
  info[356].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[356].fileTimeLo = 1326753522U;
  info[356].fileTimeHi = 0U;
  info[356].mFileTimeLo = 0U;
  info[356].mFileTimeHi = 0U;
  info[357].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[357].name = "eml_index_class";
  info[357].dominantType = "";
  info[357].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[357].fileTimeLo = 1323195778U;
  info[357].fileTimeHi = 0U;
  info[357].mFileTimeLo = 0U;
  info[357].mFileTimeHi = 0U;
  info[358].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[358].name = "eml_index_minus";
  info[358].dominantType = "coder.internal.indexInt";
  info[358].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[358].fileTimeLo = 1286843978U;
  info[358].fileTimeHi = 0U;
  info[358].mFileTimeLo = 0U;
  info[358].mFileTimeHi = 0U;
  info[359].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[359].name = "eml_scalar_eg";
  info[359].dominantType = "double";
  info[359].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[359].fileTimeLo = 1286843996U;
  info[359].fileTimeHi = 0U;
  info[359].mFileTimeLo = 0U;
  info[359].mFileTimeHi = 0U;
  info[360].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[360].name = "eml_index_prod";
  info[360].dominantType = "double";
  info[360].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[360].fileTimeLo = 1286843980U;
  info[360].fileTimeHi = 0U;
  info[360].mFileTimeLo = 0U;
  info[360].mFileTimeHi = 0U;
  info[361].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[361].name = "eml_index_class";
  info[361].dominantType = "";
  info[361].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[361].fileTimeLo = 1323195778U;
  info[361].fileTimeHi = 0U;
  info[361].mFileTimeLo = 0U;
  info[361].mFileTimeHi = 0U;
  info[362].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[362].name = "eml_index_times";
  info[362].dominantType = "coder.internal.indexInt";
  info[362].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[362].fileTimeLo = 1286843980U;
  info[362].fileTimeHi = 0U;
  info[362].mFileTimeLo = 0U;
  info[362].mFileTimeHi = 0U;
  info[363].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[363].name = "eml_int_forloop_overflow_check";
  info[363].dominantType = "";
  info[363].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[363].fileTimeLo = 1346535540U;
  info[363].fileTimeHi = 0U;
  info[363].mFileTimeLo = 0U;
  info[363].mFileTimeHi = 0U;
  info[364].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[364].name = "eml_index_plus";
  info[364].dominantType = "coder.internal.indexInt";
  info[364].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[364].fileTimeLo = 1286843978U;
  info[364].fileTimeHi = 0U;
  info[364].mFileTimeLo = 0U;
  info[364].mFileTimeHi = 0U;
  info[365].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[365].name = "sum";
  info[365].dominantType = "double";
  info[365].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[365].fileTimeLo = 1314761812U;
  info[365].fileTimeHi = 0U;
  info[365].mFileTimeLo = 0U;
  info[365].mFileTimeHi = 0U;
  info[366].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[366].name = "eml_assert_valid_dim";
  info[366].dominantType = "double";
  info[366].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[366].fileTimeLo = 1286843894U;
  info[366].fileTimeHi = 0U;
  info[366].mFileTimeLo = 0U;
  info[366].mFileTimeHi = 0U;
  info[367].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[367].name = "eml_scalar_floor";
  info[367].dominantType = "double";
  info[367].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  info[367].fileTimeLo = 1286843926U;
  info[367].fileTimeHi = 0U;
  info[367].mFileTimeLo = 0U;
  info[367].mFileTimeHi = 0U;
  info[368].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[368].name = "eml_index_class";
  info[368].dominantType = "";
  info[368].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[368].fileTimeLo = 1323195778U;
  info[368].fileTimeHi = 0U;
  info[368].mFileTimeLo = 0U;
  info[368].mFileTimeHi = 0U;
  info[369].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[369].name = "intmax";
  info[369].dominantType = "char";
  info[369].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[369].fileTimeLo = 1311280516U;
  info[369].fileTimeHi = 0U;
  info[369].mFileTimeLo = 0U;
  info[369].mFileTimeHi = 0U;
  info[370].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[370].name = "eml_index_class";
  info[370].dominantType = "";
  info[370].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[370].fileTimeLo = 1323195778U;
  info[370].fileTimeHi = 0U;
  info[370].mFileTimeLo = 0U;
  info[370].mFileTimeHi = 0U;
  info[371].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[371].name = "eml_scalar_eg";
  info[371].dominantType = "double";
  info[371].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[371].fileTimeLo = 1286843996U;
  info[371].fileTimeHi = 0U;
  info[371].mFileTimeLo = 0U;
  info[371].mFileTimeHi = 0U;
  info[372].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[372].name = "eml_matrix_vstride";
  info[372].dominantType = "double";
  info[372].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[372].fileTimeLo = 1286843988U;
  info[372].fileTimeHi = 0U;
  info[372].mFileTimeLo = 0U;
  info[372].mFileTimeHi = 0U;
  info[373].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[373].name = "eml_index_minus";
  info[373].dominantType = "double";
  info[373].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[373].fileTimeLo = 1286843978U;
  info[373].fileTimeHi = 0U;
  info[373].mFileTimeLo = 0U;
  info[373].mFileTimeHi = 0U;
  info[374].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[374].name = "eml_index_class";
  info[374].dominantType = "";
  info[374].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[374].fileTimeLo = 1323195778U;
  info[374].fileTimeHi = 0U;
  info[374].mFileTimeLo = 0U;
  info[374].mFileTimeHi = 0U;
  info[375].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[375].name = "eml_size_prod";
  info[375].dominantType = "double";
  info[375].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[375].fileTimeLo = 1286843998U;
  info[375].fileTimeHi = 0U;
  info[375].mFileTimeLo = 0U;
  info[375].mFileTimeHi = 0U;
  info[376].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[376].name = "eml_index_class";
  info[376].dominantType = "";
  info[376].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[376].fileTimeLo = 1323195778U;
  info[376].fileTimeHi = 0U;
  info[376].mFileTimeLo = 0U;
  info[376].mFileTimeHi = 0U;
  info[377].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[377].name = "eml_index_times";
  info[377].dominantType = "double";
  info[377].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[377].fileTimeLo = 1286843980U;
  info[377].fileTimeHi = 0U;
  info[377].mFileTimeLo = 0U;
  info[377].mFileTimeHi = 0U;
  info[378].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[378].name = "eml_matrix_npages";
  info[378].dominantType = "double";
  info[378].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[378].fileTimeLo = 1286843986U;
  info[378].fileTimeHi = 0U;
  info[378].mFileTimeLo = 0U;
  info[378].mFileTimeHi = 0U;
  info[379].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[379].name = "eml_index_plus";
  info[379].dominantType = "double";
  info[379].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[379].fileTimeLo = 1286843978U;
  info[379].fileTimeHi = 0U;
  info[379].mFileTimeLo = 0U;
  info[379].mFileTimeHi = 0U;
  info[380].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[380].name = "eml_index_class";
  info[380].dominantType = "";
  info[380].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[380].fileTimeLo = 1323195778U;
  info[380].fileTimeHi = 0U;
  info[380].mFileTimeLo = 0U;
  info[380].mFileTimeHi = 0U;
  info[381].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[381].name = "eml_size_prod";
  info[381].dominantType = "double";
  info[381].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[381].fileTimeLo = 1286843998U;
  info[381].fileTimeHi = 0U;
  info[381].mFileTimeLo = 0U;
  info[381].mFileTimeHi = 0U;
  info[382].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[382].name = "eml_int_forloop_overflow_check";
  info[382].dominantType = "";
  info[382].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[382].fileTimeLo = 1346535540U;
  info[382].fileTimeHi = 0U;
  info[382].mFileTimeLo = 0U;
  info[382].mFileTimeHi = 0U;
  info[383].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[383].name = "eml_index_plus";
  info[383].dominantType = "double";
  info[383].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[383].fileTimeLo = 1286843978U;
  info[383].fileTimeHi = 0U;
  info[383].mFileTimeLo = 0U;
  info[383].mFileTimeHi = 0U;
}

static void g_emlrt_marshallIn(const mxArray *Pxk, const char_T *identifier,
  emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  h_emlrt_marshallIn(emlrtAlias(Pxk), &thisId, y);
  emlrtDestroyArray(&Pxk);
}

static void g_info_helper(ResolvedFunctionInfo info[567])
{
  info[384].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[384].name = "eml_index_plus";
  info[384].dominantType = "coder.internal.indexInt";
  info[384].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[384].fileTimeLo = 1286843978U;
  info[384].fileTimeHi = 0U;
  info[384].mFileTimeLo = 0U;
  info[384].mFileTimeHi = 0U;
  info[385].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[385].name = "norm";
  info[385].dominantType = "double";
  info[385].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  info[385].fileTimeLo = 1336547294U;
  info[385].fileTimeHi = 0U;
  info[385].mFileTimeLo = 0U;
  info[385].mFileTimeHi = 0U;
  info[386].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[386].name = "measurement_eq_unknown_state";
  info[386].dominantType = "double";
  info[386].resolved =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[386].fileTimeLo = 1418319103U;
  info[386].fileTimeHi = 0U;
  info[386].mFileTimeLo = 0U;
  info[386].mFileTimeHi = 0U;
  info[387].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[387].name = "mtimes";
  info[387].dominantType = "double";
  info[387].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[387].fileTimeLo = 1289544892U;
  info[387].fileTimeHi = 0U;
  info[387].mFileTimeLo = 0U;
  info[387].mFileTimeHi = 0U;
  info[388].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[388].name = "colon";
  info[388].dominantType = "double";
  info[388].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  info[388].fileTimeLo = 1348217128U;
  info[388].fileTimeHi = 0U;
  info[388].mFileTimeLo = 0U;
  info[388].mFileTimeHi = 0U;
  info[389].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[389].name = "reshape";
  info[389].dominantType = "double";
  info[389].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[389].fileTimeLo = 1286843968U;
  info[389].fileTimeHi = 0U;
  info[389].mFileTimeLo = 0U;
  info[389].mFileTimeHi = 0U;
  info[390].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[390].name = "eml_index_class";
  info[390].dominantType = "";
  info[390].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[390].fileTimeLo = 1323195778U;
  info[390].fileTimeHi = 0U;
  info[390].mFileTimeLo = 0U;
  info[390].mFileTimeHi = 0U;
  info[391].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!varargin_nempty";
  info[391].name = "eml_index_class";
  info[391].dominantType = "";
  info[391].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[391].fileTimeLo = 1323195778U;
  info[391].fileTimeHi = 0U;
  info[391].mFileTimeLo = 0U;
  info[391].mFileTimeHi = 0U;
  info[392].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!varargin_nempty";
  info[392].name = "eml_index_plus";
  info[392].dominantType = "double";
  info[392].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[392].fileTimeLo = 1286843978U;
  info[392].fileTimeHi = 0U;
  info[392].mFileTimeLo = 0U;
  info[392].mFileTimeHi = 0U;
  info[393].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[393].name = "eml_assert_valid_size_arg";
  info[393].dominantType = "double";
  info[393].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[393].fileTimeLo = 1286843894U;
  info[393].fileTimeHi = 0U;
  info[393].mFileTimeLo = 0U;
  info[393].mFileTimeHi = 0U;
  info[394].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[394].name = "eml_index_prod";
  info[394].dominantType = "coder.internal.indexInt";
  info[394].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[394].fileTimeLo = 1286843980U;
  info[394].fileTimeHi = 0U;
  info[394].mFileTimeLo = 0U;
  info[394].mFileTimeHi = 0U;
  info[395].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[395].name = "eml_int_forloop_overflow_check";
  info[395].dominantType = "";
  info[395].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[395].fileTimeLo = 1346535540U;
  info[395].fileTimeHi = 0U;
  info[395].mFileTimeLo = 0U;
  info[395].mFileTimeHi = 0U;
  info[396].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[396].name = "eml_index_rdivide";
  info[396].dominantType = "coder.internal.indexInt";
  info[396].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  info[396].fileTimeLo = 1286843980U;
  info[396].fileTimeHi = 0U;
  info[396].mFileTimeLo = 0U;
  info[396].mFileTimeHi = 0U;
  info[397].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[397].name = "max";
  info[397].dominantType = "double";
  info[397].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  info[397].fileTimeLo = 1311280516U;
  info[397].fileTimeHi = 0U;
  info[397].mFileTimeLo = 0U;
  info[397].mFileTimeHi = 0U;
  info[398].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  info[398].name = "eml_relop";
  info[398].dominantType = "function_handle";
  info[398].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  info[398].fileTimeLo = 1342476382U;
  info[398].fileTimeHi = 0U;
  info[398].mFileTimeLo = 0U;
  info[398].mFileTimeHi = 0U;
  info[399].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  info[399].name = "coder.internal.indexIntRelop";
  info[399].dominantType = "";
  info[399].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[399].fileTimeLo = 1326753522U;
  info[399].fileTimeHi = 0U;
  info[399].mFileTimeLo = 0U;
  info[399].mFileTimeHi = 0U;
  info[400].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  info[400].name = "isnan";
  info[400].dominantType = "coder.internal.indexInt";
  info[400].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[400].fileTimeLo = 1286843960U;
  info[400].fileTimeHi = 0U;
  info[400].mFileTimeLo = 0U;
  info[400].mFileTimeHi = 0U;
  info[401].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[401].name = "eml_error";
  info[401].dominantType = "char";
  info[401].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  info[401].fileTimeLo = 1343855558U;
  info[401].fileTimeHi = 0U;
  info[401].mFileTimeLo = 0U;
  info[401].mFileTimeHi = 0U;
  info[402].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[402].name = "eml_scalar_eg";
  info[402].dominantType = "double";
  info[402].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[402].fileTimeLo = 1286843996U;
  info[402].fileTimeHi = 0U;
  info[402].mFileTimeLo = 0U;
  info[402].mFileTimeHi = 0U;
  info[403].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[403].name = "coder.internal.indexIntRelop";
  info[403].dominantType = "";
  info[403].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[403].fileTimeLo = 1326753522U;
  info[403].fileTimeHi = 0U;
  info[403].mFileTimeLo = 0U;
  info[403].mFileTimeHi = 0U;
  info[404].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[404].name = "eml_int_forloop_overflow_check";
  info[404].dominantType = "";
  info[404].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[404].fileTimeLo = 1346535540U;
  info[404].fileTimeHi = 0U;
  info[404].mFileTimeLo = 0U;
  info[404].mFileTimeHi = 0U;
  info[405].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[405].name = "attparsilentmex";
  info[405].dominantType = "double";
  info[405].resolved =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/attparsilentmex.m";
  info[405].fileTimeLo = 1416505945U;
  info[405].fileTimeHi = 0U;
  info[405].mFileTimeLo = 0U;
  info[405].mFileTimeHi = 0U;
  info[406].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[406].name = "power";
  info[406].dominantType = "double";
  info[406].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  info[406].fileTimeLo = 1348217130U;
  info[406].fileTimeHi = 0U;
  info[406].mFileTimeLo = 0U;
  info[406].mFileTimeHi = 0U;
  info[407].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[407].name = "sum";
  info[407].dominantType = "double";
  info[407].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[407].fileTimeLo = 1314761812U;
  info[407].fileTimeHi = 0U;
  info[407].mFileTimeLo = 0U;
  info[407].mFileTimeHi = 0U;
  info[408].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[408].name = "isequal";
  info[408].dominantType = "double";
  info[408].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[408].fileTimeLo = 1286843958U;
  info[408].fileTimeHi = 0U;
  info[408].mFileTimeLo = 0U;
  info[408].mFileTimeHi = 0U;
  info[409].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[409].name = "eml_const_nonsingleton_dim";
  info[409].dominantType = "double";
  info[409].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  info[409].fileTimeLo = 1286843896U;
  info[409].fileTimeHi = 0U;
  info[409].mFileTimeLo = 0U;
  info[409].mFileTimeHi = 0U;
  info[410].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[410].name = "sqrt";
  info[410].dominantType = "double";
  info[410].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[410].fileTimeLo = 1343855586U;
  info[410].fileTimeHi = 0U;
  info[410].mFileTimeLo = 0U;
  info[410].mFileTimeHi = 0U;
  info[411].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[411].name = "atan2";
  info[411].dominantType = "double";
  info[411].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  info[411].fileTimeLo = 1343855572U;
  info[411].fileTimeHi = 0U;
  info[411].mFileTimeLo = 0U;
  info[411].mFileTimeHi = 0U;
  info[412].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  info[412].name = "eml_scalar_eg";
  info[412].dominantType = "double";
  info[412].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[412].fileTimeLo = 1286843996U;
  info[412].fileTimeHi = 0U;
  info[412].mFileTimeLo = 0U;
  info[412].mFileTimeHi = 0U;
  info[413].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  info[413].name = "eml_scalexp_alloc";
  info[413].dominantType = "double";
  info[413].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[413].fileTimeLo = 1352450060U;
  info[413].fileTimeHi = 0U;
  info[413].mFileTimeLo = 0U;
  info[413].mFileTimeHi = 0U;
  info[414].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  info[414].name = "eml_scalar_atan2";
  info[414].dominantType = "double";
  info[414].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  info[414].fileTimeLo = 1286843920U;
  info[414].fileTimeHi = 0U;
  info[414].mFileTimeLo = 0U;
  info[414].mFileTimeHi = 0U;
  info[415].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  info[415].name = "mrdivide";
  info[415].dominantType = "double";
  info[415].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[415].fileTimeLo = 1357976748U;
  info[415].fileTimeHi = 0U;
  info[415].mFileTimeLo = 1319755166U;
  info[415].mFileTimeHi = 0U;
  info[416].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  info[416].name = "floor";
  info[416].dominantType = "double";
  info[416].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[416].fileTimeLo = 1343855580U;
  info[416].fileTimeHi = 0U;
  info[416].mFileTimeLo = 0U;
  info[416].mFileTimeHi = 0U;
  info[417].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  info[417].name = "eml_index_class";
  info[417].dominantType = "";
  info[417].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[417].fileTimeLo = 1323195778U;
  info[417].fileTimeHi = 0U;
  info[417].mFileTimeLo = 0U;
  info[417].mFileTimeHi = 0U;
  info[418].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon";
  info[418].name = "intmax";
  info[418].dominantType = "char";
  info[418].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[418].fileTimeLo = 1311280516U;
  info[418].fileTimeHi = 0U;
  info[418].mFileTimeLo = 0U;
  info[418].mFileTimeHi = 0U;
  info[419].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[419].name = "vector2polar";
  info[419].dominantType = "double";
  info[419].resolved =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m";
  info[419].fileTimeLo = 1417710421U;
  info[419].fileTimeHi = 0U;
  info[419].mFileTimeLo = 0U;
  info[419].mFileTimeHi = 0U;
  info[420].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m";
  info[420].name = "power";
  info[420].dominantType = "double";
  info[420].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  info[420].fileTimeLo = 1348217130U;
  info[420].fileTimeHi = 0U;
  info[420].mFileTimeLo = 0U;
  info[420].mFileTimeHi = 0U;
  info[421].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m";
  info[421].name = "sum";
  info[421].dominantType = "double";
  info[421].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[421].fileTimeLo = 1314761812U;
  info[421].fileTimeHi = 0U;
  info[421].mFileTimeLo = 0U;
  info[421].mFileTimeHi = 0U;
  info[422].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m";
  info[422].name = "sqrt";
  info[422].dominantType = "double";
  info[422].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[422].fileTimeLo = 1343855586U;
  info[422].fileTimeHi = 0U;
  info[422].mFileTimeLo = 0U;
  info[422].mFileTimeHi = 0U;
  info[423].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m";
  info[423].name = "atan2";
  info[423].dominantType = "double";
  info[423].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  info[423].fileTimeLo = 1343855572U;
  info[423].fileTimeHi = 0U;
  info[423].mFileTimeLo = 0U;
  info[423].mFileTimeHi = 0U;
  info[424].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_known_features/vector2polar.m";
  info[424].name = "mpower";
  info[424].dominantType = "double";
  info[424].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  info[424].fileTimeLo = 1286844042U;
  info[424].fileTimeHi = 0U;
  info[424].mFileTimeLo = 0U;
  info[424].mFileTimeHi = 0U;
  info[425].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[425].name = "mrdivide";
  info[425].dominantType = "double";
  info[425].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[425].fileTimeLo = 1357976748U;
  info[425].fileTimeHi = 0U;
  info[425].mFileTimeLo = 1319755166U;
  info[425].mFileTimeHi = 0U;
  info[426].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[426].name = "cos";
  info[426].dominantType = "double";
  info[426].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  info[426].fileTimeLo = 1343855572U;
  info[426].fileTimeHi = 0U;
  info[426].mFileTimeLo = 0U;
  info[426].mFileTimeHi = 0U;
  info[427].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  info[427].name = "eml_scalar_cos";
  info[427].dominantType = "double";
  info[427].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  info[427].fileTimeLo = 1286843922U;
  info[427].fileTimeHi = 0U;
  info[427].mFileTimeLo = 0U;
  info[427].mFileTimeHi = 0U;
  info[428].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[428].name = "sin";
  info[428].dominantType = "double";
  info[428].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  info[428].fileTimeLo = 1343855586U;
  info[428].fileTimeHi = 0U;
  info[428].mFileTimeLo = 0U;
  info[428].mFileTimeHi = 0U;
  info[429].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  info[429].name = "eml_scalar_sin";
  info[429].dominantType = "double";
  info[429].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  info[429].fileTimeLo = 1286843936U;
  info[429].fileTimeHi = 0U;
  info[429].mFileTimeLo = 0U;
  info[429].mFileTimeHi = 0U;
  info[430].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/measurement_eq_unknown_state.m";
  info[430].name = "minangle";
  info[430].dominantType = "double";
  info[430].resolved =
    "[E]/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m";
  info[430].fileTimeLo = 1411329554U;
  info[430].fileTimeHi = 0U;
  info[430].mFileTimeLo = 0U;
  info[430].mFileTimeHi = 0U;
  info[431].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m";
  info[431].name = "mtimes";
  info[431].dominantType = "double";
  info[431].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[431].fileTimeLo = 1289544892U;
  info[431].fileTimeHi = 0U;
  info[431].mFileTimeLo = 0U;
  info[431].mFileTimeHi = 0U;
  info[432].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m";
  info[432].name = "abs";
  info[432].dominantType = "double";
  info[432].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[432].fileTimeLo = 1343855566U;
  info[432].fileTimeHi = 0U;
  info[432].mFileTimeLo = 0U;
  info[432].mFileTimeHi = 0U;
  info[433].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m";
  info[433].name = "any";
  info[433].dominantType = "logical";
  info[433].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  info[433].fileTimeLo = 1286844034U;
  info[433].fileTimeHi = 0U;
  info[433].mFileTimeLo = 0U;
  info[433].mFileTimeHi = 0U;
  info[434].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  info[434].name = "eml_all_or_any";
  info[434].dominantType = "char";
  info[434].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[434].fileTimeLo = 1286843894U;
  info[434].fileTimeHi = 0U;
  info[434].mFileTimeLo = 0U;
  info[434].mFileTimeHi = 0U;
  info[435].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[435].name = "isequal";
  info[435].dominantType = "double";
  info[435].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[435].fileTimeLo = 1286843958U;
  info[435].fileTimeHi = 0U;
  info[435].mFileTimeLo = 0U;
  info[435].mFileTimeHi = 0U;
  info[436].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[436].name = "eml_const_nonsingleton_dim";
  info[436].dominantType = "logical";
  info[436].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  info[436].fileTimeLo = 1286843896U;
  info[436].fileTimeHi = 0U;
  info[436].mFileTimeLo = 0U;
  info[436].mFileTimeHi = 0U;
  info[437].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[437].name = "isnan";
  info[437].dominantType = "logical";
  info[437].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[437].fileTimeLo = 1286843960U;
  info[437].fileTimeHi = 0U;
  info[437].mFileTimeLo = 0U;
  info[437].mFileTimeHi = 0U;
  info[438].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m";
  info[438].name = "find";
  info[438].dominantType = "logical";
  info[438].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  info[438].fileTimeLo = 1303171406U;
  info[438].fileTimeHi = 0U;
  info[438].mFileTimeLo = 0U;
  info[438].mFileTimeHi = 0U;
  info[439].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[439].name = "eml_index_class";
  info[439].dominantType = "";
  info[439].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[439].fileTimeLo = 1323195778U;
  info[439].fileTimeHi = 0U;
  info[439].mFileTimeLo = 0U;
  info[439].mFileTimeHi = 0U;
  info[440].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[440].name = "eml_scalar_eg";
  info[440].dominantType = "logical";
  info[440].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[440].fileTimeLo = 1286843996U;
  info[440].fileTimeHi = 0U;
  info[440].mFileTimeLo = 0U;
  info[440].mFileTimeHi = 0U;
  info[441].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[441].name = "eml_int_forloop_overflow_check";
  info[441].dominantType = "";
  info[441].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[441].fileTimeLo = 1346535540U;
  info[441].fileTimeHi = 0U;
  info[441].mFileTimeLo = 0U;
  info[441].mFileTimeHi = 0U;
  info[442].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[442].name = "eml_index_plus";
  info[442].dominantType = "double";
  info[442].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[442].fileTimeLo = 1286843978U;
  info[442].fileTimeHi = 0U;
  info[442].mFileTimeLo = 0U;
  info[442].mFileTimeHi = 0U;
  info[443].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m";
  info[443].name = "disp";
  info[443].dominantType = "char";
  info[443].resolved = "[IXMB]$matlabroot$/toolbox/matlab/lang/disp";
  info[443].fileTimeLo = MAX_uint32_T;
  info[443].fileTimeHi = MAX_uint32_T;
  info[443].mFileTimeLo = MAX_uint32_T;
  info[443].mFileTimeHi = MAX_uint32_T;
  info[444].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[444].name = "eml_matrix_vstride";
  info[444].dominantType = "double";
  info[444].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[444].fileTimeLo = 1286843988U;
  info[444].fileTimeHi = 0U;
  info[444].mFileTimeLo = 0U;
  info[444].mFileTimeHi = 0U;
  info[445].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[445].name = "eml_size_prod";
  info[445].dominantType = "logical";
  info[445].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[445].fileTimeLo = 1286843998U;
  info[445].fileTimeHi = 0U;
  info[445].mFileTimeLo = 0U;
  info[445].mFileTimeHi = 0U;
  info[446].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[446].name = "eml_index_minus";
  info[446].dominantType = "double";
  info[446].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[446].fileTimeLo = 1286843978U;
  info[446].fileTimeHi = 0U;
  info[446].mFileTimeLo = 0U;
  info[446].mFileTimeHi = 0U;
  info[447].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[447].name = "eml_index_times";
  info[447].dominantType = "coder.internal.indexInt";
  info[447].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[447].fileTimeLo = 1286843980U;
  info[447].fileTimeHi = 0U;
  info[447].mFileTimeLo = 0U;
  info[447].mFileTimeHi = 0U;
}

static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  p_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_info_helper(ResolvedFunctionInfo info[567])
{
  info[448].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[448].name = "eml_matrix_npages";
  info[448].dominantType = "double";
  info[448].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[448].fileTimeLo = 1286843986U;
  info[448].fileTimeHi = 0U;
  info[448].mFileTimeLo = 0U;
  info[448].mFileTimeHi = 0U;
  info[449].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[449].name = "eml_size_prod";
  info[449].dominantType = "logical";
  info[449].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[449].fileTimeLo = 1286843998U;
  info[449].fileTimeHi = 0U;
  info[449].mFileTimeLo = 0U;
  info[449].mFileTimeHi = 0U;
  info[450].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[450].name = "eml_index_class";
  info[450].dominantType = "";
  info[450].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[450].fileTimeLo = 1323195778U;
  info[450].fileTimeHi = 0U;
  info[450].mFileTimeLo = 0U;
  info[450].mFileTimeHi = 0U;
  info[451].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[451].name = "eml_index_plus";
  info[451].dominantType = "coder.internal.indexInt";
  info[451].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[451].fileTimeLo = 1286843978U;
  info[451].fileTimeHi = 0U;
  info[451].mFileTimeLo = 0U;
  info[451].mFileTimeHi = 0U;
  info[452].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[452].name = "eml_index_plus";
  info[452].dominantType = "double";
  info[452].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[452].fileTimeLo = 1286843978U;
  info[452].fileTimeHi = 0U;
  info[452].mFileTimeLo = 0U;
  info[452].mFileTimeHi = 0U;
  info[453].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[453].name = "eml_int_forloop_overflow_check";
  info[453].dominantType = "";
  info[453].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[453].fileTimeLo = 1346535540U;
  info[453].fileTimeHi = 0U;
  info[453].mFileTimeLo = 0U;
  info[453].mFileTimeHi = 0U;
  info[454].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[454].name = "isnan";
  info[454].dominantType = "double";
  info[454].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[454].fileTimeLo = 1286843960U;
  info[454].fileTimeHi = 0U;
  info[454].mFileTimeLo = 0U;
  info[454].mFileTimeHi = 0U;
  info[455].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[455].name = "any";
  info[455].dominantType = "logical";
  info[455].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  info[455].fileTimeLo = 1286844034U;
  info[455].fileTimeHi = 0U;
  info[455].mFileTimeLo = 0U;
  info[455].mFileTimeHi = 0U;
  info[456].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[456].name = "disp";
  info[456].dominantType = "char";
  info[456].resolved = "[IXMB]$matlabroot$/toolbox/matlab/lang/disp";
  info[456].fileTimeLo = MAX_uint32_T;
  info[456].fileTimeHi = MAX_uint32_T;
  info[456].mFileTimeLo = MAX_uint32_T;
  info[456].mFileTimeHi = MAX_uint32_T;
  info[457].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[457].name = "eye";
  info[457].dominantType = "double";
  info[457].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  info[457].fileTimeLo = 1286843888U;
  info[457].fileTimeHi = 0U;
  info[457].mFileTimeLo = 0U;
  info[457].mFileTimeHi = 0U;
  info[458].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[458].name = "mldivide";
  info[458].dominantType = "double";
  info[458].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  info[458].fileTimeLo = 1357976748U;
  info[458].fileTimeHi = 0U;
  info[458].mFileTimeLo = 1319755166U;
  info[458].mFileTimeHi = 0U;
  info[459].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  info[459].name = "eml_scalar_eg";
  info[459].dominantType = "double";
  info[459].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[459].fileTimeLo = 1286843996U;
  info[459].fileTimeHi = 0U;
  info[459].mFileTimeLo = 0U;
  info[459].mFileTimeHi = 0U;
  info[460].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  info[460].name = "eml_lusolve";
  info[460].dominantType = "double";
  info[460].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  info[460].fileTimeLo = 1309476396U;
  info[460].fileTimeHi = 0U;
  info[460].mFileTimeLo = 0U;
  info[460].mFileTimeHi = 0U;
  info[461].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  info[461].name = "eml_index_class";
  info[461].dominantType = "";
  info[461].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[461].fileTimeLo = 1323195778U;
  info[461].fileTimeHi = 0U;
  info[461].mFileTimeLo = 0U;
  info[461].mFileTimeHi = 0U;
  info[462].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  info[462].name = "eml_index_class";
  info[462].dominantType = "";
  info[462].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[462].fileTimeLo = 1323195778U;
  info[462].fileTimeHi = 0U;
  info[462].mFileTimeLo = 0U;
  info[462].mFileTimeHi = 0U;
  info[463].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  info[463].name = "eml_xgetrf";
  info[463].dominantType = "double";
  info[463].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  info[463].fileTimeLo = 1286844006U;
  info[463].fileTimeHi = 0U;
  info[463].mFileTimeLo = 0U;
  info[463].mFileTimeHi = 0U;
  info[464].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  info[464].name = "eml_lapack_xgetrf";
  info[464].dominantType = "double";
  info[464].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  info[464].fileTimeLo = 1286844010U;
  info[464].fileTimeHi = 0U;
  info[464].mFileTimeLo = 0U;
  info[464].mFileTimeHi = 0U;
  info[465].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  info[465].name = "eml_matlab_zgetrf";
  info[465].dominantType = "double";
  info[465].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[465].fileTimeLo = 1302714194U;
  info[465].fileTimeHi = 0U;
  info[465].mFileTimeLo = 0U;
  info[465].mFileTimeHi = 0U;
  info[466].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[466].name = "realmin";
  info[466].dominantType = "char";
  info[466].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  info[466].fileTimeLo = 1307676442U;
  info[466].fileTimeHi = 0U;
  info[466].mFileTimeLo = 0U;
  info[466].mFileTimeHi = 0U;
  info[467].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[467].name = "eps";
  info[467].dominantType = "char";
  info[467].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[467].fileTimeLo = 1326753196U;
  info[467].fileTimeHi = 0U;
  info[467].mFileTimeLo = 0U;
  info[467].mFileTimeHi = 0U;
  info[468].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[468].name = "min";
  info[468].dominantType = "coder.internal.indexInt";
  info[468].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[468].fileTimeLo = 1311280518U;
  info[468].fileTimeHi = 0U;
  info[468].mFileTimeLo = 0U;
  info[468].mFileTimeHi = 0U;
  info[469].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[469].name = "colon";
  info[469].dominantType = "double";
  info[469].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  info[469].fileTimeLo = 1348217128U;
  info[469].fileTimeHi = 0U;
  info[469].mFileTimeLo = 0U;
  info[469].mFileTimeHi = 0U;
  info[470].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  info[470].name = "floor";
  info[470].dominantType = "double";
  info[470].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[470].fileTimeLo = 1343855580U;
  info[470].fileTimeHi = 0U;
  info[470].mFileTimeLo = 0U;
  info[470].mFileTimeHi = 0U;
  info[471].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  info[471].name = "intmin";
  info[471].dominantType = "char";
  info[471].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  info[471].fileTimeLo = 1311280518U;
  info[471].fileTimeHi = 0U;
  info[471].mFileTimeLo = 0U;
  info[471].mFileTimeHi = 0U;
  info[472].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  info[472].name = "intmax";
  info[472].dominantType = "char";
  info[472].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[472].fileTimeLo = 1311280516U;
  info[472].fileTimeHi = 0U;
  info[472].mFileTimeLo = 0U;
  info[472].mFileTimeHi = 0U;
  info[473].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  info[473].name = "intmin";
  info[473].dominantType = "char";
  info[473].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  info[473].fileTimeLo = 1311280518U;
  info[473].fileTimeHi = 0U;
  info[473].mFileTimeLo = 0U;
  info[473].mFileTimeHi = 0U;
  info[474].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  info[474].name = "intmax";
  info[474].dominantType = "char";
  info[474].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[474].fileTimeLo = 1311280516U;
  info[474].fileTimeHi = 0U;
  info[474].mFileTimeLo = 0U;
  info[474].mFileTimeHi = 0U;
  info[475].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  info[475].name = "eml_isa_uint";
  info[475].dominantType = "coder.internal.indexInt";
  info[475].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  info[475].fileTimeLo = 1286843984U;
  info[475].fileTimeHi = 0U;
  info[475].mFileTimeLo = 0U;
  info[475].mFileTimeHi = 0U;
  info[476].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  info[476].name = "eml_unsigned_class";
  info[476].dominantType = "char";
  info[476].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  info[476].fileTimeLo = 1323195780U;
  info[476].fileTimeHi = 0U;
  info[476].mFileTimeLo = 0U;
  info[476].mFileTimeHi = 0U;
  info[477].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  info[477].name = "eml_index_class";
  info[477].dominantType = "";
  info[477].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[477].fileTimeLo = 1323195778U;
  info[477].fileTimeHi = 0U;
  info[477].mFileTimeLo = 0U;
  info[477].mFileTimeHi = 0U;
  info[478].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  info[478].name = "eml_index_class";
  info[478].dominantType = "";
  info[478].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[478].fileTimeLo = 1323195778U;
  info[478].fileTimeHi = 0U;
  info[478].mFileTimeLo = 0U;
  info[478].mFileTimeHi = 0U;
  info[479].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  info[479].name = "intmax";
  info[479].dominantType = "char";
  info[479].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[479].fileTimeLo = 1311280516U;
  info[479].fileTimeHi = 0U;
  info[479].mFileTimeLo = 0U;
  info[479].mFileTimeHi = 0U;
  info[480].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  info[480].name = "eml_isa_uint";
  info[480].dominantType = "coder.internal.indexInt";
  info[480].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  info[480].fileTimeLo = 1286843984U;
  info[480].fileTimeHi = 0U;
  info[480].mFileTimeLo = 0U;
  info[480].mFileTimeHi = 0U;
  info[481].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  info[481].name = "eml_index_plus";
  info[481].dominantType = "double";
  info[481].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[481].fileTimeLo = 1286843978U;
  info[481].fileTimeHi = 0U;
  info[481].mFileTimeLo = 0U;
  info[481].mFileTimeHi = 0U;
  info[482].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  info[482].name = "eml_int_forloop_overflow_check";
  info[482].dominantType = "";
  info[482].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[482].fileTimeLo = 1346535540U;
  info[482].fileTimeHi = 0U;
  info[482].mFileTimeLo = 0U;
  info[482].mFileTimeHi = 0U;
  info[483].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[483].name = "eml_index_class";
  info[483].dominantType = "";
  info[483].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[483].fileTimeLo = 1323195778U;
  info[483].fileTimeHi = 0U;
  info[483].mFileTimeLo = 0U;
  info[483].mFileTimeHi = 0U;
  info[484].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[484].name = "eml_index_plus";
  info[484].dominantType = "double";
  info[484].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[484].fileTimeLo = 1286843978U;
  info[484].fileTimeHi = 0U;
  info[484].mFileTimeLo = 0U;
  info[484].mFileTimeHi = 0U;
  info[485].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[485].name = "eml_int_forloop_overflow_check";
  info[485].dominantType = "";
  info[485].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[485].fileTimeLo = 1346535540U;
  info[485].fileTimeHi = 0U;
  info[485].mFileTimeLo = 0U;
  info[485].mFileTimeHi = 0U;
  info[486].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[486].name = "eml_index_minus";
  info[486].dominantType = "double";
  info[486].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[486].fileTimeLo = 1286843978U;
  info[486].fileTimeHi = 0U;
  info[486].mFileTimeLo = 0U;
  info[486].mFileTimeHi = 0U;
  info[487].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[487].name = "eml_index_minus";
  info[487].dominantType = "coder.internal.indexInt";
  info[487].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[487].fileTimeLo = 1286843978U;
  info[487].fileTimeHi = 0U;
  info[487].mFileTimeLo = 0U;
  info[487].mFileTimeHi = 0U;
  info[488].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[488].name = "eml_index_times";
  info[488].dominantType = "coder.internal.indexInt";
  info[488].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[488].fileTimeLo = 1286843980U;
  info[488].fileTimeHi = 0U;
  info[488].mFileTimeLo = 0U;
  info[488].mFileTimeHi = 0U;
  info[489].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[489].name = "eml_index_plus";
  info[489].dominantType = "coder.internal.indexInt";
  info[489].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[489].fileTimeLo = 1286843978U;
  info[489].fileTimeHi = 0U;
  info[489].mFileTimeLo = 0U;
  info[489].mFileTimeHi = 0U;
  info[490].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[490].name = "eml_ixamax";
  info[490].dominantType = "double";
  info[490].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  info[490].fileTimeLo = 1299101970U;
  info[490].fileTimeHi = 0U;
  info[490].mFileTimeLo = 0U;
  info[490].mFileTimeHi = 0U;
  info[491].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  info[491].name = "eml_blas_inline";
  info[491].dominantType = "";
  info[491].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[491].fileTimeLo = 1299101968U;
  info[491].fileTimeHi = 0U;
  info[491].mFileTimeLo = 0U;
  info[491].mFileTimeHi = 0U;
  info[492].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  info[492].name = "eml_index_class";
  info[492].dominantType = "";
  info[492].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[492].fileTimeLo = 1323195778U;
  info[492].fileTimeHi = 0U;
  info[492].mFileTimeLo = 0U;
  info[492].mFileTimeHi = 0U;
  info[493].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  info[493].name = "eml_refblas_ixamax";
  info[493].dominantType = "double";
  info[493].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  info[493].fileTimeLo = 1299101970U;
  info[493].fileTimeHi = 0U;
  info[493].mFileTimeLo = 0U;
  info[493].mFileTimeHi = 0U;
  info[494].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  info[494].name = "eml_index_class";
  info[494].dominantType = "";
  info[494].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[494].fileTimeLo = 1323195778U;
  info[494].fileTimeHi = 0U;
  info[494].mFileTimeLo = 0U;
  info[494].mFileTimeHi = 0U;
  info[495].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  info[495].name = "eml_xcabs1";
  info[495].dominantType = "double";
  info[495].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  info[495].fileTimeLo = 1286843906U;
  info[495].fileTimeHi = 0U;
  info[495].mFileTimeLo = 0U;
  info[495].mFileTimeHi = 0U;
  info[496].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  info[496].name = "abs";
  info[496].dominantType = "double";
  info[496].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[496].fileTimeLo = 1343855566U;
  info[496].fileTimeHi = 0U;
  info[496].mFileTimeLo = 0U;
  info[496].mFileTimeHi = 0U;
  info[497].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  info[497].name = "eml_int_forloop_overflow_check";
  info[497].dominantType = "";
  info[497].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[497].fileTimeLo = 1346535540U;
  info[497].fileTimeHi = 0U;
  info[497].mFileTimeLo = 0U;
  info[497].mFileTimeHi = 0U;
  info[498].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  info[498].name = "eml_index_plus";
  info[498].dominantType = "coder.internal.indexInt";
  info[498].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[498].fileTimeLo = 1286843978U;
  info[498].fileTimeHi = 0U;
  info[498].mFileTimeLo = 0U;
  info[498].mFileTimeHi = 0U;
  info[499].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[499].name = "eml_xswap";
  info[499].dominantType = "double";
  info[499].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  info[499].fileTimeLo = 1299101978U;
  info[499].fileTimeHi = 0U;
  info[499].mFileTimeLo = 0U;
  info[499].mFileTimeHi = 0U;
  info[500].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  info[500].name = "eml_blas_inline";
  info[500].dominantType = "";
  info[500].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[500].fileTimeLo = 1299101968U;
  info[500].fileTimeHi = 0U;
  info[500].mFileTimeLo = 0U;
  info[500].mFileTimeHi = 0U;
  info[501].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  info[501].name = "eml_index_class";
  info[501].dominantType = "";
  info[501].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[501].fileTimeLo = 1323195778U;
  info[501].fileTimeHi = 0U;
  info[501].mFileTimeLo = 0U;
  info[501].mFileTimeHi = 0U;
  info[502].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  info[502].name = "eml_refblas_xswap";
  info[502].dominantType = "double";
  info[502].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  info[502].fileTimeLo = 1299101986U;
  info[502].fileTimeHi = 0U;
  info[502].mFileTimeLo = 0U;
  info[502].mFileTimeHi = 0U;
  info[503].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  info[503].name = "eml_index_class";
  info[503].dominantType = "";
  info[503].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[503].fileTimeLo = 1323195778U;
  info[503].fileTimeHi = 0U;
  info[503].mFileTimeLo = 0U;
  info[503].mFileTimeHi = 0U;
  info[504].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  info[504].name = "abs";
  info[504].dominantType = "coder.internal.indexInt";
  info[504].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[504].fileTimeLo = 1343855566U;
  info[504].fileTimeHi = 0U;
  info[504].mFileTimeLo = 0U;
  info[504].mFileTimeHi = 0U;
  info[505].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  info[505].name = "eml_int_forloop_overflow_check";
  info[505].dominantType = "";
  info[505].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[505].fileTimeLo = 1346535540U;
  info[505].fileTimeHi = 0U;
  info[505].mFileTimeLo = 0U;
  info[505].mFileTimeHi = 0U;
  info[506].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  info[506].name = "eml_index_minus";
  info[506].dominantType = "coder.internal.indexInt";
  info[506].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[506].fileTimeLo = 1286843978U;
  info[506].fileTimeHi = 0U;
  info[506].mFileTimeLo = 0U;
  info[506].mFileTimeHi = 0U;
  info[507].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  info[507].name = "eml_index_plus";
  info[507].dominantType = "coder.internal.indexInt";
  info[507].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[507].fileTimeLo = 1286843978U;
  info[507].fileTimeHi = 0U;
  info[507].mFileTimeLo = 0U;
  info[507].mFileTimeHi = 0U;
  info[508].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[508].name = "eml_div";
  info[508].dominantType = "double";
  info[508].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  info[508].fileTimeLo = 1313373010U;
  info[508].fileTimeHi = 0U;
  info[508].mFileTimeLo = 0U;
  info[508].mFileTimeHi = 0U;
  info[509].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  info[509].name = "eml_xgeru";
  info[509].dominantType = "double";
  info[509].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  info[509].fileTimeLo = 1299101974U;
  info[509].fileTimeHi = 0U;
  info[509].mFileTimeLo = 0U;
  info[509].mFileTimeHi = 0U;
  info[510].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  info[510].name = "eml_blas_inline";
  info[510].dominantType = "";
  info[510].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[510].fileTimeLo = 1299101968U;
  info[510].fileTimeHi = 0U;
  info[510].mFileTimeLo = 0U;
  info[510].mFileTimeHi = 0U;
  info[511].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  info[511].name = "eml_xger";
  info[511].dominantType = "double";
  info[511].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  info[511].fileTimeLo = 1299101974U;
  info[511].fileTimeHi = 0U;
  info[511].mFileTimeLo = 0U;
  info[511].mFileTimeHi = 0U;
}

static void i_emlrt_marshallIn(const mxArray *Pvk, const char_T *identifier,
  emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  j_emlrt_marshallIn(emlrtAlias(Pvk), &thisId, y);
  emlrtDestroyArray(&Pvk);
}

static void i_info_helper(ResolvedFunctionInfo info[567])
{
  info[512].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  info[512].name = "eml_index_minus";
  info[512].dominantType = "coder.internal.indexInt";
  info[512].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[512].fileTimeLo = 1286843978U;
  info[512].fileTimeHi = 0U;
  info[512].mFileTimeLo = 0U;
  info[512].mFileTimeHi = 0U;
  info[513].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  info[513].name = "eml_warning";
  info[513].dominantType = "char";
  info[513].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  info[513].fileTimeLo = 1286844002U;
  info[513].fileTimeHi = 0U;
  info[513].mFileTimeLo = 0U;
  info[513].mFileTimeHi = 0U;
  info[514].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  info[514].name = "eml_scalar_eg";
  info[514].dominantType = "double";
  info[514].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[514].fileTimeLo = 1286843996U;
  info[514].fileTimeHi = 0U;
  info[514].mFileTimeLo = 0U;
  info[514].mFileTimeHi = 0U;
  info[515].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  info[515].name = "eml_int_forloop_overflow_check";
  info[515].dominantType = "";
  info[515].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[515].fileTimeLo = 1346535540U;
  info[515].fileTimeHi = 0U;
  info[515].mFileTimeLo = 0U;
  info[515].mFileTimeHi = 0U;
  info[516].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  info[516].name = "eml_xtrsm";
  info[516].dominantType = "char";
  info[516].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  info[516].fileTimeLo = 1299101978U;
  info[516].fileTimeHi = 0U;
  info[516].mFileTimeLo = 0U;
  info[516].mFileTimeHi = 0U;
  info[517].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  info[517].name = "eml_blas_inline";
  info[517].dominantType = "";
  info[517].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[517].fileTimeLo = 1299101968U;
  info[517].fileTimeHi = 0U;
  info[517].mFileTimeLo = 0U;
  info[517].mFileTimeHi = 0U;
  info[518].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  info[518].name = "eml_index_class";
  info[518].dominantType = "";
  info[518].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[518].fileTimeLo = 1323195778U;
  info[518].fileTimeHi = 0U;
  info[518].mFileTimeLo = 0U;
  info[518].mFileTimeHi = 0U;
  info[519].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  info[519].name = "eml_scalar_eg";
  info[519].dominantType = "double";
  info[519].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[519].fileTimeLo = 1286843996U;
  info[519].fileTimeHi = 0U;
  info[519].mFileTimeLo = 0U;
  info[519].mFileTimeHi = 0U;
  info[520].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  info[520].name = "eml_refblas_xtrsm";
  info[520].dominantType = "char";
  info[520].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[520].fileTimeLo = 1299101986U;
  info[520].fileTimeHi = 0U;
  info[520].mFileTimeLo = 0U;
  info[520].mFileTimeHi = 0U;
  info[521].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[521].name = "eml_scalar_eg";
  info[521].dominantType = "double";
  info[521].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[521].fileTimeLo = 1286843996U;
  info[521].fileTimeHi = 0U;
  info[521].mFileTimeLo = 0U;
  info[521].mFileTimeHi = 0U;
  info[522].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[522].name = "eml_index_minus";
  info[522].dominantType = "double";
  info[522].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[522].fileTimeLo = 1286843978U;
  info[522].fileTimeHi = 0U;
  info[522].mFileTimeLo = 0U;
  info[522].mFileTimeHi = 0U;
  info[523].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[523].name = "eml_index_class";
  info[523].dominantType = "";
  info[523].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[523].fileTimeLo = 1323195778U;
  info[523].fileTimeHi = 0U;
  info[523].mFileTimeLo = 0U;
  info[523].mFileTimeHi = 0U;
  info[524].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[524].name = "eml_int_forloop_overflow_check";
  info[524].dominantType = "";
  info[524].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[524].fileTimeLo = 1346535540U;
  info[524].fileTimeHi = 0U;
  info[524].mFileTimeLo = 0U;
  info[524].mFileTimeHi = 0U;
  info[525].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[525].name = "eml_index_times";
  info[525].dominantType = "coder.internal.indexInt";
  info[525].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[525].fileTimeLo = 1286843980U;
  info[525].fileTimeHi = 0U;
  info[525].mFileTimeLo = 0U;
  info[525].mFileTimeHi = 0U;
  info[526].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[526].name = "eml_index_plus";
  info[526].dominantType = "coder.internal.indexInt";
  info[526].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[526].fileTimeLo = 1286843978U;
  info[526].fileTimeHi = 0U;
  info[526].mFileTimeLo = 0U;
  info[526].mFileTimeHi = 0U;
  info[527].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[527].name = "eml_index_plus";
  info[527].dominantType = "double";
  info[527].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[527].fileTimeLo = 1286843978U;
  info[527].fileTimeHi = 0U;
  info[527].mFileTimeLo = 0U;
  info[527].mFileTimeHi = 0U;
  info[528].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  info[528].name = "eml_div";
  info[528].dominantType = "double";
  info[528].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  info[528].fileTimeLo = 1313373010U;
  info[528].fileTimeHi = 0U;
  info[528].mFileTimeLo = 0U;
  info[528].mFileTimeHi = 0U;
  info[529].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  info[529].name = "eml_qrsolve";
  info[529].dominantType = "double";
  info[529].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[529].fileTimeLo = 1307676444U;
  info[529].fileTimeHi = 0U;
  info[529].mFileTimeLo = 0U;
  info[529].mFileTimeHi = 0U;
  info[530].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[530].name = "min";
  info[530].dominantType = "double";
  info[530].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[530].fileTimeLo = 1311280518U;
  info[530].fileTimeHi = 0U;
  info[530].mFileTimeLo = 0U;
  info[530].mFileTimeHi = 0U;
  info[531].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[531].name = "eml_xgeqp3";
  info[531].dominantType = "double";
  info[531].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  info[531].fileTimeLo = 1286844004U;
  info[531].fileTimeHi = 0U;
  info[531].mFileTimeLo = 0U;
  info[531].mFileTimeHi = 0U;
  info[532].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  info[532].name = "eml_lapack_xgeqp3";
  info[532].dominantType = "double";
  info[532].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  info[532].fileTimeLo = 1286844008U;
  info[532].fileTimeHi = 0U;
  info[532].mFileTimeLo = 0U;
  info[532].mFileTimeHi = 0U;
  info[533].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  info[533].name = "eml_matlab_zgeqp3";
  info[533].dominantType = "double";
  info[533].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[533].fileTimeLo = 1290024566U;
  info[533].fileTimeHi = 0U;
  info[533].mFileTimeLo = 0U;
  info[533].mFileTimeHi = 0U;
  info[534].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[534].name = "eml_index_class";
  info[534].dominantType = "";
  info[534].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[534].fileTimeLo = 1323195778U;
  info[534].fileTimeHi = 0U;
  info[534].mFileTimeLo = 0U;
  info[534].mFileTimeHi = 0U;
  info[535].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[535].name = "min";
  info[535].dominantType = "coder.internal.indexInt";
  info[535].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[535].fileTimeLo = 1311280518U;
  info[535].fileTimeHi = 0U;
  info[535].mFileTimeLo = 0U;
  info[535].mFileTimeHi = 0U;
  info[536].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[536].name = "eml_scalar_eg";
  info[536].dominantType = "double";
  info[536].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[536].fileTimeLo = 1286843996U;
  info[536].fileTimeHi = 0U;
  info[536].mFileTimeLo = 0U;
  info[536].mFileTimeHi = 0U;
  info[537].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[537].name = "colon";
  info[537].dominantType = "coder.internal.indexInt";
  info[537].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  info[537].fileTimeLo = 1348217128U;
  info[537].fileTimeHi = 0U;
  info[537].mFileTimeLo = 0U;
  info[537].mFileTimeHi = 0U;
  info[538].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[538].name = "eps";
  info[538].dominantType = "char";
  info[538].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[538].fileTimeLo = 1326753196U;
  info[538].fileTimeHi = 0U;
  info[538].mFileTimeLo = 0U;
  info[538].mFileTimeHi = 0U;
  info[539].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[539].name = "sqrt";
  info[539].dominantType = "double";
  info[539].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[539].fileTimeLo = 1343855586U;
  info[539].fileTimeHi = 0U;
  info[539].mFileTimeLo = 0U;
  info[539].mFileTimeHi = 0U;
  info[540].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[540].name = "eml_int_forloop_overflow_check";
  info[540].dominantType = "";
  info[540].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[540].fileTimeLo = 1346535540U;
  info[540].fileTimeHi = 0U;
  info[540].mFileTimeLo = 0U;
  info[540].mFileTimeHi = 0U;
  info[541].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[541].name = "eml_xnrm2";
  info[541].dominantType = "double";
  info[541].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  info[541].fileTimeLo = 1299101976U;
  info[541].fileTimeHi = 0U;
  info[541].mFileTimeLo = 0U;
  info[541].mFileTimeHi = 0U;
  info[542].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[542].name = "eml_index_plus";
  info[542].dominantType = "coder.internal.indexInt";
  info[542].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[542].fileTimeLo = 1286843978U;
  info[542].fileTimeHi = 0U;
  info[542].mFileTimeLo = 0U;
  info[542].mFileTimeHi = 0U;
  info[543].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[543].name = "eml_index_minus";
  info[543].dominantType = "double";
  info[543].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[543].fileTimeLo = 1286843978U;
  info[543].fileTimeHi = 0U;
  info[543].mFileTimeLo = 0U;
  info[543].mFileTimeHi = 0U;
  info[544].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[544].name = "eml_index_plus";
  info[544].dominantType = "double";
  info[544].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[544].fileTimeLo = 1286843978U;
  info[544].fileTimeHi = 0U;
  info[544].mFileTimeLo = 0U;
  info[544].mFileTimeHi = 0U;
  info[545].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[545].name = "eml_index_times";
  info[545].dominantType = "coder.internal.indexInt";
  info[545].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[545].fileTimeLo = 1286843980U;
  info[545].fileTimeHi = 0U;
  info[545].mFileTimeLo = 0U;
  info[545].mFileTimeHi = 0U;
  info[546].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[546].name = "eml_index_minus";
  info[546].dominantType = "coder.internal.indexInt";
  info[546].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[546].fileTimeLo = 1286843978U;
  info[546].fileTimeHi = 0U;
  info[546].mFileTimeLo = 0U;
  info[546].mFileTimeHi = 0U;
  info[547].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[547].name = "eml_ixamax";
  info[547].dominantType = "double";
  info[547].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  info[547].fileTimeLo = 1299101970U;
  info[547].fileTimeHi = 0U;
  info[547].mFileTimeLo = 0U;
  info[547].mFileTimeHi = 0U;
  info[548].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[548].name = "eml_xswap";
  info[548].dominantType = "double";
  info[548].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  info[548].fileTimeLo = 1299101978U;
  info[548].fileTimeHi = 0U;
  info[548].mFileTimeLo = 0U;
  info[548].mFileTimeHi = 0U;
  info[549].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[549].name = "eml_matlab_zlarfg";
  info[549].dominantType = "double";
  info[549].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  info[549].fileTimeLo = 1286844022U;
  info[549].fileTimeHi = 0U;
  info[549].mFileTimeLo = 0U;
  info[549].mFileTimeHi = 0U;
  info[550].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[550].name = "eml_matlab_zlarf";
  info[550].dominantType = "char";
  info[550].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[550].fileTimeLo = 1286844022U;
  info[550].fileTimeHi = 0U;
  info[550].mFileTimeLo = 0U;
  info[550].mFileTimeHi = 0U;
  info[551].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[551].name = "coder.internal.indexIntRelop";
  info[551].dominantType = "";
  info[551].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[551].fileTimeLo = 1326753522U;
  info[551].fileTimeHi = 0U;
  info[551].mFileTimeLo = 0U;
  info[551].mFileTimeHi = 0U;
  info[552].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  info[552].name = "eml_index_times";
  info[552].dominantType = "double";
  info[552].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[552].fileTimeLo = 1286843980U;
  info[552].fileTimeHi = 0U;
  info[552].mFileTimeLo = 0U;
  info[552].mFileTimeHi = 0U;
  info[553].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[553].name = "abs";
  info[553].dominantType = "double";
  info[553].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[553].fileTimeLo = 1343855566U;
  info[553].fileTimeHi = 0U;
  info[553].mFileTimeLo = 0U;
  info[553].mFileTimeHi = 0U;
  info[554].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  info[554].name = "mtimes";
  info[554].dominantType = "double";
  info[554].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[554].fileTimeLo = 1289544892U;
  info[554].fileTimeHi = 0U;
  info[554].mFileTimeLo = 0U;
  info[554].mFileTimeHi = 0U;
  info[555].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[555].name = "max";
  info[555].dominantType = "double";
  info[555].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  info[555].fileTimeLo = 1311280516U;
  info[555].fileTimeHi = 0U;
  info[555].mFileTimeLo = 0U;
  info[555].mFileTimeHi = 0U;
  info[556].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[556].name = "eml_xcabs1";
  info[556].dominantType = "double";
  info[556].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  info[556].fileTimeLo = 1286843906U;
  info[556].fileTimeHi = 0U;
  info[556].mFileTimeLo = 0U;
  info[556].mFileTimeHi = 0U;
  info[557].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[557].name = "mtimes";
  info[557].dominantType = "double";
  info[557].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[557].fileTimeLo = 1289544892U;
  info[557].fileTimeHi = 0U;
  info[557].mFileTimeLo = 0U;
  info[557].mFileTimeHi = 0U;
  info[558].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[558].name = "eps";
  info[558].dominantType = "char";
  info[558].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[558].fileTimeLo = 1326753196U;
  info[558].fileTimeHi = 0U;
  info[558].mFileTimeLo = 0U;
  info[558].mFileTimeHi = 0U;
  info[559].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[559].name = "eml_flt2str";
  info[559].dominantType = "double";
  info[559].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  info[559].fileTimeLo = 1309476396U;
  info[559].fileTimeHi = 0U;
  info[559].mFileTimeLo = 0U;
  info[559].mFileTimeHi = 0U;
  info[560].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  info[560].name = "char";
  info[560].dominantType = "double";
  info[560].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  info[560].fileTimeLo = 1319755168U;
  info[560].fileTimeHi = 0U;
  info[560].mFileTimeLo = 0U;
  info[560].mFileTimeHi = 0U;
  info[561].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[561].name = "eml_warning";
  info[561].dominantType = "char";
  info[561].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  info[561].fileTimeLo = 1286844002U;
  info[561].fileTimeHi = 0U;
  info[561].mFileTimeLo = 0U;
  info[561].mFileTimeHi = 0U;
  info[562].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[562].name = "eml_scalar_eg";
  info[562].dominantType = "double";
  info[562].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[562].fileTimeLo = 1286843996U;
  info[562].fileTimeHi = 0U;
  info[562].mFileTimeLo = 0U;
  info[562].mFileTimeHi = 0U;
  info[563].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[563].name = "eml_conjtimes";
  info[563].dominantType = "double";
  info[563].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  info[563].fileTimeLo = 1286843896U;
  info[563].fileTimeHi = 0U;
  info[563].mFileTimeLo = 0U;
  info[563].mFileTimeHi = 0U;
  info[564].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  info[564].name = "eml_div";
  info[564].dominantType = "double";
  info[564].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  info[564].fileTimeLo = 1313373010U;
  info[564].fileTimeHi = 0U;
  info[564].mFileTimeLo = 0U;
  info[564].mFileTimeHi = 0U;
  info[565].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[565].name = "minangle";
  info[565].dominantType = "double";
  info[565].resolved =
    "[E]/home/tim/github/Summer2014/cooperative estimation/2D/minangle.m";
  info[565].fileTimeLo = 1411329554U;
  info[565].fileTimeHi = 0U;
  info[565].mFileTimeLo = 0U;
  info[565].mFileTimeHi = 0U;
  info[566].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[566].name = "rdivide";
  info[566].dominantType = "double";
  info[566].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[566].fileTimeLo = 1346535588U;
  info[566].fileTimeHi = 0U;
  info[566].mFileTimeLo = 0U;
  info[566].mFileTimeHi = 0U;
}

static void info_helper(ResolvedFunctionInfo info[567])
{
  info[0].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[0].name = "length";
  info[0].dominantType = "double";
  info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  info[0].fileTimeLo = 1303171406U;
  info[0].fileTimeHi = 0U;
  info[0].mFileTimeLo = 0U;
  info[0].mFileTimeHi = 0U;
  info[1].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[1].name = "mtimes";
  info[1].dominantType = "double";
  info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[1].fileTimeLo = 1289544892U;
  info[1].fileTimeHi = 0U;
  info[1].mFileTimeLo = 0U;
  info[1].mFileTimeHi = 0U;
  info[2].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[2].name = "mpower";
  info[2].dominantType = "double";
  info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  info[2].fileTimeLo = 1286844042U;
  info[2].fileTimeHi = 0U;
  info[2].mFileTimeLo = 0U;
  info[2].mFileTimeHi = 0U;
  info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  info[3].name = "power";
  info[3].dominantType = "double";
  info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  info[3].fileTimeLo = 1348217130U;
  info[3].fileTimeHi = 0U;
  info[3].mFileTimeLo = 0U;
  info[3].mFileTimeHi = 0U;
  info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  info[4].name = "eml_scalar_eg";
  info[4].dominantType = "double";
  info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[4].fileTimeLo = 1286843996U;
  info[4].fileTimeHi = 0U;
  info[4].mFileTimeLo = 0U;
  info[4].mFileTimeHi = 0U;
  info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  info[5].name = "eml_scalexp_alloc";
  info[5].dominantType = "double";
  info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[5].fileTimeLo = 1352450060U;
  info[5].fileTimeHi = 0U;
  info[5].mFileTimeLo = 0U;
  info[5].mFileTimeHi = 0U;
  info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  info[6].name = "floor";
  info[6].dominantType = "double";
  info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[6].fileTimeLo = 1343855580U;
  info[6].fileTimeHi = 0U;
  info[6].mFileTimeLo = 0U;
  info[6].mFileTimeHi = 0U;
  info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[7].name = "eml_scalar_floor";
  info[7].dominantType = "double";
  info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  info[7].fileTimeLo = 1286843926U;
  info[7].fileTimeHi = 0U;
  info[7].mFileTimeLo = 0U;
  info[7].mFileTimeHi = 0U;
  info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  info[8].name = "eml_scalar_eg";
  info[8].dominantType = "double";
  info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[8].fileTimeLo = 1286843996U;
  info[8].fileTimeHi = 0U;
  info[8].mFileTimeLo = 0U;
  info[8].mFileTimeHi = 0U;
  info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  info[9].name = "mtimes";
  info[9].dominantType = "double";
  info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[9].fileTimeLo = 1289544892U;
  info[9].fileTimeHi = 0U;
  info[9].mFileTimeLo = 0U;
  info[9].mFileTimeHi = 0U;
  info[10].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[10].name = "sqrt";
  info[10].dominantType = "double";
  info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[10].fileTimeLo = 1343855586U;
  info[10].fileTimeHi = 0U;
  info[10].mFileTimeLo = 0U;
  info[10].mFileTimeHi = 0U;
  info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[11].name = "eml_error";
  info[11].dominantType = "char";
  info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  info[11].fileTimeLo = 1343855558U;
  info[11].fileTimeHi = 0U;
  info[11].mFileTimeLo = 0U;
  info[11].mFileTimeHi = 0U;
  info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[12].name = "eml_scalar_sqrt";
  info[12].dominantType = "double";
  info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  info[12].fileTimeLo = 1286843938U;
  info[12].fileTimeHi = 0U;
  info[12].mFileTimeLo = 0U;
  info[12].mFileTimeHi = 0U;
  info[13].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[13].name = "colon";
  info[13].dominantType = "double";
  info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  info[13].fileTimeLo = 1348217128U;
  info[13].fileTimeHi = 0U;
  info[13].mFileTimeLo = 0U;
  info[13].mFileTimeHi = 0U;
  info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  info[14].name = "colon";
  info[14].dominantType = "double";
  info[14].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  info[14].fileTimeLo = 1348217128U;
  info[14].fileTimeHi = 0U;
  info[14].mFileTimeLo = 0U;
  info[14].mFileTimeHi = 0U;
  info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  info[15].name = "isfinite";
  info[15].dominantType = "double";
  info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  info[15].fileTimeLo = 1286843958U;
  info[15].fileTimeHi = 0U;
  info[15].mFileTimeLo = 0U;
  info[15].mFileTimeHi = 0U;
  info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  info[16].name = "isinf";
  info[16].dominantType = "double";
  info[16].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  info[16].fileTimeLo = 1286843960U;
  info[16].fileTimeHi = 0U;
  info[16].mFileTimeLo = 0U;
  info[16].mFileTimeHi = 0U;
  info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  info[17].name = "isnan";
  info[17].dominantType = "double";
  info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[17].fileTimeLo = 1286843960U;
  info[17].fileTimeHi = 0U;
  info[17].mFileTimeLo = 0U;
  info[17].mFileTimeHi = 0U;
  info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  info[18].name = "floor";
  info[18].dominantType = "double";
  info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[18].fileTimeLo = 1343855580U;
  info[18].fileTimeHi = 0U;
  info[18].mFileTimeLo = 0U;
  info[18].mFileTimeHi = 0U;
  info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs";
  info[19].name = "abs";
  info[19].dominantType = "double";
  info[19].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[19].fileTimeLo = 1343855566U;
  info[19].fileTimeHi = 0U;
  info[19].mFileTimeLo = 0U;
  info[19].mFileTimeHi = 0U;
  info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[20].name = "eml_scalar_abs";
  info[20].dominantType = "double";
  info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  info[20].fileTimeLo = 1286843912U;
  info[20].fileTimeHi = 0U;
  info[20].mFileTimeLo = 0U;
  info[20].mFileTimeHi = 0U;
  info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  info[21].name = "eps";
  info[21].dominantType = "double";
  info[21].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[21].fileTimeLo = 1326753196U;
  info[21].fileTimeHi = 0U;
  info[21].mFileTimeLo = 0U;
  info[21].mFileTimeHi = 0U;
  info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[22].name = "eml_mantissa_nbits";
  info[22].dominantType = "char";
  info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  info[22].fileTimeLo = 1307676442U;
  info[22].fileTimeHi = 0U;
  info[22].mFileTimeLo = 0U;
  info[22].mFileTimeHi = 0U;
  info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  info[23].name = "eml_float_model";
  info[23].dominantType = "char";
  info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  info[23].fileTimeLo = 1326753196U;
  info[23].fileTimeHi = 0U;
  info[23].mFileTimeLo = 0U;
  info[23].mFileTimeHi = 0U;
  info[24].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[24].name = "eml_realmin";
  info[24].dominantType = "char";
  info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  info[24].fileTimeLo = 1307676444U;
  info[24].fileTimeHi = 0U;
  info[24].mFileTimeLo = 0U;
  info[24].mFileTimeHi = 0U;
  info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  info[25].name = "eml_float_model";
  info[25].dominantType = "char";
  info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  info[25].fileTimeLo = 1326753196U;
  info[25].fileTimeHi = 0U;
  info[25].mFileTimeLo = 0U;
  info[25].mFileTimeHi = 0U;
  info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[26].name = "eml_realmin_denormal";
  info[26].dominantType = "char";
  info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  info[26].fileTimeLo = 1326753198U;
  info[26].fileTimeHi = 0U;
  info[26].mFileTimeLo = 0U;
  info[26].mFileTimeHi = 0U;
  info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  info[27].name = "eml_float_model";
  info[27].dominantType = "char";
  info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  info[27].fileTimeLo = 1326753196U;
  info[27].fileTimeHi = 0U;
  info[27].mFileTimeLo = 0U;
  info[27].mFileTimeHi = 0U;
  info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[28].name = "abs";
  info[28].dominantType = "double";
  info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[28].fileTimeLo = 1343855566U;
  info[28].fileTimeHi = 0U;
  info[28].mFileTimeLo = 0U;
  info[28].mFileTimeHi = 0U;
  info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[29].name = "isfinite";
  info[29].dominantType = "double";
  info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  info[29].fileTimeLo = 1286843958U;
  info[29].fileTimeHi = 0U;
  info[29].mFileTimeLo = 0U;
  info[29].mFileTimeHi = 0U;
  info[30].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[30].name = "eml_guarded_nan";
  info[30].dominantType = "";
  info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  info[30].fileTimeLo = 1286843976U;
  info[30].fileTimeHi = 0U;
  info[30].mFileTimeLo = 0U;
  info[30].mFileTimeHi = 0U;
  info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  info[31].name = "realmax";
  info[31].dominantType = "char";
  info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  info[31].fileTimeLo = 1307676442U;
  info[31].fileTimeHi = 0U;
  info[31].mFileTimeLo = 0U;
  info[31].mFileTimeHi = 0U;
  info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  info[32].name = "eml_realmax";
  info[32].dominantType = "char";
  info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  info[32].fileTimeLo = 1326753196U;
  info[32].fileTimeHi = 0U;
  info[32].mFileTimeLo = 0U;
  info[32].mFileTimeHi = 0U;
  info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  info[33].name = "eml_float_model";
  info[33].dominantType = "char";
  info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  info[33].fileTimeLo = 1326753196U;
  info[33].fileTimeHi = 0U;
  info[33].mFileTimeLo = 0U;
  info[33].mFileTimeHi = 0U;
  info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  info[34].name = "mtimes";
  info[34].dominantType = "double";
  info[34].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[34].fileTimeLo = 1289544892U;
  info[34].fileTimeHi = 0U;
  info[34].mFileTimeLo = 0U;
  info[34].mFileTimeHi = 0U;
  info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[35].name = "isnan";
  info[35].dominantType = "double";
  info[35].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[35].fileTimeLo = 1286843960U;
  info[35].fileTimeHi = 0U;
  info[35].mFileTimeLo = 0U;
  info[35].mFileTimeHi = 0U;
  info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[36].name = "eml_index_class";
  info[36].dominantType = "";
  info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[36].fileTimeLo = 1323195778U;
  info[36].fileTimeHi = 0U;
  info[36].mFileTimeLo = 0U;
  info[36].mFileTimeHi = 0U;
  info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[37].name = "eml_guarded_nan";
  info[37].dominantType = "char";
  info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  info[37].fileTimeLo = 1286843976U;
  info[37].fileTimeHi = 0U;
  info[37].mFileTimeLo = 0U;
  info[37].mFileTimeHi = 0U;
  info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  info[38].name = "eml_is_float_class";
  info[38].dominantType = "char";
  info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  info[38].fileTimeLo = 1286843982U;
  info[38].fileTimeHi = 0U;
  info[38].mFileTimeLo = 0U;
  info[38].mFileTimeHi = 0U;
  info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[39].name = "isinf";
  info[39].dominantType = "double";
  info[39].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  info[39].fileTimeLo = 1286843960U;
  info[39].fileTimeHi = 0U;
  info[39].mFileTimeLo = 0U;
  info[39].mFileTimeHi = 0U;
  info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[40].name = "floor";
  info[40].dominantType = "double";
  info[40].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[40].fileTimeLo = 1343855580U;
  info[40].fileTimeHi = 0U;
  info[40].mFileTimeLo = 0U;
  info[40].mFileTimeHi = 0U;
  info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[41].name = "mtimes";
  info[41].dominantType = "double";
  info[41].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[41].fileTimeLo = 1289544892U;
  info[41].fileTimeHi = 0U;
  info[41].mFileTimeLo = 0U;
  info[41].mFileTimeHi = 0U;
  info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[42].name = "abs";
  info[42].dominantType = "double";
  info[42].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  info[42].fileTimeLo = 1343855566U;
  info[42].fileTimeHi = 0U;
  info[42].mFileTimeLo = 0U;
  info[42].mFileTimeHi = 0U;
  info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[43].name = "eps";
  info[43].dominantType = "char";
  info[43].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[43].fileTimeLo = 1326753196U;
  info[43].fileTimeHi = 0U;
  info[43].mFileTimeLo = 0U;
  info[43].mFileTimeHi = 0U;
  info[44].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[44].name = "eml_is_float_class";
  info[44].dominantType = "char";
  info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  info[44].fileTimeLo = 1286843982U;
  info[44].fileTimeHi = 0U;
  info[44].mFileTimeLo = 0U;
  info[44].mFileTimeHi = 0U;
  info[45].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  info[45].name = "eml_eps";
  info[45].dominantType = "char";
  info[45].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  info[45].fileTimeLo = 1326753196U;
  info[45].fileTimeHi = 0U;
  info[45].mFileTimeLo = 0U;
  info[45].mFileTimeHi = 0U;
  info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  info[46].name = "eml_float_model";
  info[46].dominantType = "char";
  info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  info[46].fileTimeLo = 1326753196U;
  info[46].fileTimeHi = 0U;
  info[46].mFileTimeLo = 0U;
  info[46].mFileTimeHi = 0U;
  info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[47].name = "intmax";
  info[47].dominantType = "char";
  info[47].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[47].fileTimeLo = 1311280516U;
  info[47].fileTimeHi = 0U;
  info[47].mFileTimeLo = 0U;
  info[47].mFileTimeHi = 0U;
  info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  info[48].name = "coder.internal.indexIntRelop";
  info[48].dominantType = "";
  info[48].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[48].fileTimeLo = 1326753522U;
  info[48].fileTimeHi = 0U;
  info[48].mFileTimeLo = 0U;
  info[48].mFileTimeHi = 0U;
  info[49].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  info[49].name = "eml_float_model";
  info[49].dominantType = "char";
  info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  info[49].fileTimeLo = 1326753196U;
  info[49].fileTimeHi = 0U;
  info[49].mFileTimeLo = 0U;
  info[49].mFileTimeHi = 0U;
  info[50].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  info[50].name = "intmin";
  info[50].dominantType = "char";
  info[50].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  info[50].fileTimeLo = 1311280518U;
  info[50].fileTimeHi = 0U;
  info[50].mFileTimeLo = 0U;
  info[50].mFileTimeHi = 0U;
  info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  info[51].name = "eml_index_minus";
  info[51].dominantType = "double";
  info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[51].fileTimeLo = 1286843978U;
  info[51].fileTimeHi = 0U;
  info[51].mFileTimeLo = 0U;
  info[51].mFileTimeHi = 0U;
  info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[52].name = "eml_index_class";
  info[52].dominantType = "";
  info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[52].fileTimeLo = 1323195778U;
  info[52].fileTimeHi = 0U;
  info[52].mFileTimeLo = 0U;
  info[52].mFileTimeHi = 0U;
  info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  info[53].name = "eml_index_rdivide";
  info[53].dominantType = "double";
  info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  info[53].fileTimeLo = 1286843980U;
  info[53].fileTimeHi = 0U;
  info[53].mFileTimeLo = 0U;
  info[53].mFileTimeHi = 0U;
  info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  info[54].name = "eml_index_class";
  info[54].dominantType = "";
  info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[54].fileTimeLo = 1323195778U;
  info[54].fileTimeHi = 0U;
  info[54].mFileTimeLo = 0U;
  info[54].mFileTimeHi = 0U;
  info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  info[55].name = "eml_int_forloop_overflow_check";
  info[55].dominantType = "";
  info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[55].fileTimeLo = 1346535540U;
  info[55].fileTimeHi = 0U;
  info[55].mFileTimeLo = 0U;
  info[55].mFileTimeHi = 0U;
  info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  info[56].name = "intmax";
  info[56].dominantType = "char";
  info[56].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[56].fileTimeLo = 1311280516U;
  info[56].fileTimeHi = 0U;
  info[56].mFileTimeLo = 0U;
  info[56].mFileTimeHi = 0U;
  info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  info[57].name = "mtimes";
  info[57].dominantType = "double";
  info[57].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[57].fileTimeLo = 1289544892U;
  info[57].fileTimeHi = 0U;
  info[57].mFileTimeLo = 0U;
  info[57].mFileTimeHi = 0U;
  info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  info[58].name = "eml_index_times";
  info[58].dominantType = "double";
  info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[58].fileTimeLo = 1286843980U;
  info[58].fileTimeHi = 0U;
  info[58].mFileTimeLo = 0U;
  info[58].mFileTimeHi = 0U;
  info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[59].name = "eml_index_class";
  info[59].dominantType = "";
  info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[59].fileTimeLo = 1323195778U;
  info[59].fileTimeHi = 0U;
  info[59].mFileTimeLo = 0U;
  info[59].mFileTimeHi = 0U;
  info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  info[60].name = "eml_index_plus";
  info[60].dominantType = "double";
  info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[60].fileTimeLo = 1286843978U;
  info[60].fileTimeHi = 0U;
  info[60].mFileTimeLo = 0U;
  info[60].mFileTimeHi = 0U;
  info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[61].name = "eml_index_class";
  info[61].dominantType = "";
  info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[61].fileTimeLo = 1323195778U;
  info[61].fileTimeHi = 0U;
  info[61].mFileTimeLo = 0U;
  info[61].mFileTimeHi = 0U;
  info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  info[62].name = "eml_index_minus";
  info[62].dominantType = "coder.internal.indexInt";
  info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[62].fileTimeLo = 1286843978U;
  info[62].fileTimeHi = 0U;
  info[62].mFileTimeLo = 0U;
  info[62].mFileTimeHi = 0U;
  info[63].context =
    "[E]/home/tim/github/Summer2014/cooperative estimation/3D/full_w_unknown_features/ukf_update_unknown_state.m";
  info[63].name = "sqrtm";
  info[63].dominantType = "double";
  info[63].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/sqrtm.m";
  info[63].fileTimeLo = 1305343202U;
  info[63].fileTimeHi = 0U;
  info[63].mFileTimeLo = 0U;
  info[63].mFileTimeHi = 0U;
}

static void j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  q_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const mxArray *uk, const char_T *identifier,
  real_T (**y_data)[100], int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  l_emlrt_marshallIn(emlrtAlias(uk), &thisId, y_data, y_size);
  emlrtDestroyArray(&uk);
}

static void l_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T (**y_data)[100], int32_T y_size[1])
{
  r_emlrt_marshallIn(emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T (**ret_data)[200], int32_T ret_size[1])
{
  int32_T iv108[1];
  boolean_T bv0[1];
  int32_T iv109[1];
  iv108[0] = 200;
  bv0[0] = TRUE;
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 1U,
    iv108, bv0, iv109);
  ret_size[0] = iv109[0];
  *ret_data = (real_T (*)[200])mxGetData(src);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv110[2];
  boolean_T bv1[2];
  int32_T i;
  int32_T iv111[2];
  for (i = 0; i < 2; i++) {
    iv110[i] = 200;
    bv1[i] = TRUE;
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 2U,
    iv110, bv1, iv111);
  ret->size[0] = iv111[0];
  ret->size[1] = iv111[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = FALSE;
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv112[2];
  boolean_T bv2[2];
  int32_T i;
  int32_T iv113[2];
  for (i = 0; i < 2; i++) {
    iv112[i] = 100;
    bv2[i] = TRUE;
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 2U,
    iv112, bv2, iv113);
  ret->size[0] = iv113[0];
  ret->size[1] = iv113[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = FALSE;
  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T (**ret_data)[100], int32_T ret_size[1])
{
  int32_T iv114[1];
  boolean_T bv3[1];
  int32_T iv115[1];
  iv114[0] = 100;
  bv3[0] = TRUE;
  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 1U,
    iv114, bv3, iv115);
  ret_size[0] = iv115[0];
  *ret_data = (real_T (*)[100])mxGetData(src);
  emlrtDestroyArray(&src);
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  ResolvedFunctionInfo info[567];
  nameCaptureInfo = NULL;
  info_helper(info);
  b_info_helper(info);
  c_info_helper(info);
  d_info_helper(info);
  e_info_helper(info);
  f_info_helper(info);
  g_info_helper(info);
  h_info_helper(info);
  i_info_helper(info);
  emlrtAssign(&nameCaptureInfo, b_emlrt_marshallOut(info));
  emlrtNameCapturePostProcessR2012a(emlrtAlias(nameCaptureInfo));
  return nameCaptureInfo;
}

void ukf_update_unknown_state_api(const mxArray * const prhs[7], const mxArray
  *plhs[2])
{
  real_T (*xnew_data)[200];
  emxArray_real_T *Pxk;
  emxArray_real_T *Pvk;
  emxArray_real_T *Pnk;
  int32_T xk_size[1];
  real_T (*xk_data)[200];
  int32_T uk_size[1];
  real_T (*uk_data)[100];
  int32_T ytilde_size[1];
  real_T (*ytilde_data)[200];
  real_T alpha;
  const mxArray *tmp;
  emxArray_real_T *Pnew;
  int32_T xnew_size[1];
  xnew_data = (real_T (*)[200])mxMalloc(sizeof(real_T [200]));
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&Pxk, 2, &sb_emlrtRTEI, TRUE);
  emxInit_real_T(&Pvk, 2, &sb_emlrtRTEI, TRUE);
  emxInit_real_T(&Pnk, 2, &sb_emlrtRTEI, TRUE);

  /* Marshall function inputs */
  e_emlrt_marshallIn(emlrtAlias(prhs[0]), "xk", &xk_data, xk_size);
  g_emlrt_marshallIn(emlrtAlias(prhs[1]), "Pxk", Pxk);
  i_emlrt_marshallIn(emlrtAlias(prhs[2]), "Pvk", Pvk);
  g_emlrt_marshallIn(emlrtAlias(prhs[3]), "Pnk", Pnk);
  k_emlrt_marshallIn(emlrtAlias(prhs[4]), "uk", &uk_data, uk_size);
  e_emlrt_marshallIn(emlrtAlias(prhs[5]), "ytilde", &ytilde_data, ytilde_size);
  alpha = emlrt_marshallIn(emlrtAliasP(prhs[6]), "alpha");

  /* Marshall in global variables */
  tmp = mexGetVariable("global", "Ts");
  if (tmp) {
    Ts = emlrt_marshallIn(tmp, "Ts");
    Ts_dirty = 0U;
  }

  emxInit_real_T(&Pnew, 2, &sb_emlrtRTEI, TRUE);

  /* Invoke the target function */
  ukf_update_unknown_state(*xk_data, xk_size, Pxk, Pvk, Pnk, *uk_data, uk_size, *
    ytilde_data, ytilde_size, alpha, *xnew_data, xnew_size, Pnew);

  /* Marshall out global variables */
  mexPutVariable("global", "Ts", emlrt_marshallOut(Ts));

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(*xnew_data, xnew_size);
  plhs[1] = d_emlrt_marshallOut(Pnew);
  Pnew->canFreeData = FALSE;
  emxFree_real_T(&Pnew);
  Pnk->canFreeData = FALSE;
  emxFree_real_T(&Pnk);
  Pvk->canFreeData = FALSE;
  emxFree_real_T(&Pvk);
  Pxk->canFreeData = FALSE;
  emxFree_real_T(&Pxk);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (ukf_update_unknown_state_api.c) */
