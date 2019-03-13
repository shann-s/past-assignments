#include <stdio.h>
#define MAX 100

void calc_values( double prc[], int qty[], double val[], int num);

void show_table( long long bcode[], double prc[], int qty[], double val[], int num);

int main(void) {
	
	long long barcode[MAX];
	double price[MAX];
	int quantity[MAX];
	double values[MAX];
	int counter;
	long long b;

	counter = 0;

	printf("Grocery Store Inventory\n");
	printf("=======================\n");

	b = 1;

	while (b != 0) {	//Prompts the user for array information

	printf("Barcode  :  ");
	scanf("%lld", &b);

		if (b != 0) {

			barcode[counter] = b;

			printf("Price  :  ");
			scanf("%lf", &price[counter]);

			printf("Quantity  :  ");
			scanf("%d", &quantity[counter]);

			counter = counter + 1;
	
		}
	}

	calc_values(price, quantity, values, counter);		//Calls function to calculate the total of price and quantity

	show_table(barcode, price, quantity, values, counter);		//Prints the Table of the barcode, price, quantity, and value

	return 0;
}

void calc_values( double prc[], int qty[], double val[], int num) {

	int i;

	i = 0;

	for(i = 0; i <  num; i++) {	//Calculates each price and quantity in the array

	val[i] = prc[i] * qty[i];

	}

}

void show_table( long long bcode[], double prc[], int qty[], double val[], int num) {

	int a;
	
	a = 0;

	printf("          Goods in Stock\n");
	printf("          ==============\n");

	printf("Barcode      Price      Quantity   Value\n");
	printf("----------------------------------------\n");

	for(a = 0; a < num; a++) {		//Prints all the information collected and calculated

	printf("%lld   %.2lf        %d        %.2lf\n", bcode[a], prc[a], qty[a], val[a]);

	}

}
