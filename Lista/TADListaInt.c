#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;           // Informação do nó
    struct no *proximo; // Endereço do próximo nó
}No;

typedef struct lista {
    No *primeiro;
}Lista;

Lista *criaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->primeiro = NULL;
    return l;
}

void insere(Lista *l, int valor) {
    //Complexidade: O(1)

    //alcoar o no
    No *no = malloc(sizeof(No));
    //modificar o campo 'dado' do 'no'
    no->dado = valor;
    //campo proximo do 'no' aponta para NULL
    no->proximo = l->primeiro;
    //'l->primeiro aponta para o novo nó
    l->primeiro = no;
}

int vazia(Lista *l) {
    return l->primeiro == NULL;
}

void imprimeLista(Lista *l) {
    No *atual = l->primeiro;
    while (atual != NULL) { //while (atual)    
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }
}

void liberaLista(Lista *l) {
    No *atual = l->primeiro;
    while (atual != NULL) { //while (atual)    
        No *tmp = atual->proximo;
        free(atual);
        atual = tmp;
    }
    free(l);
    l= NULL;
}

int main() {
    Lista *l = criaLista();
    insere(l, 2);
    insere(l, 3);
    insere(l, 5);
    insere(l, 7);

    imprimeLista(l);
    liberaLista(l);
    return 0;
}