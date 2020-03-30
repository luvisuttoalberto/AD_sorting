#include <stdio.h>

#include "insertion_sort.h"
#include "quick_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "heap_sort.h"
#include "utilities.h"

#define MAX_SIZE 1<<10

#define NUM_OF_REPETITIONS 100

int main(int argc, char *argv[])
{
    int *A=get_random_int_array(MAX_SIZE);

    printf("Size\tInsertion Sort\tQuick Sort\tBubble Sort\tSelection Sort\tHeap Sort");
    for (unsigned int i=0; (1<<i)<=MAX_SIZE; i++) {
        const unsigned int A_size=1<<i;
        printf("\n2**%d",i);
        printf("\t%lf",test(insertion_sort,A,
                            A_size,sizeof(int),
                            leq_int,NUM_OF_REPETITIONS));
        printf("\t%lf",test(quick_sort,A,
                            A_size,sizeof(int),
                            leq_int,NUM_OF_REPETITIONS));
        printf("\t%lf",test(bubble_sort,A,
                            A_size,sizeof(int),
                            leq_int,NUM_OF_REPETITIONS));
        printf("\t%lf",test(selection_sort,A,
                            A_size,sizeof(int),
                            leq_int,NUM_OF_REPETITIONS));
        printf("\t%lf",test(heap_sort,A,
                            A_size,sizeof(int),
                            leq_int,NUM_OF_REPETITIONS));
    }

    printf("\n");
    free(A);

    return 0;
}