//Ju Youn Chae
//Ported over from trngsmallcrush
//Using smallcrush on OpenSSl random generator

#include <stdio.h>
#include <string.h>
#include <openssl/rand.h>
#include "TestU01.h"

//Generates the random we'll be running smallcrush on
unsigned int prng_generate (void)

{
    unsigned char buffer[4];
    RAND_bytes(buffer, sizeof(buffer));
    return (buffer);
}

int main()
{
    // Create TestU01 PRNG object for our generator
    unif01_Gen* gen = unif01_CreateExternGenBits("OpenSSL PRNG", prng_generate);

    // Run the tests.
    bbattery_SmallCrush(gen);

    // Clean up.
    unif01_DeleteExternGenBits(gen);
    return 0;
}
