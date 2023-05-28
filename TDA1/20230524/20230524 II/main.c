#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"

int main() {
    int codaluno, i = 0;
    Turma* turma;
    turma = (Turma*)malloc(sizeof(Turma));
    turma = criar(turma, 20);
    printf("\n\nInsira um codigo de busca para aluno: ");
    scanf("%d", &codaluno);
    busca(turma, 20, codaluno);
    buscarec(turma, 20, codaluno, i);
    printar(turma, 20);

    return 0;
}
