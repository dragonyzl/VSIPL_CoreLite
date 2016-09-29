# VSIPL_CoreLite
Vector, Signal, And Image Processing Library(VSIPL) is a library for image processing. This project aims to utilize OpenMP to make the library parallel.

The structure of the project as following.
```

   |-CoreLiteExample
   |---exAdd_f
   |---example1
   |---example10
   |---example11
   |---example8
   |---exCcfftop_f
   |---exCmagsq_f
   |---exDiv_f
   |---exEuler_f
   |---exExp_f
   |---exHisto_f
   |---exRandom_f
   |---exRcfftop_f
   |---exSin_f
   |-include
   |---privateCL
   |-lib
   |-src_core_lite
   |---error
   |---scalar
   |-----vsip_cscalar_f
   |---signal
   |-----vsip_fft_f
   |-----vsip_fir_f
   |---support
   |-----block
   |-------error
   |-------vsip_block_f
   |-------vsip_block_i
   |-------vsip_cblock_f
   |-----copy
   |-----init_fin
   |-----vector
   |-------vsip_cvview_f
   |---------error
   |-------vsip_vview_f
   |---------error
   |-------vsip_vview_i
   |---------error
   |---vector
   |-----vsip_cvview_f
   |-----vsip_random
   |-----vsip_vview_f
   |-testing
```
