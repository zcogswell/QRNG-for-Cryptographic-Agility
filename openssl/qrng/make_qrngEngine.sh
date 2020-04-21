#!/bin/bash
#Makes qrngEngine.so
gcc -fPIC -o qrngEngine.o -c qrngEngine.c
gcc -shared -o qrngEngine.so -lcrypto qrngEngine.o
openssl engine -t -c `pwd`/qrngEngine.so