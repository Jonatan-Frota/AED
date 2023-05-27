#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

void NovaLista(int* lista1, int tam);
void imprimir(int* lista1, int tam);
void buscar(int* lista1, int tam, int busca);
void maiorit(int* lista1, int tam);
int maiorec(int* lista1, int tam, int maior, int i);
void menorit(int* lista1, int tam);
int menorec(int* lista1, int tam, int menor, int i);
int somait(int* lista1, int tam);
int somarec(int* lista1, int tam, int i, int soma);
int multit(int* lista1, int tam);
int multrec(int* lista1, int tam, int i);
void NovaListaOrd(int* lista2, int tam);
void printrec(int *lista2, int tam, int i);
void bbit(int* lista2, int tam, int busca, int cont);
void bbrec(int* lista2, int tam, int busca, int inicio, int fim, int metade, int cont);

#endif // LISTA_H_INCLUDED
