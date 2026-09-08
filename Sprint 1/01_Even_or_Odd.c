#include <stdio.h>

int main(){
    int no;
    printf("Enter the number : ");
    scanf("%d",&no);

    if (no%2 == 0){
        printf("\n\t %d is Even \n", no);
    }

    else {
        printf("\n\t %d is Odd \n", no);
    }

    return 0;
}
