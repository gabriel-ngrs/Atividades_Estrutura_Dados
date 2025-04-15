#ifndef HASH_H
#define HASH_H

#define TAM1 10
#define MAX_STR 50

typedef struct Objeto {
    char chave[MAX_STR];
    struct Objeto* prox;
} Objeto;

typedef struct Lista {
    Objeto* inicio;
} Lista;

typedef struct TabelaNivel2 {
    int tam;
    Lista* listas;
} TabelaNivel2;

typedef struct TabelaHash {
    TabelaNivel2* nivel1[TAM1];
} TabelaHash;

TabelaHash* criarTabela(int n);
void inserir(TabelaHash* th, char* chave);
Objeto* buscar(TabelaHash* th, char* chave);

#endif