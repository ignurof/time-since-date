#include <stdio.h>
#include "validate_input.h"

int validate_date(int date_birth_input)
{
	// TODO: Actual validation that checks for a VALID date input
	if(date_birth_input < 19000101 || date_birth_input > 20500101)
	{
		printf("Invalid date input!\n");
		return 0;
	}

	return 1;
}
