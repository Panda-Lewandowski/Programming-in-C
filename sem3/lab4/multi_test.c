#include "func.h"
// Классы эквивалентности:
// 1. разноразмерные матрицы v
// 2. А * 0 v
// 3. А * (-А) v
// 4. матрица на вектор v
// 5. квадратные матрицы v
// 6. положительные матрицы
// 7. отрицательные
// 8. смешанные
// 9. вектор на матрицу v
// 0. матрица на обратную v
// 00 вектор на вектор v
int main()
{
    int fc;
    int na = 3, ma = 4;
    int nb = 2, mb = 1;
    float** res;

    //Test #1
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(nb, mb);
        mtr_a = init_matrix(mtr_a, na, ma);
        mtr_b = init_matrix(mtr_b, nb, mb);


        res = multi(mtr_a, mtr_b, na, ma, nb, mb);

        if(res == NULL)
            printf("Test #1 passed.\n");

        free(mtr_a);
        free(mtr_b);

    }

    //Test #2
    nb = 4;
    mb = 3;
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(nb, mb);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
                mtr_a[i][j] = i + j;
        mtr_b = init_matrix(mtr_b, nb, mb);


        //print_matr(mtr_a, na, ma);
        //print_matr(mtr_b, na, ma);
        res = multi(mtr_a, mtr_b, na, ma, nb, mb);
        float** mtr_r = allocate_matrix(na, mb);
        mtr_r = init_matrix(mtr_r, na, mb);
        fc = comp_matr(res, na, mb, mtr_r, na, mb);
        if(fc == MORE)
             printf("Test #2 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(mtr_r);
        free(res);

    }

    //Test #3
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(nb, mb);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
                mtr_a[i][j] = i + j;
        for (int i = 0; i < nb; i++)
            for (int j = 0; j < mb; j++)
                mtr_b[i][j] = -(i + j);


        res = multi(mtr_a, mtr_b, na, ma, nb, mb);
        float** mtr_r = allocate_matrix(na, mb);
        mtr_r[0][0] = -14;
        mtr_r[0][1] = -20;
        mtr_r[0][2] = -26;

        mtr_r[1][0] = -20;
        mtr_r[1][1] = -30;
        mtr_r[1][2] = -40;

        mtr_r[2][0] = -26;
        mtr_r[2][1] = -40;
        mtr_r[2][2] = -54;
        fc = comp_matr(res, na, mb, mtr_r, na, mb);
        if(fc == MORE)
             printf("Test #3 passed.\n");


        free(mtr_a);
        free(mtr_b);
        free(mtr_r);
        free(res);
    }

    //Test #4
    na = 3;
    ma = 3;
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        for (int i = 0; i < na; i++)
            for (int j = 0; j < ma; j++)
            {
                mtr_a[i][j] = i + j;
                mtr_b[i][j] = i - j;
            }


        res = multi(mtr_a, mtr_b, na, ma, na, ma);
        float** mtr_r = allocate_matrix(na, ma);
        mtr_r[0][0] = 5;
        mtr_r[0][1] = 2;
        mtr_r[0][2] = -1;

        mtr_r[1][0] = 8;
        mtr_r[1][1] = 2;
        mtr_r[1][2] = -4;

        mtr_r[2][0] = 11;
        mtr_r[2][1] = 2;
        mtr_r[2][2] = -7;
        fc = comp_matr(res, na, ma, mtr_r, na, ma);
        if(fc == MORE)
             printf("Test #4 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(mtr_r);
        free(res);
    }

    //Test #5
    {
        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(ma, 1);
        for (int i = 0; i < na; i++)
        {
            mtr_b[i][0] = i;
            for (int j = 0; j < ma; j++)
                mtr_a[i][j] = i + j;
        }

        res = multi(mtr_a, mtr_b, na, ma, ma, 1);
        float** mtr_r = allocate_matrix(na, 1);
        mtr_r[0][0] = 5;
        mtr_r[1][0] = 8;
        mtr_r[2][0] = 11;
        fc = comp_matr(res, na, 1, mtr_r, na, 1);
        if(fc == MORE)
             printf("Test #5 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(mtr_r);
        free(res);
    }

    //Test #6
    {

        float **mtr_a = allocate_matrix(1, ma);
        float **mtr_b = allocate_matrix(na, ma);
        for (int i = 0; i < na; i++)
        {
            mtr_a[0][i] = i;
            for (int j = 0; j < ma; j++)
                mtr_b[i][j] = i + j;
        }


        res = multi(mtr_a, mtr_b, 1, ma, na, ma);
        float** mtr_r = allocate_matrix(1, ma);
        mtr_r[0][0] = 5;
        mtr_r[0][1] = 8;
        mtr_r[0][2] = 11;
        fc = comp_matr(res, 1, ma, mtr_r, 1, ma);
        if(fc == MORE)
             printf("Test #6 passed.\n");

        free(mtr_a);
        free(mtr_b);
        free(mtr_r);
        free(res);
    }

    //Test #7
    {

        float **mtr_a = allocate_matrix(na, ma);
        float **mtr_b = allocate_matrix(na, ma);
        mtr_a[0][0] = 2;
        mtr_a[0][1] = 5;
        mtr_a[0][2] = 7;

        mtr_a[1][0] = 6;
        mtr_a[1][1] = 3;
        mtr_a[1][2] = 4;

        mtr_a[2][0] = 5;
        mtr_a[2][1] = -2;
        mtr_a[2][2] = -3;

        mtr_b[0][0] = 1;
        mtr_b[0][1] = -1;
        mtr_b[0][2] = 1;

        mtr_b[1][0] = -38;
        mtr_b[1][1] = 41;
        mtr_b[1][2] = -34;

        mtr_b[2][0] = 27;
        mtr_b[2][1] = -29;
        mtr_b[2][2] = 24;
        res = multi(mtr_a, mtr_b, na, ma, na, ma);
        float** mtr_r = allocate_matrix(na, na);
        mtr_r = init_matrix(mtr_r, na, ma);
        mtr_r[0][0] = 1;
        mtr_r[1][1] = 1;
        mtr_r[2][2] = 1;
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
