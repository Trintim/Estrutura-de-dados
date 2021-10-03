#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Util.h"
#include "ArvAVL.h"
#include "Fila.h"

struct no{
    char* palavra;
    struct no* dir;
    struct no* esq;
    int altura;
};


No* criaNo(char* palavra){
    No* novo = malloc(sizeof(No));
    novo->palavra = mallocSafe((strlen(palavra) + 1) * sizeof(char));
    strcpy(novo->palavra, palavra);
    novo->dir = novo->esq = NULL;
    novo->altura = 0;
    return novo;
}

void liberaArvore(No* raiz){
    if (raiz){
        liberaArvore(raiz->dir);
        liberaArvore(raiz->esq);
        free(raiz->palavra);
        free(raiz);
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int alturaABB(No* raiz) {
    if(raiz == NULL)
        return -1;
    int hSAE = alturaABB(raiz->esq);
    int hSAD = alturaABB(raiz->dir);
    if (hSAE > hSAD)
        return hSAE + 1;
    else
        return hSAD + 1;
}

int altura(No* raiz){
    if (!raiz)
        return -1;
    return raiz->altura;

}

int fatorBalanceamentoABB(No* raiz){
    return alturaABB(raiz->esq) - alturaABB(raiz->dir);
}

int fatorBalanceamento(No* raiz){
    return altura(raiz->esq) - altura(raiz->dir);
}

No* insereNo(No* raiz, No* novo){
    //INSERÇÃO
    if (!raiz) return novo;
    if (strcmp(novo->palavra, raiz->palavra) < 0)
        raiz->esq = insereNo(raiz->esq, novo);
    else
        raiz->dir = insereNo(raiz->dir, novo);

    return raiz;
}

No* rotacaoRR(No* A){
    No* B = A->esq;

    //Rotacao
    A->esq = B->dir;
    B->dir = A;

    //Atualiza as alturas
    A->altura = max(altura(A->esq), altura(A->dir)) + 1;
    B->altura = max(altura(B->esq), altura(B->dir)) + 1;
    return B;
}

No* rotacaoLL(No* A){
    No* B = A->dir;

    //Rotacao
    A->dir = B->esq;
    B->esq = A;

    //Atualiza as alturas
    A->altura = max(altura(A->esq), altura(A->dir)) + 1;
    B->altura = max(altura(B->esq), altura(B->dir)) + 1;
    return B;
}

/**
 * @brief Arvore AVL
 *
 * @param raiz
 * @param novo
 * @return No*
 */

No* insereNoAVL(No* raiz, No* novo){
    //INSERÇÃO
    if (!raiz) return novo;
    if (strcmp(novo->palavra, raiz->palavra) < 0)
        raiz->dir = insereNoAVL(raiz->dir, novo);
    else
        raiz->esq = insereNoAVL(raiz->esq, novo);

    //ATUALIZA ALTURA
    raiz->altura = max(altura(raiz->esq), altura(raiz->dir)) + 1;

    //VERIFICAR BALANCEAMENTO
    int balancRaiz = fatorBalanceamento(raiz);

    if (balancRaiz > 1 && fatorBalanceamento(raiz->esq) >= 0)
       return rotacaoRR(raiz);
    else if (balancRaiz < -1 && fatorBalanceamento(raiz->dir) <= 0)
        return rotacaoLL(raiz);
    else if (balancRaiz > 1 && fatorBalanceamento(raiz->esq) < 0){
        raiz->esq = rotacaoLL(raiz->esq);
        return rotacaoRR(raiz);
    }
    else if (balancRaiz < -1 && fatorBalanceamento(raiz->dir) > 0){
        raiz->dir = rotacaoRR(raiz->dir);
        return rotacaoLL(raiz);
    }
    return raiz;
}

int pertence(No* raiz, char* palavra){
    if (!raiz)
        return 0;
    else if (!strcmp(raiz->palavra, palavra))
        return 1;
    else if (pertence(raiz->esq, palavra))
        return 1;
    else
        return pertence(raiz->dir, palavra);
}

void padding ( char ch, int n ){
  int i;
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void imprimeArvore(No *raiz, int level){
  if ( raiz == NULL ) {
    padding ('\t', level );
    puts ("~" );
  } else {
      imprimeArvore(raiz->dir, level + 1);
      padding('\t', level);
      printf("%s\n", raiz->palavra);
      imprimeArvore(raiz->esq, level + 1);
  }
}

void achaSugestoes(Fila* sugestoes, No* raiz, char* palavra, int range){
    if (!raiz)
        return;
    if (strlen(palavra) == strlen(raiz->palavra)){
        if (distanciaEdicao(palavra, raiz->palavra) <= range)
            enqueue(sugestoes, raiz->palavra);
    }
    achaSugestoes(sugestoes, raiz->dir, palavra, range);
    achaSugestoes(sugestoes, raiz->esq, palavra, range);
}