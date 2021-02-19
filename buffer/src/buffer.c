/**
 * @file buffer.c
 * @author Zack Cogswell
 * @brief Takes numbers and creates a buffer file with them.
 */

#include <stdio.h> //for printf
#include <stdlib.h> //for rand
#include <time.h> //for time
#include <unistd.h> //for usleep and access
#include <string.h> //for strlen

#include "buffer.h"

int fill(buffer *buf, int size, int delay){
    FILE *file = fopen(buf->filename, "w");
    fclose(file);
    char tempfile[strlen(buf->filename) + 5];
    sprintf(tempfile, "%s.temp", buf->filename);
    char lockfile[strlen(buf->filename) + 5];
    sprintf(lockfile, "%s.lock", buf->filename);
    char string[size];
    while(1){
        file = fopen(tempfile, "w");
        fclose(file);
        for(int i = 0; i < buf->size; i++){
            file = fopen(tempfile, "ab");
            buf->func(size, string);
            fwrite(string, 1, size, file);
            usleep(delay*1000);
            fclose(file);
        }
        file = fopen(lockfile, "w");
        fclose(file);
        rename(tempfile, buf->filename);
        remove(lockfile);
    }
    return 0;
}

void getBuff(buffer *buf, int size, char *num){
    char lockfile[strlen(buf->filename) + 5];
    sprintf(lockfile, "%s.lock", buf->filename);
    while(!access(lockfile, F_OK)){
        usleep(1000);
    }
    FILE *file = fopen(buf->filename, "rb");
    fseek(file, buf->loc, SEEK_SET);
    fread(num, 1, size, file);
    fclose(file);
    buf->loc += size;
}

//Testting functions

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
    buffer buf = {1000000, 0, "../bin/buffer.bin", &myrand};
    fill(&buf, 4, delay);
    return 0;
}