/*
1) Чтение строки из текстового файла. Строка должна читаться целиком (т.е. до символа EOL или EOF) за один проход. Реализация с помощью выделения большого буфера и чтения за один раз не принимается.
2) Замена в строке указанной непустой подстроки произвольной длины на другую подстроку произвольной длины (возможно пустую).

С помощью реализованных функций обработать текстовый файл, в котором выполнить замену всех вхождений указанной подстроки на заданную. Преобразованные строки записать в новый файл.

Пример.
В строке "aaaa" заменяем подстроку "aa" на "bbb". После замены получаем "bbbbbb".

Все параметры передаются как аргументы командной строки.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"


int main(int argc, char** argv)
{

    FILE* f;
    FILE* g;
    char* string;
    char* stringNew;
    int rc = 0;

    if (argc != 4)
    {
        fprintf(stderr, "Error!  Must input 3 arguments!\n"); //недостаточное кол-во аргументов КС
        rc = NOT_GIVEN_FILE;
    }
    else
    {
        f = fopen(argv[1],"r");
        g = fopen("out.txt","w");

        if (f == NULL)
        {

            fprintf(stderr, "Error! Could not open %s. %s.\n", argv[1], strerror(errno)); //неудачное открытие файла
            rc = NON_EXISTENT_FILE;

        }
        else if(g == NULL)
        {
            fprintf(stderr, "Error! Could not open %s. %s.\n", argv[2], strerror(errno)); //неудачное открытие файла
            rc = NON_EXISTENT_FILE;
        }
        else
        {
            if(BUFSIZE <= 1)
                puts("Please, change BUFSIZE!!It will be more than 1!\n\n");
            else
            {
                while((string = get_line(f)))
                {
                    //printf("'%s'", string);
                    stringNew = replace_line(string,argv[2],argv[3]);

                    fprintf(g,"%s",stringNew);
                    free(stringNew);
                    free(string);
                }
                free(string);
                puts("Success!");
            }


        }
        fclose(f);
        fclose(g);
    }
    return rc;
}
