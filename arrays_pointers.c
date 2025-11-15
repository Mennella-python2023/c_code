#include <stdio.h>
#include <stdlib.h>

// Funzione per stampare una matrice dinamica
void printMatrix(int *arrptr[], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arrptr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {// Dichiarazione di un array di puntatori
    int *arrptr[3];// Matrice 3x3
    int i, j;

    // Allocazione e inizializzazione
    for (i = 0; i < 3; i++) {
        arrptr[i] = (int *) malloc(3 * sizeof(int));//
        for (j = 0; j < 3; j++)//
            arrptr[i][j] = (3 * i) + j + 1;
    }

    // Stampa della matrice
    printf("Matrice 3x3:\n");
    printMatrix(arrptr, 3, 3);

    // Liberazione memoria
    for (i = 0; i < 3; i++)
        free(arrptr[i]);

    return 0;
}
