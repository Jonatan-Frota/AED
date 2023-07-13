#include <stdio.h>
#include <stdlib.h>
#include "hashdisp.h"
#define MAX 20

void inicializar(TBHASH tabela){
int i;
for(i = 0; i < MAX; i++){
    tabela[i] = NULL;
}}

int dispersar(int chave){

return(chave%MAX);

}

int sondageml(int chave, int posicao){
return(chave+posicao)%MAX;
}

int sondagemquad1(int chave, int posicao){
int j;
j = (chave +(posicao*posicao))%11;
return(j);
}

int sondagemquad2(int chave, int posicao){
int j;
j = (chave + 2*chave + (posicao * posicao))%11;
return (j);
}

int hash2(int chave){
int j;
j = 7 - (chave%7);
return(j);
}

void inserir(TBHASH tab, VALOR valor){
int h = dispersar(valor.inteiro);
if(tab[h] == NULL){
tab[h] = malloc(sizeof(VALOR));
*(tab[h]) = valor;
}
else{
//h = sondageml(valor.inteiro, h);
//h = sondagemquad1(valor.inteiro, h);
//h = sondagemquad2(valor.inteiro, h);
h = hash2(valor.inteiro);
tab[h] = malloc(sizeof(VALOR));
*(tab[h]) = valor;
}}

void exibir(TBHASH tabela){
int i;
for(i = 0; i < MAX; i++){
    if(tabela[i] != NULL){
        printf("\nValor: %d", tabela[i]->inteiro);
    }
    else{
        printf("\nValor: NULL");
    }
}
}
