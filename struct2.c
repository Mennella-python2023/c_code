#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ===========================
    Strutture dati
   =========================== */

// Nodo della lista collegata (elemento della coda)
typedef struct Node {// Nodo della lista collegata (elemento della coda)
    int value;// Valore memorizzato nel nodo
    struct Node *next;// Puntatore al nodo successivo
} Node;// Nodo della lista collegata (elemento della coda)

// Coda con puntatori a front (testa) e rear (coda)
typedef struct Queue {/* Coda con puntatori a front (testa) e rear (coda) */
    Node *front;// Puntatore al primo nodo della coda
    Node *rear;// Puntatore all'ultimo nodo della coda  
} Queue;/* Coda con puntatori a front (testa) e rear (coda) */

/* ===========================
    Prototipi delle funzioni
   =========================== */

void initQueue(Queue *q); // inizializza la coda
bool isEmpty(const Queue *q); // ritorna true se la coda è vuota
bool enqueue(Queue *q, int value);         // restituisce false se malloc fallisce
bool dequeue(Queue *q, int *outValue);     // restituisce false se coda vuota
void printFirstN(const Queue *q, int n);// stampa i primi N elementi senza modificarli
void freeQueue(Queue *q);// libera tutti i nodi della coda e la reimposta vuota

/* ===========================
    Implementazione
   =========================== */

// Inizializza la coda
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear  = NULL;
}

// Ritorna true se la coda è vuota
bool isEmpty(const Queue *q) {
    return (q->front == NULL);
}

// Inserisce un elemento in coda; ritorna false in caso di allocazione fallita
bool enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));// Allocazione del nuovo nodo
    if (newNode == NULL) {
        // Non usare exit qui: lascia che sia il chiamante a decidere cosa fare
        return false;
    }

    newNode->value = value;// Imposta il valore
    newNode->next  = NULL;// Nuovo nodo sarà l'ultimo, quindi next è NULL

    if (q->rear == NULL) {
        // Coda vuota: front e rear puntano entrambi al nuovo nodo
        q->front = newNode;
        q->rear  = newNode;
    } else {
        // Collega in fondo e aggiorna rear
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return true;
}

// Estrae un elemento dalla testa; ritorna false se la coda è vuota
bool dequeue(Queue *q, int *outValue) {
    if (isEmpty(q)) {
        return false;
    }
    Node *temp = q->front;
    if (outValue) {
        *outValue = temp->value;
    }
    q->front = q->front->next;
    if (q->front == NULL) {
        // Se la coda è diventata vuota, azzera anche rear
        q->rear = NULL;
    }
    free(temp);
    return true;
}

// Stampa i primi N elementi senza modificarli
void printFirstN(const Queue *q, int n) {
    if (n <= 0) {
        printf("Richiesto n=%d: niente da stampare.\n", n);
        return;
    }

    printf("Primi %d valori: ", n);
    const Node *current = q->front;
    int i = 0;
    while (i < n && current != NULL) {
        printf("%d", current->value);
        current = current->next;
        i++;
        if (i < n && current != NULL) {
            printf(" ");
        }
    }
    printf("\n");

    if (i < n) {
        printf("Nota: la coda contiene solo %d elemento%s.\n",
                i, (i == 1 ? "" : "i"));
    }
}

// Libera tutti i nodi della coda e la reimposta vuota
void freeQueue(Queue *q) {
    Node *current = q->front;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    q->front = NULL;
    q->rear  = NULL;
    printf("Memoria liberata.\n");
}

/* ===========================
    Esempio d'uso (main)
   =========================== */

int main(void) {
    int arr[10] = {2, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    Queue q;// Dichiarazione della coda
    initQueue(&q);// Inizializzazione della coda

    // Inserimento degli elementi nell'ordine dato
    for (int i = 0; i < 10; i++) {
        if (!enqueue(&q, arr[i])) {
            fprintf(stderr, "Errore: allocazione memoria fallita su enqueue(%d).\n", arr[i]);
            freeQueue(&q);
            return EXIT_FAILURE;
        }
    }

    // Stampa dei primi 5 e poi dei primi 7 elementi
    printFirstN(&q, 5);
    printFirstN(&q, 7);

    // Esempio opzionale: dequeue di alcuni elementi (decommenta per provare)
    /*
    int value;
    for (int k = 0; k < 3; ++k) {
        if (dequeue(&q, &value)) {
            printf("Dequeue: %d\n", value);
        } else {
            printf("Coda vuota durante il dequeue.\n");
            break;
        }
    }
    printFirstN(&q, 10);
    */

    // Libera la memoria
    freeQueue(&q);

    return EXIT_SUCCESS;
}