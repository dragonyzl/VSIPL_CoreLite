/* Created by RJudd */
/* SPAWARSYSCEN D881 */
#include<vsip.h>

#define VU_PI 3.141592653589793
#define F  .15
#define L  64

int main (){vsip_init((void*)0);
{
  int i;
  vsip_cvview_f* vectorOut = vsip_cvcreate_f(L/2 + 1,0);
  vsip_vview_f* vectorIn = vsip_vcreate_f(L,0);
  vsip_vview_f* ivectorOut = vsip_vcreate_f(L,0);
  vsip_fft_f* fftplan  = vsip_rcfftop_create_f(L,1.0,0,0);
  vsip_fft_f* ifftplan = vsip_crfftop_create_f(L,(double)(1.0/L),0,0);
  char printbuffer[L/2][40];

  vsip_vramp_f(0, 2 * VU_PI * F, vectorIn);
  vsip_vcos_f(vectorIn,vectorIn);

  /* print vectorIn */
  for(i=0; i<L/2; i++)
       sprintf(printbuffer[i],"%2d, %2d input-> %7.3f, %7.3f",i, i+L/2, vsip_vget_f(vectorIn,i), vsip_vget_f(vectorIn,i+L/2));

  /*find the fft*/
  vsip_rcfftop_f(fftplan,vectorIn,vectorOut);
  /*find the inverse fft*/
  vsip_crfftop_f(ifftplan,vectorOut,ivectorOut);
  /*print it */
  for(i=0; i<L/2; i++)
     printf("%s   fft -> (%9.4f, %9.4f) ifft-> %7.3f, %7.3f\n" ,
           printbuffer[i],
           vsip_real_f(vsip_cvget_f(vectorOut,i)),
           vsip_imag_f(vsip_cvget_f(vectorOut,i)),
           vsip_vget_f(ivectorOut,i), 
           vsip_vget_f(ivectorOut,i+L/2));
  printf("                                  fft -> (%9.4f, %9.4f)\n",
           vsip_real_f(vsip_cvget_f(vectorOut,i)),
           vsip_imag_f(vsip_cvget_f(vectorOut,i)));
  {
     vsip_cvalldestroy_f(vectorOut);
     vsip_valldestroy_f(vectorIn);
     vsip_fft_destroy_f(fftplan);
  }
}vsip_finalize((void*)0); return 0;
}
