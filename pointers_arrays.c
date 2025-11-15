#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[3][3];        // matrice statica
    int *ptrarr[3];         // array di puntatori

    // Inizializzo la matrice
    array[2][2] = 42;

    // Alloco memoria per ptrarr[2]
    ptrarr[2] = malloc(3 * sizeof(int));
    ptrarr[2][2] = 99;

    printf("array[2][2] = %d\n", array[2][2]);
    printf("ptrarr[2][2] = %d\n", ptrarr[2][2]);

    free(ptrarr[2]);
    return 0;
}
