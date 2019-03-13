#include <stdio.h>

void wordCount(char word[]);

int main(void) {

	char words[100] = {};

	printf("Word Counter\n============\n");

	printf("Text to be analyzed : ");
	scanf("%100[^\n]", &words);		//Prompts the user for a string no more than 100 characters

	wordCount(words);			//Calls function for word count


	return 0;
}

void wordCount(char word[]){

	int k, b;

	for (k = 0; word[k] != '\0'; k++){	//Runs loop until the end of string with null byte

		if (word[k] == ' ') {		//Looks for blank spaces to add in counter

			b = b + 1;

		}


	}

	b = b + 1;				//Adds +1 for the missing space to count the last word

	printf("Word count : %d\n", b);		//Prints the word count


}
