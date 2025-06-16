
// funzioni.c
#include "aux.h"

char* confronti_positivi(int* a, int n, int x) {
    if (a == NULL || n <= 0) {
        return NULL;
    }

    // Conta quanti elementi sono > 0
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            count++;
        }
    }

    if (count == 0) {
        return NULL;
    }

    // Alloca memoria per la stringa (+1 per '\0')
    char* result = (char*)malloc((count + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    // Costruisce la stringa 't'/'f'
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            result[j++] = (a[i] > x) ? 't' : 'f';
        }
    }

    result[j] = '\0';  // Terminatore
    return result;
}

// Facoltativa: stampa array di interi
void vec_print(int *vec, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", vec[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}
