#!/bin/bash

gcc -std=c99 -Wall -O3 -o trngsmallcrush_ssl trngsmallcrush_ssl.c -Iinclude -Llib -ltestu01 -lprobdist -lmylib -lm -lcrypto -mrdrnd
