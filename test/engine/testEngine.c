/**
 * @file testEngine.c
 * @author Zack Cogswell
 * @brief Example OpenSSL Engine implementation for changing the RAND function.
 * @version 0.2
 */

#include <stdio.h> //for fprintf
#include <string.h> //for memset

#include <openssl/engine.h>

/////REMOVE FOR IMPLEMENTATION/////
#include "../noRand/noRand.h"

/////CHANGE NAME FOR IMPLEMENTATION/////
static const char *engine_id = "testEngine";
static const char *engine_name = "test";

//RAND_METHOD structure
static const RAND_METHOD noRand = {.bytes = fake_rand}; /////CHANGE NAME/////

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
    if(!ENGINE_set_RAND(e, &noRand)){ /////CHANGE NAME/////
        fprintf(stderr, "ENGINE_set_RAND failed\n");
        return 0;
    }
    return 1;
}

//OpenSSL Engine initialization
IMPLEMENT_DYNAMIC_BIND_FN(bind);
IMPLEMENT_DYNAMIC_CHECK_FN();
