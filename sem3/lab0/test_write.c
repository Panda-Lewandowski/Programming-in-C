#include "func.h"

int main(void)
{
    FILE *f, *g;
    int m = 0, n, rc;
    float   b[5] = {4.2, 8.4, 5.1, 16.7, 4.3};
    float buf;

    f = fopen("write1.txt", "w");
    g = fopen("write2.txt", "w");

    n = 5;
    rc = write(g, b, n);

    fclose(f);
    fclose(g);

    f = fopen("write1.txt", "r");
    g = fopen("write2.txt", "r");

    if (rc == 0)
    {
        //rewind(g);

        int i = 0;

        while(fscanf(g, "%g", &buf) == 1)
        {

            if ((buf - b[i]) < 0.00000001)
                m++;

            i++;
        }
    }

    if (m == 5)
        printf("Function WRITE OK");
    else
        printf("Function WRITE FAILED");

    fclose(f);
    fclose(g);

    return 0;

}
