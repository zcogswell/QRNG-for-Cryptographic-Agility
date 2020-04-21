#!/bin/bash
#Demonstrates qrngEngine.so
echo "Normal"
openssl rand -hex 10
echo "Engine"
openssl rand -engine `pwd`/qrngEngine.so -hex 10