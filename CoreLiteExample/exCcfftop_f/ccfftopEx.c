/* Created by RJudd */
/* SPAWARSYSCEN D881 */
#include<vsip.h>

#define VU_PI 3.141592653589793
#define F  .15
#define L  64

int main () { vsip_init((void*)0);{
  int i;
  vsip_cblock_f* blockOut = vsip_cblockcreate_f(2 * L/2, 0);
  vsip_cvview_f* vectorOut = vsip_cvbind_f(blockOut,0,2,L/2);
  vsip_cvview_f* vectorIn = vsip_cvcreate_f(L/2,0);
  vsip_vview_f* realIn = vsip_vrealview_f(vectorIn);
  vsip_vview_f* imagIn = vsip_vimagview_f(vectorIn);
  vsip_vview_f* data = vsip_vcreate_f(L,0); /*n*/
  vsip_fft_f* fftplan = vsip_ccfftop_create_f(L/2,1,-1,0,0);
  vsip_fft_f* fftplanI = vsip_ccfftop_create_f(L/2,(double)2/L,1,0,0);
  char inputdata[L][30];

  /* put some data in realIn
  vsip_vramp_f(0, 2 * VU_PI * F, realIn);
  vsip_vcos_f(realIn,realIn); */
  vsip_vramp_f(0,2 * VU_PI * F, data);
  vsip_vcos_f(data,data);
  vsip_vputlength_f(data,L/2);
  vsip_vputstride_f(data,2);
  vsip_vcopy_f_f(data,realIn);
  vsip_vputoffset_f(data,1);
  vsip_vcopy_f_f(data,imagIn);
  /* print realIn */
  for(i=0; i<L/2; i++)
       sprintf(inputdata[i],"%2d input-> %7.3f + %7.3fi",i, 
           vsip_real_f(vsip_cvget_f(vectorIn,i)),
           vsip_imag_f(vsip_cvget_f(vectorIn,i)));
  /*make sure imagIn is full of zeros*/
/*  vsip_vfill_f(0,imagIn);*/

  /*find the fft*/
  vsip_ccfftop_f(fftplan,vectorIn,vectorOut);
  /*invert the fft*/
  vsip_ccfftop_f(fftplanI,vectorOut,vectorIn);
  /*print it */
  for(i=0; i<L/2; i++)
     printf("%s   fft -> (%7.3f, %7.3f)   ifft -> (%7.3f, %7.3f)\n",
           inputdata[i],
           vsip_real_f(vsip_cvget_f(vectorOut,i)),
           vsip_imag_f(vsip_cvget_f(vectorOut,i)),
           vsip_real_f(vsip_cvget_f(vectorIn,i)),
           vsip_imag_f(vsip_cvget_f(vectorIn,i)));
  {
     vsip_vdestroy_f(imagIn);
     vsip_vdestroy_f(realIn);
     vsip_valldestroy_f(data);
     vsip_cblockdestroy_f(vsip_cvdestroy_f(vectorIn));
     vsip_cblockdestroy_f(vsip_cvdestroy_f(vectorOut));
     vsip_fft_destroy_f(fftplan);
     vsip_fft_destroy_f(fftplanI);
  }
  }vsip_finalize((void*)0);return 0;
}
