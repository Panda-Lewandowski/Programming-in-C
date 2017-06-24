#include "func.h"

int main(void)
{
    int n = 0, m = 0, fc = 0;
    FILE* f;
    FILE* g;
    FILE* h;

    f = fopen("test1.txt", "r");

    fc = count(f, &n);

    if(fc == 0 && n == 5)
    {
        printf("Test #1 passed.\n");
        m++;
    }

    fclose(f);
    n = 0;

    g = fopen("test2.txt", "r");

    fc = count(g, &n);

    if(fc == 0 && n == 10)
    {
        printf("Test #2 passed.\n");
        m++;
    }

    fclose(g);
    n = 0;

    h = fopen("test3.txt", "r");

    fc = count(h, &n);

    if(fc == NO_DATA && n == 0)
    {
        printf("Test #3 passed.\n");
        m++;
    }

    fclose(h);

    if(m == 3)
        printf("Test_count ok.\n");
    else
        printf("Test_count failed.\n");

    return 0;
}
