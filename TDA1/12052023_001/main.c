#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

int main()
{
    CUBO *lados;
    lados = (CUBO*) malloc(sizeof(CUBO));
    inserir(lados);
    printar(lados);
    free(lados);
    return 0;
}
