#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashII.h"
#define MAX 10

void inicializar(TBHASH tabela){
int i;
for(i = 0; i < MAX; i++){
    tabela[i] = NULL;
}}

int dispersar(int chave){
int h;
h = (chave%MAX);
return(h);
}

int inserir(TBHASH tabela, PACIENTE novo){
int h;
h = dispersar(novo.codigo);
ELEMENTO* anterior = NULL;
ELEMENTO* atual = tabela[h];
while(atual != NULL){
    anterior = atual;
    atual = atual->proximo;
}
if(atual == NULL){
    atual = malloc(sizeof(ELEMENTO));
    atual->pac = novo;
    atual->proximo = NULL;
    if(anterior == NULL){
        tabela[h] = atual;
    }
    else{
        anterior->proximo = atual;
    }
    return 1;
}
}
void mostrartab(TBHASH tabela){
ELEMENTO* atual;
int i;
for(i = 0; i < MAX; i++){
    if(tabela[i] != NULL){
        atual = tabela[i];
        while(atual != NULL){
            printf("(%s, ", atual->pac.nome);
            printf("Idade: %d, ", atual->pac.idade);
            printf("CPF: %s)   ", atual->pac.cpf);
            atual = atual->proximo;
        }
    }
    else{
        printf("\nLista de pacientes %d -> ", i+1);
    }
}}
