#include "func.h"

int main()
{
    char r[10] =  "qwer";
    char s[] = "ty";
    int n = 0;

    if(strcmp(string_cat(r, s),"qwerty") == 0)
        n++;

    if(n == 1)
        printf("Test #1 passed.\n");


    char r1[10] = "";
    char s1[] = "qwerty";
    if(strcmp(string_cat(r1, s1),"qwerty") == 0)
        n++;

    if(n == 2)
        printf("Test #2 passed.\n");


    char r2[10] = "qwerty";
    char s2[] = "";
    if(strcmp(string_cat(r2, s2),"qwerty") == 0)
        n++;

    if(n == 3)
        printf("Test #3 passed.\n");


    char r3[10] = "";
    char s3[] = "";
    if(strcmp(string_cat(r3, s3),"") == 0)
        n++;

    if(n == 4)
        printf("Test #4 passed.\n");


    char r4[15] = "123456 ";
    char s4[] = "qwerty";
    if(strcmp(string_cat(r4, s4),"123456 qwerty") == 0)
        n++;


    if(n == 5)
        printf("Test #5 passed.\n");


    char r5[20] = "кверти ";
    char s5[] = "qwerty";
    if(strcmp(string_cat(r5, s5),"кверти qwerty") == 0)
        n++;

    if(n == 6)
        printf("Test #6 passed.\n");


    char r6[10] = "123 ";
    char s6[] = "qwerty ";
    char t6[] = "кверти";
    string_cat(r6, s6);
    if(strcmp(string_cat(r6, t6),"123 qwerty кверти") == 0)
        n++;

    if(n == 7)
        printf("Test #7 passed.\n");
    return 0;
}
