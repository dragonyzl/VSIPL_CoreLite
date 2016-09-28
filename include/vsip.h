#ifndef _vsip_header_h
#define _vsip_header_h 1
/* Modified By RJudd March 8, 1998 */
/* Modified to concatenate headers */
/* Randall Judd is a US Government Employee.  Work preformed on VSIP
// are part of his official duties.  The US Government has a license
// under these copyrights, and this material may be reproduced and used
// by or for the US Government */

/* very first vsip.h by hughes, copyright below */
/* 
// This file contains public VSIP type definitions.
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
// There are    real scalar typedefs for each
// of the eleven built-in ANSI C types
//
//	Suffix	C_type
//   	_d	double
//   	_f	float
//   	_i	signed int
//  	_si	signed short int
// 
// Revision History:
// Mar. 28, 1997	Added copyright notice.				*/

#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<math.h>
#include<limits.h>
#include<vsip_error.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define VSIP_PI M_PI

/* support flags and hints; enumerated types */
typedef enum {
    VSIP_MEM_NONE          = 0,            /* No Hint           */
    VSIP_MEM_RDONLY        = 1,            /* Read Only         */
    VSIP_MEM_CONST         = 2,            /* Constant          */
    VSIP_MEM_SHARED        = 3,            /* Shared            */
    VSIP_MEM_SHARED_RDONLY = 4,            /* Shared, Read Only */
    VSIP_MEM_SHARED_CONST  = 5             /* Shared, Constant  */
} vsip_memory_hint;

typedef enum {
    VSIP_CMPLX_INTERLEAVED,
    VSIP_CMPLX_SPLIT,
    VSIP_CMPLX_NONE
} vsip_cmplx_mem;

#define VSIP_CMPLX_MEM VSIP_CMPLX_INTERLEAVED

/* Signal flags */
typedef enum {
    VSIP_FFT_FWD = -1,
    VSIP_FFT_INV = +1
} vsip_fft_dir;

typedef enum {
    VSIP_FFT_IP = 0,
    VSIP_FFT_OP = 1
} vsip_fft_place;

typedef enum {
    VSIP_ALG_SPACE = 0,
    VSIP_ALG_TIME  = 1,
    VSIP_ALG_NOISE = 2
} vsip_alg_hint;

typedef enum {
    VSIP_NONSYM = 0,
    VSIP_SYM_EVEN_LEN_ODD   = 1,
    VSIP_SYM_EVEN_LEN_EVEN  = 2
} vsip_symmetry;

typedef enum {
    VSIP_STATE_NO_SAVE = 1,
    VSIP_STATE_SAVE = 2
} vsip_obj_state;

typedef enum {
    VSIP_HIST_RESET = 1,
    VSIP_HIST_ACCUM = 2
} vsip_hist_opt;

/* random number generator flags */
typedef enum {
    VSIP_PRNG = 0,
    VSIP_NPRNG = 1
} vsip_rng;
/* end enumerated types */
/************************************************************************/
/* Boolean type definition						*/
typedef signed int vsip_scalar_bl;
typedef	vsip_scalar_bl	vsip_bool;
#define VSIP_MAX_SCALAR_BL INT_MAX
#define VSIP_FALSE 0
#define VSIP_TRUE !VSIP_FALSE

/*   Index type definitions						*/
typedef unsigned long int vsip_scalar_vi;		/* vector index	*/
typedef struct { vsip_scalar_vi r,c; } vsip_scalar_mi;	/* matrix index	*/
typedef	vsip_scalar_vi vsip_index;
#define VSIP_MAX_SCALAR_VI ULONG_MAX

/* Type for offset, stride and length */
typedef	vsip_scalar_vi	vsip_offset;
typedef	vsip_scalar_vi	vsip_length;
typedef signed long int	vsip_stride;

/*    real scalar type definitions					*/
typedef			float	vsip_scalar_f;
typedef   signed	int	vsip_scalar_i;
typedef   unsigned      int     vsip_scalar_ue32;

#define	VSIP_MAX_SCALAR_F	  FLT_MAX
#define	VSIP_MAX_SCALAR_I	  INT_MAX

#define	VSIP_MIN_SCALAR_F	  FLT_MIN
#define	VSIP_MIN_SCALAR_I	  INT_MIN

/* complex scalar type definitions					*/
typedef struct { vsip_scalar_f  r, i; } vsip_cscalar_f;

