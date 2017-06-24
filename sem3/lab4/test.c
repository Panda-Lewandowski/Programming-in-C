#include "func.h"

int main(void)
{

    FILE* f;
    f = fopen("mtr1.txt", "r+");
    //int n = 3, m = 3;
    //int k = n;
    //float **mtr_a = allocate_matrix(n, m);
    float **mtr_b; /*= allocate_matrix(m, k);*/

    /*for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mtr_a[i][j] = i + j;*/
    /*mtr_a[0][0] = 1;
    mtr_a[0][1] = -2;
     mtr_a[0][2] = 3;

     mtr_a[1][0] =   4;
     mtr_a[1][1] =     0;
      mtr_a[1][2] =      6;

    mtr_a[2][0] =  -7;
    mtr_a[2][1] =8;
    mtr_a[2][2] =9;
    print_matr(mtr_a, n, m);*/







    //float det = determinant(mtr_a, n);
   // printf("det(mtr_a) = %.3f\n", det);

    //mtr = init_matrix(mtr, 2, 3);
    int m, k;
    mtr_b = fread_matr(f, &m, &k);

    print_matr(mtr_b, m, k);
    //float** mtr = multi(mtr_a, mtr_b, n, m, k);
   // print_matr(mtr, n, k);


    //fprint_matr(f, mtr, n, m);
    free(mtr_b);
    //free(mtr_b);
    //free(mtr);

    //fclose(f);
    return 0;
}
