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

Fila* criaFila();

void liberaFila(Fila* fila);

void enqueue(Fila* fila, char* palavra);

void dequeue(Fila* fila);

void esvaziaFila(Fila* fila);

char* frenteFila(Fila* fila);

char* fundoFila(Fila* fila);

int filaVazia(Fila* fila);

void imprimeFilaVerde(Fila* fila);

void imprimeFilaRoxo(Fila* fila);

int contemFila(Fila* fila, char* palavra);
