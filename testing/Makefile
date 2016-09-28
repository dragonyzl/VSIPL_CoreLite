CC=gcc
DIR=..
INCLUDE=$(DIR)/include
LIB=$(DIR)/lib

test_cl: test_cl.c *.h
	$(CC) -o test_cl test_cl.c -g -L$(LIB) -I$(INCLUDE) -lvsip_cl -lm

clean:
	rm test_cl
