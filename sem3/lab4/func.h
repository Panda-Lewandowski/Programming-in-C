#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SUCCESS 0
#define NOT_GIVEN_FILE -1
#define NON_EXISTENT_FILE -2
#define NO_DATA -3
#define ALLOC_ERR -4
#define ERR -5
#define MORE INT_MAX
#define LESS INT_MIN
#define EPS 0.00001
//сложение
//умножение
//Вычисление определителя с помощью разложения по строке.
//объединение подходов

//чтение из ФАЙЛА v
//запись в файл v
//сравнение матриц
// Один файл содержит одну матрицу.
//Количество строк и столбцов матрицы указывается в первой строчке файла.

float** allocate_matrix(const int n,const int m);
int fprint_matr(FILE *f, float **mtr, const int n, const int m);
float** fread_matr(FILE* f,int* n, int* m);
float** init_matrix(float** mtr, const int n, const int m);
float** add(float** mtr1, float** mtr2, const int na, const int ma, const int nb, const int mb);
float** multi(float** mtr1, float** mtr2, const int n,
              const int m, const int l, const int k);
void print_matr(float** mtr, const int n, const int m);
float determinant(float** mtr, const int n);
int comp_float(float a, float b);
int comp_matr(float** a, int na, int ma, float** b, int nb, int mb);
float randfrom(int min, int max);
#endif // FUNC_H
