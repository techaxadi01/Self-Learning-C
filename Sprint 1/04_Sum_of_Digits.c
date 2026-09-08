#include <stdio.h>

int main(){
    int i,no,sum=0;

    printf("Enter the number : ");
    scanf("%d",&no);

    for (i = no; i > 0; i/=10) {
        sum += i%10;
    }

    printf("\n\t The sum of digits of '%d' is '%d'", no, sum);

    return 0;
}
