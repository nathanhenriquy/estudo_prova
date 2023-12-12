/*Faça um programa que leia informações de n alunos em um vetor alocado dinamicamente. Em seguida, imprima as informações lidas na ordem decrescente das médias dos alunos.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	char nome[30];
	float media;
	int faltas;
} aluno;

int main(){
    int i, quantalunos;

    printf("\nDigite o numero de alunos: ");
    scanf("%i", &quantalunos);

    struct aluno * a = (struct aluno *)malloc(quantalunos * sizeof(struct aluno));

    if (a == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return 1; 
    }

    for ( i = 0; i < quantalunos; i++)
    {
        printf("Nome do aluno %d: ", i + 1);
        scanf("%s", a[i].nome);

        printf("Média do aluno %d: ", i + 1);
        scanf("%f", &a[i].media);

        printf("Faltas do aluno %d: ", i + 1);
        scanf("%d", &a[i].faltas);

        printf("\n");
    }

    for (i = 0; i < quantalunos - 1; i++) {
        for (int j = i + 1; j < quantalunos; j++) {
            if (a[i].media < a[j].media) {
                
                struct aluno temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    
    printf("\nAlunos em ordem decrescente de média:\n");
    for (i = 0; i < quantalunos; i++) {
        printf("Nome: %s\n", a[i].nome);
        printf("Média: %.2f\n", a[i].media);
        printf("Faltas: %d\n", a[i].faltas);
        printf("\n");
    }

    free(a);
    

    
    return 0;
}
