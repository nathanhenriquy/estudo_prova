#include <stdio.h>
#include <stdlib.h>

int main() {
    float notas[] = {9.1, 4.6, 5.7, 8.3, 6.15, 7.3, 5.43, 6.15, 8.75, 6.32};

    int i, j, n = 10;
    float aux;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= 10; j++) { 
            if (notas[j] > notas[j + 1]) {
                aux = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = aux;
            }
        }
    }

    printf("Notas ordenadas em ordem crescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%.2f ", notas[i]);
    }

    return 0;
}
