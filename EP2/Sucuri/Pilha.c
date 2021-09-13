#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

typedef struct pilha {
    Objeto *inicio;
    int n;
} Pilha;

/**
 * @brief Faz a alocação de memória para a Pilha
 *
 * @return Fila*
 */
Pilha *criaPilha(){
    Pilha *p = mallocSafe(sizeof(Pilha));
    p->inicio  = NULL;
    p->n = 0;
    return p;
}

/**
 * @brief Faz a liberação de memória dinamicamente alocada
 * por cada objeto da pilha
 *
 * @param pilha
 */
void liberaPilha(Pilha *pilha) {

    Objeto *no = pilha->inicio;
    while(no){
        Objeto *aux = no;
        no = no->proximo;
        liberaObjeto(aux);
    }
    free(pilha);
}

/**
 * @brief Insere um novo objeto a pilha. Como na função 'enqueue' da Fila,
 * você pode apenas incluir o objeto na pilha ou
 * fazer uma cópia do objeto e incluir essa cópia.
 *
 * @param pilha Ponteiro para a pilha onde o objeto deve ser inserido
 * @param objeto Objeto a ser inserido
 */
void empilha(Pilha *pilha, Objeto *objeto) {

    if (pilha->inicio == NULL){
        pilha->inicio = objeto;
    }
    else{
        objeto->proximo = pilha->inicio;
        pilha->inicio = objeto;
    }
    pilha->n++;
}

/**
 * @brief Remove (apaga) o objeto do topo da pilha
 *
 * @param pilha Ponteiro para a pilha
 */
void desempilha(Pilha *pilha){

    if (!pilha->n){
        return;
    }
    Objeto *no = pilha->inicio;
    pilha->inicio = pilha->inicio->proximo;
    liberaObjeto(no);
    pilha->n--;
}

/**
 * @brief Retorna (sem apagar) o objeto do topo da pilha
 *
 * @param pilha Ponteiro para a pilha
 * @return Objeto*
 */
Objeto *topoPilha(Pilha *pilha){
    return pilha->inicio;
}

/**
 * @brief Verifica se a pilha está vazia
 *
 * @param pilha Ponteiro para a pilha
 * @return true ou false
 */
bool pilhaVazia(Pilha *pilha){
    return (pilha == NULL || pilha->n == 0);
}

/**
 * @brief Retorna o número de objetos na pilha
 *
 * @param pilha Ponteiro para a pilha
 * @return int
 */
int tamanhoPilha(Pilha *pilha) {
    if (pilhaVazia(pilha)) return 0;
    return pilha->n;
}

/**
 * @brief Fução que imprime os elementos da pilha.
 * Essa função pode ajudar a detectar problemas nos objetos da pilha
 * Para imprimir um objeto, use (chame) a função imprimeObjeto.
 *
 * @param pilha Ponteiro para a pilha que se deseja imprimeir
 * @param tipo Tipo da impressão (veja a função imprimeObjeto no arquivo Objeto.c)
 */
void imprimePilha(Pilha *pilha, int tipo) {
    Objeto *no = pilha->inicio;
    while(no){
        imprimeObjeto(no, tipo);
        no = no->proximo;
    }
}