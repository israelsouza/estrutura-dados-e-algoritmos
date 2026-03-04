#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

GRAFO *criarGrafo(int vertices){
    GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
    g->vertices = vertices;
    g->arestas = 0;
    g->adj = (VERTICE *) malloc(vertices*sizeof(VERTICE));

    int i;
    for(i=0; i<vertices; i++){
        g->adj[i].cab = NULL;
    }
    return(g);
}

ADJACENCIA *criarAdj(int v, int peso){
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return(temp);
}

bool criarAresta(
    GRAFO *grafo,
    int vi,
    int vf,
    TIPOPESO p
){
    if(!grafo) return(false);
    if ( (vf<0) || (vf >= grafo->vertices)) return(false);
    if( (vi<0) || (vi >= grafo->vertices)) return(false);

    ADJACENCIA *novo = criarAdj(vf, p);
    novo->prox = grafo->adj[vi].cab;
    grafo->adj[vi].cab = novo;
    grafo->arestas++;
    return(true);
}


/* ===================== ALGORITMO DE DIJKSTRA ===================== */

// grafo
// vetor com arranjo de distancias
// vetor com arranjo dos predecessores
// ponto inicial
void inicializarGrafoDijkstra(GRAFO *g, int *d, int *p, int s)
{
    int v;
    for(v=0; v < g->vertices; v++)
    {
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0;
}

/**
 * @param g grafo
 * @param d vetor com arranjo de distancias
 * @param p vetor com arranjo dos predecessores
 * @param u aresta / relacionamento 'atual'
 * @param v aresta / relacionamento 'proximo'
 */
void relaxa(GRAFO *g, int *d, int *p, int u, int v)
{
    ADJACENCIA *ad = g->adj[u].cab;

    while (ad && ad->vertice != v)
        ad = ad->prox;
    
    if(ad) {
        if (d[v] > d[u] + ad->peso) {
            // atualiza a estimativa
            d[v] = d[u] + ad->peso;
            p[v] = u;
        }
    }
}


bool existirAberto(GRAFO *g, int *aberto)
{
    int i;
    for(i=0; i < g->vertices; i++)
        if (aberto[i]) return(true);
    
    return(false);
}

// busca primeiro nó aberto
int menorDistancia(GRAFO *g, int *aberto, int *d)
{
    int i;
    for(i=0; i < g->vertices; i++)
        if( aberto[i] ) break;
    
    if( i == g->vertices ) return(-1);
    int menor = i;
    for(i=menor+1; i < g->vertices; i++ )
    {
        if(aberto[i] && (d[menor] > d[i]))
        {
            menor = i;
        }
    }
    return(menor);
}



// grafo
// ponto inicial
int *djikstra(GRAFO *g, int s)
{
    int *d = (int *) malloc(g->vertices* sizeof(int));

    int p[g->vertices];
    bool aberto[g->vertices];
    inicializarGrafoDijkstra(g, d, p, s);

    int i;
    for (i = 0; i < g->vertices ; i++)
        aberto[i] = true;
    
    while (existirAberto(g, aberto))
    {
        int u = menorDistancia(g, aberto, d);
        aberto[u] = false;

        ADJACENCIA *ad = g->adj[u].cab;

        while (ad)
        {
            relaxa(g, d, p, u, ad->vertice);
            ad = ad->prox;
        }
    }

    return (d);
}


int main(void){
    GRAFO *gr = criarGrafo(6);

    criarAresta(gr, 0, 1, 10);
    criarAresta(gr, 0, 2, 5);
    criarAresta(gr, 2, 1, 3);
    criarAresta(gr, 1, 3, 1);
    criarAresta(gr, 2, 3, 8);
    criarAresta(gr, 2, 4, 2);
    criarAresta(gr, 4, 5, 6);
    criarAresta(gr, 3, 5, 4);
    criarAresta(gr, 3, 4, 4);

    int *r = djikstra(gr, 0);

    int i;
    for(i=0; i < gr->vertices; i++)
    {
        printf("D(v0 -> v%d) = %d\n", i,r[i]);
    }

}