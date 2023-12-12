/*15. Considere a seguinte estrutura:
    1. struct aluno:


        typedef struct aluno {
            char nome[30];
            float media;
            int faltas;
        } aluno;


    2. Faça um programa que leia informações de n alunos em um vetor alocado dinamicamente. Em seguida, imprima as informações lidas na ordem decrescente das médias dos alunos.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[30];
    float media;
    int faltas;

} aluno;

void buble (aluno *a, int n){
    int i, j;

    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n - i -1; j++)
        {
          if (a[j].media < a[j + 1].media) {
                aluno temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
    



int main()
{
    int quant;

    printf("Quantos alunos deseja adicionar: ");
    scanf("%i", &quant);

    struct aluno *a = (struct aluno *)malloc (quant * sizeof (struct aluno ));

    for (int i = 0; i < quant; i++)
    {
        printf("Nome: ");
        fflush(stdin);
        gets(a[i].nome);
        fflush(stdin);

        printf("Media: ");
        scanf("%f", &a[i].media);

        printf("Faltas: ");
        scanf("%i", &a[i].faltas);

    };

    buble(a, quant);

    for (int i = 0; i < quant; i++)
    {
        printf("Nome: %s", a[i].nome);  
        printf("Media: %f", a[i].media);        
        printf("Faltas: %i", a[i].faltas);
        printf("\n");
       
    };

    free(a);  
    
    return 0;
}

