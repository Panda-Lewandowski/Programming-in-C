/*Разработайте программу, которая вводит из файла, имя которого
 *  определяется
 * в командной строке, числа и помещает их в линейный односвязный
 * список так,
 *  чтобы элементы его составляли возрастающую последовательность.
 * Затем вводится
 * число со стандартного потока ввода и вставляется в соответствующее
 * место списка.
 *  Числа из списка записать в файл, имя которого определяется
 * в командной строке.*/
//тесты vv
//функция вставки числа в список vv
//в инсерт энд исп афтер vv
//функция создания списка по массиву vv
//функ сравнения списка с массива либо с списком vv
//atoi заменить vv
//функции вставки в список должны обр ошибку vv
// убрать отдельное создание головы vv
#include "list.h"

///
/// \brief main
/// \param argc
/// \param argv
/// \return Code error or 0
///
int main(int argc, char** argv)
{
    FILE *f;
    int rc = 0, buf, fc;
    FILE *g;
    list_node *head = NULL;

    if (argc != 4)
    {
        fprintf(stderr, "Error!  Must input 3 arguments!\n"); //недостаточное кол-во аргументов КС
        rc = NOT_GIVEN_FILE;
    }
    else
    {
        f = fopen(argv[1], "r"); //открытие входного файла
        g = fopen(argv[2], "w");

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

           while ((fc = fscanf(f, "%d", &buf)) == 1)
           {
                if(head == NULL)
                    head = node_create(buf);
                else
                    head = insert(head, buf);
                if(!head)
                {
                    fprintf(stderr, "Allocation is not successful!\n");
                    rc = ERROR;
                    break;
                }
           }
           if(fc == 0)
           {
               rc = NO_DATA;
           }
           else
           {
               head = insert(head, a_to_i(argv[3]));

               if(!head)
               {
                   fprintf(stderr, "Allocation is not successful!\n");
                   rc = ERROR;
               }
               else
               {
                   while (head)
                    {
                        fprintf(g, "%d ", head->data);
                        head = head->next;
                    }

                    printf("Success. Please, open %s.", argv[2]);
                }

                destroy(head);
            }

        }

        fclose(f);
        fclose(g);
    }

    return rc;
}


