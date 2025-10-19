
#include <stdio.h>

// Funzione ricorsiva tail-recursive che calcola la somma da 1 a n
int sum_tail(int n, int acc) {
    if (n == 0)
        return acc;
    else
        return sum_tail(n - 1, acc + n);
}

int main() {
    // Test della funzione sum_tail
    int n1 = 5;
    int n2 = 10;
    int n3 = 0;

    printf("Somma da 1 a %d = %d\n", n1, sum_tail(n1, 0)); // 15
    printf("Somma da 1 a %d = %d\n", n2, sum_tail(n2, 0)); // 55
    printf("Somma da 1 a %d = %d\n", n3, sum_tail(n3, 0)); // 0

    return 0;
}
