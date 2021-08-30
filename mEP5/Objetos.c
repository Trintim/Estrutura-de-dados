#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Objetos.h"

/**
 * @brief Cria um objeto sem tipo definido
 * 
 * @return Objeto* 
 */
Objeto *criaObjeto() {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = INDEFINIDO;
    obj->item.vString = NULL;
    obj->proximo = NULL;
    return obj;
}

/**
 * @brief Cria um objeto para armazenar um número inteiro
 * 
 * @param valor Valor a ser armazenado no objeto
 * @return Objeto* 
 */
Objeto *criaObjetoInteiro(int valor) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = INT;
    obj->item.vInt = valor;
    obj->proximo = NULL;
    return obj;
}

/**
 * @brief Cria um objeto para armazenar um número real (ponto flutuante)
 * 
 * @param valor Valor a ser armazenado no objeto 
 * @return Objeto* 
 */
Objeto *criaObjetoReal(double valor) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = FLOAT;
    obj->item.vFloat = valor;
    obj->proximo = NULL;
    return obj;
}

/**
 * @brief Cria um objeto para armazenar um string.
 * 
 * @param palavra String a ser armazenado no objeto
 * @return Objeto* 
 */
Objeto *criaObjetoString(char *palavra) {
    Objeto *obj = malloc(sizeof(Objeto));
    obj->tipo = STR;
    obj->item.vString = malloc((strlen(palavra) + 1) * sizeof(char));
    strcpy(obj->item.vString, palavra);
    obj->proximo = NULL;
    return obj;
}

/**
 * @brief Faz a desalocação de memória apontada pelo objeto.
 * 
 * @param obj Ponteiro para o objeto a ser desalocado
 */
void liberaObjeto(Objeto *obj) {
    if(obj == NULL) return;
    if (obj->tipo == STR && obj->item.vString)
        free(obj->item.vString);
    free(obj);
}

/**
 * @brief Imprime a informação detalhada contida no objeto.
 * 
 * @param obj Objeto a ser impresso
 */
void imprimeInformacaoObjeto(Objeto *obj) {
    if (obj == NULL)
        return;
    if(obj->tipo == INT) {
        printf("Inteiro com valor: %d\n", obj->item.vInt);
    }
    else if (obj->tipo == FLOAT) {
        printf("Real com valor: %.5lf\n", obj->item.vFloat);
    }
    else if (obj->tipo == STR) {
        printf("String com valor: %s\n", obj->item.vString);
    }
    else {
        printf("Tipo não reconhecido\n");
    }
}

/**
 * @brief Imprime a informação resumida contida no objeto.
 * Diferente da função 'imprimeInformacaoObjeto', nessa função é impresso
 * apenas o valor do item de acordo com o seu tipo (INT, FLOAT, STR).
 * 
 * @param obj Objeto a ser impresso
 */
void imprimeItemObjeto(Objeto *obj) {
    if (obj == NULL)
        return;
    if(obj->tipo == INT) {
        printf("%d ", obj->item.vInt);
    }
    else if (obj->tipo == FLOAT) {
        printf("%.5lf ", obj->item.vFloat);
    }
    else if (obj->tipo == STR) {
        printf("%s ", obj->item.vString);
    }
    else {
        printf("Tipo não reconhecido ");
    }
}