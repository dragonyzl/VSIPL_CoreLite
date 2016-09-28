static vsip_cscalar_f VU_csub_f(
       vsip_cscalar_f a,
       vsip_cscalar_f b)
{
      return vsip_cmplx_f(
               vsip_real_f(a)-vsip_real_f(b),
               vsip_imag_f(a)-vsip_imag_f(b));
}

static vsip_scalar_f VU_cmag_f(
       vsip_cscalar_f a)
{
      vsip_scalar_f a_r = vsip_real_f(a),
                    a_i = vsip_imag_f(a);
      vsip_scalar_f retval = (vsip_scalar_f)sqrt(a_r * a_r + a_i * a_i);
      return retval;
}
           
static vsip_length VU_vgetlength_f(
    vsip_vview_f *X)
{
    vsip_vattr_f attr;
    vsip_vgetattrib_f(X,&attr);
    return attr.length;
}
static vsip_length VU_cvgetlength_f(
    vsip_cvview_f *X)
{
    vsip_cvattr_f attr;
    vsip_cvgetattrib_f(X,&attr);
    return attr.length;
}

/* VU_limitIP_f does an in place replacement of the values in
/   "a" with 1 if the value is greater than "error", otherwise 0*/
static void VU_limitIP_f(
       vsip_vview_f* a,
       vsip_scalar_f error)
{
     vsip_length n = VU_vgetlength_f(a);
     vsip_index i;
     for(i=0; i<n; i++)
        vsip_vput_f(a, i,
            (vsip_vget_f(a,i)>error) ? 1:0);
     return;
}

static void VU_vprintm_f(char s[],
    vsip_vview_f *X)
{
    char format[50];
    vsip_length L = VU_vgetlength_f(X);
    vsip_index vi;
    vsip_scalar_f x;
    strcpy(format,"%");
    strcat(format,s);
    strcat(format,"f %s\n");
    printf("[\n");
    for(vi=0; vi<L; vi++){
      x=vsip_vget_f(X,vi);
      printf(format,x,";");
    }
    printf("];\n");
    return;
}

static void VU_cvprintm_f(char s[],
    vsip_cvview_f *X)
{
    char format[50];
    vsip_length L = VU_cvgetlength_f(X);
    vsip_index vi;
    vsip_cscalar_f x;
    strcpy(format,"(%");
    strcat(format,s);
    strcat(format,"f %+");
    strcat(format,s);
    strcat(format,"fi) %s\n");
    printf("[\n");
    for(vi=0; vi<L; vi++){
      x=vsip_cvget_f(X,vi);
      printf(format,vsip_real_f(x),
                    vsip_imag_f(x),";");
    }
    printf("];\n");
    return;
}

