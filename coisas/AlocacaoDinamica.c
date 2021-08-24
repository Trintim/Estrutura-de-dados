#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void funcao(int *a, int n){
    for(int i = 0; i < 10; i++){
        a[i] = i + 1;
    }
}

int main(int argc, char** argv) {

    int x = 123;
    int y[10];

    printf("\n%d - %p\n",x, &x);

    int *p = &x;

    printf("\n%d - %p - %p\n\n", *p, &p, p);

    for(int i = 0; i < 10; i++){
        printf("%d ", y[i]);
    }

    printf("\n");

    funcao(y, 10);

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d ", y[i]);
    }

    printf("\n");

    return 0;
}