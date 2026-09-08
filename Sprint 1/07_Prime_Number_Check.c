#include <stdio.h>
#include <math.h>

int main(){
    int i,no,prime = 1;

    printf("Enter the number : ");
    scanf("%d",&no);
    i = ceil(sqrt(no));

    for (i; i > 1; i--){
        if (no % i == 0){
            prime = 0;
            break;
        }
    }

    if (prime == 1){
        printf("\n\t %d is a Prime",no);
    }
    else{
        printf("\n\t %d is not a Prime",no);
    }

    return 0;
}
