/*
 * update_eq_17_state_types.h
 *
 * Code generation for function 'update_eq_17_state'
 *
 * C source code generated on: Thu Nov 20 12:06:54 2014
 *
 */

#ifndef __UPDATE_EQ_17_STATE_TYPES_H__
#define __UPDATE_EQ_17_STATE_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /*typedef_emxArray_real_T*/
#ifndef struct_emxArray_real_T_100
#define struct_emxArray_real_T_100
struct emxArray_real_T_100
{
    real_T data[100];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_100*/
#ifndef typedef_emxArray_real_T_100
#define typedef_emxArray_real_T_100
typedef struct emxArray_real_T_100 emxArray_real_T_100;
#endif /*typedef_emxArray_real_T_100*/
#ifndef struct_emxArray_real_T_25
#define struct_emxArray_real_T_25
struct emxArray_real_T_25
{
    real_T data[25];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_25*/
#ifndef typedef_emxArray_real_T_25
#define typedef_emxArray_real_T_25
typedef struct emxArray_real_T_25 emxArray_real_T_25;
#endif /*typedef_emxArray_real_T_25*/

#endif
/* End of code generation (update_eq_17_state_types.h) */
