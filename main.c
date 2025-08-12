#include <sodium.h>
#include "cli.h"
#include "nyx_err.h"
#include "create_point.h"

int main(int argc, char * argv[]) {
    if (sodium_init() < 0) {
        fprintf(stderr, "error: failed init libsodium.\n");
        return -1;
    }
    
    proc_err(create_point("234", "hello"));
    proc_err(distr_args(argc, argv));
}
