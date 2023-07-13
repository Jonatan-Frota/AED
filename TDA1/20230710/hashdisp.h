#ifndef HASHDISP_H_INCLUDED
#define HASHDISP_H_INCLUDED
#define MAX 20

typedef struct{
int inteiro;
}VALOR;
typedef VALOR* TBHASH[MAX];


void inicializar(TBHASH tabela);

int dispersar(int chave);

int sondageml(int chave, int posicao);

int sondagemquad1(int chave, int posicao);

int sondagemquad2(int chave, int posicao);

int hash2(int chave);

void inserir(TBHASH tab, VALOR valor);

void exibir(TBHASH tabela);


#endif // HASHDISP_H_INCLUDED
