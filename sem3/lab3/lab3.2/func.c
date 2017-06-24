#include "func.h"
//#define DEBUG
///
/// \brief get_line считывает строчку из файла с помощью маленького буфера
/// \param f файл входной
/// \return NULL или строку
///
char* get_line(FILE* f)//контроль выделения памяти v, зачем фор v , возвращать без незаполненной памяти
{
    char* line;
    char* buf;
    int size = BUFSIZE;

    buf = malloc(size);
    line = malloc(size);
    memset(line, '\0', size);


    if(buf && line)
    {


        while (!feof(f))
        {
            if(fgets(buf, BUFSIZE, f))
            {

                if(buf[strlength(buf)-1] != '\n' /*&& !feof(f)*/)
                {

                       char* cop;
                       cop = line;

                       int oldsize = size;

                       size += BUFSIZE;


                       line = malloc(size);

                       if(line)
                       {
                           memcpy(line, cop, oldsize);

                           string_cat(line, buf);
                           free(cop);



                       }
                       else
                       {

                           free(cop);
                           free(buf);
                           free(line);
                           return NULL;
                       }
                }
                else
                {


                    /*line = string_cat(line, buf);
                    free(buf);
                    return line;*/



                    line = string_cat(line, buf);
                    if(size != strlength(line))
                    {
                        char* cop = malloc(strlength(line)+1);
                        //cop = line;
                        //line = malloc(strlength(cop)+1);
                        if(cop)
                        {
                            memset(cop, '\0', strlength(line)+1);


                            cop = memmove(cop, line, strlength(line));

                            free(line);
                            free(buf);
                            return cop;
                        }
                        else
                        {
                            return NULL;
                        }
                    }
                    else
                    {
                        free(buf);
                        return line;

                    }
                }


            }
            else
            {
                //printf("'%s'", line);
                free(buf);
                //free(line);

                return line;
            }
        }
    }

    free(buf);
    free(line);
    return NULL;

}
///
/// \brief replace_line заменяет в строке str строку from на строку to
/// \param str
/// \param from
/// \param to
/// \return возвращает результирующую строку
///
char* replace_line(char* str, const char *from, const char *to)
{
    char* ptr = str;
    char* ptrOld;
    char* result;
    int find = 0;

    const int lenS = strlength(str);
    const int lenF = strlength(from);
    const int lenT = strlength(to);
    int	lenR;

    if (lenF <= 0)
    {
#ifdef DEBUG
        printf("> Error: trying to replace empty substring!\n");
#endif
        return NULL;
    }

    do//находим количество повторений
    {
        ptr = strstr_my(ptr, from);
        if (ptr)
        {
            ptr += lenF;
            find++;
        }
    }
    while (ptr);
#ifdef DEBUG
    if (find == 0)

        printf("> Warning: no substring <%s> in line <%s>.\n",from, str);
#endif
    lenR = lenS - find*lenF + find*lenT;//вычисляем длину результата
    result = malloc(lenR+1);
    if(result)
    {
        memset(result,'\0',lenR+1);
        ptr = str;

        do
        {
            ptrOld = ptr;
            ptr = strstr_my(ptr, from);//где начинается очередное вхождение
            if (ptr)
            {
                string_n_cat(result, ptrOld, ptr-ptrOld);//копируем все до вхождения
                string_n_cat(result, to, lenT);//копируем заменитель
                ptr += lenF;//сдвигаемся на длину заменяемой подстроки
            }
            else//если вхождения по какой-то причине не найдены
                string_n_cat(result,ptrOld,strlen(ptrOld));
        }
        while (ptr);

        return result;
    }
    else
        return NULL;
}
///
/// \brief strstr_my находит первое вхождение needdle в haystack
/// \param haystack
/// \param needle
/// \return первое вхождение или  NULL
///
char *strstr_my(char *haystack, const char *needle)
{
    int pos, shift;

    if (needle[0] == '\0')
        return haystack;

    for (shift = 0; haystack[shift] != '\0'; shift++)
        for (pos = 0; haystack[pos + shift] == needle[pos]; pos++)
            if (needle[pos + 1] == '\0')
                return haystack + shift;

    return NULL;

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

///
/// \brief string_n_cat конкатенация строк с ограничением по символам
/// \param s1 первая строка
/// \param s2 вторая строка
/// \param n количество присоединяемых символов
/// \return первую с присоединенными n символами из второй
///
char*  string_n_cat(char *s1, const char *s2, size_t n)//прислать по почте
{
    char *cur = s1;
    while (*cur)
        cur++;


    for(size_t i = 0; i< n; i++) {
        //printf("'%s' - '%s'\n", cur, s2);
        *cur++ = *s2++;

    }

    *cur++ = '\0';


    return s1;
}
