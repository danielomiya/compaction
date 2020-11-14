#ifndef HELPERS_H
#define HELPERS_H

void print_usage(const char *executable_name);

const char *not_found(const char *executable_name);

unsigned int str_eq(const char *a, const char *b);

unsigned int str_ne(const char *a, const char *b);

unsigned int is_number(char character);

int scan_number(const char *word, int cursor, int *number);

int scan_string(const char *word, int cursor, char *string);

#endif // HELPERS_H
