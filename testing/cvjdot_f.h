/* $Id: cvjdot.t,v 1.1 2000/04/02 20:29:58 judd Exp $ */
static void cvjdot_f(){
   printf("********\nTEST cvjdot_f\n");
   {
     vsip_scalar_f data_a_i[] = { 1.1, 1.2, 2.1, 2.2, -3.1, -3.3};
     vsip_scalar_f data_a_r[] = { 2.1, 3.2, -2.1, -2.2, +5.1, +5.3};
     vsip_scalar_f data_b_i[] = {10.1, 11.2, 22.1, 12.2, -13.1, -0.3};
     vsip_scalar_f data_b_r[] = {8.1, 10.2, -12.1, 10.2, -11.1, -2.3};
     vsip_cscalar_f ans = vsip_cmplx_f(123.22,144.78);
     vsip_cscalar_f val = vsip_cmplx_f(0,0);

     vsip_cblock_f  *block_a = vsip_cblockbind_f(data_a_r,data_a_i,6,0);
     vsip_cblock_f  *block_b = vsip_cblockbind_f(data_b_r,data_b_i,6,0);
     vsip_cblock_f  *block_c = vsip_cblockcreate_f(30,VSIP_MEM_NONE);

     vsip_cvview_f  *a = vsip_cvbind_f(block_a,0,1,6);
     vsip_cvview_f  *b = vsip_cvbind_f(block_b,0,1,6);
     vsip_cvview_f  *c = vsip_cvbind_f(block_c,18,-2,6);

     vsip_cblockadmit_f(block_a,VSIP_TRUE);
     vsip_cblockadmit_f(block_b,VSIP_TRUE);

     vsip_cvcopy_f_f(a,c);
     printf("val = vsip_cvjdot_f(a,b)\n");
     val = vsip_cvjdot_f(c,b);
     printf("vector a\n");VU_cvprintm_f("8.6",c);
     printf("vector b\n");VU_cvprintm_f("8.6",b);
     printf("val = (%f %+fi)\n",vsip_real_f(val),vsip_imag_f(val));
     printf("right answer (%6.4f %+6.4fi)\n",vsip_real_f(ans),vsip_imag_f(ans));
     if(VU_cmag_f(VU_csub_f(ans,val)) > .0002)
         printf("error\n");
     else
         printf("correct\n");

     vsip_cvalldestroy_f(a);
     vsip_cvalldestroy_f(b);
     vsip_cvalldestroy_f(c);
   }
   return;
}
