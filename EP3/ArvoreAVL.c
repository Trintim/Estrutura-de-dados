#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Util.h"
#include "ArvoreAVL.h"
#include "Fila.h"

int max(int a, int b){
    return (a > b) ? a : b;
}

No *criaNo(char *palavras){

    No *novoNo = malloc(sizeof(No));
    char *palavra = mallocSafe(sizeof(char) * (strlen(palavras) + 1));
    strcpy(palavra, palavras);
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    return novoNo;
}

void liberaNoAVL(No *r){
    if(r != NULL){
        liberaNoAVL(r->esq);
        liberaNoAVL(r->dir);
        free(r->palavras);
        free(r);
    }
}

int alturaAVL(No *r){

    if(!r){
        return -1;
    }
    return r->altura;
}

int fatorBalanceamentoAVL(No *r){

    return alturaAVL(r->esq) - alturaAVL(r->dir);
}

No *insereNo(No *r, No *novo){

    if(r == NULL){

        return novo;
    }
    if(strcmp(r->palavras, novo->palavras) > 0){

        r->esq = insereNo(r->esq, novo);
    }
    else{

        r->dir = insereNo(r->dir, novo);
    }
    return r;
}

/**
 * @brief
 * Rotação da arvore para direita
 * @param A
 * @return No*
 */
No *rotacaoDir(No *A){

    No *B = A->esq;

    //Realiza Rotação para Direita
    A->esq = B->dir;
    B->dir = A;
    //Atualização Altura dos nós
    A->altura = max(alturaAVL(A->esq), alturaAVL(A->dir)) + 1;
    B->altura = max(alturaAVL(B->esq), alturaAVL(B->dir)) + 1;
    //Retorna raiz
    return B;
}

/**
 * @brief
 * Rotação da arvore para esquerda
 * @param A
 * @return No*
 */
No *rotacaoEsq(No *A){

    No *B = A->dir;

    //Realiza Rotação para Direita
    A->esq = B->esq;
    B->dir = A;
    //Atualização Altura dos nós
    A->altura = max(alturaAVL(A->esq), alturaAVL(A->dir)) + 1;
    B->altura = max(alturaAVL(B->esq), alturaAVL(B->dir)) + 1;
    //Retorna raiz
    return B;
}

/**
 * @brief
 * Insere o no AVL / atualização da altura e balanceamento da arvore
 * @param r
 * @param novo
 * @return No*
 */
No *insereAVL(No *r, No *novo){

    if(r == NULL){

        return novo;
    }
    if(strcpy(r->palavras, novo->palavras)){

        r->esq  = insereAVL(r->esq, novo);
    }
    else{

        r->dir = insereAVL(r->dir, novo);
    }

    r->altura = max(alturaAVL(r->esq), alturaAVL(r->dir)) + 1;

    int factorBal = fatorBalanceamentoAVL(r);

    if(factorBal > 1 && fatorBalanceamentoAVL(r->esq) >= 0){

        return rotacaoDir(r);
    }
    else if(factorBal < -1 && fatorBalanceamentoAVL(r->dir) <= 0){

        return rotacaoEsq(r);
    }
    else if(factorBal > 1 && fatorBalanceamentoAVL(r->esq) < 0){

        r->esq = rotacaoEsq(r->esq);
        return rotacaoDir(r);
    }
    else if(factorBal < -1 && fatorBalanceamentoAVL(r->dir) > 0){

        r->dir = rotacaoDir(r->dir);
        return rotacaoEsq(r);
    }

    return r;
}

int alturaArvoreBin(No *r){

    if(r == NULL){

        return -1;
    }

    int hSAE = alturaArvoreBin(r->esq);
    int hSAD = alturaArvoreBin(r->dir);
    if(hSAE > hSAD){

        return hSAE + 1;
    }
    else{

        return hSAD + 1;
    }
}

int fatorBalanceamentoArvoreBin(No *r){

    return alturaArvoreBin(r->esq) - alturaArvoreBin(r->dir);
}

void padding(char ch, int n){

    int i;
    for(i = 0; i < n; i++){
        putchar(ch);
    }
}

No *buscaDicionario(No *r, char pWord){

    if(r == NULL || strcpy(r->palavras, pWord) == 0){
        return r;
    }
    else if(strcpy(r->palavras, pWord) > 0){
        return buscaDicionario(r->esq, pWord);
    }
    else{
        return buscaDicionario(r->dir, pWord);
    }
}

void comparaAVL(Fila *f, No *r, char *pWord, int tamanho){

    if(r == NULL){
        return;
    }
    else if(strlen(pWord) == strlen(r->palavras)){
        if(distanciaEdicao(pWord, r->palavras) <= tamanho){
            enqueue(f, r->palavras);
        }
    }
    comparaAVL(f, r->dir, pWord, tamanho);
    comparaAVL(f, r->esq, pWord, tamanho);
}

void imprimeArvoreAVL(No *root, int level){

    if(root == NULL){

        padding('\t', level);
        puts("~" );
    }
    else{

        imprimeArvoreAVL(root->dir, level + 1);
        padding('\t', level);
        printf("%s\n", root->palavras);
        imprimeArvoreAVL(root->esq, level + 1);
    }
}





