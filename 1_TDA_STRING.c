#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, a, b = 0;
    char frase[50];
    char letra;
    printf("Insira a frase: ");
    fgets(frase, 50, stdin);
    printf("\nInsira a letra que voce gostaria de verificar: ");
    scanf(" %c", &letra);
    a = strlen(frase);
    for(i = 0; i < a; i++){
   if(frase[i] == letra){
    b += 1;
   }

    }
    if (b != 0){
        printf("\nSim!");
    }
    else{
        printf("\nNao!");
    }

    return 0;
}
