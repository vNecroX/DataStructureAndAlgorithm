#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4 

int main(){
    int numbers[N];
    int i = 0;

    int min, max;
    min = 0;    max = 1000;

    for(; i<N; i++)
        scanf("%i", &numbers[N]);

    i = 0;

    for(; i<N; i++){
        if(numbers[i] < min)
            min = numbers[i];
        
        if(numbers[i] > max)
            max = numbers[i];
    }

    printf("min is: %i", min);
    printf("\nmax is: %i", max);

    return 0;
}