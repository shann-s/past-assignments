#include <stdio.h>

int main(void) 
{
	int apples;
	double cash, total, hst, purchase;
	float change;

	printf("There are only 21 apples in the store\nand they are 1.99 each plus taxes how many would you like?\n");
	scanf("%d", &apples);

	if  ( (apples > 21) || (apples < 0) )

	printf("I'm sorry! we don't have enough apples for you!\n");

	else {

	total = apples * 1.99;

	printf("That would be  $%.2lf \n", total);

	hst = total * 0.13;

	printf ("HST (13%) %.2lf\n", hst);

	purchase = hst + total;

	printf("Total purchase price  $%.2lf\n", purchase);

	printf("Cash tendered  $");
	scanf("%lf", &cash);

	if (total > cash) {

	printf("Sorry you don't have enough money to buy!\n");

	}

	else {

	change = cash - total;

	printf("Your change is  $%.2f\n", change);

	}
}

	printf("Please come again!\n");

	return 0;
}
