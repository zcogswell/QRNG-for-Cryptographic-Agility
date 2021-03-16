#include <stdio.h>
#include <string.h>
#include "TestU01.h"

#include "buffer.h"

buffer buf;

unsigned int buffer_generate(void){
    unsigned char rand[4];
    getBuff(&buf, 4, rand);
    return *(unsigned int *)rand;
}

int main(int argc, char **argv){
    char filename[128] = "../bin/buffer.bin";
    if(argc > 1){
        strncpy(filename, argv[1], 128);
    }
    buf = (buffer){226900000*4, 0, *filename, 0};
    unsigned char rand[4];
    getBuff(&buf, 4, rand);
    for(int i = 0; i < 4; i++){
        printf("0x%X ", rand[i]);
    }
    printf("\n");
    getBuff(&buf, 4, rand);
    for(int i = 0; i < 4; i++){
        printf("0x%X ", rand[i]);
    }
    printf("\n");
    // printf("%x\n", rand);

    // unif01_Gen* gen = unif01_CreateExternGenBits("Buffered RNG", buffer_generate);
    // bbattery_SmallCrush(gen);
    // unif01_DeleteExternGenBits(gen);
    return 0;
}