/*A obesidade é um problema de saúde crescente em todo o mundo. Muitas vezes, é importante monitorar e analisar dados relacionados ao peso de indivíduo sao longo do tempo para avaliar seu progresso na direção de um peso saudável.

Implemente um programa em C que após a pessoas informar o número de dias que deseja computar seu peso e seus respectivos pesos chame uma função em chamada controle Peso. A função deverá receber como parâmetros um ponteiro para um vetor de valores float referentes ao peso da pessoa, o tamanho desse (referente aos dias que ela computou seu peso) e uma variável para a média. A função deve somar todos os pesos informados pela pessoa e em seguida retornar via ponteiro para a pessoa a média de peso dela no período analisado.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void controlePeso(float *pesos, int tamanho, float *media)
{
    float soma = 0;

    for (int i = 0; i < tamanho; i++)
    {
        soma += pesos[i];
    }

    if (tamanho > 0)
    {
        *media = soma / tamanho;
    }
}

int main()
{
    int numDias;

    printf("Informe o número de dias que deseja computar o peso: ");
    scanf("%d", &numDias);

    float *pesos = (float *)malloc(numDias * sizeof(float));

    if (pesos == NULL)
    {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < numDias; i++)
    {
        printf("Informe o peso no dia %d: ", i + 1);
        scanf("%f", &pesos[i]);
    }

    float mediaPeso;
    controlePeso(pesos, numDias, &mediaPeso);

    printf("A média de peso no período analisado é: %.2f\n", mediaPeso);

    free(pesos);

    return 0;
}
