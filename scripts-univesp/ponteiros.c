#include <stdio.h>

int main() {
    int x = 25;

    printf("Valor inicial de x: %i\n", x); // 25

    int* y = &x; // guarda a referencia de memoria da variavel x

    *y = 30; // diz para atualizar o valor da referencia que y armazena (25 para 30)

    printf("Valor atual de x: %i\n", x); // 30

    return 0;
}