#ifndef HANGAR_H_INCLUDED
#define HANGAR_H_INCLUDED

typedef struct{
char nome[50];
int ident;
}AVIAO;

typedef struct{
AVIAO hangar[20];
int qnt;
}PILHA;

void inicializar(PILHA *pilha);

void inserir(PILHA *pilha);

void exibir(PILHA *pilha);

void excluir(PILHA *pilha);

void primeiro(PILHA *pilha);


void excluirpos(PILHA *pilha);


#endif // HANGAR_H_INCLUDED
