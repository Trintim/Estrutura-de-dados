#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

struct lista {
    Objeto *inicio;
    Objeto *fim;
    int n;
};

/**
 * @brief Faz alocação de memória para a lista
 * Complexidade: O(1)
 * 
 * @return Lista* 
 */
Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio =  NULL;
    lista->fim = NULL;
    lista->n = 0;
    return lista;
}

/**
 * @brief Faz a liberação de memória dinamicamente alocada por cada objeto da lista
 * Complexidade: O(n)
 * 
 * @param lista: ponteiro da lista a ser desalocada 
 */
void liberaLista(Lista* lista) {
    if (lista == NULL)
        return;
    Objeto* atual = lista->inicio;
    while (atual != NULL) {
        Objeto* t = atual->proximo; 
        liberaObjeto(atual);
        atual = t;              
    }
    free(lista);
    lista = NULL;
}

/**
 * @brief Insere um novo objeto no *fim* da lista 
 * Complexidade: O(1)
 * 
 * @param lista: ponteiro da lista 
 * @param elem: ponteiro do objeto a ser inserido
 */
void insereLista(Lista *lista, Objeto *elem) {
    if (lista == NULL)
        return;
    elem->proximo = NULL;
    if(listaVazia(lista)) {
        lista->inicio = lista->fim = elem;
    }
    else {
        lista->fim->proximo = elem;
        lista->fim = elem;
    }
    lista->n++;
}

/**
 * @brief Função de alta ordem que imprime cada objeto da lista de acordo com
 * a função 'imprimeObjeto' (passada como parâmetro).
 * Complexidade: O(n)
 * 
 * @param lista: ponteiro da lista
 * @param imprimeObjeto: ponteiro da função utilizada para imprimir cada objeto
 */
void imprimeLista(Lista *lista, void (*imprimeObjeto)(Objeto *)){
    if(listaVazia(lista))
        return;
    Objeto *atual = lista->inicio;
    while(atual != NULL){
        imprimeObjeto(atual);
        atual = atual->proximo;
    }
}

/**
 * @brief Retorna true se a lista estiver vazia e false, caso contrário
 * Complexidade: O(1)
 * 
 * @param lista: ponteiro da lista
 * @return true ou false
 */
bool listaVazia(Lista *lista){
    if (lista == NULL)
        return true;
    return (lista->inicio == NULL);
}

/**
 * @brief Retorna o número de elementos da lista
 * Complexidade: O(1)
 * 
 * @param lista: ponteiro da lista
 * @return int 
 */
int tamanhoLista(Lista *lista){
    if (lista == NULL)
        return 0;
    return lista->n;
}

/**
 * @brief Retorna um ponteiro para o primeiro elemento da lista
 * Complexidade: O(1)
 * 
 * @param lista: ponteiro da lista 
 * @return Objeto* 
 */
Objeto *getPrimeiro(Lista *lista) {
    if (lista == NULL) 
        return NULL;
    return lista->inicio;
}
