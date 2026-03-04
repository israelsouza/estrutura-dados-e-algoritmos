/* IMPLEM. C/ LISTAS DE ADJACÊNCIAS */

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA; // representa uma aresta


typedef struct vertice {
    // dados a serem armazenados
    ADJACENCIA *cab;
} VERTICE;


typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE * adj;
} GRAFO;



void visitarProfundidade(GRAFO *g, int u, int *cor){
    // se fosse buscar uma chave (id), seria feita a alteração
    // aqui, antes entrar no loop; e modif. estrutura
    cor[u] = AMARELO;
    ADJACENCIA *v = g->adj[u].cab;
    while(v){
        if( cor[v->vertice] == BRANCO )
            visitarProfundidade(g, v->vertice, cor);
        
        v = v->prox;
    }
    cor[u] = VERMELHO;
}


void profundidade(GRAFO *g){
    int cor[g->vertices];

    int u;
    
    for(u=0; u < g->vertices; u++){
        cor[u] = BRANCO;
    }

    for(u=0; u < g->vertices; u++){
        if(cor[u] == BRANCO)
            visitarProfundidade(g, u, cor);
    }
}