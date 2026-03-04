#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int topo1;
    int topo2;
} PILHA_DUPLA;



void inicializarEstrutura(PILHA_DUPLA* p){
    p->topo1 = -1;
    p->topo2 = MAX;
}

int tamanhoPilhaDupla(PILHA_DUPLA* p)
{
    return p->topo1 + 1 + MAX - p->topo2;
}

bool exibirUmaPilha(PILHA_DUPLA* p, int pilha)
{
    if (pilha < 1 || pilha > 2) return false;

    printf("PILHA %i: \" ", pilha);

    
    /*
        My implementação - porem exibe segundo a posição, não do ultimo elemento inserido até o primeiro

        if ( pilha == 1 ) {
            int topo = p->topo1;
            for ( int i = 0; i < topo; i++) printf("%i ", p->A[i].chave );
        }
        else {
            int topo = p->topo2;
            for ( i = MAX-1; i > topo; i--)printf("%i ", p->A[i] );
        }

    */
    
    int i;
    if (pilha==1) for( i=p->topo1; i>=0; i-- )  printf("%i ", p->A[i].chave);
    else  for( i=p->topo2; i<MAX; i++ )  printf("%i ", p->A[i].chave);

    printf("\"\n");

    return true;
}

bool push(PILHA_DUPLA* p, REGISTRO reg, int pilha)
{
    if (pilha < 1 || pilha > 2) return false;
    if ( p->topo1 + 1 == p->topo2 ) return false;

    if (pilha == 1) {
        p->topo1 = p->topo1+1;
        p->A[p->topo1].chave = reg; 
    }

    if (pilha == 2) {
        p->topo2 = p->topo2-1;
        p->A[p->topo2].chave = reg; 
    }

    return true;
}


bool pop(PILHA_DUPLA* p, REGISTRO* reg, int pilha)
{
    if (pilha < 1 || pilha > 2) return false;

    if (pilha==1){
        if (p->topo1 == -1) return false;
        *reg = p->A[p->topo1];
        p->topo1 = p->topo1-1;
    }

    if (pilha==2) {
        if (p->topo2 == MAX) return false;
        *reg = p->A[p->topo2];
        p->topo2 = p->topo2 + 1;
    }

    return true;
}

void reiniciarPilhaDupla(PILHA_DUPLA* p){
    p->topo1 = -1;
    p->topo2 = MAX;
    // ou então
    inicializarEstrutura(p);
}
