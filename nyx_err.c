#include <stdio.h>
#include <stdlib.h>
#include "nyx_err.h"

static void must_err(const char * msg);
static void default_err(const char * msg);

void proc_err(enum nyx_err_t code) {
    switch(code) {
        case NYX_ERR_OK:
            return;
        case NYX_ERR_ALLOC:
            must_err("failed allocation memory");
            break;
        case NYX_ERR_INVALID_ARG:
            default_err("invalid argument in func");
            break;
        case NYX_ERR_NULL:
            must_err("value is null");
            break;
        default:
            default_err("undefined error");
            break;
    }
}

static void must_err(const char * msg) {
    fprintf(stderr, "critical error: %s\n", msg);
    exit(-1);
}

static void default_err(const char * msg) {
    fprintf(stderr, "error: %s\n", msg);
}
