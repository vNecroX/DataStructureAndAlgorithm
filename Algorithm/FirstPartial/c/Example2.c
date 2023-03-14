#include <stdio.h>
#include <stdlib.h>

int *ptNum;
int num = 10;

int main(){
    ptNum = &num;
    printf("Num is: %i\n", num);
    printf("Num dir is: %i\n", &num);
    printf("Pointer value in *ptNum is: %i\n", *ptNum);
    return 0;
}