/* Created by RJudd */
/* SPAWARSYSCEN D881 */
/* Example of add */
 
#include<stdio.h>
#include<vsip.h>

#define L 7                   /*length*/

int main()
{vsip_init((void*)0);
   {
    int i;
    vsip_vview_f* dataLeft  = vsip_vcreate_f(L,0);
    vsip_vview_f* dataRight  = vsip_vcreate_f(L,0);
    vsip_vview_f* dataSum = vsip_vcreate_f(L,0);

    /* Make up some data to find the magnitude of */
    /* First compute a ramp from One to L */
    vsip_vramp_f(1.0, 1.0 , dataLeft);
    /* Then compute a ramp from one to minus one */
    vsip_vramp_f(1.0, -2.0/(double)(L-1), dataRight);

    /* Add the vectors */
    vsip_vadd_f(dataLeft, dataRight, dataSum);

    /*now print out the data and its sum*/

    for(i=0; i<L; i++)
        printf("%7.4f = (%7.4f) + (%7.4f) \n",vsip_vget_f(dataSum,i),
             vsip_vget_f(dataLeft,i),vsip_vget_f(dataRight,i));
    

    /*destroy the vector views and any associated blocks*/
    vsip_blockdestroy_f(vsip_vdestroy_f(dataLeft));
    vsip_blockdestroy_f(vsip_vdestroy_f(dataRight));
    vsip_blockdestroy_f(vsip_vdestroy_f(dataSum));
   }
   vsip_finalize((void*)0);
   return 1;
}
/*output*/
/* 2.0000 = ( 1.0000) + ( 1.0000) 
   2.6667 = ( 2.0000) + ( 0.6667) 
   3.3333 = ( 3.0000) + ( 0.3333) 
   4.0000 = ( 4.0000) + ( 0.0000) 
   4.6667 = ( 5.0000) + (-0.3333) 
   5.3333 = ( 6.0000) + (-0.6667) 
   6.0000 = ( 7.0000) + (-1.0000) */
