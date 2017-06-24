#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "func.h"
//-s -r -f -i

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

        fprintf(stderr, "Error!  Must input at least names of input and output files!\n"); //недостаточное кол-во аргументов КС
        rc = NOT_GIVEN_FILE;
    }
    else
    {
        FILE* f;
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            fprintf(stderr, "Error! Could not open %s. %s.\n", argv[1], strerror(errno)); //неудачное открытие файла
            rc = NON_EXISTENT_FILE;

        }
        else
        {
            element *head = form_list(f);

            for(int i = 2; i < argc-1; i++)
            {
                if(strcmp(argv[i], "-sn") == 0)
                {
                    if(head)
                    {
                        head = insert_sort(head, comp_elem_num);
                    }
                    else
                        print_list(head);

                    if(i == argc-2)
                        break;
                    i++;
                }

                if(strcmp(argv[i], "-sm") == 0)
                {
                    if(head)
                    {
                        head = insert_sort(head, comp_elem_name);
                    }
                    else
                        print_list(head);
                    //print_list(head);
                    if(i == argc-2)
                        break;
                    i++;


                }

                if(strcmp(argv[i], "-r") == 0)
                {
                    if(head)
                    {
                        head = reverse_list(head);
                    }
                    else
                        print_list(head);

                    if(i == argc-2)
                        break;
                    i++;
                }

                if(strcmp(argv[i], "-f") == 0)
                {
                    if(head)
                    {
                        char* name = argv[i+1];
                        int num = a_to_i(argv[i+2]);
                        element* foo = create_element(name, num);
                        element* find = find_elem(head, foo, comp_elem);
                        if(find)
                            printf("\n>Magazine '%s' #%d have found.\n", name, num);
                        else
                            printf("\n>Magazine '%s' #%d have not found.\n", name, num);

                        free_list(&foo);
                    }
                    else
                        print_list(head);

                    if(i == argc-2)
                        break;
                    i += 2;
                }

                if(strcmp(argv[i], "-i") == 0)
                {
                    if(head)
                    {
                        char* name = argv[i+1];
                        int num = a_to_i(argv[i+2]);
                        element* foo = create_element(name, num);
                        element* here = create_element(argv[i+3], a_to_i(argv[i+4]));
                        element* find = find_elem(head, here, comp_elem);
                        if(find)
                        {
                            head = insert(head, foo, find);
                            printf("\n>Magazine '%s' #%d was insert before '%s' #%d.",
                                   ELEM_TO_DATA(foo)->name,  ELEM_TO_DATA(foo)->number,  ELEM_TO_DATA(find)->name,  ELEM_TO_DATA(find)->number);
                        }
                        else
                        {
                            printf("\n>Magazine '%s' #%d have not finded.\n", name, num);
                            free_list(&foo);
                        }



                        free_list(&here);
                    }
                    else
                        print_list(head);

                    if(i == argc-2)
                        break;
                    i += 4;
                }

            }

            //print_list(head);


            FILE* g;
            g = fopen(argv[argc-1], "w");
            if (g == NULL)
            {
                fprintf(stderr, "Error! Could not open %s. %s.\n", argv[argc-1], strerror(errno)); //неудачное открытие файла
                rc = NON_EXISTENT_FILE;

            }
            else
            {
                fprint_list(head, g);
            }


            printf("\nFreeing...\n");
            free_list(&head);
            //print_list(head);
        }
    }

    return rc;

}
