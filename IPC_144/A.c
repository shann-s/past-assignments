#include <stdio.h>

int main(void) {

	int input, first, second, third, m;

	printf("Please enter a password(3 digits) : \n");
	scanf("%d", &input);
	
	first = input / 100;

	printf("First digit : %d\n", first);

	m = input / 10;
	
	second = m % 10;

	printf("Second digit : %d\n", second);

	third = input % 10;

	printf("Third digit : %d\n", third);

	return 0;
}
