CC=gcc
CFLAGS=-Ofast -Wall -Wextra -Wpedantic -march=native -flto -fwhole-program -pedantic

.PHONY: all
all: c_benchmark python java


.PHONY: c_benchmark
c_benchmark: main.c
	$(CC) $(CFLAGS) -o $@ $^
	echo "C-Code:"
	./c_benchmark

.PHONY: clean
clean:
	rm -f *.o c_benchmark *.class

.PHONY: python
python:
	echo "python3-Code:"
	python3 main.py

.PHONY: java
java:
	echo "java-Code:"
	javac Benchmark.java
	java Benchmark
