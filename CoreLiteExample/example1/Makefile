## Created January 31, 1999 
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

example1:	example1.c
	$(COMPILEP) -o example1 example1.c $(librariesP)

development:	example1.c
	$(COMPILED) -o example1 example1.c $(librariesD)

clean:
	rm -f example1 *.exe
