#include "func.h"
//#define  DEBUG

//в сортировке не использовать выражение вида база+и*размер
//переписать фильтр
//в сортировке проверять свап на выделение памчяти
///
/// \brief count
/// \details подсчитывает кол-во чисел в файле
/// \param f файл
/// \param n кол-во чисел
/// \return код ошибки или 0
///
int fcount(FILE *f, int *n)
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

    if(start == end)
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
    int rc = 0, i = 0;

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
/// \details ПЕРВАЯ ВЕРСИЯ
/// \brief filt фильтрует массив, оставляя в нем элементы, которое бoльше суммы элементов за ним
/// \param start указатель на начало массива
/// \param end указатель за конец массива
/// \return код ошибки или ноль
///
int filt(int **start, int **end)
{
    int rc = 0;


    if(*start >= *end)
        rc = ERR;
    else
    {
         //int* middle = *start + ((int)(*end - *start)/2);//серединка

#ifdef DEBUG
         assert(middle < start);
#endif

         int *ptr = *start;
         int sum = 0;
         do//вычислем общую сумму
         {
             sum += *ptr;
             ptr++;
         }
         while(ptr != *end);

         ptr = *start;
         while(ptr != *end)
         {
             sum -= *ptr;
             if(*ptr < sum)
             {
                 //(ptr <= middle)
                     *start = del_right(ptr, *start);
                 //else if(ptr > middle)
                     //*end = del_left(ptr, *end);

             }

             ptr++;


         }

         //вычисляем сумму перед текущем элементом
         //удаляя его из общей суммы
         //если он меньше суммы удаляем его:
         //если он в первой половине подтягиваем начало
         //если он во втoрой половине подтягиваем конец

    }

    return rc;

}
/// \details НЕ ОСВОБОЖДАЕТ ПАМЯТЬ
/// \brief del_right удаляет элемент в списке, "подтягивая" элементы стоящие перед ним
/// \param elem удаляемый элемент
/// \param start указател на начало массива
/// \return новый указатель на начало массива
///
int* del_right(int *elem, int* start)
{
    //int* ff = start;
    int* tmp = elem - 1;

    while(tmp != start - 1)
    {
        *(elem) = *(tmp);
        tmp--;
        elem--;

    }
    start++;
    //free(ff);//тут проблемы с доктором
    return start;

}
/// \details НЕ ОСВОБОЖДАЕТ ПАМЯТЬ
/// \brief del_left удаляет элемент в списке, "подтягивая" элементы стоящие за ним
/// \param elem удаляемый элемент
/// \param end указатель за конец массива
/// \return новый указатель на конец массива
///
int* del_left(int* elem, int* end)
{
    int* tmp = elem + 1;

    while(tmp <= end + 1)
    {
        *(elem) = *(tmp);
        tmp++;
        elem++;
    }

    end--;
    return end;
}

///
/// \brief comp_int  функция сравнения двух чисел типа int
/// \param const void *p константный указатель на первое число
/// \param const void *q константный указатель на второе число
/// \return   Если p меньше, чем q, то возвращается значение меньше 0.
///           Если p равно q, то возвращается 0.
///           Если p больше, чем q, то возвращается величина больше 0.;
///
int comp_int(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    int res = *a - *b;
    if (res > 0)
      return MORE;
    else if(res == 0)
      return 0;
    else
      return LESS;
}

///
/// \brief comp_char функция сравнения двух символов
/// \param const void *p константный указатель на первый символ
/// \param const void *q константный указатель на второй символ
/// \return   Если p меньше, чем q, то возвращается значение меньше 0.
///           Если p равно q, то возвращается 0.
///           Если p больше, чем q, то возвращается величина больше 0.;
///
///
int comp_char(const void* p,const void* q)
{
  const char *a = p;
  const char *b = q;
  char res = *a - *b;
  if (res > 0)
    return MORE;
  else if(res == 0)
    return 0;
  else
    return LESS;
}

///
/// \brief comp_float функция сравнения двух чисел типа float
/// \param const void *p константный указатель на первое число
/// \param const void *q константный указатель на второе число
/// \return   Если p меньше, чем q, то возвращается значение меньше 0.
///           Если p равно q, то возвращается 0.
///           Если p больше, чем q, то возвращается величина больше 0.;
///
int comp_float(const void* p, const void* q)
{
    const float *a = p;
    const float *b = q;
    float res = *a - *b;
    if (res > 0)
      return MORE;
    else if(res == 0)
      return 0;
    else
      return LESS;
}

