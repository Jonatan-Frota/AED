#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"


Turma* criar(Turma* turma, int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++) {
        printf("\nInsira o codigo do aluno %d: ", i + 1);
        scanf("%d", &turma->alunos[i].codigo);
        printf("Insira o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]", turma->alunos[i].nome);
        printf("Insira a idade do aluno %d: ", i + 1);
        scanf("%d", &turma->alunos[i].idade);
        printf("Insira o coeficiente do aluno %d: ", i + 1);
        scanf("%f", &turma->alunos[i].coef);
    }
    return turma;
}

void printar(Turma* turma, int quantidade){
    printf("\nTURMA:\n");
    int i;
    for (i = 0; i < quantidade; i++){
        printf("\nCodigo: %d\n", turma->alunos[i].codigo);
        printf("Nome: %s\n", turma->alunos[i].nome);
    }
}

void busca(Turma* turma, int quantidade, int codaluno) {
    int i;
    for (i = 0; i < quantidade; i++){
        if (turma->alunos[i].codigo == codaluno) {
            printf("Busca iterativa:\nNome: %s\n", turma->alunos[i].nome);
            printf("Idade: %d\n", turma->alunos[i].idade);
            printf("Coeficiente: %1.2f\n", turma->alunos[i].coef);
            return;
        }
    }
    printf("Aluno nao encontrado.\n");
}

void buscarec(Turma* turma, int quantidade, int codaluno, int i){
    if (i >= quantidade) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    if (turma->alunos[i].codigo == codaluno){
        printf("\nBusca recursiva: \nNome: %s\n", turma->alunos[i].nome);
        printf("Idade: %d\n", turma->alunos[i].idade);
        printf("Coeficiente: %1.2f\n", turma->alunos[i].coef);
        return;
    }

    buscarec(turma, quantidade, codaluno, i + 1);
}
