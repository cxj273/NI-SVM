/*
 * FEencode.cpp
 *
 * Code generation for function 'FEencode'
 *
 * C source code generated on: Sat Sep  7 16:14:47 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FisherVectorEncode.h"
#include "FEencode.h"
#include "FisherVectorEncode_emxutil.h"
#include "rand.h"
#include "mexFisherEncodeHelperSP.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * function code = FEencode(obj, x)
 */
void FEencode(int32_T obj_codebook__n_gauss, int32_T obj_codebook__n_dim,
              emxArray_real32_T *x, emxArray_real32_T *code, fisher_handle<float>* fh)
{
  fisher_encode(fh, x, code, obj_codebook__n_gauss, obj_codebook__n_dim);
/*
  fprintf(stderr, "FEencode: got vector length %d\n", code->size[0]);
      for (int i9 = 0; i9 <= 10; i9++) {
		fprintf(stderr, "c %g\n", code->data[i9]);
      }
exit(-1);
*/
  /* mexFisherEncodeHelperSPmat('encode', obj.fc_.cpp_handle, x); */
}

/* End of code generation (FEencode.cpp) */