///
/// \brief sort функция сортировки массива
/// \param base массив
/// \param num кол-во элементов в массиве
/// \param size
/// \param compare
///
int sort(void *base, size_t num, size_t size,
          int (*compare) (const void *, const void *))
{
#ifdef DEBUG
    assert(num > 0);
#endif

    if(!base)
        return ERR;

    void *t = malloc(size);


    if (t == NULL)
        return ALLOC_ERR;

    int s = 1;

    int stop_forward = 0;
    int stop_back = num-1;

    while(s)
    {
        s = 0;
        char* cur_frd = (char*)base + stop_forward*size;

        for(int i = stop_forward; i < num-1; i++)//вперед
        {
            /*if ((*compare)((char*)base + i * size, (char*)base + (i + 1) * size) > 0)
            {
                swap((char*)base + i * size, (char*)base + (i + 1) * size, size);
                s = 1;
                stop_back = i;
            }*/

            if ((*compare)(cur_frd, cur_frd+size) > 0)
            {

                //swap(cur_frd, cur_frd+size, size);
                memcpy(t, cur_frd, size);
                memcpy(cur_frd, cur_frd+size, size);
                memcpy(cur_frd+size, t, size);
                s = 1;
                stop_back = i;
            }

            cur_frd += size;

        }

        if(s)
        {
            char* cur_bck = (char*)base + stop_back*size;
            for(int j = stop_back; j > 0; j--)//назад
            {
                /*if ((*compare)((char*)base + j * size, (char*)base + (j - 1) * size) < 0)
                {
                    swap((char*)base + j * size, (char*)base + (j - 1) * size, size);
                    s = 1;
                    stop_forward = j;

                }*/

                if ((*compare)(cur_bck, cur_bck-size) < 0)
                {
                    //swap(cur_bck, cur_bck-size, size);
                    memcpy(t, cur_bck, size);
                    memcpy(cur_bck, cur_bck-size, size);
                    memcpy(cur_bck-size, t, size);
                    s = 1;
                    stop_forward = j;
                }

                cur_bck -= size;

            }
        }

        /*char* ptr = base;
        while(ptr != (char*)base + num*size)
        {
            printf("%d  ", *ptr);
            ptr += size;
        }
        printf("\n");*/

    }
    free(t);
    return 0;

}


///
/// \brief swap меняет местами две области памяти
/// \param p указатель на первую область
/// \param q указатель на вторую область
/// \param size размер областей памяти
/// \return код ошибки или 0
///
int swap(void* p, void* q, size_t size)
{
    void *t = malloc(size);//динамическ массив не создавать постоянно новую перемкнную

    if (t == NULL)
        return ALLOC_ERR;

    memcpy(t, p, size);
    memcpy(p, q, size);
    memcpy(q, t, size);

    free(t);
    return 0;

}
/// \details  ВТОРАЯ ВЕРСИЯ
/// \brief filter фильтрует массив, оставляя в нем элементы, которое бoльше суммы элементов за ним
/// \param start указатель на начало массива
/// \param end указатель за конец массива
/// \param n кол-во оставшихся элемнтов
/// \return указатель на начало нового массива или NULL
///
int filter(int** start, int** end)
{


    if(*start >= *end)
        return ERR;
    else
    {
         int *ptr = *start;
         int sum = 0;
         do//вычисляем общую сумму
         {
             sum += *ptr;
             ptr++;
         }
         while(ptr != *end);

         ptr = *start;
         int item = 0;
         int buf_sum = sum;
         while(ptr != *end)
         {
             buf_sum -= *ptr;
             if(*ptr >= buf_sum)
             {
                 item++;
             }

             ptr++;
         }
         if(item)
         {
             int* st = malloc(item * sizeof(int));

             if(!st)
                 return ALLOC_ERR;

             ptr = *start;
             int* ptr_st = st;
             while(ptr != *end)
             {
                 sum -= *ptr;
                 if(*ptr >= sum)
                 {
                     *ptr_st = *ptr;
                     ptr_st++;

                 }

                 ptr++;
             }

             *start = st;
             *end  = st + item;

         }
    }
    return 0;

}

///
/// \brief tick
/// \return
///
unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}
///
/// \brief count
/// \param start
/// \param end
/// \return
///
int count(int* start, int* end)
{
    if(start >= end)
        return ERR;
    else
    {
       int i = 0;
       while(start != end)
       {
           i++;
           start++;
       }
       return i;
    }


}
///
/// \brief write
/// \param f
/// \param start
/// \param end
/// \return
///
int write(FILE *f, int *start, int *end)
{
    int rc;
    if(start == end)
        rc = ERR;
    else
        rc = 0;

    while(start != end)
    {
        fprintf(f, "%d ", *start);
        start++;
    }



    return rc;

}
///
/// \brief compare
/// \param start
/// \param n
/// \param test
/// \param m
/// \return
///
int compare(int* start, int n,int* test, int m)
{
    int i = 0;
    if(n < m)
        return -1;
    else
    {
        int* ptr = start;
        while(ptr != start+n)
        {
            if(*ptr == *test)
                i++;
            ptr++;
            test++;
        }

        return i;
    }

}
