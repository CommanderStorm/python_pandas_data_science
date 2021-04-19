#include <stdio.h>
#include <time.h>
#define BENCHMARK_NUM 100
#define BENCHMARK_REP 1000000
#define BENCHMARK_LONG_REP 100000000

int *generate_random_arr(int size)
{
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
}

void sum(int *arr)
{
    long sum = 0;
    for (int i = 0; i < BENCHMARK_LONG_REP; i++)
    {
        sum += arr[i];
    }
}

void sum_if(int *arr)
{
    long sum = 0;
    for (int i = 0; i < BENCHMARK_REP; i++)
    {
        if (arr[i] > 1073741823)
            sum += arr[i];
    }
}

int *no_duplicate(int *arr)
{
    int len = BENCHMARK_REP;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < len; k++)
                {
                    arr[k] = arr[k + 1];
                }
                j--;
                len--;
            }
        }
    }
    return arr;
}

void main()
{
    int *benchmark_data = generate_random_arr(BENCHMARK_REP);
    int *long_benchmark = generate_random_arr(BENCHMARK_LONG_REP);
printf("[[");
    for (int i = 0; i < 100; i++)
    {
    clock_t begin = clock();
    sum(long_benchmark);
clock_t end = clock();
printf("%d, " ,(double)(end - begin) / CLOCKS_PER_SEC);
    }
printf("], [");
    for (int i = 0; i < 100; i++)
    {
    clock_t begin = clock();
    sum_if(benchmark_data);
clock_t end = clock();
printf("%d, " ,(double)(end - begin) / CLOCKS_PER_SEC);
    }

printf("], [");
    for (int i = 0; i < 100; i++)
    {
    clock_t begin = clock();
    no_duplicate(benchmark_data);
clock_t end = clock();
printf("%d, " ,(double)(end - begin) / CLOCKS_PER_SEC);
    }
printf("]]");
    free(benchmark_data);
    free(long_benchmark);
}