#include <stdio.h>

int main(){
    int i,no;
    int frq[10] = {0};

    printf("Enter the number : ");
    scanf("%d",&no);

    if (no == 0) {
        frq[0] = 1;
    }

    while (no != 0) {
        frq[(no % 10)]++;
        no /= 10;
    }

    for (i = 0; i < 10; i++){
        printf("\n\t Frequency of '%d' = %d", i, frq[i]);
    }

    return 0;
}
