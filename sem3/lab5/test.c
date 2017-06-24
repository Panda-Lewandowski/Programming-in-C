#include "func.h"
#include <string.h>
//%s %o %c v
//%o %s %c v
//%o %c %s v
//%c %o %s v
//%c %s %o v
//%s %c %o v
//%s %o v
//%c %s v
//%c v
//%o v
//%s v
//qwerty %o
//<----> %s
//123456 %c
// 123 %c qwerty %s --- %o
int main()
{
    int fc = 0, rc = 0;
    {
        char s[11];
        char r[11];
        fc = my_snprintf(s, 11, "%c = %s = %o", 54, "qwerty", 108);
        rc = snprintf(r, 11, "%c = %s = %o", 54, "qwerty", 108);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #1 passed.\n");
        //printf("%s \n", r/*, rc*/);
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%s %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 20, "%s %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #2 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%o %s %c", 8, "qwerty", 57);
        rc = snprintf(r, 20, "%o %s %c", 8, "qwerty", 57);
        if(strcmp(s, r) == 0 && fc == rc)
           printf("Test #3 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%o %c %s", 48, 100, "- - -");
        rc = snprintf(r, 20, "%o %c %s", 48, 100, "- - -");
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #4 passed.\n");

    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%c %o %s", 74, 100, "12345");
        rc = snprintf(r, 20, "%c %o %s", 74, 100, "12345");
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #5 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%c %s %o", 74, "qwerty", 61);
        rc = snprintf(r, 20, "%c %s %o", 74, "qwerty", 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #6 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%s %c %o", "qwerty", 100, 61);
        rc = snprintf(r, 20, "%s %c %o", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #7 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%s %o", "qwerty", 100, 61);
        rc = snprintf(r, 20, "%s %o", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #8 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%c %s", 74, "qwerty");
        rc = snprintf(r, 20, "%c %s", 74, "qwerty");
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #9 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%s", "qwerty");
        rc = snprintf(r, 20, "%s", "qwerty");
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #10 passed.\n");

    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%o", 100);
        rc = snprintf(r, 20, "%o", 100);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #11 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 20, "%c", 61);
        rc = snprintf(r, 20, "%c", 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #12 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 4, "%s %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 4, "%s %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #13 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 9, "%s %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 9, "%s %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #14 passed.\n");
    }


    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 1, "123 %s %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 1, "123 %s %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #15 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 9, "%s poiy %o %c", "qwerty", 100, 61);
        rc = snprintf(r, 9, "%s poiy %o %c", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #16 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 6, "%s%c", "qwerty", 100);
        rc = snprintf(r, 6, "%s%c", "qwerty", 100);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #17 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 10, "%s", "qwerty", 100, 61);
        rc = snprintf(r, 10, "%s", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #18 passed.\n");
    }

    {
        char s[20] = {0};
        char r[20] = {0};
        fc = my_snprintf(s, 10, "", "qwerty", 100, 61);
        rc = snprintf(r, 10, "", "qwerty", 100, 61);
        if(strcmp(s, r) == 0 && fc == rc)
            printf("Test #19 passed.\n");
    }




    return 0;
}
