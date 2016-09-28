## Created RJudd January 31, 1999 
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

histoExP:	histoEx.c
	$(COMPILEP) -o histoEx histoEx.c $(librariesP)

development:	histoEx.c
	$(COMPILED) -o histoEx histoEx.c $(librariesD)

clean:
	rm -f histoEx *.exe
