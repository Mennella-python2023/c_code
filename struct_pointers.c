#include <stdio.h>
#include <stdlib.h>

// Struttura per un nodo della coda
struct Node {
    int value;
    struct Node *next;
};

int main(void) {
    // Array di valori da inserire nella coda
    int arr[10] = {2, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // Puntatori per la coda
    struct Node *front = NULL;   // primo elemento
    struct Node *rear = NULL;    // ultimo elemento

    // Creazione della coda con malloc
    for (int i = 0; i < 10; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->value = arr[i];
        newNode->next = NULL;

        if (rear == NULL) {
            // Primo nodo
            front = newNode;
            rear = newNode;
        } else {
            // Aggiunta in fondo
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Stampa dei primi 5 valori
    printf("First 5 values\n");
    struct Node *current = front;
    for (int i = 0; i < 5 && current != NULL; i++) {
        printf("%d\n", current->value);
        current = current->next;
    }

    // Stampa dei primi 7 valori
    printf("First 7 values\n");
    current = front;
    for (int i = 0; i < 7 && current != NULL; i++) {
        printf("%d\n", current->value);
        current = current->next;
    }

    // Liberazione della memoria
    current = front;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    printf("Memory is freed..\n");

    return 0;
}
