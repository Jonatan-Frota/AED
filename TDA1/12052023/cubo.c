#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>

void inserir(CUBO *lados){
printf("Insira o tamanho dos lados do cubo: ");
scanf("%f", &lados -> lado);
lados -> area = 6*((lados -> lado)*(lados-> lado));
lados -> volume = lados -> lado * lados-> lado * lados -> lado;
}


void printar(CUBO *lados){
printf("\nLados: %1.2f", lados-> lado);
printf("\nArea: %1.2f", lados-> area);
printf("\nVolume: %1.2f", lados-> volume);
}
