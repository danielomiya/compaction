#include <stdio.h>
#include "c_template/hello.h"

int main(int argc, char **argv) {
    const char *name = "user";
    const char *greet = hello(name);

    printf("%s\n", greet);

    return 0;
}
