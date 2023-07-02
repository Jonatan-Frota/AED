#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

typedef struct
{
    int posicao;
    char nome[50];
} ALUNO;

typedef struct aux
{
    ALUNO alun;
    struct aux* proximo;
    struct aux* anterior;
} ELEMENTO;

typedef struct
{
    ELEMENTO* cabeca;
} DEQUE;

void inicializar(DEQUE* deque);

void inseririnicio(DEQUE* deque, ALUNO aluno);

void inserirfim(DEQUE* deque, ALUNO aluno);

void excluirinicio(DEQUE* deque);

void excluirfim(DEQUE* deque);

void atualizapos(DEQUE* deque);

void exibirdireta(DEQUE* deque, int posicao);

void exibirinversa(DEQUE *deque, int posicao);


#endif // DEQUE_H_INCLUDED
