#include <stdio.h>

int main(){
    int no;
    printf("Enter the number : ");
    scanf("%d",&no);

    if (no < 0){
        printf("\n\t %d is Negative \n", no);
    }

    else if (no > 0) {
        printf("\n\t %d is Posivite \n", no);
    }

    else {
        printf("\n\t The number is 0");
    }

    return 0;
}
