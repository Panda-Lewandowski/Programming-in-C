#include "func.h"
#include "time.h"
#define ELEM 1000
#define N 30
//функция сравнения двух значений v
//reverse v
//случай упоряд/неупоряд с повторамми v
//пустой v
//пара упорядоченных v
//замерять время много раз и выбирать среднее
//использовать статич массивы v
int main()
{
    int n = 0;
    int fc = 0;
    puts("GENERAL TEST\n");
    {
        int foo[] = {2, 5, 8, 71, 100};//sorted
        int* st = foo;

        int res[] = {2,5,8,71,100};

        fc = sort(st, 5, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 5, res, 5);
            if(n == 5)
                printf("Test #1 passed.\n");
            free(st);
        }
    }


    {
        int foo[] = {14, 3, 85, 5, 7};//unsorted
        int* st = foo;

        int res[] = {3, 5, 7, 14, 85};

        fc = sort(st, 5, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 5, res, 5);
            if(n == 5)
                printf("Test #2 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {2};
        int* st = foo;

        int res[] = {2};

        fc = sort(st, 1, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 1, res, 1);
            if(n == 1)
                printf("Test #3 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {2, 100};
        int* st = foo;

        int res[] = {2, 100};

        fc = sort(st, 2, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 2, res, 2);
            if(n == 2)
                printf("Test #4 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {100, 2};
        int* st = foo;

        int res[] = {2, 100};

        fc = sort(st, 2, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 2, res, 2);
            if(n == 2)
                printf("Test #5 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {100, 100};//sorted
        int* st = foo;

        int res[] = {100, 100};

        fc = sort(st, 2, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 2, res, 2);
            if(n == 2)
                printf("Test #6 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {'a', 'f', 's', 'a', 'g'};
        int* st = foo;

        int res[] = {'a', 'a', 'f', 'g', 's'};

        fc = sort(st, 5, sizeof(char), comp_char);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 5, res, 5);
            if(n == 5)
                printf("Test #7 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {2.4, 8.5, 1.5, 0.2, 0.256};
        int* st = foo;

        int res[] = {0.2, 0.256, 1.5, 2.4, 8.5};

        fc = sort(st, 5, sizeof(float), comp_float);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 5, res, 5);
            if(n == 5)
                printf("Test #8 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};//reverse
        int* st = foo;

        int res[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        fc = sort(st, 9, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 9, res, 9);
            if(n == 9)
                printf("Test #9 passed.\n");
        }
    }

    {
        int foo[] = {1.0, 1.1, 2.3, 2.3, 5.4, 8.6};//sorted with repeats
        int* st = foo;

        int res[] = {1.0, 1.1, 2.3, 2.3, 5.4, 8.6};

        fc = sort(st, 6, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 6, res, 6);
            if(n == 6)
                printf("Test #10 passed.\n");
            free(st);
        }
    }

    {
        int foo[] = {5, 2, 8, 7, 9, 8};//unsorted with repeats
        int* st = foo;

        int res[] = {2, 5, 7, 8, 8, 9};

        fc = sort(st, 6, sizeof(int), comp_int);

        if(fc != ALLOC_ERR)
        {
            n = compare(st, 6, res, 6);
            if(n == 6)
                printf("Test #11 passed.\n");
            free(st);
        }
    }

    {
        int* st = NULL;

        fc = sort(st, 0, sizeof(int), comp_int);

        if(fc == ERR)
        {
           printf("Test #12 passed.\n");
        }
    }

    puts("\n\nTIME TEST\n");
    unsigned long long tb, te;
    {
        puts("I. Sorted massive");
        FILE* f = fopen("sorted.txt", "w+");
        int* foo = malloc(sizeof(int) * ELEM);
        int* bar = malloc(sizeof(int) * ELEM);
        int* st = foo;
        int* ms = bar;
        for(int i = 0; i < ELEM; i++)
        {
            st[i] = i;
            ms[i] = i;
        }
        for(int i = 0; i < ELEM; i++)
        {
            fprintf(f, "%d\t", i+1);
            unsigned long long aver = 0;
            for(int j = 0; j < N; j++)
            {
                tb = tick();
                sort(st, i+1, sizeof(int), comp_int);
                te = tick();
                aver += (te-tb);
            }
            unsigned long long t1 = aver / N;
            fprintf(f, "%d\t", (int)t1);
            aver = 0;
            for(int j = 0; j < N; j++)
            {
                tb = tick();
                qsort(ms, i+1, sizeof(int), comp_int);
                te = tick();
                aver += (te-tb);
            }
            unsigned long long t2 = aver / N;
            fprintf(f, "%d\n", (int)t2);
            /*if(t1 < t2)
            {
                printf("%d elements:(bubble)%d  (qsort)%d\n", i+1, (int)t1, (int)t2);
            }*/
        }
        free(foo);
        free(bar);
        fclose(f);
    }

    {
        puts("II. Reversed massive");
        FILE* f = fopen("reversed.txt", "w+");
        int* foo = malloc(sizeof(int) * ELEM);
        int* bar = malloc(sizeof(int) * ELEM);
        int* st = foo;
        int* ms = bar;
        for(int i = ELEM; i > 0; i--)
        {
            st[ELEM - i] = i;
            ms[ELEM - i] = i;
        }
        for(int i = 0; i < ELEM; i++)
        {
            fprintf(f, "%d\t", i+1);
            unsigned long long aver = 0;
            for(int j = 0; j < N; j++)
            {
                tb = tick();
                sort(st, i+1, sizeof(int), comp_int);
                te = tick();
                aver += (te-tb);
            }
            unsigned long long t1 = aver / N;

            fprintf(f, "%d\t", (int)t1);
            aver = 0;
            for(int j = 0; j < N; j++)
            {
                tb = tick();
                qsort(ms, i+1, sizeof(int), comp_int);
                te = tick();
                aver += (te-tb);
            }
            unsigned long long t2 = aver / N;
            fprintf(f, "%d\n", (int)t2);
            /*if(t1 < t2)
            {
                printf("%d elements:(bubble)%d  (qsort)%d\n", i+1, (int)t1, (int)t2);
            }*/
        }
        free(foo);
        free(bar);
        fclose(f);
    }

    {
        srand(time(NULL));
        puts("III. Random massive");
        FILE* f = fopen("random.txt", "w+");
        int* foo = malloc(sizeof(int) * ELEM);
        int* bar = malloc(sizeof(int) * ELEM);
        int* st = foo;
        int* ms = bar;
        for(int i = 0; i < ELEM; i++)
        {
            int t = rand();
            st[i] = t;
            ms[i] = t;
        }
        for(int i = 0; i < ELEM; i++)
        {
            fprintf(f, "%d\t", i+1);
            unsigned long long aver = 0;
            for(int j = 0; j < N; j++)
            {
                tb = tick();
                sort(st, i+1, sizeof(int), comp_int);
                te = tick();
                aver += (te-tb);
            }
            unsigned long long t1 = aver / N;

            fprintf(f, "%d\t", (int)t1);
            aver = 0;
            for(int j = 0; j < N; j++)
            {
                tb = tick();
                qsort(ms, i+1, sizeof(int), comp_int);
                te = tick();
                aver += (te-tb);
            }
            unsigned long long t2 = aver / N;
            fprintf(f, "%d\n", (int)t2);
            /*if(t1 < t2)
            {
                printf("%d elements:(bubble)%d  (qsort)%d\n", i+1, (int)t1, (int)t2);
            }*/
        }
        free(foo);
        free(bar);
        fclose(f);
    }
    puts("\n\n<press ENTER to see analysis>");
    getchar();
    printf("Wait for a second....");
    system("time.xmcd");
    return 0;
}


