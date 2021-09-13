#include <stdio.h>
#include <stdlib.h>

#include "Posfixa.h"
#include "Pilha.h"

/**
 * @brief Converte uma fila de objetos em notação infixa em notação pós-fixa.
 * Pseudo-código (retirado do PDF do EP):
 * - Crie uma pilha vazia para manter os operadores.
 * - Crie uma fila vazia para a saída.
 * - Examine cada objeto da fila infixa e se o objeto for:
 *   - um operando (FLOAT ou INT), coloque-o na fila de saída.
 *   - um abre parêntese (ABRE_PARENTESES), insira-o na pilha.
 *   - um fecha parênteses (FECHA_PARENTESES), remova os objetos da pilha até
 *     que o abre parêntese correspondente seja removido. Coloque cada operador
 *     removido na fila de saída.
 *   - um operador insira-o na pilha. Entretanto, remova antes os operadores que
 *     estão na pilha que têm precedência maior ou igual ao operador encontrado e
 *     coloque-os na fila de saída. Lembre-se que o campo valor de um objeto que
 *     armazena um operador contém o valor da sua precedência (quanto maior esse
 *     valor, maior é a precedência do operador).
 * - Quando a expressão tiver sido completamente examinada, verifique a pilha.
 *   Qualquer operador que ainda está na pilha deve ser removido e colocado na
 *   fila de saída.
 *
 * Para evitar problemas de vazamento de memória e/ou falha de segmentação, se
 * nas funções 'enqueue' (Fila.c) e 'empilha' (Pilha.c) você optou por *apenas
 * incluir o objeto* (sem fazer cópia dos mesmos), passe uma cópia do objeto
 * sempre que essas funções (enqueue e empilha) forem utilizadas.
 * Lembre-se que a função 'desempilha' (Pilha.h) e 'dequeue' (Fila.h)
 * fazem a desalocação dos objetos (liberaObjeto)
 *
 * @param infixa Fila de objeto em notação infixa
 * @return Fila*
 */
Fila *infixaParaPosfixa(Fila *infixa) {
    Pilha *entryOperators = criaPilha();
    Fila *out = criaFila();
    while(tamanhoFila(infixa)){
        Objeto *noInfixa = front(infixa);
        if (noInfixa->categoria == FLOAT || noInfixa->categoria == INT){
            enqueue(out, copiaObjeto(noInfixa));
        }
        else if (noInfixa->categoria == ABRE_PARENTESES){
            empilha(entryOperators, copiaObjeto(noInfixa));
        }
        else if (noInfixa->categoria == FECHA_PARENTESES){
            while(1){
                Objeto *operador = topoPilha(entryOperators);
                if (operador->categoria == ABRE_PARENTESES){
                    desempilha(entryOperators);
                    break;
                }
                enqueue(out, copiaObjeto(operador));
                desempilha(entryOperators);
            }
        }
        else if(noInfixa->categoria == 0 || noInfixa->categoria == 6){
            empilha(entryOperators, copiaObjeto(noInfixa));
        }
        else{
            while(1){
                Objeto *operador = topoPilha(entryOperators);
                if (operador == NULL || operador->valor.vInt < noInfixa->valor.vInt){
                    break;
                }
                enqueue(out, copiaObjeto(operador));
                desempilha(entryOperators);
            }
            empilha(entryOperators, copiaObjeto(noInfixa));
        }
        dequeue(infixa);
    }
    while(tamanhoPilha(entryOperators)){
        Objeto *operador = topoPilha(entryOperators);
        enqueue(out, copiaObjeto(operador));
        desempilha(entryOperators);
    }
    liberaPilha(entryOperators);
    return out;
}

/**
 * @brief Imprime a fila de objeto em notação pós-fixa
 *
 * @param posfixa Fila com os objeto que se seja imprimir
 */
void imprimePosFixa(Fila *posfixa) {
    //Como temos que desempilhar (ou seja, os elementos serão apagados)
    //precisamos fazer uma cópia da fila para não perdermos os objetos.
    //Então, usamos a cópia para imprimir os objetos
    Fila *f = copiaFila(posfixa);
    while(!filaVazia(f)) {
        Objeto *obj = front(f);
        imprimeObjeto(obj, POSFIXA);
        dequeue(f);
    }
    printf("\n");
    liberaFila(f);
}