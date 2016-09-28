## Created RJudd to make add example for Core Lite, October 11, 1998 
## SPAWARSYSCEN D881

CC=gcc
INCLUDE=-I../../include
DEFINEP=-DVSIP_PERFORMANCE_MODE
DEFINED=-DVSIP_DEVELOPMENT_MODE
OPTIONS=-O2 -Wall -ansi -pedantic
LIBRARY=-L../../lib
librariesP=-lvsip_cl -lm
librariesD=-lDvsip_cl -lm
COMPILEP=$(CC) $(INCLUDE) $(LIBRARY) $(DEFINEP) $(OPTIONS)
COMPILED=$(CC) $(INCLUDE) $(LIBRARY) $(DEFINED) $(OPTIONS)
COMPILE=$(CC) $(INCLUDE) $(OPTIONS)
SOURCES= VU_cvprint_f.c \
VU_vprint_f.c
OBJECTS= VU_cvprint_f.o \
VU_vprint_f.o
MAIN=eulerEx

eulerEx:	$(MAIN).c $(OBJECTS)
	$(COMPILEP) -o $(MAIN) $(MAIN).c $(OBJECTS) $(librariesP)

development:	$(MAIN).c $(OBJECTS)
	$(COMPILED) -o $(MAIN) $(MAIN).c $(OBJECTS) $(librariesD)

$(OBJECTS):	$(SOURCES)
	$(COMPILE) -c $(SOURCES)

clean:
	rm $(OBJECTS) $(MAIN)
