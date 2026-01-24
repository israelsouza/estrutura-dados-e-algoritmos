#include <stdio.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX]; 
    int nroElem; 
} LISTA;


/* VERSÃO INICIAL - Com 2 comparações */

int buscaSequencial(LISTA* l, TIPOCHAVE ch){
    int i=0;
    while (i < l->nroElem)
    {
        if (ch == l->A[i].chave) return i;
        else i++;
    }
    return -1;    
}

/* ------------------------------------------------------------ */

typedef struct{
    REGISTRO A[MAX+1]; 
    int nroElem; 
} LISTA_MELHORADA;

/* MELHORADA */

int buscaSentinela(LISTA_MELHORADA* l, TIPOCHAVE ch) {
    int i = 0;
    l->A[l->nroElem].chave = ch;
    while(l->A[i].chave != ch) i++;
    if(i== l->nroElem) return -1;
    return i;
}

bool inserirElementoListaOrdenado(LISTA* l, REGISTRO reg){
    if(l->nroElem >= MAX) return false;
    int pos = l->nroElem;
    while (pos > 0 && l->A[pos-1].chave > reg.chave)
    {
        l->A[pos] = l->A[pos-1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;    
}

int buscaBinaria(LISTA* l, TIPOCHAVE ch){
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem-1;
    while(esq <= dir) {
        meio = ( (esq + dir) / 2 );
        if(l->A[meio].chave == ch) return meio;
        
        if(l->A[meio].chave < ch) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

/* A EXCLUSÃO FICA MAIS EFICIENTE COM A BUSCA BINARIA? ANTES X DEPOIS*/

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

bool excluirElementoLista_Melhorada(TIPOCHAVE ch, LISTA* l){
    int pos, j;
    pos = buscaBinaria(l, ch); // fica mais eficiente a busca
    if(pos == -1) return false;
    for (j = pos; j < l->nroElem-1; j++){ // porem, custo de processamento para deslocar tudo para não ter gaps de desperdicio se mantem
        l->A[j] = l->A[j+1];
    }
    l->nroElem--;
    return true;
}
