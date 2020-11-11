#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compaction/helpers.h"

void print_usage(const char* executable_name) {
    printf("Usage: %s [command] [input?]\n\n", executable_name);
    printf("Commands:\n");
    printf("prog: compacts sequences of repeated chars\n");
    printf("prog2: compacts sequences of repeated patterns\n");
    printf("desprog: uncompacts any of the above compaction\n");
    printf("help: shows this message\n");
}

const char *not_found(const char *executable_name) {
    const char *format = "Command not found, try using '%s help'";

    // -1 is because we subtract '%s' (-2) and add \0 (+1)
    int alloc_length = strlen(format) + strlen(executable_name) - 1;

    char *result = malloc(sizeof(char)*alloc_length);

    sprintf(result, format, executable_name);

    return result;
}

unsigned int str_eq(const char *a, const char *b) {
    return strcmp(a, b) == 0;
}

unsigned int str_ne(const char *a, const char *b) {
    return !str_eq(a, b);
}
