#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    int x = 123, y = 456;
    int t = 0;
    //int *p = NULL;
    //printf("%ld\n", sizeof(int));
    long *p = malloc(t * sizeof(long));
    if (p == NULL){
        printf("ERROR MALLOC");
        exit(1);
    }

    for(int i=0; i < 5; i++){
        p[i] = i + 1;
    }

    printf("\n");

    for(int i=0; i < 5; i++){
        printf("%ld - %p\n", p[i], &p[i]);
    }

    printf("\n");

    

    //printf("\n%d - %p - %p\n\n", *p, &p, p);

    /*
    for(int i; i < t; i++){
        notas[t] = i + 1;
    }

    printf("\n");
    t = 20;

    for(int i; i < t; i++){
        printf("%d ", notas[i]);
    }

    printf("\n");*/

    return 0;
    free(p);
}