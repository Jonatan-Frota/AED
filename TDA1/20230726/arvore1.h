#ifndef ARVORE1_H_INCLUDED
#define ARVORE1_H_INCLUDED

typedef struct{
int valor;
}INTEIRO;

typedef struct aux{
INTEIRO num;
struct aux* direita;
struct aux* esquerda;
}ELEMENTO;

typedef struct{
ELEMENTO* raiz;
}ARVORE;

// Inicializar arvore:
void inicializar(ARVORE* arvore);

// Inserir:
ELEMENTO* inserirop(ELEMENTO* raiz, ELEMENTO* novo);
//
void inserir(ARVORE* arvore, ELEMENTO* novo);
// Função para exibir:
void exibir(ARVORE* arvore, int ordem);
// Percorrer Pré-ordem:
void preOrdem(ELEMENTO* raiz);

// Percorrer In-ordem:
void inOrdem(ELEMENTO* raiz);

// Percorrer Pós-ordem:
void posOrdem(ELEMENTO* raiz);

// Busca:
ELEMENTO* buscaop(ELEMENTO*raiz, int valor);



#endif // ARVORE1_H_INCLUDED
