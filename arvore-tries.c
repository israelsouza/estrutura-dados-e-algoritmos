#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define true 1
#define false 0
#define N_ALFABETO 26

typedef int bool;
typedef bool TIPORETORNO;

typedef struct no {
    struct no *filhos[N_ALFABETO]; // arranjo de ponteiro para nó
    TIPORETORNO fim;
} NO;

typedef NO* PONTEIRO;




PONTEIRO criarNo(){
    PONTEIRO p = NULL;

    p = (PONTEIRO)malloc(sizeof(NO));
    if (p) {
        p->fim = false;
        int i;
        for (i=0; i< N_ALFABETO; i++)
            p->filhos[i] = NULL;
    }
    return(p);
}

PONTEIRO inicializar() {
    return(criarNo());
}



int mapearIndice(char c){
    return( (int)c - (int)'a' );
}


void inserir(PONTEIRO raiz, char *chave){
    int nivel;
    int compr = strlen(chave);
    int i;
    PONTEIRO p = raiz;

    for(nivel=0; nivel < compr; nivel++){
        i = mapearIndice(chave[nivel]);
        if(!p->filhos[i]){
            p->filhos[i] = criarNo();
        }
        p = p->filhos[i];
    }
    p->fim = true;
}


bool buscar(PONTEIRO raiz, char *chave){
    int nivel;
    int compr = strlen(chave);
    int i;

    PONTEIRO p = raiz;

    for(nivel=0; nivel<compr; nivel++){
        i = mapearIndice(chave[nivel]);
        if(!p->filhos[i]) return false;
        p = p->filhos[i];
    }
    return(p->fim);
}




int main() {
    PONTEIRO r = inicializar();
}