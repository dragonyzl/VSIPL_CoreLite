#include<stdio.h>
#include<vsip.h>
void VU_vprint_f(vsip_vview_f* x)
{
   vsip_length i;
   vsip_vattr_f attr;
   vsip_vgetattrib_f(x,&attr);
   printf("[");
   for(i=0; i<attr.length-1; i++) 
       printf("%9.4f;\n",vsip_vget_f(x,i));
       printf("%9.4f]\n",vsip_vget_f(x,i));
   return;
}
