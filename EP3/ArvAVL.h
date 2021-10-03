#ifndef EP3_AvrAVL_H
#define EP3_AvrAVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Fila.h"

typedef struct no No;

No *criaNo(char* pWord);
void liberaNo(No *r);
int alturaAVL(No *r);
int fatorBalanceamentoAVL(No *r);
No *insereNoArvBin(No *r, No* novo);
No *rotacaoDir(No *A);
No *rotacaoEsq(No *A);
int alturaArvoreBin(No *r) ;
int fatorBalanceamentoArvoreBin(No *r);
No *insereAVL(No *r, No* novo);
int buscaDicionario(No *r, char *pWord);
void padding(char ch, int n);
void comparaFazSugestao(Fila* f, No *r, char* pWord, int tam);
void imprimeArvoreAVL(No *noR, int level);
#endif