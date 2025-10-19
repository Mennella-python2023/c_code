#include <stdio.h>

int main() {
    // Declare an array of pointers to integers
    int arr[5] = {0, 10, 20, 30, 40};
    int *array_of_pointers[5] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]};

    // Dereference and print the values using the array of pointers    
    for (int i = 0; i < 5; i++) {
        printf("Value at index %d: %d\n", i, *array_of_pointers[i]);
        printf("Address of arr[%d]: %p\n", i, (void *)array_of_pointers[i]);
    }   
    return 0;
}