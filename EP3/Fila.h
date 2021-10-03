#ifndef EP3_FILA_H
#define EP3_FILA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Fila no
 *
 */
typedef struct no No;
/**
 * @brief Fila fila
 *
 */
typedef struct fila Fila;

Fila *criaFila();
void liberaFila(Fila *f);
int buscarFila(Fila *f, char* pWord);
void enqueue(Fila *f, char *pWord);
void dequeue(Fila *f);
void imprimeSugestao(Fila *f);
int filaVazia(Fila *f);
void esvaziaFila(Fila *f);
char *front(Fila *f);
char *back(Fila *f);
#endif