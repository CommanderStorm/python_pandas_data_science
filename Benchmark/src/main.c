#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BENCHMARK_NUM 20

int* generate_random_arr(long size)
{
    int* arr = malloc(sizeof(int) * size);
    for (long i = 0; i < size; i++) {
        arr[i] = rand();
    }
    return arr;
}

void summarize(int* arr, long len)
{
    long sum = 0;
    for (long i = 0; i < len; i++) {
        sum += arr[i];
    }
    if (sum < 0)
        exit(EXIT_FAILURE);
}

void summarize_if(int* arr, long len)
{
    long sum = 0;
    for (long i = 0; i < len; i++) {
        if (arr[i] > 1073741823)
            sum += arr[i];
    }
    if (sum < 0)
        exit(EXIT_FAILURE);
}

void no_duplicate(int* arr, long len)
{
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

    if (len < 0)
        exit(EXIT_FAILURE);
}

int main()
{
    srand(time(NULL));
    struct timespec start;
    struct timespec end;
    for (long benchmark_cnt = 10000000; benchmark_cnt < 1000000000; benchmark_cnt+=10000000) {
    for (int i = 0; i < BENCHMARK_NUM; i++) {
        int* benchmark_data = generate_random_arr(benchmark_cnt);
        clock_gettime(CLOCK_MONOTONIC, &start);
        summarize(benchmark_data,benchmark_cnt);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("c_summarize,%d,%.10f\n",benchmark_cnt, (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        free(benchmark_data);
    }
    for (int i = 0; i < BENCHMARK_NUM; i++) {
        int* benchmark_data = generate_random_arr(benchmark_cnt);
        clock_gettime(CLOCK_MONOTONIC, &start);
        summarize_if(benchmark_data,benchmark_cnt);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("c_summarize_if,%d,%.10f\n",benchmark_cnt, (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        free(benchmark_data);
    }
/**

    for (long benchmark_cnt = 100000; benchmark_cnt < 10000000; benchmark_cnt+=100000) {
    for (int i = 0; i < BENCHMARK_NUM; i++) {
        int* benchmark_data = generate_random_arr(benchmark_cnt);
        clock_gettime(CLOCK_MONOTONIC, &start);
        no_duplicate(benchmark_data, benchmark_cnt);
        clock_gettime(CLOCK_MONOTONIC, &end);
        printf("c_no_duplicate,%d,%.10f\n",benchmark_cnt, (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9);
        free(benchmark_data);
    }
  **/
    }
    return EXIT_SUCCESS;
}