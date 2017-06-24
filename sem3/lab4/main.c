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
    int rc = 0;
    if (argc < 3)
    {

        fprintf(stderr, "Error!  Must input at least 3 arguments!\n"); //недостаточное кол-во аргументов КС
        rc = NOT_GIVEN_FILE;
    }
    else
    {

        for(int i = 1; i < argc; i++)
        {
            if(strcmp(argv[i], "-s") == 0)
            {
                FILE* f;
                FILE* g;
                f = fopen(argv[i+1], "r+");
                if (f == NULL)
                {
                    fprintf(stderr, "Error! Could not open %s. %s.\n", argv[i+1], strerror(errno)); //неудачное открытие файла
                    rc = NON_EXISTENT_FILE;

                }
                else
                {
                    g = fopen(argv[i+2], "r+");
                    if (g == NULL)
                    {
                        fprintf(stderr, "Error! Could not open %s. %s.\n", argv[i+2], strerror(errno)); //неудачное открытие файла
                        rc = NON_EXISTENT_FILE;

                    }
                    else
                    {
                        int na, ma, nb, mb;
                        float** mtr_a = fread_matr(f, &na, &ma);
                        float** mtr_b = fread_matr(g, &nb, &mb);

                        float** res = add(mtr_a, mtr_b, na, ma, nb, mb);
                        if(!res)
                            printf("The addition cannot be done, matrices has different sizes!.\n");
                        else
                        {
                            FILE* l;
                            l = fopen("add_result.txt", "w+");
                            if(l)
                                fprint_matr(l, res, na, ma);
                            else
                                fprintf(stderr, "Error! Could not open %s. %s.\n", "add_result.txt", strerror(errno));
                            i += 2;
                            free(res);
                            fclose(l);
                        }

                        free(mtr_a);
                        free(mtr_b);
                        fclose(f);
                        fclose(g);

                        printf("See addition result in add_result.txt\n");

                    }
                }
            }

            if(strcmp(argv[i], "-m") == 0)
            {
                FILE* f;
                FILE* g;
                f = fopen(argv[i+1], "r+");
                if (f == NULL)
                {
                    fprintf(stderr, "Error! Could not open %s. %s.\n", argv[i+1], strerror(errno)); //неудачное открытие файла
                    rc = NON_EXISTENT_FILE;

                }
                else
                {
                    g = fopen(argv[i+2], "r+");
                    if (g == NULL)
                    {
                        fprintf(stderr, "Error! Could not open %s. %s.\n", argv[i+2], strerror(errno)); //неудачное открытие файла
                        rc = NON_EXISTENT_FILE;

                    }
                    else
                    {
                        int na, ma, nb, mb;
                        float** mtr_a = fread_matr(f, &na, &ma);
                        float** mtr_b = fread_matr(g, &nb, &mb);

                        float** res = multi(mtr_a, mtr_b, na, ma, nb, mb);
                        if(!res)
                            printf("The multiplication cannot be done, matrices has different sizes!.\n");
                        else
                        {
                            FILE* l;
                            l = fopen("multi_result.txt", "w+");
                            if(l)
                                fprint_matr(l, res, na, mb);
                            else
                                fprintf(stderr, "Error! Could not open %s. %s.\n", "add_result.txt", strerror(errno));
                            i += 2;
                            free(res);
                            fclose(l);
                        }

                        free(mtr_a);
                        free(mtr_b);
                        fclose(f);
                        fclose(g);

                        printf("See multiplication result in multi_result.txt\n");

                    }
                }
            }

            if(strcmp(argv[i], "-d") == 0)
            {
                FILE* f;
                f = fopen(argv[i+1], "r+");
                if (f == NULL)
                {
                    fprintf(stderr, "Error! Could not open %s. %s.\n", argv[i+1], strerror(errno)); //неудачное открытие файла
                    rc = NON_EXISTENT_FILE;

                }
                else
                {
                    int n, m;
                    float** mtr = fread_matr(f, &n, &m);

                    float det = determinant(mtr, n);

                    printf("Determinant of matrix from %s is %.3f.\n", argv[i+1], det);

                    free(mtr);
                    fclose(f);



                }
            }
        }
    }

    return rc;
}
