#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "compaction/compaction.h"

#define BUFFER_SIZE 1024
#define STRING_EMPTY ""
#define NUL '\0'

const char *prog(const char *word) {
    int i, count = 1, length = strlen(word);
    char buffer[BUFFER_SIZE], *cursor = buffer;

    for (i = 1; i <= length; i++) {
        if (word[i] == word[i-1] && word[i] != NUL) {
            count++;
            continue;
        }

        if (buffer == cursor) cursor += sprintf(cursor, "%c%d", word[i-1], count);
        else cursor += sprintf(cursor, "-%c%d", word[i-1], count);

        count = 1; // reset count
    }

    length = strlen(buffer); // get length of used space on buffer

    cursor = malloc(sizeof(char)*(length+1));
    strcpy(cursor, buffer);
    // cursor is now an array with only the number
    // of positions necessary for our compacted string

    return cursor;
}

const char *prog2(const char *word) {
    return STRING_EMPTY;
}

const char *desprog(const char *word) {
    return STRING_EMPTY;
}
