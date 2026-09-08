#include <stdio.h>

int main(){
    int i,no,a,b,x;

    printf("Enter the number of elements : ");
    scanf("%d",&no);

    a = 0, b = 1;
    printf("%d, %d, ", a, b);
    for (i = 2; i <= no; i++)
    {
        (i != no) ? printf("%d, ", a + b) : printf("%d", a + b);
        b += a;
        a = b - a;

        /*
        Same as
        x = a + b;
        a = b;
        b = x;
        */
    }

    return 0;
}