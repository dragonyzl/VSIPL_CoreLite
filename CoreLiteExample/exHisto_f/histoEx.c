/* Created by RJudd */
/* SPAWARSYSCEN D881 */
/* Example of add */
 
#include<stdio.h>
#include<vsip.h>

#define L 50000                 /*length*/
#define NS 8
#define NB 50
void VU_vprint_f(vsip_vview_f*);

int main(){vsip_init((void*)0);
{
    vsip_vview_f  *histoU    = vsip_vcreate_f(NB,0),
                  *histoN    = vsip_vcreate_f(NB,0);
    vsip_vview_f* data      = vsip_vcreate_f(L,0);
    vsip_vview_f* dataOne   = vsip_vcreate_f(L,0);
    vsip_vview_f* dataTwo   = vsip_vcreate_f(L,0);
    vsip_vview_f* dataThree = vsip_vcreate_f(L,0);
    vsip_vview_f* dataFour = vsip_vcreate_f(L,0);
    vsip_vview_f* dataFive = vsip_vcreate_f(L,0);
    vsip_vview_f* dataSix = vsip_vcreate_f(L,0);
    vsip_vview_f* dataSeven = vsip_vcreate_f(L,0);
    vsip_vview_f* dataEight = vsip_vcreate_f(L,0);
    vsip_randstate *state = vsip_randcreate(7,1,1,VSIP_NPRNG);
    vsip_randstate *stateOne  = vsip_randcreate(7,NS,1,VSIP_NPRNG);
    vsip_randstate *stateTwo  = vsip_randcreate(7,NS,2,VSIP_NPRNG);
    vsip_randstate *stateThree = vsip_randcreate(7,NS,3,VSIP_NPRNG);
    vsip_randstate *stateFour = vsip_randcreate(7,NS,4,VSIP_NPRNG);
    vsip_randstate *stateFive = vsip_randcreate(7,NS,5,VSIP_NPRNG);
    vsip_randstate *stateSix = vsip_randcreate(7,NS,6,VSIP_NPRNG);
    vsip_randstate *stateSeven = vsip_randcreate(7,NS,7,VSIP_NPRNG);
    vsip_randstate *stateEight = vsip_randcreate(7,NS,8,VSIP_NPRNG);
    vsip_vrandu_f(stateOne,dataOne);
    vsip_vrandu_f(stateTwo,dataTwo);
    vsip_vrandu_f(stateThree,dataThree);
    vsip_vrandu_f(stateFour,dataFour);
    vsip_vrandu_f(stateFive,dataFive);
    vsip_vrandu_f(stateSix,dataSix);
    vsip_vrandu_f(stateSeven,dataSeven);
    vsip_vrandu_f(stateEight,dataEight);
    vsip_vcopy_f_f(dataOne,data);
    vsip_vsub_f(data,dataTwo,data);
    vsip_vadd_f(data,dataThree,data);
    vsip_vsub_f(data,dataFour,data);
    vsip_vadd_f(data,dataFive,data);
    vsip_vsub_f(data,dataSix,data);
    vsip_vadd_f(data,dataSeven,data);
    vsip_vsub_f(data,dataEight,data);
    vsip_vhisto_f(dataOne,-.10,1.1,VSIP_HIST_RESET,histoU);
    vsip_vhisto_f(data,-5,5,VSIP_HIST_RESET,histoN);
    printf("histoN =");VU_vprint_f(histoN);
    printf("histoU =");VU_vprint_f(histoU);
    /*destroy the vector views and any associated blocks*/
    vsip_valldestroy_f(histoU);
    vsip_valldestroy_f(histoN);
    vsip_valldestroy_f(data);
    vsip_valldestroy_f(dataOne);
    vsip_valldestroy_f(dataTwo);
    vsip_valldestroy_f(dataThree);
    vsip_valldestroy_f(dataFour);
    vsip_valldestroy_f(dataFive);
    vsip_valldestroy_f(dataSix);
    vsip_valldestroy_f(dataSeven);
    vsip_valldestroy_f(dataEight);
    vsip_randdestroy(state);
    vsip_randdestroy(stateOne);
    vsip_randdestroy(stateTwo);
    vsip_randdestroy(stateThree);
    vsip_randdestroy(stateFour);
    vsip_randdestroy(stateFive);
    vsip_randdestroy(stateSix);
    vsip_randdestroy(stateSeven);
    vsip_randdestroy(stateEight); 
}vsip_finalize((void*)0); return 1;
}
void VU_vprint_f(vsip_vview_f *a)
{
    vsip_vattr_f attr;
    vsip_index i;
    vsip_vgetattrib_f(a,&attr);
    printf("[");
    for(i=0; i<attr.length-1; i++)
         printf("%7.4f;\n",vsip_vget_f(a,i));
    printf("%7.4f];\n", vsip_vget_f(a,i));
    return;
}

