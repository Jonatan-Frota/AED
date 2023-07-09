#ifndef HASHII_H_INCLUDED
#define HASHII_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
char nome[50];
char cpf[15];
int codigo;
int idade;
}PACIENTE;

typedef struct aux{
    PACIENTE pac;
    struct aux* proximo;

}ELEMENTO;

typedef ELEMENTO* TBHASH[MAX];


void inicializar(TBHASH tabela);
int inserir(TBHASH tabela, PACIENTE novo);
void mostrartab(TBHASH tabela);
void excluir(TBHASH tabela, int codigo);

#endif // HASHII_H_INCLUDED
