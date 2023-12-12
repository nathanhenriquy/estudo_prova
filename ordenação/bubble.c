#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float bubleSort(float *V, int N)
{
    int i, continua, fim = N;
    float aux;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            if (V[i] > V[i + 1])
            {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}

int main()
{
    setlocale(LC_ALL, "PORTUGUESE");

    float vet[] = {9.1, 4.6, 5.7, 8.3, 6.15, 7.3, 5.43, 8.75, 6.32, 7.1};
    float soma;
    int i, n = 10;

    bubleSort(vet, n);

    system("cls");

    printf("Os valores após a ordenação serão:");

    for (i = 0; i < n; i++)
    {

        printf("\n %.2f ", vet[i]);
        soma = soma + vet[i];
    }

    printf("\n Á media da turma é: %.2f", soma / 10);
}