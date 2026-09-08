#include <stdio.h>
#include <limits.h>

int main() {
	int i,no;
    int num[100] = {0};
    int h1 = INT_MIN, h2 = INT_MIN;

	printf("Enter the no of Elements: ");
	scanf("%d", &no);

	printf("Enter the Elements: ");
	for (i = 0; i < no; i++) {
		scanf("%d", &num[i]);
	}

    for (i = 0; i < no; i++){
        if (h1 < num[i]){
            h2 = h1;
            h1 = num[i];
        }
    }

    if (no == 1){
        h2 = h1;
        printf("\n\t Since there is only 1 Element");
    }

    printf("\n\t The Second Highest No is : %d", h2);

	return 0;
}
