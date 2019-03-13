#include <stdio.h>
#define MAX 100

/* calculate the values of all the items */
/* input parameters: prc, qty, num
   output parameter: val
 */
void calc_values( double prc[], int qty[], double val[], int num );

/* display the table */
/* input parameters: bcode, prc, qty, val, num
   output parameter: NONE
 */
void show_table( long long bcode, double prc[], int qty[], double val[], int num );

int main(void){

    long long barcode[MAX];
    double    price[MAX];
    int       quantity[MAX];
    int       values[MAX]
    int       counter;

    counter = 0;

    /* use a while loop (or do-while loop) to get user input and fill up the arrays */
    /* use "%lld" to read or print a long long integer */



    /* function calls: use of array names */

    calc_values(price, quantity, values, counter);

    show_table(barcode, price, quantity, values, counter);

    return 0;
}
