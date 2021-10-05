#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Util.h"
#include "ArvoresBinAvl.h"
#include "Fila.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct no{
    char *palavras;
    struct no *dir;
    struct no *esq;
    int alturaAVL;
};


No *criaNo(char *pWord){

    No *novo = malloc(sizeof(No));
    novo->palavras = mallocSafe((strlen(pWord) + 1) * sizeof(char));
    strcpy(novo->palavras, pWord);
    novo->dir = NULL;
    novo->esq = NULL;
    novo->alturaAVL = 0;
    return novo;
}

void liberaNo(No *r){
    if(r){

        liberaNo(r->dir);
        liberaNo(r->esq);
        free(r->palavras);
        free(r);
    }
}

int alturaArvoreBin(No *r) {
    if(r == NULL){
        return -1;
    }

    int hSAE = alturaArvoreBin(r->esq);
    int hSAD = alturaArvoreBin(r->dir);
    if (hSAE > hSAD){

        return hSAE + 1;
    }
    else{

        return hSAD + 1;
    }
}

int alturaAVL(No *r){
    if (r == NULL){
        return -1;
    }
    return r->alturaAVL;

}

int fatorBalanceamentoArvoreBin(No *r){

    return alturaArvoreBin(r->esq) - alturaArvoreBin(r->dir);
}

int fatorBalanceamentoAVL(No *r){

    return alturaAVL(r->esq) - alturaAVL(r->dir);
}

No *insereNoArvoreBin(No *r, No *novo){
    //INSERÇÃO
    if (r == NULL){
        return novo;
    }
    if (strcmp(novo->palavras, r->palavras) < 0){

        r->esq = insereNoArvoreBin(r->esq, novo);
    }
    else{

        r->dir = insereNoArvoreBin(r->dir, novo);
    }
    return r;
}

No *rotacaoDir(No *A){

    No *B = A->esq;

    //Rotacao
    A->esq = B->dir;
    B->dir = A;

    //Atualiza as alturas
    A->alturaAVL = max(alturaAVL(A->esq), alturaAVL(A->dir)) + 1;
    B->alturaAVL = max(alturaAVL(B->esq), alturaAVL(B->dir)) + 1;

    return B;
}

No *rotacaoEsq(No *A){

    No *B = A->dir;

    //Rotacao
    A->dir = B->esq;
    B->esq = A;

    //Atualiza as alturas
    A->alturaAVL = max(alturaAVL(A->esq), alturaAVL(A->dir)) + 1;
    B->alturaAVL = max(alturaAVL(B->esq), alturaAVL(B->dir)) + 1;

    return B;
}

No *insereAVL(No *r, No *novo){

    if (r == NULL){ return novo;
    }
    if (strcmp(novo->palavras, r->palavras) < 0){

        r->dir = insereAVL(r->dir, novo);
    }
    else{

        r->esq = insereAVL(r->esq, novo);
    }

    r->alturaAVL = max(alturaAVL(r->esq), alturaAVL(r->dir)) + 1;

    int factoBal = fatorBalanceamentoAVL(r);

    if (factoBal > 1 && fatorBalanceamentoAVL(r->esq) >= 0){

       return rotacaoDir(r);
    }
    else if (factoBal < -1 && fatorBalanceamentoAVL(r->dir) <= 0){

        return rotacaoEsq(r);
    }
    else if (factoBal > 1 && fatorBalanceamentoAVL(r->esq) < 0){

        r->esq = rotacaoEsq(r->esq);
        return rotacaoDir(r);
    }
    else if (factoBal < -1 && fatorBalanceamentoAVL(r->dir) > 0){

        r->dir = rotacaoDir(r->dir);
        return rotacaoEsq(r);
    }
    return r;
}

int buscaDicionario(No *r, char *pWord){
    if (r == NULL){

        return 0;
    }
    else if (!strcmp(r->palavras, pWord)){

        return 1;
    }
    else if (buscaDicionario(r->esq, pWord)){
        return 1;
    }
    else{

        return buscaDicionario(r->dir, pWord);
    }
}

void padding ( char ch, int n ){
    int i;
    for ( i = 0; i < n; i++ )
        putchar ( ch );
}

void imprimeArvoreAVL(No *r, int level){

    if ( r == NULL ) {
        padding ('\t', level );
        puts ("~" );
    } else {
        imprimeArvoreAVL(r->dir, level + 1);
        padding('\t', level);
        printf("%s\n", r->palavras);
        imprimeArvoreAVL(r->esq, level + 1);
    }
}

void comparaFazSugestao(Fila* f, No *r, char *pWord, int tam){

    if (r == NULL){
        return;
    }

    if (strlen(pWord) == strlen(r->palavras)){
        if (distanciaEdicao(pWord, r->palavras) <= tam){
            enqueue(f, r->palavras);
        }
    }

    comparaFazSugestao(f, r->dir, pWord, tam);
    comparaFazSugestao(f, r->esq, pWord, tam);
}
