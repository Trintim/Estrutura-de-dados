  
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *criaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void insereInicio(Lista *l, int valor) {
    //Complexidade: O(1)

    //Alocar o no
    No *no = malloc(sizeof(No));
    //Modificar o campo 'dado' do 'no'
    no->dado = valor;
    //Campo 'proximo' do no aponta para NULL
    no->proximo = l->inicio;
    //'l->inicio' aponta para o novo nó
    l->inicio = no;
}

void imprimeLista(Lista *l) {
    No *atual = l->inicio;
    while (atual != NULL) { // while (atual)
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }
}

void liberaLista(Lista *l) {
    No *atual = l->inicio;
    while (atual != NULL) {
        No *tmp = atual->proximo;
        free(atual);
        atual = tmp;
    }
    free(l);
    l = NULL; 
}

int vazia(Lista *l){
    return l->inicio == NULL;
}

int tamanhoLista(Lista *l){
    /*complexidade: O(n)*/
    int t = 0;
    No *aux = l->inicio;
    while (aux != NULL)
    {
        t++;
        aux = aux->proximo;
    }
    
    
}

int main() {

    Lista *l = criaLista();
    insereInicio(l, 2);
    insereInicio(l, 3);
    insereInicio(l, 5);
    insereInicio(l, 7);

    imprimeLista(l);
    printf("%d\n", tamanhoLista(l));

    liberaLista(l);

    return 0;
}