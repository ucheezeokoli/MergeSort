CC = g++

all:
	$(CC) -std=c++11 -o a.exe MergeSort.cpp

clean:
	rm -f a.exe

