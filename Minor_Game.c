#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int Random_No, No_of_Guess = 0, Guess;

	srand((unsigned int)time(NULL));
    Random_No = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game! \n\n");

    while (1) {
        printf("\n");
        printf("Guess the No. : ");
        scanf("%d", &Guess);

        if (Guess < Random_No) {
            printf("Your Guess is lower than the Number. Go Higher! \n");
            No_of_Guess += 1;
        }
        else if (Guess > Random_No) {
            printf("Your Guess is greater than the Number. Go Lower! \n");
            No_of_Guess += 1;
        }
        else {
            printf("Congrats !!! You guessed right in %d attempts. \n", No_of_Guess);
            printf("The Number was : %d \n\n", Random_No);
            break;
        }
    }

	return 0;
}
