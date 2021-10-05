typedef struct no No;
typedef struct fila Fila;

Fila *criaFila();
void liberaFila(Fila *f);
int buscaFila(Fila *f, char *pWord);
void enqueue(Fila *f, char *pWord);
void dequeue(Fila *f);
void esvaziaFila(Fila *f);
char *front(Fila *f);
char *back(Fila *f);
int filaVazia(Fila *f);
void mostraSugestao(Fila *f);

/**
 * @brief Aqui estão as funções que foram utilizadas para armazenar os dados dos textos inseridos
 *
 */
/*

criaFila, liberaFila, buscaFila, enqueue, dequeue, esvaziaFila, front, back, filaVazia, mostraSugestao,

*/