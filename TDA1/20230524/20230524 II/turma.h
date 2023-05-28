#ifndef TURMA_H_INCLUDED
#define TURMA_H_INCLUDED

typedef struct ALUNO {
    int codigo;
    char nome[50];
    int idade;
    float coef;
} aluno;

typedef struct TURMA {
    aluno alunos[30];
} Turma;


Turma* criar(Turma* turma, int quantidade);
void printar(Turma* turma, int quantidade);
void busca(Turma* turma, int quantidade, int codaluno);
void buscarec(Turma* turma, int quantidade, int codaluno, int i);



#endif // TURMA_H_INCLUDED
