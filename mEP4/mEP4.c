#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

Lista *juntaLista(Lista *l1, Lista *l2) {

    Lista *resultado = criaLista();
    /*
     * Sua tarefa é, entre outras, implementar o código dessa função que junta duas listas ordenadas de forma que
     * a lista resultante ('resultado') esteja ordenada.
     * Os elementos de l1 e l2, se existirem, sempre estarão ordenados (do menoResultadoenoResultado para o maior de acordo com a id do nó).
     *
     * Lembre-se que você não pode fazer alocação dinâmica/estática de novos nós (usando malloc), mas você pode
     * criar novos ponteiros para os nós das listas. Além disso, com exceção da função criaLista, a função
     * juntaLista não pode utilizar/chamar outras funções do TAD Lista, ou seja, todo o código de manipulação dos
     * elementos da lista devem ser feitos dentro da função juntaLista.
     *
     * A função deve ter complexidade O(n)
     *
     * Exemplos de entrada:
     * l1 = 1->2->5->10
     * l2 = 3->7->8->11
     * Resultado esperado:
     * resultado = 1->2->3->5->7->8->10->11
    */
    No *no1 = NULL;
    No *no2 = NULL;
    No *noResultado = NULL;

    if(l1->inicio == NULL){
        return l2;
    }

    if(l2->inicio == NULL){
        return l1;
    }

    no1 = l1->inicio;
    no2 = l2->inicio;

    if(no1->id < no2->id){
        resultado->inicio = no1;
        no1 = no1->proximo;
    }
    else {
        resultado->inicio = no2;
        no2 = no2->proximo;
    }

    noResultado = resultado->inicio;

    while(no1 != NULL && no2 != NULL){
        if(no1->id <= no2->id){
            noResultado->proximo = no1;
            no1 = no1->proximo;
        }
        else {
            noResultado->proximo = no2;
            no2 = no2->proximo;
        }
        noResultado = noResultado->proximo;
    }

    if(no1 == NULL){
        noResultado->proximo = no2;
    }

    else if(no2 == NULL){
        noResultado->proximo = no1;
    }

    if(l1->fim->id > l2->fim->id){
        resultado->fim = l1->fim;
    }

    else{
        resultado->fim = l2->fim;
    }

    return resultado;
}
