
#include <stdio.h>

int maxZeriConsecutivi(char str[]) {
    int maxLen = 0, currentLen = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            currentLen++;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            currentLen = 0;
        }
    }

    return maxLen;
}

int main() {
    char str[] = "10011000010111000";
    int maxZeri = maxZeriConsecutivi(str);
    printf("La lunghezza massima della sottosequenza di '0' consecutivi è: %d\n", maxZeri);

    return 0;
}
