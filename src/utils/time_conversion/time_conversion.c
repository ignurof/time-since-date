#include <stdio.h>
#include <time.h>
#include "time_conversion.h"

time_object handle_time_conversion(void)
{
	time_t time_result = time(NULL);

	if(time_result != (time_t)(-1))
	{
	//	printf("Current time in UTC is %s\n", asctime(gmtime(&time_result)));
	//	printf("Local: %s\n", asctime(localtime(&time_result)));
		// TODO: learn structs -> man mktime, man difftime
		struct tm time_struct = *localtime(&time_result);
		int current_year = (1900 + time_struct.tm_year);
	//	printf("year: %i\n", current_year);
		int current_month = (1 + time_struct.tm_mon);
	//	printf("month: %i\n", current_month);
		time_object to;
		to.year = current_year;
		to.month = current_month;
		printf("%i, %i\n", to.year, to.month);
		return to;
	}
}
