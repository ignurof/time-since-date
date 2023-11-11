#include <stdio.h>
#include "../../thyme/thyme.h"

// Program should handle frontend (input, output)
// Library should handle backend (calculations)

// This creates a stray newline for the next input in the stream
// all scanf after this should have a blank space before the conversion specifier in the format string
// https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
int main(void)
{
	struct tsd time_since_date = get_time_since_date();

	printf("Years since date: %i\n", time_since_date.years_since_date);
	printf("Months since date: %i\n", time_since_date.months_since_date);
	printf("Weeks since date: %i\n", time_since_date.weeks_since_date);
	printf("Days since date: %i\n", time_since_date.days_since_date);
	printf("Hours since date: %i\n", time_since_date.hours_since_date);
	printf("Minutes since date: %i\n", time_since_date.minutes_since_date);
	printf("Seconds since date: %i\n", time_since_date.seconds_since_date);

	return 0;
}
