#include <stdio.h>
#include <stdlib.h>

int numbers[10];
int i = 0;

int main(){

    for(; i<10; i++)
        scanf("%i", &numbers[i]);

    i = 0;

    printf("\nStored numbers are: \n");

    for(; i<10; i++)
        printf("%i\n", numbers[i]);

    return 0;
}
