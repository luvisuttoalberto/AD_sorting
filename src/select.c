#include "select.h"
#include "quick_sort.h"
#include "swap.h"

#define ADDR(A, j, elem_size) ((A)+(j)*(elem_size))

int equal_elements(const void *x, const void *y, total_order leq){
    return leq(x, y) && leq(y, x);
}

tuple modified_partition(void *A, unsigned int l, unsigned int r, unsigned int p, const size_t elem_size, total_order leq){
    tuple result;

    // swap pivot p and first element in A (l)
    swap(ADDR(A, l, elem_size), ADDR(A, p, elem_size), elem_size);
    p = l++;
    
    unsigned int num_of_equal_elem = 0;

    while(l <= r){
        if(!equal_elements(ADDR(A, p, elem_size), ADDR(A, p, elem_size), leq)){ // l != p
            if(leq(ADDR(A, l, elem_size), ADDR(A, p, elem_size))){ // l < p
                swap(ADDR(A, l, elem_size), ADDR(A, p-num_of_equal_elem, elem_size), elem_size);
                p = l++;
            }else{ // l > p
                swap(ADDR(A, l, elem_size), ADDR(A, r, elem_size), elem_size);
                r--;
            }
        }else{ // l == p
            p = l++;
            num_of_equal_elem++;
        }
    }

    // final swap
    swap(ADDR(A, p, elem_size), ADDR(A, r, elem_size), elem_size);

    result.first_element = r - num_of_equal_elem;   // end of first section
    result.second_element = r;                      // end of second section

    return result;
}

unsigned int select_pivot(void *A, const unsigned int n, const size_t elem_size, total_order leq){
    
}

unsigned int select_index(void *A, const unsigned int n, const unsigned int i, const size_t elem_size, total_order leq)
{
    return 0;	
}

void recursive_quick_sort_select(void *A, unsigned int l, unsigned int r, const size_t elem_size, total_order leq){

    while(l < r){
        unsigned int p = l + select_pivot(ADDR(A, l, elem_size), r-l, elem_size, leq);

        tuple indexes = modified_partition(A, p, l, r-1, elem_size, leq);
        recursive_quick_sort_select(A, l, indexes.first_element, elem_size, leq);
        l = indexes.second_element + 1;
    }
}

// used just as an API
void quick_sort_select(void *A, const unsigned int n, const size_t elem_size, total_order leq)
{
    recursive_quick_sort_select(A, 0, n, elem_size, leq);
}
