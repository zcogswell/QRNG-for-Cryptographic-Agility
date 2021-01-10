# TRNG
A true random number generator.
Currently using the TRNG found inside modern AMD64 processors.

OpenSSL comes with an RDRAND Engine.

## Prerequisites
Intel or possibly AMD x86_64 processor with the RDRAND instruction.

Package `libtestu01-dev` on Debian systems or equivalent for TestU01

## Usage
`lib/test_trngEngine.sh` demonstrates the built-in TRNG engine that comes with OpenSSL.

`make` will generate binaries that to run TestU01 on the TRNG both in and out of OpenSSL.