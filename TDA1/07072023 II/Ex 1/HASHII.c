#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HASHII.h"
#define MAX 10

void inicializar(TABELAH tabela) {
    int i;
    for (i = 0; i < MAX; i++) {
        tabela[i] = NULL;
    }
}

int dispersar(int chave) {
    int h;
    h = (chave % MAX);
    return h;
}

int inserir(TABELAH tabela, PACIENTE novo) {
    int h;
    h = dispersar(novo.codigo);
    while (tabela[h] != NULL) {
        if (tabela[h]->codigo == novo.codigo) {
            if (tabela[h]->flag == 0) {
                *tabela[h] = novo;
                tabela[h]->flag = 1;
                return 1;
            } else {
                printf("\nPaciente ja inserido!\n");
                return 0;
            }
        }
        h = (h + 1) % MAX;
    }
    if (tabela[h] == NULL || tabela[h]->flag == 0) {
        tabela[h] = malloc(sizeof(PACIENTE));
        if (tabela[h] == NULL) {
            printf("\nFalha ao alocar memoria!\n");
            return 0;
        }
        *tabela[h] = novo;
        tabela[h]->flag = 1; // Marca o paciente como não excluído
        return 1;
    }
    return 0;
}

void excluir(TABELAH tab, int codigo) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tab[i] != NULL && tab[i]->codigo == codigo) {
            tab[i]->flag = 0; // Marca o paciente como excluído
            return;
        }
    }
    printf("\nPaciente nao encontrado!\n");
}


void mostrartab(TABELAH tab) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tab[i] != NULL) {
            printf("\nNome: %s\n", tab[i]->nome);
            printf("Idade: %d\n", tab[i]->idade);
            printf("CPF: %s\n", tab[i]->cpf);
            printf("Codigo: %d\n", tab[i]->codigo);
        }
    }
}



