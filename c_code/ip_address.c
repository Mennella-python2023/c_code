#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValidPart(const char *part) {
    int len = strlen(part);
    if (len == 0 || len > 3) return 0;

    // No non-digit characters
    for (int i = 0; i < len; ++i) {
        if (!isdigit(part[i])) return 0;
    }

    // No leading zeros unless single digit 0
    if (len > 1 && part[0] == '0') return 0;

    // Convert to integer and check range
    int value = atoi(part);
    if (value < 0 || value > 255) return 0;

    return 1;
}

int main(void) {
    char IPAddress[100];
    char *parts[4];
    int partCount = 0;

    printf("Enter an IPv4 address: ");
    scanf("%99s", IPAddress);

    // Make a copy to tokenize
    char IPcopy[100];
    strcpy(IPcopy, IPAddress);

    char *token = strtok(IPcopy, ".");
    while (token != NULL && partCount < 4) {
        if (!isValidPart(token)) {
            printf("Error: not a valid address.\n");
            return 1;
        }
        parts[partCount++] = token;
        token = strtok(NULL, ".");
    }

    // If not exactly 4 parts or extra tokens exist
    if (partCount != 4 || token != NULL) {
        printf("Error: not a valid address.\n");
        return 1;
    }

    // Construct outputs
    char last3[100], last2[100], last1[100];
    snprintf(last3, sizeof(last3), "%s.%s.%s", parts[1], parts[2], parts[3]);
    snprintf(last2, sizeof(last2), "%s.%s", parts[2], parts[3]);
    snprintf(last1, sizeof(last1), "%s", parts[3]);

    printf("Last 3 parts: %s\n", last3);
    printf("Last 2 parts: %s\n", last2);
    printf("Last 1 part: %s\n", last1);

    return 0;
}
