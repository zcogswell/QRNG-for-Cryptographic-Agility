#!/bin/bash
#Makes testEngine.so
gcc -fPIC -o testEngine.o -c testEngine.c
gcc -shared -o testEngine.so -lcrypto testEngine.o
openssl engine -t -c `pwd`/testEngine.so