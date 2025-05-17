#include <stdio.h>

int contaOccorrenze(char str[], char c) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[] = "programmazione";
    char c = 'o';

    int occorrenze = contaOccorrenze(str, c);
    printf("Il carattere '%c' appare %d volte nella stringa.\n", c, occorrenze);

    return 0;
}

