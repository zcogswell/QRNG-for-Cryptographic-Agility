#!/bin/bash
#Demonstrates testEngine.so
echo "Normal"
openssl rand -hex 10
echo "Engine"
cd $(dirname "${BASH_SOURCE[0]}")
openssl rand -engine ../bin/testEngine.so -hex 10