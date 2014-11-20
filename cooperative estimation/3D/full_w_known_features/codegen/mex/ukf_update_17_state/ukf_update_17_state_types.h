/*
 * ukf_update_17_state_types.h
 *
 * Code generation for function 'ukf_update_17_state'
 *
 * C source code generated on: Thu Nov 20 12:39:29 2014
 *
 */

#ifndef __UKF_UPDATE_17_STATE_TYPES_H__
#define __UKF_UPDATE_17_STATE_TYPES_H__

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
#ifndef struct_emxArray_real_T_1x25
#define struct_emxArray_real_T_1x25
struct emxArray_real_T_1x25
{
    real_T data[25];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x25*/
#ifndef typedef_emxArray_real_T_1x25
#define typedef_emxArray_real_T_1x25
typedef struct emxArray_real_T_1x25 emxArray_real_T_1x25;
#endif /*typedef_emxArray_real_T_1x25*/
#ifndef struct_emxArray_real_T_1x250
#define struct_emxArray_real_T_1x250
struct emxArray_real_T_1x250
{
    real_T data[250];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x250*/
#ifndef typedef_emxArray_real_T_1x250
#define typedef_emxArray_real_T_1x250
typedef struct emxArray_real_T_1x250 emxArray_real_T_1x250;
#endif /*typedef_emxArray_real_T_1x250*/
#ifndef struct_emxArray_real_T_1x601
#define struct_emxArray_real_T_1x601
struct emxArray_real_T_1x601
{
    real_T data[601];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x601*/
#ifndef typedef_emxArray_real_T_1x601
#define typedef_emxArray_real_T_1x601
typedef struct emxArray_real_T_1x601 emxArray_real_T_1x601;
#endif /*typedef_emxArray_real_T_1x601*/
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
#ifndef struct_emxArray_real_T_299
#define struct_emxArray_real_T_299
struct emxArray_real_T_299
{
    real_T data[299];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_299*/
#ifndef typedef_emxArray_real_T_299
#define typedef_emxArray_real_T_299
typedef struct emxArray_real_T_299 emxArray_real_T_299;
#endif /*typedef_emxArray_real_T_299*/
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

#endif
/* End of code generation (ukf_update_17_state_types.h) */
