// modelagem

#include <stdio.h>
#define MAX 50

#define true 1
#define false 0

typedef int bool; // bool nao é um tipo nativo, por isso precisa ser declarado

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int topo;
} PILHA; 


// funções - inicialização - tamanho - exibição - inserção - exclusão - reinicialização

void inicializarEstrutura(PILHA* p)
{
    p->topo = -1;
}

int tamanhoPilha(PILHA* p)
{
    return p->topo + 1 ;
}

void printarRegistros(PILHA* p)
{
    printf("PILHA: \" ");
    int i;
    
    for (i = p->topo; i >= 0; i--)
    {
        printf("%i ", p->A[i].chave);
    }

    printf("\"\n");
}

bool push(PILHA* p, REGISTRO reg)
{
    if(p->topo >= MAX-1) return false;
    p->topo = p->topo+1;
    p->A[p->topo] = reg;
    return true;
}

/*
Aqui não é removido o valor do registro a ser excluido,
apenas é decrementado o topo, a var que define a quantidade de
elementos válidos a serem exibidos pro usuário.

Como foi decrementado, se fossee printar, não aparece
o ultimo elemento, reduzindo o processamento.
*/
bool pop(PILHA* p, REGISTRO* reg)
{
    if(p->topo == -1) return false;
    *reg = p->A[p->topo];
    p->topo = p->topo - 1;
    return true;
}


void reinicializarPilha(PILHA* p)
{
    p->topo = -1;
}