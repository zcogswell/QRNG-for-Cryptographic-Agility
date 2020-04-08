PACKAGE_NAME=libdrng
PACKAGE_VERSION=1.0
CC=gcc
CFLAGS=-g -O2 -O2
AR=ar


TEST_OBJ=main.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: bin lib 

bin: test

lib: libdrng.a

libdrng.a: rdrand.o rdseed.o 
	$(AR) rcs $@ $?

test: $(TEST_OBJ) libdrng.a
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ) -L. -ldrng

clean:
	rm -f *.o libdrng.a test
	
distclean: clean
	rm -f Makefile config.guess config.status config.log config.h
	rm -r -f autom4te.cache

