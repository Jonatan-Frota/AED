#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inserir(No** inicio, int dado) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No* atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

No* copiar_lista(No* lista) {
    if (lista == NULL) {
        return NULL;
    }

    No* atual = lista;
    No* nova_inicio = NULL;
    No* fim = NULL;

    while (atual != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = atual->dado;
        novo->prox = NULL;

        if (nova_inicio == NULL) {
            nova_inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = fim->prox;
        }

        atual = atual->prox;
    }

    return nova_inicio;
}

No* concatenar_listas(No* lista1, No* lista2) {
    if (lista1 == NULL) {
        return copiar_lista(lista2);
    }

    No* atual = lista1;
    No* nova_inicio = copiar_lista(lista1);
    No* fim = NULL;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    fim = atual;
    fim->prox = copiar_lista(lista2);

    return nova_inicio;
}

No* intercalar_listas(No* lista1, No* lista2) {
    if (lista1 == NULL) {
        return copiar_lista(lista2);
    }
    if (lista2 == NULL) {
        return copiar_lista(lista1);
    }

    No* atual1 = lista1;
    No* atual2 = lista2;
    No* nova_inicio = NULL;
    No* fim = NULL;

    while (atual1 != NULL && atual2 != NULL) {
        No* novo1 = (No*)malloc(sizeof(No));
        novo1->dado = atual1->dado;
        novo1->prox = NULL;

        No* novo2 = (No*)malloc(sizeof(No));
        novo2->dado = atual2->dado;
        novo2->prox = NULL;

        if (nova_inicio == NULL) {
            nova_inicio = novo1;
            fim = novo1;
            fim->prox = novo2;
            fim = fim->prox;
        } else {
            fim->prox = novo1;
            fim = fim->prox;
            fim->prox = novo2;
            fim = fim->prox;
        }

        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    while (atual1 != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = atual1->dado;
        novo->prox = NULL;

        fim->prox = novo;
        fim = fim->prox;

        atual1 = atual1->prox;
    }

    while (atual2 != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = atual2->dado;
        novo->prox = NULL;

        fim->prox = novo;
        fim = fim->prox;

        atual2 = atual2->prox;
    }

    return nova_inicio;
}

void exibir(No* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
    } else {
        No* atual = inicio;
        while (atual != NULL) {
            printf("%d ", atual->dado);
            atual = atual->prox;
        }
        printf("\n");
    }
}
