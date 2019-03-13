#include <stdio.h>

int main(void)
{

	int input,input1, input2, input3, s1, s2, s3, first, third, sixth;

	printf ("Enter a password (7 digits) :\n");
	scanf ("%d", &input);

	first = input / 1000000;

	printf("Enter the first digit : ");
	scanf("%d", &input1);

	if (input1 == first) {

		printf("Correct\n");

	}

	else {

		printf("Incorrect number\n");

	}

	third = input / 10000;
	s1 = third % 10;

	printf("Enter the third digit : ");
	scanf("%d", &input2);

	if (input2 == s1) {

		printf("Correct\n");

	}

	else {

		printf("Incorrect number!\n");

	}

	sixth = input / 10;
	s2 = sixth % 10;

	printf("Enter the sixth digit : ");
	scanf("%d", &input3);

	if (input3 == s2) {

		printf("Correct!\n");

	}

	else {

		printf("Incorrect number!\n");

	}

	if (input1 == first) {

	printf("Sorry, you have made 2 mistakes\n");

	}

	if (input2 == s1) {

	printf("Sorry, you have made 2 mistakes\n");

	}

	if (input3 == s2) {

	printf("Sorry, you have made 2 mistakes\n");

	}

	if ((input1 == first) && (input2 == s1) && (input3 == s2)) {

	printf("You have passed the security check!\n");

	}
	
	else {

		if ((input1 == first) && (input2 == s1)) {

		printf("Sorry, You have made 1 mistake!\n");

		}

			if ((input1 == first) && (input3 == s2)) {

			printf("Sorry, you have made 1 mistake!\n");

			}

				if ((input2 == s1) && (input3 == s2)) {

				printf("Sorry, you have made 1 mistake!\n");
		
				}

	}
	
	return 0;
}
