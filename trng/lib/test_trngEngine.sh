#!/bin/sh
#Demonstrates rdrand Engine
echo "Normal"
openssl rand -hex 10
echo "Engine"
openssl rand -engine rdrand -hex 10