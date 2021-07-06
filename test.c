#include <stdio.h>
#include <stdlib.h>

double **cria(int n) {
    //Função que cria uma matriz simetrica n x n
    //Essa função também deve inicializar todos os elementos com 0
    //Retono: ponteiro para a matriz 
    double **m = malloc(n*sizeof(double));;

    for(int i = 0; i < n; i++){
        m[i] = calloc(n, n*sizeof(double));
    }

    return m;
}

void imprime(double **m, int n){
    //Função que imprime a matriz
    //Essa função deve imprimir a matriz de forma natural
    //independente de como ela está sendo armazenada.
    //Ou seja, deve ser impressos os n x n elementos na tela.
    //Imprima os valores com 2 casas decimais
    for(int i = 0; i < n; i++){
        printf("%d ", m[i][n]);
        printf("\n");
    }

}

int main() {
    int n = 10;
    double **m = cria(n);

    imprime(m, n);

    return 0;
}