/* OBS SE FOR COMPILAR, PRECISA DO 'ENTRY POINT' (main function) */

// int main(){
//     typedef struct{
//         TIPOCHAVE chave;
//     } REGISTRO;

//     typedef struct{
//         REGISTRO A[MAX];
//         int nroElem;
//     } LISTA;

//     LISTA list;

//     void inicializarLista(LISTA* l){
//         l->nroElem = 0;
//     }
    
//     inicializarLista(&list);
//     tamanho(&list);
    
//     return 0;
// }

#include <stdio.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    // demais elementos
} REGISTRO;

typedef struct{
    REGISTRO A[MAX]; // o registro é um arranjo com numero máx elementos
    int nroElem; // pois começa vazio (0) e vai aumentando conforme inserção
} LISTA;


/* QUAL A DIFERENÇA DESSAS 2 FUNÇÕES???? [IMG01] */

void inicializarLista(LISTA l){
    l.nroElem = 0;
}

void inicializarLista(LISTA* l){
    l->nroElem = 0;
}

/* RETORNA NUMERO DE ELEMENTOS */

int tamanho (LISTA* l){
    return l->nroElem;
}

/* EXIBIR/IMPRIMIR TODOS ELEMENTOS DA LISTA */

void exibirLista(LISTA* l){
    int i;
    printf("Lista: \" ");
    
    for (i = 0; i < l->nroElem; i++)
    {
        printf("%i ", l->A[i].chave);
    }
    
    printf("\"\n");
}

/* BUSCAR POR UM ELEMENTO */

int buscaSequencial(LISTA* l, TIPOCHAVE ch){
    int i=0;
    while (i < l->nroElem)
    {
        if (ch == l->A[i].chave) return i;
        else i++;
    }
    return -1;    
}

/* INSERÇÃO DE UM ELEMENTO EM POSIÇÃO ESPECÍFICA */

/**
 * @param reg - valor de registro a ser inserido na posição i
 * @param i - posição dada pelo usuário
 */
bool inserirElementoLista(LISTA* l, REGISTRO reg, int i){
    int j;
    if (l->nroElem == MAX || (i < 0) || (i > l->nroElem))
        return false;
    for(j = l->nroElem; j>i; j--) l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->nroElem++;
    return true;
}

/* EXCLUSÃO DE UM ELEMENTO EM POSIÇÃO ESPECÍFICA */

bool excluirElementoLista(TIPOCHAVE ch, LISTA* l){
    int pos, j;
    pos = buscaSequencial(l, ch);
    if(pos == -1) return false;
    for (j = pos; j < l->nroElem-1; j++){
        l->A[j] = l->A[j+1];
    }
    l->nroElem--;
    return true;
}

/* REINICIALIZAÇÃO DA LISTA */

void reiniciarLista(LISTA* l){
    l->nroElem = 0;
}