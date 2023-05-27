#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void NovaLista(int* lista1, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("Insira o elemento %d da lista: \n", i+1);
        scanf("%d", &lista1[i]);
    }
}

void imprimir(int* lista1, int tam) {
    int i;
    printf("\nLista:\n");
    for (i = 0; i < tam; i++) {
        printf("%d ", lista1[i]);
    }
}

void buscar(int* lista1, int tam, int busca) {
    int i, cont = 0, a = 0;

    for (i = 0; i < tam; i++) {
        cont++;
        if (lista1[i] == busca) {
            printf("Valor encontrado em: %d (sequencial - %d comparacoes).\n", i+1, cont);
            a++;
        }
    }

    if (a == 0) {
        printf("\nValor nao encontrado (sequencial - %d comparacoes).", cont);
    }
}

void maiorit(int* lista1, int tam) {
    int i, maior = 0;

    for (i = 0; i < tam; i++) {
        if (lista1[i] > maior) {
            maior = lista1[i];
        }
    }

    printf("\nMaior elemento da lista por busca iterativa: %d", maior);
}

int maiorec(int* lista1, int tam, int maior, int i) {
    if (i == tam) {
        printf("\nMaior elemento da lista por busca recursiva: %d", maior);
        return 0;
    }

    if (lista1[i] > maior) {
        maior = lista1[i];
    }

    return maiorec(lista1, tam, maior, i+1);
}

void menorit(int* lista1, int tam) {
    int i;
    int menor = lista1[0];

    for (i = 0; i < tam; i++) {
        if (lista1[i] < menor) {
            menor = lista1[i];
        }
    }

    printf("\n\nMenor elemento da lista por busca iterativa: %d", menor);
}

int menorec(int* lista1, int tam, int menor, int i) {
    if (i == tam) {
        printf("\nMenor elemento da lista por busca recursiva: %d", menor);
        return 0;
    }

    if (lista1[i] < menor) {
        menor = lista1[i];
    }

    return menorec(lista1, tam, menor, i+1);
}

int somait(int* lista1, int tam) {
    int i, soma = 0;

    for (i = 0; i < tam; i++) {
        soma += lista1[i];
    }

    return soma;
}

int somarec(int* lista1, int tam, int i, int soma) {
    if (i == tam) {
        return soma;
    }
    else {
        soma += lista1[i];
        return somarec(lista1, tam, i+1, soma);
    }
}

int multit(int* lista1, int tam) {
    int i, total = lista1[0];

    for (i = 0; i < tam; i++) {
        total *= lista1[i];
    }

    return total;
}

int multrec(int* lista1, int tam, int i) {
    int produto;

    if (i == tam) {
        return 1;
    }
    else {
        produto = lista1[i] * multrec(lista1, tam, i+1);
        return produto;
    }
}

void NovaListaOrd(int* lista2, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("Insira o valor %d da lista 2: ", i+1);
        scanf("%d", &lista2[i]);
        if (i >= 1) {
            while (lista2[i] < lista2[i-1]) {
                printf("Valor invalido. Insira de forma ordenada! ");
                printf("Insira o valor %d da lista 2: ", i+1);
                scanf("%d", &lista2[i]);
            }
        }
    }
}

void printrec(int *lista2, int tam, int i) {
    if (i == tam) {
        return;
    }
    else {
        printf("%d ", lista2[i]);
        return printrec(lista2, tam, i+1);
    }
}

void bbit(int* lista2, int tam, int busca, int cont) {
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim) {
        int metade = (inicio + fim) / 2;

        if (lista2[metade] == busca) {
            printf("Valor encontrado em: %d (binaria iterativa - %d comparacoes).", metade+1, cont);
            return;
        }

        if (lista2[metade] < busca) {
            inicio = metade + 1;
            cont++;
        }
        else {
            fim = metade - 1;
            cont++;
        }
    }

    printf("\nValor nao encontrado (binaria iterativa - %d comparacoes).", cont);
}

void bbrec(int* lista2, int tam, int busca, int inicio, int fim, int metade, int cont) {
    metade = (inicio + fim) / 2;

    if (inicio > fim) {
        printf("\nValor nao encontrado (binaria recursiva - %d comparacoes).", cont);
        return;
    }

    if (lista2[metade] == busca) {
        printf("\nValor encontrado em: %d (binaria recursiva - %d comparacoes).", metade+1, cont);
        return;
    }

    if (lista2[metade] < busca) {
        bbrec(lista2, tam, busca, metade+1, fim, metade, cont+1);
    }
    else {
        bbrec(lista2, tam, busca, inicio, metade-1, metade, cont+1);
    }
}
