/*! \defgroup func Модуль с функциями
 *
 * \brief Содержит функции read, write, create, average
 *
 * \details Выполняет основные вычисления: ср.ариф.,
 * чтение значений в массив, создание нового массива, запись нового массива в файл
 *
 * \author Daria Shcherbatyuk, 2016
 */




#include "func.h"

/*!
 * \brief read
 * Функция для чтение элементов массива с файла
 * \param *f указатель входного файла
 * \param а массив для записи
 * \param max_n максимальное кол-во элеметнов
 * \param *n указатель на реальное кол-во эл-тов
 * \return код ошибки или 0
 */
int read(FILE *f,float a[], int max_n, int *n)
{
    int i = 0, fc, rc;

    while ((fc = fscanf(f, "%f", &a[i])) == 1 && i+1 <= max_n)
    {

        i++;

    }
         //чтение элементов

    if (fc == 1 && i+1 > max_n)//если вышли за пределы допустимого размера(20)
    {

        *n = max_n;
        rc = 0;
    }
    else if (i == 0)//данных нет
    {

        *n = 0;
        rc = NO_DATA;
    }
    else
    {
        //printf("%d\n", i);
        *n = i;
        rc = 0;

    }
    //printf("\n");
    return rc;
}


//фактическая размерность и предполагаемая размерность массива на выход
// совадают, они равны фактической размерности массива на вход

/*!
 * \brief write
 * Функция для записи массива в файл
 * \param b[] массив
 * \param g выходной файл
 * \param m кол-во эл-тов
 * \return код ошибки или 0
 */
int write(FILE *g, const float b[], const int m)
{
    int i = 0, rc, fc = 1;

    while((fc = fprintf(g, "%.3f   ", b[i++])) != EOF && i < m);//печать эл-тов

    //printf("%d  ", i);
    if (fc == EOF || i > m)//если не удалась печать или превышенно доп.кол-во
        rc = WRITE_ERROR;
    else
        rc = 0;

    return rc;

}



/*!
 * \brief average
 * Функция для нахождения среднего арифметического
 * \param av среднее арифметичское
 * \param a[] массив
 * \param n размер массива
 * \return код ошибки или 0
 */
int average(const float a[], int n, float *av)
{
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        //printf("%d   ", n);
        sum += a[i];//подсчет суммы

    }

    assert(n != 0);
    *av = sum / n; //вычисление ср ариф
    return 0;
}

/*!
 * \brief create
 * Функция для составления нового массива из старого
 * \param av среднее арифметичское
 * \param a[] исходный массив
 * \param
 * \return код ошибки или 0
 */
int create(float av, float b[], const float a[], int max_n, int *m, const int n)
{
    int rc, j = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= av && j < max_n)
        {
            b[j] = a[i];
            //printf("%f  ", a[i]);
            j++;

        }
    }


    if (j >  max_n)
        rc = REPLETION;
    else
    {
        rc = 0;
        *m = j;
    }
    //printf("m= %d, n= %d", *m, *n);
    return rc;

}

int compare(const float a[], const float b[], int n)
{
    int k = 1, rc;

    for (int i = 0; i < n; i++)
    {
        if ((a[i] - b[i])  > 0.000001)
            k = 0;
    }

    if(k)
    {
        //printf("There are same arrays.\n");
        rc = 0;
    }
    else
    {
        //printf("There are not same arrays.\n");
        rc = -1;
    }

    return rc;


}
