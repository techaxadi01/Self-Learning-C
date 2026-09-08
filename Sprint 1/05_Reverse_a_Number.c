#include <stdio.h>

int main(){
    int i,no,rev_no=0;

    printf("Enter the number : ");
    scanf("%d",&no);

    for (i = no; i > 0; i/=10) {
        rev_no *= 10;
        rev_no += i%10;
    }

    printf("\n\t '%d' in reversed form is '%d'", no, rev_no);

    return 0;
}
