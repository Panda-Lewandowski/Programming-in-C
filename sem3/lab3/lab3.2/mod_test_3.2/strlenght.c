#include "func.h"

int main()
{
    int n = 0;

    if(strlength("12345") == 5)
        n++;
    if(n == 1)
        printf("Test #1 passed.\n");

    if(strlength("") == 0)
        n++;
    if(n == 2)
        printf("Test #2 passed.\n");

    if(strlength("qwerty") == 6)
        n++;
    if(n == 3)
        printf("Test #3 passed.\n");

    if(strlength("0") == 1)
        n++;
    if(n == 4)
        printf("Test #4 passed.\n");


    return 0;
}