/************************************************************************/
/* Begin incomplete typedefs */
/* Block typedefs */
struct vsip_blockattributes_f;
typedef struct vsip_blockattributes_f vsip_block_f;

struct vsip_cblockattributes_f;
typedef struct vsip_cblockattributes_f vsip_cblock_f;

struct vsip_blockattributes_i;
typedef struct vsip_blockattributes_i vsip_block_i;

/* Real vector view typedefs */
struct vsip_vviewattributes_f; 
typedef struct vsip_vviewattributes_f	vsip_vview_f;

struct vsip_vviewattributes_i; 
typedef struct vsip_vviewattributes_i	vsip_vview_i;

/* Real matrix view typedefs */
struct vsip_mviewattributes_f; 
typedef struct vsip_mviewattributes_f	vsip_mview_f;

/* Complex vector view typedefs */
struct vsip_cvviewattributes_f;
typedef struct vsip_cvviewattributes_f	vsip_cvview_f;

/* Random -- Random object type definition */
struct vsip_randobject;
typedef struct vsip_randobject vsip_randstate;

/* signal -- Signal Procesing object type definitions */
struct vsip_fftattributes_f;
typedef struct vsip_fftattributes_f vsip_fft_f;

struct vsip_firattributes_f;
typedef struct vsip_firattributes_f vsip_fir_f;

struct vsip_cfirattributes_f;
typedef struct vsip_cfirattributes_f vsip_cfir_f;

/* End incomplete type definitions */
/************************************************************************/

/* attributes structures */
/* The following are used as arguments to get and put attribute functions */

typedef struct {
       vsip_offset  offset;
       vsip_stride  stride;
       vsip_length  length;
       vsip_block_f* block;
} vsip_vattr_f; /* vector view attributes for double */

typedef struct {
       vsip_offset  offset;
       vsip_stride  stride;
       vsip_length  length;
       vsip_cblock_f* block;
} vsip_cvattr_f; /* complex vector view attributes for double */

typedef struct {
       vsip_offset   offset;
       vsip_stride   stride;
       vsip_length   length;
       vsip_block_i* block;
} vsip_vattr_i; /* vector view attributes for integer */

/* signal attributes structures */
typedef struct{
       vsip_scalar_vi input;       /* input length */
       vsip_scalar_vi output;      /* output length */
       vsip_fft_place place;       /* in/out-of-place */
       vsip_scalar_f scale;        /* scale factor */
       vsip_fft_dir dir;           /* Forward or inverse */
} vsip_fft_attr_f;

typedef struct{
       vsip_scalar_vi kernel_len;    /* Kernel Length */
       vsip_symmetry symm;           /* Kernel symmetry */
       vsip_scalar_vi in_len;        /* Filter input segment length */
       vsip_scalar_vi out_len;       /* filter output segment length */
       vsip_length decimation;
       vsip_obj_state state;
} vsip_fir_attr;

typedef struct{
       vsip_scalar_vi kernel_len;    /* Kernel Length */
       vsip_symmetry symm;           /* Kernel symmetry */
       vsip_scalar_vi in_len;        /* Filter input segment length */
       vsip_scalar_vi out_len;       /* filter output segment length */
       vsip_length decimation;
       vsip_obj_state state;
} vsip_cfir_attr;

/* Created By RJudd March 8, 1998 */
/* SPAWARSYSCEN D881 */
/* Randall Judd is a US Government Employee.  Work preformed on VSIP
// are part of his official duties.  The US Government has a license
// under these copyrights, and this material may be reproduced and used
// by or for the US Government */

/* Based on VSIP pre-release Reference Version December 1997 HRL
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
// This file contains a prototype object oriented ANSI C language definition
// for the application programmer's interface
// to the VSIP (Vector Signal Image Processing) scalar library.
//
// Revision History:
// Feb. 28, 1997	Added copyright notice.
// Mar. 31, 1997	Modified to conform with VSIP decoder ring.	*/

#define vsip_cos_f    (float)cos
#define vsip_sin_f    (float)sin
#define vsip_tan_f    (float)tan
#define vsip_acos_f   (float)acos
#define vsip_asin_f   (float)asin
#define vsip_atan_f   (float)atan
#define vsip_cosh_f   (float)cosh
#define vsip_sinh_f   (float)sinh
#define vsip_tanh_f   (float)tanh
#define vsip_exp_f    (float)exp
#define vsip_log_f    (float)log
#define vsip_log10_f  (float)log10
#define vsip_mag_f    (float)fabs
#define vsip_pow_f    (float)pow
#define vsip_atan2_f  (float)atan2
#define vsip_sqrt_f   (float)sqrt
#define vsip_ceil_f   (float)ceil
#define vsip_floor_f  (float)floor

