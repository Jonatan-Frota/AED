#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HASH.h"
#define MAX 10


int main() {
    TABELAH tabela;
    PACIENTE p;
    inicializar(tabela);

// Paciente 1:
    strcpy(p.nome, "Matheus ");
    strcpy(p.cpf, "062.457.687-25");
    p.idade = 15;
    p.codigo = 1245;
    p.flag = 1;
    inserir(tabela, p);

// Paciente 2:
    strcpy(p.nome, "Gustavo ");
    strcpy(p.cpf, "145.879.568-29");
    p.idade = 27;
    p.codigo = 1249;
    p.flag = 1;
    inserir(tabela, p);

 //Paciente 3:
    strcpy(p.nome, "Kaio ");
    strcpy(p.cpf, "185.879.728-29");
    p.idade = 21;
    p.codigo = 5241;
    p.flag = 1;
    inserir(tabela, p);

//Paciente 4:
    strcpy(p.nome, "Frank ");
    strcpy(p.cpf, "395.199.558-21");
    p.idade = 29;
    p.codigo = 2243;
    p.flag = 1;
    inserir(tabela, p);

//Paciente 5:
    strcpy(p.nome, "Jonatan ");
    strcpy(p.cpf, "062.973.602-27");
    p.idade = 20;
    p.codigo = 2002;
    p.flag = 1;
    inserir(tabela, p);
    mostrartab(tabela);
// Excluir:
    printf("\n\nPaciente Frank sera excluido e substituido");
    excluir(tabela, 2243);
//Inserir outro paciente no lugar:
    strcpy(p.nome, "Bill ");
    strcpy(p.cpf, "395.199.558-21");
    p.idade = 21;
    p.codigo = 2243;
    inserir(tabela, p);
    mostrartab(tabela);
    return 0;
}
