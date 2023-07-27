#include <stdio.h>
#include <stdlib.h>
#include "arvore1.h"

// Inicializar arvore:
void inicializar(ARVORE* arvore){
arvore->raiz = NULL;
}

// Inserir:
ELEMENTO* inserirop(ELEMENTO* raiz, ELEMENTO* novo){
if(raiz == NULL){
    return (novo);
}
if(raiz->num.valor>novo->num.valor){
    raiz->esquerda = inserirop(raiz->esquerda, novo);
}
else{
    raiz->direita = inserirop(raiz->direita, novo);
}
return(raiz);
}
//
void inserir(ARVORE* arvore, ELEMENTO* novo){
arvore->raiz = inserirop(arvore->raiz, novo);
return;
}

// Função para exibir:
void exibir(ARVORE* arvore, int ordem) {
    switch (ordem) {
        case 1:
            printf("Pre-ordem: ");
            preOrdem(arvore->raiz);
            break;
        case 2:
            printf("In-ordem: ");
            inOrdem(arvore->raiz);
            break;
        case 3:
            printf("Pos-ordem: ");
            posOrdem(arvore->raiz);
            break;
        default:
            printf("Opcao invalida.\n");
    }
    printf("\n");
}
// Percorrer Pré-ordem:
void preOrdem(ELEMENTO* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->num.valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Percorrer In-ordem:
void inOrdem(ELEMENTO* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerda);
        printf("%d ", raiz->num.valor);
        inOrdem(raiz->direita);
    }
}

// Percorrer Pós-ordem:
void posOrdem(ELEMENTO* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->num.valor);
    }
}


// Busca:
ELEMENTO* buscaop(ELEMENTO*raiz, int valor){
if (raiz == NULL || raiz->num.valor == valor) {
    return raiz;
}
if(raiz->num.valor > valor){
    return(buscaop(raiz->esquerda, valor));
}else{
    return(buscaop(raiz->direita, valor));
}}
//
ELEMENTO* busca(ARVORE* arvore, int valor){
return (buscaop(arvore->raiz, valor));
}
