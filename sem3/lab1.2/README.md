## Лабораторная работа 1 (часть 1). Динамическая память, адресная арифметика.

    При решении задач в методических целях нельзя использовать выражение вида a[i] и 
    вообще квадратные скобки (только в этой лабораторной работе). Вместо него используется 
    выражение *pa, где pa - указатель на i-ый элемент массива (именно на i-ый элемент, а не 
    выражение вида *(pa + i)). Также нельзя передавать как аргумент размер массива в элементах, 
    если массив уже создан. Вместо этого предлагается использовать пару указателей: на первый элемент 
    массива и на элемент массива, расположенный за последним. Ситуация когда эти массивы совпадают, 
    означает пустоту обрабатываемого массива.
   
### :red_circle: Задача 1 

Написать программу, которая считывает из текстового файла целые числа в массив и выполняет обработку этого массива (см. распределение вариантов).
Память под массив выделяется динамически. Число элементов в массиве определяется в первом проходе по текстовому файлу, во время второго прохода числа считываются в массив.
Имя файла передается через параметры командной строки.

#### :large_blue_diamond: Варианты
 
1. :arrow_forward:Вычислить значение `max(x[0] + x[n-1], x[1] + x[n-2], x[2] + x[n-3], ..., x[(n-1)/2] + x[n/2])`, где `n` размер массива.
2. Вычислить значение `x[0]*y[0]+x[1]*y[1]+ ... + x[k]*y[k]`, где `x[i]` – отрицательные элементы массива a из n элементов, взятые в порядке их следования; `y[i]` – положительные элементы этого массива, взятые в обратном порядке; `k = min(p,q)`, где `p` – количество положительных элементов массива a, `q` – количество отрицательных элементов этого массива.
3. Вычислить значение `x[0] + x[0]*x[1] + x[0]*x[1]*x[2] + ... + x[0]*x[1]*x[2] ... x[m]`, где `x[i]` - элементы массива x из `n` элементов, `m` - индекс первого отрицательного элемента этого массива либо число `n-1`, если такого элемента в массиве нет.
4. Вычислить значение `min(x[0]*x[1], x[1]*x[2],x[2]*x[3], ..., x[n-3]*x[n-2], x[n-2]*x[n-1])`, где `x[i]` - элементы массива `x` из `n` элементов.
5. Найти количество различных чисел в файле.

### :red_circle: Задача 2 

Написать программу, которая упорядочивает массив.
Данные в массив считываются из файла (можно и нужно взять функцию чтения массива из предыдущей лабораторной работы). Полученный после сортировки массив записывается в файл.
Возможно, что перед сортировкой элементы массива могут быть отфильтрованы с помощью функции-фильтра.

Функция-фильтр работает следующим образом:
- определяет количество элементов массива, которые удовлетворяют заданному условию;
- выделяет память под соответствующее количество элементов;
- копирует элементы, удовлетворяющие условию, из старого массива в новый.
Функция сортировки реализуется универсальной (т.е. имеет одинаковый прототип с функцией qsort из стандартной библиотеки (stdlib.h)).

Все параметры (имена файлов, необходимость фильтрации) передаются через аргументы командной строки.
Для функции сортировки и функции-фильтра реализуются модульные тесты.

#### :large_blue_diamond: Алгоритмы сортировки 

1. Сортировка выбором: находится максимальный элемент массива и переносится в его конец; затем этот метод применяется ко всем элементам массива, кроме последнего (т.к. он уже находится на своем месте), и т.д.
2. Сортировка обменом (метод пузырька): последовательно сравниваются пары соседних элементов `x[k]` и `x[k+1] (k = 0, 1, … , n-2)` и, если `x[k] > x[k+1]`, то они переставляются; в результате наибольший элемент окажется на своем месте в конце массива; затем этот метод применяется ко всем элементам, кроме последнего, и т.д.
3. Сортировка вставками: пусть первые `k` элементов массива `(от 0 до k-1)` уже упорядочены по неубыванию; тогда берется `x[k]` и рaзмещается среди первых `k` элементов так, чтобы упорядоченными оказались уже `k+1` первых элементов; этот метод повторяется при `k от 1 до n-1`.
4. Модифицированная сортировка вставками. Для поиска места вставки нового элемента используется двоичный поиск.
5. Модифицированная сортировка пузырьком I. Запоминайте, где произошел последний обмен элементов, и при следующем проходе алгоритм не заходит за это место. Если последними поменялись i-ый и i+1-ый элементы, то при следующем проходе алгоритм не сравнивает элементы за i-м.
6. Модифицированная сортировка пузырьком II. Нечетные и четные проходы выполняются в противоположных направлениях: нечетные проходы от начала к концу, четные – от конца массива к его началу. При нечетных проходах большие элементы сдвигаются к концу массива, а при четных проходах – меньшие элементы двигаются к его началу.
7. Модифицированная сортировка пузырьком III. Идеи первой и второй модифицированной сортировки пузырьком объединяются.

#### :large_blue_diamond: Функция-фильтр 

В массиве остаются элементы

1. расположенные между минимальным и максимальным элементами массива;
2. от нулевого до m-го, где m - индекс первого отрицательного элемента этого массива либо число n-1, если такого элемента в массиве нет;
3. от нулевого до p-го, где p - индекс последнего отрицательного элемента этого массива либо число n-1, если такого элемента в массиве нет;
4. которые больше среднего арифметического всех элементов массива;
5. которые больше суммы элементов расположенных за ним.

### :red_circle: Замер времени 

Практически каждый процессор имеет специальный встроенный регистр - счетчик тактов, значение которого можно получить специальной командой процессора. Команда процессора `RDTSC` (Read Time Stamp Counter) возвращает в регистрах `EDX` и `EAX` 64-разрядное беззнаковое целое, равное числу тактов с момента запуска процессора. Вызвав эту команду до и после участка программы, для которого требуется вычислить время исполнения, можно вычислить разность показаний счетчика. Оно равно числу тактов, затраченных на исполнение замеряемого участка. Для перехода от числа тактов к времени требуется умножить число тактов на время одного такта (величина, обратная тактовой частоте процессора). Для процессора с тактовой частотой 1ГГц время такта - 1 нс.

Достоинством этого способа является максимально возможная точность измерения времени, недостатком - команда получения числа тактов зависит от архитектуры процессора.

Недостатки способа и подходы к борьбе с ними описаны в работе «Использование Time-Stamp Counter для измерения времени выполнения кода на процессорах с архитектурой Intel 64 и IA-32» Михаила Курносова.

```c
#include <stdio.h>

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

void test(void)
{
    long double test = 0.0;

    for(unsigned long long i = 0; i < 10000; i++)
        test += 0.5;
}

#define N 5

int main(void)
{
    unsigned long long tb, te;

    tb = tick();
    for(int i = 0; i < N; i++)
        test();
    te = tick();

    printf("test 'time': %llu\n", (te - tb) / N);

    return 0;
}
```