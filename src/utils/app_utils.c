#include <stdio.h>
#include "version.h"
#include "app_utils.h"

#define APP_NAME "age-since-birth"

void app_init(void)
{
	printf("%s %i %i %i\n\n", APP_NAME, APP_VERSION_MAJOR, APP_VERSION_MINOR, APP_VERSION_PATCH);
}

void handle_app_exit(int *should_app_close)
{
	char close_option = 'n';
	
	printf("Do you want to go again? (y)es / (n)o\n");
	int close_option_input = scanf(" %c", &close_option);
	printf("close_option_input: %i\n", close_option_input);
	
	if(close_option == 'n')
	{
		// Here I need to dereference the pointer, 
		// to change the value located at the adress which the pointer contains
		*should_app_close = 1;
	}
	
	printf("Restarting...\n");
}
