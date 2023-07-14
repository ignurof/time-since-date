#include <stdio.h>
#include "time_conversion.h"
#include "app_utils.h"
#include "validate_input.h"

int main(void)
{
	app_init();	

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

		// C is pass by value, so I don't need a pointer adress here
		// since there is no modication of the variable going on, only value read
		int validate_date_input = validate_date(date_birth);
		if(validate_date_input == 0)
			return 1;
		
		time_object my_time = handle_time_conversion();
		//printf("%i, %i\n", time.year, time.month);

		// C pass variables by value, so to change a variable inside of the function scope
		// I need to pass the adress of the variable, and a adress is a pointer variable
		// That means the function should take a int pointer as we are trying to change the value of an int
		// handle_app_exit(int *);
		handle_app_exit(&should_app_close);
	}

	printf("Exiting program...\n");

	return 0;
}
