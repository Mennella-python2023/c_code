#include <stdio.h>
#include <stdlib.h>

// Struttura per un nodo della coda
struct Node {
    int value;
    struct Node *next;
};

// Funzione per inserire un elemento in coda
void enqueue(struct Node **front, struct Node **rear, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Errore: allocazione memoria fallita.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        // Primo nodo
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Funzione per stampare i primi N elementi
void printFirstN(struct Node *front, int n) {
    printf("Primi %d valori:\n", n);
    struct Node *current = front;
    for (int i = 0; i < n && current != NULL; i++) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

// Funzione per liberare la memoria della coda
void freeQueue(struct Node *front) {
    struct Node *current = front;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    printf("Memoria liberata.\n");
}

int main(void) {
    int arr[10] = {2, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    struct Node *front = NULL;
    struct Node *rear = NULL;

    // Creazione della coda
    for (int i = 0; i < 10; i++) {
        enqueue(&front, &rear, arr[i]);
    }

    // Stampa dei primi 5 e 7 valori
    printFirstN(front, 5);
    printFirstN(front, 7);

    // Liberazione memoria
    freeQueue(front);

    return 0;
}