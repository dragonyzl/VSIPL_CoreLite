## Created RJudd
## SPAWARSYSCEN D881

CC=gcc
INCLUDE=-I../../include
DEFINES=-DVSIP_PERFORMANCE_MODE
OPTIONS=-O2 -Wall -ansi -pedantic
LIBRARY=-L../../lib
libraries=-lvsip_cl -lm
COMPILE=$(CC) $(INCLUDE) $(LIBRARY) $(DEFINES) $(OPTIONS)
librariesD=-lDvsip_cl -lm
DEFINED=-DVSIP_DEVELOPMENT_MODE
COMPILED=$(CC) $(INCLUDE) $(LIBRARY) $(DEFINED) $(OPTIONS)

divEx:	divEx.c
	$(COMPILE) -o divEx divEx.c $(libraries)

development:	divEx.c
	$(COMPILED) -o divEx divEx.c $(librariesD)

clean:
	rm -f divEx *.exe

