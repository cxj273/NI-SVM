
#include "fisher.h"
using namespace std;
template<class T>
fisher<T>::fisher( fisher_param &_param )
  : snum(0), param(_param), gmm(0), iwgh(0), istd(0), s0(0), s1(0), s2(0), fv(0) 
{
  ngrad = (int)param.grad_weights + (int)param.grad_means + (int)param.grad_variances;
  assert( (param.alpha>0.0) && (param.alpha<=1.0) );
}

template<class T>
fisher<T>::~fisher()
{
  delete[] iwgh;
  iwgh = NULL;

  delete[] istd;
  istd = NULL;
  delete[] fv;

  delete[] s0;

  for(int i = 0; i < ngauss; i++)
  {
    delete[] s1[i];
  }

  delete[] s1;

  for(int i = 0; i < ngauss; i++)
  {
    delete[] s2[i];
  }

  delete[] s2;

  gmm = NULL;
}

template<class T>
void
fisher<T>::set_model( gaussian_mixture<T> &_gmm )
{
  gmm = &_gmm;
  ndim = gmm->n_dim();
  ngauss = gmm->n_gauss();

  fkdim = 0;
  if( param.grad_weights )
  {
    fkdim += ngauss;
  }
  if( param.grad_means )
  {
    fkdim += ngauss*ndim;
  }
  if( param.grad_variances )
  {
    fkdim += ngauss*ndim;
  }
  fv = new T[fkdim];
  memset( fv, 0, sizeof(T)*fkdim);

  delete[] iwgh;

  // precompute inverse weights
  iwgh = new T[ngauss];
  for( int j=0; j<ngauss; ++j )
  {
    assert( gmm->coef[j]>0.0 );
    iwgh[j] = 1.0/gmm->coef[j];
  } 

  // precompute inverse standard deviations
  if( param.grad_means || param.grad_variances )
  {
    delete[] istd;
    istd = new T[ngauss*ndim];

    for( int j=0; j<ngauss; ++j ) 
    {
      T *var_j = gmm->var[j];
      T *istd_j = istd+j*ndim;
      for( int k=ndim; k--; ) 
      {
        assert( var_j[k]>0.0 );
        istd_j[k] = (T)1.0/(T)sqrtf( (float)var_j[k] );
      }
    }    
  }
/*
  std::cerr << "ngauss: " << ngauss << std::endl;
  for(int j = 0; j < ngauss; j++)
  {
    T *mean_j = gmm->mean[j];
    for (int k = ndim; k < ndim; k++)
        std::cerr << mean_j[k] << " ";
    std::cerr << std::endl;
  }
*/
  s0 = new T[ngauss];
  memset(s0, 0, ngauss * sizeof(T));
  s1 = new T*[ngauss];
  for(int k = ngauss;k--;)
  {
      s1[k] = new T[ndim];
      memset(s1[k], 0, ndim*sizeof(T));
  }
  s2 = new T*[ngauss];
  for(int k = ngauss; k--;)
  {
      s2[k] = new T[ndim];
      memset(s2[k], 0, ndim*sizeof(T));
  }
}


template<class T>
int
fisher<T>::compute( std::vector<T*> &x, T *fk )
{
  std::vector<T> wghx( x.size(), 1.0 );  
  return compute( x, wghx, fk );
}

// Author: Xiaojun Chang
// Date: 2014.07.02
template<class T>
void
fisher<T>::AddOne( T* sample)
{
    assert(gmm);
    
    gmm->accumulate_statistics( sample, true, param.grad_means||param.grad_variances, param.grad_variances, s0, s1, s2);
    snum ++;
}

