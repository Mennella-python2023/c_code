#include <stdio.h>

int main() {
    // Declare an array of pointers to integers
    int *arr[5];

    // Declare some integer variables
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    // Assign the addresses of the integer variables to the array of pointers
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;
    arr[3] = &d;
    arr[4] = &e;

    // Print the values using the array of pointers
    for (int i = 0; i < 5; i++) {
        printf("Value at arr[%d]: %d\n", i, *arr[i]);
    }

    return 0;
}