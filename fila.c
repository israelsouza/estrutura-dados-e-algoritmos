// modelagem

#include <stdio.h>

#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int inicio;
    int qtdElementos;
} FILA;



void iniciarEstrutura(FILA* f) {
    f->inicio=0;
    f->qtdElementos=0;
}

int retornarQuantidadeElementos(FILA* f){
    return f->qtdElementos;
}

void exibirElementos(FILA* f){
    printf("FILA: \" ");
    int i = f->inicio;
    int temp;
    
    for (temp = 0; temp < f->qtdElementos; temp++)
    {
        printf("%i ", f->A[i].chave);
        i = (i+1) % MAX; // tratamento para não estourar o limite definido do arranjo
    }

    printf("\"\n");
}

bool inserirElementoFila(FILA* f, REGISTRO reg){
    if (f->qtdElementos >= MAX) return false;
    int posicao = (f->inicio + f->qtdElementos) % MAX;
    f->A[posicao].chave = reg;
    f->qtdElementos++;
    return true;
}

bool excluirElementoFila(FILA* f, REGISTRO* reg){
    if (f->qtdElementos == 0) return false;
    *reg = f->A[f->inicio];
    
    f->inicio = (f->inicio+1) % MAX;
    f->qtdElementos--;
    return true;
}

void reinicializarFila(FILA* f){
    f->inicio=0;
    f->qtdElementos=0;
}