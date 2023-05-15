#include <stdio.h>
#include <stdlib.h>
typedef struct{
char data[20];

}DATA;

void inserir(DATA *usuario){
printf("Insira uma data: ");
fgets(usuario -> data, 20, stdin);

}
void printar(DATA *usuario){
printf("\nData inserida: %s", usuario -> data);
}

int main()
{
    DATA *usuario;
    usuario = (DATA*) malloc(sizeof(DATA));
    inserir(usuario);
    printar(usuario);
    free(usuario);

    return 0;
}
