#include <stdbool.h>
#ifndef TURMA_H_INCLUDED
#define TURMA_H_INCLUDED


typedef struct {
    int matricula;
    char nome[50];
    int idade;
} ALUNO;

typedef struct {
    ALUNO alun;
    int proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO turma[100];
    int inicio;
    int disponivel;
} LISTA;

void inicializar(LISTA* lista);
void liberar(LISTA* lista);
int quantidade(LISTA* lista);
bool cheia(LISTA* lista);
bool vazia(LISTA* lista);
void exibir(LISTA* lista);
bool inserir(LISTA* lista, ALUNO aluno);
bool excluir(LISTA* lista, int matricula);
bool altMat(LISTA* lista, int matriculaAntiga, int novaMatricula);

#endif // TURMA_H_INCLUDED
