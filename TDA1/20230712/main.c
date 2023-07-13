#include <stdio.h>
#include <stdlib.h>
#include "HASHES.h"
#define MAX 9



int main()
{
    TBHASH tabela;
    INTEIRO numero;
    inicializar(tabela);
    numero.valor = 12;
    inserir(tabela, numero);
    numero.valor = 44;
    inserir(tabela, numero);
    numero.valor = 13;
    inserir(tabela, numero);
    numero.valor = 88;
    inserir(tabela, numero);
    numero.valor = 23;
    inserir(tabela, numero);
    numero.valor = 94;
    inserir(tabela, numero);
    numero.valor = 11;
    inserir(tabela, numero);
    numero.valor = 39;
    inserir(tabela, numero);
    numero.valor = 20;
    inserir(tabela, numero);
    numero.valor = 16;
    inserir(tabela, numero);
    numero.valor = 5;
    inserir(tabela, numero);
    exibir(tabela);
    return 0;
}
