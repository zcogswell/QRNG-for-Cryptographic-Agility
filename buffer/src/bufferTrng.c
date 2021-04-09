#include <stdio.h>

#include "buffer.h"

void trng_generate(int size, char *string){
    unsigned int rand;
    for(int i = 0; i < size; i += sizeof(rand)){
        if(__builtin_ia32_rdrand32_step(&rand)){
            for(int j = 0; j < sizeof(rand) && i+j < size; j++){
                string[i+j] = (char)(rand % 0x100);
                rand >>= 8;
            }
        }
        else{
            printf("Failed to get a random value");
            break;
        }
    }
    
}

int main(){
    buffer trng = {1000000000, 0, "../bin/buffer.bin", &trng_generate};
    fill(&trng, 1024*1024, 0, 0);
    return 0;
}