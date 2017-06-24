#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#define NOT_GIVEN_FILE -1
#define NON_EXISTENT_FILE -2
#define NO_DATA -3
#define ALLOC_ERR -4
#define ERR -5
//чтение кол-ва чисел. в массив обработка
int read(FILE *f, int *start, int *end);
int count(FILE *f, int *n);
int find(int *start, int *end, int *max);
#endif // FUNC_H
