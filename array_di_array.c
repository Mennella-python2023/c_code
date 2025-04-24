#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Quanti punti vuoi memorizzare?\n");
    scanf("%d", &n);

    // Allocate memory for array of pointers
    float** a = calloc(n, sizeof(int*));

    if (a == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    // Allocate memory for each point
    for (int i = 0; i < n; i++) {
        a[i] = calloc(3, sizeof(float));

        if (a[i] == NULL) {
            printf("Errore nell'allocazione della memoria.\n");
            return 1;
        }

        printf("Inserisci coordinate del punto %d: ", i);
        scanf("%f %f %f", &(a[i][0]), &(a[i][1]), &(a[i][2]));
    }

    // Print stored points
    for (int i = 0; i < n; i++) {
        printf("P%d = (%.2f, %.2f, %.2f)\n", i, a[i][0], a[i][1], a[i][2]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}




