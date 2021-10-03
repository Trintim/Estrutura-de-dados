#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#include "Util.h"
#include "ArvAVL.h"
#include "Fila.h"

/* Número máximo de caracteres em uma linha */
#define TAM_MAX_LINHA 1024
/* Número máximo de caracteres em uma palavra */
#define TAM_MAX_PALAVRA 128
/* Espaços em branco */
const char *whiteSpace = " \t\v\f\n";


void imprimePalavraErrada(String palavra);

int main(int argc, char *argv[]) {
    double inicioProg = MyClock();
    double inicioImportDic;
    double inicioSugestoes;
    char linha[TAM_MAX_LINHA];
    char nomeArqDicionario[TAM_MAX_PALAVRA];
    char nomeArqTexto[TAM_MAX_PALAVRA];
    char palavra[TAM_MAX_PALAVRA];
    char cpypalavra[TAM_MAX_PALAVRA];
    char cpypalavra2[TAM_MAX_PALAVRA];
    bool arvoreAVL = false;

    /* Lê os valores passados como argumento para o programa */
    /* Não altera essa parte.                                */
    for(int i = 1; i < argc; ++i) {
        if (!strncmp(argv[i], "-avl", 4)) {
            arvoreAVL = true;
        }
        else if (!strncmp(argv[i], "-d", 2)){
            strcpy(nomeArqDicionario, argv[i + 1]);
            i++;
        }
        else if (!strncmp(argv[i], "-t", 2)){
            strcpy(nomeArqTexto, argv[i + 1]);
            i++;
        }
        else {
            fprintf(stderr, "Uso: ./%s -d <ArquivoDicionario> -t <Texto> [-avl]\n", argv[0]);
            exit(1);
        }
    }


    FILE *fDicionario, *fTexto;

    /* Carrega o dicionário */
    fDicionario = fopen(nomeArqDicionario, "r");
    if (fDicionario == NULL) {
        printf("Nao foi possivel abrir o arquivo '%s'\n", nomeArqDicionario);
        exit(EXIT_FAILURE);
    }

    /**
     * Tarefa 0: Crie a árvore binária de busca que será utilizada
     *           para armazenar as palávras do dicionário.
     *
     * Para essa parte você pode optar por:
     *
     * 1) criar um único TAD que gerencia a árvore binária. A função de
     *    criação/inicialização recebe um parâmetro que indica se a árvore
     *    é ou não balanceada. Internamente no TAD, você decide se precisa/deve
     *    ou não fazer o balanceamento quando uma nova palavra for inserida.
     *
     * ou
     *
     * 2) criar dois TADs associados as árvores, um para árvore de
     *    busca não balanceada e outro para a árvore AVL (árvore de busca balanceada).
     *
     */
    inicioImportDic = MyClock();
    No* dicionario = NULL;
    int qntPalavras = 0;
    while(fscanf(fDicionario, "%s", palavra) == 1) {
        /**
         * Tarefa 1: Adicione a palavra na árvore
         *
         */
        AVISO(Ainda não implemente a árvore);
        if (arvoreAVL) {
            dicionario = insereNoAVL(dicionario, criaNo(palavra));
            qntPalavras++;
        }
        else {
            dicionario = insereNo(dicionario, criaNo(palavra));
            qntPalavras++;
        }
    }

    /* imprime informações uteis sobre a árvore */
    printf("%d palavras importadas.\n", qntPalavras);
    printf("\033[1;32mTempo de Importação do Dicionário: %.10lf seg\n\n\033[00m", (MyClock() - inicioImportDic) / CLOCKS_PER_SEC);
    printf("------------------------------------------------------\n");


    if (arvoreAVL){
        printf("\033[1;35mFator de Balanceamento da Árvore: %d\n\n\033[00m", fatorBalanceamento(dicionario));
        printf("\033[1;35mAltura da Árvore: %d\n\n\033[00m", altura(dicionario));
    }
    else{
        //printf("\033[1;35mFator de Balanceamento da Árvore: %d\n\n\033[00m", fatorBalanceamentoABB(dicionario));
        //printf("\033[1;35mAltura da Árvore: %d\n\n\033[00m", alturaABB(dicionario));
    }
    printf("------------------------------------------------------\n");

    /* Carrega o texto */
    fTexto = fopen(nomeArqTexto, "r");
    if (fTexto == NULL) {
        printf("Nao foi possivel abrir o arquivo '%s'\n", nomeArqTexto);
        exit(EXIT_FAILURE);
    }

    /**
     * Tarefa 2: Crie uma estrutura de dados que você acha mais adequada para
     *           armazenar as palavras incorretas. Os requisitos do EP podem te ajudar
     *           na escolha pela estrutura de dados.
    */

    Fila* erros = criaFila();
    int qntErros = 0;

    while(fgets(linha, TAM_MAX_LINHA, fTexto) != NULL ) {
        /* Separa as palavras da linha */
        char *word = strtok(linha, whiteSpace);
        // Percorre a linha extraindo as palavras
        while( word != NULL ) {
            if(isdigit(word[0]) || word[0] == '-') {
                printf("%s ", word);
                word = strtok(NULL, whiteSpace);
                continue;
            }
            strcpy(cpypalavra, word);
            removePontuacao(cpypalavra);
            strcpy(cpypalavra2, cpypalavra);
            converteMinusculo(cpypalavra2);

            /**
             * Tarefa 3: Verifique se a palavra 'cpypalavra' OU 'cpyplavra2' está na árvore que
             *           armazena o dicionário. Se estiver, apenas imprima-a.
             */
            if ( pertence(dicionario, cpypalavra) || pertence(dicionario, cpypalavra2))
                printf("%s ", word);
            else {
                imprimePalavraErrada(word);
                /**
                 *  Tarefa 4: Adicione a palavra na estrutura de dados escolhida na Tarefa 2
                 *
                 */
                //nTAREFA 3: Adicione a palavra em alguma estrutura de dados de sua preferência
                enqueue(erros, cpypalavra);
                qntErros++;
            }

            //Pega a próxima palavra
            word = strtok(NULL, whiteSpace);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("----------------------------------------\n");
    printf("-      Número de palavras lidas: %d\n", qntPalavras);
    printf("- Número de palavras incorretas: %d\n", qntErros);
    printf("Palavra(s) incorreta(s) e sugestão(ões)\n");
    printf("----------------------------------------\n");
    inicioSugestoes = MyClock();
    Fila* sugestoes = criaFila();
    while(!filaVazia(erros)){
        char* palavraErrada = frenteFila(erros);
        imprimePalavraErrada(palavraErrada);
        if (strlen(palavraErrada) <= 7)
            achaSugestoes(sugestoes, dicionario, palavraErrada, 2);
        else
            achaSugestoes(sugestoes, dicionario, palavraErrada, 3);

        imprimeFilaVerde(sugestoes);
        esvaziaFila(sugestoes);
        dequeue(erros);
        printf("\n");
    }
    printf("Quantidade de erros encontrados: %d", qntErros);
    printf("\033[1;35mTempo para gerar as sugestões: %.10lf seg\n\n\033[00m", (MyClock() - inicioSugestoes) / CLOCKS_PER_SEC);
    liberaFila(erros);
    liberaFila(sugestoes);
    liberaArvore(dicionario);
    /**
     * Tarefa 5: Para cada palavra incorreta, imprima-a e percorra o dicionário em busca de sugestões.
     *
     */

    printf("----------------------------------------\n");
    printf("\033[1;32mTempo Total: %.10lf seg\n\n\033[00m", (MyClock() - inicioProg) / CLOCKS_PER_SEC);


    fclose(fDicionario);
    fclose(fTexto);
    return 0;
}

/**
 * @brief Imprime uma palavra errada em vermelho. Caracteres finais, que não sejam letras,
 * não são impressos em vermelho.
 *
 * @param palavra
 */
void imprimePalavraErrada(String palavra) {
    int ultimaLetra = encontraPosicaoUltimaLetra(palavra);
    int tamanho = strlen(palavra);
    printf("\033[4;31m");
    for(int i = 0; i <= ultimaLetra; i++)
        printf("%c", palavra[i]);
    printf("\033[00m");
    for (int i = ultimaLetra + 1; i < tamanho; i++)
        printf("%c", palavra[i]);
    printf(" ");
}