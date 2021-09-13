#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Avalia.h"
#include "Categorias.h"
#include "Pilha.h"
#include "Util.h"

/**
 * @brief Faz a avaliação da expressão em notação pós-fixa e retorna o fimOperacao da expressão.
 * A sua função deve examinar cada objeto da fila 'posFixa' e:
 * - Se o objeto for um aplicacao (FLOAT ou INT), empilhar o objeto;
 * - Se o objeto contém um operador, então:
 *   - Desempilhar um ou dois números da pilha, dependendo do tipo do operador;
 *   - Calcular o valor da operação correspondente; e
 *   - Empilhar o valor calculado.
 * Ao final (quando a fila estiver vazia), retorne o objeto (ou uma cópia) do topo da pilha.
 *
 * @param posFixa Fila com os objeto em notação pos-fixa
 * @return Objeto*
 */
Objeto *avalia(Fila *posFixa) {

    Pilha *operacoes = criaPilha();
    Objeto *fimOperacao = criaObjeto();
    while(tamanhoFila(posFixa)){
        Objeto *noPosFixa = front(posFixa);
        if (noPosFixa->categoria == INT || noPosFixa->categoria == FLOAT){
            empilha(operacoes, copiaObjeto(noPosFixa));
        }
        else if (noPosFixa->categoria == OPER_MENOS_UNARIO){
            Objeto *aplicacao = topoPilha(operacoes);
            if (aplicacao->categoria == FLOAT){
                fimOperacao->valor.vFloat = aplicacao->valor.vFloat * (-1);
                fimOperacao->categoria = FLOAT;
            }
            else{
                fimOperacao->valor.vInt = aplicacao->valor.vInt * (-1);
                fimOperacao->categoria = INT;
            }
            desempilha(operacoes);
            empilha(operacoes, copiaObjeto(fimOperacao));
        }
        else if (noPosFixa->categoria <= 5){
            Objeto *aplicacao1 = copiaObjeto(topoPilha(operacoes));
            desempilha(operacoes);
            Objeto *aplicacao2 = copiaObjeto(topoPilha(operacoes));
            desempilha(operacoes);
            if (noPosFixa->categoria == OPER_EXPONENCIACAO){
                if (aplicacao1->categoria == FLOAT && aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = pow(aplicacao2->valor.vFloat, aplicacao1->valor.vFloat);
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao1->categoria == FLOAT){
                    fimOperacao->valor.vFloat = pow(aplicacao2->valor.vInt, aplicacao1->valor.vFloat);
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = pow(aplicacao2->valor.vFloat, aplicacao1->valor.vInt);
                    fimOperacao->categoria = FLOAT;
                }
                else{
                    fimOperacao->valor.vInt = pow(aplicacao2->valor.vInt, aplicacao1->valor.vInt);
                    fimOperacao->categoria = INT;
                }
            }
            else if (noPosFixa->categoria == OPER_RESTO_DIVISAO){
                if (aplicacao1->categoria == FLOAT && aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = fmod(aplicacao2->valor.vFloat, aplicacao1->valor.vFloat);
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao1->categoria == FLOAT){
                    fimOperacao->valor.vFloat = fmod(aplicacao2->valor.vInt, aplicacao1->valor.vFloat);
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = fmod(aplicacao2->valor.vFloat, aplicacao1->valor.vInt);
                    fimOperacao->categoria = FLOAT;
                }
                else{
                    fimOperacao->valor.vInt = aplicacao2->valor.vInt % aplicacao1->valor.vInt;
                    fimOperacao->categoria = INT;
                }
            }
            else if (noPosFixa->categoria == OPER_MULTIPLICACAO ){
                if (aplicacao1->categoria == FLOAT && aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vFloat * aplicacao1->valor.vFloat;
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao1->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vInt * aplicacao1->valor.vFloat;
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vFloat * aplicacao1->valor.vInt;
                    fimOperacao->categoria = FLOAT;
                }
                else{
                    fimOperacao->valor.vInt = aplicacao2->valor.vInt * aplicacao1->valor.vInt;
                    fimOperacao->categoria = INT;
                }
            }
            else if (noPosFixa->categoria == OPER_DIVISAO){
                if (aplicacao1->categoria == FLOAT && aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vFloat / aplicacao1->valor.vFloat;
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao1->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vInt / aplicacao1->valor.vFloat;
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vFloat / aplicacao1->valor.vInt;
                    fimOperacao->categoria = FLOAT;
                }
                else{
                    fimOperacao->valor.vInt = aplicacao2->valor.vInt / aplicacao1->valor.vInt;
                    fimOperacao->categoria = INT;
                }
            }
            else if (noPosFixa->categoria == OPER_ADICAO){
                if (aplicacao1->categoria == FLOAT && aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vFloat + aplicacao1->valor.vFloat;
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao1->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vInt + aplicacao1->valor.vFloat;
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vFloat + aplicacao1->valor.vInt;
                    fimOperacao->categoria = FLOAT;
                }
                else{
                    fimOperacao->valor.vInt = aplicacao2->valor.vInt + aplicacao1->valor.vInt;
                    fimOperacao->categoria = INT;
                }
            }
            else if (noPosFixa->categoria == OPER_SUBTRACAO){
                if (aplicacao1->categoria == FLOAT && aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vFloat - aplicacao1->valor.vFloat;
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao1->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vInt - aplicacao1->valor.vFloat;
                    fimOperacao->categoria = FLOAT;
                }
                else if (aplicacao2->categoria == FLOAT){
                    fimOperacao->valor.vFloat = aplicacao2->valor.vFloat - aplicacao1->valor.vInt;
                    fimOperacao->categoria = FLOAT;
                }
                else{
                    fimOperacao->valor.vInt = aplicacao2->valor.vInt - aplicacao1->valor.vInt;
                    fimOperacao->categoria = INT;
                }
            }

            liberaObjeto(aplicacao1);
            liberaObjeto(aplicacao2);
            empilha(operacoes, copiaObjeto(fimOperacao));
        }
        dequeue(posFixa);
    }
    liberaObjeto(fimOperacao);
    fimOperacao = copiaObjeto(topoPilha(operacoes));
    liberaPilha(operacoes);
    return fimOperacao;
}
