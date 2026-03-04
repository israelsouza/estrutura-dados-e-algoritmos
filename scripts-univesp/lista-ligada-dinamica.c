// Modelagem

#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    // demais campos
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* proximo; // ponteiro do tipo elemento, aponta pro proximo elemento - notação especial pois ao ler linha a linha, não existe o tipo ELEMENTO ainda
} ELEMENTO;

typedef ELEMENTO* PONTEIRO;

typedef struct {
    PONTEIRO inicio;
} LISTA;



// Inicializar a estrutura

void inicializarEstrutura(LISTA* l){
    l->inicio = NULL;
}


// Retornar a quantidade de elementos válidos

int tamanho(LISTA* l){
    PONTEIRO endereco_valido = l->inicio;
    int tamanho = 0;

    while (endereco_valido != NULL) 
    {
        tamanho++;
        endereco_valido = endereco_valido->proximo;
    }

    return tamanho;
}


// Exibir/imprimir os elementos da estrutura

void exibirLista(LISTA* l){
    PONTEIRO endereco_valido = l->inicio;
    printf("LISTA: \" ");
    
    while (endereco_valido != NULL)
    {
        printf("%i ", endereco_valido->reg.chave);
        endereco_valido = endereco_valido->proximo;
    }

    printf("\"\n");
}


// Buscar por um elemento na estrutura
/* existem 2 cenários
    - id (chave) com ordem sequencial  (1, 2, 3...)
    - id não ordenado (uuid)
*/

PONTEIRO buscaSequencial(LISTA* l, TIPOCHAVE ch){ // necessario percorrer TODA a lista
    PONTEIRO posicao_atual = l->inicio;

    while ( posicao_atual != NULL )
    {
        if ( posicao_atual->reg.chave == ch ) return posicao_atual;
        posicao_atual = posicao_atual->proximo;
    }

    return NULL;
}


PONTEIRO buscaSequencialOrdenada ( LISTA* l, TIPOCHAVE ch ) { // qnd ordenada, nao nec. percorrer tudo
    PONTEIRO pososicao_atual = l->inicio;

    while (pososicao_atual != NULL && pososicao_atual->reg.chave < ch)
    {
        pososicao_atual = pososicao_atual->proximo;
    }
    
    if(pososicao_atual != NULL && pososicao_atual->reg.chave == ch ) return pososicao_atual;

    return NULL;
}


// Inserir elementos na estrutura 

PONTEIRO buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONTEIRO* ant){
    *ant = NULL;
    PONTEIRO atual = l->inicio;

    while ( (atual != NULL ) && (atual->reg.chave < ch))
    {
        *ant = atual;
        atual = atual->proximo;
    }
    
    if ( (atual != NULL) && (atual->reg.chave == ch) ) return atual;

    return NULL
}

bool inserirElementoListaOrdenada(LISTA* l, REGISTRO reg){
    TIPOCHAVE ch = reg.chave;
    PONTEIRO ant, i;

    i = buscaSequencialExc(l, ch, &ant);

    if (i != NULL) return false; 

    i = (PONTEIRO) malloc(sizeof(ELEMENTO));

    i->reg = reg;

    // agr q foi inserido, basta ajustar ponteiros

    if (ant == NULL)
    {
        i->proximo = l->inicio;
        l->inicio = i;
    }
    else
    {
        i->proximo = ant->proximo;
        ant->proximo = i;
    }
    return true;
}


// Excluir elementos na estrutura

bool excluirElementoLista(LISTA* l, TIPOCHAVE ch){
    PONTEIRO ant, i;

    i = buscaSequencialExc(l, ch, &ant);

    if (i == NULL) return false;

    if(ant == NULL) l->inicio = i->proximo;
    else ant->proximo = i->proximo;

    free(i);
    return true;
}


// Reinicializar a estrutura

void reinicializarLista(LISTA* l) {
    PONTEIRO end = l->inicio;

    while (end!=NULL)
    {
        PONTEIRO apagar = end;
        end = end->proximo;
        free(apagar);
    }

    l->inicio = NULL;
}

