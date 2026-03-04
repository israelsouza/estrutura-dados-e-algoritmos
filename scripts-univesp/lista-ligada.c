// MODELAGEM

#define MAX 50
#define VALOR_INVALIDO -1

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave; // tipo de ID
    // demias campos
} REGISTRO;

typedef struct {
    REGISTRO reg;
    int proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX];
    int inicio; // os valores que o usuário inseriu
    int disponivel;
} LISTA;

// Inicializar a estrutura

// aqui, todos elem estão disponiveis
// var inicio (nao há item valido, pois nada foi inserido)
// var dispo (pos do primeiro elem da lista disponivel (pd ser pos 4, 8...))

void inicializarLista(LISTA* l){ // lista que usuario ve
    int i;
    for (i=0; i<MAX-1; i++) {
        l->A[i].proximo = i+1;
    }
    l->A[MAX-1].proximo=VALOR_INVALIDO;
    l->inicio = VALOR_INVALIDO;
    l->disponivel=0;
}


// Retornar a quantidade de elementos válidos
// para se obter, é necessario percorrer a lista com valores válidos

int tamanho(LISTA* l){
    int i = l->inicio;
    int tamanho = 0;

    while (i != VALOR_INVALIDO)
    {
        tamanho++;
        i = l->A[i].proximo;
    }

    return tamanho;
}



// Exibir/imprimir elementos da estrutura

void exibirLista(LISTA* l){
    int i = l->inicio;

    printf("lista: \" ");

    while (i != VALOR_INVALIDO)
    {
        printf("%i ", l->A[i].reg.chave );

        i = l->A[i].proximo;
    }

    printf("\"\n");
}



// Buscar por um elemento (lista já ordenada)
// recebe uma chave -- retorna:
// posicao - se encontrar elemento  OU
// invalido - se não encontrar elemento

// não é possivel usar busca binaria devido a dispersao em memoria dos elementos

int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch){
    int i = l->inicio;

    while (i != VALOR_INVALIDO && l->A[i].reg.chave < ch)
    {
        i = l->A[i].proximo;
    }

    if (i != VALOR_INVALIDO && l->A[i].reg.chave == ch)
    {
        return i;
    }

    return VALOR_INVALIDO;
}


// - Inserir elementos na estrutura

int obterNo(LISTA* l){
    int resultado = l->disponivel;
    if(l->disponivel != VALOR_INVALIDO)
    {
        l->disponivel = l->A[l->disponivel].proximo;
    }
    return resultado;
}


bool inserirListaOrd(LISTA* l, REGISTRO reg){
    if (l->disponivel == VALOR_INVALIDO) return false;

    int ant = VALOR_INVALIDO;
    int i = l->inicio;
    TIPOCHAVE ch = reg.chave;

    while (( i != VALOR_INVALIDO) && (l->A[i].reg.chave < ch))
    {
        ant = i;
        i = l->A[i].proximo;
    }

    if ( i != VALOR_INVALIDO && l->A[i].reg.chave == ch) return false; // significa que o registro já existe, e para nao haver duplicidade, encerramos a função por aqui

    i = obterNo(l);
    l->A[i].reg = reg;

    if (ant == VALOR_INVALIDO) // se sim, é o primeiro elemento
    {
        l->A[i].proximo = l->inicio;
        l->inicio = i; // aponta para ele, o primeiro elemento da lista
    }
    else // se nao, é algo depois do primeiro elemento
    {
        l->A[i].proximo = l->A[ant].proximo; // ajusta ponteiro do elemento atual para o proximo
        l->A[ant].proximo = i; // ajusta ponteiro do elemento anterior para o novo
    }
    return true;
}


// - Excluir elementos na estrutura

void devolverNo(LISTA* l, int j\){
    l->A[j].proximo = l->disponivel;
    l->disponivel = j;
}

bool excluirElementoLista(LISTA* l, TIPOCHAVE ch) {
    int ant = VALOR_INVALIDO;
    int i = l->inicio;

    while (( i != VALOR_INVALIDO) && (l->A[i].reg.chave < ch))
    {
        ant = i;
        i = l->A[i].proximo;
    }

    if(i==VALOR_INVALIDO || l->A[i].reg.chave != ch) return false;

    if(ant == VALOR_INVALIDO) l->A[i].proximo;
    else l->A[ant].proximo = l->A[i].proximo;

    devolverNo(l, i);

    return true;
} 


// - Reinicializar a estrutura

void reinicializarLista(LISTA* l){
    inicializarLista(l);
}
