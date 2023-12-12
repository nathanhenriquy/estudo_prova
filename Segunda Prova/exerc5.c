/*Uma equipe de vôlei possui 12 atletas, cada um com suarespectiva altura. Implemente um algoritmo em linguagem C que ordene os atletas em ordemcrescente de altura.

Alt | Nome
--- | --------
180 | João
178 | Maria
176 | José...

Dicas:
 Você pode utilizar um algoritmo de ordenação simples, como o Bubble Sort ou o SelectionSort.
 Para armazenar as alturas dos atletas, você pode utilizar um vetor.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altura;
    char nome[50];
} Atleta;

void trocar(Atleta *a, Atleta *b) {
    Atleta temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Atleta atletas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (atletas[j].altura > atletas[j + 1].altura) {
                trocar(&atletas[j], &atletas[j + 1]);
            }
        }
    }
}

int main() {
    
    int numAtletas = 12;

    Atleta equipeVolei[12] = {
        {180, "João"},
        {178, "Maria"},
        {176, "José"},
       
    };

  
    bubbleSort(equipeVolei, numAtletas);

    printf("Altura | Nome\n");
    printf("------|--------\n");
    for (int i = 0; i < numAtletas; i++) {
        printf("%d     | %s\n", equipeVolei[i].altura, equipeVolei[i].nome);
    }

    return 0;
}

