#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* lista;
int tamanho_inicial;
int quantidade_elementos_atual;

void criar_lista(int tamanho) {
    tamanho_inicial = tamanho;
    lista = (int*) malloc(tamanho_inicial * sizeof(int));
    if (lista == NULL) {
        printf("Erro na alocacao de memoria.");
        exit(1);
    }
    quantidade_elementos_atual = 0;
    printf("Lista criada com sucesso com capacidade de armazenar %d elementos do tipo int.\n", tamanho_inicial);
}

void verificar_vazia() {
    printf(quantidade_elementos_atual == 0 ? "A lista esta vazia.\n" : "A lista nao esta vazia.\n");
}

void verificar_cheia() {
    printf(quantidade_elementos_atual == tamanho_inicial ? "A lista esta cheia.\n" : "A lista nao esta cheia.\n");
}

void obter_tamanho() {
    printf("O tamanho atual da lista e: %d e ainda comporta %d elementos, capacidade maxima: %d\n", quantidade_elementos_atual, tamanho_inicial - quantidade_elementos_atual, tamanho_inicial);
}

void obter_modificar(int posicao, char *opcao) {
    if (posicao < 1 || posicao > quantidade_elementos_atual) {
        printf("Posicao invalida.\n");
        return;
    }
    int index = posicao - 1;

    if (strcmp(opcao, "obter") == 0) {
        printf("Valor na posicao %d: %d\n", posicao, lista[index]);
    } else if (strcmp(opcao, "modificar") == 0) {
        int novo_valor;
        printf("Digite o novo valor: ");
        scanf("%d", &novo_valor);
        lista[index] = novo_valor;
        printf("Modificado com exito.\n");
    } else {
        printf("Opcao invalida.\n");
    }
}

void inserir_elemento(int posicao, int valor) {
    if (quantidade_elementos_atual == tamanho_inicial || posicao < 1 || posicao > quantidade_elementos_atual + 1) {
        printf("Posicao invalida ou lista cheia.\n");
        return;
    }
    for (int i = quantidade_elementos_atual; i >= posicao; i--) {
        lista[i] = lista[i - 1];
    }
    lista[posicao - 1] = valor;
    quantidade_elementos_atual++;
    printf("Elemento %d inserido na posicao %d.\n", valor, posicao);
}

void remover_elemento(int posicao) {
    if (posicao < 1 || posicao > quantidade_elementos_atual) {
        printf("Posicao invalida.\n");
        return;
    }
    for (int i = posicao - 1; i < quantidade_elementos_atual - 1; i++) {
        lista[i] = lista[i + 1];
    }
    quantidade_elementos_atual--;
    printf("Elemento da posicao %d removido.\n", posicao);
}

int main() {
    int opcao, pos, valor;
    char comando[10];

    do {
        printf("\nMenu:\n");
        printf("1. Criar lista\n2. Verificar se esta vazia\n3. Verificar se esta cheia\n4. Obter tamanho\n5. Obter ou modificar elemento\n6. Inserir elemento\n7. Remover elemento\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o tamanho inicial: ");
                scanf("%d", &valor);
                criar_lista(valor);
                break;
            case 2:
                verificar_vazia();
                break;
            case 3:
                verificar_cheia();
                break;
            case 4:
                obter_tamanho();
                break;
            case 5:
                printf("Digite a posicao e 'obter' ou 'modificar': ");
                scanf("%d %s", &pos, comando);
                obter_modificar(pos, comando);
                break;
            case 6:
                printf("Digite a posicao e o valor: ");
                scanf("%d %d", &pos, &valor);
                inserir_elemento(pos, valor);
                break;
            case 7:
                printf("Digite a posicao para remover: ");
                scanf("%d", &pos);
                remover_elemento(pos);
                break;
            case 0:
                printf("Encerrando...\n");
                free(lista);
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}


