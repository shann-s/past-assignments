#include <stdio.h>

int getInteger(int min, int max);

void getDailyData( float* high, float* low, char * condition);

void draw( char c, int num);

float average(float first, float second);

void displayResult( int days, float allDaysAverage );

char symbolToDraw(char condition, float averageTemperature);

void clear(void);

int main(void) {

	int numDays;

	int i;

	float sum = 0;
	float dailyHigh;

	float dailyLow;

	char conditions;

	float dailyAvg = 0;

	printf("Weather Analyzer 2.0\n ");
	printf("====================\n");

	printf("How many days of data?\n");

	numDays = getInteger(1,14);


	for (i = 0; i < numDays; i++){
		
		getDailyData (&dailyHigh, &dailyLow, &conditions);
		
		dailyAvg = average(dailyHigh, dailyLow);


		printf("Today's average temperature is: %.2f\n", dailyAvg);

		sum += dailyAvg;
		
		draw(symbolToDraw(conditions, dailyAvg), 20);
	}

	displayResult(numDays, (sum/numDays));
 
	return 0;
}

int getInteger(int min, int max) {
	
	int i;

	printf("Enter an integer between 1 and 14: ");
	scanf("%d", &i);

	while ((i > max) || (i < min)) {

		printf("Error! Try again!\n");
		printf("Enter an integer between 1 and 14: ");
		scanf("%d", &i);

	}

	return i;
}

void getDailyData( float* high, float* low, char * condition){


	float hi, lo;
	char con;
	int rc, keeptrying = 1;

	do {

	printf("Enter today's high, low, and condition (c=cloudy, s=sunny, p=precipitation)\nSeparated by commas : ");

	rc = scanf("%f,%f, %c", &hi, &lo, &con);
	
	if ( rc != 3) {

		printf("ERROR! TRY AGAIN! Bad char");
		clear();

	} else if ((con != 's') && (con != 'c') && (con != 'p')){
		
		printf("Error! Try again!\n");
		clear();

	} else if( lo > hi) {

		printf("Error! Try again!\n");

	} else
	
	 	keeptrying = 0;

	} while (keeptrying == 1);

	*high = hi;
	*low = lo;
	*condition = con;
}

float average(float first, float second) {

	float sum, average;

	sum = first + second;

	average = sum / 2;

	return average;
}

char symbolToDraw(char condition, float averageTemperature) {

	if (condition == 115) {

		printf("@");

		return '@';

	}

	if (condition == 99) {

		printf("~");

		return '~';	

	}

	if ((condition == 112) && (averageTemperature < 0)) {

		printf("*");

		return '*';

	}

	if ((condition == 112) && (averageTemperature > 0)) {
	
		printf(";");

		return ';';

	}
}

void draw(char c, int num) {
	
	int a = 0;

	for (a = 0; a <= num; ++a) {
	
		printf("%c", c);

	}

	printf("\n");

}

void displayResult( int days, float allDaysAverage) {

	if (days == 1 ) {

		printf("Your one day average is %.2f\n", allDaysAverage);

	}

	if (days == 2) {

		printf("Your two days average is %.2f\n", allDaysAverage);

	}

	if (days == 3) {

		printf ("Your three days average is %.2f\n", allDaysAverage);

	}

	if (days == 4) {

		printf("Your four days average is %.2f\n", allDaysAverage);

	}

	if (days == 5) {

		printf("Your five days average is %.2f\n", allDaysAverage);

	}

	if (days == 6) {

		printf("Your six days average is %.2f\n", allDaysAverage);

	}

	if (days == 7) {

		printf("Your seven days average is %.2f\n", allDaysAverage);

	}

	if (days == 8) {

		printf("Your eight days average is %.2f\n", allDaysAverage);

	}

	if (days == 9) {

		printf("Your nine days average is %.2f\n", allDaysAverage);

	}

	else 
		printf("Your %d day average is %.2f", days, allDaysAverage);
}

void clear(void) {

	while (getchar() != '\n');

}
