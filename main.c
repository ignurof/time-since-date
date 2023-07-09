#include <stdio.h>
#include <time.h>
#include <mylib.h>

void handle_time_conversion(time_t);

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

		handle_time_conversion(time(NULL));

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

// TODO: put into lib
void handle_time_conversion(time_t time_result)
{
	if(time_result != (time_t)(-1))
	{
		printf("Current time in UTC is %s\n", asctime(gmtime(&time_result)));
		printf("Local: %s\n", asctime(localtime(&time_result)));
		// TODO: learn structs -> man mktime, man difftime
		struct tm time_struct = *localtime(&time_result);
		int current_year = (1900 + time_struct.tm_year);
		printf("year: %i\n", current_year);
		int current_month = (1 + time_struct.tm_mon);
		printf("month: %i\n", current_month);
	}
}