/* vsip_scalar_f */
vsip_scalar_f (vsip_exp10_f)(vsip_scalar_f x);
vsip_scalar_f (vsip_sqrd2_f)(vsip_scalar_f x, vsip_scalar_f y);
vsip_scalar_f (vsip_min_f)(vsip_scalar_f x, vsip_scalar_f y);
vsip_scalar_f (vsip_max_f)(vsip_scalar_f x, vsip_scalar_f y);
vsip_scalar_f (vsip_hypot_f)(vsip_scalar_f x, vsip_scalar_f y);
vsip_scalar_f (vsip_recip_f)(vsip_scalar_f x);          /* 1/x          */
vsip_scalar_f (vsip_rsqrt_f)(vsip_scalar_f x);          /* 1/sqrt(x)    */

/* vsip_random */
vsip_scalar_f (vsip_randu_f)(vsip_randstate*);
vsip_cscalar_f (vsip_crandu_f)(vsip_randstate*);
vsip_scalar_f (vsip_randn_f)(vsip_randstate*);
vsip_cscalar_f (vsip_crandn_f)(vsip_randstate*);

/* vsip_cscalar_f */
#ifdef VSIP_DEVELOPMENT_MODE
vsip_scalar_f (vsip_real_f)(vsip_cscalar_f x);
vsip_scalar_f (vsip_imag_f)(vsip_cscalar_f x);
#else
#define vsip_real_f(x) ((x).r)
#define vsip_imag_f(x) ((x).i)
#endif

