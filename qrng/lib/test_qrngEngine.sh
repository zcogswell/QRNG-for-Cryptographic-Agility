#!/bin/sh
#Demonstrates qrngEngine.so
echo "Normal"
openssl rand -hex 10
echo "Engine"
cd $(dirname "${BASH_SOURCE[0]}")
openssl rand -engine ../bin/qrngEngine.so -hex 10