#include <stdio.h>
#include "time_conversion.h"
#include "app_utils.h"

int main(void)
{
	int should_app_close = 0;
	int date_birth = 0;

	while(should_app_close == 0)
	{
		printf("Enter the date of birth in this format: 19990101\n");
		printf("Date of birth: ");
		// This creates a stray newline for the next input in the stream
		// all scanf after this should have a blank space before the conversion specifier in the format string
		// https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
		int date_birth_input = scanf("%i", &date_birth);
		printf("date_birth_input: %i\n", date_birth_input);

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


