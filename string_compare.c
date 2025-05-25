
#include <stdio.h>

// Function to compare two strings character by character
int stringCompare(char *strA, char *strB)
{
    int i;
    for (i = 0; strA[i] != 0 && strB[i] != 0; i++)
    {
        if (strA[i] > strB[i])
        {
            return 1; // strA is greater
        }
        else if (strA[i] < strB[i])
        {
            return -1; // strB is greater
        }
    }

    // If both strings reach null terminator at the same time
    if (strA[i] == 0)
    {
        if (strB[i] == 0)
            return 0; // Strings are equal
        else
            return -1; // strB is longer
    }
    else
        return 1; // strA is longer
}

int main(void)
{
    // Comparing different string pairs
    int result1 = stringCompare("AAC", "BBB");  // AAA < BBB → returns -1
    int result2 = stringCompare("AAC", "AAB");  // AAC > AAB → returns 1
    int result3 = stringCompare("AAC", "AAC");  // Equal → returns 0
    int result4 = stringCompare("AAC", "AACC"); // AAC < AACC → returns -1
    
    // Print results
    printf("result1: %d\n", result1);
    printf("result2: %d\n", result2);
    printf("result3: %d\n", result3);
    printf("result4: %d\n", result4);
    
    return 0;
}
