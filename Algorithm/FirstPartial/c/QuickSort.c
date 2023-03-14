#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int array[] = {28, 11, 96, -5, 21, 18, 12, 22, 30, 97, -1, -40, -500};
int x = 0;

bool sortedArray = false;

void printArray(int);
void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int *a, int *b);

int main(){
    int arraySize = sizeof array / sizeof array[0];

    printArray(arraySize);
    quickSort(array, 0, arraySize-1);
    printArray(arraySize);

    return 0;
}

void printArray(int arrSize){
    if(sortedArray)
         printf("Sorted array. .\n");
    else
        printf("Unsorted array. .\n");

    for(; x<arrSize; x++)
            printf("%i ", array[x]);

    printf("\n\n");

    sortedArray = true;
    x = 0;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int partitionIndex = partition(arr, left, right);
        quickSort(arr, left, partitionIndex);
        quickSort(arr, partitionIndex+1, right);
    }
}

int partition(int arr[], int left, int right){
    int pivot = arr[left];

    while(1){
        while(arr[left] < pivot)
            left++;
        
        while(arr[right] > pivot)
            right--;

        if(left >= right)
            return right;
        else{
            swap(&arr[left], &arr[right]);

            left++;
            right--;
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}