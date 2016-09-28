## RJudd October 11, 1998 
## SPAWARSYSCEN D881 

CC=gcc
INCLUDE=-I../../../../include -I../../../../include/privateCL
DEFINES=-DVSIP_PERFORMANCE_MODE
OPTIONS=-O2 -Wall -ansi -pedantic
AR=ar
AR_OPTIONS=rcvs
ARLIB=libvsip_cl.a
ARCHIVE=../../../../lib/$(ARLIB)
COMPILE=$(CC) $(DEFINES) $(OPTIONS)
SOURCES= vsip_vbind_i.c \
vsip_vdestroy_i.c \
vsip_vgetattrib_i.c \
vsip_vputattrib_i.c
OBJECTS= vsip_vbind_i.o \
vsip_vdestroy_i.o \
vsip_vgetattrib_i.o \
vsip_vputattrib_i.o
$(ARCHIVE):		$(OBJECTS)
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

obj:	$(OBJECTS)

arch:
	$(AR) $(AR_OPTIONS) $(ARCHIVE) $(OBJECTS)

$(OBJECTS):	$(SOURCES)
	$(COMPILE) $(INCLUDE) -c $(SOURCES)

clean:
	rm -f $(OBJECTS)
