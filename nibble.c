
#include <stdio.h>
int main(){
    int number;
    scanf("%d", &number);
    int high_nibble = (number >> 4) & 0x0F;
    int low_nibble = number & 0x0F;

    printf("H nibble: %d\n", high_nibble);
    printf("L nibble: %d\n", low_nibble);
    
    return 0;
}