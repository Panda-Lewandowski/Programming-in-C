#include "func.h"
#include <string.h>


int main()
{
    char *p;
    char *s = "123";
    int n = 0, m = 0;
    char *t;


    p = strpbrk_my ("this is a test", "hyhuik");
    //s = "his is a test";
    s = strpbrk("this is a test", "hyhuik");
    if(strcmp(p, s) == 0)
        n++;

    p = strpbrk_my ("this is a test", "this is a test");
    //s = "this is a test";
    s = strpbrk("this is a test", "this is a test");
    if(strcmp(p, s) == 0)
        n++;

    p = strpbrk_my ("this is a test", " ");
    //s = " is a test";
    s = strpbrk("this is a test", " ");
    if(strcmp(p, s) == 0)
        n++;

    p = strpbrk_my ("this is a test", "12345");
    if(p == NULL)
        n++;


    t = strndup("memory", 3);
    if(strcmp(t, "mem") == 0)
        m++;

    free(t);

    t = strndup("memory", 6);
    if(strcmp(t, "memory") == 0)
        m++;


    free (t);


    t = strndup("memory", -10);
    if(strcmp(t,"memory") == 0)
        m++;

    free(t);


    t = strndup("memory", 10);
    if(strcmp(t,"memory") == 0)
        m++;

    free(t);

    t = strndup("123456", 3);
    if(strcmp(t, "123") == 0)
        m++;

    free(t);

    t = strndup("memory", 0);
    if(strcmp(t, "") == 0)
        m++;

    free(t);

    if(n == 4)
        printf("Test strbrk Ok.\n");
    if(m == 6)
        printf("Test strndup Ok.\n");


    return 0;
}
