#include <stdio.h>

int main(void){

	int orange;

	printf("Hello! We only have 12 oranges today!\n");
	scanf("%d", &orange);

	while (orange < 0 ) {

	printf("Hello! We only have 12 oranges today!\n");
	scanf("%d", &orange);

	}

	printf("Thank you come again!\n");

	return 0;
}
