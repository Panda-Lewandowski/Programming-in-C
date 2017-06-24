#include "func.h"


int main(void)
{
    FILE *f, *g, *k, *l;
    int m = 0, n, rc;
    float a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N], correct[5] = {4.2, 8.4, 5.1, 16.7, 4.3} ;

    f = fopen("read1.txt", "r");
    g = fopen("read2.txt", "r");
    k = fopen("read3.txt", "r");
    l = fopen("read4.txt", "r");

    rc = read(f, a, MAX_N, &n); //empty file
    if (rc == NO_DATA && n == 0)
        m++;

    n = 0;
    rc = read(g, b, MAX_N, &n);// >10 simbols
    if (rc == REPLETION && n == 10)
        m++;
    //printf("%d", n);

    n = 0;
    rc = read(k, c, MAX_N, &n); // 1 simbol
    if (rc == 0 && n == 1)
    {
        if ((c[0] - 25.25) < 0.000001)
            m++;

    }

    n = 0;
    rc = read(l, d, MAX_N, &n); //5 simbols
    if (rc == 0 && n == 5)
    {
        for (int i = 0; i < 5; i++)
            if (compare(d, correct, n) == 0)
                m++;
    }

    if (m == 7)
        printf("Function READ OK");
    else
        printf("Function READ FAILED");

    fclose(f);
    fclose(g);
    fclose(k);
    fclose(l);

    return 0;

}
