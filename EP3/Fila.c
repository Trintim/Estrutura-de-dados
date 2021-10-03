#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Fila.h"
#include "Util.h"


struct no{
    struct no* proximo;
    char* palavra;
};

struct fila{
    No* inicio;
    No* fim;
    int n;
};

Fila* criaFila(){
    Fila* novaFila = mallocSafe(sizeof(Fila));
    novaFila->inicio = novaFila->fim = NULL;
    novaFila->n = 0;
    return novaFila;
}

void liberaFila(Fila* fila){
    No* atual = fila->inicio;
    while(atual){
        No* auxiliar = atual;
        atual = atual->proximo;
        free(auxiliar->palavra);
        free(auxiliar);
    }
    free(fila);
}

int contemFila(Fila* fila, char* palavra){
    No* atual = fila->inicio;
    while(atual){
        if (!strcmp(palavra, atual->palavra))
            return 1;
        atual = atual->proximo;
    }
    return 0;
}

void enqueue(Fila* fila, char* palavra){
    if (contemFila(fila, palavra))
        return;
    No* novo = mallocSafe(sizeof(No));
    novo->palavra = mallocSafe((strlen(palavra) + 1) * sizeof(char));
    strcpy(novo->palavra, palavra);
    novo->proximo = NULL;
    if (!fila->inicio)
        fila->inicio = fila->fim = novo;
    else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    fila->n++;
}

void dequeue(Fila* fila){
    if (!fila->inicio)
        return;
    else{
        No* aux = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(aux->palavra);
        free(aux);
        aux = NULL;
    }
    fila->n--;
}

void esvaziaFila(Fila* fila){
    while(!filaVazia(fila)){
        dequeue(fila);
    }
}

char* frenteFila(Fila* fila){
    return fila->inicio->palavra;
}

char* fundofila(Fila* fila){
    return fila->fim->palavra;
}

int filaVazia(Fila* fila){
    return fila->n == 0;
}

void imprimeFilaVerde(Fila* fila){
    No* atual = fila->inicio;
    while(atual){
        if (!atual->proximo)
            printf("\033[1;32m%s.\033[00m", atual->palavra);
        else
            printf("\033[1;32m%s, \033[00m", atual->palavra);
        atual = atual->proximo;
    }
}

void imprimeFilaRoxo(Fila* fila){
    No* atual = fila->inicio;
    while(atual){
        printf("\033[1;35m%s, \033[00m", atual->palavra);
        atual = atual->proximo;
    }
}



