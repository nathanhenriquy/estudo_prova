/*Escreva um programa que crie um arquivo chamado "registro.txt" para armazenar informações de alunos. O programa deve permitir ao usuário inserir os dados de vários alunos, como nome,matrícula e idade. Os dados de cada aluno devem ser escritos no arquivo em um formato específico.Depois que o usuário inserir os dados, o programa deve listar os alunos do arquivo no console*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alunos
{
    char nome[50];
    int matricula;
    int idade;
};

int main()
{
    int quant;

    printf("QUantos Alunos deseja adicionar? ");
    scanf("%i", &quant);

    struct alunos *a = (struct alunos *)malloc(quant * sizeof(struct alunos));

    if (a == NULL)
    {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    FILE *arq;

    arq = fopen("registro.txt", "a");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        free(a);
        return 1;
    }

    for (int i = 0; i < quant; i++)
    {
        printf("\nSeu nome: ");
        fflush(stdin);
        gets(a[i].nome);
        fflush(stdin);

        printf("Sua matricula: ");
        scanf("%i", &a[i].matricula);

        printf("Sua Idade: ");
        scanf("%i", &a[i].idade);

        fprintf(arq, "%s %i %i", a[i].nome, a[i].matricula, a[i].idade);
    }

    fclose(arq);

    printf("\n\n DADOS \n\n ");

    arq = fopen("registro.txt", "r");

    for (int i = 0; i < quant; i++)
    {
        fscanf(arq, "%s %i %i", a[i].nome, &a[i].matricula, &a[i].idade);
        printf("Nome: %s Matricula: %i Idade: %i\n", a[i].nome, a[i].matricula, a[i].idade);
    }

    fclose(arq);

    free(a);

    return 0;
}
