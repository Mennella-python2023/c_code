#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* invertiArray(char *v, int n) {
    char *inverso = (char*) malloc((n + 1) * sizeof(char)); // +1 per il terminatore '\0'
    if (inverso == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        inverso[i] = v[n - 1 - i]; // Copia gli elementi in ordine inverso
    }
    
    inverso[n] = '\0'; // Aggiunta del terminatore di stringa

    return inverso;
}

int main() {
    char v[100]; // Supponiamo una dimensione massima di 100 caratteri

    printf("Inserisci una stringa: ");
    fgets(v, sizeof(v), stdin); // Legge l'input dell'utente

    // Rimuove il '\n' dalla fine della stringa, se presente
    int n = strlen(v);
    if (v[n - 1] == '\n') {
        v[n - 1] = '\0';
        n--; // Riduciamo la lunghezza effettiva della stringa
    }

    char *inverso = invertiArray(v, n);

    if (inverso != NULL) {
        printf("Stringa invertita: %s\n", inverso);
        free(inverso); // Liberiamo la memoria allocata
    }

    return 0;
}
