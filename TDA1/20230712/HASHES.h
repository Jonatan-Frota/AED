#ifndef HASHES_H_INCLUDED
#define HASHES_H_INCLUDED
#define MAX 9

typedef struct{
int valor;
}INTEIRO;

typedef struct aux{
INTEIRO inteiro;
struct aux* proximo;
}ELEMENTO;

typedef ELEMENTO* TBHASH[MAX];

void inicializar(TBHASH tabela);

int dispersar(int chave);

void exibir(TBHASH tabela);

void inserir(TBHASH tabela, INTEIRO novo);

#endif // HASHES_H_INCLUDED
