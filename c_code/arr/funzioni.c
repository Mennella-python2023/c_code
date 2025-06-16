
#include <stdlib.h>
#include <stdio.h>
#include "funzioni.h"

char* confronti_positivi(int* a, int n, int x) {
    if (a == NULL || n <= 0) {
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            count++;
        }
    }

    if (count == 0) {
        return NULL;
    }

    char* result = (char*)malloc((count + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            result[j++] = (a[i] > x) ? 't' : 'f';
        }
    }

    result[j] = '\0';
    return result;
}

void vec_print(int* vec, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", vec[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}
