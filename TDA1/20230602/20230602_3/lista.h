#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef struct No {
    int dado;
    struct No* prox;
} No;

void inserir(No** inicio, int dado);
void exibir(No* inicio);

#endif // LISTA_H_INCLUDED
