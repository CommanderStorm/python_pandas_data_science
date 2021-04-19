import time
import random
import numpy as np


def generate_random_list(d):
    data = []
    for _ in range(d):
        data.append(random.randint(0, 2147483647))
    return data


def summarize(benchmark_data):
    benchmarks = []
    for _ in range(100):
        start_time = time.time()
        sum(benchmark_data)
        benchmarks.append(time.time() - start_time)
    return benchmarks


def summarize_if(benchmark_data):
    benchmarks = []
    for _ in range(100):
        start_time = time.time()
        sum(filter(lambda x: x > 1073741823, benchmark_data))
        benchmarks.append(time.time() - start_time)
    return benchmarks


def remove_duplicates(benchmark_data):
    benchmarks = []
    for _ in range(100):
        start_time = time.time()
        set(benchmark_data)
        benchmarks.append(time.time() - start_time)
    return benchmarks


def np_summarize(benchmark_data):
    benchmarks = []
    arr = np.array(benchmark_data, dtype=np.int32)
    for _ in range(100):
        start_time = time.time()
        arr.sum()
        benchmarks.append(time.time() - start_time)
    return benchmarks


def np_summarize_if(benchmark_data):
    benchmarks = []
    arr = np.array(benchmark_data, dtype=np.int32)
    for _ in range(100):
        start_time = time.time()
        arr[arr < 500_000].sum()
        benchmarks.append(time.time() - start_time)
    return benchmarks


def np_remove_duplicates(benchmark_data):
    benchmarks = []
    arr = np.array(benchmark_data, dtype=np.int32)
    for _ in range(100):
        start_time = time.time()
        np.unique(arr)
        benchmarks.append(time.time() - start_time)
    return benchmarks


if __name__ == '__main__':
    benchmark_data = generate_random_list(10_000_000)
    long_benchmark = generate_random_list(100_000_000)
    benchmark_times = [
        summarize(long_benchmark),
        np_summarize(long_benchmark),
        summarize_if(benchmark_data),
        np_summarize_if(benchmark_data),
        remove_duplicates(benchmark_data),
        np_remove_duplicates(benchmark_data)
    ]
    print(benchmark_times)
