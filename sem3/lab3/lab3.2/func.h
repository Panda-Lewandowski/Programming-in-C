#ifndef __FUNC_H__
#define __FUNC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFSIZE 5 //размер буфера
#define NOT_GIVEN_FILE -1
#define NON_EXISTENT_FILE -2
#define NO_DATA -3

char* get_line(FILE* f);

char* replace_line(char* str, const char* from, const char* to);

char* strstr_my(char *haystack, const char *needle);

size_t strlength(const char *str);

char*  string_cat(char *s1, const char *s2);

char*  string_n_cat(char *s1, const char *s2, size_t n);
#endif
