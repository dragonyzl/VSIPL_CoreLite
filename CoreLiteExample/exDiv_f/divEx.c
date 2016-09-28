/* example of vector-vector divide */
#include<stdio.h>
#include<vsip.h>
#define L 5

int main(){vsip_init((void*)0);
{
   int i;
   /* define some vectors */
   vsip_vview_f* dataN= vsip_vcreate_f(L,0);
   vsip_vview_f* dataD= vsip_vcreate_f(L,0);
   vsip_vview_f* dataQ= vsip_vcreate_f(L,0);
   /* make up some data */
   vsip_vramp_f(1,1,dataN);
   vsip_vfill_f(2,dataD);
   /*divide one by two and print the input and output */
   vsip_vdiv_f(dataN,dataD,dataQ);
   for(i=0; i<L; i++)
       printf("%7.4f / %7.4f = %7.4f\n",
              vsip_vget_f(dataN,i),
              vsip_vget_f(dataD,i),
              vsip_vget_f(dataQ,i));
   printf("\n");
   /* destroy created objects */
   vsip_blockdestroy_f(vsip_vdestroy_f(dataN));
   vsip_blockdestroy_f(vsip_vdestroy_f(dataD));
   vsip_blockdestroy_f(vsip_vdestroy_f(dataQ));
}vsip_finalize((void*)0); return 0;
}
/* output */
/* 1.0000 /  2.0000 =  0.5000
   2.0000 /  2.0000 =  1.0000
   3.0000 /  2.0000 =  1.5000
   4.0000 /  2.0000 =  2.0000
   5.0000 /  2.0000 =  2.5000
*/
