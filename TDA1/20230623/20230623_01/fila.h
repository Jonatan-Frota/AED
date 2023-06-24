#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct
{
    char nome[50];
    int ident;
    struct AVIAO* proximo;
} AVIAO;

typedef struct
{
    AVIAO* inicio;
    AVIAO* fim;
} FILA;

void inicializar(FILA* fila);

void inserir(FILA* fila, char modelo[50], int identificador);

void autorizar(FILA *fila);

void exibir(FILA *fila);

void primeiro(FILA *fila);


#endif // FILA_H_INCLUDED
