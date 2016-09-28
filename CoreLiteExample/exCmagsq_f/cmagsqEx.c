/* Example of cmagsq*/
#include<stdio.h>
#include<vsip.h>
#define VU_PI 3.1415926535
#define L 7                   /* length */

int main(){vsip_init((void*)0);
{
    int i;
    vsip_vview_f* dataRe  = vsip_vcreate_f(L,0);
    vsip_vview_f* dataIm  = vsip_vcreate_f(L,0);
    vsip_vview_f* dataMagsq = vsip_vcreate_f(L,0);
    vsip_cvview_f* dataCmplx = vsip_cvcreate_f(L,0);
    vsip_cscalar_f cscalar;
    /* Make up some data to find the magnitude of */
    /* First compute a ramp from zero to 2pi and apply sin */
    vsip_vramp_f(0.0, (2.0 * VU_PI / (double) (L - 1)), dataRe);
    vsip_vsin_f(dataRe,dataRe);
    /* Then compute a ramp from zero to 3pi and apply cos */
    vsip_vramp_f(0.0, (3.0 * VU_PI / (double) (L - 1)), dataIm);
    vsip_vcos_f(dataIm,dataIm);
    /* Finally make a complex vector. */
    vsip_vcmplx_f(dataRe, dataIm, dataCmplx);
    /* Find the Magnitude */
    vsip_vcmagsq_f(dataCmplx,dataMagsq);
    /*now print out dataCmplex and its arguments*/
    for(i=0; i<L; i++){
        cscalar = vsip_cvget_f(dataCmplx, (vsip_scalar_vi) i);
        printf("(%7.4f, %7.4f) => %7.4f\n",cscalar.r, cscalar.i,
             vsip_vget_f(dataMagsq, (vsip_scalar_vi) i));
    }
    /*destroy the vector views and any associated blocks*/
    vsip_blockdestroy_f(vsip_vdestroy_f(dataRe));
    vsip_blockdestroy_f(vsip_vdestroy_f(dataIm));
    vsip_blockdestroy_f(vsip_vdestroy_f(dataMagsq));
    vsip_cblockdestroy_f(vsip_cvdestroy_f(dataCmplx));
}vsip_finalize((void*)0);return 0;
}
/* output */
/* ( 0.0000,  1.0000) =>  1.0000
   ( 0.8660,  0.0000) =>  0.7500
   ( 0.8660, -1.0000) =>  1.7500
   ( 0.0000, -0.0000) =>  0.0000
   (-0.8660,  1.0000) =>  1.7500
   (-0.8660,  0.0000) =>  0.7500
   (-0.0000, -1.0000) =>  1.0000 */
