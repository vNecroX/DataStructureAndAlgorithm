#include <stdio.h>

#define N 5

int main(){
    int maiz[N][N];
    int i, j, quantity = 1;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            maiz[i][j] = quantity;
            quantity *= 2;
        }
    }

    for (i=0; i<N; i++){
        for (j=0; j<N; j++)
            printf ("%10i", maiz[i][j]);
        
        printf("\n");
    }

    return 0;
}