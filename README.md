# group-assignment2
Group assignment 2 for CPSC 351

Programming Assignment #2, Threads

Write a POSIX multithreaded sorting program (in C) called sorting.c that works as follows: A list of integers is divided into two smaller lists of (nearly) equal size. Two separate worker threads (which we will term sorting threads) sort each sublist using a sorting algorithm of your choice. The two sublists are then merged by a third worker thread - a merging thread - which merges the two sorted sublists into a single sorted list.

Because we are striving for Data Parallelism (same algorithm on different data) and because global data are shared across all threads, perhaps the easiest way to set up the data is to create a global (file scoped) array. Each sorting thread will work on one half of this array. A second global array of the same size as the unsorted integer array will also be established. The merging thread will then merge the two sublists into this second array. Graphically, this program is structured as:












This programming project will require passing parameters to each of the sorting threads. In particular, it will be necessary to identify the starting address from which each thread is to begin sorting, and the number of items to be sorted. See Hints below.

The parent thread will output the sorted array once all sorting has completed.

Other information:

The list of integers to be sorted is (use the exact values and order provided below):
{7, 12, 19, 3, 18, 4, 2, -5, 6, 15, 8}

gcc -pthread sorting.c -osorting is an example command to compile and link your program

3.	./sorting | tee sorting_output.txt is an example command to run your program while collecting your program’s output to a text file and seeing the output on the console.

Submit (only) the following 2 files to TITANium.

Code file and output file.

Hints:

The parent thread initializes an unsorted array with integer numbers. The easiest approach for sharing data is to create global data. For example, at file scope:




The parent thread then creates sorter threads, passing each a parameter containing the location (pointer) and size (unsigned int) of the unsorted array. The easiest approach for passing data to threads is to create a data structure using a typedef and struct. For example,
/* structures for passing data to worker threads */ typedef struct
{

int *	subArray;
unsigned int size;
} SortingThreadParameters;

typedef struct

{
SortingThreadParameters left;

SortingThreadParameters right;
} MergingThreadParameters;
