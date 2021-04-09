#include <stdio.h>
#include "buffer.h"

int main(){
    char *filename = "../bin/buffer.bin";
    printf("%s\n", filename);
    buffer buf = {1024*4, 0, filename, 0};
    printf("%s\n", buf.filename);
    unsigned char num[4];
    for(int i = 0; i < 4; i++){
        getBuff(&buf, 4, num);
        printf("%ld\n", buf.loc);
        printf("%X\n", *(int *)num);
    }
}