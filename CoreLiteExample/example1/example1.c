/* Created RJudd */
/* SPAWARSYSCEN D881 */

#include<stdio.h>
#include<vsip.h>

#define N 8 /* the length of the vector */

int main(){ vsip_init((void*)0);
{
   
   void VU_vprint_f(vsip_vview_f*);
   vsip_vview_f *A = vsip_vcreate_f(N,0),
                *B = vsip_vcreate_f(N,0),
                *C = vsip_vcreate_f(N,0);
   vsip_vramp_f(0,1,A);
   printf("A = \n");VU_vprint_f(A);

   vsip_vfill_f(5,B);
   printf("B = \n");VU_vprint_f(B);

   vsip_vadd_f(A,B,C);
   printf("C = \n");VU_vprint_f(C);
      
   vsip_valldestroy_f(A);
   vsip_valldestroy_f(B);
   vsip_valldestroy_f(C);
}
vsip_finalize((void*)0);
return 1;
}

void VU_vprint_f(vsip_vview_f* a){
   int i;
   vsip_vattr_f attr;
   vsip_vgetattrib_f(a,&attr);
   for(i=0; i<attr.length; i++)
   printf("%4.0f",vsip_vget_f(a,i));
   printf("\n");
   return;
}
