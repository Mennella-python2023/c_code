
#include <stdio.h>

int main() {
    char word[100], reversed[100]; // Declare a string big enough for long words
    int i, length = 0;

    printf("Enter a word: ");
    scanf("%s", word);

    // Determine the length without strlen
    while (word[length] != '\0') {
        length++;
    }

    // Reverse the word
    for (i = 0; i < length; i++) {
        reversed[i] = word[length - i - 1];
    }
    reversed[length] = '\0'; // Null-terminate the reversed string

    printf("Reversed word: %s\n", reversed);

    return 0;
}
