#include "func.h"

int main()
{

    int n = 0;
    int fc = 0;
    {
        int foo[] = {23, 34, 0, 1, 0};

        int* end = foo + 5;
        int* st = foo;
        int** ptr_st = &st;
        int** ptr_end = &end;

        int res[] = {34, 1, 0};

        fc = filter(ptr_st, ptr_end);
        if(fc != ALLOC_ERR || fc != ERR)
        {
            n = compare(st, 5, res, 3);
            if(n == 3)
                printf("Test #1 passed.\n");
            free(st);
        }



    }


    {
        int foo[] = {1, 3, 0, 5, 6};

        int* end = foo + 5;
        int* st = foo;
        int** ptr_st = &st;
        int** ptr_end = &end;

        int res[] = {6};

        fc = filter(ptr_st, ptr_end);
        if(fc != ALLOC_ERR || fc != ERR)
        {
            n = compare(st, 5, res, 1);
            if(n == 1)
                printf("Test #2 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {0};
        int* end = foo;
        int* st = foo;
        int** ptr_st = &st;
        int** ptr_end = &end;

        fc = filter(ptr_st, ptr_end);
        if(fc == ERR)
            n++;
        if(n == 2)
            printf("Test #3 passed.\n");
    }

    {

        int foo[] = {0};

        int* end = foo + 1;
        int* st = foo;
        int** ptr_st = &st;
        int** ptr_end = &end;

        int res[] = {0};

        fc = filter(ptr_st, ptr_end);
        if(fc != ALLOC_ERR || fc != ERR)
        {
            n = compare(st, 1, res, 1);
            if(n == 1)
                printf("Test #4 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {100, 34};

        int* end = foo + 2;
        int* st = foo;
        int** ptr_st = &st;
        int** ptr_end = &end;

        int res[] = {100, 34};

        fc = filter(ptr_st, ptr_end);
        if(fc != ALLOC_ERR || fc != ERR)
        {
            n = compare(st, 2, res, 2);
            if(n == 2)
                printf("Test #5 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {100, 100};

        int* end = foo + 2;
        int* st = foo;
        int** ptr_st = &st;
        int** ptr_end = &end;

        int res[] = {100, 100};

        fc = filter(ptr_st, ptr_end);
        if(fc != ALLOC_ERR || fc != ERR)
        {
            n = compare(st, 2, res, 2);
            if(n == 2)
                printf("Test #6 passed.\n");
            free(st);
        }
    }


    return 0;
}
