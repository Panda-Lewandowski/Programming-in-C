/*! \brief Постановка задачи.

 \details Написать программу, которая считывает из
   текстового файла вещественные числа и
записывает их  в массив. Далее на основе этого массива формирует второй по принципу:
в новый массив попадают числа больше их среднего арифметического.
Новый массив записывается в новый файл.



 \author Daria Shcherbatyuk, 2016
 */


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
    FILE *f;  ///< Входной файл
    FILE *g; ///< Выходной файл
    int rc, n, m, fc; ///< код ошибки программы, размерность массивов, код ошибки функций
    float av; ///< ср ариф
    float a[MAX_N], b[MAX_N]; ///< Новый и старый массив


    if (argc != 3)
    {

        fprintf(stderr, "Error!  Must input 3 arguments!\n"); //недостаточное кол-во аргументов КС
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
            g = fopen(argv[2], "w"); //открытие на запись выходного файла

            if (g != NULL)
            {

                fc = read(f, a, MAX_N, &n); //чтение значений в массив
                //printf("%d", fc);

                if (fc != REPLETION && fc != NO_DATA)
                {
                    average(a,n, &av); //вычисленре ср ариф

                    if (create(av, b, a, MAX_N, &m, n) != REPLETION) //составление нового массива
                    {
                        if (write(g, b, m) != WRITE_ERROR) //запись нового массива в файл
                        {
                            printf("OK.See the results in the file %s ", argv[2]);
                            rc = 0;
                        }
                        else
                        {
                            printf("Not OK. Can't write array B  to file.");
                            rc = WRITE_ERROR;
                        }

                    }
                    else
                    {
                        printf("Not OK. Array  B overflow.");
                        rc = REPLETION;
                    }
                }
                else
                {
                    if (fc == NO_DATA)
                    {
                        printf("Not OK. There is no data.");
                        rc = NO_DATA;
                    }
                    else
                    {
                        printf("Not OK. Array A overflow.");
                        rc = REPLETION;
                    }
                }


                fclose(g);
            }
            else
            {
                fprintf(stderr, "Error! Could not open %s. %s.\n", argv[2], strerror(errno)); //неудачное открытие файла
                rc = NON_EXISTENT_FILE;
            }

            //fclose(g);

            fclose(f);
        }

        //fclose(f);
    }
    return rc;
}
