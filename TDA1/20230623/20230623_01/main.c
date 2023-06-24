#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
int main()
{
    FILA fila;
    inicializar(&fila);
    int op, qnt, ident, i;
    char nome[50];
    do
    {
        printf("TABELA: \n\n");
        printf("[1] Inserir N avioes na fila.\n");
        printf("[2] Autorizar decolagem do primeiro aviao.\n");
        printf("[3] Adicionar um novo aviao a fila.\n");
        printf("[4] Listar todos os avioes na fila.\n");
        printf("[5] Caracteristicas do primeiro aviao.\n");
        printf("[6] Finalizar.\n");
        scanf("%d", &op);


    switch(op){

    case 1:
        printf("Digite a quantidade de avioes que deseja inserir: ");
        scanf("%d", &qnt);
        for(i = 0; i < qnt; i++)
        {
            printf("Digite o nome do aviao %d: ", i+1);
            scanf("%s", nome);
            printf("Digite o identificador do aviao %d: ", i+1);
            scanf("%d", &ident);
            printf("\n");
            inserir(&fila, nome, ident);
            printf("\n");
        }
        break;

    case 2:
        autorizar(&fila);
        break;
    case 3:
            printf("Digite o nome do aviao %d: ", i+1);
            scanf("%s", nome);
            printf("Digite o identificador do aviao %d: ", i+1);
            scanf("%d", &ident);
            inserir(&fila, nome, ident);
        break;

    case 4:
        exibir(&fila);
        break;
    case 5:
        primeiro(&fila);
        break;
    case 6:
        printf("Finalizando...");
    }
        }while(op!=6);
    return 0;
}
