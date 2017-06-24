#include "func.h"

int main(void)
{
    int max = 0,m = 0, n = 0;
    FILE* f;
    FILE* g;
    FILE* h;
    int *start;
    int *end;
    int fc;

    n = 5;
    f = fopen("test1.txt", "r");
    start = calloc(n, sizeof(int));
    end = start + n;
    read(f, start, end);
    start = end - n;


    fc = find(start, end, &max);
    if(max == 6 && fc == 0)
    {
        m++;
    }
    if(m == 1)
        printf("Test #1 passed.\n");
    fclose(f);
    free(start);

    max = 0;
    n = 10;
    g = fopen("test2.txt", "r");
    start = calloc(n, sizeof(int));
    end = start + n;
    read(f, start, end);
    start = end - n;
    fc = find(start, end, &max);
    if(max == 0 && fc == 0)
    {
        m++;
    }
    if(m == 2)
        printf("Test #2 passed.\n");
    fclose(g);
    free(start);

    max = 0;
    int test1[] = {1, 2, 3, 4, 5};
    n = 5;
    start = test1;
    end = start + n;
    fc = find(start, end, &max);
    start = end - n;
    if(max == 6 && fc == 0)
    {
       m++;
    }
    if(m == 3)
        printf("Test #3 passed.\n");

    max = 0;
    int test2[] = {1, 2};

    start = test2;
    end = test2;
    fc = find(start, end, &max);
    start = end - n;
    if(fc == ERR)
    {
       m++;
    }
    if(m == 4)
        printf("Test #4 passed.\n");

    max = 0;
    n = 7;
    h = fopen("test4.txt", "r");
    start = calloc(n, sizeof(int));
    end = start + n;
    read(f, start, end);
    start = end - n;
    fc = find(start, end, &max);
    start = end - n;
    if(max == 12 && fc == 0)
    {
       m++;
    }
    if(m == 5)
        printf("Test #5 passed.\n");
    fclose(h);
    free(start);

    if(m == 5)
        printf("Test_find ok.\n");
    else
        printf("Test_find failed.\n");


    return 0;
}
