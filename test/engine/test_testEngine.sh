#!/bin/bash
#Demonstrates testEngine.so
echo "Normal"
openssl rand -hex 10
echo "Engine"
openssl rand -engine `pwd`/testEngine.so -hex 10