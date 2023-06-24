#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangar.h"

void inicializar(PILHA *pilha){
pilha->qnt = 0;
}

void inserir(PILHA *pilha){
if(pilha->qnt == 20){
    printf("\nO hangar esta cheio!\n");
    return 0;
}
printf("Digite o nome do aviao: ");
scanf("%s", pilha->hangar[pilha->qnt].nome);
printf("Digite o identificador do aviao: ");
scanf("%d", &pilha->hangar[pilha->qnt].ident);
pilha->qnt++;
printf("\nAviao inserido com sucesso!\n");
}

void exibir(PILHA *pilha){
int i;
if(pilha->qnt == 0){
    printf("O hangar nao possui avioes no momento!\n\n");
    return;
}
for(i = 0; i < pilha->qnt; i++){
    printf("Aviao %d:\n", i+1);
    printf("Nome: %s\n", pilha->hangar[i].nome);
    printf("Identificador: %d\n\n", pilha->hangar[i].ident);

}}

void excluir(PILHA *pilha){
    if(pilha->qnt == 0){
        printf("\nO hangar nao possui avioes para excluir!\n");
        return;
    }
int i = pilha->qnt;
pilha->hangar[i].ident = pilha->hangar[i+1].ident;
strcpy(pilha->hangar[i].nome, pilha->hangar[i+1].nome);
pilha->qnt--;
printf("\nAviao decolou com sucesso!\n");
}

void primeiro(PILHA *pilha){
    if(pilha->qnt == 0){
        printf("\nO hangar nao possui avioes no momento!\n");
        return;
    }
int i = pilha->qnt-1;
printf("\n\nNome: %s\n", pilha->hangar[0].nome);
printf("Identificador: %d", pilha->hangar[0].ident);
printf("\nNumero de avioes na frente: %d\n\n", i);
}


void excluirpos(PILHA *pilha) {
    if (pilha->qnt == 0) {
        printf("\nO hangar esta vazio!\n");
        return;
    }

    int pos, tamres, i, j;
    printf("\nDigite a posicao do aviao que deseja retirar do hangar: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > pilha->qnt) {
        printf("\nPosição invalida!\n");
        return;
    }

    pos--; // Ajustar a posição para começar em 0

    tamres = pilha->qnt - pos - 1;
    int id[tamres];
    char nome[tamres][50];

    // Armazenar os aviões após a posição em variáveis temporárias
    for (i = pilha->qnt - 1, j = 0; i > pos; i--, j++) {
        id[j] = pilha->hangar[i].ident;
        strcpy(nome[j], pilha->hangar[i].nome);
    }

    // Remover os aviões após a posição
    for (i = pos; i < pilha->qnt - 1; i++) {
        pilha->hangar[i].ident = pilha->hangar[i + 1].ident;
        strcpy(pilha->hangar[i].nome, pilha->hangar[i + 1].nome);
    }

    pilha->qnt--;

    // Recolocar os aviões na ordem correta
    for (i = pos, j = tamres - 1; j >= 0; i++, j--) {
        pilha->hangar[i].ident = id[j];
        strcpy(pilha->hangar[i].nome, nome[j]);
    }

    printf("\nAviao removido com sucesso!\n");
}
