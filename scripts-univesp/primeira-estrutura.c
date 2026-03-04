#include <stdio.h>
#define alturaMaxima 225

typedef struct {
    int peso;
    int altura;
} PesoAltura;

int main(){
    PesoAltura pessoa1;
    pessoa1.altura = 80;
    pessoa1.peso = 185;

    printf("Altura: %i, Peso: %i.", pessoa1.altura, pessoa1.peso);

    if (pessoa1.altura > alturaMaxima) printf("Altura acima da máxima.\n");
    else printf("Altura abaixo da máxima.\n");

    return 0;
}
