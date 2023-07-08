#ifndef HASHI_H_INCLUDED
#define HASHI_H_INCLUDED
#define MAX 10

typedef struct {
    char nome[50];
    char cpf[15];
    int idade;
    int codigo;
} PACIENTE;

typedef PACIENTE *TABELAH[MAX];

void inicializar(TABELAH tabela);

int inserir(TABELAH tabela, PACIENTE novo);

void mostrartab(TABELAH tab);


#endif // HASHI_H_INCLUDED
