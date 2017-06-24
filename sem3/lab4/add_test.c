#include "func.h"
// Классы эквивалентности:
// 1. разноразмерные матрицы - неразрешено вызовом функции
// 2. А + 0 v
// 3. А + (-А) v
// 4. прямоугольные матрицы v
// 5. квадратные матрицы v
// 6. положительные матрицы v
// 7. отрицательные v
// 8. смешанные v
int main()
{
    int fc;
    int na = 3, ma = 3;
    //int nb, mb;
    float** res;
    //Test #1
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        mtr_a = init_matrix(mtr_a, na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < na; j++)
                mtr_b[i][j] = i + j;

        res = add(mtr_a, mtr_b, na, ma, na, ma);
        fc = comp_matr(res, na, ma, mtr_b, na, ma);
        if(fc == MORE)
            printf("Test #1 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(res);
    }

    //Test #2
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < na; j++)
            {
                mtr_a[i][j] = i + j;
                mtr_b[i][j] = -(i + j);
            }


        //print_matr(mtr_a, na, ma);
        //print_matr(mtr_b, na, ma);
        res = add(mtr_b, mtr_a, na, ma, na, ma);
        mtr_a = init_matrix(mtr_a, na, ma);
        fc = comp_matr(res, na, ma, mtr_a, na, ma);
        if(fc == MORE)
             printf("Test #2 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(res);
    }

    //Test #3
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
            {
                mtr_a[i][j] = i + j;
                mtr_b[i][j] = i;
            }


        //print_matr(mtr_a, na, ma);
        //print_matr(mtr_b, na, ma);
        res = add(mtr_b, mtr_a, na, ma, na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
                mtr_a[i][j] = 2 * i + j;
        fc = comp_matr(res, na, ma, mtr_a, na, ma);
        if(fc == MORE)
             printf("Test #3 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(res);
    }

    //Test #4
    na = 2; ma = 3;
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
            {
                mtr_a[i][j] = j;
                mtr_b[i][j] = i;
            }


        //print_matr(mtr_a, na, ma);
        //print_matr(mtr_b, na, ma);
        res = add(mtr_b, mtr_a, na, ma, na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
                mtr_a[i][j] = i + j;
        fc = comp_matr(res, na, ma, mtr_a, na, ma);
        if(fc == MORE)
             printf("Test #4 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(res);
    }

    //Test #5
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
            {
                mtr_a[i][j] = 3 * j;
                mtr_b[i][j] = 2 * i;
            }


        //print_matr(mtr_a, na, ma);
        //print_matr(mtr_b, na, ma);
        res = add(mtr_b, mtr_a, na, ma, na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
                mtr_a[i][j] = 2 * i + 3 * j;
        fc = comp_matr(res, na, ma, mtr_a, na, ma);
        if(fc == MORE)
             printf("Test #5 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(res);
    }

    //Test #6
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
            {
                mtr_a[i][j] = -j;
                mtr_b[i][j] = -i;
            }


        //print_matr(mtr_a, na, ma);
        //print_matr(mtr_b, na, ma);
        res = add(mtr_b, mtr_a, na, ma, na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
                mtr_a[i][j] = - i - j;
        fc = comp_matr(res, na, ma, mtr_a, na, ma);
        if(fc == MORE)
             printf("Test #6 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(res);
    }

    //Test #7
    {
        srand(time(NULL));
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        float **mtr_r = allocate_matrix(na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
            {
                int a = randfrom(-1000, 1000);
                int b = randfrom(0, 2000);
                mtr_a[i][j] = a;
                mtr_b[i][j] = b;
                mtr_r[i][j] = a + b;
            }


        //print_matr(mtr_a, na, ma);
        //print_matr(mtr_b, na, ma);
        res = add(mtr_b, mtr_a, na, ma, na, ma);
        fc = comp_matr(res, na, ma, mtr_r, na, ma);
        if(fc == MORE)
             printf("Test #7 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(mtr_r);
        free(res);
    }



    return 0;
}
