#include "Fila.h"

struct no{
    char palavras;
    struct no *esq;
    struct no *dir;
    int altura;
};

typedef struct no No;

No *criaNo (char *palavras);

void liberaNoAVL(No *r);

int alturaAVL(No *r);
int fatorBalanceamentoAVL(No *r);

No *rotacaoDir(No *A);
No *rotacaoEsq(No *A);

No *insereAVL(No *r, No *novo);
No *insereNo(No *r, No *novo);

int alturaArvoreBin(No *r);
int fatorBalanceamentoArvoreBin(No *r);

void padding(char ch, int n);

void comparaAVL(Fila *f, No *r, char *pWord, int tamanho);
No *buscaDicionario(No *r, char pWord);

void imprimeArvoreAVL(No *root, int level);

