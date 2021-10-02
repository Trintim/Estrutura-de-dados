#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Fila.h"
#include "Util.h"

Fila *criaFila(){

    Fila *fila = mallocSafe(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->n = 0;
}

int buscaFila(Fila *f, char *pWord){

    if(f != NULL){

        if(!filaVazia(f)){

            NoFila *atual = f->inicio;
            while (atual){

                if(!strcmp(pWord, atual->palavras)){
                    return 1;
                }

            }
            atual = atual->proximo;
        }
    }
    return 0;
}

void liberaFila(Fila *f){

    NoFila *noAtual = f->inicio;
    while (noAtual){

        NoFila *t = noAtual;
        noAtual = noAtual->proximo;
        free(t->palavras);
        free(t);
    }
    free(f);
}

void enqueue(Fila *f, char *pWord){

    if(buscaFila(f, pWord)){
        return;
    }

    NoFila *novo = mallocSafe(sizeof(NoFila));
    novo->palavras = mallocSafe((strlen(pWord) + 1) * sizeof(char));
    strcpy(novo->palavras, pWord);
    novo->proximo = NULL;
    if(!f->inicio){

        f->inicio = novo;
        f->fim = novo;
    }
    else{

        f->fim->proximo = novo;
        f->fim = novo;
    }
    f->n++;
}

void dequeue(Fila *f){

    if(!f->inicio){

        return;
    }
    else{

        NoFila *atual = f->inicio;
        f->inicio = f->inicio->proximo;
        free(atual->palavras);
        free(atual);
        atual = NULL;
    }
    f->n--;
}

void imprimeFilaSugestao(Fila *f){

    NoFila *atual = f->inicio;
    while (atual){
        if(!atual->proximo){
            printf("\033[1;32;40m%s\033[00m, ", atual->palavras);
        }
        else{
            printf("\033[1;32;40m%s\033[00m, ", atual->palavras);
        }
        atual = atual->proximo;
    }
}

int filaVazia(Fila *f){

    return f->n == 0;
}

char *front(Fila *f){

    if(filaVazia(f)){

        printf("ERRO: Fila vazia");
        return -1;
    }
    else return f->inicio->palavras;
}

void zerar(Fila *f){

    while (filaVazia(f) == NULL){
        dequeue(f);
    }
}


