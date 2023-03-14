#include <stdio.h>
#include <stdlib.h>

int arraySize = 5;
int grades[] = {98, 5, 7, 23, 5};
int *ptGrades;
int i = 0;

int main(){
    ptGrades = grades; 
    //ptGrades = &grades[0], 

    for(; i<arraySize; i++)
        printf("Grade %i is: %i\n", i+1, *(ptGrades+i));
    
    return 0;
}