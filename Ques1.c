#include <stdio.h>

int main(){
	int num = 2647203;
	int *ptr;
	ptr = &num;
	
	printf("print using variable %d \n", num);
	printf("value in pointer %p \n", (void *)ptr);
	printf("print using pointer %d \n", *ptr);
	
	return 0;
}
