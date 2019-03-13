#include <stdio.h>
#define MAX 9

int main(void){

	int number, i, total=0;

	for (i = 1; i <= MAX; i=i+1) {

	printf("Enter a number :\n");
	scanf("%d", &number);

	total = total + number;
	}

	printf("You have entered %d whole numbers\n", MAX);
	printf("Here is the sum %d\n", total);

	return 0;

}
