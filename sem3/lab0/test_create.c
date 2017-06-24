#include "func.h"

int main(void)
{
    float av;
    float a[5] = {5.2, 5.3, 8.3, 25.4, 10.8}, b[5];
    float c[1] = {0.0}, d[1];
    float g[4];
    int m = 0, n, k = 0, rc;

    n = 5;
    av = 11;
    rc = create(av, b, a, MAX_N, &m, n);

    if (rc == 0 && m == 1)
    {
        if (b[0] == a[3])
            k++;
        //printf(" First test: ");
        compare(a, b, n);

    }

    m = 0;
    n = 1;
    av = 0.0;
    rc = create(av, d, c, MAX_N, &m, n);
    //printf("%d  %d", rc, m);
    if (rc == 0 && m == 1)
    {
        //printf("Second test:  ");
        if (compare(d, c, n) == 0)
            k++;
        //printf("%d    ", k);
    }

    n = 0;
    m = 0;
    av = 0.0;
    rc = create(av, a, g, MAX_N, &m, n);
    if (rc == 0 && m == 0)
    {
        k++;
    }

    if (k == 3)
        printf("Function CREATE OK");
    else
        printf("Function CREATE FAILED");

    return 0;
}
