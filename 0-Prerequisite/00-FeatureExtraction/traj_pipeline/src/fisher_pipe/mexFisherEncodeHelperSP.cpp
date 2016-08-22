/*
 * mexFisherEncodeHelper.cxx
 *
 * handle = mexFisherEncodeHelper('init',gmm_mat,<fisher_params>)
 * FV = mexFisherEncodeHelper('encode',handle,x,<weights>)
 * mexFisherEncodeHelper('clear',handle)
 *
 * Author: Ken Chatfield
 * July 2011
 *
 * This is a MEX-file for MATLAB.
 */

#include "gmm-fisher/fisher.h"
#include "gmm-fisher/gmm.h"
#include "fisher_handle.h"
#include "mexFisherEncodeHelperSP.h"
#include <set>
#include <vector>
#include <string>
#include <string.h>
#include "FisherVectorEncode_emxutil.h"

fisher_handle<float>* fisher_init(const emxArray_real32_T* codebook_mean, const emxArray_real32_T* codebook_variance, const emxArray_real32_T* codebook_coef, int32_T num_gaussians, int32_T pca_dim, boolean_T encoder_grad_weights, boolean_T encoder_grad_means, boolean_T encoder_grad_variances, real32_T encoder_alpha, real32_T encoder_pnorm){
	float *mean_arr = (float*)codebook_mean -> data;
	float *variance_arr = (float*)codebook_variance -> data;
	float *coef_arr = (float*)codebook_coef -> data;
	int n_gauss = num_gaussians;
	int n_dim = pca_dim;
	//validate GMM field dimensions
	//size_t mean_mat_m = codebook_mean -> size[0];
	//size_t mean_mat_n = codebook_mean -> size[1];
	//size_t variance_mat_m = codebook_variance -> size[0];
	//size_t variance_mat_n = codebook_variance -> size[1];
	//size_t coef_mat_m = codebook_coef -> size[0];
	//size_t coef_mat_n = codebook_coef -> size[1];
	
	// convert GMM field arrays to vectors
	std::vector<float*> mean(n_gauss);
	std::vector<float*> variance(n_gauss);
	for (int j = 0; j < n_gauss; ++j) {
		mean[j] = &mean_arr[j*n_dim];
		variance[j] = &variance_arr[j*n_dim];
	}
	std::vector<float> coef(coef_arr, coef_arr + n_gauss);
	// prepare a GMM model with data from the structure
	gaussian_mixture<float> *gmmproc = new gaussian_mixture<float>(n_gauss,n_dim);
	gmmproc->set(mean, variance, coef);

	// construct a c++ struct with default parameter values
	fisher_param fisher_encoder_params;

	fisher_encoder_params.grad_weights = encoder_grad_weights;
	fisher_encoder_params.grad_means = encoder_grad_means;
	fisher_encoder_params.grad_variances = encoder_grad_variances;
	fisher_encoder_params.alpha = encoder_alpha;
	fisher_encoder_params.pnorm = encoder_pnorm;
	fisher_encoder_params.gamma_eps = 0; //not used....
	//fprintf(stderr, "%d %d %d %g %g\n", encoder_grad_weights, encoder_grad_means, encoder_grad_variances, encoder_alpha, encoder_pnorm);

	fisher_handle<float> *fisher_encoder =
		new fisher_handle<float>(*gmmproc,fisher_encoder_params);
	// initialise encoder with a GMM model (vocabulary)
	fisher_encoder->set_model(*gmmproc);
	//fprintf(stderr, "dim %d\n", fisher_encoder->dim());
	//exit(-1);
	// return handle to fisher encoder class instance
	return fisher_encoder;
}

void fisher_encode(fisher_handle<float> *fisher_encoder, emxArray_real32_T* x, emxArray_real32_T* fv, int n_gauss, int n_dim ){
	float *x_arr = x -> data;
	size_t x_m = x -> size[0];
	size_t x_n = x -> size[1];
	// convert input vectors to c++ std::vector format
	std::vector<float*> xptr(x_n);
	for (int j = 0; j < x_n; ++j) {
		xptr[j] = &x_arr[j*x_m];
	}
	// do encoding
        int32_T i0 = fv->size[0] * fv->size[1];
        fv -> size[0] = fisher_encoder -> dim();
        fv -> size[1] = 1;
        emxEnsureCapacity((emxArray__common *)fv, i0, (int32_T)sizeof(real32_T));
	float* fk = fv -> data;
	fisher_encoder->compute(xptr, fk);
}

/*
void fisher_clear(){
	// get encoder from handle
	fisher_handle<float> *fisher_encoder =
		convertMat2Ptr<float>(prhs[1]);
	gaussian_mixture<float>* gmmproc = fisher_encoder->getGmmPtr();
	if (gmmproc)
		delete gmmproc;
	delete fisher_encoder;
}
*/
















