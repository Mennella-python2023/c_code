#include <stdio.h>
#include <stdlib.h>

struct house {
    int houseNumber;
    struct house *previous;
    struct house *next;
};

int main(void) {
    // Creazione dei nodi
    struct house house1;
    struct house house2;
    struct house house3;
    struct house house4;

    // Inizializzazione dei valori
    house1.houseNumber = 1;
    house2.houseNumber = 3;
    house3.houseNumber = 5;
    house4.houseNumber = 7;

    // Collegamenti "next"
    house1.next = &house2;
    house2.next = &house3;
    house3.next = &house4;
    house4.next = NULL;

    // Collegamenti "previous"
    house1.previous = NULL;
    house2.previous = &house1;
    house3.previous = &house2;
    house4.previous = &house3;

    // Puntatori di inizio e fine lista
    struct house *firstHouse = &house1;
    struct house *lastHouse = &house4;
    struct house *current;

    // Stampa in ordine crescente
    printf("Case in ordine crescente:\n");
    current = firstHouse;
    while (current != NULL) {
        printf("House number: %d\n", current->houseNumber);
        current = current->next;
    }

    // Stampa in ordine decrescente
    printf("\nCase in ordine decrescente:\n");
    current = lastHouse;
    while (current != NULL) {
        printf("House number: %d\n", current->houseNumber);
        current = current->previous;
    }

    return 0;
}
