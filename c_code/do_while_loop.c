#include <stdio.h>

int main(void) {
    int n, line = 1;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if(n <= 1)
        n = 1;
    else if(n > 20)
        n = 20;
        
    do{
        int pair = 1;
        do{
            printf("*#");
            pair++;
            
        }while (pair <= line);
        
        printf("\n");
        line++;
    }while(line <= n);
    
    return 0;
}
   



