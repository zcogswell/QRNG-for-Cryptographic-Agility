//Ju Youn Chae, Geoffrey Kanteles, Zack Cogswell
//Using smallcrush on intel's hardware trng generator
#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#include "TestU01.h"


//Grabs the random we'll be running smallcrush on
unsigned int qrng_generate(void){
    unsigned int output;
    /*while(access("../../qrng/qiskit/rand.txt.lock", F_OK) != -1){
        printf("file locked\n");
        usleep(100000);
    }*/
    FILE* file = fopen ("../../qrng/qiskit/rand.bin", "r");
    fread(&output, sizeof(output), 1, file);
    fclose(file);
    /*if(count != 1 || status != 0){
        fprintf(stderr, "Reading failure.");
        return 0;
    }*/
    usleep(100000);
    return output;
}

int main(){    
    //for(int i = 0; i < 10; i++) printf("%u\n", qrng_generate());
    // Create TestU01 TRNG object for our generator
    unif01_Gen* gen = unif01_CreateExternGenBits("QRNG", qrng_generate);

    // Run the tests.
    bbattery_Crush(gen);

    // Clean up.
    unif01_DeleteExternGenBits(gen);

    return 0;
}
