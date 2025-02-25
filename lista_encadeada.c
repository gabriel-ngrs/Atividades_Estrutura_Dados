#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* cabeca;
    int tamanho;
} ListaEncadeada;

ListaEncadeada* criar_lista() {
    ListaEncadeada* lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    if (lista == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    lista->cabeca = NULL;
    lista->tamanho = 0;
    return lista;
}

int esta_vazia(ListaEncadeada* lista) {
    return lista->tamanho == 0;
}

int obter_tamanho(ListaEncadeada* lista) {
    return lista->tamanho;
}

void imprimir_lista(ListaEncadeada* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int obter_elemento(ListaEncadeada* lista, int pos) {
    if (pos < 1 || pos > lista->tamanho) {
        printf("Posicao invalida!\n");
        return -1;
    }
    No* atual = lista->cabeca;
    for (int i = 1; i < pos; i++) {
        atual = atual->prox;
    }
    return atual->dado;
}

void modificar_elemento(ListaEncadeada* lista, int pos, int novo_valor) {
    if (pos < 1 || pos > lista->tamanho) {
        printf("Posicao invalida!\n");
        return;
    }
    No* atual = lista->cabeca;
    for (int i = 1; i < pos; i++) {
        atual = atual->prox;
    }
    atual->dado = novo_valor;
}

void inserir_elemento(ListaEncadeada* lista, int pos, int valor) {
    if (pos < 1 || pos > lista->tamanho + 1) {
        printf("Posicao invalida!\n");
        return;
    }
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    novo->dado = valor;
    if (pos == 1) {
        novo->prox = lista->cabeca;
        lista->cabeca = novo;
    } else {
        No* atual = lista->cabeca;
        for (int i = 1; i < pos - 1; i++) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
    lista->tamanho++;
}

void remover_elemento(ListaEncadeada* lista, int pos) {
    if (pos < 1 || pos > lista->tamanho) {
        printf("Posicao invalida!\n");
        return;
    }
    No* removido;
    if (pos == 1) {
        removido = lista->cabeca;
        lista->cabeca = lista->cabeca->prox;
    } else {
        No* atual = lista->cabeca;
        for (int i = 1; i < pos - 1; i++) {
            atual = atual->prox;
        }
        removido = atual->prox;
        atual->prox = removido->prox;
    }
    free(removido);
    lista->tamanho--;
}

int main() {
    ListaEncadeada* lista = criar_lista();
    inserir_elemento(lista, 1, 10);
    inserir_elemento(lista, 2, 20);
    inserir_elemento(lista, 3, 30);
    imprimir_lista(lista);
    remover_elemento(lista, 2);
    imprimir_lista(lista);
    modificar_elemento(lista, 2, 50);
    imprimir_lista(lista);
    printf("Elemento na posicao 1: %d\n", obter_elemento(lista, 1));
    free(lista);
    return 0;
}
