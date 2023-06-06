#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    No* lista1 = NULL;
    No* lista2 = NULL;

    // Inserir elementos na lista1:
    inserir(&lista1, 1);
    inserir(&lista1, 2);
    inserir(&lista1, 3);

    // Inserir elementos na lista2:
    inserir(&lista2, 4);
    inserir(&lista2, 5);
    inserir(&lista2, 6);

    // Copiar a lista1 para uma nova lista:
    No* lista_copiada = copiar_lista(lista1);
    printf("Lista copiada: ");
    exibir(lista_copiada);

    // Concatenar as listas lista1 e lista2:
    No* lista_concatenada = concatenar_listas(lista1, lista2);
    printf("Lista concatenada: ");
    exibir(lista_concatenada);

    // Intercalar as listas lista1 e lista2:
    No* lista_intercalada = intercalar_listas(lista1, lista2);
    printf("Lista intercalada: ");
    exibir(lista_intercalada);

    return 0;
}
