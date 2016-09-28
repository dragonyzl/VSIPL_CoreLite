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

addEx:	addEx.c
	$(COMPILEP) -o addEx addEx.c $(librariesP)

development:	addEx.c
	$(COMPILED) -o addEx addEx.c $(librariesD)

clean:
	rm -f addEx *.exe
