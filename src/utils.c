#include <stdio.h>
#include "utils.h"


void handle_app_exit(int* should_app_close)
{
	char close_option = 'n';

	printf("Retry %s ? (y) / (n)\n", APP_NAME);
	// Every scanf after the first requires whitespace
	// To change the value of close_option variable,
	// we need to pass the pointer address as C is pass by value as default,
	// so to edit the close_option variable value we need the memory pointer address.
	int close_option_input = scanf(" %c", &close_option);
	// Here we can just display the value as we don't want to edit it.
	printf("close_option_input: %i\n", close_option_input);

	if(close_option == 'n')
	{
		// Need to "dereference" the pointer to change value located at memory address.
		// a pointer tag (*) on a pointer address variable dereferences the pointer.
		*should_app_close = 1;
	}

	printf("Restarting...\n");
}
