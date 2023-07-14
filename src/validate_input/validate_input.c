#include <stdio.h>

void validate_date_input(int date_birth_input)
{
	if(date_birth_input >= 19000101 || date_birth_input <= 20500101)
	{
		printf("Successfull input");
	}
	else
	{
		printf("Error!");
	}
}
