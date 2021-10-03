
#include "Fila.h"

/**
 * @brief Arvore daqui
 *
 */
typedef struct no No;

No* criaNo(char* palavra);

void liberaArvore(No* raiz);

int pertence(No* raiz, char* palavra);

No* insereNo(No* raiz, No* novo);

No* insereNoAVL(No* raiz, No* novo);

void imprimeArvore(No* raiz, int level);

void achaSugestoes(Fila* sugestoes, No* raiz, char* palavra, int range);

int fatorBalanceamento(No* raiz);

int fatorBalanceamentoABB(No* raiz);

int altura(No* raiz);

int alturaABB(No* raiz);
