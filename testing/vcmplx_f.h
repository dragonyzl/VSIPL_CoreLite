/* $Id: vcmplx.t,v 1.1 2000/04/02 20:29:58 judd Exp $ */
static void vcmplx_f(){
   printf("********\nTEST vcmplx_f\n");
   {
     vsip_scalar_f data_a[] = { 2.1 , 3.2, -2.1, -2.2,  +5.1, +5.3};
     vsip_scalar_f data_b[] = {10.1, 11.2, 22.1, 12.2, -13.1, -0.3};
     vsip_scalar_f ans_r[] = { 2.1,  3.2,  -2.1, -2.2,  +5.1, +5.3};
     vsip_scalar_f ans_i[] = {10.1, 11.2,  22.1, 12.2, -13.1, -0.3};

     vsip_block_f  *block_a = vsip_blockbind_f(data_a,6,0);
     vsip_block_f  *block_b = vsip_blockbind_f(data_b,6,0);
     vsip_cblock_f  *block_c = vsip_cblockcreate_f(30,VSIP_MEM_NONE);
     vsip_cblock_f  *block_d = vsip_cblockcreate_f(30,VSIP_MEM_NONE);
     vsip_cblock_f  *ans_block = vsip_cblockbind_f(ans_r,ans_i,6,0);

     vsip_vview_f   *a   = vsip_vbind_f(block_a,0,1,6);
     vsip_vview_f   *b   = vsip_vbind_f(block_b,0,1,6);
     vsip_cvview_f   *c   = vsip_cvbind_f(block_c,18,-2,6);
     vsip_cvview_f  *d   = vsip_cvbind_f(block_d,2,3,6);
     vsip_vview_f   *d_r = vsip_vrealview_f(d);
     vsip_vview_f   *d_i = vsip_vimagview_f(d);

     vsip_cvview_f  *ansv = vsip_cvbind_f(ans_block,0,1,6);
     vsip_cvview_f  *chk = vsip_cvcreate_f(6,0);
     vsip_vview_f  *chk_r = vsip_vrealview_f(chk);

     vsip_blockadmit_f(block_a,VSIP_TRUE);
     vsip_blockadmit_f(block_b,VSIP_TRUE);
     vsip_cblockadmit_f(ans_block,VSIP_TRUE);

     printf("vsip_vcmplx_f(a,b,c)\n");
     vsip_vcmplx_f(a,b,c);
     printf("vector a\n");VU_vprintm_f("8.6",a);
     printf("vector b\n");VU_vprintm_f("8.6",b);
     printf("vector c\n");VU_cvprintm_f("8.6",c);
     printf("right answer\n");VU_cvprintm_f("8.4",ansv);

     vsip_cvsub_f(c,ansv,chk); vsip_cvmag_f(chk,chk_r); VU_limitIP_f(chk_r,.0001);
     if(vsip_vsumval_f(chk_r) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     printf("\na,b real,imag view of c (in place)\n");
     vsip_vcopy_f_f(a,d_r);
     vsip_vcopy_f_f(b,d_i);
     vsip_vcmplx_f(d_r,d_i,d);
     vsip_cvsub_f(d,ansv,chk); vsip_cvmag_f(chk,chk_r); VU_limitIP_f(chk_r,.0001);
     if(vsip_vsumval_f(chk_r) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     vsip_valldestroy_f(a);
     vsip_valldestroy_f(b);
     vsip_cvalldestroy_f(c);
     vsip_cvalldestroy_f(d);
     vsip_vdestroy_f(chk_r);
     vsip_cvalldestroy_f(chk);
     vsip_cvalldestroy_f(ansv);
   }
   return;
}
