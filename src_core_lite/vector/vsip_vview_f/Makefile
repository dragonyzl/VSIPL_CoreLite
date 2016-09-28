## RJudd October 11, 1998 
## SPAWARSYSCEN D881 

CC=gcc
INCLUDE=-I../../../include -I../../../include/privateCL
DEFINES=-DVSIP_PERFORMANCE_MODE
OPTIONS=-O2 -Wall -ansi -pedantic
AR=ar
AR_OPTIONS=rcvs
ARLIB=libvsip_cl.a
ARCHIVE=../../../lib/$(ARLIB)
COMPILE=$(CC) $(DEFINES) $(OPTIONS)
SOURCES= vsip_vlog_f.c \
vsip_svadd_f.c \
vsip_svdiv_f.c \
vsip_svmul_f.c \
vsip_vadd_f.c \
vsip_vatan2_f.c \
vsip_vatan_f.c \
vsip_vcos_f.c \
vsip_vdiv_f.c \
vsip_vdot_f.c \
vsip_vexp_f.c \
vsip_vfill_f.c \
vsip_vlog10_f.c \
vsip_vmag_f.c \
vsip_vmax_f.c \
vsip_vmaxval_f.c \
vsip_vmin_f.c \
vsip_vminval_f.c \
vsip_vmul_f.c \
vsip_vneg_f.c \
vsip_vramp_f.c \
vsip_vrecip_f.c \
vsip_vsin_f.c \
vsip_vsq_f.c \
vsip_vsqrt_f.c \
vsip_vsub_f.c \
vsip_vsumsqval_f.c \
vsip_vsumval_f.c
OBJECTS= vsip_vlog_f.o \
vsip_svadd_f.o \
vsip_svdiv_f.o \
vsip_svmul_f.o \
vsip_vadd_f.o \
vsip_vatan2_f.o \
vsip_vatan_f.o \
vsip_vcos_f.o \
vsip_vdiv_f.o \
vsip_vdot_f.o \
vsip_vexp_f.o \
vsip_vfill_f.o \
vsip_vlog10_f.o \
vsip_vmag_f.o \
vsip_vmax_f.o \
vsip_vmaxval_f.o \
vsip_vmin_f.o \
vsip_vminval_f.o \
vsip_vmul_f.o \
vsip_vneg_f.o \
vsip_vramp_f.o \
vsip_vrecip_f.o \
vsip_vsin_f.o \
vsip_vsq_f.o \
vsip_vsqrt_f.o \
vsip_vsub_f.o \
vsip_vsumsqval_f.o \
vsip_vsumval_f.o

$(ARCHIVE):		$(OBJECTS)
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

obj:	$(OBJECTS)

arch:
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

$(OBJECTS):	$(SOURCES)
	$(COMPILE) $(INCLUDE) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)
