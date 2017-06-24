#include "func.h"

int main(void)
{
    FILE *g;
    int *st;
    int *en;
    int rc, i, max = 0;


    g = fopen("test.txt", "r");

    count(g, &i);

    st = calloc(i, sizeof(int));

    if(st == NULL)
    {
        rc = ALLOC_ERR;
        return rc;
    }
    else
    {
        en = st + i;
        read(g, st, en);
        rc = 0;
    }

    for(; st < en; st++)
    {
        printf("%d ", *st);
    }

    printf("\n");
    st = en - i;
    find(st, en, &max);
    printf("олри = %d", max);
    /*
    en -=1;
    printf("st = %d    en = %d", *st, *en);*/
    return rc;
}
