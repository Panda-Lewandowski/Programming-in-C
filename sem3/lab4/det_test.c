#include "func.h"
// Классы эквивалентности:
// 1.2Х2 v
// 2. Е v
// 3. нулевая v
// 4. NxM - невозможно по вызову функции
// 5. NxN v
// 6. 0x0
int main()
{

    float det = 0;
    //Test #1
    {
        float** mtr = allocate_matrix(2, 2);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                mtr[i][j] = i+j+2;

        det = determinant(mtr, 2);
        if(det == -1)
            printf("Test #1 passed.\n");

        free(mtr);
    }

    //Test #2
    {
        float** mtr = allocate_matrix(4, 4);
        mtr = init_matrix(mtr, 4, 4);
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(i == j)
                    mtr[i][j] = 1;

        det = determinant(mtr, 4);
        if(det == 1)
            printf("Test #2 passed.\n");

        free(mtr);
    }

    //Test #3
    {
        float** mtr = allocate_matrix(4, 4);
        mtr = init_matrix(mtr, 4, 4);

        det = determinant(mtr, 4);
        if(det == 0)
            printf("Test #3 passed.\n");

        free(mtr);
    }

    //Test #4
    {
        float** mtr = allocate_matrix(3, 3);
        mtr[0][0] = 1;
        mtr[0][1] = -2;
        mtr[0][2] = 3;

        mtr[1][0] = 4;
        mtr[1][1] = 0;
        mtr[1][2] = 6;

        mtr[2][0] = -7;
        mtr[2][1] = 8;
        mtr[2][2] = 9;

        det = determinant(mtr, 3);
        if(det == 204)
            printf("Test #4 passed.\n");

        free(mtr);
    }

    //Test #5
    {
        float** mtr = allocate_matrix(3, 3);
        det = determinant(mtr, 0);
        if(det == 0)
            printf("Test #5 passed.");
        free(mtr);
    }
    return 0;
}
