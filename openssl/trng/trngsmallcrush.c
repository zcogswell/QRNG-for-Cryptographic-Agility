//Ju Youn Chae
//Using smallcrush on intel's hardware trng generator
#include <stdio.h>
#include <limits.h>
#include "TestU01.h"


//Generates the random we'll be running smallcrush on
unsigned int trng_generate (void)
{
    unsigned int randf;
    if ( __builtin_ia32_rdrand32_step(&rand) ) {
        return rand;
    }
    else printf("Failed to get a random value");
    return 0;
}

int main()
{
    // Create TestU01 TRNG object for our generator
    unif01_Gen* gen = unif01_CreateExternGenBits("Intel TRNG", trng_generate);

    // Run the tests.
    bbattery_Crush(gen);

    // Clean up.
    unif01_DeleteExternGenBits(gen);

    return 0;
}
