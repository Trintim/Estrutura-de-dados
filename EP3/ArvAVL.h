
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



/**
 * @brief Abaixo estão todas As funções utilizadas na criação das arvores Balanceadas e não balanceadas para armazenar as palavras do dicionario
 *
 */
/*
Funções para Arvore balanceada
alturaAVL, fatorBalanceamentoAVL, imprimeArvoreAVL,
rotacaoDir, rotacaoEsq, insereAVL, insereAVL,

Funções para Arvore não balanceada
insereNoArvBin, alturaArvoreBin, fatorBalanceamentoArvoreBin,

Funções compartilhadas
criaNo, liberaNo,
buscaDicionario,
comparaFazSugestao,
imprimeArvoreAVL,
*/