#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"
int main() {
    LISTA lista;
    inicializar(&lista);

    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    inserir(&lista, 4 );
    inserir(&lista, 5);

    printf("Lista Original: ");
    imprimir(&lista);

    l1a(&lista);
    printf("A: ");
    imprimir(&lista);

    l2a(&lista);
    printf("B: ");
    imprimir(&lista);

    return 0;
}
