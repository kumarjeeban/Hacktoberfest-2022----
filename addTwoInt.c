#include <stdio.h>

// function to add two integers in c
int main() {    
    int number1, number2, sum;
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);
    sum = number1 + number2;      
    printf("%d + %d = %d", number1, number2, sum);
    return 0;
}
