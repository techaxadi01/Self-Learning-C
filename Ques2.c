#include <stdio.h>

int main(){
	int num1 = 10, num2 = 20;
	int *ptr1 = &num1, *ptr2 = &num2;
	
	printf("Before swap \n");
	printf("\t Num 1: %d \n", *ptr1);
	printf("\t Num 2: %d \n", *ptr2);
	
	*ptr1 += *ptr2;
	*ptr2 = *ptr1 - *ptr2;
	*ptr1 -= *ptr2;
	
	printf("After swap \n");
	printf("\t Num 1: %d \n", *ptr1);
	printf("\t Num 2: %d \n", *ptr2);
	
	return 0;
}
