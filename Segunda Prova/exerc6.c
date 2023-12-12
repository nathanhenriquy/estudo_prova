/*Implemente um programa em linguagem C que permita ocadastro de animais em uma ONG. O programa deve permitir as seguintes operações:

 Cadastro de um novo animal: O usuário deve informar os seguintes dados do animal:
 Código
 Nome
 Espécie
 Raça
 Data de nascimento
 Sexo

 Consulta de um animal: O usuário deve informar o código do animal para consultar seusdados.
 Listagem de todos os animais:

O programa deve listar todos os animais cadastrados, comseus respectivos dados.O programa deve utilizar arquivos TXT para armazenar os dados dos animais.

Exemplo de saída:

**Menu**
1. Cadastrar animal
2. Consultar animal
3. Listar animais
0. Sair*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ong
{
    int codigo;
    char nome[50];
    char especie[50];
    char raca[50];
    int dia, mes, ano;
    char sexo[2];
};

int main()
{
    struct ong *g = malloc(sizeof(struct ong));

    int escolha;

    while (1)
    {
        printf("\n**Menu**\n1. Cadastrar animal\n2. Consultar animal\n3. Listar animais\n0. Sair\n");
        scanf("%i", &escolha);

        switch (escolha)
        {
        case 1:
        {
            FILE *arq = fopen("ong.txt", "a");

            if (arq == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
                exit(1);
            }

            printf("Qual o codigo: ");
            scanf("%i", &g->codigo);

            printf("Qual o Nome: ");
            fflush(stdin);
            fgets(g->nome, sizeof(g->nome), stdin);
            g->nome[strcspn(g->nome, "\n")] = '\0';

            printf("Qual a especie: ");
            fflush(stdin);
            fgets(g->especie, sizeof(g->especie), stdin);
            g->especie[strcspn(g->especie, "\n")] = '\0';

            printf("Qual a raca: ");
            fflush(stdin);
            fgets(g->raca, sizeof(g->raca), stdin);
            g->raca[strcspn(g->raca, "\n")] = '\0';

            printf("Qual o dia nascimento: ");
            scanf("%i", &g->dia);
            printf("Qual o mes nascimento: ");
            scanf("%i", &g->mes);
            printf("Qual o ano nascimento: ");
            scanf("%i", &g->ano);

            printf("Qual a sexo (M ou F): ");
            fflush(stdin);
            fgets(g->sexo, sizeof(g->sexo), stdin);
            g->sexo[strcspn(g->sexo, "\n")] = '\0';

            fprintf(arq, "%i %s %s %s %i %i %i %s\n", g->codigo, g->nome, g->especie, g->raca, g->dia, g->mes, g->ano, g->sexo);
            fclose(arq);

            printf("Animal cadastrado com sucesso!\n");
        }
        break;

        case 2:
        {
            int cod2;

            printf("Digite o Codigo do Animal: ");
            scanf("%i", &cod2);

            FILE *arq = fopen("ong.txt", "r");

            if (arq == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
                exit(1);
            }

            int encontrado = 0;

            while (fscanf(arq, "%i %s %s %s %i %i %i %s", &g->codigo, g->nome, g->especie, g->raca, &g->dia, &g->mes, &g->ano, g->sexo) != EOF)
            {
                if (cod2 == g->codigo)
                {
                    printf("%i %s %s %s %i %i %i %s\n", g->codigo, g->nome, g->especie, g->raca, g->dia, g->mes, g->ano, g->sexo);
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
            {
                printf("Nao achou esse codigo.\n");
            }

            fclose(arq);
        }
        break;

        case 3:
        {
            FILE *arq = fopen("ong.txt", "r");

            if (arq == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
                exit(1);
            }

            while (fscanf(arq, "%i %s %s %s %i %i %i %s", &g->codigo, g->nome, g->especie, g->raca, &g->dia, &g->mes, &g->ano, g->sexo) != EOF)
            {
                printf("%i %s %s %s %i %i %i %s\n", g->codigo, g->nome, g->especie, g->raca, g->dia, g->mes, g->ano, g->sexo);
            }

            fclose(arq);
        }
        break;

        case 0:
            free(g);
            exit(0);

        default:
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}
