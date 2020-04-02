#include <openssl/engine.h>
#include <openssl/rand.h>
#include <string.h>

static const char *engine_id = "testEngine";
static const char *engine_name = "test";

int fake_rand(unsigned char *buf, int num){
    memset(buf, 0, num);
    return 1;
}

static int bind(ENGINE *e, const char *id){
    if(!ENGINE_set_id(e, engine_id)){
        fprintf(stderr, "ENGINE_set_id failed\n");
        return 0;
    }
    if(!ENGINE_set_name(e, engine_name)){
        fprintf(stderr, "ENGINE_set_name failed\n");
        return 0;
    }
    return 1;
}

IMPLEMENT_DYNAMIC_BIND_FN(bind);
IMPLEMENT_DYNAMIC_CHECK_FN();
RAND_METHOD noRand = {.bytes = fake_rand};
RAND_set_rand_method(&noRand);