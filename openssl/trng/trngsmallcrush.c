//Ju Youn Chae
//Using smallcrush on intel's hardware trng generator
#include <stdio.h>
#include <limits.h>
#include "TestU01.h"


//Generates the random we'll be running smallcrush on
unsigned int trng_generate (void)
{
    float min = -100.001;
    float max = 100.001;
    float *randf;
    unsigned long long rand64;
    if ( __builtin_ia32_rdrand64_step(&rand64) ) {
        *randf= (float)rand64/ULONG_MAX*(max - min) + min;
        return (*randf);
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
