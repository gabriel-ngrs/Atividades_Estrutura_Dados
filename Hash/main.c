#include <stdio.h>
#include "hash.h"

int main() {
    TabelaHash* tabela = criarTabela(100);

    inserir(tabela, "João");
    inserir(tabela, "Marco");
    inserir(tabela, "Marina");
    inserir(tabela, "Julia");
    inserir(tabela, "Antônio");
    inserir(tabela, "José");

    char busca[] = "Marina";
    Objeto* resultado = buscar(tabela, busca);
    if (resultado != NULL)
        printf("Encontrado: %s\n", resultado->chave);
    else
        printf("Não encontrado.\n");

    return 0;
}