#include<stdio.h>
#include<vsip.h>
#define N   1024
#define avg 1000
#define D      2
#define RNS  17       /* Random Number Seed */
#define RNT VSIP_PRNG /* Random Number Type */
void VU_vprint_f(vsip_vview_f*);
int main(){ vsip_init((void*)0);
{
   int i;
   vsip_vview_f *dataIn   = vsip_vcreate_f(D * N,0);
   vsip_cvview_f *dataFFT = vsip_cvcreate_f(N/2 + 1,0);
   vsip_vview_f *dataOut  = vsip_vcreate_f(N,0);
   vsip_vview_f *spect_avg = vsip_vcreate_f(N/2 + 1.0,0);
   vsip_vview_f *spect_new = vsip_vcreate_f(N/2 + 1.0,0);
   vsip_randstate *state  = vsip_randcreate(RNS,1,1,RNT);
   vsip_fir_f *fir;
   vsip_fft_f *fft = vsip_rcfftop_create_f(N,1,0,0);
   vsip_scalar_f b[] = 
            {0.0234, -0.0094, -0.0180, -0.0129,  0.0037, 
             0.0110, -0.0026, -0.0195, -0.0136,  0.0122,
             0.0232, -0.0007, -0.0314, -0.0223,  0.0250,
             0.0483, -0.0002, -0.0746, -0.0619,  0.0930,
             0.3023,  0.3999,  0.3023,  0.0930, -0.0619,
            -0.0746, -0.0002,  0.0483,  0.0250, -0.0223,
            -0.0314, -0.0007,  0.0232,  0.0122, -0.0136,
            -0.0195, -0.0026,  0.0110,  0.0037, -0.0129,
            -0.0180 ,-0.0094,  0.0234};
    {
        vsip_block_f *kblock = vsip_blockbind_f(b,43,0);
        vsip_vview_f *kernel =
            vsip_vbind_f(kblock,0,1,43);
        vsip_blockadmit_f(kblock,1);
        fir = vsip_fir_create_f( kernel, VSIP_NONSYM, D * N, 
                 D, VSIP_STATE_SAVE, 0, 0);
        vsip_valldestroy_f(kernel);
     }
     vsip_vfill_f(0,spect_avg);
     for(i=0; i<avg; i++){
        vsip_vrandu_f(state,dataIn);
        vsip_svadd_f(-.5,dataIn,dataIn);
        vsip_firflt_f(fir,dataIn,dataOut);
        vsip_rcfftop_f(fft,dataOut,dataFFT);
        vsip_vcmagsq_f(dataFFT,spect_new);
        vsip_vadd_f(spect_new,spect_avg,spect_avg);
      }
      vsip_svmul_f(1.0/avg,spect_avg,spect_avg);
      printf("spect_avg =");VU_vprint_f(spect_avg);

      vsip_valldestroy_f(dataIn);
      vsip_valldestroy_f(spect_avg);
      vsip_valldestroy_f(spect_new);
      vsip_cvalldestroy_f(dataFFT);
      vsip_valldestroy_f(dataOut);
      vsip_randdestroy(state);
      vsip_fft_destroy_f(fft);
      vsip_fir_destroy_f(fir);
}vsip_finalize((void*)0);
return 1;      
}

void VU_vprint_f(vsip_vview_f *a)
{
    vsip_vattr_f attr;
    vsip_index i;
    vsip_vgetattrib_f(a,&attr);
    printf("[");
    for(i=0; i<attr.length-1; i++)
         printf("%7.4f;\n",vsip_vget_f(a,i));
    printf("%7.4f];\n", vsip_vget_f(a,i));
    return;
}
