#include <stdio.h>

#define APP_NAME "age-since-birth"
#define APP_VERSION "v0.0.1"

void init_app(void)
{
	printf("%s %s\n\n", APP_NAME, APP_VERSION);
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
