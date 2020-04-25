//Geoffrey Kanteles
//Using smallcrush on intel's hardware trng generator
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "TestU01.h"


//Grabs the random we'll be running smallcrush on
unsigned int qrng_generate (void)

{
    FILE* file = fopen ("rand.txt", "r");
    unsigned int output = fscanf(file, "%d");
    usleep (100000);
    return output;
}

int main()
{
    // Create TestU01 TRNG object for our generator
    unif01_Gen* gen = unif01_CreateExternGenBits("QRNG", qrng_generate);

    // Run the tests.
    bbattery_Crush(gen);

    // Clean up.
    unif01_DeleteExternGenBits(gen);

    return 0;
}
