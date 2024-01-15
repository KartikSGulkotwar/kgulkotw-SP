#include <stdio.h>

int main()
{
    int given_number;
    printf("Enter the number : ");
    scanf("%d", &given_number);
    
    if(given_number % 2 == 0)
        printf("The number is an even number.");
    else
        printf("The number is an odd number.");
    return 0;
}
