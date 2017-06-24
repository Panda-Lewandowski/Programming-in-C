#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define NOT_GIVEN_FILE -1
#define NON_EXISTENT_FILE -2
#define NO_DATA -3
#define ALLOC_ERR -4
#define ERR -5
#define MORE INT_MAX
#define LESS INT_MIN



int read(FILE *f, int *start, int *end);
int fcount(FILE *f, int *n);
int find(int *start, int *end, int *max);
int filt(int **start, int **end);
int sort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *));
int* del_right(int *elem, int *start);
int* del_left(int *elem, int *end);
int comp_int(const void* p, const void* q);
int comp_char(const void* p,const void* q);
int comp_float(const void* p, const void* q);
int swap(void* p, void* q, size_t size);
int filter(int** start, int** end);
unsigned long long tick(void);
int count(int* start, int* end);
int write(FILE *f, int *start, int *end);
int compare(int* start, int n,int* test, int m);

#endif // FUNC_H

/* Модифицированная сортировка пузырьком I. Запоминайте, где произошел последний
 * обмен элементов, и при следующем проходе алгоритм не заходит за это место.
 * Если последними поменялись i-ый и i+1-ый элементы, то при следующем проходе
 * алгоритм не сравнивает элементы за i-м.
 *
 * v Модифицированная сортировка пузырьком II. Нечетные и четные проходы выполняются
 * в противоположных направлениях: нечетные проходы от начала к концу, четные – от
 * конца массива к его началу. При нечетных проходах большие элементы сдвигаются к
 * концу массива, а при четных проходах – меньшие элементы двигаются к его началу.
 */
