/*Um órgão governamental responsável pelo combate aotrabalho infantil precisa de um programa para gerenciar os dados de crianças e adolescentes que trabalham. O programa deve permitir as seguintes operações:

 Leitura dos dados: O programa deve ler os dados de um arquivo TXT ou struct que contémas seguintes informações sobre cada criança ou adolescente:
 Nome
 Idade
 Sexo
 Endereço
 Ocupação

 Exibição dos dados de todas as crianças e adolescentes: O programa deve exibir os dados detodas as crianças e adolescentes, com suas respectivas informações.

 Ordenação dos dados por idade: O programa deve ordenar os dados por idade, em ordemcrescente.

Exemplo de saída:
**Dados de todas as crianças e adolescentes:**
Nome | Idade | Sexo | Endereço | Ocupação
------- |---------|--------|------------- |----------------|--------------
João | 12 | Masculino | Rua das Flores, 123 | Garçom
Maria| 13 | Feminino | Rua da Alegria, 456 | Vendedora...

Dicas:
 Para armazenar os dados das crianças e adolescentes, você pode utilizar um vetor deponteiros para estruturas de dados.
 Para ler os dados do arquivo TXT, você pode utilizar a função fscanf().
 Para ordenar os dados por idade, você pode utilizar um algoritmo de ordenação simples,como Bubble Sort, InsertSort ou o Selection Sort.*/
#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
    char nome[50];
    int idade;
    char sexo[10];
    char endereco[100];
    char ocupacao[50];
};

int main()
{
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int numLinhas;
    fscanf(arquivo, "%d", &numLinhas);

    struct Pessoa *pessoas = malloc(numLinhas * sizeof(struct Pessoa));

    for (int i = 0; i < numLinhas; i++)
    {
        fscanf(arquivo, "%s %d %s %s %s",
               pessoas[i].nome, &pessoas[i].idade, pessoas[i].sexo,
               pessoas[i].endereco, pessoas[i].ocupacao);
    }

    printf("**Dados de todas as crianças e adolescentes:**\n");
    printf("Nome | Idade | Sexo | Endereço | Ocupação\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < numLinhas; i++)
    {
        printf("%s | %d | %s | %s | %s\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo,
               pessoas[i].endereco, pessoas[i].ocupacao);
    }

    for (int i = 0; i < numLinhas - 1; i++)
    {
        for (int j = 0; j < numLinhas - i - 1; j++)
        {
            if (pessoas[j].idade > pessoas[j + 1].idade)
            {
                struct Pessoa temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }

    printf("\n**Dados ordenados por idade:**\n");
    printf("Nome | Idade | Sexo | Endereço | Ocupação\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < numLinhas; i++)
    {
        printf("%s | %d | %s | %s | %s\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo,
               pessoas[i].endereco, pessoas[i].ocupacao);
    }

    fclose(arquivo);
    free(pessoas);

    return 0;
}
