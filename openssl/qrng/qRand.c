/**
 * @file qRand.c
 * @author Zack Cogswell, Goeffrey Kanteles
 * @brief Example program for writing random generators and implementing into OpenSSL
 * @version 0.1
 */

#include <stdio.h> //for printf
#include <string.h> //for memset
#include <unistd.h> //for usleep

#include <openssl/rand.h>

/**
 * @brief Quantum random function, calls IBM Qisket from a Python script.
 * 
 * @param buf buffer to place random bytes into
 * @param num number of random bytes to generate
 * @return int status code, 1 = success, 0 = failure
 */
int q_rand(unsigned char *buf, int num){
    char rand[4];
    FILE *fptr;
    for(int i = 0; i < num; i+=4){
        fptr = fopen("rand.txt", "rb");
        fread(rand, sizeof(rand), 1, fptr);
        memcpy(buf + i, rand, (num - i) < 4 ? (num - i) : 4);
        fclose(fptr);
        usleep(100000);
    }
    return 0;
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
    RAND_METHOD noRand = {.bytes = q_rand};
    RAND_set_rand_method(&noRand);

    RAND_bytes(rand, sizeof(rand)); //fake RAND
    for(unsigned long i = 0; i < sizeof(rand); i++){
        printf("%hhu ", rand[i]);
    }
    printf("\n");
    return 0;
}