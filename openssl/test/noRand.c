#include <openssl/rand.h>
#include <stdio.h>
#include <string.h>

int fake_rand(unsigned char *buf, int num){
    memset(buf, 0, num);
    return 1;
}

int main(){
    unsigned char rand[16];
    RAND_bytes(rand, sizeof(rand)); //default RAND
    for(unsigned long i = 0; i < sizeof(rand); i++){
        printf("%hhu ", rand[i]);
    }
    printf("\n");

    RAND_METHOD noRand = {.bytes = fake_rand};
    RAND_set_rand_method(&noRand);
    RAND_bytes(rand, sizeof(rand)); //fake RAND
    for(unsigned long i = 0; i < sizeof(rand); i++){
        printf("%hhu ", rand[i]);
    }
    printf("\n");
    return 0;
}