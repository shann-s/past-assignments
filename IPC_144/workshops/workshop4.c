#include <stdio.h>

int get_principal();

double get_rate();

int get_years();

double calc_future_value (int base, double rate, int years);

void display_result (double answer);

int main(void) {

	double rate, fv;
	int years, base;

	printf("Investment calculator\n ======================\n");

	base=get_principal(); 	/*Calls for function get_principal() and stores value into base*/
	rate=get_rate();	/*Calls for function get_rate() and stores value into rate*/
	years=get_years();	/*Calls for function get_years() and stores value into years*/

	fv=calc_future_value(base, rate, years);	/*Calls for func calculation then store value into fv*/

	display_result(fv);	/*Calls for function to display and displays the result from calculation in fv*/
	
	return 0;
}

int get_principal()
{
	int b;	/*declares value for principal*/

	printf("Principal : ");

	scanf("%d", &b);	/*Prompts user for principal value*/

	return b;

}

double get_rate()
{
	double r;	/*Declares value for rate*/

	printf("Annual rate : ");

	scanf("%lf", &r);	/*Prompts user for rate*/

	return r;
}

int get_years()
{

	int y;	/*Declares value for years*/

	printf("No of years : ");

	scanf("%d", &y);	/*Prompts user for years*/

	return y;

}

double calc_future_value (int base, double rate, int years)
{

	double answer, x;
	int i;
	x = 1;
	for (i = 0; i < years; i++) {	/*Exponential: The rate + 1 by the power of years. Calculate rate for ___ years*/
		x = x * (1 + rate);
	}

	answer = base * x;

	return answer;

}

void display_result (double answer) 
{

	printf("The future value is : $%.2lf\n", answer);	/*Displays the answer from func calc_future_value*/

}
