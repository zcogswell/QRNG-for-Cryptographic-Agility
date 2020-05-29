#!/bin/bash

gcc -std=c99 -Wall -O3 -o prngsmallcrush prngsmallcrush.c -Iinclude -Llib -ltestu01 -lprobdist -lmylib -lm -lcrypto
