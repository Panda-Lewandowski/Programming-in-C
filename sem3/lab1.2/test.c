#include "func.h"

int main()
{

    int foo[5] = {23, 34, 0, 1, 0};
    int*end = foo + 5;

    int* st = foo;
    int** ptr_st = &st;
    int** ptr_end = &end;

    int* ptr = st;
    while(ptr != end)
    {
        printf("%d  ", *ptr);
        ptr++;
    }
    printf("\n");
    filter(ptr_st, ptr_end);
    /*for(int i = 0; i < 5; i++)
            printf("%d    ", st[i]);*/


    ptr = st;
    while(ptr != end)
    {
        printf("%d  ", *ptr);
        ptr++;
    }

    //sort(st, 3, sizeof(int), comp_int );
    /*for(int i = 0; i < 4; i++)
            printf("%d    ", st[i]);
    int p = 10;
    p = count(st, end);

    int* a = &p;
    int q = 7;
    int* b = &q;
    swap(a, b, sizeof(int));
    printf("----->>>  %d  %d", *a, *b);*/
    free(st);




    return 0;
}
