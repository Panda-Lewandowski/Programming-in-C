#include "func.h"

int main(void)
{
    int n = 0,fc = 0, m = 0;
    FILE* f;
    FILE* g;
    FILE* h;
    int *start;
    int *end;
    int test1[5] = {1, 2, 3, 4, 5};
    int test2[7] = {5, 8, 9, 6, 2, 4, 5};

    n = 5;
    f = fopen("test1.txt", "r");
    start = calloc(n, sizeof(int));
    end = start + n;
    fc = read(f, start, end);
    start = end - n;
    if(fc == 0)
    {
        fc = compare(start, end, test1, n);
        if(fc == 0)
            m = 5;
    }
    if(m == 5)
        printf("Test #1 passed.\n");
    fclose(f);
    free(start);

    n = 10;
    g = fopen("test2.txt", "r");
    start = calloc(n, sizeof(int));
    end = start;
    fc = read(g, start, end);
    if(fc == ERR)
    {
        m++;
    }
    if(m == 6)
        printf("Test #2 passed.\n");
    fclose(g);
    free(start);

    n = 7;
    h = fopen("test4.txt", "r");
    start = calloc(n, sizeof(int));
    end = start + n;
    fc = read(h, start, end);
    start = end - n;
    if(fc == 0)
    {
        fc = compare(start, end, test2, n);
        if(fc == 0)
            m = 13;
    }
    if(m == 13)
        printf("Test #3 passed.\n");
    fclose(h);
    free(start);

    if(m == 13)
        printf("Test_read ok.\n");
    else
        printf("Test_read failed.\n");


    return 0;
}