// Author: Xiaojun Chang
// Date: 2014.07.02
template<class T>
void
fisher<T>::Compute()
{
    cerr << "snum: " << snum << endl;

    assert(gmm);
    
    int ngauss = gmm->n_gauss();
    int ndim = gmm->n_dim();

    std::vector<T> wghx( snum, 1.0);
    T wghsum = 0.0;

    for(int i = 0; i < snum; i++)
    {
        wghsum += wghx[i];
    }

    assert(wghsum > 0);

    T *p = fv;

    //Gradient w.r.t the means
    
    for(int j = 0; j < ngauss; j++)
    {
        T *s1_j = s1[j];
        T *mean_j = gmm->mean[j];
        T *istd_j = istd + j*ndim;
        T *p_j = p + j*ndim;
        T mc = (T)sqrtf((float)iwgh[j])/wghsum;

        for(int k = ndim; k--; )
        {
            p_j[k] = mc * (s1_j[k] - mean_j[k] * s0[j]) * istd_j[k];
        }
    }

    p += ngauss*ndim;

    // Gradient w.r.t the variances
    //
    for(int j = 0; j < ngauss; j++)
    {
        T *s1_j = s1[j];
        T *s2_j = s2[j];
        T *mean_j = gmm->mean[j];
        T *var_j = gmm->var[j];
        T *p_j = p+j*ndim;
        T vc = (T)sqrtf(0.5f*(float)iwgh[j]) / wghsum;

        for(int k = ndim; k--; )
        {
            p_j[k] = vc * ( ( s2_j[k] + mean_j[k] *(mean_j[k] * s0[j] - (T)2.0*s1_j[k] ) ) / var_j[k] - s0[j]);
        }
    }
}

template<class T>
int 
fisher<T>::compute( std::vector<T*> &x, std::vector<T> &wghx, T *fk )
{  

  assert(gmm);

  assert( x.size()==wghx.size() );

  int nsamples = (int)wghx.size();

  T wghsum=0.0;
#pragma omp parallel for reduction(+:wghsum)
  for( int i=0; i<nsamples; ++i ) 
  {
    wghsum += wghx[i];
  }

  assert( wghsum>0 );

  // accumulate statistics
  /*gmm->reset_stat_acc();
  for( int i=0; i<nsamples; ++i ) 
  {
    gmm->accumulate_statistics( x[i], true, param.grad_means||param.grad_variances, param.grad_variances );
  }*/
  T *s0, **s1, **s2;
  int ngauss = gmm->n_gauss();
  int ndim = gmm->n_dim();
  {
    s0 = new T[ngauss];
    memset( s0, 0, ngauss*sizeof(T));
    s1 = new T*[ngauss];
    for( int k=ngauss; k--; )
    {
      s1[k] = new T[ndim];
      memset( s1[k], 0, ndim*sizeof(T));
    }
    s2 = new T*[ngauss];
    for( int k=ngauss; k--; )
    {
      s2[k] = new T[ndim];
      memset( s2[k], 0, ndim*sizeof(T));
    }
    for( int i=0; i<nsamples; ++i )
    {
      gmm->accumulate_statistics( x[i], true, param.grad_means||param.grad_variances, param.grad_variances,
				  s0, s1, s2 );
    }
  }

  T *p=fk;

  // Gradient w.r.t. the mixing weights
  // without the constraint \sum_i pi_i=1 => Soft-BoV
  if( param.grad_weights )
  {
    for( int j=ngauss; j--; ) 
    {        
      p[j] = s0[j] / ( wghsum*(T)sqrtf((float)iwgh[j]) );
    } 
    p += ngauss;
  }

  // Gradient w.r.t. the means
  if( param.grad_means )
  {
#pragma omp parallel for
    for( int j=0; j<ngauss; j++ ) 
    {
      T *s1_j = s1[j];
      T *mean_j = gmm->mean[j];
      T *istd_j = istd+j*ndim;
      T *p_j = p+j*ndim;
      T mc = (T)sqrtf((float)iwgh[j])/wghsum;

      for( int k=ndim; k--; ) 
      {
        p_j[k] = mc * ( s1_j[k] - mean_j[k] * s0[j] ) * istd_j[k];
      }      
    }
    p += ngauss*ndim;     
  }


  // Gradient w.r.t. the variances
  if( param.grad_variances )
  {

#pragma omp parallel for
    for( int j=0; j<ngauss; j++ ) 
    {
      T *s1_j = s1[j];
      T *s2_j = s2[j];
      T *mean_j = gmm->mean[j];
      T *var_j = gmm->var[j];
      T *p_j = p+j*ndim;
      T vc = (T)sqrtf(0.5f*(float)iwgh[j])/wghsum;

      for( int k=ndim; k--; ) 
      {
        p_j[k] = vc * ( ( s2_j[k] + mean_j[k] * ( mean_j[k]*s0[j] - (T)2.0*s1_j[k] ) ) / var_j[k] - s0[j] );
      }   
    }
  } 
  
  alpha_and_lp_normalization();
  
  return 0;
}


