#!/bin/bash
#Makes qRand
gcc $(python3-config --cflags) -o qRand qRand.c $(python3-config --libs) -lcrypto
./qRand