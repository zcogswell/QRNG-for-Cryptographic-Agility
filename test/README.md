# Test
Examples for modifying OpenSSL, creating OpenSSL Engines, and running TestU01

## Prerequisites
Package `libssl-dev` on Debian systems or equivalent for OpenSSL.

Package `testu01-bin` on Debian systems or equivalent for TestU01

## Execute
Executables make with `make`.

Then the executables can be found in 'bin/'.

testEngine.so is not an executable, but rather the Engine to be called in OpenSSL.

To demonstrate testEngine run `lib/test_testEngine.sh`.