#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

int main() {
    LISTA polinomio1;
    polinomio1.inicio = NULL;
    polinomio1.tam = 0;

    LISTA polinomio2;
    polinomio2.inicio = NULL;
    polinomio2.tam = 0;

    int grau1, grau2;

    printf("Insira o maior grau do polinomio 1: ");
    scanf("%d", &grau1);
    inserir(&polinomio1, grau1);

    printf("\nInsira o maior grau do polinomio 2: ");
    scanf("%d", &grau2);
    inserir(&polinomio2, grau2);

    printf("\nPolinomio 1:\n");
    exibir(&polinomio1);

    printf("\n\nPolinomio 2:\n");
    exibir(&polinomio2);

    LISTA *soma = somarp(&polinomio1, &polinomio2);

    printf("\n\nSOMA:\n");
    exibir(soma);

    return 0;
}
