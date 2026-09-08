#include <stdio.h>

int main(){
    int a,b,c;

    printf("Enter the a : ");
    scanf("%d",&a);
    printf("Enter the b : ");
    scanf("%d",&b);
    printf("Enter the c : ");
    scanf("%d",&c);

    if (a >= b && a >= c){
        printf("\n\t %d is the largest \n", a);
    }
    else if (b >= a && b >= c){
        printf("\n\t %d is the largest \n", b);
    }
    else {
        printf("\n\t %d is the largest \n", c);
    }

    return 0;
}
