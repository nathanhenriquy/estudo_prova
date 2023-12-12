/*Escreva um programa em C que pede ao usuário para inserir o número de linhas e colunas de uma matriz bidimensional. Em seguida, aloque dinamicamente a matriz e peça ao usuário para inserir os elementos da matriz. Finalmente, calcule e imprima a soma de todos os elementos da matriz.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int linha, coluna, i, j, **matrizb, soma = 0;
    
        printf("Digite o numero para linhas: ");
            scanf("%i", &linha);

        printf("\nDigite o numero para colunas: ");
            scanf("%i", &coluna);   

        
        matrizb = (int **)malloc(linha * sizeof(int *));
            for ( i = 0; i < linha; i++) {
                matrizb[i] = (int *)malloc(coluna * sizeof(int));
        }

        printf("\nPreencha a matriz: \n");

        for ( i = 0; i < linha; i++) {
            for ( j = 0; j < coluna; j++) {
            printf("Elemento [%i][%i]: ", i, j);
            scanf("%d", &matrizb[i][j]);
            }
        }

        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
            soma += matrizb[i][j];
            }
        }

        printf("\n=====================================================\n");

        printf("\nMatriz dada: \n");

        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
            printf("%i | ", matrizb[i][j]);
            }
            printf("\n");
        }

        printf("\nA soma eh: %i \n", soma);

        for ( i = 0; i < linha; i++)
        {
            free(matrizb[i]);
        }

         free(matrizb);       

     

    
    return 0;
}
