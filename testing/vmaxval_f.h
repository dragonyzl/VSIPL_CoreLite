/* $Id: vmaxval.t,v 1.1 2000/04/02 20:29:58 judd Exp $ */
static void vmaxval_f(){
   printf("********\nTEST vmaxval_f\n");
   {
     vsip_scalar_f data_a[] = { 1.1, 1.2, 2.1, 2.2, -3.1, -3.3};
     vsip_scalar_f ans = 2.2;
     vsip_scalar_f val = 0;
     vsip_index  ans_ind = 3; 
     vsip_index  ind = 9999;
     vsip_block_f  *block_a = vsip_blockbind_f(data_a,6,0);
     vsip_vview_f  *a = vsip_vbind_f(block_a,0,1,6);
     vsip_blockadmit_f(block_a,VSIP_TRUE);
     val = vsip_vmaxval_f(a,&ind);
     printf("vector |a>\n"),VU_vprintm_f("6.4",a);
     printf("val = vsip_vmaxval_f(a,&ind)\n");
     printf("val = %f\nexpected answer %f\n",val,ans);
     printf("ind = %u\nexpected index %u\n",ind,ans_ind);

     if(fabs(val - ans) < .0001)
        printf("val correct\n");
     else
        printf("val in error\n");

     if(ind == ans_ind)
        printf("index correct\n");
     else
        printf("index in error\n");

     vsip_valldestroy_f(a);
   }
   return;
}
