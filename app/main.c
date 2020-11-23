#include <stdio.h>
#include <string.h>
#include "compaction/compaction.h"
#include "compaction/helpers.h"

#define HELP_COMMAND "help"
#define PROG_COMMAND "prog"
#define PROG2_COMMAND "prog2"
#define DESPROG_COMMAND "desprog"

int main(int argc, char** argv) {
    const char *command, *input, *output, *executable = argv[0];

    if ((argc < 3) || (argc > 1 && strcmp(argv[1], HELP_COMMAND) == 0)) {
        print_usage(executable);
        return 0;
    }

    command = argv[1], input = argv[2];

    if (str_eq(command, PROG_COMMAND))
        output = prog(input);
    else if (str_eq(command, PROG2_COMMAND))
        output = prog2(input);
    else if (str_eq(command, DESPROG_COMMAND))
        output = desprog(input);
    else
        output = not_found(executable);

    printf("%s\n", output);
    return 0;
}
