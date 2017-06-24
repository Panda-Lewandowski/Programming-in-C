#include "func.h"

int main()
{
    int n = 0;

    {
    char r[10] =  "qwer";
    char s[] = "tyyyyyyyyyyyyyyyy";


    if(strcmp(string_n_cat(r, s, 2),"qwerty") == 0)
        n++;

    //printf("r = '%s'\n", r);
    }

    if(n == 1)
        printf("Test #1 passed.\n");


    {
    char r[10] =  "qwerty";
    char s[] = "";

    if(strcmp(string_n_cat(r, s, 2),"qwerty") == 0)
        n++;

    //printf("r = '%s'\n", r);
    }

    if(n == 2)
        printf("Test #2 passed.\n");

    {
    char r[10] =  "";
    char s[] = "qwerty";

    if(strcmp(string_n_cat(r, s, 6),"qwerty") == 0)
        n++;

    //printf("r = '%s'\n", r);
    }

    if(n == 3)
        printf("Test #3 passed.\n");

    {
    char r[10] =  "";
    char s[] = "";

    if(strcmp(string_n_cat(r, s, 2),"") == 0)
        n++;

    //printf("r4 = '%s'\n", r4);
    }

    if(n == 4)
        printf("Test #4 passed.\n");

    {
    char r[10] =  "1234 ";
    char s[] = "qwerty";

    if(strcmp(string_n_cat(r, s, 4),"1234 qwer") == 0)
        n++;

    //printf("r = '%s'\n", r);
    }

    if(n == 5)
        printf("Test #5 passed.\n");

    {
    char r[20] =  {'h', 'e', 'l', 'l', 'o', '\0'};
    char s[7] = {' ','w', 'o', 'r', 'l', 'd', '\0'};

    if(strcmp(string_n_cat(r, s, 4),"hello wor") == 0)
        n++;


    printf("r = '%s', len = %d\n"
           "r[9] = (int)'%d'\n", r,
           strlen(r), r[9]);
    for(int i = 0; i <= strlen(r); i++)
        printf("'%c'  ", r[i]);
    printf("\n");

    }

    if(n == 6)
        printf("Test #6 passed.\n");

    {
    char r[20] =  {'h', 'e', 'l', 'l', 'o', '\0'};
    char s[6] = {' ','w', 'o', 'r', 'l', 'd'};
    if(strcmp(string_n_cat(r, s, 4),"hello wor") == 0)
        n++;


    printf("r = '%s', len = %d\n"
           "r[9] = (int)'%d'\n", r,
           strlen(r), r[9]);
    for(int i = 0; i <= strlen(r); i++)
        printf("'%c'  ", r[i]);
    printf("\n");

    }

    if(n == 7)
        printf("Test #7 passed.\n");

    return 0;

}
