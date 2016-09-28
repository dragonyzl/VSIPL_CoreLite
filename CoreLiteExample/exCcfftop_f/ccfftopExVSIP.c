/* Created by RJudd August 27, 1998*/
/* SPAWARSYSCEN D881 */
#include<vsip.h>
#include<sys/types.h>
#include<sys/timeb.h>

#define VU_PI 3.141592653589793
#define F  .15
#define LL 24
#define LP 33
#define delta .0000000001

int main (int argc,char *argv[]) { vsip_init((void*)0);{
vsip_length L = LL;
vsip_length Lp;
if(argc != 1) L = (vsip_length) atoi(argv[1]);
Lp = (LP > L) ? L : LP;
{
  int i;
  vsip_cvview_f* vector = vsip_cvcreate_f(L,0);
  vsip_cvview_f* vectorOUT = vsip_cvcreate_f(L,0);
  vsip_vview_f* realIn = vsip_vrealview_f(vector);
  vsip_vview_f* imagIn = vsip_vimagview_f(vector);
  vsip_fft_f* fftplan = vsip_ccfftop_create_f(L,1,-1,0,0);
  vsip_fft_f* fftplanI = vsip_ccfftop_create_f(L,(double)(1.0/L),1,0,0);
  char printDataOne[LP][25],
       printDataTwo[LP][35];

  { int k; for(k=0; k<1; k++){
  /* put some data in realIn*/
  vsip_vramp_f(0, 2 * VU_PI * F, realIn);
  vsip_vcos_f(realIn,realIn);
  /* print realIn */
  for(i=0; i<Lp; i++){ 
       sprintf(printDataOne[i],"%2d input -> %8.5f",i, vsip_vget_f(realIn,i)+delta);
  }
  /*make sure imagIn is full of zeros*/
  vsip_vfill_f(0,imagIn);
  /*find the fft*/
  {
    int ftime(struct timeb *tp);
    struct timeb begin;
    struct timeb finish;
    ftime(&begin);
    vsip_ccfftop_f(fftplan,vector,vectorOUT);
    ftime(&finish);
    printf("%8.4f\n",(finish.time + finish.millitm/1000.0)-(begin.time + begin.millitm/1000.0));
  }
  for(i=0; i<Lp; i++){
     sprintf(printDataTwo[i]," fft -> (%8.4f, %8.4f)",
           vsip_real_f(vsip_cvget_f(vectorOUT,i))+delta,
           vsip_imag_f(vsip_cvget_f(vectorOUT,i))+delta);
  }
  /*invert the fft*/
  vsip_ccfftop_f(fftplanI,vectorOUT,vector); 
  /*print it */
  for(i=0; i<Lp; i++){
     printf("%s %s  ifft -> (%8.4f, %8.4f)\n",
           printDataOne[i],
           printDataTwo[i],
           vsip_real_f(vsip_cvget_f(vector,i))+delta,
           vsip_imag_f(vsip_cvget_f(vector,i))+delta);
  }
  }} 
  {
     vsip_vdestroy_f((void*)imagIn);
     vsip_vdestroy_f((void*)realIn);
     vsip_cblockdestroy_f(vsip_cvdestroy_f((void*)vector));
     vsip_fft_destroy_f((void*)fftplan); 
     vsip_fft_destroy_f((void*)fftplanI);
  }
  }vsip_finalize((void*)0);return 0;
}
}
