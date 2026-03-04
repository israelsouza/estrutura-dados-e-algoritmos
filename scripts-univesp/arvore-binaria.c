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

/* ================================ */

/* 
    Busca binária não recursiva.
    Devolve ponteiro do nó buscado.
    Abastece o pai com o ponteiro para nó pai deste.
*/

PONTEIRO buscarNo(PONTEIRO raiz, TIPOCHAVE ch, PONTEIRO *pai){
    PONTEIRO atual = raiz;
    *pai = NULL;

    while(atual){
        if(atual->chave == ch) return(atual);

        *pai = atual;
        if(ch < atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }

    return(NULL);
}
PONTEIRO removerNo(PONTEIRO raiz, TIPOCHAVE ch){
    PONTEIRO pai, no, p, q;

    no = buscarNo(raiz, ch, &pai);

    if(no==NULL) return(raiz);

    if(!no->esq || !no->dir ){
        if(!no->esq) q = no->dir;
        else q = no->esq;
    }
    else {
        p = no;
        q = no->esq;

        while(q->dir) {
            p=q;
            q=q->dir;
        }
        if(p != no) {
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if(!pai) {
        free(no);
        return(q);
    }
    if (ch < pai->chave) pai->esq = q;
    else pai->dir = q;

    free(no);
    return(raiz);
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
