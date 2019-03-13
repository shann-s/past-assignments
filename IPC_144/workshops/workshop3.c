#include <stdio.h>

int main(void)
{

	int input,input1, input2, input3, s1, s2, first, third, sixth;

	printf ("Enter a password (7 digits) :\n");
	
	scanf ("%d", &input);				/*Prompts the user for a password*/

	first = input / 1000000;			/*Divides the input to a single digit which gets the answer to the first digit*/

	printf("Enter the first digit : ");
	
	scanf("%d", &input1);				/*Prompts the user for the first digit*/

	if (input1 == first) {				/*If the first digit and input is the same as the calculation then it will print correct*/

		printf("Correct\n");

	}

	else {						/*If the user's input and first digit is not the same else it puts the message incorrect number*/

		printf("Incorrect number\n");

	}

	third = input / 10000;
	
	s1 = third % 10;				/*Calculates for the third digit. Using modulus after the division of the third digit*/

	printf("Enter the third digit : ");
	
	scanf("%d", &input2);				/*Prompts the user for the third digit*/

	if (input2 == s1) {				/*If the third digit and the user input is the same it prints correct...*/

		printf("Correct\n");

	}

	else {						/*Else it prints "Incorrect number!"*/

		printf("Incorrect number!\n");

	}

	sixth = input / 10;
	
	s2 = sixth % 10;				/*Calculates the sixth number with the same formula as the third digit but in 10 for the sixth digit using modulus*/

	printf("Enter the sixth digit : ");
	
	scanf("%d", &input3);				/*Prompts the user for the sixth digit*/

	if (input3 == s2) {				/*If the input and the calculation is the same it prints correct*/

		printf("Correct!\n");

	}

	else {

		printf("Incorrect number!\n");		/*If the input and calculation is not the same it then prints else "Incorrect number!"*/

	}

	if ((input1 == first) && (input2 == s1) && (input3 == s2)) {		/*If the input for all 3 prompts are correct it says you passed the security check*/

	printf("You have passed the security check!\n");

	}

	else {								/*Else it check for all the possiblities of mistakes in the security check*/

	
	if ((input1 == first) && (input2 == s1)) 			/*Makes checks for 2 correct inputs to display the incorrec input and display 1 mistake*/
	{

		printf("Sorry, You have made 1 mistake.\n");
	}


		else 
		{
			if ((input1 == first) && (input3 == s2)) 

			printf("Sorry, you have made 1 mistake.\n");
			
				else 
			{
		
					if ((input2 == s1) && (input3 == s2)) 

					printf("Sorry, you have made 1 mistake.\n");
					
						else 				/*If the doesn't make 1 mistake it checks for 2 which the machine only checks 1 correct input*/
				{
				
							if (input1 == first)			/*Makes checks for 1 correct input to display 2 mistakes*/

							printf("Sorry, you have made 2 mistakes.\n");		
							

								else 
					{

									if (input2 == s1) 

									printf("Sorry, You have made 2 mistakes.\n");
									
										else 
							{

											if (input3 == s2)

											printf("Sorry, you have made 2 mistakes.\n");
														
												else {		/*If the user fails all 3 checks it prints that the user made 3 mistakes*/

													printf("Sorry, You have made 3 mistakes.\n");

												}
							}
					}
				}					
			}

		}
	}

	return 0;
}