vsip_cscalar_f (vsip_cmplx_f)(vsip_scalar_f x, vsip_scalar_f y);
vsip_cscalar_f (vsip_cneg_f)(vsip_cscalar_f x);		
vsip_cscalar_f (vsip_cmul_f)(vsip_cscalar_f x, vsip_cscalar_f y);
vsip_cscalar_f (vsip_rcmul_f)(vsip_scalar_f x, vsip_cscalar_f y);
vsip_cscalar_f (vsip_cdiv_f)(vsip_cscalar_f x, vsip_cscalar_f y);
vsip_cscalar_f (vsip_rcdiv_f)(vsip_scalar_f x, vsip_cscalar_f y);
vsip_cscalar_f (vsip_crdiv_f)(vsip_cscalar_f x, vsip_scalar_f y);
vsip_cscalar_f (vsip_cadd_f)(vsip_cscalar_f x, vsip_cscalar_f y);
vsip_cscalar_f (vsip_rcadd_f)(vsip_scalar_f x, vsip_cscalar_f y);
vsip_cscalar_f (vsip_csub_f)(vsip_cscalar_f x, vsip_cscalar_f y);
vsip_cscalar_f (vsip_rcsub_f)(vsip_scalar_f x, vsip_cscalar_f y);
vsip_cscalar_f (vsip_crsub_f)(vsip_cscalar_f x, vsip_scalar_f y);
vsip_scalar_bl (vsip_cleq_f)(vsip_cscalar_f x, vsip_cscalar_f y);
vsip_scalar_bl (vsip_clne_f)(vsip_cscalar_f x, vsip_cscalar_f y);
vsip_scalar_f (vsip_cmag_f)(vsip_cscalar_f x);			
vsip_scalar_f (vsip_arg_f)(vsip_cscalar_f x);		
vsip_cscalar_f (vsip_conj_f)(vsip_cscalar_f x);		
vsip_scalar_f (vsip_cmagsq_f)(vsip_cscalar_f x);	
vsip_cscalar_f (vsip_cjmul_f)(vsip_cscalar_f x, vsip_cscalar_f y);
void (vsip_polar_f)(vsip_cscalar_f a, vsip_scalar_f* r, vsip_scalar_f* t);
vsip_cscalar_f (vsip_rect_f)(vsip_scalar_f r, vsip_scalar_f t);
vsip_cscalar_f (vsip_cexp_f)(vsip_cscalar_f x);		
vsip_cscalar_f (vsip_clog_f)(vsip_cscalar_f x);		
vsip_cscalar_f (vsip_cexp10_f)(vsip_cscalar_f x);	
vsip_cscalar_f (vsip_clog10_f)(vsip_cscalar_f x);	
vsip_cscalar_f (vsip_csqrt_f)(vsip_cscalar_f x);	
vsip_cscalar_f (vsip_crecip_f)(vsip_cscalar_f x);	
vsip_cscalar_f (vsip_crsqrt_f)(vsip_cscalar_f x);	
void (vsip_CMPLX_f)(vsip_scalar_f x, vsip_scalar_f y, vsip_cscalar_f* z);
void (vsip_CNEG_f)(vsip_cscalar_f x, vsip_cscalar_f* y);
void (vsip_CMUL_f)(vsip_cscalar_f x, vsip_cscalar_f y, vsip_cscalar_f* z);
void (vsip_RCMUL_f)(vsip_scalar_f x, vsip_cscalar_f y, vsip_cscalar_f* z);
void (vsip_CDIV_f)(vsip_cscalar_f x, vsip_cscalar_f y, vsip_cscalar_f* z);
void (vsip_CRDIV_f)(vsip_cscalar_f x, vsip_scalar_f y, vsip_cscalar_f* z);
void (vsip_CADD_f)(vsip_cscalar_f x, vsip_cscalar_f y, vsip_cscalar_f* z);
void (vsip_RCADD_f)(vsip_scalar_f x, vsip_cscalar_f y, vsip_cscalar_f* z);
void (vsip_CSUB_f)(vsip_cscalar_f x, vsip_cscalar_f y, vsip_cscalar_f* z);
void (vsip_RCSUB_f)(vsip_scalar_f x, vsip_cscalar_f y, vsip_cscalar_f* z);
void (vsip_CRSUB_f)(vsip_cscalar_f x, vsip_scalar_f y, vsip_cscalar_f* z);
void (vsip_CONJ_f)(vsip_cscalar_f x, vsip_cscalar_f* y);
void (vsip_CJMUL_f)(vsip_cscalar_f x, vsip_cscalar_f y, vsip_cscalar_f* z);
void (vsip_RECT_f)(vsip_scalar_f r, vsip_scalar_f t, vsip_cscalar_f* a);
void (vsip_CEXP_f)(vsip_cscalar_f x, vsip_cscalar_f* y);
void (vsip_CLOG_f)(vsip_cscalar_f x, vsip_cscalar_f* y);
void (vsip_CSQRT_f)(vsip_cscalar_f x, vsip_cscalar_f* y);
void (vsip_CRECIP_f)(vsip_cscalar_f x, vsip_cscalar_f* y);

/* Constructed by RJudd */
/* SPAWARSYSCEN D881 */
/* support header file constructed using References header files */
/* Modified to support support functions as needed */
/* Modified RJudd August 3, 1998 */
/* to add attribute structure */ 
/* Based on work in December 1997 Reference pre-release by HRL
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
// This file contains a prototype object oriented ANSI C language definition
// for the application programmer's interface
// to the VSIP (Vector Signal Image Processing) block data library.
// 
// Two distinct classes of array objects are accomodated:
// 1.	Private arrays are allocated, accessed and deallocated
// 	only by VSIP library functions.  They permit the VSIP
// 	library developer to exploit optimization opportunities
// 	such as cache memory management, deferred evaluation and
// 	loop fusion transparently to the application program.
// 	
// 2.	Public arrays are allocated, accessed and deallocated
// 	by the application program but may be accessed by VSIP
// 	library functions as well.  They permit VSIP library
// 	functions to reference large ANSI C arrays directly
// 	instead of copying them into or out of private arrays.
// 	Otherwise, they should be avoided because they tend to
// 	frustrate VSIP library optimizations.
// The attributes of an array object are encapsulated in an ANSI C struct
// which is hidden from the application programmer and can only be created,
// accessed and deleted through functions provided by the library developer.
//
// Revision History:
// Feb. 28, 1997	Added copyright notice.
// Mar. 31, 1997	Modified to conform with VSIP decoder ring.	*/

/* Start init/fin */
int vsip_init(
     void*);

int vsip_finalize(
     void*);

/* Start block */

vsip_cmplx_mem (vsip_cstorage)(
     void);

/* vsip_block_f */
vsip_block_f* (vsip_blockcreate_f)(   /* create */
     size_t N,
     vsip_memory_hint h);
 
