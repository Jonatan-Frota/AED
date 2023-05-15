#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char nome[50];
char data[15];
char cpf[20];
}FORMULARIO;



void inserir(FORMULARIO *usuario){
strcpy(usuario -> nome, "Jonatan Frota");
strcpy(usuario -> data, "18/07/2003");
strcpy(usuario -> cpf, "062.973.602-27");
}

void printar(FORMULARIO *usuario){
printf("Nome: %s", usuario -> nome);
printf("\nData: %s", usuario -> data);
printf("\nCPF: %s", usuario -> cpf);


}


int main()
{
FORMULARIO *usuario;
usuario = (FORMULARIO *) malloc(sizeof(FORMULARIO));
inserir(usuario);
printar(usuario);
free(usuario);
}
