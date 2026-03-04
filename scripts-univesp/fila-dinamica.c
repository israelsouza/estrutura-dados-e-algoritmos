#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* proximo;
} ELEMENTO, * PONTEIRO_PARA_ELEMENTO;

typedef struct {
    PONTEIRO_PARA_ELEMENTO inicio;
    PONTEIRO_PARA_ELEMENTO fim;
} FILA;


void inicializarEstrutura(FILA* f)
{
    f->fim = NULL;
    f->inicio = NULL;
}

int tamanho(FILA* f)
{
    PONTEIRO_PARA_ELEMENTO end = f->inicio;
    int tamanho = 0;

    while ( end != NULL )
    {
       tamanho++;
        end = end->proximo;
    }
    
    return tamanho;
}

void imprimirElementos(FILA* f)
{
    PONTEIRO_PARA_ELEMENTO end = f->inicio;
    printf("FILA: \" ");
    
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->proximo;
    }

    printf("\"\n");
}

bool inserirElemento(FILA* f, REGISTRO reg)
{
    PONTEIRO_PARA_ELEMENTO novo = (PONTEIRO_PARA_ELEMENTO) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->proximo = NULL;
    if(f->inicio == NULL) f->inicio = novo;
    else f->fim->proximo = novo;
    f->fim = novo;
    return true; 
}

bool excluirElemento(FILA* f, REGISTRO* reg)
{
    if (f->inicio == NULL) return false;
    *reg = f->inicio->reg;
    PONTEIRO_PARA_ELEMENTO apagar = f->inicio;
    f->inicio = f->inicio->proximo;
    free(apagar);
    if(f->inicio == NULL) f->fim == NULL
    return true;
}

void reinicializarEstrutura(FILA* f)
{
    PONTEIRO_PARA_ELEMENTO end = f->inicio;

    while (end != NULL)
    {
        PONTEIRO_PARA_ELEMENTO apagar = end;
        end = end->proximo;
        free(apagar);
    }

    f->inicio = NULL;
    f->fim = NULL;
}