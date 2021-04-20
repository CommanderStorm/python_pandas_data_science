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

void summarize(int* arr)
{
    long sum = 0;
    for (long i = 0; i < BENCHMARK_LONG_REP; i++) {
        sum += arr[i];
    }
    if (sum == 0)
        exit(EXIT_FAILURE);
}

void summarize_if(int* arr)
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
    long len = BENCHMARK_REP;
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
    srand(time(NULL));
    struct timespec start;
    struct timespec end;
    for (int i = 0; i < 100; i++) {
        int* long_benchmark = generate_random_arr(BENCHMARK_LONG_REP);
        clock_gettime(CLOCK_MONOTONIC, &start);
        summarize(long_benchmark);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("c_summarize,%.10f\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        free(long_benchmark);
    }
    for (int i = 0; i < 100; i++) {
        int* benchmark_data = generate_random_arr(BENCHMARK_REP);
        clock_gettime(CLOCK_MONOTONIC, &start);
        summarize_if(benchmark_data);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("c_summarize_if,%.10f\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        free(benchmark_data);
    }

    for (int i = 0; i < 100; i++) {
        int* benchmark_data = generate_random_arr(BENCHMARK_REP);
        clock_gettime(CLOCK_MONOTONIC, &start);
        no_duplicate(benchmark_data);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("c_no_duplicate,%.10f\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        free(benchmark_data);
    }
    return EXIT_SUCCESS;
}