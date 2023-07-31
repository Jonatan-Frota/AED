#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arvnot.h"

struct No* criarNo(char valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

struct No* inserir(struct No* raiz, char valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

struct No* inserirExpressao(struct No* raiz, const char* expressao, int* indice) {
    char token = expressao[*indice];

    // Ignorar espacos em branco
    while (token == ' ') {
        (*indice)++;
        token = expressao[*indice];
    }

    if (token == '\0') {
        return NULL;
    }

    // Se encontrarmos um parentese aberto, avancamos para o proximo caractere
    if (token == '(') {
        (*indice)++;
        token = expressao[*indice];
    }

    // Criamos um novo no para o token atual
    struct No* novoNo = criarNo(token);

    // Avancamos para o proximo caractere
    (*indice)++;

    // Verificamos se o proximo token e um operador
    if (expressao[*indice] == '+' || expressao[*indice] == '-' ||
        expressao[*indice] == '*' || expressao[*indice] == '/') {

        // Inserimos a subarvore esquerda com o proximo operador
        novoNo->esquerda = inserirExpressao(raiz, expressao, indice);

        // Avancamos para o proximo caractere apos o operador
        (*indice)++;
    }

    // Inserimos a subarvore direita com o proximo token
    novoNo->direita = inserirExpressao(raiz, expressao, indice);

    // Se encontrarmos um parentese fechado, avancamos para o proximo caractere
    if (expressao[*indice] == ')') {
        (*indice)++;
    }

    return novoNo;
}

void imprimirInfixa(struct No* raiz, bool parenteses) {
    if (raiz == NULL) {
        return;
    }

    if (parenteses && (raiz->esquerda != NULL || raiz->direita != NULL)) {
        printf("(");
    }

    imprimirInfixa(raiz->esquerda, true);
    printf("%c", raiz->valor);
    imprimirInfixa(raiz->direita, true);

    if (parenteses && (raiz->esquerda != NULL || raiz->direita != NULL)) {
        printf(")");
    }
}

void imprimirPosfixa(struct No* raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimirPosfixa(raiz->esquerda);
    imprimirPosfixa(raiz->direita);
    printf("%c", raiz->valor);
}

void imprimirPrefixa(struct No* raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("%c", raiz->valor);
    imprimirPrefixa(raiz->esquerda);
    imprimirPrefixa(raiz->direita);
}

int avaliarExpressao(struct No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->valor >= 'a' && raiz->valor <= 'z') {
        // Supondo que os valores das variaveis sejam os codigos ASCII
        return raiz->valor;
    }

    int valorEsquerda = avaliarExpressao(raiz->esquerda);
    int valorDireita = avaliarExpressao(raiz->direita);

    switch (raiz->valor) {
        case '+':
            return valorEsquerda + valorDireita;
        case '-':
            return valorEsquerda - valorDireita;
        case '*':
            return valorEsquerda * valorDireita;
        case '/':
            return valorEsquerda / valorDireita;
        default:
            return 0;
    }
}
