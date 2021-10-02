#ifndef EP3_ArvoreAVL_H
#define EP3_ArvoreAVL_H
#include "Fila.h"

/**
 * @brief Estrutura criada para as arvores AVL/BIN
 *
 */
typedef struct noArvore{
    char *palavras;
    struct noArvore *esq;
    struct noArvore *dir;
    int altura;
}NoArvore;

NoArvore *criaNo(char *pWord);

void liberaNoAVL(NoArvore *r);

int alturaAVL(NoArvore *r);
int fatorBalanceamentoAVL(NoArvore *r);

NoArvore *rotacaoDir(NoArvore *A);
NoArvore *rotacaoEsq(NoArvore *A);

NoArvore *insereAVL(NoArvore *r, NoArvore *novo);
NoArvore *insereNo(NoArvore *r, NoArvore *novo);

int alturaArvoreBin(NoArvore *r);
int fatorBalanceamentoArvoreBin(NoArvore *r);

void padding(char ch, int n);

void comparaAVL(Fila *f, NoArvore *r, char *pWord, int tamanho);
int buscaDicionario(NoArvore *r, char *pWord);

void imprimeArvoreAVL(NoArvore *root, int level);

#endif