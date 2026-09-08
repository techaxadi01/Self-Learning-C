#include <stdio.h>

int main() {
	int i, j, no, temp, num[100] = {0};

	printf("Enter the no of Elements: ");
	scanf("%d", &no);

	printf("Enter the Elements: ");
	for (i = 0; i < no; i++) {
		scanf("%d", &num[i]);
	}

	for (i = 0; i < no - 1; i++) {
		for (j = 0; j < no - i - 1; j++) {
			if (num[j] > num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	printf("Array in Ascending Order: ");
	for (i = 0; i < no; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
}
