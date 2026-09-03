#include <stdio.h>

int main(){
	float c;
    printf ("Enter C \n");
    scanf ("%f",&c);
    printf("F = (9.0/5.0)*C + 32 = %.2f\n", (((9.0/5.0)*c) + 32) );
    return 0;
}
