#include<stdio.h>
#include<vsip.h>
void VU_cvprint_f(vsip_cvview_f* x)
{
   vsip_length i;
   vsip_cvattr_f attr; 
   vsip_cvgetattrib_f(x,&attr);
   printf("[");
   for(i=0; i<attr.length-1; i++)
       printf("%9.4f + %9.4fi;\n",
                vsip_real_f(vsip_cvget_f(x,i)),
                vsip_imag_f(vsip_cvget_f(x,i)));
       printf("%9.4f + %9.4fi]\n",
                vsip_real_f(vsip_cvget_f(x,i)),
                vsip_imag_f(vsip_cvget_f(x,i)));
   return;
}
