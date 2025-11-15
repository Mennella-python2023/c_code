#include <stdio.h>

// Function declaration
double square(double x);

// Function definition
double square(double x) {
    return x * x;
}

int main() {
    // Test values
    double values[] = {2.0, 6.0, 2.5, 12.12, 345.68, -3.5, 0.0, 1.414};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        printf("square of %.2f is %.2f\n", values[i], square(values[i]));
    }

    return 0;
}