vsip_block_f* (vsip_blockbind_f)(     /* bind */
     vsip_scalar_f *p,
     size_t N,
     vsip_memory_hint h);
 
vsip_scalar_f* (vsip_blockrebind_f)(  /* rebind */
     vsip_block_f*,
     vsip_scalar_f*);
 
vsip_scalar_f* (vsip_blockfind_f)(    /* find */
     const vsip_block_f *b);

int  (vsip_blockadmit_f)(             /* admit */
     vsip_block_f*,
     vsip_scalar_bl);
 
vsip_scalar_f* (vsip_blockrelease_f)( /* release */
     vsip_block_f*,
     vsip_scalar_bl);
 
void (vsip_blockdestroy_f)(           /* destroy */
     vsip_block_f *b);
 
/* vsip_cblock_f */
vsip_cblock_f* (vsip_cblockcreate_f)(
     size_t N,
     vsip_memory_hint h);

vsip_cblock_f* (vsip_cblockbind_f)(
     vsip_scalar_f *R,vsip_scalar_f *I,
     size_t N,
     vsip_memory_hint h);

void (vsip_cblockrebind_f)(
     vsip_cblock_f*,
     vsip_scalar_f*, vsip_scalar_f*, /* new */
     vsip_scalar_f**, vsip_scalar_f** /* return old */);

void (vsip_cblockfind_f)(
     const vsip_cblock_f *b,
     vsip_scalar_f**,
     vsip_scalar_f**);

int  (vsip_cblockadmit_f)(
     vsip_cblock_f*,
     vsip_scalar_bl);

void (vsip_cblockrelease_f)(
     vsip_cblock_f*,
     vsip_scalar_bl,
     vsip_scalar_f**, vsip_scalar_f**);

void (vsip_cblockdestroy_f)(
     vsip_cblock_f *b);

/* vsip_block_i */
vsip_block_i* (vsip_blockcreate_i)(
     size_t N, 
     vsip_memory_hint h);

vsip_block_i* (vsip_blockbind_i)(
     vsip_scalar_i *p,
     size_t N, 
     vsip_memory_hint h);

vsip_scalar_i* (vsip_blockrebind_i)(
     vsip_block_i*, 
     vsip_scalar_i*);

vsip_scalar_i* (vsip_blockfind_i)(
     const vsip_block_i *b);

int (vsip_blockadmit_i)(
     vsip_block_i*,
     vsip_scalar_bl);

vsip_scalar_i* (vsip_blockrelease_i)(
     vsip_block_i*,
     vsip_scalar_bl);

void (vsip_blockdestroy_i)(
     vsip_block_i *b);
 
/* end block */
/********************************************************************/

/* vector */
/* vsip_vview_f */
vsip_vview_f* (vsip_vcreate_f)(
     vsip_length n, 
     vsip_memory_hint h);

vsip_vview_f* (vsip_vcloneview_f)(
     const vsip_vview_f* v);

vsip_vview_f* (vsip_vbind_f)(
     const vsip_block_f* b, 
     vsip_offset o, 
     vsip_stride s, 
     vsip_length n);

vsip_block_f* (vsip_vdestroy_f)(
     vsip_vview_f* v);

void (vsip_valldestroy_f)(
     vsip_vview_f*);

vsip_vview_f* (vsip_vsubview_f)(
     const vsip_vview_f* v, 
     vsip_index j, 
     vsip_length n);

vsip_block_f* (vsip_vgetblock_f)(
     const vsip_vview_f* v);

vsip_offset (vsip_vgetoffset_f)(
     const vsip_vview_f* v);

vsip_stride (vsip_vgetstride_f)(
     const vsip_vview_f* v);

vsip_length (vsip_vgetlength_f)(
     const vsip_vview_f* v);

void (vsip_vgetattrib_f)(
     const vsip_vview_f*,
     vsip_vattr_f*);

vsip_scalar_f (vsip_vget_f)(
     const vsip_vview_f* v, 
     vsip_index j);

vsip_vview_f* (vsip_vputoffset_f)(
     vsip_vview_f* v, 
     vsip_offset o);

vsip_vview_f* (vsip_vputstride_f)(
     vsip_vview_f* v, 
     vsip_stride s);

vsip_vview_f* (vsip_vputlength_f)(
     vsip_vview_f* v, 
     vsip_length n);

vsip_vview_f* (vsip_vputattrib_f)(
     vsip_vview_f*,
     const vsip_vattr_f*);

