#include <stdio.h>
#include "../../thyme/thyme.h"

int main(void)
{
	struct date_time_input_t dti = {2023, 1, 5, 9, 42, 0};

	struct time_since_date_t tsd = get_time_since_date(dti);

	printf("%i years, %i months, %i days, %i hours, %i minutes, %i seconds\n", 
			tsd.years_since_date, 
			tsd.current_month_date_count, 
			tsd.current_day_date_count, 
			tsd.current_hour_date_count, 
			tsd.current_minute_date_count, 
			tsd.current_second_date_count
		  );

	printf("Years since date: %i\n", tsd.years_since_date);
	printf("Months since date: %i\n", tsd.months_since_date);
	printf("Weeks since date: %i\n", tsd.weeks_since_date);
	printf("Days since date: %i\n", tsd.days_since_date);
	printf("Hours since date: %i\n", tsd.hours_since_date);
	printf("Minutes since date: %i\n", tsd.minutes_since_date);
	printf("Seconds since date: %i\n", tsd.seconds_since_date);

	return 0;
}
