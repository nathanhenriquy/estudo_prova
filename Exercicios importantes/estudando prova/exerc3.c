/*Crie um programa em C para registrar o tempo gasto em tarefas diferentes. O programa deve permitirao usuário especificar o número de tarefas, inserir nomes de tarefas e o tempo gasto em cada uma. Use a locação dinâmica para armazenar as informações das tarefas e, no final, calcule o tempo total gasto e exiba as tarefas e o tempo gasto em cada uma.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tarefa{
    char nome [100];
    int tempo_gasto;

};

int main(){
    int i, num_tarefas, total_gasto = 0;


    printf("Quantas tarefas deseja registrar? ");
        scanf("%i", &num_tarefas);
    
    struct tarefa * t = (struct tarefa *) malloc (num_tarefas * sizeof(struct tarefa));

    printf("\n======Cadastro dos Registros======\n");

    for (i = 0; i < num_tarefas; i++) {
        printf("Nome da Tarefa: ");
        fflush(stdin);
        gets(t[i].nome);    
         
        printf("Tempo gasto (em minutos): ");
        scanf("%i", &t[i].tempo_gasto);


        printf("\n");

    }

        for (int i = 0; i < num_tarefas; i++) 
	{
        total_gasto += t[i].tempo_gasto;
    }

        

    printf("\n======TAREFAS======\n");

    for (i = 0; i < num_tarefas; i++) {
        printf("\nNome: %s ", t[i].nome);
        printf("\nTempo: %.i min", t[i].tempo_gasto);
     
        printf("\n\n");
    }

    printf("Total tempo gasto: %.i minutos ", total_gasto);

    free(t);
    

    
    return 0;
}