void (vsip_vput_f)(
     const vsip_vview_f* v,
     vsip_index j, 
     vsip_scalar_f x);

/* vsip_vview_i */
vsip_vview_i* (vsip_vcreate_i)(
     vsip_length n, 
     vsip_memory_hint h);

vsip_vview_i* (vsip_vcloneview_i)(
     const vsip_vview_i* v);

vsip_vview_i* (vsip_vbind_i)(
     const vsip_block_i* b, 
     vsip_offset o, 
     vsip_stride s, 
     vsip_length n);
   
vsip_block_i* (vsip_vdestroy_i)(
     vsip_vview_i* v);

void (vsip_valldestroy_i)(
     vsip_vview_i* v);

vsip_vview_i* (vsip_vsubview_i)(
     const vsip_vview_i* v, 
     vsip_index j, 
     vsip_length n);

vsip_block_i* (vsip_vgetblock_i)(
     const vsip_vview_i* v);
 
vsip_offset (vsip_vgetoffset_i)(
     const vsip_vview_i* v);
 
vsip_stride (vsip_vgetstride_i)(
     const vsip_vview_i* v);
 
vsip_length (vsip_vgetlength_i)(
     const vsip_vview_i* v);
 
void (vsip_vgetattrib_i)(
     const vsip_vview_i*,
     vsip_vattr_i*);
 
vsip_scalar_i (vsip_vget_i)(
     const vsip_vview_i* v, 
     vsip_index j);

vsip_vview_i* (vsip_vputoffset_i)(
     vsip_vview_i* v, 
     vsip_offset o);

vsip_vview_i* (vsip_vputstride_i)(
     vsip_vview_i* v, 
     vsip_stride s);

vsip_vview_i* (vsip_vputlength_i)(
     vsip_vview_i* v, 
     vsip_length n);

vsip_vview_i* (vsip_vputattrib_i)(
     vsip_vview_i*,
     const vsip_vattr_i*);

void (vsip_vput_i)(
     const vsip_vview_i* v,
     vsip_index j, 
     vsip_scalar_i x);

/* Copy prototypes */
void (vsip_vcopy_f_f)(
  const vsip_vview_f* a,
  const vsip_vview_f* r);

void (vsip_cvcopy_f_f)(
  const vsip_cvview_f* a,
  const vsip_cvview_f* r);

void (vsip_vcopy_i_i)(
  const vsip_vview_i* a,
  const vsip_vview_i* r);

void (vsip_vcopy_i_f)(
  const vsip_vview_i* a,
  const vsip_vview_f* r);

void (vsip_vcopy_f_i)(
  const vsip_vview_f* a,
  const vsip_vview_i* r);

/* end complex vector double */

/* vsip_cvview_f */
vsip_cvview_f* (vsip_cvcreate_f)(
     vsip_length n, vsip_memory_hint h);

vsip_cvview_f* (vsip_cvcloneview_f)(
     const vsip_cvview_f* v);

vsip_cvview_f* (vsip_cvbind_f)(
     const vsip_cblock_f* b, 
     vsip_offset o, 
     vsip_stride s, 
     vsip_length n);

vsip_cblock_f* (vsip_cvdestroy_f)(
     vsip_cvview_f* v);

void (vsip_cvalldestroy_f)(
     vsip_cvview_f* v);

vsip_cvview_f* (vsip_cvsubview_f)(
     const vsip_cvview_f* v, 
     vsip_index j,
     vsip_length n);

vsip_vview_f* (vsip_vrealview_f)(
     const vsip_cvview_f* v);

vsip_vview_f* (vsip_vimagview_f)(
     const vsip_cvview_f* v);

vsip_cblock_f* (vsip_cvgetblock_f)(
     const vsip_cvview_f* v);

vsip_offset (vsip_cvgetoffset_f)(
     const vsip_cvview_f* v);

vsip_stride (vsip_cvgetstride_f)(
     const vsip_cvview_f* v);

vsip_length (vsip_cvgetlength_f)(
     const vsip_cvview_f* v);

void (vsip_cvgetattrib_f)(
     const vsip_cvview_f* ,
     vsip_cvattr_f*);

vsip_cscalar_f (vsip_cvget_f)(
     const vsip_cvview_f* v, 
     vsip_index j);

vsip_cvview_f* (vsip_cvputoffset_f)(
     vsip_cvview_f* v, 
     vsip_offset o);

