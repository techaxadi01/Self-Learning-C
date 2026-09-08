#include <stdio.h>

int main(){
    int i,no;
    long fact=1;

    printf("Enter the number : ");
    scanf("%d",&no);

    for (i = no; i > 0; i--)
    {
        fact *= i;
    }
    
    printf("\n\t Factorial of %d, %d! = %d", no, no, fact);

    return 0;
}
