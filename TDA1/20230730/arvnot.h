#ifndef ARVNOT_H_INCLUDED
#define ARVNOT_H_INCLUDED
struct No {
    char valor;
    struct No* esquerda;
    struct No* direita;
};

struct No* criarNo(char valor);

struct No* inserir(struct No* raiz, char valor);

struct No* inserirExpressao(struct No* raiz, const char* expressao, int* indice);

void imprimirInfixa(struct No* raiz, bool parenteses);

void imprimirPosfixa(struct No* raiz);

void imprimirPrefixa(struct No* raiz);

int avaliarExpressao(struct No* raiz);


#endif // ARVNOT_H_INCLUDED
