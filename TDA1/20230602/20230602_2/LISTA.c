#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"

void inicializar(LISTA* lista) {
    int i;
    for (i = 0; i < 99; i++) {
        lista->nos[i].prox = i + 1;
    }
    lista->nos[99].prox = -1;
    lista->inicio = -1;
    lista->disponivel = 0;
}

int inserir(LISTA* lista, int valor) {
    if (lista->disponivel != -1) {
        int novoNo = lista->disponivel;
        lista->disponivel = lista->nos[novoNo].prox;
        lista->nos[novoNo].dado = valor;
        lista->nos[novoNo].prox = -1;

        if (lista->inicio == -1) { lista->inicio = novoNo; }
        else {
            int atual = lista->inicio;
            while (lista->nos[atual].prox != -1) {
                atual = lista->nos[atual].prox;
            }
            lista->nos[atual].prox = novoNo;
        }

        return 1;
    } else { return 0; }
}

void imprimir(LISTA* lista) {
    int atual = lista->inicio;
    while (atual != -1) {
        printf("%d ", lista->nos[atual].dado);
        atual = lista->nos[atual].prox;
    }
    printf("\n");
}

void l1a(LISTA* lista) {
    if (lista->inicio != -1) {
        int primeiroNo = lista->inicio;
        int segundoNo = lista->nos[primeiroNo].prox;

        if (segundoNo != -1) {
            int atual = segundoNo;
            while (lista->nos[atual].prox != -1) {
                atual = lista->nos[atual].prox;
            }
            lista->nos[atual].prox = primeiroNo;
            lista->inicio = segundoNo;
            lista->nos[primeiroNo].prox = -1;
        }
    }
}

void l2a(LISTA* lista) {
    int anterior = -1;
    int atual = lista->inicio;
    int proximo;

    while (atual != -1) {
        proximo = lista->nos[atual].prox;
        lista->nos[atual].prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->inicio = anterior;
}
