
#include "Fila.h"

/**
 * @brief Arvore daqui
 *
 */
typedef struct no No;

No* criaNo(char *pWord);

void liberaNo(No *r);

int buscaDicionario(No *r, char *pWord);

No* insereNoArvBin(No *r, No *novo);

No* insereAVL(No *r, No *novo);

void imprimeArvoreAVL(No *noR, int level);

void comparaFazSugestao(Fila* f, No *r, char *pWord, int tam);

int fatorBalanceamentoAVL(No *r);

int fatorBalanceamentoArvoreBin(No *r);

int alturaAVL(No *r);

int alturaArvoreBin(No *r);

