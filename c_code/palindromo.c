#include <stdio.h>
#include <string.h>

int main() {
    char word[100];       // Declare a string big enough for long words
    char reversed[100];   // To store the reversed word
    int length, i;

    printf("Enter a word: ");
    scanf("%s", word);    // Read the word (no spaces)

    length = strlen(word);

    // Reverse the word
    for (i = 0; i < length; i++) {
        reversed[i] = word[length - 1 - i];
    }
    reversed[length] = '\0';  // Null-terminate the reversed string

    printf("%s\n", reversed); // Print the reversed word

    return 0;
}
