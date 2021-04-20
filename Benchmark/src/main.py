import time
from typing import List

import numpy as np


def generate_random_list(list_len: int) -> List[int]:
    return generate_random_array(list_len).tolist()


def generate_random_array(list_len):
    return np.random.randint(low=0, high=2147483647, size=list_len, dtype=np.int32)


def summarize(benchmark_cnt):
    benchmarks = []
    for _ in range(100):
        benchmark_data = generate_random_list(benchmark_cnt)
        start_time = time.time()
        s = sum(benchmark_data)
        print(f"python_summarize,{(time.time() - start_time):.10f}")
        if s < 0:
            raise RuntimeError()
    return benchmarks


def summarize_if(benchmark_cnt):
    benchmarks = []
    for _ in range(100):
        benchmark_data = generate_random_list(benchmark_cnt)
        start_time = time.time()
        s = sum(filter(lambda x: x > 1073741823, benchmark_data))
        print(f"python_summarize_if,{(time.time() - start_time):.10f}")
        if s < 0:
            raise RuntimeError()
    return benchmarks


def no_duplicate(benchmark_cnt):
    benchmarks = []
    for _ in range(100):
        benchmark_data = generate_random_list(benchmark_cnt)
        start_time = time.time()
        a = set(benchmark_data)
        print(f"python_no_duplicate,{(time.time() - start_time):.10f}")
        if len(a) == 0:
            raise RuntimeError()
    return benchmarks


def np_summarize(benchmark_cnt):
    benchmarks = []
    for _ in range(100):
        arr = generate_random_array(benchmark_cnt)
        start_time = time.time()
        s = arr.sum()
        print(f"python_np_summarize,{(time.time() - start_time):.10f}")
        if s < 0:
            raise RuntimeError()
    return benchmarks


def np_summarize_if(benchmark_cnt):
    benchmarks = []
    for _ in range(100):
        arr = generate_random_array(benchmark_cnt)
        start_time = time.time()
        s = arr[arr < 500_000].sum()
        print(f"python_np_summarize_if,{(time.time() - start_time):.10f}")
        if s < 0:
            raise RuntimeError()
    return benchmarks


def np_no_duplicate(benchmark_cnt):
    benchmarks = []
    for _ in range(100):
        arr = generate_random_array(benchmark_cnt)
        start_time = time.time()
        a = np.unique(arr)
        print(f"python_np_no_duplicate,{(time.time() - start_time):.10f}")
        if len(a) == 0:
            raise RuntimeError()
    return benchmarks


if __name__ == '__main__':
    np_summarize(100_000_000)
    summarize(100_000_000)
    np_summarize_if(10_000_000)
    summarize_if(10_000_000)
    np_no_duplicate(10_000_000)
    no_duplicate(10_000_000)
