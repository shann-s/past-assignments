#include <stdio.h>

int get_numerator();

int get_denominator();

int calc_gcd(int x, int y);

void simplify(int *a, int *b);

int main (void) {

	int x, y;
	int  num, den;

	printf("Fraction Simplifier \n =================== \n");
	
	num=get_numerator();	//Stores numerator func value in "num" 
	den=get_denominator();	//Stores numerator func value in "den"

	x = num;	//Stores the same value of num into x to simplify it. To keep "num" value as original
	y = den;	//Stores the same valu of den into y to simplify it. Keeping the "den" value original to use for later
	
	simplify(&x, &y);	//Calls function and gets the values from x and y to simplify and stores the pointer *a and *b to x and y.

	printf ("%d / %d = %d / %d \n", num, den, x, y);	//Prints the results for the simplified form but also showing the origninal fraction.
	return 0;
}

int get_numerator() {		//Prompts the user fo the numerator

	int n;

	printf("Numerator: ");
	scanf("%d", &n);

	return n;

}

int get_denominator() {		//Prompts the user for the denominator.

	int d;

	printf("Denominator: ");
	scanf("%d", &d);
	
	return d;
}

int calc_gcd(int x, int y) {

	int temp;

	while (y != 0) {	//Calculates for the greatest common factor.

	temp = x % y;
	x = y;
	y = temp;
	}

	return x;

}

void simplify(int *a, int *b) {

	int temp, gcd,  num, den;	//Declares the parameters being used

	num = *a;	//Stores values of *a into num
	den = *b;	//Stores values of *b into den

	gcd = calc_gcd(num, den);	//Calls function and uses parameters num and den to calculate. Then store it into "gcd".

	num = num / gcd;	//Calculates for the simplified numerator

	den = den / gcd;	//den divided by greatest common factor 

	*a = num;	//Stores the simplified values to *a and *b pointers.
	*b = den;
	return;
}
