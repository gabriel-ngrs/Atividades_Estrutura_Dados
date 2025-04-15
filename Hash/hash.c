#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int hash1(char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
        soma += chave[i];
    return soma % TAM1;
}

int hash2(char* chave, int tam_n2) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
        soma += chave[i] * (i + 1);
    return soma % tam_n2;
}

TabelaHash* criarTabela(int n) {
    TabelaHash* th = malloc(sizeof(TabelaHash));
    for (int i = 0; i < TAM1; i++) {
        th->nivel1[i] = malloc(sizeof(TabelaNivel2));
        th->nivel1[i]->tam = n / TAM1;
        th->nivel1[i]->listas = malloc(sizeof(Lista) * th->nivel1[i]->tam);
        for (int j = 0; j < th->nivel1[i]->tam; j++)
            th->nivel1[i]->listas[j].inicio = NULL;
    }
    return th;
}

void inserir(TabelaHash* th, char* chave) {
    int i1 = hash1(chave);
    int i2 = hash2(chave, th->nivel1[i1]->tam);
    Objeto* novo = malloc(sizeof(Objeto));
    strcpy(novo->chave, chave);
    novo->prox = th->nivel1[i1]->listas[i2].inicio;
    th->nivel1[i1]->listas[i2].inicio = novo;
}

Objeto* buscar(TabelaHash* th, char* chave) {
    int i1 = hash1(chave);
    int i2 = hash2(chave, th->nivel1[i1]->tam);
    Objeto* atual = th->nivel1[i1]->listas[i2].inicio;
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}