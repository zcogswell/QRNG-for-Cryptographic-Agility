/**
 * @file qRand.c
 * @author Zack Cogswell, Goeffrey Kanteles
 * @brief Example program for writing random generators and implementing into OpenSSL
 * @version 0.1
 */


#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <stdio.h> //for printf
#include <string.h> //for memset
#include <stdlib.h>
#include <unistd.h>

#include <openssl/rand.h>




/**
 * @brief Quantum random function, calls IBM Qisket from a Python script.
 * 
 * @param buf buffer to place random bytes into
 * @param num number of random bytes to generate
 * @return int status code, 1 = success, 0 = failure
 */
int q_rand(unsigned char *buf, int num){
    int rand = 0;
    char output[num];
    FILE *fptr;
    for(int i = 0; i < num/4; i++){
        fptr = fopen("rand.txt", "r");
        fscanf(fptr, "%d", &rand);
        memcpy(output + (i*4), &rand, 4);
        fclose(fptr);
        usleep(100000);
    }
    memcpy(buf, output, num);
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