#include <stdio.h>
#include <malloc.h>

typedef struct tempNo
{
    float valor;
    int coluna;
    struct tempNo* proximo;
} NO;

typedef NO* PONTEIRO_P_ELEMENTO;

typedef struct
{
    PONTEIRO_P_ELEMENTO A;
    int linhas;
    int colunas;
} MATRIZ_ESPARSA ;


/* OPERAÇÕES

INICIALIZAR MATRIZ      new matriz[m][n]
ATRIBUIR UM VALOR       matriz[x][y] = valor
ACESSAR UM VALOR        valor = matriz[x][y]

*/

void inicializarMatriz(MATRIZ_ESPARSA* m, int linha, int coluna)
{
    int i;
    m->linhas = linha;
    m->colunas = coluna;
    m->A = (PONTEIRO_P_ELEMENTO*) malloc( linhas * sizeof(PONTEIRO_P_ELEMENTO) );
    for ( i=0; i<linha; i++ ) m->A[i] = NULL;
}

bool atribuirValorMatriz(MATRIZ_ESPARSA* m, int linha, int coluna, float valor)
{
    if (linha < 0 || linha >= m->linhas ||
        coluna < 0 || coluna >= m->colunas ) return false;

    PONTEIRO_P_ELEMENTO anterior = NULL;
    PONTEIRO_P_ELEMENTO atual = m->A[linha];

    while(atual != NULL && atual->coluna < coluna) {
        anterior = atual;
        atual = atual->proximo;
    }

    if ( atual != NULL && atual->coluna == coluna ) {
        // caso o valor já exista na matriz
        if ( valor == 0) {
            if ( anterior == NULL ) m->A[linha] = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
        }
        else atual->valor = valor;
    } else {
        // caso o valor não exista (alocar memoria e inserir)
        PONTEIRO_P_ELEMENTO novo = (PONTEIRO_P_ELEMENTO) malloc(sizeof(NO));
        novo->coluna = coluna;
        novo->valor = valor;
        novo->proximo = atual;
        if ( anterior == NULL ) m->A[linha] = novo;
        else anterior->proximo = novo;
    }

    return true;
} 

float buscarValorNaMatriz(MATRIZ_ESPARSA* m, int linha, int coluna)
{
    if (linha < 0 || linha >= m->linhas ||
        coluna < 0 || coluna >= m->colunas ) return 0;
    
    PONTEIRO_P_ELEMENTO atual = m->A[linha];
    while (atual != NULL && atual->coluna < coluna)
    {
        atual = atual->proximo;
    }

    if ( atual != NULL && atual->coluna == coluna ) return atual->valor;
    else return 0;
}
