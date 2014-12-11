/*
 * ukf_update_unknown_state_types.h
 *
 * Code generation for function 'ukf_update_unknown_state'
 *
 * C source code generated on: Thu Dec 11 11:40:53 2014
 *
 */

#ifndef __UKF_UPDATE_UNKNOWN_STATE_TYPES_H__
#define __UKF_UPDATE_UNKNOWN_STATE_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_ResolvedFunctionInfo
#define typedef_ResolvedFunctionInfo
typedef struct
{
    const char * context;
    const char * name;
    const char * dominantType;
    const char * resolved;
    uint32_T fileTimeLo;
    uint32_T fileTimeHi;
    uint32_T mFileTimeLo;
    uint32_T mFileTimeHi;
} ResolvedFunctionInfo;
#endif /*typedef_ResolvedFunctionInfo*/
#ifndef struct_emxArray__common
#define struct_emxArray__common
struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray__common*/
#ifndef typedef_emxArray__common
#define typedef_emxArray__common
typedef struct emxArray__common emxArray__common;
#endif /*typedef_emxArray__common*/
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T
{
    boolean_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_boolean_T*/
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /*typedef_emxArray_boolean_T*/
#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T
struct emxArray_creal_T
{
    creal_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_creal_T*/
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct emxArray_creal_T emxArray_creal_T;
#endif /*typedef_emxArray_creal_T*/
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_int32_T*/
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /*typedef_emxArray_int32_T*/
#ifndef struct_emxArray_int32_T_4
#define struct_emxArray_int32_T_4
struct emxArray_int32_T_4
{
    int32_T data[4];
    int32_T size[1];
};
#endif /*struct_emxArray_int32_T_4*/
#ifndef typedef_emxArray_int32_T_4
#define typedef_emxArray_int32_T_4
typedef struct emxArray_int32_T_4 emxArray_int32_T_4;
#endif /*typedef_emxArray_int32_T_4*/
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
#ifndef struct_emxArray_real_T_1x100
#define struct_emxArray_real_T_1x100
struct emxArray_real_T_1x100
{
    real_T data[100];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x100*/
#ifndef typedef_emxArray_real_T_1x100
#define typedef_emxArray_real_T_1x100
typedef struct emxArray_real_T_1x100 emxArray_real_T_1x100;
#endif /*typedef_emxArray_real_T_1x100*/
#ifndef struct_emxArray_real_T_1x1001
#define struct_emxArray_real_T_1x1001
struct emxArray_real_T_1x1001
{
    real_T data[1001];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x1001*/
#ifndef typedef_emxArray_real_T_1x1001
#define typedef_emxArray_real_T_1x1001
typedef struct emxArray_real_T_1x1001 emxArray_real_T_1x1001;
#endif /*typedef_emxArray_real_T_1x1001*/
#ifndef struct_emxArray_real_T_1x200
#define struct_emxArray_real_T_1x200
struct emxArray_real_T_1x200
{
    real_T data[200];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x200*/
#ifndef typedef_emxArray_real_T_1x200
#define typedef_emxArray_real_T_1x200
typedef struct emxArray_real_T_1x200 emxArray_real_T_1x200;
#endif /*typedef_emxArray_real_T_1x200*/
#ifndef struct_emxArray_real_T_200
#define struct_emxArray_real_T_200
struct emxArray_real_T_200
{
    real_T data[200];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_200*/
#ifndef typedef_emxArray_real_T_200
#define typedef_emxArray_real_T_200
typedef struct emxArray_real_T_200 emxArray_real_T_200;
#endif /*typedef_emxArray_real_T_200*/
#ifndef struct_emxArray_real_T_4
#define struct_emxArray_real_T_4
struct emxArray_real_T_4
{
    real_T data[4];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_4*/
#ifndef typedef_emxArray_real_T_4
#define typedef_emxArray_real_T_4
typedef struct emxArray_real_T_4 emxArray_real_T_4;
#endif /*typedef_emxArray_real_T_4*/
#ifndef struct_emxArray_real_T_499
#define struct_emxArray_real_T_499
struct emxArray_real_T_499
{
    real_T data[499];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_499*/
#ifndef typedef_emxArray_real_T_499
#define typedef_emxArray_real_T_499
typedef struct emxArray_real_T_499 emxArray_real_T_499;
#endif /*typedef_emxArray_real_T_499*/

#endif
/* End of code generation (ukf_update_unknown_state_types.h) */
