#include <stdlib.h>
#include <stdio.h>


int main(){

    int *p = malloc(100*sizeof(int));
    int *q = malloc(100*sizeof(int));
    q = p;


    printf("opa nene");

    return 0;


}