#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HASHIII.h"
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

void excluir(TBHASH tabela, int codigo) {
    int h = dispersar(codigo);
    ELEMENTO* atual = tabela[h];
    ELEMENTO* anterior = NULL;

    while (atual != NULL && atual->pac.codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Paciente nao encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        tabela[h] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Paciente excluido com sucesso!\n");
}

