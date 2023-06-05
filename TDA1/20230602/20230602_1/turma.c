#include <stdlib.h>
#include <stdio.h>
#include "turma.h"
#include <stdbool.h>

void inicializar(LISTA* lista) {
    int i;
    for (i = 0; i < 99; i++) {
        lista->turma[i].proximo = i + 1;
        lista->turma[i].alun.matricula = -1;
    }
    lista->turma[99].proximo = -1;
    lista->inicio = -1;
    lista->disponivel = 0;
}

void liberar(LISTA* lista) {
    inicializar(lista);
}

int quantidade(LISTA* lista) {
    int atual = lista->inicio;
    int count = 0;

    while (atual != -1) {
        count++;
        atual = lista->turma[atual].proximo;
    }

    return count;
}

bool cheia(LISTA* lista) {
    return lista->disponivel == -1;
}

bool vazia(LISTA* lista) {
    return lista->inicio == -1;
}

void exibir(LISTA* lista) {
    int atual = lista->inicio;
printf("\nTURMA:\n\n");
    while (atual != -1) {
        printf("Matricula: %d\n", lista->turma[atual].alun.matricula);
        printf("Nome: %s\n", lista->turma[atual].alun.nome);
        printf("Idade: %d\n\n", lista->turma[atual].alun.idade);
        atual = lista->turma[atual].proximo;
    }
}

bool inserir(LISTA* lista, ALUNO aluno) {
    if (cheia(lista)) {
        printf("\nTurma cheia. Nao foi possivel inserir.\n");
        return false;
    }

    int atual = lista->inicio;
    int anterior = -1;

    while (atual != -1 && lista->turma[atual].alun.matricula < aluno.matricula) {
        anterior = atual;
        atual = lista->turma[atual].proximo;
    }

    if (atual != -1 && lista->turma[atual].alun.matricula == aluno.matricula) {
        printf("\nMatricula ja existe na turma!\n");
        return false;
    }

    int posicao = lista->disponivel;
    lista->disponivel = lista->turma[lista->disponivel].proximo;

    lista->turma[posicao].alun = aluno;

    if (anterior == -1) {
        lista->turma[posicao].proximo = lista->inicio;
        lista->inicio = posicao;
    } else {
        lista->turma[posicao].proximo = lista->turma[anterior].proximo;
        lista->turma[anterior].proximo = posicao;
    }

    return true;
}

bool excluir(LISTA* lista, int matricula) {
    if (vazia(lista)) {
        printf("\nTurma vazia. Nao foi possivel excluir.\n");
        return false;
    }

    int atual = lista->inicio;
    int anterior = -1;

    while (atual != -1 && lista->turma[atual].alun.matricula != matricula) {
        anterior = atual;
        atual = lista->turma[atual].proximo;
    }

    if (atual == -1) {
        printf("\bMatricula nao encontrada na turma.\n");
        return false;
    }

    if (anterior == -1) {
        lista->inicio = lista->turma[atual].proximo;
    } else {
        lista->turma[anterior].proximo = lista->turma[atual].proximo;
    }

    lista->turma[atual].proximo = lista->disponivel;
    lista->disponivel = atual;

    return true;
}

bool altMat(LISTA* lista, int matriculaAntiga, int novaMatricula) {
    if (vazia(lista)) {
        printf("\nTurma vazia. Nao foi possível alterar a matricula.\n");
        return false;
    }

    int atual = lista->inicio;

    while (atual != -1 && lista->turma[atual].alun.matricula != matriculaAntiga) {
        atual = lista->turma[atual].proximo;
    }

    if (atual == -1) {
        printf("\nMatricula nao encontrada na lista.\n");
        return false;
    }

    lista->turma[atual].alun.matricula = novaMatricula;

    return true;
}
