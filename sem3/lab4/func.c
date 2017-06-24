#include "func.h"
///
/// \brief allocate_matrix выделение памяти под матрицу
/// \param n кол-во строк
/// \param m кол-во столбцов
/// \return матрица
///
float** allocate_matrix(const int n,const int m)
{
    float **data = malloc(n * sizeof(float*) + n * m * sizeof(float));
    if (!data)
        return NULL;

    for(int i = 0; i < n; i++)
        data[i] = (float*)
                 ((char*) data + n * sizeof(float*) + i * m * sizeof(float));

    return data;
}

///
/// \brief init_matrix  заполнение матрицы нулями
/// \param mtr матрица
/// \param n кол-во строк
/// \param m кол-во столбцов
/// \return матрица
///
float** init_matrix(float** mtr, const int n, const int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mtr[i][j] = 0;

    return mtr;
}
///
/// \brief fprint_matr печать матрицы в файл
/// \param f файл
/// \param mtr матрица
/// \param n кол-во строк
/// \param m кол-во столбцов
/// \return код выхода
///
int fprint_matr(FILE* f, float **mtr,const int n,const int m)
{
    if(f)
    {
        fprintf(f, "%d \t %d\n\n", n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                fprintf(f, "%4.2f ", mtr[i][j]);

            fprintf(f, "\n");
        }

        return SUCCESS;
    }

    return ERR;

}
///
/// \brief fread_matr чтение матрицы из файла
/// \param f файл
/// \param mtr матрица
/// \param n кол-во строк
/// \param m кол-во столбцов
/// \return матрица или NULL
///
float** fread_matr(FILE* f,int* n,int* m)
{
    if(f)
    {
        fscanf(f, "%d %d", n, m);
        fscanf(f, "\n");

        float** mtr = allocate_matrix(*n, *m);

        mtr = init_matrix(mtr, *n, *m);
        for (int i = 0; i < *n; i++)
        {
            for (int j = 0; j < *m; j++)
                fscanf(f, "%f", &(mtr[i][j]));


            fscanf(f, "\n");
        }

        return mtr;
    }

    return NULL;

}
///
/// \brief add сложение двух матриц одинаковой размерность
/// \param mtr1 матрица 1
/// \param mtr2 матрица 2
/// \param n кол-во строк
/// \param m кол-во столбцов
/// \return матрица или NULL
///
float** add(float** mtr1, float** mtr2, const int na, const int ma,const int nb, const int mb)
{
    if(na != nb || ma != mb)
        return NULL;

    float **mtr_res = allocate_matrix(na, ma);

    if(mtr_res)
    {
        for (int i = 0; i < na; i++)
        {
            for (int j = 0; j < ma; j++)
                mtr_res[i][j] = mtr1[i][j] + mtr2[i][j];

        }

        return mtr_res;

    }
    else
        return NULL;
}
///
/// \brief multi умножение двух матриц
/// \param mtr1 матрица
/// \param mtr2 матрица
/// \param n кол-во строк в первой матрице
/// \param m кол-во столбцов одной матрицы и сторк другой
/// \param k кол-во столбцов во второй матрице
/// \return матрица или NULL
///
float** multi(float** mtr1, float** mtr2, const int n, const int m, const int l, const int k)
{
    if(m != l)
        return NULL;

    float **mtr_res = allocate_matrix(n, k);

    if(mtr_res)
    {
        mtr_res = init_matrix(mtr_res, n, k);
        for (int i = 0; i < n; i++)//строку
        {
            for (int j = 0; j < k; j++)//на столбец
            {
                for(int l = 0; l < m;  l++)
                    mtr_res[i][j] += mtr1[i][l] * mtr2[l][j];
            }
        }

        return mtr_res;

    }
    else
        return NULL;
}
///
/// \brief print_matr печать матрицы в консоль
/// \param mtr матрица
/// \param n кол-во строк
/// \param m кол-во столбов
///
void print_matr(float** mtr, const int n, const int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf(" %4.2f", mtr[i][j]);

        printf("\n");
    }
    puts("\n\n");
}

///
/// \brief determinant функция вычисления определителя разложением по строке
/// \param mtr матрица
/// \param n кол-во строк и столбцов
/// \return определитель
///
float determinant(float** mtr, const int n)
{
    if(n == 0)
        return 0;

    if(n == 2)
        return mtr[0][0]*mtr[1][1] - mtr[1][0]*mtr[0][1];
    else
    {
        //recursion
        int sign = 1;
        float det = 0;
        for(int j = 0; j < n; j++)//по первой строке
        {
            float** minor = allocate_matrix(n-1, n-1);
            minor = init_matrix(minor, n-1, n-1);

            for(int k = 1; k < n; k++)
            {
                int g = 0;
                for(int l = 0;  l < n; l++)
                    if(l != j)
                        minor[k-1][g++] = mtr[k][l];


            }

            if(sign == 1)//сократить
            {
                det += mtr[0][j] * determinant(minor, n-1);
                sign = 0;
            }
            else
            {
                det -= mtr[0][j] * determinant(minor, n-1);
                sign = 1;
            }

            free(minor);
        }


        return det;

    }
}
///
/// \brief comp_float
/// \param a
/// \param b
/// \return
///
int comp_float(float a, float b)
{
    if (fabs(a - b) <= EPS * fmax(fabs(a), fabs(b)))
    {
    // Числа равны с относительной точностью eps (0 < eps < 1)
        return MORE;
    }
    else
        return LESS;
}
///
/// \brief comp_matr
/// \param a
/// \param na
/// \param ma
/// \param b
/// \param nb
/// \param mb
/// \return
///
int comp_matr(float** a, int na, int ma, float** b, int nb, int mb)
{
    if( na != nb || ma != mb)
        return LESS;
    else
    {
        int rc = 0;
        for (int i = 0; i < na; i++)
        {
            for (int j = 0; j < ma; j++)
            {
                rc = comp_float(a[i][j], b[i][j]);
                if(rc == LESS)
                    break;
            }
            if(rc == LESS)
                break;
        }

        if(rc == LESS)
            return LESS;
        else
            return MORE;
    }
}

float randfrom(int min, int max)
{
    int range = max - min;
    int div = RAND_MAX / range;
    //printf("%f  %d\n", (float) rand() / div, min);
    return  min + ((float) rand() / div);
}
