#!/bin/bash

gcc -std=c99 -Wall -O3 -o trngsmallcrush trngsmallcrush.c -Iinclude -Llib -ltestu01 -lprobdist -lmylib -lm -mrdrnd
