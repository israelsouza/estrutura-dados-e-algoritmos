/* ALGORITMO

- Defino um nó inicial, marcando como explorado
- Coloco na fila
- Enquanto a final não estiver vazio:
    - Pego o primeiro da fila
    - Busco nós vizinhos não explorado
    - Se houver, marco como explorado e coloco no fim da fila

- Verifico e marco se houver outro nó inicial não percorrido  

*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;


typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA; // aresta / relacionamento


typedef struct vertice {
    // dados a serem armazenados
    ADJACENCIA *cab;
} VERTICE; // no


typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;  // lista ligada das adjacencias
} GRAFO; // um-todo

// ------------------------------------------------

#define MAX 50
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

void iniciarFila(FILA* f) {
    f->inicio=0;
    f->qtdElementos=0;
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


// ------------------------------------------------

void visitaL(GRAFO *g, int s, bool *expl)
{
    FILA f;
    iniciarFila(&f);

    expl[s] = true; // muda aqui se for capturar algo
    REGISTRO *u = (REGISTRO *) malloc(sizeof(REGISTRO)); // 
    u->chave = s;
    inserirElementoFila(&f, *u);

    while (f.inicio) 
    {
        excluirElementoFila(&f, u);
        ADJACENCIA *v = g->adj[u->chave].cab; // v = vizinho

        while (v)
        {
            if (!expl[v->vertice]) {
                expl[v->vertice] = true; // muda aqui se for capturar algo
                u->chave = v->vertice;
                inserirElementoFila(&f, *u);
            }
            v = v->prox;
        }
    }
    free(u);
}

// aqui há apenas a 'caminhada' na estrutura
void largura(GRAFO *g)
{
    bool expl[g->vertices]; // simula uma lista ligada, define o tamanho da lista com a quantidade de nós (L38)

    int u;
    for (u = 0; u < g->vertices; u++)
        expl[u] = false; // percorro a lista setando todos como não explorado  
    
    for (u=0; u < g->vertices; u++)
        if(!expl[u])
            visitaL(g, u, expl);
}
