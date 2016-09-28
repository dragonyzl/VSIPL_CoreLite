/* $Id: vsumval.t,v 1.2 2000/04/04 19:55:30 judd Exp $ */
static void vsumval_f(){
   printf("********\nTEST vsumval_f\n");
   {
       vsip_scalar_f data[] = {1.0, 1.1, 1.2, 1.3, 1.4, 1.4, 1.3, 1.2, 1.1, 1.0};
       vsip_scalar_f val = 0.0;
       vsip_scalar_f ans = 12.0;
       vsip_vview_f *a = vsip_vbind_f(
                 vsip_blockbind_f(data,10,0),0,1,10);
       vsip_block_f  *block = vsip_blockcreate_f(1024,0);
       vsip_vview_f *b = vsip_vbind_f(block,500,5,10);
  
       vsip_blockadmit_f(vsip_vgetblock_f(a),VSIP_TRUE);
       vsip_vcopy_f_f(a,b);
       
       printf("val = vsip_vsumval_f(a)\n");
       printf("vector a\n");VU_vprintm_f("6.4",a);
       val = vsip_vsumval_f(b);
       printf("val %f\n",val);
       printf("right answer %7.4f\n",ans);
       if(fabs(val-ans) < .0001)
           printf("correct\n");
       else
           printf("error\n");
       vsip_valldestroy_f(a);
       vsip_valldestroy_f(b);
    }
    return;
}
