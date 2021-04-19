#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BENCHMARK_NUM 10
#define BENCHMARK_REP 10000000
#define BENCHMARK_LONG_REP 100000000

int* generate_random_arr(long size)
{
    int* arr = malloc(sizeof(int) * size);
    for (long i = 0; i < size; i++) {
        arr[i] = rand();
    }
    return arr;
}

void sum(int* arr)
{
    long sum = 0;
    for (long i = 0; i < BENCHMARK_LONG_REP; i++) {
        sum += arr[i];
    }
    if (sum == 0)
        exit(EXIT_FAILURE);
}

void sum_if(int* arr)
{
    long sum = 0;
    for (long i = 0; i < BENCHMARK_REP; i++) {
        if (arr[i] > 1073741823)
            sum += arr[i];
    }
    if (sum == 0)
        exit(EXIT_FAILURE);
}

void no_duplicate(int* arr)
{
    int len = 100;
    for (long i = 0; i < len; i++) {
        for (long j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                for (long k = j; k < len; k++) {
                    arr[k] = arr[k + 1];
                }
                j--;
                len--;
            }
        }
    }

    if (len == BENCHMARK_REP)
        exit(EXIT_FAILURE);
}

int main()
{
    struct timespec start;
    struct timespec end;
    printf("[[");
    for (int i = 0; i < 100; i++) {
        int* long_benchmark = generate_random_arr(BENCHMARK_LONG_REP);
        clock_gettime(CLOCK_MONOTONIC, &start);
        sum(long_benchmark);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("%f", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        if (i + 1 < 100)
            printf(", ");
        free(long_benchmark);
    }
    printf("],\n[");
    for (int i = 0; i < 100; i++) {
        int* benchmark_data = generate_random_arr(BENCHMARK_REP);
        clock_gettime(CLOCK_MONOTONIC, &start);
        sum_if(benchmark_data);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("%f", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        if (i + 1 < 100)
            printf(", ");
        free(benchmark_data);
    }
    printf("],\n[");
    for (int i = 0; i < 100; i++) {
        int* benchmark_data = generate_random_arr(BENCHMARK_REP);
        clock_gettime(CLOCK_MONOTONIC, &start);
        no_duplicate(benchmark_data);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("%f", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        if (i + 1 < 100)
            printf(", ");
        free(benchmark_data);
    }
    printf("]]\n");
    return EXIT_SUCCESS;
}