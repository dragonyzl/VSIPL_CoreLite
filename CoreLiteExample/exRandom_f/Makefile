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

randomExP:	randomEx.c
	$(COMPILEP) -o randomEx randomEx.c $(librariesP)

development:	randomEx.c
	$(COMPILED) -o randomEx randomEx.c $(librariesD)

clean:
	rm -f randomEx *.exe
