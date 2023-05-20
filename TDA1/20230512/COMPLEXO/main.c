#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

int main()
{
    NUMERO *numero1;
    NUMERO *numero2;
    numero1 = (NUMERO*) malloc(sizeof(NUMERO));
    numero2 = (NUMERO*) malloc(sizeof(NUMERO));
    inserir(numero1, numero2);
    soma(numero1, numero2);
    sub(numero1, numero2);
    mult(numero1, numero2);
    divisao(numero1, numero2);
    liberar(numero1, numero2);
    return 0;
}
