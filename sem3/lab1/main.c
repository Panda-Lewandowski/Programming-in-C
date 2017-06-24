#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "func.h"


/*!
 * \brief main
 * Основная функция.
 * \param argc Кол-во аргументов комадной строки
 * \param argv Массив аргументов комадной строки
 * \return Код ошибки или 0
 */

int main(int argc, char** argv)
{
    FILE *f;
    int rc, fc;
    int *start;
    int *end;
    int n, max;
    if (argc != 2)
        {

            fprintf(stderr, "Error!  Must input 2 arguments!\n"); //недостаточное кол-во аргументов КС
            rc = NOT_GIVEN_FILE;
        }
        else
        {
            f = fopen(argv[1], "r"); //открытие входного файла

            if (f == NULL)
            {
                fprintf(stderr, "Error! Could not open %s. %s.\n", argv[1], strerror(errno)); //неудачное открытие файла
                rc = NON_EXISTENT_FILE;

            }
            else
            {
                fc = count(f, &n);
                if(fc == NO_DATA)
                {
                    fprintf(stderr, "There are no data in file.\n");
                    rc = NO_DATA;
                }
                else
                {
                    start = calloc(n, sizeof(int));
                    if(start == NULL)
                    {
                        fprintf(stderr, "Allocation error.\n");
                        rc = ALLOC_ERR;
                    }
                    else
                    {
                        end = start + n;
                        fc = read(f, start, end);
                        if(fc == ERR)
                        {
                            fprintf(stderr, "Algorithm error.\n");
                            rc = ERR;
                        }
                        else
                        {
                            //start = end - n;
                            fc = find(start, end, &max);
                            if(fc == ERR)
                            {
                                fprintf(stderr, "Finding error.\n");
                                rc = ERR;
                            }
                            else
                                printf("The maximum sum of pairs is %d.", max);
                        }
                    }

                    free(start);
                }
            }

            fclose(f);
        }




        return rc;
}


