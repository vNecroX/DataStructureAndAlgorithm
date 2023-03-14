#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){
    int maiz[N][N];
    int i, j, count=0;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            count++;
            maiz[i][j] = count;
        }
    }

    for (i=0; i<N; i++){
        for (j=0; j<N; j++)
            printf ("%10i",maiz[i][j]);
    
        printf("\n");
    }

    return 0;
}