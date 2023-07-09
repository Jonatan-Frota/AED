#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    char nome[50];
    char cpf[15];
    int idade;
    int codigo;
    int flag;
} PACIENTE;

typedef PACIENTE *TABELAH[MAX];
void inicializar(TABELAH tabela) {
    int i;
    for (i = 0; i < MAX; i++) {
        tabela[i] = NULL;
    }
}

int dispersar(int chave) {
    int h;
    h = (chave % MAX);
    return h;
}

int inserir(TABELAH tabela, PACIENTE novo) {
    int h;
    h = dispersar(novo.codigo);
    while (tabela[h] != NULL) {
        if (tabela[h]->codigo == novo.codigo) {
            if (tabela[h]->flag == 0) {
                *tabela[h] = novo;
                tabela[h]->flag = 1;
                printf("\nPaciente substituido com sucesso!\n");
                return 1;
            } else {
                printf("\nPaciente ja inserido!\n");
                return 0;
            }
        }
        h = (h + 1) % MAX;
    }
    if (tabela[h] == NULL || tabela[h]->flag == 0) {
        tabela[h] = malloc(sizeof(PACIENTE));
        if (tabela[h] == NULL) {
            printf("\nFalha ao alocar memoria!\n");
            return 0;
        }
        *tabela[h] = novo;
        tabela[h]->flag = 1; // Marca o paciente como não excluído
        return 1;
    }
    return 0;
}

void excluir(TABELAH tab, int codigo) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tab[i] != NULL && tab[i]->codigo == codigo) {
            tab[i]->flag = 0; // Marca o paciente como excluído
            printf("\nPaciente excluido com sucesso!\n");
            return;
        }
    }
    printf("\nPaciente nao encontrado!\n");
}


void mostrartab(TABELAH tab) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tab[i] != NULL) {
            printf("\nNome: %s\n", tab[i]->nome);
            printf("Idade: %d\n", tab[i]->idade);
            printf("CPF: %s\n", tab[i]->cpf);
            printf("Codigo: %d\n", tab[i]->codigo);
        }
    }
}




int main() {
    TABELAH tabela;
    PACIENTE p;
    inicializar(tabela);

// Paciente 1:
    strcpy(p.nome, "Matheus ");
    strcpy(p.cpf, "062.457.687-25");
    p.idade = 15;
    p.codigo = 1245;
    p.flag = 1;
    inserir(tabela, p);

// Paciente 2:
    strcpy(p.nome, "Gustavo ");
    strcpy(p.cpf, "145.879.568-29");
    p.idade = 27;
    p.codigo = 1249;
    p.flag = 1;
    inserir(tabela, p);

 //Paciente 3:
    strcpy(p.nome, "Kaio ");
    strcpy(p.cpf, "185.879.728-29");
    p.idade = 21;
    p.codigo = 5241;
    p.flag = 1;
    inserir(tabela, p);

//Paciente 4:
    strcpy(p.nome, "Frank ");
    strcpy(p.cpf, "395.199.558-21");
    p.idade = 29;
    p.codigo = 2243;
    p.flag = 1;
    inserir(tabela, p);

//Paciente 5:
    strcpy(p.nome, "Jonatan ");
    strcpy(p.cpf, "062.973.602-27");
    p.idade = 20;
    p.codigo = 2002;
    p.flag = 1;
    inserir(tabela, p);
    mostrartab(tabela);
// Excluir:
    printf("\n\nPaciente Frank sera excluido e substituido");
    excluir(tabela, 2243);
//Inserir outro paciente no lugar:
    strcpy(p.nome, "Bill ");
    strcpy(p.cpf, "395.199.558-21");
    p.idade = 21;
    p.codigo = 2243;
    inserir(tabela, p);
    mostrartab(tabela);
    return 0;
}

