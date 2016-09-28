static void vrandu_f(){
   printf("\n*******\nTEST vsip_vrandu_f\n");
   {
      vsip_randstate *state1_1 = vsip_randcreate(7,1,1,VSIP_PRNG);
      vsip_randstate *state3_1 = vsip_randcreate(7,3,1,VSIP_PRNG);
      vsip_randstate *state3_2 = vsip_randcreate(7,3,2,VSIP_PRNG);
      vsip_randstate *state3_3 = vsip_randcreate(7,3,3,VSIP_PRNG);
      vsip_vview_f *x1_1 = vsip_vcreate_f(10,0);
      vsip_vview_f *x3_1 = vsip_vcreate_f(10,0);
      vsip_vview_f *x3_2 = vsip_vcreate_f(10,0);
      vsip_vview_f *x3_3 = vsip_vcreate_f(10,0);
      vsip_scalar_f data1_1[] = { 0.238764703, 0.802720249, 0.627929747, 0.220843256,
                                    0.786506951, 0.160186827, 0.194293201, 0.803141296, 
                                    0.234705746, 0.033771098};
      vsip_scalar_f data3_1[] = { 0.238764703, 0.802720249, 0.627929747, 0.220843256,
                                    0.786506951, 0.160186827, 0.194293201, 0.803141296,
                                    0.234705746, 0.033771098};
      vsip_scalar_f data3_2[] = { 0.086193860, 0.686928570, 0.905980766, 0.449434102,
                                    0.431472480, 0.392291605, 0.990291536, 0.378969252,
                                    0.894510210, 0.049527705};
      vsip_scalar_f data3_3[] = { 0.372649014, 0.539229810, 0.914156497, 0.745231926,
                                    0.799175084, 0.696496427, 0.199220479, 0.232882679,
                                    0.822755516, 0.628619969};
      vsip_block_f *block1_1 = vsip_blockbind_f(data1_1,10,0);
      vsip_block_f *block3_1 = vsip_blockbind_f(data3_1,10,0);
      vsip_block_f *block3_2 = vsip_blockbind_f(data3_2,10,0);
      vsip_block_f *block3_3 = vsip_blockbind_f(data3_3,10,0);
      vsip_vview_f *ans1_1 = vsip_vbind_f(block1_1,0,1,10);
      vsip_vview_f *ans3_1 = vsip_vbind_f(block3_1,0,1,10);
      vsip_vview_f *ans3_2 = vsip_vbind_f(block3_2,0,1,10);
      vsip_vview_f *ans3_3 = vsip_vbind_f(block3_3,0,1,10);
      vsip_blockadmit_f(block1_1,VSIP_TRUE);
      vsip_blockadmit_f(block3_1,VSIP_TRUE);
      vsip_blockadmit_f(block3_2,VSIP_TRUE);
      vsip_blockadmit_f(block3_3,VSIP_TRUE);
      vsip_vrandu_f(state1_1,x1_1);
      vsip_vrandu_f(state3_1,x3_1);
      vsip_vrandu_f(state3_2,x3_2);
      vsip_vrandu_f(state3_3,x3_3);
      printf("x1_1 =");VU_vprintm_f("8.6",x1_1);
      printf("\nans1_1 =");VU_vprintm_f("8.6",ans1_1);
      vsip_vsub_f(x1_1,ans1_1,x1_1); vsip_vmag_f(x1_1,x1_1);
      if(vsip_vsumval_f(x1_1) > .001) printf("error\n"); else printf("correct\n");

      printf("\n\nx3_1 =");VU_vprintm_f("8.6",x3_1);
      printf("\nans3_1 =");VU_vprintm_f("8.6",ans3_1);
      vsip_vsub_f(x3_1,ans3_1,x1_1); vsip_vmag_f(x1_1,x1_1);
      if(vsip_vsumval_f(x1_1) > .001) printf("error\n"); else printf("correct\n");

      printf("\n\nx3_2 =");VU_vprintm_f("8.6",x3_2);
      printf("\nans3_2 =");VU_vprintm_f("8.6",ans3_2);
      vsip_vsub_f(x3_2,ans3_2,x1_1); vsip_vmag_f(x1_1,x1_1);
      if(vsip_vsumval_f(x1_1) > .001) printf("error\n"); else printf("correct\n");

      printf("\n\nx3_3 =");VU_vprintm_f("8.6",x3_3);
      printf("\nans3_3 =");VU_vprintm_f("8.6",ans3_3);
      vsip_vsub_f(x3_3,ans3_3,x1_1); vsip_vmag_f(x1_1,x1_1);
      if(vsip_vsumval_f(x1_1) > .001) printf("error\n"); else printf("correct\n");

      vsip_randdestroy(state1_1);
      vsip_randdestroy(state3_1);
      vsip_randdestroy(state3_2);
      vsip_randdestroy(state3_3);
      vsip_valldestroy_f(x1_1);
      vsip_valldestroy_f(x3_1);
      vsip_valldestroy_f(x3_2);
      vsip_valldestroy_f(x3_3);
      vsip_valldestroy_f(ans1_1);
      vsip_valldestroy_f(ans3_1);
      vsip_valldestroy_f(ans3_2);
      vsip_valldestroy_f(ans3_3);
   }
   return;
}
