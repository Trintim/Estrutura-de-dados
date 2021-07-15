#include <stdio.h>
#include <stdlib.h>

int main(){

    long int *p;
    long int **B;
    int i, j;
    long int n;
    int cont = 1;

    scanf("%ld", &n);

    //p vetor de permutacao
    p = malloc(n*sizeof(long int));
    if (p == NULL){
        exit(1);
    }

    B = malloc(n*sizeof(long int*));
    if (B == NULL){
        exit(1);
    }

    for(i = 0; i < n; i++){
        B[i] = malloc(n*sizeof(long int));
        if (B[i] == NULL){
            exit(1);
        }
    }

    for(i = 0; i < n; i++){
        scanf("%ld", &p[i]);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%ld", &B[i][j]);
        }
    }

    for (i = 0; i < n; i++){
        if(p[i] == cont && cont <= n){
            for(j = 0; j < n; j++){
                printf("%ld ", B[i][j]);
            }
            printf("\n");
            cont++;
            i=-1;
        }
    }

    for (i = 0; i < n; i++){
        free(B[i]);
    }
    free(B);
    free(p);

    return 0;
}