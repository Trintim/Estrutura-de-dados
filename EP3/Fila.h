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


/**
 * @brief Aqui estão as funções que foram utilizadas para armazenar os dados dos textos inserido
 *
 */
/*

criaFila, liberaFila, buscarFila, enqueue, dequeue, imprimeSugestao, filaVazia, esvaziaFil, front, back

*/