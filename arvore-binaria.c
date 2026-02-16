#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    /* DEMAIS DADOS AQUI (nome, idade, cidade...) */
    struct aux *esq, *dir;
} NO;

typedef NO* PONTEIRO;

PONTEIRO inicializar(){
    return(NULL);
}

PONTEIRO criarNovoNo(TIPOCHAVE ch){
    PONTEIRO novoNo = (PONTEIRO)malloc(sizeof(NO));
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->chave = ch;
    return(novoNo);
}

PONTEIRO inserirNo(PONTEIRO raiz, PONTEIRO no){
    if (raiz == NULL) return(no);

    if (no->chave < raiz->chave)
        raiz->esq = inserirNo(raiz->esq, no);
    else
        raiz->dir = inserirNo(raiz->dir, no);
    
    return(raiz);
}

int main() {
    PONTEIRO r = inicializar();
    PONTEIRO no = criarNovoNo(23);

    r = inserirNo(r, no);

    return 0;
}
