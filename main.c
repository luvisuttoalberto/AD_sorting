#include <stdio.h>

#include "insertion_sort.h"
#include "quick_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "heap_sort.h"
#include "utilities.h"

#define MAX_SIZE 1<<13

#define NUM_OF_REPETITIONS 20

void test_and_print(void (*sort)(void *A, const unsigned int n, 
                         const size_t elem_size, 
                         total_order leq), 
                    const void *A, const unsigned int n, 
                    const size_t elem_size, total_order leq, 
                    const unsigned int rep)
{
    int sorted;

    printf("\t%lf",test(sort,A,n,elem_size,leq,rep,&sorted));
    if (sorted) {
        printf(" (OK)");
    } else {
        printf(" (Not Sorted)");
    }
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    int *A=get_random_int_array(MAX_SIZE);
    int sorted;

    printf("Size\tInsertion Sort\tQuick Sort\tBubble Sort\tSelection Sort\tHeap Sort");
    for (unsigned int i=0; (1<<i)<=MAX_SIZE; i++) {
        const unsigned int A_size=1<<i;
        printf("\n2**%d",i);
        test_and_print(insertion_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(quick_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(bubble_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(selection_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(heap_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
    }

    printf("\n");
    free(A);

    return 0;
}