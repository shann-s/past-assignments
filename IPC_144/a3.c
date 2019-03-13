#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*V 1.1:
Changes:

1) declared i outside of loop, you don't need -std=c99 to compile anymore
2) added a check for existence of historicaldata.csv
*/

/*an instance of this struct holds the weather data for a single day*/
struct DailyData{
    int day;
    int month;
    int year;
    float high;
    float low;
    float precipitation;
    char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/
struct MonthlyStatistic{
    float minTemperature;
    float maxTemperature;
    float averageTemperature;
    float totalPrecipitation;
};
int readDailyData(FILE* fp, struct DailyData allData[]);

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],
                    int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw( char c, int num );


int main(void){
    FILE* fp = fopen("historicaldata.csv","r");
    if(!fp){
        printf("you need to put historicaldata.csv into this directory\n");
        exit(0);
    }
    struct DailyData  allData[3000];
    struct DailyData yearData[366];
    int numTotalRecords;

    numTotalRecords = readDailyData(fp, allData);
    int year;
    int reportType;
    int i;
    struct MonthlyStatistic monthly[12];
    printf("Please enter the year for the report: ");
    scanf("%d",&year);
    printf("Please enter the type of report you wish to generate:\n");
    printf("1) summary\n");
    printf("2) detailed\n");
    scanf("%d",&reportType);
    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);
    sortYearData(yearData,numDays);

    for(i=0;i<12;i++){
        getStats(i+1,yearData,numDays,&monthly[i]);
    }

    printf("Weather summary for %d\n",year);
    printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
    printf("|-----------|-------|-------|-------|---------|\n");
    for(i=0;i<12;i++){
        printMonthlyStatistic(i+1,&monthly[i]);
    }
    printf("\n\n");
    printf("Precipitation Graph\n\n");
    for (i=0;i<12;i++){
        graphLine(i+1,&monthly[i]);
    }
    if(reportType == 2){
        printf("\n\n");
        printf("Detailed report:\n");
        printVerbose(yearData,numDays);
    }
    return 0;
}
int readDailyData(FILE* fp, struct DailyData allData[]){
    int i=0;
    while(fscanf(fp,"%d,%d,%d,%f,%f,%f,%c\n",
        &allData[i].year,&allData[i].month,&allData[i].day,
        &allData[i].high,&allData[i].low,&allData[i].precipitation,
        &allData[i].condition) == 7){
        i++;
    }
    return i;
}
int getRelevantRecords(int yearWanted, const struct DailyData allData[], 
                                    int sz,  struct DailyData yearData[]){
	int k, s=0, a, b, c;

	for (k = 0; k <= sz; k++) {

		if (allData[k].year == yearWanted){

				yearData[s].year = allData[k].year;
				yearData[s].day = allData[k].day;
				yearData[s].high = allData[k].high;
				yearData[s].low = allData[k].low;
				yearData[s].precipitation = allData[k].precipitation;
				yearData[s].condition = allData[k].condition;
				yearData[s].month = allData[k].month;

				s++;
			}
		}

	a = s / 1;

	b = a % 10;

	if (b == 6) {
	
		c = 366;
		return c;

	}else if (b == 5) {

		c = 365;
		return c;

	}


	//Finds the yearWanted to match the year in alldata then puts all the data in the yearData array.

}

void sortYearData(struct DailyData yearData[], int sz){

     	int i, j;

	struct DailyData temp;

	for (i = 0; i < sz; i++){

		for(j = 0; j < (sz - 1) ; j++) {

			if (yearData[j].month > yearData[j + 1].month){

				temp = yearData[j];
				yearData[j] = yearData[j+1];
				yearData[j+1] = temp;
			}

			if (yearData[j].month == yearData[j + 1].month) {
						
				if (yearData[j].day > yearData[j + 1].day) {

					temp = yearData[j];
					yearData[j] = yearData[j+1];
					yearData[j+1] = temp;
				}

			}
			
		}
	}

	//Sorts all the months in the yearData and sorts days when the month equals
}

void getStats(int month, const struct DailyData yearData[],
                    int sz,struct MonthlyStatistic* monthly){

	int i, s, b, c;

	float high, low, avg;

	s = 0;
	low = 0;
	high = 0;
	avg = 0;
	monthly->maxTemperature = -20;
	monthly->minTemperature = 20;

	for (i = 0; i < sz; i++){

		if (yearData[i].month == month){

			if (yearData[i].high > monthly->maxTemperature){

				monthly->maxTemperature = yearData[i].high;
			}
			if (yearData[i].low < monthly->minTemperature){

				monthly->minTemperature = yearData[i].low;
			}

			monthly->totalPrecipitation += yearData[i].precipitation;

			monthly->averageTemperature += average(yearData[i].low, yearData[i].high); 
	s = s + 1;
		}
	}

	monthly->averageTemperature = monthly->averageTemperature / s;

	//Puts the highest and lowest temp into monthly struct and adds precipitation into the monthly struct then finally in the monthly struct the "s" counter which is the days in the month divides the added max and min temperature.
}
void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly){

	char* months[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	printf("| %9s | %-5.1f | %-5.1f | %-5.1f | %-7.1f |\n", months[month-1],  monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature, monthly->totalPrecipitation);

	//Prints the row of the weather summary. in the monthly weather struct
}
void graphLine(int month,const struct MonthlyStatistic* monthly){

	float b;

	int i;

	char* months[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	b = monthly->totalPrecipitation / 10;

	if (b > 0.50){

		b = b + 0.50;

	}

	printf(" %9s |", months[month-1]);

	for (i = 0; i < (int) b; i++){

		printf("*");

	}

	printf("\n");

	//Divides the total precipitation by 10 and checks to see if it will be greater than 5. If greater than 5 it will round up then prints the total precip by 10s in *
}
void printVerbose(const struct DailyData allData[],int sz){

	int i;

	float avg;

	char* months[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	

	for(i = 0; i < sz; i++){

		avg = average(allData[i].low, allData[i].high);

		printf("%5s %5d %d: %5.1f ", months[allData[i].month-1], allData[i].day, allData[i].year, avg);

		draw(symbolToDraw(allData[i].condition, avg), 20);
	}

	//In detailed report prints the month name declared by the array and the counter is the number of months in the alldata struct. And in the loop gets the average of the allData to calculate for the detailed report and finally prints the character by getting the condition in the year data and printing it 20 times.
}
char symbolToDraw(char condition, float avgTemp){

	if (condition == 115) {

		return '@';

	}

	if (condition == 99) {

		return '~';

	}

	if ((condition == 112) && (avgTemp < 0)) {

		return '*';

	}

	if ((condition == 112) && (avgTemp > 0)) {

		return ';';

	}
       
	//Finds which symbol to draw based on the allData struct condition
}
float average(float first, float second){
    
	float sum, average;

	sum = first + second;

	average = sum / 2;

	return average;
	
	//Takes the first and second float then divides it by 2. Total divided by quantity, the amount of variables
}
void draw( char c, int num ){

	int a = 0;

	for (a = 0; a <= num; a++){

		printf("%c", c);

	}
       
	printf("\n");

	//Draws the specified chearacter
}
