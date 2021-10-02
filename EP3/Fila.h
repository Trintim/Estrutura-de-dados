#ifndef EP3_Fila_H
#define EP3_Fila_H

/**
 * @brief No de gerenciamento das filas
 *
 */
typedef struct no{
    struct no *proximo;
    char *palavras;
}No;

/**
 * @brief Fila para ordenação
 *
 */
typedef struct fila{
    No *inicio;
    No *fim;
    int n;
}Fila;

Fila* criaFila();

int buscaFila(Fila *f, char *pWord);
void liberaFila(Fila *f);
void enqueue(Fila *f, char *pWord);
void dequeue(Fila *f);
void imprimeFilaSugestao(Fila *f);
int filaVazia(Fila *f);
char *front(Fila *f);
void zerar(Fila *f);

#endif