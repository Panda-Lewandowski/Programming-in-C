#include "func.h"

int count(FILE *f, int *n)
{
    int i = 0, rc = 0, buf;

    while (fscanf(f, "%d", &buf) == 1)
    {
        i++;
    }

    if(i == 0)
        rc = NO_DATA;
    else
        rewind(f);

    *n = i;

    return rc;
}

int read(FILE *f, int *start, int *end)
{
    int rc;



    while(fscanf(f, "%d", start) ==1)
    {
        start++;
    }

    if(*start == *end)
        rc = 0;
    else
        rc = ERR;

    return rc;

}


int find(int* start, int* end, int *max)
{
    int rc = 0, i = 0;

    if(start >= end)
        rc = ERR;
    else
    {
        end -= 1;
        *max = *start + *end;
        while((end - start) >= 0)
        {
            if(*start + *end > *max)
                *max = *start + *end;
            start++;
            end--;
            i++;
        }
    }

    return rc;
}


int compare(int* start, int* end,int* test1, int m)
{
    int rc = 0, i = 0, k = 0;
    int n = end - start;
    if(n != m)
        rc = -1;
    else
    {
        for(; start < end; start++, i++)
        {
            if(*start == test1[i])
                k++;
        }
    }

    return rc;
}
