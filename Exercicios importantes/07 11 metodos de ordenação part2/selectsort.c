#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *V, int N)
{
    int i, j, menor, troca;

    for (i = 0; i < N - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < N; j++)
        {
            if (V[j] < V[menor])
                menor = j;
        }
        if (i != menor)
        {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

int main()
{
    float notas[] = {9.1, 4.6, 5.7, 8.3, 6.15, 7.3, 5.43, 6.15, 8.75, 6.32};

    int n = 10;

    selectionSort(notas, n);

    printf("Notas ordenadas em ordem crescente:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f ", notas[i]);
    }

    return 0;
}
