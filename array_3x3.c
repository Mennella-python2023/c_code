#include <stdio.h>

// Funzione per stampare una matrice 3x3
void printMatrix(int arr[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); // nuova riga dopo ogni riga della matrice
    }
    printf("\n"); // riga vuota per separare stampe successive
}

int main(void) {
    int arr[3][3] = { 
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9} 
    };

    // Invocazioni della funzione
    printf("Prima stampa:\n");
    printMatrix(arr, 3, 3);

    printf("Seconda stampa:\n");
    printMatrix(arr, 3, 3);

    return 0;
}
