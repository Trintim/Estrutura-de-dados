#include "Fila.h"

typedef struct no No;

No *criaNo(char *pWord);
void liberaNo(No *r);
int alturaArvoreBin(No *r) ;
int alturaAVL(No *r);
int fatorBalanceamentoArvoreBin(No *r);
int fatorBalanceamentoAVL(No *r);
No *insereNoArvoreBin(No *r, No *novo);
No *rotacaoDir(No *A);
No *rotacaoEsq(No *A);
No *insereAVL(No *r, No *novo);
int buscaDicionario(No *r, char *pWord);
void padding (char ch, int n);
void imprimeArvoreAVL(No *r, int level);
void comparaFazSugestao(Fila* f, No *r, char *pWord, int tam);

/**
 * @brief Abaixo estão todas as funções utilizadas na criação das arvores balanceadas e não balanceadas para armazenar as palavras do dicionario
 *
 */
/*
Fonções para Arvore Balanceada
fatorBalanceamentoAVL, insereAVL, rotacaoDir, rotacaoEsq, alturaAVL

Fonções para Arvore não Balanceada
fatorBalanceamentoArvoreBin, insereNoArvoreBin, alturaArvoreBin

Funções compartilhadas
comparaFazSugestao, padding, buscaDicionario, liberaNo, criaNo

*/
