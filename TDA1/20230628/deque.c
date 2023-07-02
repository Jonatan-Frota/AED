#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

void inicializar(DEQUE* deque)
{
    deque->cabeca = malloc(sizeof(ELEMENTO));
    deque->cabeca->anterior = deque->cabeca;
    deque->cabeca->proximo = deque->cabeca;
}

void inseririnicio(DEQUE* deque, ALUNO aluno)
{
    ELEMENTO* novo = malloc(sizeof(ELEMENTO));
    if (novo == NULL)
    {
        printf("\nErro: falha na alocação de memória.\n");
        return;
    }
    novo->alun = aluno;
    novo->proximo = deque->cabeca->proximo;
    novo->anterior = deque->cabeca;
    deque->cabeca->proximo->anterior = novo;
    deque->cabeca->proximo = novo;
    atualizapos(deque);
}

void inserirfim(DEQUE* deque, ALUNO aluno)
{
    ELEMENTO* novo = malloc(sizeof(ELEMENTO));
    if (novo == NULL)
    {
        printf("\nErro: falha na alocação de memória.\n");
        return;
    }
    novo->alun = aluno;
    novo->proximo = deque->cabeca;
    novo->anterior = deque->cabeca->anterior;
    deque->cabeca->anterior->proximo = novo;
    deque->cabeca->anterior = novo;
    atualizapos(deque);
}

void excluirinicio(DEQUE* deque)
{
    if (deque->cabeca->proximo == deque->cabeca)
    {
        printf("\nNao ha alunos na lista!\n");
        return;
    }
    ELEMENTO* aux = deque->cabeca->proximo;
    deque->cabeca->proximo = aux->proximo;
    aux->proximo->anterior = deque->cabeca;
    free(aux);
    atualizapos(deque);
    printf("\nAluno excluido com sucesso!\n");
}

void excluirfim(DEQUE* deque)
{
    if (deque->cabeca->proximo == deque->cabeca)
    {
        printf("\nNao ha alunos na lista!\n");
        return;
    }
    ELEMENTO* aux = deque->cabeca->anterior;
    aux->anterior->proximo = deque->cabeca;
    deque->cabeca->anterior = aux->anterior;
    free(aux);
    atualizapos(deque);
    printf("\nAluno excluido com sucesso!\n");
}

void atualizapos(DEQUE* deque)
{
    ELEMENTO* aux = deque->cabeca->proximo;
    int i = 1;
    while (aux != deque->cabeca)
    {
        aux->alun.posicao = i;
        aux = aux->proximo;
        i++;
    }
}

void exibirdireta(DEQUE* deque, int posicao)
{
    ELEMENTO* aux = deque->cabeca->proximo;
    printf("\nExibicao em ordem direta:\n\n");
    while (aux != deque->cabeca)
    {
        if(aux->alun.posicao >= posicao)
        {
            printf("Nome: %s -> Posicao: %d\n", aux->alun.nome, aux->alun.posicao);
        }
        aux = aux->proximo;
    }
}

void exibirinversa(DEQUE *deque, int posicao)
{
    ELEMENTO* aux = deque->cabeca->anterior;
    printf("\nExibicao em ordem direta:\n\n");
    while (aux != deque->cabeca)
    {
        if(aux->alun.posicao <= posicao)
        {
            printf("Nome: %s -> Posicao: %d\n", aux->alun.nome, aux->alun.posicao);
        }
        aux = aux->anterior;
    }
}
