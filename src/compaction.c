#include "compaction/compaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compaction/helpers.h"

#define BUFFER_SIZE 1024
#define STRING_EMPTY ""
#define NUL '\0'

const char* prog(const char* word) {
    int i, count = 1, length = strlen(word);
    char buffer[BUFFER_SIZE], *cursor = buffer;

    for (i = 1; i <= length; i++) {
        // if current character equals last and not end of string
        // it only increments count
        if (word[i] == word[i - 1] && word[i] != NUL) {
            count++;
            continue;
        }

        // if buffer == cursor, nothing has been written to buffer
        // therefore appending '-' is not necessary
        if (buffer == cursor)
            cursor += sprintf(cursor, "%c%d", word[i - 1], count);
        else
            cursor += sprintf(cursor, "-%c%d", word[i - 1], count);

        count = 1;  // reset count
    }

    length = strlen(buffer);  // get length of used space on buffer

    cursor = malloc(sizeof(char) * (length + 1));
    strcpy(cursor, buffer);
    // cursor is now an array with only the number
    // of positions necessary for our compacted string

    // edit: reusing 'cursor' name for other purposes was a
    // lasy way to not allocate more memory for a new pointer
    return cursor;
}

const char* prog2(const char* word) {
    char *result, temp[32], buffer[BUFFER_SIZE], *cursor = buffer;
    int count, pattern_length, start_pattern = 0, end_pattern = -1, i = 1;

    while (1) {
        if (end_pattern == -1 && word[i] == word[start_pattern]) {
            end_pattern = i;

            pattern_length = end_pattern - start_pattern;
            count = 1;

            while (substr_eq(word, word, start_pattern, i, pattern_length)) {
                count++;
                i += pattern_length;
            }

            str_slice(word, start_pattern, pattern_length, temp);

            if (buffer == cursor)
                cursor += sprintf(cursor, "%s%d", temp, count);
            else
                cursor += sprintf(cursor, "-%s%d", temp, count);

            start_pattern = start_pattern + pattern_length * count;
            end_pattern = -1;
        }

        if (word[i] == NUL)
            break;

        i++;
    }

    result = malloc(sizeof(char) * (strlen(buffer) + 1));
    strcpy(result, buffer);

    return result;
}

const char* desprog(const char* word) {
    char buffer[BUFFER_SIZE], pattern[32], *result;
    int cursor = 0, count, i;
    unsigned int has_written = 0;

    // while we don't reach end of string
    while (word[cursor] != NUL) {
        // read a string and a number
        cursor = scan_string(word, cursor, pattern);
        cursor = scan_number(word, cursor, &count);

        for (i = 0; i < count; i++) {
            if (has_written) {  // if anything has been written, only
                                // concatenate
                strcat(buffer, pattern);
                continue;
            }

            // otherwise replaces contents of buffer
            strcpy(buffer, pattern);
            has_written = 1;
        }
    }

    // alloc only needed memory and copy output to 'result'
    result = malloc(sizeof(char) * (1 + strlen(buffer)));
    strcpy(result, buffer);

    return result;
}
