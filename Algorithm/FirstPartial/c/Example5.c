#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alpha[] = "abcdefghijklmnopqrstuvwxyz";
char *ptAlpha;
int i = 0;
int n;

int main(){
    ptAlpha = alpha;
    n = strlen(alpha);

    for(; i<n; i++)
        printf("%c in ASCII is: %i\n", *(ptAlpha+i), *(ptAlpha+i));
    
    return 0;
}