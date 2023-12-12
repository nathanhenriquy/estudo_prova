/*Escreva um programa que peça ao usuário para especificar o tamanho de um vetor de inteiros e, em seguida, aloque dinamicamente memória para esse vetor. Preencha o vetor com números aleatórios e, em seguida, imprima os valores.*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vet, tamvet, i;

    printf("Qual o tamanho do vetor? =  ");
        scanf("%i", &tamvet);

    vet = (int *) malloc(tamvet * sizeof(int));

    if (vet == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return 1; 
    }

    for ( i = 0; i < tamvet; i++)
    {
        printf("DIgite valores para a posicao %i= ", i);
            scanf("%i", &vet[i]);
    }

     for ( i = 0; i < tamvet; i++)
    {
        printf(" %i = %i\n ", i , vet[i] );
            
    }

    free(vet);
    
    
    return 0;
}
