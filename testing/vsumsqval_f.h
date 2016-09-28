/* $Id */
static void vsumsqval_f(){
   printf("********\nTEST vsumsqval_f\n");
   {
     vsip_scalar_f data[] = {-1,  1, 0,  2, -2 };
     vsip_scalar_f ans = 10.0;
     vsip_scalar_f val=0;
     vsip_block_f  *block = vsip_blockbind_f(data,5,0);
     vsip_vview_f  *a = vsip_vbind_f(block,0,1,5);
     vsip_blockadmit_f(block,VSIP_TRUE);
     val = vsip_vsumsqval_f(a);
     printf("val = vsip_vsumsqval_f(a)\n vector a\n");VU_vprintm_f("8.6",a);
     printf("val = %f\n",val);
     printf("right answer %f\n",ans);
     if(val == ans)
          printf("correct\n");
     else
          printf("error\n");
     vsip_valldestroy_f(a);
   }
   return;
}
