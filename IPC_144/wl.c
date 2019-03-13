#include <stdio.h>

int main(void){

	int select, b, i;

	printf("Welcome!\n");
	printf("==========\n");
	
	printf("Please select a number between 1 - 10\n");
	scanf("%d", &select);

	while((select > 10) && (select < 0)){

		printf("while loop");

		printf("==ERROR==\n");
		printf("Please try again!\n");
		scanf("%d", &select);


	}

	printf("After loop");

	b = 1;

	i = 0;

	while (i < b) {

		i = i + 1;

		b = b + 2;

		printf("i : %d = %d\n", i, b);


	}



	return 0;
}
