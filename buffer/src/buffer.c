/**
 * @file buffer.c
 * @author Zack Cogswell
 * @brief Takes numbers and creates a buffer file with them.
 */

#include <stdio.h> //for printf
#include <unistd.h> //for usleep and access
#include <string.h> //for strlen

#include "buffer.h"

int fill(buffer *buf, int size, int delay, int refill){
    FILE *file = fopen(buf->filename, "w");
    fclose(file);
    char tempfile[strlen(buf->filename) + 5];
    sprintf(tempfile, "%s.temp", buf->filename);
    char lockfile[strlen(buf->filename) + 5];
    sprintf(lockfile, "%s.lock", buf->filename);
    char string[size];
    do{
        file = fopen(tempfile, "w");
        fclose(file);
        for(int i = 0; i < buf->size; i += size){
            file = fopen(tempfile, "ab");
            buf->rng(size, string);
            fwrite(string, 1, size, file);
            usleep(delay*1000);
            fclose(file);
        }
        file = fopen(lockfile, "w");
        fclose(file);
        rename(tempfile, buf->filename);
        remove(lockfile);
    }while(refill);
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
    fread(num, size, 1, file);
    fclose(file);
    buf->loc += size;
}
