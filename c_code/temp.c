#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    void *data = malloc(sizeof(float) + sizeof(char));
    float *temp = (float *)data;
    char *scala = (char *)(temp + 1);

    printf("Inserire la temperatura: ");
    scanf("%f", temp);

    getchar(); // Consume the leftover newline character
    printf("Inserire la scala (K, C, F): ");
    scanf("%c", scala);

    switch (*scala) {
    case 'K':
        printf("C: %f\n", *temp - 273.15f);
        printf("F: %f\n", (*temp - 273.15f) * 9.0f / 5.0f + 32.0f);
        break;
    case 'C':
        printf("K: %f\n", *temp + 273.15f);
        printf("F: %f\n", *temp * 9.0f / 5.0f + 32.0f);
        break;
    case 'F':
        printf("K: %f\n", ((*temp - 32.0f) * 5.0f / 9.0f) + 273.15f);
        printf("C: %f\n", (*temp - 32.0f) * 5.0f / 9.0f);
        break;
    default:
        printf("Scala non valida! Inserire K, C o F.\n");
        break;
    }

    free(data);
    data = NULL;

    return 0;
}
