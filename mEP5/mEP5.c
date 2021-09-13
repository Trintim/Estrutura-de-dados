#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Util.h"
#include "Objetos.h"
#include "Lista.h"
#include "mEP5.h"

/**
 * @brief Verifica se a lista com a expressão matemática (que pode contér números e simbolos)
 * é uma expressão válida. Além disso, ela também deve verificar se os operados são válidos,
 * ou seja, se são '+' ou '-' (únicos que serão considerados válidos nesse miniEP).
 * Uma expressão deve ser considerada inválida se:
 * - Houver a leitura de dois objetos seguidos do mesmo tipo (por exemplo, dois objetos do tipo STR
 *   ou dois objetos numéricos);
 * - Terminar com um operador;
 * - Se o operador não for soma (+) ou subtração (-).
 *
 * @param expressao: lista encadeada com os itens (números e possíveis operadores)
 * @return true ou false
 */
bool expressaoValida(Lista *expressao) {
    //AVISO("Avalia.c: Ainda não completei a função 'expressaoValida'");

    if(!expressao)
        return false;

    Objeto *objA = getPrimeiro(expressao);
    int valor = 0;
    int valor2 = 0;

    while(objA){

        if(!objA->proximo){
            if(objA->tipo == STR)
            return false;
        }
        else{
            if(objA->tipo == objA->proximo->tipo){
                return false;
            }
            else if(objA->tipo == STR){
                valor = strcmp(objA->item.vString, "+");
                valor2 = strcmp(objA->item.vString, "-");
                if(valor != 0 && valor2 != 0){
                    return false;
                }
            }
        }
        objA = objA->proximo;
    }

    return true;
}

/**
 * @brief Calcula o valor da expressão presente em 'expressão'. Supõem-se que a
 * expressão é válida.
 *
 * Exemplos:
 * - 10 = -10
 * 10 = 10
 * 10 + -15 = -5 (o '-15' significa o número inteiro -15 e não o operador '-' seguido do número 15)
 * - 10 + 15 = 5
 * -10 - -15 = 5
 * - -10 - -15 = 25
 * + 10 + -15 = -5
 * 3.5 + 10 = 13.5 (note que se um valor for real, o resultado final *deve* ser real)
 *
 * @param expressao: lista encadeada com os itens (números e possíveis operadores)
 * @return Objeto*
 */
Objeto *avaliaExpressao(Lista *expressao) {
    Objeto *resultado = criaObjeto();

    Objeto *no1 = getPrimeiro(expressao);;
    double cont = 0;

    if(no1->tipo == INT){
        cont += no1->item.vInt;
        resultado->tipo = INT;
    }
    else if(no1->tipo == FLOAT){
        cont += no1->item.vFloat;
        resultado->tipo = FLOAT;
    }
    while(no1){
        if(no1->tipo == STR){
            if(strcmp(no1->item.vString, "+") == 0){
                if(no1->proximo->tipo == INT){
                    if(resultado->tipo == INDEFINIDO){
                        resultado->tipo = INT;
                    }
                    cont += no1->proximo->item.vInt;
                }
                else{
                    if (no1->proximo->tipo == FLOAT){
                        resultado->tipo = FLOAT;
                    }
                    cont += no1->proximo->item.vFloat;
                }
            }
            else{
                if(no1->proximo->tipo == INT){
                    if (resultado->tipo == INDEFINIDO){
                        resultado->tipo = INT;
                    }
                    cont -= no1->proximo->item.vInt;
                }
                else{
                    if (no1->proximo->tipo == FLOAT){
                        resultado->tipo = FLOAT;
                    }
                    cont -= no1->proximo->item.vFloat;
                }
            }
        }
        no1 = no1->proximo;
    }

    if (resultado->tipo == FLOAT){
        resultado->item.vFloat = cont;
    }
    else if(resultado->tipo == INT){
        resultado->item.vInt = cont;
    }

    return resultado;
}