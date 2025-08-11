#include <sodium.h>
#include "cli.h"

int main(int argc, char * argv) {
    if (sodium_init() < 0) {
        fprintf(stderr, "error: failed init libsodium.\n");
        return -1;
    }
    
    proc_err(distr_args(argc, argv));
}
