/* $Id: vcos.t,v 1.1 2000/04/02 20:29:58 judd Exp $ */
static void vcos_f(){
   printf("********\nTEST vcos_f\n");
   {
     vsip_scalar_f data[] = {0, M_PI/4.0, M_PI/3.0, M_PI, 1.25 * M_PI};
     vsip_scalar_f ans[] = { 1.0, 0.7071, 0.5, -1.0, -0.7071};
     vsip_block_f  *block = vsip_blockbind_f(data,5,0);
     vsip_block_f  *ans_block = vsip_blockbind_f(ans,5,0);
     vsip_vview_f  *a = vsip_vbind_f(block,0,1,5);
     vsip_vview_f  *ansv = vsip_vbind_f(ans_block,0,1,5);
     vsip_vview_f  *b = vsip_vcreate_f(15,0);
     vsip_vview_f  *chk = vsip_vcreate_f(5,0);
     vsip_vputlength_f(b,5);
     vsip_blockadmit_f(block,VSIP_TRUE);
     vsip_blockadmit_f(ans_block,VSIP_TRUE);
     printf("test out of place, compact, user \"a\", vsipl \"b\"\n");
     vsip_vcos_f(a,b);
     printf("vcos_f(a,b)\n vector a\n");VU_vprintm_f("8.6",a);
     printf("vector b\n");VU_vprintm_f("8.6",b);
     printf("expected answer to 4 decimal digits\n");VU_vprintm_f("8.4",ansv);

     vsip_vsub_f(b,ansv,chk); vsip_vmag_f(chk,chk); VU_limitIP_f(chk,.0001);
     if(vsip_vsumval_f(chk) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     printf("\na,b in place\n");
     vsip_vputstride_f(b,2);vsip_vcopy_f_f(a,b);
     vsip_vcos_f(a,a);
     vsip_vsub_f(a,ansv,chk); vsip_vmag_f(chk,chk); VU_limitIP_f(chk,.0001);
     if(vsip_vsumval_f(chk) > .5) 
         printf("error\n");
     else 
         printf("correct\n");

     printf("\n");
     /* check with a stride 1, b stride 2 */
     printf("vsip_vcos(a,b) with <a> stride 2, <b> stride 1\n");
     vsip_vcos_f(b,a);
     vsip_vsub_f(a,ansv,chk); vsip_vmag_f(chk,chk); VU_limitIP_f(chk,.0001);
     if(vsip_vsumval_f(chk) > .5) 
         printf(" vcos_f in error for in place\n");
     else {
         printf("correct\n");
     }
     vsip_valldestroy_f(a);
     vsip_valldestroy_f(b);
     vsip_valldestroy_f(chk);
     vsip_valldestroy_f(ansv);
   }
   return;
}
