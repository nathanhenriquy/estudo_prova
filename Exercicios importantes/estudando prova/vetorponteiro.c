/* Declare um vetor de 10 posições do tipo int, inicialize um ponteiro para a posição inicial do vetor, faça o ponteiro percorrer o vetor preenchendo estas posições com valores quaisquer lidos do teclado e depois imprima os 10 valores de trás para frentes, novamente a partir do vetor;*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    int vet[10];
	int *p;
	int i;
	
	p = vet;
	
	for(i=0; i<10; i++)
	{
		printf("Digite valor para %i = ", i);
            scanf("%i", p);
		p++;
	}

    printf("Valores do vetor de tras para frente:\n");
    p = &vet[9]; 

    for (i = 9; i >= 0; i--) {
        printf("%i ", *p); 
        p--; 
    }

   
    return 0;
}
