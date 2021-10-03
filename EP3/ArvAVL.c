#include "Util.h"
#include "ArvAVL.h"
#include "Fila.h"

struct no{
    char *palavras;
    struct no *dir;
    struct no *esq;
    int altura;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

No *criaNo(char* pWord){

    No *novo = malloc(sizeof(No));
    novo->palavras = mallocSafe((strlen(pWord) + 1) * sizeof(char));
    strcpy(novo->palavras, pWord);
    novo->altura = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

void liberaNo(No *r){

    if (r != NULL){

        liberaNo(r->dir);
        liberaNo(r->esq);
        free(r->palavras);
        free(r);
    }
}

int alturaAVL(No *r){

    if (r == NULL)
        return -1;
    return r->altura;
}

int fatorBalanceamentoAVL(No *r){
    return alturaAVL(r->esq) - alturaAVL(r->dir);
}

No *insereNoArvBin(No *r, No* novo){

    if(r == NULL){

        return novo;
    }
    if(strcmp(r->palavras, novo->palavras) < 0){

        r->esq = insereNoArvBin(r->esq, novo);
    }
    else{

        r->dir = insereNoArvBin(r->dir, novo);
    }
    return r;
}

/**
 * @brief Rotação da arvore para direita
 *
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
 * @brief Rotação da arvore para Esquerda
 *
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

int alturaArvoreBin(No *r) {

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



/**
 * @brief Arvore AVL
 *
 * @param r
 * @param novo
 * @return No*
 */

No *insereAVL(No *r, No* novo){

    if (r == NULL){

        return novo;
    }
    if (strcmp(novo->palavras, r->palavras) < 0){

        r->dir = insereAVL(r->dir, novo);
    }
    else{

        r->esq = insereAVL(r->esq, novo);
    }

    r->altura = max(alturaAVL(r->esq), alturaAVL(r->dir)) + 1;


    int factorBal = fatorBalanceamentoAVL(r);

    if (factorBal > 1 && fatorBalanceamentoAVL(r->esq) >= 0){

       return rotacaoDir(r);
    }
    else if (factorBal < -1 && fatorBalanceamentoAVL(r->dir) <= 0){

        return rotacaoEsq(r);
    }
    else if (factorBal > 1 && fatorBalanceamentoAVL(r->esq) < 0){
        r->esq = rotacaoEsq(r->esq);
        return rotacaoDir(r);
    }
    else if (factorBal < -1 && fatorBalanceamentoAVL(r->dir) > 0){
        r->dir = rotacaoDir(r->dir);
        return rotacaoEsq(r);
    }
    return r;
}

int buscaDicionario(No *r, char *pWord){

    if(r == NULL){
        return 0;
    }
    else if(!strcmp(r->palavras, pWord)){
        return 1;
    }
    else if(buscaDicionario(r->esq, pWord)){
        return 1;
    }
    else{
        return buscaDicionario(r->dir, pWord);
    }
}

void padding(char ch, int n){

    int i;
    for(i = 0; i < n; i++){
        putchar(ch);
    }
}

void comparaFazSugestao(Fila* f, No *r, char* pWord, int tam){

    if(r == NULL){
        return;
    }

    else if(strlen(pWord) == strlen(r->palavras)){
        if(distanciaEdicao(pWord, r->palavras) <= tam){
            enqueue(f, r->palavras);
        }
    }

    comparaFazSugestao(f, r->dir, pWord, tam);
    comparaFazSugestao(f, r->esq, pWord, tam);
}

void imprimeArvoreAVL(No *noR, int level){

    if(noR == NULL){

        padding('\t', level);
        puts("~");
    }
    else{

        imprimeArvoreAVL(noR->dir, level + 1);
        padding('\t', level);
        printf("%s\n", noR->palavras);
        imprimeArvoreAVL(noR->esq, level + 1);
    }
}