/**
 * @file qrngEngine.c
 * @author Zack Cogswell
 * @brief OpenSSL Engine implementation for changing the RAND function to quantum simulator.
 * @version 0.2
 */

#include <stdio.h> //for fprintf
#include <string.h> //for memcpy
#include <unistd.h> //for usleep

#include <openssl/engine.h>

//#include "qRand.h" /////Doesn't appear to work despite compiling properly/////

static const char *engine_id = "qrngEngine";
static const char *engine_name = "QRNG";

/**
 * @brief New random function
 * 
 * @param buf buffer to place random bytes into
 * @param num number of random bytes to generate
 * @return int status code, 1 = success, 0 = failure
 */
int q_rand(unsigned char *buf, int num){
    char rand[4];
    FILE *fptr;
    for(int i = 0; i < num; i+=4){
        fptr = fopen("rand.bin", "rb");
        fread(rand, sizeof(rand), 1, fptr);
        fclose(fptr);
        memcpy(buf + i, rand, (num - i) < 4 ? (num - i) : 4);
        usleep(100000);
    }
    return 1;
}

static const RAND_METHOD qRand = {.bytes = q_rand};

/**
 * @brief Required function to create OpenSSL Engine.
 *
 * @return int status code, 1 = success, 0 = failure
 */
static int bind(ENGINE *e, const char *id){
    if(!ENGINE_set_id(e, engine_id)){
        fprintf(stderr, "ENGINE_set_id failed\n");
        return 0;
    }
    if(!ENGINE_set_name(e, engine_name)){
        fprintf(stderr, "ENGINE_set_name failed\n");
        return 0;
    }
    if(!ENGINE_set_RAND(e, &qRand)){
        fprintf(stderr, "ENGINE_set_RAND failed\n");
        return 0;
    }
    return 1;
}

//OpenSSL Engine initialization
IMPLEMENT_DYNAMIC_BIND_FN(bind);
IMPLEMENT_DYNAMIC_CHECK_FN();