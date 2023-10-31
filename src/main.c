#include <stdio.h>
#include "utils.h"

enum {
	JANUARY = 0,
	FEBRUARY = 1,
	MARCH = 2,
	APRIL = 3,
	MAY = 4,
	JUNE = 5,
	JULY = 6,
	AUGUST = 7,
	SEPTEMBER = 8,
	OCTOBER = 9,
	NOVEMBER = 10,
	DECEMBER = 11
};

int main(void)
{
	int should_app_close = 0;
	int year_birth = 0;
	int month_birth = 0;
	int day_birth = 0;
	int hour_birth = 0;
	int minute_birth = 0;

	while(should_app_close == 0)
	{
		// DEBUG
		year_birth = 2023;
		month_birth = 1;
		day_birth = 5;
		hour_birth = 9;
		minute_birth = 42;
		// DEBUG

		printf("Year of birth (19XX): ");
		// This creates a stray newline for the next input in the stream
		// all scanf after this should have a blank space before the conversion specifier in the format string
		// https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
		//scanf("%i", &year_birth);
		int validate_year_input = validate_year(year_birth);
		if(validate_year_input == 0)
			return 1;

		printf("Month of birth (1-12): ");
		//scanf(" %i", &month_birth);
		int validate_month_input = validate_month(month_birth);
		if(validate_month_input == 0)
			return 2;

		printf("Day of birth(1-31): ");
		//scanf(" %i", &day_birth);
		int validate_day_input = validate_day(day_birth);
		if(validate_day_input == 0)
			return 3;

		printf("Hour of birth (0-23): ");
		//scanf(" %i", &hour_birth);
		int validate_hour_input = validate_hour(hour_birth);
		if(validate_hour_input == 0)
			return 4;

		printf("Minute of birth (0-59): ");
		//scanf(" %i", &minute_birth);
		int validate_minute_input = validate_minute(minute_birth);
		if(validate_minute_input == 0)
			return 5;
		
		printf("Getting current time...\n\n");
		time_object time = handle_time_conversion();
		printf("year: %i, month: %i, day_in_month: %i, week_day: %i\n",
				time.year,
				time.month,
				time.day_in_month,
				time.week_day
			  );
		printf("day_in_year: %i, hour: %i, min: %i, sec: %i\n\n",
				time.day_in_year,
				time.hour,
				time.min,
				time.sec
			  );

		int years_since_birth = time.year - year_birth;

		int current_month_birth_conversion = time.month - month_birth;
		// if age has not reached the birth month yet, convert year and month correctly
		if(current_month_birth_conversion < 0)
		{
			int x = 12;
			x += current_month_birth_conversion;
			current_month_birth_conversion = x;
			years_since_birth -= 1;
		}

		int current_day_birth_conversion = time.day_in_month - day_birth;
		int months_since_birth = 0.0;
		int days_since_birth = 0;
		int year_date = year_birth;
		int i;
		for(i = 0; i < years_since_birth; i++)
		{
			if(year_date % 4 == 0)
			{
				days_since_birth += 366;
			}
			else
			{
				days_since_birth += 365;
			}

			year_date += 1;
		}
		
		printf("%i years old, %i months and %i days\n", years_since_birth, current_month_birth_conversion, current_day_birth_conversion);

		printf("Years since birth: %i\n", years_since_birth);
		
		months_since_birth = years_since_birth * 12 + current_month_birth_conversion;
		printf("Months since birth: %i\n", months_since_birth);

		days_since_birth = current_day_birth_conversion + days_since_birth;

		if(years_since_birth == 0)
		{
			//  JANUARY = 31,
			//	FEBRUARY = 28,
			//	MARCH = 31,
			//	APRIL = 30,
			//	MAY = 31,
			//	JUNE = 30,
			//	JULY = 31,
			//	AUGUST = 31,
			//	SEPTEMBER = 30,
			//	OCTOBER = 31,
			//	NOVEMBER = 30,
			//	DECEMBER = 31
			days_since_birth = 0;
			int j;
			for(j = 0; j < current_month_birth_conversion; j++)
			{
				switch(j)
				{
					case JANUARY:
						days_since_birth += 31;
						break;
					case FEBRUARY:
						days_since_birth += 28;
						if(year_date % 4 == 0) // leap year
							days_since_birth += 1;
						break;
					case MARCH:
						days_since_birth += 31;
						break;
					case APRIL:
						days_since_birth += 30;
						break;
					case MAY:
						days_since_birth += 31;
						break;
					case JUNE:
						days_since_birth += 30;
						break;
					case JULY:
						days_since_birth += 31;
						break;
					case AUGUST:
						days_since_birth += 31;
						break;
					case SEPTEMBER:
						days_since_birth += 30;
						break;
					case OCTOBER:
						days_since_birth += 31;
						break;
					case NOVEMBER:
						days_since_birth += 30;
						break;
					case DECEMBER:
						days_since_birth += 31;
						break;
				}
			}

			days_since_birth += current_day_birth_conversion;
		}
		printf("Days since birth: %i\n\n", days_since_birth);

		int hours_since_birth = days_since_birth * 24 - 24 + time.hour;
		hours_since_birth += 24 - hour_birth;
		printf("Hours since birth: %i\n", hours_since_birth);

		// C pass variables by value, so to change a variable inside of the function scope
		// I need to pass the adress of the variable, and a adress is a pointer variable
		// That means the function should take a int pointer as we are trying to change the value of an int
		// handle_app_exit(int *);
		// future me: this was a great comment!
		handle_app_exit(&should_app_close);
	}

	printf("Exiting program...\n");

	return 0;
}
