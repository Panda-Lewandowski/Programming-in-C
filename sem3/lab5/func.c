#include "func.h"
///
/// \brief my_snprintf
/// \param s
/// \param n размер строки
/// \param format
/// \return
/// возвращает количество записанных чисел;  аргументов больше, чем нужно,
/// оставшиеся игнорируются; если форматная строка длиннее n возращается -1,
/// в строку записывается только n символов; длина строки s должна быть достаточно длинной.
int my_snprintf(char *s, size_t n, const char *format, ... )
{
    va_list args;
    va_start(args, format);
    char* ptr = s;
    char cval;
    char* oval;
    char* ptr_char;
    int i = 0;

    memset(s, 0, n);

    for(const char* p = format; *p; p++)
    {
        printf("%d\n", i);
        if(i >= n-1)
        {

            return -1;
        }

        if(*p != '%')
        {
            *ptr = *p;
            ptr++;
            i++;
            continue;
        }

        switch (*++p)
        {
        case 's':
            for(char* sval = va_arg(args, char*); *sval; sval++)
            {
                if(i >= n-1)
                {
                    return -1;
                }
                *ptr = *sval;
                ptr++;
                i++;
            }
            break;
        case 'c':
            cval = va_arg(args, int);
            *ptr = cval;
            ptr++;
            i++;
            break;
        case 'o':
            oval = d_to_o(va_arg(args, unsigned int));
            ptr_char = oval;
            if(oval)
            {
                for(; *oval; oval++)
                {
                    if(i > n-1)
                    {printf("djblkjblkcvjblkxcvnbkcvn\n");
                        free(ptr_char);
                        return -1;
                    }
                    *ptr = *oval;
                    ptr++;
                    i++;
                }
                free(ptr_char);
            }
            break;
        }

    }

    va_end(args);

    return strlength(s);
}

///
/// \brief d_to_o преобразование из десятичного числа в восьмеричное
/// \param number число
/// \return возвращает восьмеричное число в виде строки или  NULL
///
char* d_to_o(unsigned int number)
{
    /*char octal_digits[MAX_OCTAL_NUMBER_LENGTH + 1];
    char* pos = octal_digits + MAX_OCTAL_NUMBER_LENGTH - 1;
    for( ; pos >= octal_digits; --pos ) {
        *pos = (number % 8) + '0';
        number /= 8;
        if( number <= 0 ) break;
    }
    octal_digits[MAX_OCTAL_NUMBER_LENGTH] = '\0';
    return pos;*/

    if(!number)
    {
        char* oct = malloc(2*sizeof(char));
        if(oct)
        {
            *oct = 0 + '0';
            *(oct + 1) = '\0';
        }
        return oct;
    }

    unsigned int buf = number;
    int size = 0;
    while(buf) //исправить
    {
        buf /= 8;
        size++;
    }

    char* oct = malloc(size*sizeof(char)+1);
    if(oct)
    {
        char* pos = oct + size-1;
        for( ; pos >= oct; --pos )
        {
            *pos = (number % 8) + '0';
            number /= 8;
            if( number <= 0 ) break;
        }
        *(pos+size) = '\0';
    }

    return oct;

}
///
/// \brief strlenght находит длину строки
/// \param str строка входная
/// \return размер строки без '\0'
///
size_t strlength(const char *str)
{
    size_t i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}


///
/// \brief string_cat конкатенация строк
/// \param s1 первая строка
/// \param s2 вторая строка
/// \return первую с присоединенной второй
///
char*  string_cat(char *s1, const char *s2)
{
    char *cur = s1;

    while (*cur)
        cur++;


    while ((*cur++ = *s2++))
        ;

    return s1;
}
