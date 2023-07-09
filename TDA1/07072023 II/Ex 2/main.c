#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HASHIII.h"
#define MAX 10

int main()
{
    TBHASH tabela;
    PACIENTE p;
    inicializar(tabela);

    p.codigo = 1291;
    strcpy(p.nome, "Jorge");
    strcpy(p.cpf, "458.647.992-28");
    p.idade = 15;
    inserir(tabela, p);

    p.codigo = 1391;
    strcpy(p.nome, "Rebeca");
    strcpy(p.cpf, "798.657.696-21");
    p.idade = 18;
    inserir(tabela, p);

    p.codigo = 1593;
    strcpy(p.nome, "Leticia");
    strcpy(p.cpf, "498.667.796-22");
    p.idade = 25;
    inserir(tabela, p);

    p.codigo = 1993;
    strcpy(p.nome, "Mariana");
    strcpy(p.cpf, "598.666.986-20");
    p.idade = 23;
    inserir(tabela, p);

    p.codigo = 1998;
    strcpy(p.nome, "Joao");
    strcpy(p.cpf, "573.778.078-30");
    p.idade = 27;
    inserir(tabela, p);

    p.codigo = 1888;
    strcpy(p.nome, "Eduarda");
    strcpy(p.cpf, "174.758.958-60");
    p.idade = 35;
    inserir(tabela, p);

    p.codigo = 1285;
    strcpy(p.nome, "Arnaldo");
    strcpy(p.cpf, "272.454.338-67");
    p.idade = 35;
    inserir(tabela, p);
    mostrartab(tabela);
//Excluir:
printf("\n\nJoao sera excluido.\n");
    excluir(tabela, 1998);
printf("\n\nTabela atualizada:\n");
    mostrartab(tabela);
    return 0;
}
