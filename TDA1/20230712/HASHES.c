#include <stdio.h>
#include <stdlib.h>
#include "HASHES.h"
#define MAX 11

void inicializar(TBHASH tabela){
int i;
for(i = 0; i < MAX; i++){
    tabela[i] = NULL;
}}

int dispersar(int chave){
int j = (2*chave + 5)%MAX;
return(j);
}

void inserir(TBHASH tabela, INTEIRO novo){
int h = dispersar(novo.valor);
ELEMENTO *atual = tabela[h];
ELEMENTO *anterior = NULL;
    while(atual != NULL){
    if(atual->inteiro.valor == novo.valor){
        printf("\nValor ja inserido!\n");
    return;
    }
    anterior = atual;
    atual = atual->proximo;
        }
    if(atual == NULL){
        atual = malloc(sizeof(ELEMENTO));
        atual->inteiro = novo;
        atual->proximo = NULL;
        if(anterior == NULL){
            tabela[h] = atual;
        }
        else{
            anterior->proximo = atual;
        }


    }
    return 1;
}
void exibir(TBHASH tabela){
int i;
ELEMENTO* atual;
for(i = 0; i < MAX; i++){
    if(tabela[i] != NULL){
        printf("\nPosicao %d-> ", i +1);
        atual = tabela[i];
        while(atual != NULL){
            printf("%d ", atual->inteiro.valor);
            atual = atual->proximo;
        }
    }
}
}
