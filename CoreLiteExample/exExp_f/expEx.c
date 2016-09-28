/* calculate a = exp(x) for x = {0,1,...N} */
 
#include<stdio.h>
#include<vsip.h>

#define N  4                    /* length */

int main(){vsip_init((void*)0);
{
    vsip_scalar_f data[N];             /*a user created data space */

    int i;

    vsip_vview_f* a = vsip_vbind_f(vsip_blockbind_f(data,N,0),0,1,N);
    vsip_vview_f* x   = vsip_vcreate_f(N,0);

    vsip_vramp_f(0.0, 1.0, x);

    /* admit the user block with no update */
    vsip_blockadmit_f(vsip_vgetblock_f(a),VSIP_FALSE);
    /*compute the exponential value */
    vsip_vexp_f(x, a);

    /* release the user block with update */
    vsip_blockrelease_f(vsip_vgetblock_f(a),VSIP_TRUE);
    /*print it */
    for(i=0; i<N; i++)
      printf("%f ",data[i]);
    printf("\n");

    /*destroy the vector views and any associated blocks*/
    vsip_blockdestroy_f(vsip_vdestroy_f(x));
    vsip_blockdestroy_f(vsip_vdestroy_f(a));
}vsip_finalize((void*)0); return 0;
}
/* output */
/* 1.000000 2.718282 7.389056 20.085537 */
