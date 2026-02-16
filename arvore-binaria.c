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

/* ================== */

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

/* ================== */

PONTEIRO buscarElemento(TIPOCHAVE ch, PONTEIRO raiz){
    if (raiz == NULL) return(NULL);

    if (raiz->chave == ch) return(raiz);

    if (raiz->chave > ch)
        return(buscarElemento(ch, raiz->esq));
    
    return(buscarElemento(ch, raiz->dir));
}

int contarNumeroNos(PONTEIRO raiz){
    if(!raiz) return 0;

    return(contarNumeroNos(raiz->esq)
            +1
            +contarNumeroNos(raiz->dir)
          );
}

void printarArvore(PONTEIRO raiz){
    if(raiz != NULL) {
        printf("%i", raiz->chave);
        printf("(");
        printarArvore(raiz->esq);
        printarArvore(raiz->dir);
        printf(")");
    }
}


int main() {
    PONTEIRO r = inicializar();

    PONTEIRO no = criarNovoNo(23);
    r = inserirNo(r, no);

    no = criarNovoNo(20);
    r = inserirNo(r, no);

    no = criarNovoNo(29);
    r = inserirNo(r, no);

    no = criarNovoNo(22);
    r = inserirNo(r, no);

    // no = criarNovoNo(25);
    // r = inserirNo(r, no);

    PONTEIRO p = buscarElemento(20, r);

    // printf("%d\n", contarNumeroNos(r));

    printarArvore(r);

    return 0;
}
