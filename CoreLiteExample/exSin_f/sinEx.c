/* Created RJudd */
/* SPAWARSYSCEN D881 */
/* print a sine wave for seven evenly spaced values between */
/* zero and two pi. */
 
#include<stdio.h>
#include<vsip.h>

#define VU_PI 3.1415926535
#define L 7                   /* length */

int main(){vsip_init((void*)0);
{
    vsip_scalar_f data[L];           /*a user created data space */

    int i;

    vsip_vview_f* ramp = vsip_vcreate_f(L,0);
    vsip_vview_f* output = vsip_vbind_f(vsip_blockbind_f(data,L,0),0,1,L);

    /*compute a ramp from zero to 2 pi */
    vsip_vramp_f(0.0, (2.0 * VU_PI / (double) (L - 1)), ramp);
    /* admit the user block with no update */
    vsip_blockadmit_f(vsip_vgetblock_f(output),VSIP_FALSE);
    /*compute the sine value */
    vsip_vsin_f(ramp, output);

    /* release the user block with update */
    vsip_blockrelease_f(vsip_vgetblock_f(output),VSIP_TRUE);
    /*print it */
    for(i=0; i<L; i++)
        printf("%f ",data[i]);
    printf("\n");

    /*destroy the vector views and any associated blocks */
    vsip_blockdestroy_f(vsip_vdestroy_f(ramp));
    vsip_blockdestroy_f(vsip_vdestroy_f(output));
}vsip_finalize((void*)0); return 0;
}
/* output */
/* 0.000000 0.866025 0.866025 0.000000 -0.866025 -0.866025 -0.000000 */
