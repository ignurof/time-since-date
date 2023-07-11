#include <stdio.h>
#include "time_conversion.h"

#define APP_VERSION "v0.0.1"

void handle_app_exit(int *);

int main(void)
{
	// const char APP_VERSION[6] = "v0.0.1";

	int should_app_close = 0;
	int age_input = 0;

	printf("age-since-birth %s\n\n", APP_VERSION);

	while(should_app_close == 0)
	{
		printf("Enter the date of birth in this format: 19990101\n");
		printf("Age: ");
		// This creates a stray newline for the next input in the stream
		// all scanf after this should have a blank space before the conversion specifier in the format string
		// https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
		int age_result = scanf("%i", &age_input);
		printf("age_result: %i\n", age_result);

		// TODO: this should return a human-readable struct that can be used to print out all the values we might want
		// ie; seconds since birth, hours, days etc etc
		handle_time_conversion();

		// C pass variables by value, so to change a variable inside of the function scope
		// I need to pass the adress of the variable, and a adress is a pointer variable
		// That means the function should take a int pointer as we are trying to change the value of an int
		// handle_app_exit(int *);
		handle_app_exit(&should_app_close);
	}
	
	printf("Exiting program...\n");

	return 0;
}

void handle_app_exit(int *should_app_close)
{
	char close_input = 'n';
	
	printf("Do you want to go again? (y)es / (n)o\n");
	int close_result = scanf(" %c", &close_input);
	printf("close_result: %i\n", close_result);
	
	if(close_input == 'n')
	{
		// Here I need to dereference the pointer, 
		// to change the value located at the adress which the pointer contains
		*should_app_close = 1;
	}
	
	printf("restarting...\n");
}
