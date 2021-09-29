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
 * @return Objeto * */
Objeto *avalia(Fila *posFixa) {
    //AVISO(Avalia.c: ainda não completei a função 'avalia');
    Pilha *entrada = criaPilha();
    while (!filaVazia(posFixa))
    {
        if (front(posFixa)->categoria == INT || front(posFixa)->categoria == FLOAT){
            empilha(entrada, copiaObjeto(front(posFixa)));
        }
        else{
            switch (front(posFixa)->categoria)
            {
            case OPER_EXPONENCIACAO:;
                Objeto *y = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                Objeto *x = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
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
                empilha(entrada, copiaObjeto(x));
                liberaObjeto(x);
                liberaObjeto(y);
                break;

            case OPER_ADICAO:;
                Objeto *soma1 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                Objeto *soma2 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                if (soma1->categoria == FLOAT){
                    if(soma2->categoria == FLOAT){
                        soma2->valor.vFloat = soma2->valor.vFloat + soma1->valor.vFloat;
                    }
                    else{
                        soma2->valor.vFloat = soma2->valor.vInt + soma1->valor.vFloat;
                        soma2->categoria = FLOAT;
                    }
                }
                else if(soma2->categoria == FLOAT){
                    soma2->valor.vFloat = soma2->valor.vFloat + soma1->valor.vInt;
                }
                else{
                    soma2->valor.vInt = soma2->valor.vInt + soma1->valor.vInt;
                }
                empilha(entrada, copiaObjeto(soma2));
                liberaObjeto(soma2);
                liberaObjeto(soma1);
                break;
            case OPER_SUBTRACAO:;
                Objeto *subtrai1 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                Objeto *subtrai2 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                if (subtrai1->categoria == FLOAT){
                    if(subtrai2->categoria == FLOAT){
                        subtrai2->valor.vFloat = subtrai2->valor.vFloat - subtrai1->valor.vFloat;
                    }
                    else{
                        subtrai2->valor.vFloat = subtrai2->valor.vInt - subtrai1->valor.vFloat;
                        subtrai2->categoria = FLOAT;
                    }
                }
                else if(subtrai2->categoria == FLOAT){
                    subtrai2->valor.vFloat = subtrai2->valor.vFloat - subtrai1->valor.vInt;
                }
                else{
                    subtrai2->valor.vInt = subtrai2->valor.vInt - subtrai1->valor.vInt;
                }
                empilha(entrada, copiaObjeto(subtrai2));
                liberaObjeto(subtrai2);
                liberaObjeto(subtrai1);
                break;
            case OPER_MULTIPLICACAO:;
                Objeto *multiplica1 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                Objeto *multiplica2 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                if (multiplica1->categoria == FLOAT){
                    if(multiplica2->categoria == FLOAT){
                        multiplica2->valor.vFloat = multiplica2->valor.vFloat * multiplica1->valor.vFloat;
                    }
                    else{
                        multiplica2->valor.vFloat = multiplica2->valor.vInt * multiplica1->valor.vFloat;
                        multiplica2->categoria = FLOAT;
                    }
                }
                else if(multiplica2->categoria == FLOAT){
                    multiplica2->valor.vFloat = multiplica2->valor.vFloat * multiplica1->valor.vInt;
                }
                else{
                    multiplica2->valor.vInt = multiplica2->valor.vInt * multiplica1->valor.vInt;
                }
                empilha(entrada, copiaObjeto(multiplica2));
                liberaObjeto(multiplica2);
                liberaObjeto(multiplica1);
                break;
            case OPER_DIVISAO:;
                Objeto *divide1 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                Objeto *divide2 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                if (divide1->categoria == FLOAT){
                    if(divide2->categoria == FLOAT){
                        divide2->valor.vFloat = divide2->valor.vFloat / divide1->valor.vFloat;
                    }
                    else{
                        divide2->valor.vFloat = divide2->valor.vInt / divide1->valor.vFloat;
                        divide2->categoria = FLOAT;
                    }
                }
                else if(divide2->categoria == FLOAT){
                    divide2->valor.vFloat = divide2->valor.vFloat / divide1->valor.vInt;
                }
                else{
                    divide2->valor.vInt = divide2->valor.vInt / divide1->valor.vInt;
                }
                empilha(entrada, copiaObjeto(divide2));
                liberaObjeto(divide2);
                liberaObjeto(divide1);
                break;
            case OPER_RESTO_DIVISAO:;
                Objeto *resto1 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                Objeto *resto2 = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                if (resto1->categoria == FLOAT){
                    if(resto2->categoria == FLOAT){
                        resto2->valor.vFloat = fabs(resto2->valor.vFloat - resto1->valor.vFloat);
                    }
                    else{
                        resto2->valor.vFloat = fabs(resto2->valor.vInt - resto1->valor.vFloat);
                        resto2->categoria = FLOAT;
                    }
                }
                else if(resto2->categoria == FLOAT){
                    resto2->valor.vFloat = fabs(resto2->valor.vFloat - resto1->valor.vInt);
                }
                else{
                    resto2->valor.vInt = resto2->valor.vInt % resto1->valor.vInt;
                }
                empilha(entrada, copiaObjeto(resto2));
                liberaObjeto(resto2);
                liberaObjeto(resto1);
                break;
            case OPER_MENOS_UNARIO:;
                Objeto *menosUnitario = copiaObjeto(topoPilha(entrada));
                desempilha(entrada);
                if (menosUnitario->categoria == FLOAT)
                    menosUnitario->valor.vFloat = -menosUnitario->valor.vFloat;
                else
                    menosUnitario->valor.vInt = -menosUnitario->valor.vInt;
                empilha(entrada, copiaObjeto(menosUnitario));
                liberaObjeto(menosUnitario);
                break;
                default:
                break;
            }
        }
        dequeue(posFixa);
    }
    Objeto *copia = copiaObjeto(topoPilha(entrada));
    liberaPilha(entrada);
    return copia;
}
