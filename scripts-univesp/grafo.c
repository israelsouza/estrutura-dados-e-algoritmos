/* IMPLEM. C/ MATRIZES DE ADJACÊNCIAS 

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

typedef struct grafo {
    int vertices; // vert. e arest. -> facilita salvar do que precisar varrer matriz sempre q necessitar
    int arestas;
    TIPOPESO **adj; // ou seja, ponderado
} GRAFO;

*/

/* IMPLEM. C/ LISTAS DE ADJACÊNCIAS */

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

/* 
METODOS

1. Criação grafo sem aresta. 
2. Inclusão de aresta (adjacência) no grafo. 
3. Visualização do grafo. 
*/

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

// grafo dirigido
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

void imprime(GRAFO *gr){
    printf("Vertices: %d. Arestas: %d.\n", gr->vertices,gr->arestas);
    int i;
    for(i=0; i<gr->vertices; i++){
        printf("v%d: ",i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while (ad)
        {
            printf("v%d(%d)", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}


int main(void){
    GRAFO * gr = criarGrafo(5);
    criarAresta(gr, 0, 1, 2);
    criarAresta(gr, 1,2,4);
    criarAresta(gr,2,0,12);
    criarAresta(gr,2,4,40);
    criarAresta(gr,3,1,3);
    criarAresta(gr,4,3,8);

    imprime(gr);
}