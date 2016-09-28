## Created R Judd 
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

sinEx:	sinEx.c
	$(COMPILE) -o sinEx sinEx.c $(libraries)

development:	sinEx.c
	$(COMPILED) -o sinEx sinEx.c $(librariesD)

clean:
	rm -f sinEx *.exe

