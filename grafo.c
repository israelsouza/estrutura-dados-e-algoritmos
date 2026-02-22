/* IMPLEM. C/ MATRIZES DE ADJACÊNCIAS */

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
} ADJACENCIA;


typedef struct vertice {
    // dados a serem armazenados
    ADJACENCIA *cab;
} VERTICE;


typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE * adj;
} GRAFO;

