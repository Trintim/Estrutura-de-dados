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

    Fila *saida = criaFila();
    Pilha *entradaOperadores = criaPilha();
    while (!filaVazia(infixa)){

        if (front(infixa)->categoria == INT || front(infixa)->categoria == FLOAT){
            enqueue(saida, copiaObjeto(front(infixa)));
        }
        else if(front(infixa)->categoria == ABRE_PARENTESES){
            empilha(entradaOperadores, copiaObjeto(front(infixa)));
        }
        else if(front(infixa)->categoria == FECHA_PARENTESES){
            while (!pilhaVazia(entradaOperadores) && topoPilha(entradaOperadores)->categoria != ABRE_PARENTESES)
            {
                enqueue(saida, copiaObjeto(topoPilha(entradaOperadores)));
                desempilha(entradaOperadores);

            }
            desempilha(entradaOperadores);
        }
        else{
            if (front(infixa)->categoria == OPER_EXPONENCIACAO || front(infixa)->categoria == OPER_MENOS_UNARIO){
                    empilha(entradaOperadores, copiaObjeto(front(infixa)));
            }
            else{
                while (!pilhaVazia(entradaOperadores))
                {
                    if(topoPilha(entradaOperadores)->valor.vInt >= front(infixa)->valor.vInt){
                        enqueue(saida, copiaObjeto(topoPilha(entradaOperadores)));
                        desempilha(entradaOperadores);
                    }
                    else{
                        break;
                    }
                }
                empilha(entradaOperadores, copiaObjeto(front(infixa)));
            }

        }
        dequeue(infixa);
    }
    while (!pilhaVazia(entradaOperadores))
    {
        enqueue(saida, copiaObjeto(topoPilha(entradaOperadores)));
        desempilha(entradaOperadores);
    }
    liberaPilha(entradaOperadores);
    return saida;
}

/**
 * @brief Imprime a fila de objeto em notação pós-fixa
 *
 * @param posfixa Fila com os objeto que se deseja imprimir
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