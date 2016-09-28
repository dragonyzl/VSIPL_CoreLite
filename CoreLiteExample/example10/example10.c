#include<stdio.h>
#include<vsip.h>
#define RNL 1024  /* length of random vector */
#define RNS 17 /* random number seed */
#define RNT VSIP_PRNG /* random number type */
int main(){vsip_init((void*)0);
{
   vsip_cvview_f *fft = vsip_cvcreate_f(RNL, 0),
                 *invfft = vsip_cvcreate_f(RNL, 0);
   vsip_randstate *state = vsip_randcreate(RNS,1,1,RNT);
   vsip_vview_f   *input = vsip_vcreate_f(RNL, 0);
   vsip_fft_f *rcfft = vsip_rcfftop_create_f(RNL,1,0,0);
   vsip_fft_f *ccfftI = vsip_ccfftop_create_f(
            RNL, 1.0/RNL, VSIP_FFT_INV,0,0);
   vsip_vrandu_f(state,input);
   vsip_cvputlength_f(fft,RNL/2+1);
   vsip_rcfftop_f(rcfft, input, fft);
   vsip_cvputoffset_f(fft, 1);
   vsip_cvputlength_f(fft, RNL/2-1);
   { /* fill out the forward fft to full length */
      vsip_cvview_f *temp = vsip_cvcloneview_f(fft);
      vsip_cvattr_f at; vsip_cvgetattrib_f(temp,&at);
      at.offset = RNL - 1; at.stride = - 1;
      vsip_cvputattrib_f(temp,&at);
      vsip_cvconj_f(fft,temp); vsip_cvdestroy_f(temp);
   }
   vsip_cvputoffset_f(fft,0);
   vsip_cvputlength_f(fft,RNL);
   vsip_ccfftop_f(ccfftI,fft,invfft);
   { /* compare results */
      vsip_vview_f *real = vsip_vrealview_f(invfft);
      vsip_vview_f *result = vsip_vimagview_f(invfft);
      vsip_vsub_f(input,real,result);
      printf("%f\n",vsip_vsumsqval_f(result)/RNL);
      vsip_vdestroy_f(real); vsip_vdestroy_f(result);
   }
   vsip_fft_destroy_f(rcfft);
   vsip_fft_destroy_f(ccfftI);
   vsip_randdestroy(state);
   vsip_cvalldestroy_f(fft);
   vsip_cvalldestroy_f(invfft);
   vsip_valldestroy_f(input);
}
vsip_finalize((void*)0);
return 1;
}
