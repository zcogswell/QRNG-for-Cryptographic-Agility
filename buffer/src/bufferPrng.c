#include <stdio.h>
#include <openssl/rand.h>
#include "buffer.h"

void prng_generate(int size, char *string){
    RAND_bytes(string, size);
}

int main(){
    buffer prng = {1000000000, 0, "../bin/buffer.bin", &prng_generate};
    fill(&prng, 1024*1024, 0, 0);
    return 0;
}