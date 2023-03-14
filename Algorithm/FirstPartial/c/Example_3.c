#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4

int main(){
    int numbers[N];
    int i = 0;

    float sum = 0;

    for(; i<N; i++)
        scanf("%i", &numbers[i]);

    i = 0;

    for(; i<N; i++)
        sum += numbers[i];

    printf("\nSum is: %f", sum);

    return 0;
}