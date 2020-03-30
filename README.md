# DSSC - Algorithmic Design - Sorting Algorithms
This repository contains some code to simplify the implementation and testing of sorting algorithms. The code in this repository natively support insertion sort, quick sort, bubble sort, selection sort, and heap sort, but other algorithms can easily be added by editing the main function in the file [main.c](main.c).

In order to test the differences in term of execution-time between the sorting algorithms, you need to implement all of them. The insertion sort algorithm must be implemented in the file [insertion_sort.c](insertion_sort.c) according to the API defined in [insertion_sort.h](insertion_sort.h); the quick sort algorithm in the file [quick_sort.c](quick_sort.c) and, so forward, for all the algorithms.


A Makefile can be produced by using [cmake](https://cmake.org/) as follows:
```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```
Afterwards you can compile the code by executing `make`. This produces an executable named `test_sorting` which can be executed in POSIX systems by using the command:
```bash
./test_sorting
Size	Insertion Sort	Quick Sort	Bubble Sort	Selection Sort	Heap Sort
2**0	0.000000	0.000000	0.000000	0.000000	0.000000
2**1	0.000000	0.000000	0.000000	0.000000	0.000000
2**2	0.000000	0.000000	0.000000	0.000000	0.000000
2**3	0.000000	0.000000	0.000000	0.000000	0.000000
2**4	0.000000	0.000000	0.000000	0.000000	0.000000
2**5	0.000000	0.000000	0.000000	0.000000	0.000000
2**6	0.000000	0.000000	0.000000	0.000000	0.000000
2**7	0.000000	0.000000	0.000000	0.000000	0.000000
2**8	0.000000	0.000000	0.000000	0.000000	0.000000
2**9	0.000000	0.000000	0.000000	0.000000	0.000000
2**10	0.000000	0.000000	0.000000	0.000000	0.000000
```

The first column in the output report the size of the tested array. The remaining columns in the output reports the execution-time in seconds of the implementations of sorting algorithms. Since the algorithms are not implemented in the repository, `test_sorting` initially reports 0 seconds for all of them. 

