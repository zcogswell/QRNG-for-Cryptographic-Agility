/**
 * @file prngSmallCrush.c
 * @author Ju Youn Chae, Zack Cogswell
 * @brief Using SmallCrush on Intel x86_64 TRNG
 */
#include <stdio.h>
#include <limits.h>
#include "TestU01.h"


/**
 * @brief Calls integrated thermal RNG
 * 
 * @return int 32-bit random number
 */
unsigned int trng_generate(void){
    unsigned int rand;
    if( __builtin_ia32_rdrand32_step(&rand)){
        return rand;
    }
    else printf("Failed to get a random value");
    return 0;
}

/**
 * @brief Performs SmallCrush on Intel TRNG
 * 
 * @return int 0 upon success
 */
int main(){
    // Create TestU01 TRNG object for our generator
    unif01_Gen* gen = unif01_CreateExternGenBits("Intel TRNG", trng_generate);

    // Run the tests.
    bbattery_SmallCrush(gen);

    // Clean up.
    unif01_DeleteExternGenBits(gen);

    return 0;
}
