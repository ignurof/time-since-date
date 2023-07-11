#include <stdio.h>
#include "time_conversion.h"

int main(void)
{
	const char APP_VERSION[6] = "v0.0.1";

	int should_app_close = 0;
	char close_input = 'n';
	int age_input = 0;

	printf("age-since-birth %s\n\n", APP_VERSION);

	while(should_app_close == 0)
	{
		printf("Enter the date of birth in this format: 19990101\n");
		printf("Age: ");
		// This creates a stray newline for the next input in the stream
		// see below comment-block for explanation
		int age_result = scanf("%i", &age_input);
		printf("age_result: %i\n", age_result);

		handle_time_conversion();

		printf("Do you want to go again? (y)es / (n)o\n");
		/*
		 * https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
		 The %c conversion specifier won't automatically skip any leading whitespace, so if there's a stray newline in the input stream (from a previous entry, for example) the scanf call will consume it immediately.
		 One way around the problem is to put a blank space before the conversion specifier in the format string:
		 */
		int close_result = scanf(" %c", &close_input);
		printf("close_result: %i\n", close_result);
		if(close_input == 'n')
		{
			should_app_close = 1;
		}
		printf("restarting...\n");
	}
	printf("Exiting program...\n");

	return 0;
}
