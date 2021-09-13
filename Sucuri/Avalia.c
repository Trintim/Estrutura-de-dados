#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Avalia.h"
#include "Categorias.h"
#include "Pilha.h"
#include "Util.h"

Objeto *avalia(Fila *posFixa) {

    Pilha *entrada = criaPilha();
    Objeto *saida = criaObjeto();

    while(tamanhoFila(posFixa)){

        Objeto *noposFixa = front(posFixa);

        if (noposFixa->categoria == INT || noposFixa->categoria == FLOAT){

            empilha(entrada, copiaObjeto(noposFixa));
        }
        else if (noposFixa->categoria == OPER_MENOS_UNARIO){

            Objeto *execute = topoPilha(entrada);
            if (execute->categoria == FLOAT){
                saida->valor.vFloat = execute->valor.vFloat * (-1);
                saida->categoria = FLOAT;
            }
            else{
                saida->valor.vInt = execute->valor.vInt * (-1);
                saida->categoria = INT;
            }
            desempilha(entrada);
            empilha(entrada, copiaObjeto(saida));
        }
        else if (noposFixa->categoria <= 5){

            Objeto *execute1 = copiaObjeto(topoPilha(entrada));
            desempilha(entrada);
            Objeto *execute2 = copiaObjeto(topoPilha(entrada));
            desempilha(entrada);

            if (noposFixa->categoria == OPER_EXPONENCIACAO){

                if (execute1->categoria == FLOAT && execute2->categoria == FLOAT){

                    saida->valor.vFloat = pow(execute2->valor.vFloat, execute1->valor.vFloat);
                    saida->categoria = FLOAT;
                }
                else if (execute1->categoria == FLOAT){

                    saida->valor.vFloat = pow(execute2->valor.vInt, execute1->valor.vFloat);
                    saida->categoria = FLOAT;
                }
                else if (execute2->categoria == FLOAT){

                    saida->valor.vFloat = pow(execute2->valor.vFloat, execute1->valor.vInt);
                    saida->categoria = FLOAT;
                }
                else{

                    saida->valor.vInt = pow(execute2->valor.vInt, execute1->valor.vInt);
                    saida->categoria = INT;
                }
            }

            else if (noposFixa->categoria == OPER_RESTO_DIVISAO){

                if (execute1->categoria == FLOAT && execute2->categoria == FLOAT){

                    saida->valor.vFloat = fmod(execute2->valor.vFloat, execute1->valor.vFloat);
                    saida->categoria = FLOAT;
                }
                else if (execute1->categoria == FLOAT){

                    saida->valor.vFloat = fmod(execute2->valor.vInt, execute1->valor.vFloat);
                    saida->categoria = FLOAT;
                }
                else if (execute2->categoria == FLOAT){

                    saida->valor.vFloat = fmod(execute2->valor.vFloat, execute1->valor.vInt);
                    saida->categoria = FLOAT;
                }
                else{

                    saida->valor.vInt = execute2->valor.vInt % execute1->valor.vInt;
                    saida->categoria = INT;
                }
            }

            else if (noposFixa->categoria == OPER_MULTIPLICACAO ){

                if (execute1->categoria == FLOAT && execute2->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vFloat * execute1->valor.vFloat;
                    saida->categoria = FLOAT;
                }
                else if (execute1->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vInt * execute1->valor.vFloat;
                    saida->categoria = FLOAT;
                }
                else if (execute2->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vFloat * execute1->valor.vInt;
                    saida->categoria = FLOAT;
                }
                else{

                    saida->valor.vInt = execute2->valor.vInt * execute1->valor.vInt;
                    saida->categoria = INT;
                }
            }

            else if (noposFixa->categoria == OPER_DIVISAO){

                if (execute1->categoria == FLOAT && execute2->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vFloat / execute1->valor.vFloat;
                    saida->categoria = FLOAT;
                }
                else if (execute1->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vInt / execute1->valor.vFloat;
                    saida->categoria = FLOAT;
                }
                else if (execute2->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vFloat / execute1->valor.vInt;
                    saida->categoria = FLOAT;
                }
                else{

                    saida->valor.vInt = execute2->valor.vInt / execute1->valor.vInt;
                    saida->categoria = INT;
                }
            }

            else if (noposFixa->categoria == OPER_ADICAO){

                if (execute1->categoria == FLOAT && execute2->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vFloat + execute1->valor.vFloat;
                    saida->categoria = FLOAT;
                }
                else if (execute1->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vInt + execute1->valor.vFloat;
                    saida->categoria = FLOAT;
                }
                else if (execute2->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vFloat + execute1->valor.vInt;
                    saida->categoria = FLOAT;
                }
                else{

                    saida->valor.vInt = execute2->valor.vInt + execute1->valor.vInt;
                    saida->categoria = INT;
                }
            }

            else if (noposFixa->categoria == OPER_SUBTRACAO){

                if (execute1->categoria == FLOAT && execute2->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vFloat - execute1->valor.vFloat;
                    saida->categoria = FLOAT;
                }
                else if (execute1->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vInt - execute1->valor.vFloat;
                    saida->categoria = FLOAT;
                }
                else if (execute2->categoria == FLOAT){

                    saida->valor.vFloat = execute2->valor.vFloat - execute1->valor.vInt;
                    saida->categoria = FLOAT;
                }
                else{

                    saida->valor.vInt = execute2->valor.vInt - execute1->valor.vInt;
                    saida->categoria = INT;
                }
            }

            liberaObjeto(execute1);
            liberaObjeto(execute2);
            empilha(entrada, copiaObjeto(saida));
        }
        dequeue(posFixa);
    }

    liberaObjeto(saida);
    saida = copiaObjeto(topoPilha(entrada));
    liberaPilha(entrada);
    return saida;
}
