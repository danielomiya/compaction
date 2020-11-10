#include <stdio.h>
#include <string.h>
#include "c_template/hello.h"

const char* hello(const char* name) {
    const char *greeting = "hello, ";
    char* result;

    if (name == NULL) name = "world";

    result = malloc((strlen(name)+strlen(greeting)+1)*sizeof(char));

    strcpy(result, greeting); // result = greeting
    strcat(result, name);     // result += name

    return result;
}
