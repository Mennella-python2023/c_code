#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // per strcpy

struct house {
    char houseColour[10];
    struct house *previous;
    struct house *next;
};

int main(void) {
    // Creazione dei nodi
    struct house house1;
    struct house house2;
    struct house house3;
    struct house house4;

    // Inizializzazione dei valori (attenzione alla dimensione: max 9 + '\0')
    strcpy(house1.houseColour, "rosa");
    strcpy(house2.houseColour, "rossa");
    strcpy(house3.houseColour, "verde");
    strcpy(house4.houseColour, "giallo");

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
        printf("Colour house: %s\n", current->houseColour);
        current = current->next;
    }

    // Stampa in ordine decrescente
    printf("\nCase in ordine decrescente:\n");
    current = lastHouse;
    while (current != NULL) {
        printf("Colour house: %s\n", current->houseColour);
        current = current->previous;
    }

    return 0;
}
