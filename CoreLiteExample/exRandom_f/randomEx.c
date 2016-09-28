/* Created by RJudd */
/* SPAWARSYSCEN D881 */
/* Example of add */
 
#include<stdio.h>
#include<vsip.h>

#define L 40                   /*length*/
#define NS 8

int main(){vsip_init((void*)0);
{

    int i;
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
    vsip_vrandu_f(state,data);
    vsip_vrandu_f(stateOne,dataOne);
    vsip_vrandu_f(stateTwo,dataTwo);
    vsip_vrandu_f(stateThree,dataThree);
    vsip_vrandu_f(stateFour,dataFour);
    vsip_vrandu_f(stateFive,dataFive);
    vsip_vrandu_f(stateSix,dataSix);
    vsip_vrandu_f(stateSeven,dataSeven);
    vsip_vrandu_f(stateEight,dataEight);
    for(i=0; i<L; i++)
        printf("%6.4f %6.4f %6.4f %6.4f %6.4f %6.4f %6.4f %6.4f %6.4f\n",
             vsip_vget_f(data,i),
             vsip_vget_f(dataOne,i),
             vsip_vget_f(dataTwo,i),
             vsip_vget_f(dataThree,i),
             vsip_vget_f(dataFour,i),
             vsip_vget_f(dataFive,i),
             vsip_vget_f(dataSix,i),
             vsip_vget_f(dataSeven,i),
             vsip_vget_f(dataEight,i));
    /*destroy the vector views and any associated blocks*/
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
