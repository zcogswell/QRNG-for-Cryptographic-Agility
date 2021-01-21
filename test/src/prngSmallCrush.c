/**
 * @file prngSmallCrush.c
 * @author Ju Youn Chae, Zack Cogswell
 * @brief Using SmallCrush on OpenSSl random generator
 */

#include <stdio.h>
#include <string.h>
#include <openssl/rand.h>
#include "TestU01.h"

/**
 * @brief Calls OpenSSL PRNG and returns a rand.
 * 
 * @return int 32-bit random number
 */
unsigned int prng_generate(void){
    unsigned char buffer[4];
    RAND_bytes(buffer, sizeof(buffer));
    return *(unsigned int *)buffer;
}

/**
 * @brief Performs SmallCrush on OpenSSL PRNG
 * 
 * @return int 0 upon success
 */
int main(){
    // Create TestU01 PRNG object for our generator
    unif01_Gen* gen = unif01_CreateExternGenBits("OpenSSL PRNG", prng_generate);

    // Run the tests.
    bbattery_SmallCrush(gen);
    //bbattery_Crush(gen);

    // Clean up.
    unif01_DeleteExternGenBits(gen);
    return 0;
}
