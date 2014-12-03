/*
 * attparsilentmex.c
 *
 * Code generation for function 'attparsilentmex'
 *
 * C source code generated on: Wed Dec  3 17:28:48 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_update_10_state.h"
#include "attparsilentmex.h"
#include <stdio.h>

/* Function Definitions */
void attparsilentmex(const real_T X[4], real_T Y[9])
{
  /* Tim Woodbury */
  /* modified for AERO 622 */
  /*  */
  /* [Y] = attpar(X,I,options) */
  /* Function to convert between attitude parametrizations */
  /*  */
  /* INPUTS: */
  /* X - matrix input of appropriate dimension (detailed later) */
  /* I - 2 x 1 indexing vector indicating the input (I(1)) and output (I(2)) */
  /*     attitude parametrizations, corresponding to the numbers in the section, */
  /*     "I/O SPECIFICATION PARAMETERS". */
  /* options - a data structure. Currently only allows output Euler angle */
  /*     sequence to be defined. Supported members are "seq" which should be a */
  /*     [3 x 1] vector describing the first, second, and third rotations in */
  /*     the desired output sequence. */
  /*  */
  /* OUTPUTS: */
  /* Y - output matrix of appropriate dimensions. */
  /*     All angles are in radians. */
  /*  */
  /* I/O SPECIFICATION PARAMETERS: */
  /* 1 - Direction cosine matrix, dimensions [3 x 3] */
  /* 2 - Euler principal axis/angle, [3 x 2]. [:,1] is the principal axis; */
  /*     [1,2] is the principal angle (rad). */
  /* 3 - 2-angle parametrization, [3 x 4] */
  /* 4 - Euler angle sequence, [3 x 2]. [:,1] are the rotation angles in radians,  */
  /*      and [2,1]-[2,2]-[2,3] is the rotation sequence.  */
  /*      [3-1-3] sequence is default for output. Other sequences may be specified */
  /*      by passing an optional data structure with a [3 x 1] member "seq" whose */
  /*      entries [a;b;c] correspond to the sequence a-b-c. Any input sequence */
  /*      may be used by specifying the second column of input appropriately. */
  /* 5 - Classical Rodrigues parameters [3 x 1] */
  /* 6 - quaternion [4 x 1]. The scalar part of the quaternion comes FIRST. */
  /* 7 - modified Rodrigues parameters [3 x 1] */
  /* 8 - exponential matrix, [3 x 3] */
  /* 9 - Cayley-Klein parameters, [2 x 2] */
  /* check if any options are passed */
  /* %check if output and inp are the same - if so do nothing */
  /* for each inp, convert to DCM */
  /* quaternion */
  /* disp('Input value specified as quaternion.'); */
  /* convert DCM to output form */
  /* DCM */
  /* disp('Output value specified as direction cosine matrix.'); */
  Y[0] = ((X[1] * X[1] - X[2] * X[2]) - X[3] * X[3]) + X[0] * X[0];
  Y[3] = 2.0 * (X[1] * X[2] + X[3] * X[0]);
  Y[6] = 2.0 * (X[1] * X[3] - X[2] * X[0]);
  Y[1] = 2.0 * (X[1] * X[2] - X[3] * X[0]);
  Y[4] = ((X[2] * X[2] - X[1] * X[1]) - X[3] * X[3]) + X[0] * X[0];
  Y[7] = 2.0 * (X[2] * X[3] + X[1] * X[0]);
  Y[2] = 2.0 * (X[1] * X[3] + X[2] * X[0]);
  Y[5] = 2.0 * (X[2] * X[3] - X[1] * X[0]);
  Y[8] = ((X[3] * X[3] - X[1] * X[1]) - X[2] * X[2]) + X[0] * X[0];
}

/* End of code generation (attparsilentmex.c) */
