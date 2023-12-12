/*Crie um programa em C para gerenciar um catálogo de produtos. Cada produto deve ter um nome (string), um código (inteiro), uma descrição (string) e um preço(float). O programa deve permitir ao usuário adicionar produtos ao catálogo e exibir todos os produtos cadastrados. Utilize alocação dinâmica para armazenar os produtos e permita que o usuário insira a quantidade desejada de produtos. Ao final,o programa deve liberar a memória alocada.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct catalogo {
    char nome[50];
    int codigo;
    char descricao[100];
    float preco;
};

int main() {
    int i, numprodutos;

    printf("\nDigite o numero de produtos: ");
    scanf("%i", &numprodutos);

    struct catalogo *c = (struct catalogo *)malloc(numprodutos * sizeof(struct catalogo));

    printf("\n======Cadastro dos produtos======\n");

    for (i = 0; i < numprodutos; i++) {
        printf("Nome do Produto: ");
        fflush(stdin);
        gets(c[i].nome);    
         
        printf("Codigo do Produto: ");
        scanf("%i", &c[i].codigo);

        printf("Descricao do Produto: ");
        fflush(stdin);
        gets(c[i].descricao);       

        printf("Preco do Produto: ");
        scanf("%f", &c[i].preco);

        printf("\n");

    }

    printf("\n======Produtos Cadastrados======\n");

    for (i = 0; i < numprodutos; i++) {
        printf("\nNome: %s ", c[i].nome);
        printf("\nCodigo: %.2i ", c[i].codigo);
        printf("\nDescricao: %s ", c[i].descricao);
        printf("\nPreco: %.2f ", c[i].preco);

        printf("\n\n");
    }

    free(c);

    return 0;
}
