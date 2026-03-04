// Modelagem

#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct tempRegistro {
    REGISTRO reg;
    struct tempRegistro* proximo;
} ELEMENTO;

typedef ELEMENTO* PONTEIRO; // se le 'tipo ponteiro para elemento'

typedef struct {
    PONTEIRO cabeca;
} LISTA;



// Inicializar a estrutura

void inicializarEstrutura(LISTA* l){
    l->cabeca = (PONTEIRO) malloc(sizeof(ELEMENTO));
    l->cabeca->proximo = l->cabeca;
}

// Retornar a quantidade de elementos válidos

int tamanho(LISTA* l){
    PONTEIRO endereco_valido = l->cabeca->proximo;
    int tamanho = 0;

    while (endereco_valido != l->cabeca) 
    {
        tamanho++;
        endereco_valido = endereco_valido->proximo;
    }

    return tamanho;
}

// Exibir/imprimir os elementos da estrutura

void exibirLista(LISTA* l){
    PONTEIRO endereco_valido = l->cabeca->proximo;
    printf("LISTA: \" ");
    
    while (endereco_valido != l->cabeca)
    {
        printf("%i ", endereco_valido->reg.chave);
        endereco_valido = endereco_valido->proximo;
    }

    printf("\"\n");
}


// Buscar por um elemento na estrutura

PONTEIRO buscaSentinela(LISTA* l, TIPOCHAVE ch){
    PONTEIRO posicao = l->cabeca->proximo;
    l->cabeca->reg.chave = ch;
    // lista ordenada <    lista não ordenada !=
    while (posicao->reg.chave != ch) posicao = posicao->proximo;
    // e adapta essa condicao tambem
    if(posicao != l->cabeca) return posicao;
    // segunda condicao serve pois pode ser que a chave do elemento atual seja maior do que a buscada, não necessáriamente é a buscada
    //if(posicao != l->cabeca && posicao->reg.chave == ch) return posicao;
    return NULL;
}


// Inserção

// auxiliar (EXC vem de Exclusão, pois é usado tbm em excluir)
// ideia de DRY tornaria 2 funcoes independentes??
// ps: DRY não é sobre rep de código, mas sim de lógica (ver augusto galego)

PONTEIRO buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONTEIRO* ant){
    *ant = l->cabeca;
    PONTEIRO atual = l->cabeca->proximo;
    l->cabeca->reg.chave = ch;
    while( atual->reg.chave < ch)
    {
        *ant = atual;
        atual = atual->proximo;
    }
    if(atual != l->cabeca && atual->reg.chave == ch) return atual;

    return NULL;
}

bool inserirElementoListaOrd(LISTA* l, REGISTRO reg){
    PONTEIRO ant, i;
    i = buscaSeqExc(l, reg.chave, &ant);
    if ( i != NULL ) return false;
    i = (PONTEIRO) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    i->proximo = ant->proximo;
    ant->proximo = i;
    return true;
}


// Exclusão

bool excluirElementoLista(LISTA* l, TIPOCHAVE ch){
    PONTEIRO ant, i;
    i = buscaSeqExc(l, ch, &ant);
    if (i == NULL) return false;
    ant->proximo = i->proximo;
    free(i);
    return true;    
}


// Reinicialização

void reiniciarEstrutura(LISTA* l){
    PONTEIRO endereco_atual = l->cabeca->proximo;

    while (endereco_atual != l->cabeca)
    {
        PONTEIRO apagar = endereco_atual;
        endereco_atual = endereco_atual->proximo;
        free(apagar);
    }

    l->cabeca->proximo = l->cabeca;
}
