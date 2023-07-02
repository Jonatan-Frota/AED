#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

int main()
{
    DEQUE deque;
    inicializar(&deque);
    char nome[50];
    char impressao;
    ALUNO novo;
    int opcao = 0, posicao;

    do
    {
        printf("\n[1] Inserir aluno no inicio\n");
        printf("[2] Inserir aluno no final\n");
        printf("[3] Excluir aluno do inicio\n");
        printf("[4] Excluir aluno do final\n");
        printf("[5] Exibir lista\n");
        printf("[6] Finalizar.\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o nome do aluno: ");
            scanf("%s", nome);
            strcpy(novo.nome, nome);
            inseririnicio(&deque, novo);
            break;

        case 2:
            printf("\nDigite o nome do aluno: ");
            scanf("%s", nome);
            strcpy(novo.nome, nome);
            inserirfim(&deque, novo);
            break;

        case 3:
            excluirinicio(&deque);
            break;

        case 4:
            excluirfim(&deque);
            break;

        case 5:
            printf("\nDigite a partir de que posicao deseja exibir: ");
            scanf("%d", &posicao);
            printf("Digite 'd' para imprimir de forma direta ou 'i' para imprimir de forma inversa: ");
            scanf(" %c", &impressao);
            if(impressao == 'd')
            {
                exibirdireta(&deque, posicao);
            }
            if(impressao == 'i')
            {
                exibirinversa(&deque, posicao);
            }
            if(impressao != 'i' && impressao != 'd')
            {
                printf("\nOpcao invalida!\n");
            }
            break;

        case 6:
            printf("\nFinalizando...\n");
            break;

        default:
            printf("\nOpcao invalida. Tente novamente!\n");
            break;
        }
    }
    while (opcao != 6);

    return 0;
}
