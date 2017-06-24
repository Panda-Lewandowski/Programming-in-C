#include <stdio.h>
#include <assert.h>
#ifndef FUNC_H
#define FUNC_H
#define NOT_GIVEN_FILE -1
#define NON_EXISTENT_FILE -2
#define REPLETION -3
#define WRITE_ERROR -4
#define NO_DATA -5
#define MAX_N 10

int read(FILE *f,float a[], int max_n, int *n);
int write(FILE *g, const float b[], const int n);

int average(const float a[], int n, float *av);
int create(float av, float b[], const float a[], int max_n, int *m,const int n);

int compare(const float a[], const float b[], int n);

#endif // FUNC_H
