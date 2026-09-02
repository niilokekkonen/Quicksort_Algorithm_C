#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void switch_num(int *x, int *y);
void quicksort(int first, int last, int array[]);
void print(int array[]);

int numbers[20];

int main() {
    int s;
    srand(time(NULL));
    for (s = 0; s < 20; s++) {
        
        numbers[s] = rand() % 20;
    } 
    printf("Unsorted array\n");
    print(numbers);
    
    quicksort(0, 19, numbers);
    printf("\nSorted array\n");
    print(numbers);
}


//Switch the elements utilizing pointers to manipulate the elements in the array
void switch_num(int *x, int*y) {
    int temp;
    //Temporary variable
    temp = *x;
    *x = *y;
    *y = temp;
}

//Sorting algorithm

//Example
// Array[5] = 0, 1, 2, 3, 4
//first = 0, last = 19
//pivot = array[] 
void quicksort(int first, int last, int array[]) {
    int pivot, left, right, temp;
    left = first;
    right = last;
    pivot = array[(first + last) / 2];
    do 
    {
        while (array[left] < pivot) left++;
         
        while (pivot < array[right]) right--;
         
        if (left <= right) {
            switch_num(&(array[left]), &(array[right]));
            left += 1;
            right -=1;
        }
    } while ((left <= right));
        
    if (first < right) quicksort(first, right, array);
        
    if (left < last) quicksort(left, last, array);
    }


void print(int array[]) {
    int i;
    for (i=0; i < 20; i++) {
        printf("%d ", array[i]);
    }
}


