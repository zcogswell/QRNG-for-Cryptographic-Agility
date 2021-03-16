#include <stdio.h>
#include <stdlib.h> //for rand
#include <time.h>

#include "buffer.h"

/**
 * @brief Creates string filled with letters in alphabetic order according to size
 */
void alpha(int size, char *string){
    for(int i = 0; i < size; i++){
        string[i] = '\x41' + i;
    }
}

/**
 * @brief Creates string of random bytes
 */
void myrand(int size, char *string){
    int irand;
    for(int i = 0; i < size; i += sizeof(int)){
        irand = rand();
        for(int j = 0; j < sizeof(int) && i+j < size; j++){
            string[i+j] = (char)(irand % 0x100);
            irand >>= 8;
        }
    }
}


/**
 * @brief Runs fill function
 * 
 * @param argv[1] delay (ms)
 * @return int 0 on success
 */
int main(int argc, char **argv){
    srand(time(NULL));
    int delay = 0;
    if(argc > 1){
        delay = atoi(argv[1]);
    }
    buffer buf = {1000*4, 0, "../bin/buffer.bin", &myrand};
    fill(&buf, 4, delay, 0);
    return 0;
}
