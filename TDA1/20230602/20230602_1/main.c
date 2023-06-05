#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int matricula;
    char nome[50];
    int idade;
} ALUNO;

typedef struct {
    ALUNO alun;
    int proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO turma[100];
    int inicio;
    int disponivel;
} LISTA;

int main(){
    LISTA minhaturma;
    ALUNO b;
    inicializar(&minhaturma);
int x;

    while (true) {
        printf("\nDIGITE PARA:\n");
        printf("[1] Inicializar a lista de turma\n");
        printf("[2] Limpar turma\n");
        printf("[3] Quantidade de alunos\n");
        printf("[4] Turma cheia?\n");
        printf("[5] Turma vazia?\n");
        printf("[6] Exibir alunos\n");
        printf("[7] Inserir um novo aluno\n");
        printf("[8] Excluir um aluno\n");
        printf("[9] Alterar matricula\n");
        printf("[-1] Para finalizar\n");
        scanf("%d", &x);

if (x == -1) {
break;
    }

    switch (x) {
case 1:
    inicializar(&minhaturma);
    printf("\nLista inicializada.\n");
        break;
case 2:
    liberar(&minhaturma);
    printf("\nLista liberada.\n");
            break;
case 3:
    printf("\nQuantidade de alunos na turma: %d\n", quantidade(&minhaturma));
            break;
case 4:
    printf("A turma esta cheia? %s\n", cheia(&minhaturma) ? "Sim" : "Nao.");
            break;
case 5:
    printf("A turma esta vazia? %s\n", vazia(&minhaturma) ? "Sim" : "Nao.");
            break;
case 6:
    exibir(&minhaturma);
            break;
case 7:
    printf("Insira o nome do aluno: ");
    scanf("%s", b.nome);
    printf("Insira a idade do aluno: ");
    scanf("%d", &b.idade);
    printf("Insira a matricula do aluno: ");
    scanf("%d", &b.matricula);

    if (inserir(&minhaturma, b)) {
            printf("Aluno inserido com sucesso na lista.\n");
        }


else {
printf("Falha ao inserir aluno na lista. Verifique se a lista está cheia ou se a matrícula já existe.\n");}

            break;
case 8:
        printf("Insira a matricula do aluno a ser excluído: ");
        int eliminar;
        scanf("%d", &eliminar);
        if (excluir(&minhaturma, eliminar)) {
                printf("Aluno com matricula %d excluido da turma.\n", eliminar);
            }
            else {
                printf("Matricula nao encontrada. Verifique se a matricula existe.\n");
                }
            break;

case 9:
        printf("Insira a matricula do aluno a ter o valor alterado: ");
        int matriculaAntiga;
        scanf("%d", &matriculaAntiga);

                printf("Insira a nova matricula: ");
                int novaMatricula;
                scanf("%d", &novaMatricula);

                if (altMat(&minhaturma, matriculaAntiga, novaMatricula)) {
                    printf("\nMatricula do aluno alterada com sucesso.\n");
                } else {
                    printf("\nMatricula nao encontrada! Tente novamente.\n");
                }
                break;
            default:
                printf("Erro. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
