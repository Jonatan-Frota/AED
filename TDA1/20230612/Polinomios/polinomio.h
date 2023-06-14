#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

typedef struct POLINOMIO {
    int coef;
    int exp;
    struct POLINOMIO *proximo;
} POLINOMIO;

typedef struct {
    POLINOMIO *inicio;
    int tam;
} LISTA;

void inserir(LISTA *lista, int grau);

void exibir(LISTA *lista);

LISTA* somarp(LISTA *polinomio1, LISTA *polinomio2);



#endif // POLINOMIO_H_INCLUDED
