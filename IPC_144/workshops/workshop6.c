#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (void) {

	int sought, throw, a, b, n, total;

	printf("Game of dice\n ==========\n");

	printf("Enter total sought  ");
	scanf("%d", &sought);

	throw = 0;

	while (sought > 12) {		//Prompts user for a number sought equal to or less than 12

		printf("** Invalid Input! Try Again! **\n");

		printf("Enter total sought  ");
		scanf("%d", &sought);

	}

	srand(time(NULL));	//Generates random seed number everytime program is run.

	while ( sought != total ) {	//Runs the loop until the sought number is equal to the total of a + b

		throw = throw + 1;

		a = (rand() % 12) + 1;

		b = (rand() % 12) + 1; 

		printf("Result of throw %d : %d + %d\n", throw, a, b);		//Displays result if the number of times thrown and the two random numbers generated.

		total = a + b;

	}

	printf("You got your total in %d throws!\n", throw);		//Displays the number of times the while loop has run with the throws

	return 0;
}
