## RJudd October 11, 1998 
## SPAWARSYSCEN D881 

CC=gcc
INCLUDE=-I../../../include -I../../../include/privateCL
DEFINES=-DVSIP_PERFORMANCE_MODE
OPTIONS=-O2 -Wall -ansi -pedantic
AR=ar
AR_OPTIONS=rcvs
ARLIB=libvsip_c.a
ARCHIVE=../../../lib/$(ARLIB)
COMPILE=$(CC) $(DEFINES) $(OPTIONS)
SOURCES= vsip_csvmul_f.c \
vsip_cvadd_f.c \
vsip_cvconj_f.c \
vsip_cvdot_f.c \
vsip_cvjdot_f.c \
vsip_cvjmul_f.c \
vsip_cvmag_f.c \
vsip_cvmul_f.c \
vsip_cvneg_f.c \
vsip_cvsub_f.c \
vsip_rcvmul_f.c \
vsip_rscvmul_f.c \
vsip_vcmagsq_f.c \
vsip_vcmplx_f.c \
vsip_vimag_f.c \
vsip_vreal_f.c
OBJECTS= vsip_csvmul_f.o \
vsip_cvadd_f.o \
vsip_cvconj_f.o \
vsip_cvdot_f.o \
vsip_cvjdot_f.o \
vsip_cvjmul_f.o \
vsip_cvmag_f.o \
vsip_cvmul_f.o \
vsip_cvneg_f.o \
vsip_cvsub_f.o \
vsip_rcvmul_f.o \
vsip_rscvmul_f.o \
vsip_vcmagsq_f.o \
vsip_vcmplx_f.o \
vsip_vimag_f.o \
vsip_vreal_f.o

$(ARCHIVE):		$(OBJECTS)
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

obj:	$(OBJECTS)


arch:
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

$(OBJECTS):	$(SOURCES)
	$(COMPILE) $(INCLUDE) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)
