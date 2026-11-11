#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_LEN 20
#define RNDM_RANGE 10

void switch_num(int *x, int *y);
void quicksort(int first, int last, int array[]);
void print(int *array, int arr_len);


int main(void) 
{
    int numbers[ARR_LEN];
    int s;
    srand(time(NULL));
    for (s = 0; s < ARR_LEN; s++) 
    {
        
        numbers[s] = rand() % RNDM_RANGE;
    } 
    printf("Unsorted array\n");
    print(numbers, ARR_LEN);
    
    quicksort(0, ARR_LEN, numbers);
    printf("\nSorted array\n");
    print(numbers, ARR_LEN);
}


//Switch the elements utilizing pointers to manipulate the elements in the array
void switch_num(int *x, int*y) 
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//Sorting algorithm

// Example
// Array[5] = 0, 1, 2, 3, 4
// first = 0, last = 4
// pivot = array[2], middle point 
void quicksort(int first, int last, int *array) 
{
    int pivot, left, right;
    left = first;
    right = last;
    pivot = array[(first + last) / 2];
    do 
    {
        while (array[left] < pivot) left++;
         
        while (pivot < array[right]) right--;
         
        if (left <= right) 
        {
            switch_num(&(array[left]), &(array[right]));
            left += 1;
            right -=1;
        }
    } while ((left <= right));        
    if (first < right) quicksort(first, right, array);
    if (left < last) quicksort(left, last, array);
}


void print(int *array, int arr_len) 
{
    int i;
    for (i=0; i < arr_len; i++) 
    {
        printf("%d ", array[i]);
    }
}


