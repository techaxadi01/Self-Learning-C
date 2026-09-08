#include <stdio.h>

int main(){
    int i,no;

    printf("Enter the number : ");
    scanf("%d",&no);

    for (i = 1; i <= 10; i++)
    {
        printf("\n\t %d x %d = %d", no, i, no*i);
    }

    return 0;
}