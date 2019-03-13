
/* functions with parameters */

#include <stdio.h>

int add(int a, int b);

int minus(int x, int y);

int main(void) {

    int num1, num2, answer;

    num1 = 111;
    num2 = 222;

    answer = add(num1, num2);   /* function call */

    printf( "1. answer = %d\n", answer );

    answer = minus(num1, num2); /* function call */

    printf( "2. answer = %d\n", answer );

    return 0;
}

int add(int a, int b) {

	int sum;

	sum = a + b;

	return sum;
}

int minus(int x, int y) {

	int diff;

	diff = x - y;

	return diff;
}