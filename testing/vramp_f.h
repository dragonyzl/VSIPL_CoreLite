/* $Id: vramp.t,v 1.1 2000/04/02 20:29:58 judd Exp $ */
static void vramp_f(){
   printf("********\nTEST vramp_f\n");
   {
     vsip_scalar_f ans[] = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
     vsip_scalar_f start = 1.1;
     vsip_scalar_f inc   = 0.1;

     vsip_block_f  *block_c = vsip_blockcreate_f(30,VSIP_MEM_NONE);
     vsip_block_f  *ans_block = vsip_blockbind_f(ans,6,0);

     vsip_vview_f  *c = vsip_vbind_f(block_c,18,-2,6);
     vsip_vview_f  *ansv = vsip_vbind_f(ans_block,0,1,6);
     vsip_vview_f  *chk = vsip_vcreate_f(6,0);

     vsip_blockadmit_f(ans_block,VSIP_TRUE);

     printf("vsip_vramp_f(start,inc,c)\n");
     vsip_vramp_f(start,inc,c);
     printf("start = %3.1f\ninc = %3.1f \nVector <c> of length 6\n");
     printf("vector c\n");VU_vprintm_f("8.6",c);
     printf("right answer\n");VU_vprintm_f("8.4",ansv);

     vsip_vsub_f(c,ansv,chk); vsip_vmag_f(chk,chk); VU_limitIP_f(chk,.0001);
     if(vsip_vsumval_f(chk) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     vsip_valldestroy_f(c);
     vsip_valldestroy_f(chk);
     vsip_valldestroy_f(ansv);
   }
   return;
}
