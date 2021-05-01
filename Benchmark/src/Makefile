CC=gcc
CFLAGS=-O3 -Wall -Wextra -Wpedantic -pedantic -std=gnu99 -march=native -flto -fwhole-program

.PHONY: all
all: clean c_benchmark java python


.PHONY: c_benchmark
c_benchmark: main.c
	$(CC) $(CFLAGS) -o $@ $^
	./c_benchmark | tee -a ../../Data/benchmark.csv

.PHONY: clean
clean:
	rm -f *.o c_benchmark *.class benchmark.csv
	echo "label,n,time [s]">../../Data/benchmark.csv

.PHONY: python
python:
	python3 main.py | tee -a ../../Data/benchmark.csv

.PHONY: java
java:
	javac Benchmark.java
	java Benchmark | tee -a ../../Data/benchmark.csv