vsip_cvview_f* (vsip_cvputstride_f)(
     vsip_cvview_f* v, 
     vsip_stride s);

vsip_cvview_f* (vsip_cvputlength_f)(
     vsip_cvview_f* v, 
     vsip_length n);

vsip_cvview_f* (vsip_cvputattrib_f)(
     vsip_cvview_f*,
     const vsip_cvattr_f*);

void (vsip_cvput_f)(
     const vsip_cvview_f* v,
     vsip_index j, 
     vsip_cscalar_f x);

/* end complex vector view float */
/********************************************************************/
/* vsip_vview_f */
vsip_scalar_f (vsip_vminval_f)(
     const vsip_vview_f* a,
     vsip_index* j);

vsip_scalar_f (vsip_vmaxval_f)(
     const vsip_vview_f* a,
     vsip_index* j);

void (vsip_vneg_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vmul_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b,
     const vsip_vview_f* r);

void (vsip_svmul_f)(
     vsip_scalar_f alpha,
     const vsip_vview_f* b,
     const vsip_vview_f* r);

void (vsip_vdiv_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b,
     const vsip_vview_f* r);

void (vsip_svdiv_f)(
     vsip_scalar_f alpha,
     const vsip_vview_f* b,
     const vsip_vview_f* r);

void (vsip_vadd_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b,
     const vsip_vview_f* r);

void (vsip_svadd_f)(
     vsip_scalar_f alpha,
     const vsip_vview_f* b,
     const vsip_vview_f* r);

void (vsip_vsub_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b,
     const vsip_vview_f* r);

void (vsip_vcos_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vsin_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vtan_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vatan_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vexp_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vlog_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vlog10_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vsqrt_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vmag_f)(const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vatan2_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b,
     const vsip_vview_f* r);

void (vsip_vsq_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vrecip_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* r);

void (vsip_vmin_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b,
     const vsip_vview_f* w);

void (vsip_vmax_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b,
     const vsip_vview_f* w);

void (vsip_vfill_f)(
     vsip_scalar_f alpha,
     const vsip_vview_f* r);
   
void (vsip_vramp_f)(
     vsip_scalar_f z,
     vsip_scalar_f d,
     const vsip_vview_f* r);

vsip_scalar_f (vsip_vsumval_f)(
     const vsip_vview_f* a);
   
vsip_scalar_f (vsip_vsumsqval_f)(
     const vsip_vview_f* a);

vsip_scalar_f (vsip_vdot_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b);

/******************************************************************/
/* vsip_cvview_f */
void (vsip_cvneg_f)(const vsip_cvview_f* a,
     const vsip_cvview_f* r);

void (vsip_cvmul_f)(
     const vsip_cvview_f* a,
     const vsip_cvview_f* b,
     const vsip_cvview_f* r);

void (vsip_csvmul_f)(
     vsip_cscalar_f alpha,
     const vsip_cvview_f* b,
     const vsip_cvview_f* r);

void (vsip_rcvmul_f)(
     const vsip_vview_f* a,
     const vsip_cvview_f* b,
     const vsip_cvview_f* r);

void (vsip_rscvmul_f)(
     vsip_scalar_f alpha,
     const vsip_cvview_f* b,
     const vsip_cvview_f* r);

void (vsip_cvadd_f)(
     const vsip_cvview_f* a,
     const vsip_cvview_f* b,
     const vsip_cvview_f* r);

void (vsip_cvsub_f)(
     const vsip_cvview_f* a,
     const vsip_cvview_f* b,
     const vsip_cvview_f* r);

void (vsip_cvmag_f)(
     const vsip_cvview_f* a,
     const vsip_vview_f* r);

void (vsip_cvconj_f)(
     const vsip_cvview_f* a,
     const vsip_cvview_f* r);

void (vsip_cvjmul_f)(
     const vsip_cvview_f* a,
     const vsip_cvview_f* b,
     const vsip_cvview_f* w);

void (vsip_vcmagsq_f)(
     const vsip_cvview_f* a,
     const vsip_vview_f* r);

vsip_cscalar_f (vsip_cvdot_f)(
     const vsip_cvview_f* a,
     const vsip_cvview_f* b);

vsip_cscalar_f (vsip_cvjdot_f)(
     const vsip_cvview_f* a,
     const vsip_cvview_f* b);

void (vsip_vreal_f)(
     const vsip_cvview_f* a,
     const vsip_vview_f* r);

