#include <stdlib.h>
#include <stdio.h>
#include "polinomio.h"

void inserir(LISTA *lista, int grau) {
    int i;
    for (i = 0; i <= grau; i++) {
        POLINOMIO *novo = malloc(sizeof(POLINOMIO));
        printf("Insira o coeficiente do polinomio de grau %d: ", i);
        scanf("%d", &novo->coef);
        novo->exp = i;
        novo->proximo = NULL;

        if (i == 0) {
            lista->inicio = novo;
        } else {
            POLINOMIO *atual = lista->inicio;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novo;
        }

        lista->tam++;
    }
}

void exibir(LISTA *lista) {
    POLINOMIO *atual = lista->inicio;
    while (atual != NULL) {
        printf("%dx^%d ", atual->coef, atual->exp);
        if(atual->proximo != NULL){
            printf("+ ");
        }
        atual = atual->proximo;
    }
}

LISTA* somarp(LISTA *polinomio1, LISTA *polinomio2) {
    LISTA *resultado = malloc(sizeof(LISTA));
    resultado->inicio = NULL;
    resultado->tam = 0;

    POLINOMIO *termo1 = polinomio1->inicio;
    POLINOMIO *termo2 = polinomio2->inicio;

    while (termo1 != NULL && termo2 != NULL) {
        POLINOMIO *novo = malloc(sizeof(POLINOMIO));
        novo->coef = termo1->coef + termo2->coef;
        novo->exp = termo1->exp;
        novo->proximo = NULL;

        if (resultado->inicio == NULL) {
            resultado->inicio = novo;
        } else {
            POLINOMIO *atual = resultado->inicio;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novo;
        }

        resultado->tam++;

        termo1 = termo1->proximo;
        termo2 = termo2->proximo;
    }

    // Copiar os termos restantes do polinômio 1:
    while (termo1 != NULL) {
        POLINOMIO *novo = malloc(sizeof(POLINOMIO));
        novo->coef = termo1->coef;
        novo->exp = termo1->exp;
        novo->proximo = NULL;

        POLINOMIO *atual = resultado->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;

        resultado->tam++;

        termo1 = termo1->proximo;
    }

    // Copiar os termos restantes do polinômio 2:
    while (termo2 != NULL) {
        POLINOMIO *novo = malloc(sizeof(POLINOMIO));
        novo->coef = termo2->coef;
        novo->exp = termo2->exp;
        novo->proximo = NULL;

        POLINOMIO *atual = resultado->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;

        resultado->tam++;

        termo2 = termo2->proximo;
    }

    return resultado;
}
