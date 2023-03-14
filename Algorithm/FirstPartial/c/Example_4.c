#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4

int main(){
    int numbers[N];
    int i = 0;

    float sum, parit, pgeom;
    sum = 0;    pgeom = 1;

    for(; i<N; i++)
        scanf("%i", &numbers[i]);

    i = 0;

    for(; i<N; i++){
        sum += numbers[i];
        pgeom *= numbers[i];
    } 

    parit = 1.0*sum / N;            //10/4
    pgeom = pow(pgeom, 1.0/N);      //24^0.25

    printf("Parit: %f", parit); 
    printf("\nPgeom: %f", pgeom); 

    return 0;
}