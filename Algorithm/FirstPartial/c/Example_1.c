#include <stdio.h>
#include <stdlib.h>

int numbers[10];
int i = 1;

int main(){
    numbers[0] = 0;

    for(; i<10; i++)
        numbers[i] = numbers[i-1] + 1;

    i = 0;
    
    for(; i<10; i++)
        printf("%i\n", numbers[i]);
    
    return 0;
}