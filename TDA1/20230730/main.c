#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arvnot.h"

int main() {
    struct No* raiz = NULL;
    char expressao[] = "a * (b - c / d)";
    int indice = 0;
    raiz = inserirExpressao(raiz, expressao, &indice);

    printf("Notacao Infixa: ");
    imprimirInfixa(raiz, false);
    printf("\nNotacao Posfixa: ");
    imprimirPosfixa(raiz);
    printf("\nNotacao Prefixa: ");
    imprimirPrefixa(raiz);
    printf("\n");

    int resultado = avaliarExpressao(raiz);
    printf("Resultado: %d\n", resultado);

    return 0;
}
