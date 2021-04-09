#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestU01.h"

#include "buffer.h"

buffer buf;
int iter, size;
unsigned char *subBuf;

unsigned int buffer_generate(void){
    unsigned char *rand;
    if(iter >= size){
        if(buf.loc + size > buf.size) size = buf.size - buf.loc;
        getBuff(&buf, size, subBuf);
        iter = 0;
    }
    rand = subBuf + iter;
    iter += 4;
    return *(unsigned int *)rand;
}

int main(int argc, char **argv){
    char *filename = "../bin/buffer.bin";
    if(argc > 1){
        strncpy(filename, argv[1], 128);
    }
    buf = (buffer){226900000*4, 0, filename, 0};
    iter = size = 1024*1024;
    subBuf = malloc(iter*sizeof(char));

    unif01_Gen* gen = unif01_CreateExternGenBits("Buffered RNG", buffer_generate);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGenBits(gen);
    free(subBuf);
    return 0;
}