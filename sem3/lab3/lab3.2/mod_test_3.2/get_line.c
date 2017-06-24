#include "func.h"

int main()
{
    FILE* g;
    char* r;
    char* s;
    int n = 0;

    g = fopen("test1.txt", "r");
    r = get_line(g);
    if(r == NULL)
        n++;
    fclose(g);
    free(r);

    if(n == 1)
        printf("Test #1 passed.\n");

    g = fopen("test0.txt", "r");

    r = get_line(g);//больше bufsize
    s = "aaavhtjhbbbbdfgj\n";
    if(strcmp(s, r) == 0)
        n++;

    free(r);

    if(n == 2)
        printf("Test #2 passed.\n");

    r = get_line(g);//меньше bufsize
    s = "a\n";
    if(strcmp(s, r) == 0)
        n++;

    free(r);

    r = get_line(g);
    if(r == NULL)
        n++;

    if(n == 3)
        printf("Test #3 passed.\n");

    free(r);

    r = get_line(g);//равно bufsize
    s = "12345678\n";
    if(strcmp(s, r) == 0)
        n++;
    free(r);

    if(n == 4)
        printf("Test #4 passed.\n");

    r = get_line(g);
    s = "qwerty 12345";
    if(strcmp(s, r) == 0)
        n++;
    free(r);

    if(n == 5)
        printf("Test #5 passed.\n");



    fclose(g);


    return 0;

}
