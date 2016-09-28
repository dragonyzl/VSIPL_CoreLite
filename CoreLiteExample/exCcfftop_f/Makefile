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

all: ccfftopExP ccfftopExVSIPP

development: ccfftopExD ccfftopExVSIPD

ccfftopExP:	ccfftopEx.c
	$(COMPILEP) -o ccfftopEx ccfftopEx.c $(librariesP)

ccfftopExD:	ccfftopEx.c
	$(COMPILED) -o ccfftopEx ccfftopEx.c $(librariesD)

ccfftopExVSIPP:	ccfftopExVSIP.c
	$(COMPILEP) -o ccfftopExVSIP ccfftopExVSIP.c $(librariesP)

ccfftopExVSIPD:	ccfftopExVSIP.c
	$(COMPILED) -o ccfftopExVSIP ccfftopExVSIP.c $(librariesD)

clean:
	rm -f ccfftopEx ccfftopExVSIP *.exe
