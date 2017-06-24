#include "func.h"
/*char* str_pbrk(char *str, const char *sym)
{
    int i = 0, j;
    char *addr = NULL;

    while (str[i] != '\0')
    {
        j = 0;

        while (sym[j] != '\0')
        {
            if (str[i] == sym[j])
            {
                addr = &str[i];
                break;
            }

            j++;
        }

        if (addr != NULL)
        break;

        i++;
    }

    return addr;
}*/

char *strpbrk_my(const char *s, const char *accept)
{
    for (; *accept != '\0'; accept++)
    {

        for(; *s != '\0'; s++)
        {
            //printf(" %c - %c\n", *accept, *s );
            if(*accept == *s)
                return (char *)s;
        }
        //printf("\n");
    }

    return NULL;
}


char *strndup(const char *str, size_t n)
{
    /*assert(n >= 0);
    if(n <= 0)
        return "";*/

    size_t m = strlen_my(str);
    char* new_str;

    if(m < n)
         new_str = malloc(m+1);
    else if(m >= n)
         new_str = malloc(n+1);

    size_t i = 0;

    if (new_str)
    {

        while(i < n && (new_str[i] = *str++))
            i++;

        new_str[i] = '\0';
        return new_str;
    }

    return NULL;


}



size_t strlen_my(const char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
        i++;
    //printf("i = %d\n", i);
    return i;
}

