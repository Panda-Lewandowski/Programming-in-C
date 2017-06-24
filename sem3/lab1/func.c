#include "func.h"
///
/// \brief count
/// \details подсчитывает кол-во чисел в файле
/// \param f файл
/// \param n кол-во чисел
/// \return код ошибки или 0
///
int count(FILE *f, int *n)
{
    int i = 0, rc = 0, buf;

    while (fscanf(f, "%d", &buf) == 1)
    {
        i++;
    }

    if(i == 0)
        rc = NO_DATA;
    else
        rewind(f);

    *n = i;

    return rc;
}
///
/// \brief read
/// \details считывает эл-ты из  файла
/// \param f файл
/// \param start указатель на начало списка
/// \param end указатель за конец списка
/// \return код ошибки или 0
///
int read(FILE *f, int *start, int *end)
{
    int rc;



    while(fscanf(f, "%d", start) == 1 && start < end)
    {
        start++;
    }

    if(*start == *end)
        rc = 0;
    else
        rc = ERR;

    return rc;

}

///
/// \brief find
/// \details ищет максимальное по заданному принципу
/// \param start указатель на начало списка
/// \param end  указатель за конец списка
/// \param max переменная максимума
/// \return код ошибки или ноль
///
int find(int* start, int* end, int *max)
{
    int rc = 0, i = 0;//шрлрп

    if(*start == *end)
        rc = ERR;
    else
    {
        end -= 1;
        *max = *start + *end;
        while((end - start) >= 0)
        {
            if(*start + *end > *max)
                *max = *start + *end;
            start++;
            end--;
            i++;
        }
    }

    return rc;
}
