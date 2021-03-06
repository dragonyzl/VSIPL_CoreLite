/* $Id: vsub.t,v 1.1 2000/04/02 20:29:58 judd Exp $ */
static void vsub_f(){
   printf("********\nTEST vsub_f\n");
   {
     vsip_scalar_f data_a[] = { 1.1, 1.2, 2.1, 2.2, -3.1, -3.3};
     vsip_scalar_f data_b[] = {10.1, 11.2, 22.1, 12.2, -13.1, -0.3};
     vsip_scalar_f ans[] = { -9.0,-10.0,-20.0,-10.0,10.0,-3.0};

     vsip_block_f  *block_a = vsip_blockbind_f(data_a,6,0);
     vsip_block_f  *block_b = vsip_blockbind_f(data_b,6,0);
     vsip_block_f  *block_c = vsip_blockcreate_f(30,VSIP_MEM_NONE);
     vsip_block_f  *block_d = vsip_blockcreate_f(30,VSIP_MEM_NONE);
     vsip_block_f  *ans_block = vsip_blockbind_f(ans,6,0);

     vsip_vview_f  *a = vsip_vbind_f(block_a,0,1,6);
     vsip_vview_f  *b = vsip_vbind_f(block_b,0,1,6);
     vsip_vview_f  *c = vsip_vbind_f(block_c,18,-2,6);
     vsip_vview_f  *d = vsip_vbind_f(block_d,2,3,6);

     vsip_vview_f  *ansv = vsip_vbind_f(ans_block,0,1,6);
     vsip_vview_f  *chk = vsip_vcreate_f(6,0);

     vsip_blockadmit_f(block_a,VSIP_TRUE);
     vsip_blockadmit_f(block_b,VSIP_TRUE);
     vsip_blockadmit_f(ans_block,VSIP_TRUE);

     printf("vsip_vsub_f(a,b)\n");
     vsip_vsub_f(a,b,c);
     printf("vsub_f(a,b,c)\n vector a\n");VU_vprintm_f("8.6",a);
     printf("vector b\n");VU_vprintm_f("8.6",b);
     printf("vector c\n");VU_vprintm_f("8.6",c);
     printf("right answer\n");VU_vprintm_f("8.4",ansv);

     vsip_vsub_f(c,ansv,chk); vsip_vmag_f(chk,chk); VU_limitIP_f(chk,.0001);
     if(vsip_vsumval_f(chk) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     printf("\na,c in place\n");
     vsip_vcopy_f_f(a,d);
     vsip_vsub_f(d,b,d);
     vsip_vsub_f(d,ansv,chk); vsip_vmag_f(chk,chk); VU_limitIP_f(chk,.0001);
     if(vsip_vsumval_f(chk) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     printf("\nb,c in place\n");
     vsip_vcopy_f_f(b,c);
     vsip_vsub_f(a,c,c);
     vsip_vsub_f(c,ansv,chk); vsip_vmag_f(chk,chk); VU_limitIP_f(chk,.0001);
     if(vsip_vsumval_f(chk) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     vsip_valldestroy_f(a);
     vsip_valldestroy_f(b);
     vsip_valldestroy_f(c);
     vsip_valldestroy_f(d);
     vsip_valldestroy_f(chk);
     vsip_valldestroy_f(ansv);
   }
   return;
}
