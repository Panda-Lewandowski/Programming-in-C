#include "func.h"

int main()
{
    int n = 0;

    if(strcmp(strstr_my("qwerty", "wer"), "werty") == 0)
        n++;

    if(n == 1)
        printf("Test #1 passed.\n");

    if(strstr_my("qwerty", "abcd") == NULL)
        n++;

    if(n == 2)
        printf("Test #2 passed.\n");

    if(strcmp(strstr_my("qwerty", "y"), "y") == 0)
        n++;

    if(n == 3)
        printf("Test #3 passed.\n");

    if(strstr_my("", "wer") == NULL)
        n++;

    if(n == 4)
        printf("Test #4 passed.\n");

    if(strcmp(strstr_my("q", "q"), "q") == 0)
        n++;

    if(n == 5)
        printf("Test #5 passed.\n");

    if(strcmp(strstr_my("qwerty", ""), "qwerty") == 0)
        n++;

    if(n == 6)
        printf("Test #6 passed.\n");


    return 0;
}
