/* Modified RJudd December 12, 1997 */
/* SPAWARSYSCEN D881 */
/**********************************************************************
// For TASP VSIPL Documentation and Code neither the United States    /
// Government, the United States Navy, nor any of their employees,    /
// makes any warranty, express or implied, including the warranties   /
// of merchantability and fitness for a particular purpose, or        /
// assumes any legal liability or responsibility for the accuracy,    /
// completeness, or usefulness of any information, apparatus,         /
// product, or process disclosed, or represents that its use would    /
// not infringe privately owned rights                                /
**********************************************************************/
/* $Id: vsip_rcvmul_f.c,v 1.1 1999/12/02 19:02:51 judd Exp $ */
/* Modified RJudd June 28, 1998 */
/* to add complex block support */
/* vsip_rcvmul_f.c Version 0.000 February 28, 1997
// 
// This file contains the vsip_rcvmul_f function definition.
//
// Copyright (c) Hughes Research Laboratories, Inc. 1997 
// A non-exclusive, non-royalty bearing license is hereby granted to all 
// persons to copy, modify, distribute and produce derivative works for 
// any purpose, provided that this copyright notice and following disclaimer 
// appear on all copies.  
// 
// THIS LICENSE INCLUDES NO WARRANTEES, EXPRESSED OR IMPLIED, WHETHER ORAL 
// OR WRITTEN, WITH RESPECT TO THE SOFTWARE OR OTHER MATERIAL, INCLUDING 
// BUT NOT LIMITED TO ANY IMPLIED WARRANTIES OF MERCHANTABILITY, OR FITNESS 
// FOR A PARTICULAR PURPOSE, OR ARISING FROM A COURSE OF PERFORMANCE, OR 
// DEALING, OR FROM USAGE OR TRADE, OR OF NON-INFRINGEMENT OF ANY PATENTS 
// OF THIRD PARTIES.
//
// This material is based upon work supported by Ft. Huachuca/DARPA under
// Contract No.  DABT63-96-C-0060.  Any opinions, findings and conclusions
// or recommendations expressed in this material are those of the author(s)
// and do not necessarily reflect the views of Ft. Huachuca/DARPA.
//
// Author: E. Robert Tisdale
//
// Revision History:
// Feb. 28, 1997	Added copyright notice.
// Mar. 31, 1997	Modified to conform with VSIP decoder ring.	*/

#include<vsip.h>
#include<vsip_vviewattributes_f.h>
#include<vsip_cvviewattributes_f.h>

extern void (vsip_vcheck_valid_f)(const char*,
  const vsip_vview_f*);
extern void (vsip_cvcheck_valid_f)(const char*,
  const vsip_cvview_f*);
extern void (vsip_vcheck_lengths_f)(const char*,
  int, const vsip_vview_f*, int, const vsip_vview_f*);
extern void (vsip_cvcheck_lengths_f)(const char*,
  int, const vsip_cvview_f*, int, const vsip_cvview_f*);
extern void (vsip_vcheck_clobber_f)(const char*,
  const vsip_vview_f*, const vsip_vview_f*);
extern void (vsip_cvcheck_clobber_f)(const char*,
  const vsip_cvview_f*, const vsip_cvview_f*);

void (vsip_rcvmul_f)(
  const vsip_vview_f* a,
  const vsip_cvview_f* b,
  const vsip_cvview_f* r) {		/* r_j = a_j*b_j	*/
#ifdef VSIP_DEVELOPMENT_MODE
  if (vsip_check_error(vsip_invalid_structure_object)) {
    vsip_vcheck_valid_f("vsip_rcvmul_f", a);
    vsip_cvcheck_valid_f("vsip_rcvmul_f", b);
    vsip_cvcheck_valid_f("vsip_rcvmul_f", r);
    }
  if (vsip_check_error(vsip_nonconformal_view_lengths)) {
    vsip_vview_f*	r_r = vsip_vrealview_f(r);
    vsip_vcheck_lengths_f("vsip_rcvmul_f", 1, a, 3, r_r);
    vsip_cvcheck_lengths_f("vsip_rcvmul_f", 2, b, 3, r);
    vsip_vdestroy_f(r_r);
    }
  if (vsip_check_error(vsip_clobbered_source_operand)) {
    vsip_vview_f*	r_r = vsip_vrealview_f(r);
    vsip_vview_f*	i_r = vsip_vimagview_f(r);
    vsip_vcheck_clobber_f("vsip_rcvmul_f", a, r_r);
    vsip_vcheck_clobber_f("vsip_rcvmul_f", a, i_r);
    vsip_cvcheck_clobber_f("vsip_rcvmul_f", b, r);
    vsip_vdestroy_f(i_r);
    vsip_vdestroy_f(r_r);
    }
#endif /* VSIP_DEVELOPMENT_MODE */
  {
      /* register */ vsip_length n = r->length;
      vsip_stride cbst = b->block->cstride;
      vsip_stride crst = r->block->cstride;
      vsip_scalar_f *ap  = (vsip_scalar_f *)((a->block->array) + a->offset * a->block->rstride),
                    *bpr = (vsip_scalar_f *)((b->block->R->array) + cbst * b->offset),
                    *rpr = (vsip_scalar_f *)((r->block->R->array) + crst * r->offset);
      vsip_scalar_f *bpi = (vsip_scalar_f *)((b->block->I->array) + cbst * b->offset),
                    *rpi = (vsip_scalar_f *)((r->block->I->array) + crst * r->offset);
      vsip_scalar_f  temp = 0;
      /* register */ vsip_stride ast = a->stride * a->block->rstride,
                                 bst = (cbst * b->stride), 
                                 rst = (crst * r->stride);
      /*end define*/
      while(n-- > 0){
          temp = *ap * *bpr ;
          *rpi = *ap * *bpi;
          *rpr = temp;
          ap += ast; 
          bpr += bst; bpi += bst;
          rpr += rst; rpi += rst;
      }
   }
}