void (vsip_vimag_f)(
     const vsip_cvview_f* a,
     const vsip_vview_f* r);

void (vsip_vcmplx_f)(
     const vsip_vview_f* a,
     const vsip_vview_f* b,
     const vsip_cvview_f* r);

/* Random */
vsip_randstate *vsip_randcreate(
     vsip_index seed,
     vsip_index numseqs,
     vsip_index id,
     vsip_rng portable); 

void vsip_vrandu_f(
     vsip_randstate *state,
     const vsip_vview_f *r);

int  vsip_randdestroy(
     vsip_randstate *state);

/* end Random */

/* Created by RJudd March 9, 1998 */
/* SPAWARSYSCEN D881 */


/* vsip_vview_f */
void (vsip_cvfreqswap_f)(
     const vsip_cvview_f* a);
 
void (vsip_vfreqswap_f)(
     const vsip_vview_f* a);
   
void (vsip_vhisto_f)(
     const vsip_vview_f* a,
     vsip_scalar_f min,
     vsip_scalar_f max,
     vsip_hist_opt opt,
     const vsip_vview_f* r);
 
/* vsip_fft_f */
void vsip_fft_getattr_f(
       const vsip_fft_f *fft,
       vsip_fft_attr_f *attr);

vsip_fft_f* vsip_ccfftop_create_f(
     vsip_length   length,      /* length of input data */
     vsip_scalar_f scale,       /* scale factor */
     vsip_fft_dir  sign,        /* fft direction */
     unsigned int  ntimes,      /* number of times */
     vsip_alg_hint hint);

vsip_fft_f* vsip_rcfftop_create_f(
     vsip_length   length,      /* length of input data */
     vsip_scalar_f scale,       /* scale factor */
     unsigned int  ntimes,      /* number of times */
     vsip_alg_hint hint);

vsip_fft_f* vsip_crfftop_create_f(
     vsip_length   length,      /* length of input data */
     vsip_scalar_f scale,       /* scale factor */
     unsigned int  ntimes,      /* number of times */
     vsip_alg_hint hint);

vsip_fft_f* vsip_ccfftip_create_f(
     vsip_length   length,      /* length of input data */
     vsip_scalar_f scale,       /* scale factor */
     vsip_fft_dir  sign,        /* fft direction */
     unsigned int  ntimes,      /* number of times */
     vsip_alg_hint hint);

void vsip_ccfftop_f(
     const vsip_fft_f    *fft,
     const vsip_cvview_f *x,
     const vsip_cvview_f *y);

void vsip_rcfftop_f(
     const vsip_fft_f    *fft,
     const vsip_vview_f  *x,
     const vsip_cvview_f *y);
        
void vsip_crfftop_f(
     const vsip_fft_f    *fft,
     const vsip_cvview_f  *x,
     const vsip_vview_f   *y);
        
void vsip_ccfftip_f(
     const vsip_fft_f *fft,
     const vsip_cvview_f *xy);
        
int vsip_fft_destroy_f(
     vsip_fft_f *fft);

/* vsip_fir_f */
void vsip_fir_getattr_f(
     const vsip_fir_f*,
     vsip_fir_attr*);

vsip_fir_f* vsip_fir_create_f(
     const vsip_vview_f*,
     vsip_symmetry,
     vsip_length,
     vsip_length D,
     vsip_obj_state,
     unsigned int,
     vsip_alg_hint);

int vsip_firflt_f(
     vsip_fir_f*,
     const vsip_vview_f*,
     const vsip_vview_f*);

int vsip_fir_destroy_f(
     vsip_fir_f *filt);

void vsip_fir_reset_f(
     vsip_fir_f *filt);

void vsip_cfir_getattr_f(
     const vsip_cfir_f*,
     vsip_cfir_attr*);

vsip_cfir_f* vsip_cfir_create_f(
     const vsip_cvview_f*,
     vsip_symmetry,
     vsip_length,
     vsip_length D,
     vsip_obj_state,
     unsigned int,
     vsip_alg_hint);

int vsip_cfirflt_f(
     vsip_cfir_f*,
     const vsip_cvview_f*,
     const vsip_cvview_f*);

int vsip_cfir_destroy_f(
     vsip_cfir_f *filt);

void vsip_cfir_reset_f(
     vsip_cfir_f *filt);

#endif /*_vsip_header_h*/
