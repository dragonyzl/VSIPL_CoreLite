## created by RJudd for Core Lite
## SPAWARSYSCEN D881 
## October 11, 1998

CC=gcc
INCLUDE=-I../../../../../include -I../../../../../include/privateCL
DEFINES=-DVSIP_DEVELOPMENT_MODE
OPTIONS=-O2 -Wall -ansi -pedantic
AR=ar
AR_OPTIONS=rcvs
ARLIB=libDvsip_cl.a
ARCHIVE=../../../../../lib/$(ARLIB)
COMPILE=$(CC) $(DEFINES) $(OPTIONS)
SOURCES= vsip_vcheck_clobber_i.c \
vsip_vcheck_lengths_i.c \
vsip_vcheck_outside_i.c \
vsip_vcheck_valid_i.c
OBJECTS= vsip_vcheck_clobber_i.o \
vsip_vcheck_lengths_i.o \
vsip_vcheck_outside_i.o \
vsip_vcheck_valid_i.o

$(ARCHIVE):	$(OBJECTS)
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

obj:	$(OBJECTS)

arch:
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

$(OBJECTS):	$(SOURCES)
	$(COMPILE) $(INCLUDE) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)

