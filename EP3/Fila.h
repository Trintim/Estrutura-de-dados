typedef struct no{
    struct no *proximo;
    char *palavras;
}NoFila;

typedef struct fila{
    NoFila *inicio;
    NoFila *fim;
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