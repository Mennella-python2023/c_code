
#include <stdio.h>

int main() {
    int num, i;

    // Ask the user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Display multiplication table
    printf("Multiplication table for %d:\n", num);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}
