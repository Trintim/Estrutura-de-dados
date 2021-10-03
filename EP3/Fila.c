#include "Fila.h"
#include "Util.h"

struct no{

    char *palavras;
    struct no *proximo;

};

struct fila{
    No *inicio;
    No *fim;
    int n;
};

Fila *criaFila(){

    Fila *fila = mallocSafe(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->n = 0;
    return fila;
}

void liberaFila(Fila *f){

    No *noAtual = f->inicio;
    while (noAtual){

        No *t = noAtual;
        noAtual = noAtual->proximo;
        free(t->palavras);
        free(t);
    }
    free(f);
}

int buscarFila(Fila *f, char* pWord){

    No *atual = f->inicio;
    while (atual){

        if(!strcmp(pWord, atual->palavras)){
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

void enqueue(Fila *f, char *pWord){

    if(buscarFila(f, pWord)){
        return;
    }

    No *novo = mallocSafe(sizeof(No));
    novo->palavras = mallocSafe((strlen(pWord) + 1) * sizeof(char));
    strcpy(novo->palavras, pWord);
    novo->proximo = NULL;

    if(f->inicio == NULL){

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

    if (f->inicio == NULL){

        return;
    }
    else{

        No *tmp = f->inicio;
        f->inicio = f->inicio->proximo;
        free(tmp->palavras);
        free(tmp);
        tmp = NULL;
    }
    f->n--;
}

void imprimeSugestao(Fila *f){

    No *atual = f->inicio;
    while(atual){
        if (atual->proximo == NULL){

            printf("\033[1;32m%s.\033[00m", atual->palavras);
        }
        else{
            printf("\033[1;32m%s, \033[00m", atual->palavras);
        }
        atual = atual->proximo;
    }
}

int filaVazia(Fila *f){

    return f->n == 0;
}

void esvaziaFila(Fila *f){

    while(!filaVazia(f)){
        dequeue(f);
    }
}

char *front(Fila *f){

    return f->inicio->palavras;
}

char *back(Fila *f){

    return f->fim->palavras;
}


