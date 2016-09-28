/* Created by RJudd */
/* SPAWARSYSCEN D881 */
/* Test of split, interleaved */
 
#include<stdio.h>
#include<vsip.h>
#include"euler.h"

#define VU_2PI 6.283185307179586

#define N 7                   /*length*/

int main(){vsip_init((void*)0);
{
    vsip_cvview_f *cs_t = vsip_cvcreate_f(N,0);
    { /* do euler */
       vsip_vview_f *v = vsip_vrealview_f(cs_t);
       vsip_vview_f *w = vsip_vimagview_f(cs_t);
       vsip_vramp_f(0,VU_2PI/(vsip_scalar_f)N,v);
       printf("vector of angles \n");
       VU_vprint_f(v);
       vsip_vsin_f(v,w);
       vsip_vcos_f(v,v);
       vsip_vdestroy_f(v);
       vsip_vdestroy_f(w);
     }
     printf("euler vector \n");
     VU_cvprint_f(cs_t);
     vsip_cvalldestroy_f(cs_t);
} vsip_finalize((void*)0); return 1;
}
