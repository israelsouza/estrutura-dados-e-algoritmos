#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* proximo;
} ELEMENTO;

typedef ELEMENTO* PONTEIRO_PARA_ELEMENTO;

typedef struct {
    PONTEIRO_PARA_ELEMENTO topo;
} PILHA;



void inicializarPilha(PILHA* p){
    p->topo = NULL;
}


int tamanho(PILHA* p){
    PONTEIRO_PARA_ELEMENTO end = p->topo;
    int tam = 0;

    if (end == NULL) return tam;

    while (endd != NULL)
    {
        tam++;
        end = end->proximo; 
    }

    return tam;
}


bool estaVazia(PILHA* p){
    if (p->topo == NULL) return true;
    return false;
}


void printarElementos(PILHA* p){
    PONTEIRO_PARA_ELEMENTO end = p->topo;
    printf("PILHA: \" ");
    
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->proximo;
    }

    printf("\"\n");
}


bool push(PILHA* p, REGISTRO reg){
    PONTEIRO_PARA_ELEMENTO i;
    i = (PONTEIRO_PARA_ELEMENTO) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    i->proximo = p->topo;
    p->topo = i;
    return true;    
}

bool pop(PILHA* p, REGISTRO* reg){
    if(p->topo == NULL) return false;
    
    *reg = p->topo->reg;
    
    PONTEIRO_PARA_ELEMENTO apagar;
    apagar = p->topo;
    p->topo = p->topo->proximo;
    free(apagar);
    return true;
}

void reiniciarPilha(PILHA* p){
    PONTEIRO_PARA_ELEMENTO apagar, posicao;
    posicao = p->topo;

    while (posicao != NULL)
    {      
        apagar = posicao;
        posicao = posicao->proximo;
        free(apagar);
    }
    
    p->topo = NULL;
}