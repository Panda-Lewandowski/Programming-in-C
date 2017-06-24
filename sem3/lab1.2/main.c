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
    FILE *g;
    int rc = 0, fc;
    int *start;
    int *end;
    int n;
    if (argc < 3)
        {

            fprintf(stderr, "Error!  Must input at least 3 arguments!\n"); //недостаточное кол-во аргументов КС
            rc = NOT_GIVEN_FILE;
        }
        else
        {
            const char* in = argv[1];
            const char* out = argv[2];
            f = fopen(in, "r"); //открытие входного файла
            g = fopen(out, "w");

            if (f == NULL)
            {
                fprintf(stderr, "Error! Could not open %s. %s.\n", argv[1], strerror(errno)); //неудачное открытие файла
                rc = NON_EXISTENT_FILE;

            }
            else
            {
                if(g == NULL)
                {
                    fprintf(stderr, "Error! Could not open %s. %s.\n", argv[2], strerror(errno)); //неудачное открытие файла
                    rc = NON_EXISTENT_FILE;
                }
                else
                {
                    fc = fcount(f, &n);
                    if(fc == NO_DATA)
                    {
                        fprintf(stderr, "There are no data in file.\n");
                        rc = NO_DATA;
                    }
                    else
                    {
                        int* foo = malloc(n * sizeof(int));
                        start = foo;
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
                                fc = 0;
                                for(int i = 3; i < argc; i++)
                                {
                                    if(strcmp(argv[i], "-f") == 0)
                                    {
                                        int** ptr_start = &start;
                                        int** ptr_end = &end;
                                        fc = filter(ptr_start, ptr_end);
                                        if(fc == ERR)
                                        {
                                            fprintf(stderr, "Algorithm error.\n");
                                            rc = ERR;
                                        }
                                        else if(fc == ALLOC_ERR)
                                        {
                                            fprintf(stderr, "Allocation error.\n");
                                            rc = ALLOC_ERR;
                                        }

                                    }

                                    if(strcmp(argv[i], "-s") == 0)
                                    {
                                        n = count(start, end);
                                        fc = sort(start, n, sizeof(int), comp_int);
                                        if(fc == ALLOC_ERR)
                                        {
                                            fprintf(stderr, "Algorithm error.\n");
                                            rc = ALLOC_ERR;
                                        }
                                    }
                                }

                                if(fc == 0)
                                {
                                    write(g, start, end);
                                    puts("SUCCESS!\n");
                                }



                            }
                        }

                        //free(foo);
                        free(start);
                    }
                }


            }
            fclose(g);
            fclose(f);

            system("fc in.txt out.txt");
            puts("\n");


        }




        return rc;
}


