#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Avalia.h"
#include "Categorias.h"
#include "Pilha.h"
#include "Util.h"

/**
 * @brief Faz a avaliação da expressão em notação pós-fixa e retorna o resultado da expressão.
 * A sua função deve examinar cada objeto da fila 'posFixa' e:
 * - Se o objeto for um operando (FLOAT ou INT), empilhar o objeto;
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
    //AVISO(Avalia.c: ainda não completei a função 'avalia');
    Pilha *aux = criaPilha();
    while (!filaVazia(posFixa))
    {
        if (front(posFixa)->categoria == INT || front(posFixa)->categoria == FLOAT){
            empilha(aux, copiaObjeto(front(posFixa)));
        }
        else{
            switch (front(posFixa)->categoria)
            {
            case OPER_EXPONENCIACAO:;
                Objeto* y = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                Objeto* x = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                if (y->categoria == FLOAT){
                    if(x->categoria == FLOAT){
                        x->valor.vFloat = pow(x->valor.vFloat, y->valor.vFloat);
                    }
                    else{
                        x->valor.vFloat = pow(x->valor.vInt, y->valor.vFloat);
                        x->categoria = FLOAT;
                    }
                }
                else if(x->categoria == FLOAT){
                    x->valor.vFloat = pow(x->valor.vFloat, y->valor.vInt);
                }
                else{
                    x->valor.vInt = pow(x->valor.vInt, y->valor.vInt);
                }
                empilha(aux, copiaObjeto(x));
                liberaObjeto(x);
                liberaObjeto(y);
                break;

            case OPER_ADICAO:;
                Objeto* somaY = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                Objeto* somaX = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                if (somaY->categoria == FLOAT){
                    if(somaX->categoria == FLOAT){
                        somaX->valor.vFloat = somaX->valor.vFloat + somaY->valor.vFloat;
                    }
                    else{
                        somaX->valor.vFloat = somaX->valor.vInt + somaY->valor.vFloat;
                        somaX->categoria = FLOAT;
                    }
                }
                else if(somaX->categoria == FLOAT){
                    somaX->valor.vFloat = somaX->valor.vFloat + somaY->valor.vInt;
                }
                else{
                    somaX->valor.vInt = somaX->valor.vInt + somaY->valor.vInt;
                }
                empilha(aux, copiaObjeto(somaX));
                liberaObjeto(somaX);
                liberaObjeto(somaY);
                break;
            case OPER_SUBTRACAO:;
                Objeto* subY = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                Objeto* subX = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                if (subY->categoria == FLOAT){
                    if(subX->categoria == FLOAT){
                        subX->valor.vFloat = subX->valor.vFloat - subY->valor.vFloat;
                    }
                    else{
                        subX->valor.vFloat = subX->valor.vInt - subY->valor.vFloat;
                        subX->categoria = FLOAT;
                    }
                }
                else if(subX->categoria == FLOAT){
                    subX->valor.vFloat = subX->valor.vFloat - subY->valor.vInt;
                }
                else{
                    subX->valor.vInt = subX->valor.vInt - subY->valor.vInt;
                }
                empilha(aux, copiaObjeto(subX));
                liberaObjeto(subX);
                liberaObjeto(subY);
                break;
            case OPER_MULTIPLICACAO:;
                Objeto* multY = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                Objeto* multX = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                if (multY->categoria == FLOAT){
                    if(multX->categoria == FLOAT){
                        multX->valor.vFloat = multX->valor.vFloat * multY->valor.vFloat;
                    }
                    else{
                        multX->valor.vFloat = multX->valor.vInt * multY->valor.vFloat;
                        multX->categoria = FLOAT;
                    }
                }
                else if(multX->categoria == FLOAT){
                    multX->valor.vFloat = multX->valor.vFloat * multY->valor.vInt;
                }
                else{
                    multX->valor.vInt = multX->valor.vInt * multY->valor.vInt;
                }
                empilha(aux, copiaObjeto(multX));
                liberaObjeto(multX);
                liberaObjeto(multY);
                break;
            case OPER_DIVISAO:;
                Objeto* divY = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                Objeto* divX = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                if (divY->categoria == FLOAT){
                    if(divX->categoria == FLOAT){
                        divX->valor.vFloat = divX->valor.vFloat / divY->valor.vFloat;
                    }
                    else{
                        divX->valor.vFloat = divX->valor.vInt / divY->valor.vFloat;
                        divX->categoria = FLOAT;
                    }
                }
                else if(divX->categoria == FLOAT){
                    divX->valor.vFloat = divX->valor.vFloat / divY->valor.vInt;
                }
                else{
                    divX->valor.vInt = divX->valor.vInt / divY->valor.vInt;
                }
                empilha(aux, copiaObjeto(divX));
                liberaObjeto(divX);
                liberaObjeto(divY);
                break;
            case OPER_RESTO_DIVISAO:;
                Objeto* divRestoY = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                Objeto* divRestoX = copiaObjeto(topoPilha(aux));
                desempilha(aux);
                if (divRestoY->categoria == FLOAT){
                    if(divRestoX->categoria == FLOAT){
                        divRestoX->valor.vFloat = fabs(divRestoX->valor.vFloat - divRestoY->valor.vFloat);
                    }
                    else{
                        divRestoX->valor.vFloat = fabs(divRestoX->valor.vInt - divRestoY->valor.vFloat);
                        divRestoX->categoria = FLOAT;
                    }
                }
                else if(divRestoX->categoria == FLOAT){
                    divRestoX->valor.vFloat = fabs(divRestoX->valor.vFloat - divRestoY->valor.vInt);
                }
                else{
                    divRestoX->valor.vInt = divRestoX->valor.vInt % divRestoY->valor.vInt;
                }
                empilha(aux, copiaObjeto(divRestoX));
                liberaObjeto(divRestoX);
                liberaObjeto(divRestoY);
                break;
            case OPER_MENOS_UNARIO:;
            Objeto* uniX = copiaObjeto(topoPilha(aux));
            desempilha(aux);
            if (uniX->categoria == FLOAT)
                uniX->valor.vFloat = -uniX->valor.vFloat;
            else
                uniX->valor.vInt = -uniX->valor.vInt;
            empilha(aux, copiaObjeto(uniX));
            liberaObjeto(uniX);
            break;
            default:
                break;
            }
        }
        dequeue(posFixa);
    }
    Objeto *cpy = copiaObjeto(topoPilha(aux));
    liberaPilha(aux);
    return cpy;
}
