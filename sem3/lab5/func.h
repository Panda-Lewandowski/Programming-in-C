#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DECIMAL_NUMBER_LENGTH 9
#define MAX_OCTAL_NUMBER_LENGTH 12

int my_snprintf(char *s, size_t n, const char *format, ... );
char* d_to_o(unsigned int number);
size_t strlength(const char *str);
char*  string_cat(char *s1, const char *s2);
#endif // FUNC_H
