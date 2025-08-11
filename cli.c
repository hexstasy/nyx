#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cli.h"
#include "nyx_err.h"
#include "config.h"
#include "flags.h"


static inline void display_help();
static inline void display_version();
static enum nyx_err_t create_point(const char * port, const char * sid);
static enum nyx_err_t conn(const char * port, const char * addr, const char * sid);
static bool cmp_args(const char * arg, const char * flag);

enum nyx_err_t distr_args(int argc, char ** argv) {
    for (int i = 1; i < argc; i++) {
        if (cmp_args(argv[i], HELP_FLAG)) {
            display_help();
            return NYX_ERR_OK;
        } 

        if (cmp_args(argv[i], VERSION_FLAG)) {
            display_version();
            return NYX_ERR_OK;
        }
        
        if (cmp_args(argv[i], CONN_FLAG) && (i+3) == argc)
            return conn(argv[i+1], argv[i+2], argv[i+3]);
    }

    return NYX_ERR_OK;
}

static inline void display_help() {
    puts("Usage nyx [OPTIONS...]");
    puts("Options:");
    puts("      --create-point [PORT] [SID]             Creates a connection point.");
    puts("      --conn [IP_ADDRESS_POINT] [PORT] [SID]  Connects to the connection point.");
    puts("      --help                                  Display this note and exit.");
    puts("      --version                               Display current version and exit.");
}

static inline void display_version() {
    printf("nyx version: %s\n", NYX_VERSION);
}

static bool cmp_args(const char * arg, const char * flag) {
    if (strcmp(arg, flag) == 0)
        return true;
    return false;
}

static enum nyx_err_t create_point(const char * port, const char * sid) {}
static enum nyx_err_t conn(const char * port, const char * addr, const char * sid) {}