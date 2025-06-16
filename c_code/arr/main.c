
#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int a[] = {-10, 8, -1, -7, 4, 7, -10, 6, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int x = 6;

    printf("Array input: ");
    vec_print(a, n);

    char* res = confronti_positivi(a, n, x);

    if (res == NULL) {
        printf("Nessun valore positivo nell'array.\n");
    } else {
        printf("Output stringa: \"%s\"\n", res);
        free(res);
    }

    return 0;
}
