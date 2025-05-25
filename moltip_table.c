
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size, i, j;
    
    // Ask the user for the matrix size
    printf("Enter the size of the multiplication table: ");
    scanf("%d", &size);

    // Check if size exceeds the limit
    if (size > 20) {
        printf("Matrix too big.\n");
        return 1;
    }

    // Allocate memory for the matrix
    int **matrix = (int **) malloc(size * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < size; i++) {
        matrix[i] = (int *) malloc(size * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    // Fill the matrix with multiplication results
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    // Print formatted multiplication table
    printf("      "); // Formatting for the header row
    for (i = 0; i < size; i++) {
        printf("%4d", i + 1);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        printf("%4d", i + 1); // Row header
        for (j = 0; j < size; j++) {
            printf("%4d", matrix[i][j]); // Matrix values with 4-character formatting
        }
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
