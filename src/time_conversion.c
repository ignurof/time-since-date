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
		int current_month = (1 + time_struct.tm_mon);
		int current_day_in_month = time_struct.tm_mday;
		int current_week_day = time_struct.tm_wday;
		int current_day_in_year = time_struct.tm_yday;
		int current_hour = time_struct.tm_hour;
		int current_min = time_struct.tm_min;
		int current_sec = time_struct.tm_sec;

		time_object to;
		to.year = current_year;
		to.month = current_month;
		to.day_in_month = current_day_in_month;
		to.week_day = current_week_day;
		to.day_in_year = current_day_in_year;
		to.hour = current_hour;
		to.min = current_min;
		to.sec = current_sec;
		return to;
	}
}
