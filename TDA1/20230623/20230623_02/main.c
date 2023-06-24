#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangar.h"

int main()
{
    PILHA pilha;

    inicializar(&pilha);
    int opcao;
    do{
    printf("\n[1] Listar avioes ja presentes.\n");
    printf("[2] Tirar um aviao do hangar.\n");
    printf("[3] Adicionar um aviao no hangar.\n");
    printf("[4] Exibir todos os avioes no hangar.\n");
    printf("[5] Caracteristicas do primeiro aviao do hangar.\n");
    printf("[6] Tirar um aviao por posicao do hangar.\n");
    printf("[7] Finalizar.\n");
    scanf("%d", &opcao);
    switch(opcao){
case 1:
    exibir(&pilha);
    break;
case 2:
    excluir(&pilha);
    break;

case 3:
    inserir(&pilha);
    break;
case 4:
    exibir(&pilha);
    break;
case 5:
    primeiro(&pilha);
    break;
case 6:
    excluirpos(&pilha);
    break;
case 7:
    printf("\nFinalizando...");
    }
    }while(opcao != 7);
    return 0;
}
