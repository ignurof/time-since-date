#include <stdio.h>
#include "../../thyme/thyme.h"

int main(void)
{
	struct dti date_time_input = {2023, 1, 5, 9, 42, 0};

	struct tsd time_since_date = get_time_since_date(date_time_input);

	printf("%i years, %i months, %i days, %i hours, %i minutes, %i seconds\n", 
			time_since_date.years_since_date, 
			time_since_date.current_month_date_count, 
			time_since_date.current_day_date_count, 
			time_since_date.current_hour_date_count, 
			time_since_date.current_minute_date_count, 
			time_since_date.current_second_date_count
		  );

	printf("Years since date: %i\n", time_since_date.years_since_date);
	printf("Months since date: %i\n", time_since_date.months_since_date);
	printf("Weeks since date: %i\n", time_since_date.weeks_since_date);
	printf("Days since date: %i\n", time_since_date.days_since_date);
	printf("Hours since date: %i\n", time_since_date.hours_since_date);
	printf("Minutes since date: %i\n", time_since_date.minutes_since_date);
	printf("Seconds since date: %i\n", time_since_date.seconds_since_date);

	return 0;
}
