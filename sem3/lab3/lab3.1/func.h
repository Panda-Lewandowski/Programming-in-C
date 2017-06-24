#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
//#define NDEBUG
#include <assert.h>
char* str_pbrk(char *str, const char *sym);
char *strpbrk_my(const char *s, const char *str);
char *strndup(const char *str, size_t n);
size_t strlen_my (const char *str);
#endif // FUNC_H
