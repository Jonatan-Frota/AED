#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


typedef struct {
    int dado;
    int prox;
} No;

typedef struct {
    No nos[100];
    int inicio;
    int disponivel;
} LISTA;

void inicializar(LISTA* lista);
int inserir(LISTA* lista, int valor);
void imprimir(LISTA* lista);
void l1a(LISTA* lista);
void l2a(LISTA* lista);

#endif // LISTA_H_INCLUDED
