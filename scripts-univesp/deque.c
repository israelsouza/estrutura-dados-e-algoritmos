// modelagem

#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;


typedef struct auxElem {
    REGISTRO reg;
    struct auxElem* anterior;
    struct auxElem* proximo;
} ELEMENTO;

typedef ELEMENTO* PONTEIRO;

typedef struct {
    PONTEIRO cabeca;
} DEQUE;



void inicializarEstrutura(DEQUE* d){
    d->cabeca = (PONTEIRO) malloc(sizeof(ELEMENTO));
    d->cabeca->proximo = d->cabeca;
    d->cabeca->anterior = d->cabeca;
}


void tamanho(DEQUE* d){
    PONTEIRO end = d->cabeca->proximo;
    int tamanho = 0;

    while (end != d->cabeca)
    {
        tamanho++;
        end = end->proximo;
    }
    
    return tamanho;
}


void printarElementos(DEQUE* d){
    PONTEIRO end = d->cabeca->anterior;
    printf("DEQUE partindo do fim: \" ");

    while (end != d->cabeca)
    {
        printf("%i ", end->reg.chave);
        end = end->anterior;
    }
    
    printf("\"\n");
}


bool inserirDequeFim(DEQUE* d, REGISTRO reg){
    PONTEIRO novo = (PONTEIRO) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->proximo = d->cabeca;
    novo->anterior = d->cabeca->anterior;

    d->cabeca->anterior = novo;
    novo->anterior->proximo = novo;
    return true
}

bool excluirElementoDequeInicio(DEQUE* d, REGISTRO* reg)
{
    if(d->cabeca->proximo == d->cabeca) return false;
    PONTEIRO apagar = d->cabeca->proximo;
    *reg = apagar->reg;
    d->cabeca->proximo = apagar->proximo;
    apagar->proximo->anterior = d->cabeca;
    free(apagar);
    return true;    
}


void reinicializarDeque(DEQUE* d)
{
    PONTEIRO end = d->cabeca->proximo;

    while (end != d->cabeca)
    {
        PONTEIRO apagar = end;
        end = end->proximo;
        free(apagar);
    }
    d->cabeca->proximo = d->cabeca;
    d->cabeca->anterior = d->cabeca;
}