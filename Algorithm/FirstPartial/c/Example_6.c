#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){
    int B[N][N];
    int i, j;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            B[i][j] = 0;
            printf("%i", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}