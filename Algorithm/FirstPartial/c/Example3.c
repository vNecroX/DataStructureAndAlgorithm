#include <stdio.h>
#include <stdlib.h>

int *ptX, *ptY;
int array[] = {2, 5, 7, 4, 5, 1};
int num;

int main(){
    ptX = &array[0];
    ptY = &array[2];
    num = *ptX * *ptY;
    printf("%i times %i is: %i\n", *ptX, *ptY, num);

    num = *ptX + 4;
    printf("ptX new value is: %i", num);

    return 0;
}