#include <stdio.h>
#include <stdlib.h>

int *array;
int hmNum;
int i = 0;

int main(){
    printf("How much numbers? ");
    scanf("%i", &hmNum);

    array = (int*)malloc(hmNum*sizeof(int));

    for(; i<hmNum; i++){
        printf("Number %i: ", i+1);
        scanf("%i", array+i);                                                                           // Like Pointer
        //scanf("%i", &array[i]);                                                                       // Like Array
    }

    i = 0;
    printf("\n");

    for(; i<hmNum; i++){
        printf("Number %i has value of: %i & it is allocated in: %i\n", i+1, *(array+i), array+i);      // Like Pointer
        //printf("Number %i has value of: %i & it is allocated in: %i \n", i+1, array[i], &array[i]);   // Like Array 
    }

    return 0;
}