#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#define MAX 10
typedef struct {
    char nome[50];
    char cpf[15];
    int idade;
    int codigo;
    int flag;
} PACIENTE;

typedef PACIENTE *TABELAH[MAX];

void inicializar(TABELAH tabela);

int dispersar(int chave);

int inserir(TABELAH tabela, PACIENTE novo);

void excluir(TABELAH tab, int codigo);

void mostrartab(TABELAH tab);

#endif // HASH_H_INCLUDED
