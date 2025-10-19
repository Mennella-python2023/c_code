#include <stdio.h>

int main() {
    // Declare an array of pointers to integers
    int arr[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int *array_of_pointers[10] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]};

    // Dereference and print the values using the array of pointers
    for (int i = 0; i < 10; i++) {
        printf("Value at index %d: %d\n", i, *array_of_pointers[i]);
        printf("Address of arr[%d]: %p\n", i, (void *)array_of_pointers[i]);
    }

    // Measure memory usage
    printf("\nMemory usage:\n");

    // Size of the array `arr` (array of 5 integers)
    printf("Size of arr: %zu bytes\n", sizeof(arr)); // size of the array `arr`

    // Size of the array of pointers `array_of_pointers` (array of 5 pointers to int)
    printf("Size of array_of_pointers: %zu bytes\n", sizeof(array_of_pointers)); // size of the pointer array

    // Size of each pointer in the array `array_of_pointers`
    printf("Size of each pointer in array_of_pointers: %zu bytes\n", sizeof(array_of_pointers[0])); // size of one pointer

    // Total size of memory used by arr and array_of_pointers
    printf("Total memory used by arr and array_of_pointers: %zu bytes\n", sizeof(arr) + sizeof(array_of_pointers));

    return 0;
}