// Author: Xiaojun Chang
// Date: 2014.07.02
template<class T>
void
fisher<T>::AddSub(fisher<T> *sub_fisher)
{
    assert(gmm);

    int ngauss = gmm->n_gauss();
    int ndim = gmm->n_dim();

    for(int i = 0; i < ngauss; i++)
    {
        s0[i] += sub_fisher->s0[i];
        for(int j = 0; j < ndim; j++)
        {
            s1[i][j] += sub_fisher->s1[i][j];
            s2[i][j] += sub_fisher->s2[i][j];
        }
    }

    snum += sub_fisher->get_num();
    
}

template<class T>
void
fisher<T>::alpha_and_lp_normalization()
{

  // alpha normalization
  if( !equal(param.alpha,1.0f) )
  {
    if( equal(param.alpha,0.5f) )
    {
#pragma omp parallel for
      for( int i=0; i<fkdim; i++ )
      {
        if( fv[i]<0.0 )
          fv[i] = -std::sqrt(-fv[i]);
        else
          fv[i] = std::sqrt(fv[i]);
      }
    }
    else
    {
#pragma omp parallel for
      for( int i=0; i<fkdim; i++ )
      {
        if( fv[i]<0.0 )
          fv[i] = -std::pow(-fv[i],(T)param.alpha);
        else
          fv[i] = std::pow(fv[i],(T)param.alpha);
      }
    }
  }

  // Lp normalization
  if( !equal(param.pnorm,(float)0.0) )
  {
    T pnorm=0;
    if( equal(param.pnorm,(float)1.0) )
    {
#pragma omp parallel for reduction(+:pnorm)
      for( int i=0; i<fkdim; ++i )
      {
        pnorm += std::fabs(fv[i]);
      }
    }
    else if( equal(param.pnorm,2.0) )
    {
      pnorm = sqrt( simd::dot_product( fkdim, fv, fv ) );
    }
    else
    {
#pragma omp parallel for reduction(+:pnorm)
      for( int i=0; i<fkdim; ++i )
      {
        pnorm += std::pow( std::fabs(fv[i]), (T)param.pnorm );
      }
      pnorm = std::pow( (double)pnorm, (double)1.0/(T)param.pnorm );
    }

    if( pnorm>0.0 )
    {
      simd::scale( fkdim, fv, (T)(1.0/pnorm) );
    }
  }
}

template<class T>
T* 
fisher<T>::get_fv()
{
    return fv;
}

template<class T>
int
fisher<T>::get_num()
{
    return snum;
}

/// \bief print
/// 
/// \param none
///
/// \return none
///
/// \author Jorge Sanchez
/// \date    August 2009

void
fisher_param::print()
{
  std::cout << "  grad_weights = " << grad_weights << std::endl;
  std::cout << "  grad_means = " << grad_means << std::endl;
  std::cout << "  grad_variances = " << grad_variances << std::endl;
  std::cout << "  alpha = " << alpha << std::endl;
  std::cout << "  pnorm = " << pnorm << std::endl;
}

template class fisher<float>;
template class fisher<double>;
