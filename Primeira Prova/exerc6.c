/*Imagine que você está desenvolvendo um programa em Linguagem C para acompanhar informações sobre a qualidade do ar em diferentes cidades de todoo mundo. Crie uma struct chamada DadosAr que armazenará informações sobre a qualidade do ar em N cidades do mundo os dados considerados para este controle serão:

 Nome do Cidade (string de tamanho 50)
 Nível de Poluição (int) – um valor inteiro que representa o nível de poluição do ar nacidade (de 0 a 100, onde 0 é a melhor qualidade do ar e 100 é a pior
 Data da coleta (string de tamanho 30) – Ex de Entrada 01/10/2023

O programa deve permitir ao usuário especificar o número de cidades que você quer gerenciar (N),inserir o nome da cidade, o nome índice de poluição e o data da coleta. Use alocação dinâmicapara armazenar as informações e, no final mostre na tela todos os dados coletados. Ao final, oprograma mostre a cidade com maior grau de poluição e também deve liberar a memória alocada,*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dadosAr
{
    char nomecidade[50];
    int poluicao;
    char data[30];
};

int main()
{
    int quant;

    printf("Informe o número de cidades: ");
    scanf("%d", &quant);

    struct dadosAr *dados = (struct dadosAr *)malloc(quant * sizeof(struct dadosAr));

    if (dados == NULL)
    {
        printf("Erro de alocacao");

        return 0;
    }

    for (int i = 0; i < quant; i++)
    {
        printf("\nInforme o nome da cidade %d: ", i + 1);
        scanf("%s", dados[i].nomecidade);

        printf("Informe o índice de poluição para a cidade %d (de 0 a 100): ", i + 1);
        scanf("%d", &dados[i].poluicao);

        printf("Informe a data da coleta para a cidade %d (no formato DD/MM/AAAA): ", i + 1);
        scanf("%s", dados[i].data);
    }

    printf("\nDados coletados:\n");

    for (int i = 0; i < quant; i++)
    {
        printf("Cidade: %s, Poluição: %d, Data da coleta: %s\n", dados[i].nomecidade, dados[i].poluicao, dados[i].data);
    }

    int indiceMaiorPoluicao = 0;
    for (int i = 1; i < quant; i++)
    {
        if (dados[i].poluicao > dados[indiceMaiorPoluicao].poluicao)
        {
            indiceMaiorPoluicao = i;
        }
    }

    printf("\nCidade com maior grau de poluição: %s, Poluição: %d\n", dados[indiceMaiorPoluicao].nomecidade, dados[indiceMaiorPoluicao].poluicao);

    free(dados);

    return 0;
};