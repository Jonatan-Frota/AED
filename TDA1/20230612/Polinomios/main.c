#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"
typedef struct POLINOMIO {
    int coef;
    int exp;
    struct POLINOMIO *proximo;
} POLINOMIO;

typedef struct {
    POLINOMIO *inicio;
    int tam;
} LISTA;

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
