
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;
    scanf("%d", &size); // Read the matrix size from user input
    
    if (size > 20) 
    {
        puts("Matrix too big."); // Display a warning if the matrix is too large
    } 
    else 
    {
        int **matrix = (int**)malloc(sizeof(int *) * size); // Allocate memory for row pointers
        int i, j;

        // Allocate memory for each row
        for (i = 0; i < size; i++) 
        {
            matrix[i] = (int*)malloc(sizeof(int) * size);
        }

        // Fill the matrix with multiplication values
        for (i = 0; i < size; i++) 
        {
            for (j = 0; j < size; j++) 
            {
                matrix[i][j] = (i+1) * (j+1);
            }
        }

        // Print column headers
        printf("%4c", ' ');
        for (j = 0; j < size; j++) 
        {
            printf("%4d", j + 1);
        }
        printf("\n");

        // Print matrix with row headers
        for (i = 0; i < size; i++) 
        {
            printf("%4d", i + 1);
            for (j = 0; j < size; j++) 
            {
                printf("%4d", matrix[i][j]);
            }
            printf("\n");
        }

        // Free allocated memory
        for (i = 0; i < size; i++) 
        {
            free(matrix[i]);
        }
        free(matrix);
    }

    return 0;
}
