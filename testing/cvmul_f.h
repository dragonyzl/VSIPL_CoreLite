/* $Id: cvmul.t,v 1.1 2000/04/02 20:29:58 judd Exp $ */
static void cvmul_f(){
   printf("********\nTEST cvmul_f\n");
   {
     vsip_scalar_f data_a_i[] = { 1.1, 1.2, 2.1, 2.2, -3.1, -3.3};
     vsip_scalar_f data_a_r[] = { 2.1, 3.2, -2.1, -2.2, +5.1, +5.3};
     vsip_scalar_f data_b_i[] = {10.1, 11.2, 22.1, 12.2, -13.1, -0.3};
     vsip_scalar_f data_b_r[] = {8.1, 10.2, -12.1, 10.2, -11.1, -2.3};
     vsip_scalar_f ans_r[] = { 5.9000,  19.2000, -21.0000, -49.2800, -97.2200, -13.1800 };
     vsip_scalar_f ans_i[] = { 30.1200, 48.0800, -71.8200, -4.4000, -32.4000, 6.0000 }; 

     vsip_cblock_f  *block_a = vsip_cblockbind_f(data_a_r,data_a_i,6,0);
     vsip_cblock_f  *block_b = vsip_cblockbind_f(data_b_r,data_b_i,6,0);
     vsip_cblock_f  *block_c = vsip_cblockcreate_f(30,VSIP_MEM_NONE);
     vsip_cblock_f  *block_d = vsip_cblockcreate_f(30,VSIP_MEM_NONE);
     vsip_cblock_f  *ans_block = vsip_cblockbind_f(ans_r,ans_i,6,0);

     vsip_cvview_f  *a = vsip_cvbind_f(block_a,0,1,6);
     vsip_cvview_f  *b = vsip_cvbind_f(block_b,0,1,6);
     vsip_cvview_f  *c = vsip_cvbind_f(block_c,18,-2,6);
     vsip_cvview_f  *d = vsip_cvbind_f(block_d,2,3,6);

     vsip_cvview_f  *ansv = vsip_cvbind_f(ans_block,0,1,6);
     vsip_cvview_f  *chk = vsip_cvcreate_f(6,0);
     vsip_vview_f  *chk_r = vsip_vrealview_f(chk);

     vsip_cblockadmit_f(block_a,VSIP_TRUE);
     vsip_cblockadmit_f(block_b,VSIP_TRUE);
     vsip_cblockadmit_f(ans_block,VSIP_TRUE);

     printf("vsip_cvmul_f(a,b,c)\n");
     vsip_cvmul_f(a,b,c);
     printf("vector a\n");VU_cvprintm_f("8.6",a);
     printf("vector b\n");VU_cvprintm_f("8.6",b);
     printf("vector c\n");VU_cvprintm_f("8.6",c);
     printf("right answer\n");VU_cvprintm_f("8.4",ansv);

     vsip_cvsub_f(c,ansv,chk); vsip_cvmag_f(chk,chk_r); VU_limitIP_f(chk_r,.0001);
     if(vsip_vsumval_f(chk_r) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     printf("\na,c in place\n");
     vsip_cvcopy_f_f(a,d);
     vsip_cvmul_f(d,b,d);
     vsip_cvsub_f(d,ansv,chk); vsip_cvmag_f(chk,chk_r); VU_limitIP_f(chk_r,.0001);
     if(vsip_vsumval_f(chk_r) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     printf("\nb,c in place\n");
     vsip_cvcopy_f_f(b,c);
     vsip_cvmul_f(a,c,c);
     vsip_cvsub_f(c,ansv,chk); vsip_cvmag_f(chk,chk_r); VU_limitIP_f(chk_r,.0001);
     if(vsip_vsumval_f(chk_r) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     vsip_cvalldestroy_f(a);
     vsip_cvalldestroy_f(b);
     vsip_cvalldestroy_f(c);
     vsip_cvalldestroy_f(d);
     vsip_vdestroy_f(chk_r);
     vsip_cvalldestroy_f(chk);
     vsip_cvalldestroy_f(ansv);
   }
   return;
}
