#include <stdio.h>
#include <string.h>

void bubbleSort(char (*V)[30], int Fim) 
{
    int i, j;
    char temp[30];

    for(i = 1; i < Fim; i++)
    {
        for (j = 0; j < Fim-1; j++)
        {
            if(strcmp(V[j],V[j+1]) > 0)
            {
                strcpy(temp,V[j]);
                strcpy(V[j],V[j+1]);
                strcpy(V[j+1],temp);
            }
        }
    }
}

int main() {
    int quant;

    printf("Digite a quantidade de nomes que deseja armazenar: ");
    scanf("%d", &quant);

    char nomes[quant][30];

    
    for (int i=0; i < quant; i++)
    {
        printf("Favor informar o nome da %iª pessoa: ", i+1);
        fflush(stdin);
        gets(nomes[i]);
        fflush(stdin);
    }

    bubbleSort(nomes, quant);

    printf("\n\n################## NOMES ORDENADOS ##################\n");

    for(int i=0; i<quant; i++)
    {
        printf("%s\n",nomes[i]);
    }
   
    

    return 0;
}




