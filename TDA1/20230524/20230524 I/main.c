#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    // Criação e print da lista:
    int tam, busca, i = 0, cont = 0;
    int* lista1;
    printf("Insira o tamanho da lista: ");
    scanf("%d", &tam);
    lista1 = (int*) malloc(tam*sizeof(int));
    NovaLista(lista1, tam);
    imprimir(lista1, tam);

// Buscando um elemento:
    printf("\n\nInsira um numero que deseja buscar na lista: ");
    scanf("%d", &busca);
    buscar(lista1, tam, busca);

// Busca de maior e menor valor:
int valor = lista1[0];
    maiorit(lista1, tam);
    maiorec(lista1, tam, valor, i);
    menorit(lista1, tam);
    menorec(lista1, tam, valor, i);

// Soma dos elementos:
int soma1 = 0, soma2 = 0;
    soma1 = somait(lista1, tam);
    printf("\n\nSoma dos elementos de forma iterativa: %d", soma1);

    soma2 = somarec(lista1, tam, i, soma2);
    printf("\nSoma dos elementos de forma recursiva: %d", soma2);

// Produto dos elementos:
int mult1, mult2, k = 1;
    mult1 = multit(lista1, tam);
    printf("\n\nProduto dos elementos de forma iterativa: %d", mult1);
    mult2 = multrec(lista1, tam, k);
    printf("\nProduto dos elementos de forma recursiva: %d", mult2);

// Criação da lista2:
   int* lista2;
   lista2 = (int*) malloc(30*sizeof(int));
   printf("\n\n------------------- LISTA 2 ------------------------\nInsira os elementos de forma ORDENADA:\n\n");
   NovaListaOrd(lista2, 30);

// Imprimir lista:
   imprimir(lista2, 30);
   printf("\nLista por recursividade:\n");
   printrec(lista2, 30, i);

// Busca na lista 2:
int inicio = 0, fim = 30, metade;
    printf("\n\nInsira um numero que deseja buscar na lista 2: ");
    scanf("%d", &busca);
    buscar(lista2, 30, busca);
    bbit(lista2, 30, busca, cont);
    bbrec(lista2, 30, busca, inicio, fim, metade, cont);

    free(lista1);
    free(lista2);

    return 0;
}
