#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct no {
    TIPOCHAVE chave;

    struct no *primFilho;
    struct no *proxIrmao;
} NO;

typedef NO* PONTEIRO;


PONTEIRO criarNovoNo(TIPOCHAVE ch){
    PONTEIRO novo = (PONTEIRO)malloc(sizeof(NO));
    novo->chave = ch;
    novo->primFilho = NULL;
    novo->proxIrmao = NULL;
    return(novo);
}

PONTEIRO inicializar(TIPOCHAVE ch){
    return(criarNovoNo(ch));
}

PONTEIRO buscaChave(TIPOCHAVE ch, PONTEIRO raiz){
    if(raiz == NULL) return NULL;
    if(raiz->chave == ch) return raiz;

    PONTEIRO p = raiz->primFilho;
    while (p)
    {
        PONTEIRO resp = buscaChave(ch, p);
        if(resp) return(resp);
        p = p->proxIrmao;
    }
    return(NULL);
}

bool inserir(PONTEIRO raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai){
    PONTEIRO pai = buscaChave(chavePai,raiz);

    if (!pai) return(false);

    PONTEIRO filho = criarNovoNo(novaChave);
    PONTEIRO p = pai->primFilho;

    if (!p) pai->primFilho = filho;
    else {
        while (p->proxIrmao)
        {
            p = p->proxIrmao;
        }
        p->proxIrmao = filho;
    }
    return(true);
}

void exibirArvore(PONTEIRO raiz){
    if(raiz == NULL) return;

    printf("%d(", raiz->chave);
    PONTEIRO p = raiz->primFilho;

    while (p)
    {
        exibirArvore(p);
        p = p->proxIrmao;
    }
    printf(")");
}


int main(){
    PONTEIRO r = inicializar(8);

    return 0;
}
