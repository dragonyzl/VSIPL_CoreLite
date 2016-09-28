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
SOURCES= vsip_cvcopy_f_f.c \
vsip_vcopy_f_f.c \
vsip_vcopy_f_i.c \
vsip_vcopy_i_f.c
OBJECTS= vsip_cvcopy_f_f.o \
vsip_vcopy_f_f.o \
vsip_vcopy_f_i.o \
vsip_vcopy_i_f.o


$(ARCHIVE):		$(OBJECTS)
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

obj:	$(OBJECTS)


arch:
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

$(OBJECTS):	$(SOURCES)
	$(COMPILE) $(INCLUDE) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)
