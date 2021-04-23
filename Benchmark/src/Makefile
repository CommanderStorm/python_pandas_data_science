CC=gcc
CFLAGS=-Ofast -Wall -Wextra -Wpedantic -march=native -flto -fwhole-program -pedantic

.PHONY: all
all: clean java python c_benchmark


.PHONY: c_benchmark
c_benchmark: main.c
	$(CC) $(CFLAGS) -o $@ $^
	./c_benchmark | tee -a benchmark.csv

.PHONY: clean
clean:
	rm -f *.o c_benchmark *.class benchmark.csv
	echo "label,n,time [s]">benchmark.csv

.PHONY: python
python:
	python3 main.py | tee -a benchmark.csv

.PHONY: java
java:
	javac Benchmark.java
	java Benchmark | tee -a benchmark.csv
