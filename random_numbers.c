
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int M, N;

    printf("Inserisci M: ");
    scanf("%d", &M);

    printf("Inserisci N: ");
    scanf("%d", &N);

    // Scambiamo M e N se M > N per sicurezza
    if (M > N) {
        int temp = M;
        M = N;
        N = temp;
    }

    // Inizializza il generatore di numeri casuali con il tempo corrente
    srand(time(NULL));

    // Genera numero casuale nell'intervallo [M, N]
    int range = N - M + 1;
    int random_number = rand() % range + M;

    printf("Numero casuale tra %d e %d: %d\n", M, N, random_number);

    return 0;
}
