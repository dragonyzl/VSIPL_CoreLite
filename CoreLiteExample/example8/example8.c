/* Created RJudd */
/* SPAWARSYSCEN D881 */

#include<vsip.h>
int VU_vcoshIP_f(vsip_vview_f *a)
{  vsip_vattr_f attr;
   vsip_vview_f *b = a;
   vsip_scalar_f *buff;
   vsip_length n;
   vsip_block_f *B;
   vsip_vgetattrib_f(a, &attr);
   B = attr.block; n = attr.length;
   if ((buff = vsip_blockrelease_f(B,1)) == NULL){
      buff=(vsip_scalar_f *)malloc(
           n * sizeof(vsip_scalar_f));
      if(buff != NULL){
           if((B = vsip_blockbind_f(buff,n,0)) == NULL){
              free((void*)buff);return 0;
           }
         }else{ return 0;
      }
      vsip_blockadmit_f(B,0);
      b = vsip_vbind_f(B,0,1,n);
      vsip_vcopy_f_f(a,b);
      vsip_blockrelease_f(B,1);
      }
   while(n-- >0){
      *buff = cosh(*buff); buff++;
   } buff = vsip_blockfind_f(B); vsip_blockadmit_f(B,1);
   if(a != b){
      vsip_vcopy_f_f(b,a);
      vsip_valldestroy_f(b);
      free((void *) buff);
   }return 1;
}
 int main(){vsip_init((void*)0);
{     int VU_vcoshIP_f(vsip_vview_f *);
      void VU_vprint_f(vsip_vview_f*);
      vsip_vview_f *A = vsip_vcreate_f(8,0);
      vsip_vramp_f(0,.2,A);
      printf("A = \n");VU_vprint_f(A);
      VU_vcoshIP_f(A);
      printf("cosh(A) = \n");VU_vprint_f(A);
      vsip_valldestroy_f(A);
}vsip_finalize((void*)0); return 1;
}  /* main using VSIPL vector */

void VU_vprint_f(vsip_vview_f* a){
      int i;
      vsip_vattr_f attr;
      vsip_vgetattrib_f(a,&attr);
      for(i=0; i<attr.length; i++)
         printf("%6.4f ",vsip_vget_f(a,i));
      printf("\n");
      return;
}

/* int main(){vsip_init((void*)0);
{
      int VU_vcoshIP_f(vsip_vview_f *);
      void VU_vprint_f(vsip_vview_f*);
      vsip_scalar_f buff[8];
      vsip_block_f *Ablock = vsip_blockbind_f(buff,8,0);
      vsip_vview_f *A = vsip_vbind_f(Ablock,0,1,8);
      vsip_blockadmit_f(Ablock,0);
      vsip_vramp_f(0,.2,A);
      printf("A = \n");VU_vprint_f(A);

      VU_vcoshIP_f(A);
      printf("cosh(A) = \n");VU_vprint_f(A);
      vsip_valldestroy_f(A);
}vsip_finalize((void*)0); return 1;
}*/  /* main using user vector */

