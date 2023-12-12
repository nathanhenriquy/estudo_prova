#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define N 5
/* EXPLICAÇÃO SOBRE A SAÍDA DA STRCMP
A função strcmp() pode retornar um valor nulo (zero), positivo ou negativo.

Quando as palavras comparadas são iguais, a função retorna 0.
Quando as palavras comparadas são diferentes e a primeira é maior, a função
retorna um valor positivo, caso contrário, a função retorna negativo, sendo
 que no alfabeto a “menor” letra é “a”, e a maior, “z”.

   saida da strcmp (str1, str2, == 0)
   == 0: str1 é igual a str2
    > 0: str1 vem depois da str2
    < 0: str1 vem antes de str2 */

void bubbleSort(char (*V)[30], int Fim) // sintase para ler e ordenar um vetor char.
{
    int i, j;
    char temp[30];

    for (i = 1; i < Fim; i++)
    {
        for (j = 0; j < Fim - 1; j++)
        {
            if (strcmp(V[j], V[j + 1]) > 0)
            {
                strcpy(temp, V[j]);
                strcpy(V[j], V[j + 1]);
                strcpy(V[j + 1], temp);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "PORTUGUESE");
    SetConsoleOutputCP(28591); // leitura da tabela Latina (escrita)
    SetConsoleCP(28591);       // Acentuação para funções (leitura) funções na bib windows

    char vet[N][30];

    int i;

    for (i = 0; i < N; i++)
    {
        printf("Favor informar o nome da %iª pessoa: ", i + 1);
        gets(vet[i]);
    }

    bubbleSort(vet, N);

    printf("\n\n################## NOMES ORDENADOS ##################\n");

    for (i = 0; i < N; i++)
    {
        printf("%s\n", vet[i]);
    }
}