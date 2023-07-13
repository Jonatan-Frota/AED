#include <stdio.h>
#include <stdlib.h>
#include "hashdisp.h"
#define MAX 20

int main()
{
    TBHASH tabela;
    VALOR valor;
    inicializar(tabela);
    valor.inteiro = 365;
    inserir(tabela, valor);
    valor.inteiro = 112;
    inserir(tabela, valor);
    valor.inteiro = 180;
    inserir(tabela, valor);
    valor.inteiro = 213;
    inserir(tabela, valor);
    valor.inteiro = 13;
    inserir(tabela, valor);
    valor.inteiro = 27;
    inserir(tabela, valor);
    exibir(tabela);

    return 0;
}
