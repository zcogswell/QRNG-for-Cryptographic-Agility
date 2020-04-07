/**
 * @file noRand.c
 * @author Zack Cogswell
 * @brief Example testing program for writing random generators and implementing into OpenSSL
 * @version 0.1
 */

#include <stdio.h> //for printf
#include <string.h> //for memset

#include <openssl/rand.h>

/**
 * @brief New random function
 * 
 * @param buf buffer to place random bytes into
 * @param num number of random bytes to generate
 * @return int status code, 1 = success, 0 = failure
 */
int fake_rand(unsigned char *buf, int num){
    memset(buf, 0, num);
    return 1;
}

/**
 * @brief Generates 16 random bytes using the default PRNG and then with the new function.
 * 
 * @return int exit code, 0 = success
 */
int main(){
    unsigned char rand[16];
    RAND_bytes(rand, sizeof(rand)); //default RAND
    for(unsigned long i = 0; i < sizeof(rand); i++){
        printf("%hhu ", rand[i]);
    }
    printf("\n");

    /////CHANGE NAME/////
    RAND_METHOD noRand = {.bytes = fake_rand};
    RAND_set_rand_method(&noRand);

    RAND_bytes(rand, sizeof(rand)); //fake RAND
    for(unsigned long i = 0; i < sizeof(rand); i++){
        printf("%hhu ", rand[i]);
    }
    printf("\n");
    return 0;
}