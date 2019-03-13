#include <stdio.h>

double get_total();

int main(void)
{

	int days, i, g;
	float high, low, avg, t, total, degree, temp;
	char condition, s, c, p;

	printf("Weather Analyzer \n ================\n");

	printf("Please enter a positive amount of days : \n");
	scanf("%d", &days);	/*Prompts the user for a positive amount of days*/

	while (days < 0) { 	/*If user has entered a negeative amount of days then the loop will keep asking the user for a positive amount of days*/

	printf("You have entered a negative amount of days!\n");
	printf("Please enter a positive amount of days : \n");
	scanf("%d", &days);

	}

	g = days;	/*Stores the value "days" to "g"*/

	for (i = 1; i <= g; ++i) {	/*In the loop the Countdown starts at 1 and adds 1 until condition is met which in this case it is the same as days*/

	printf("Enter today's high : ");	/*Prompts the user for today's high temp*/
	scanf("%f", &high);

	printf("Enter today's low : ");		/*Prompts the user for today's low temp*/
	scanf("%f", &low);

	printf("Enter today's conditions (s: sunny, c: cloudy, p: precipitation) : ");	/*Prompts the user for today's conditions*/
	scanf(" %c", &condition);

	t = high + low;	

	avg = t / 2;	/*Calculates for today's weather average by adding high + low then multiplying by the quantity which is 2*/

	total = avg;	/*Stores the value of average into "total"*/

	printf("Today's average temperature is : %.2f\n", avg);

	if (condition == 115)	/*Makes checks if user has entered the correct character for the condition then prints one of the following*/

	printf("@@@@@@@@@@@@@@@@@@@\n");

	if (condition == 99)

	printf("~~~~~~~~~~~~~~~~~~~\n");

	if ((condition == 112) && (avg < 0))	/*If the percipitation and average is below 0 then it prints this*/

	printf("*******************\n");

	if ((condition == 112) && (avg > 0))	/*If the precipitation and average is above 0 then it prints this*/

	printf(";;;;;;;;;;;;;;;;;;;\n");

	temp = temp + total;	/*first day adds total to temp value and stores it, in the upcoming days total adds into temp value and creates the new value for temp*/

	}

	degree = temp / days;	/*Averages the total amount of days and degrees by dividing the total temp by the amount of days*/

	printf("Average for all %d days is: %.2f degrees\n", days, degree); 

	return 0;
}
