//Ju Youn Chae
//Using smallcrush on intel's hardware trng generator
#include <stdio.h>
#include <limits.h>
#include <openssl/rand.h>
#include "TestU01.h"

unsigned int rdrand_gen(){
    unsigned int rand;
    if(__builtin_ia32_rdrand32_step(&rand)){
        return rand;
    }
    fprintf(stderr, "Failed to get a random value");
    return 0;
}

unsigned int trng_rand(unsigned char *buf, int num){
    unsigned int rand;
    for(int i = 0; i < num;  i += 4){
        for(int j = 0; (j < 4) && ((i + j) < num); j++){
            rand = rdrand_gen();
            buf[i+j] = (rand >> (j*4)) & 0xFF;
        }
    }
    return 0;
}

unsigned int trng_generate(void){
    unsigned char buffer[4];
    RAND_bytes(buffer, sizeof(buffer));
    unsigned int output = buffer[0] << 24;
    output += buffer[1] << 16;
    output += buffer[2] << 8;
    output += buffer[3];
    return output;
}

int main()
{
    RAND_METHOD trng = {.bytes = trng_rand};
    RAND_set_rand_method(&trng);
    // Create TestU01 TRNG object for our generator
    unif01_Gen* gen = unif01_CreateExternGenBits("Intel TRNG via OpenSSL", trng_generate);

    // Run the tests.
    bbattery_SmallCrush(gen);

    // Clean up.
    unif01_DeleteExternGenBits(gen);

    return 0;

}
