## Created RJudd 
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

example8:	example8.c
	$(COMPILEP) -o example8 example8.c $(librariesP)

development:	example8.c
	$(COMPILED) -o example8 example8.c $(librariesD)

clean:
	rm -f example8 *.exe
