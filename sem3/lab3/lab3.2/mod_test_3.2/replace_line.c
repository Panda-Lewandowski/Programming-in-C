#include "func.h"

int main()
{
    char* r;
    char* s;
    int n = 0;



    r = replace_line("abcdf", "c", "ccc");
    s = "abcccdf";
    if(strcmp(s, r) == 0)
        n++;

    free(r);

    if(n == 1)
        printf("Test #1 passed.\n");

    r = replace_line("abcdf", "", "ccc");
    if(r == NULL)
        n++;

    free(r);

    if(n == 2)
        printf("Test #2 passed.\n");

    r = replace_line("abcdf", "e", "ccc");
    s = "abcdf";
    if(strcmp(s, r) == 0)
        n++;

    free(r);

    if(n == 3)
        printf("Test #3 passed.\n");

    r = replace_line("alala", "a", "ccc");///несколько подряд
    s = "ccclccclccc";
    if(strcmp(s, r) == 0)
        n++;

    free(r);

    if(n == 4)
        printf("Test #4 passed.\n");

    r = replace_line("2 + 2 = x", "x", "4");
    s = "2 + 2 = 4";
    if(strcmp(s, r) == 0)
        n++;

    free(r);

    if(n == 5)
        printf("Test #5 passed.\n");

    r = replace_line("memortttty", "tttt", "");//большее на меньшее
    s = "memory";
    if(strcmp(s, r) == 0)
        n++;

    free(r);

    if(n == 6)
        printf("Test #6 passed.\n");

    r = replace_line("aaalaaalaaa", "aaa", "c");///несколько подряд
    s = "clclc";
    if(strcmp(s, r) == 0)
        n++;

    free(r);

    if(n == 7)
        printf("Test #7 passed.\n");

    return 0;
}
