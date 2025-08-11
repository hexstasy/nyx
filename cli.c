#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cli.h"
#include "nyx_err.h"
#include "config.h"

static void display_help();
static void display_version();
static void create_point(int port);
static void conn(int port, const char * addr);
static bool cmp_args(const char * arg, const char * flag);

nyx_err_t distr_args(int argc, const char ** argv) {
    for (int i = 1; i < argc; i++) {
        if (cmp_args(arg, HELP_FLAG)) {
            display_help();
            return NYX_ERR_OK;
        } 

        if (cmp_args(arg, VERSION_FLAG)) {
            display_version();
            return NYX_ERR_OK;
        }
        
    }

    return NYX_ERR_OK;
}

static void display_help() {
    puts("Usage nyxchat [OPTIONS...]");
    puts("Options:");
    puts("      --create-point [PORT] [SID]             Creates a connection point.");
    puts("      --conn [IP_ADDRESS_POINT] [PORT] [SID]  Connects to the connection point.");
    puts("      --help                                  Display this note and exit.");
    puts("      --version                               Display current version and exit.");
}

static void display_version() {
    printf("nyxchat version: %s\n", NYXCHAT_VERSION);
}

static bool cmp_args(const char * arg, const char * flag) {
    if (strcmp(arg, flag) == 0)
        return true;
    return false;
}
