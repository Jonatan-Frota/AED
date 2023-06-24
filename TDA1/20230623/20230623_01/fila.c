#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializar(FILA* fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

void inserir(FILA* fila, char modelo[50], int identificador){
    AVIAO *aux;
    aux = malloc(sizeof(AVIAO));
    aux->ident = identificador;
    strcpy(aux->nome, modelo);
    if(fila->inicio == NULL)
    {
        fila->inicio = aux;
        fila->fim = aux;
        aux->proximo = NULL;
    }
    else
    {
        fila->fim->proximo = aux;
        fila->fim = aux;
        aux->proximo = NULL;
    }
    printf("\nAviao inserido na fila com sucesso!\n");
}


void autorizar(FILA *fila)
{
    AVIAO *aux;
    aux = fila->inicio;
    fila->inicio = aux->proximo;
    aux = NULL;
    printf("\nAviao decolou com sucesso!\n\n");
}

void exibir(FILA *fila)
{
    AVIAO *aux;
    aux = fila->inicio;
    while(aux != NULL)
    {
        printf("Nome: %s", aux->nome);
        printf("\nIdentificador: %d\n\n", aux->ident);
        aux = aux->proximo;
    }
}

void primeiro(FILA *fila)
{
    AVIAO *aux;
    aux = fila->inicio;
    printf("Nome: %s", aux->nome);
    printf("\nIdentificador: %d\n\n", aux->ident);

}
