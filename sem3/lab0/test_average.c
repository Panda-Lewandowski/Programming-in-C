#include "func.h"

int main(void)
{
    float a[5] ={25.25, 25.25, 25.25, 25.25, 25.25}, b[5] = {4.2, 5.2, 6.3, 8.52, 14.2};
    int m = 0, n = 5;
    float av = 0;


    average(a, n, &av);
    if ((av - 25.25) < 0.000001)
        m++;

    av = 0;
    average(b, n, &av);
    if ((av - 7.684) < 0.000001)
        m++;
    //printf("%.10f", av);
    if (m == 2)
        printf("Finction AVERAGE OK");
    else
        printf("Function AVARAGE FAILED");

    return 0;
}
