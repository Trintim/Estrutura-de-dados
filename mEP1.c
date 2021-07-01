#include <stdio.h>
#include <stdlib.h>

long int *iniciaVetor(int N) {
    long int *vetor = (long int *) calloc(N, sizeof(long int));
    if (vetor == NULL){
        exit(1);
    }
    return vetor;
}

void soma(long int *vetor, int a, int b, long int x) {
    for (int i = a; i <= b; i++){ 
        vetor[i] += x;
    }
}

void subtracao(long int *vetor, int a, int b, long int x) {
    for (int i = a; i <= b; i++){
        vetor[i] -= x;
    }
}

int main() {
    int N, M, opcao, a, b;
    long int x;

    scanf("%d%d", &N, &M);
    long int *vetor = iniciaVetor(N);

    for (int j = 0; j < M; j++) {
        scanf("%d", &opcao);        
        switch (opcao) {           
            case 1:
                scanf("%d%d", &a, &b);
                if (a < 1 || b > N){
                        exit(1);
                }
                scanf("%ld", &x);
                soma(vetor, a, b, x);
                break;

            case 2:
                scanf("%d%d", &a, &b);
                if (a < 1 || b > N){
                    exit(1);
                }
                scanf("%ld", &x);
                subtracao(vetor, a, b, x);
                break;

            case 3:
                scanf("%d", &a);
                if (a <= N){
                    printf("%ld\n", vetor[a]);
                }
                break;

            default:
                exit(1);

        }
    }
  
    free(vetor);
    return 0;
}

