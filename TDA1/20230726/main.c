#include <stdio.h>
#include <stdlib.h>
#include "arvore1.h"

int main() {
    ARVORE arvore;
    inicializar(&arvore);
    int opcao, buscar;
    ELEMENTO* aux = malloc(sizeof(ELEMENTO));
    // Inicialização composta:
    inserir(&arvore, &(ELEMENTO){.num.valor = 24});
    inserir(&arvore, &(ELEMENTO){.num.valor = 10});
    inserir(&arvore, &(ELEMENTO){.num.valor = 32});
    inserir(&arvore, &(ELEMENTO){.num.valor = 5});
    inserir(&arvore, &(ELEMENTO){.num.valor = 12});
    inserir(&arvore, &(ELEMENTO){.num.valor = 29});
    inserir(&arvore, &(ELEMENTO){.num.valor = 35});

    //Exibir:
    printf("Digite a opcao de exibicao: \n[1] Pre-Ordem.\n[2] In-Ordem.\n[3]Pos-ordem.\n");
    scanf("%d", &opcao);
    printf("\n");
    exibir(&arvore, opcao);

    //Buscar:
    printf("\nDigite o valor a ser encontrado: ");
    scanf("%d", &buscar);
    aux = busca(&arvore, buscar);

    if (aux != NULL) {
        printf("\nValor encontrado: %d", aux->num.valor);
    } else {
        printf("\nNao encontrado!");
    }

    return 0;
}

