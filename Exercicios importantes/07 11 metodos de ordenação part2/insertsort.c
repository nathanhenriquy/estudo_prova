/*Faça um programa que receba um número de alunos matriculas nadisciplina de Prog, e receba também a matricula de cada um dos alunosdesta turma.Após utilizando-se do método de ordenação Insertsort listena tela por ordem das matriculas os alunos desta turma.*/

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(float *v, int N)
{
    int i, j;
    float aux;

    for (i = 1; i < N; i++)
    {
        aux = v[i];
        j = i - 1;
        while ((j >= 0) && (aux < v[j]))
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

int main()
{
    int n;

    printf("Quantos alunos deseja cadastrar?  ");
        scanf("%i", &n);

    int alunos[n];

    for (int i = 0; i < n; i++)
    {
        printf("Digite a matricula do aluno %i: ", i + 1);
            scanf("%i", &alunos[i]);
            
        
    }
    
    insertion_sort(alunos, n);

    printf("Matrículas dos alunos ordenadas:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", alunos[i]);
    }


    return 0;
}
