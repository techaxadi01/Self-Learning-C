#include <stdio.h>

int main(){
    int i,no,rev_no=0;

    printf("Enter the number : ");
    scanf("%d",&no);
    i = no;

    do {
        rev_no *= 10;
        rev_no += i%10;
        i /= 10;
    } while (i > 0);

    if (no == rev_no) {
        printf("\n\t '%d' is a palindrome number.", no);
    } else {
        printf("\n\t '%d' is not a palindrome number.", no);
    }

    return 0;
}
