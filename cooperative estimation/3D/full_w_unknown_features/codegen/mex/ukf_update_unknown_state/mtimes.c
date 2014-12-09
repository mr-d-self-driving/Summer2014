/*
 * mtimes.c
 *
 * Code generation for function 'mtimes'
 *
 * C source code generated on: Tue Dec  9 10:58:58 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_unknown_state.h"
#include "mtimes.h"
#include "ukf_update_unknown_state_mexutil.h"
#include "ukf_update_unknown_state_data.h"
#include <stdio.h>

/* Function Definitions */
void dynamic_size_checks(const emxArray_creal_T *a, const emxArray_creal_T *b)
{
  const mxArray *y;
  static const int32_T iv38[2] = { 1, 45 };

  const mxArray *m5;
  char_T cv18[45];
  int32_T i;
  static const char_T cv19[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D',
    'y', 'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p',
    'a', 'n', 's', 'i', 'o', 'n' };

  const mxArray *b_y;
  static const int32_T iv39[2] = { 1, 21 };

  char_T cv20[21];
  static const char_T cv21[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  if (!(a->size[1] == b->size[0])) {
    if (((a->size[0] == 1) && (a->size[1] == 1)) || ((b->size[0] == 1) &&
         (b->size[1] == 1))) {
      emlrtPushRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      y = NULL;
      m5 = mxCreateCharArray(2, iv38);
      for (i = 0; i < 45; i++) {
        cv18[i] = cv19[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m5, cv18);
      emlrtAssign(&y, m5);
      error(message(y, &l_emlrtMCI), &m_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&kh_emlrtRSI, emlrtRootTLSGlobal);
    } else {
      emlrtPushRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
      emlrt_synchGlobalsToML();
      b_y = NULL;
      m5 = mxCreateCharArray(2, iv39);
      for (i = 0; i < 21; i++) {
        cv20[i] = cv21[i];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m5, cv20);
      emlrtAssign(&b_y, m5);
      error(message(b_y, &n_emlrtMCI), &o_emlrtMCI);
      emlrt_synchGlobalsFromML();
      emlrtPopRtStackR2012b(&jh_emlrtRSI, emlrtRootTLSGlobal);
    }
  }
}

/* End of code generation (mtimes.c) */
