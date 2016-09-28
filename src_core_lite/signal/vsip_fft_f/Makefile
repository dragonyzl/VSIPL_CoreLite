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
SOURCES= vsip_fft_destroy_f.c \
vsip_ccfftop_create_f.c \
vsip_ccfftop_f.c \
vsip_rcfftop_create_f.c \
vsip_rcfftop_f.c \
vsip_crfftop_create_f.c \
vsip_crfftop_f.c
OBJECTS= vsip_fft_destroy_f.o \
vsip_ccfftop_create_f.o \
vsip_ccfftop_f.o \
vsip_rcfftop_create_f.o \
vsip_rcfftop_f.o \
vsip_crfftop_create_f.o \
vsip_crfftop_f.o 

$(ARCHIVE):		$(OBJECTS)
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

obj:	$(OBJECTS)

arch:
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

$(OBJECTS):	$(SOURCES)
	$(COMPILE) $(INCLUDE) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)
