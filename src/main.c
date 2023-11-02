#include <stdio.h>
#include "utils.h"

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
	int year_date = 0;
	int month_date = 0;
	int day_date = 0;
	int hour_date = 0;
	int minute_date = 0;
	int second_date = 0;

	while(should_app_close == 0)
	{
		// DEBUG
		year_date = 2023;
		month_date = 1;
		day_date = 5;
		hour_date = 9;
		minute_date = 42;
		second_date = 0;
		// DEBUG

		printf("Year of date (19XX): ");
		// This creates a stray newline for the next input in the stream
		// all scanf after this should have a blank space before the conversion specifier in the format string
		// https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
		//scanf("%i", &year_date);
		int validate_year_input = validate_year(year_date);
		if(validate_year_input == 0)
			return 1;

		printf("Month of date (1-12): ");
		//scanf(" %i", &month_date);
		int validate_month_input = validate_month(month_date);
		if(validate_month_input == 0)
			return 2;

		printf("Day of date (1-31): ");
		//scanf(" %i", &day_date);
		int validate_day_input = validate_day(day_date);
		if(validate_day_input == 0)
			return 3;

		printf("Hour of date (0-23): ");
		//scanf(" %i", &hour_date);
		int validate_hour_input = validate_hour(hour_date);
		if(validate_hour_input == 0)
			return 4;

		printf("Minute of date (0-59): ");
		//scanf(" %i", &minute_date);
		int validate_minute_input = validate_minute(minute_date);
		if(validate_minute_input == 0)
			return 5;

		printf("Second of date (0-59): ");
		//scanf(" %i", &second_date);
		int validate_second_input = validate_second(second_date);
		if(validate_second_input == 0)
			return 6;

		printf("Getting current time...\n\n");
		time_object converted_time = handle_time_conversion();
		printf("year: %i, month: %i, day_in_month: %i, week_day: %i\n",
				converted_time.year,
				converted_time.month,
				converted_time.day_in_month,
				converted_time.week_day
			  );
		printf("day_in_year: %i, hour: %i, min: %i, sec: %i\n\n",
				converted_time.day_in_year,
				converted_time.hour,
				converted_time.min,
				converted_time.sec
			  );

		int years_since_date = converted_time.year - year_date;

		int current_month_date_count = converted_time.month - month_date;
		// if age has not reached the birth month yet, convert year and month correctly
		// ie: 28 years -2 months -> 27 years 10 months
		if(current_month_date_count < 0)
		{
			int x = 12;
			x += current_month_date_count;
			current_month_date_count = x;
			years_since_date -= 1;
		}

		int current_day_date_count = converted_time.day_in_month - day_date;
		int months_since_date = 0;
		int days_since_date = 0;
		int iterate_year_date = year_date;
		int i;
		for(i = 0; i < years_since_date; i++)
		{
			if(iterate_year_date % 4 == 0)
			{
				days_since_date += 366;
			}
			else
			{
				days_since_date += 365;
			}

			iterate_year_date += 1;
		}

		// TODO: Fixa så det inte står 10 månader -4 dagar nu när det är 4 dagar kvar.
		// det borde stå typ 9 månader och XX dagar.
		if(current_day_date_count < 0)
		{
			current_month_date_count -= 1;
			// here we need to make sure month index is back to 0
			// then account for the previous month not current month
			switch(converted_time.month - 1)
			{
				case JANUARY:
					// DECEMBER 
					current_day_date_count = 31 + current_day_date_count;
					break;
				case FEBRUARY:
					// JANUARY
					current_day_date_count = 31 + current_day_date_count;
					break;
				case MARCH:
					// FEBRUARY
					current_day_date_count = 28 + current_day_date_count;
					if(year_date % 4 == 0) // leap year
						current_day_date_count += 1;
					break;
				case APRIL:
					// MARCH
					current_day_date_count = 31 + current_day_date_count;
					break;
				case MAY:
					// APRIL
					current_day_date_count = 30 + current_day_date_count;
					break;
				case JUNE:
					// MAY
					current_day_date_count = 31 + current_day_date_count;
					break;
				case JULY:
					// JUNE
					current_day_date_count = 30 + current_day_date_count;
					break;
				case AUGUST:
					// JULY
					current_day_date_count = 31 + current_day_date_count;
					break;
				case SEPTEMBER:
					// AUGUST
					current_day_date_count = 31 + current_day_date_count;
					break;
				case OCTOBER:
					// SEPTEMBER
					current_day_date_count = 30 + current_day_date_count;
					break;
				case NOVEMBER:
					// OCTOBER
					current_day_date_count = 31 + current_day_date_count;
					break;
				case DECEMBER:
					// NOVEMBER
					current_day_date_count = 30 + current_day_date_count;
					break;
			}
		}

		printf("%i years, %i months and %i days\n", years_since_date, current_month_date_count, current_day_date_count);

		printf("Years since date: %i\n", years_since_date);

		months_since_date = years_since_date * 12 + current_month_date_count;
		printf("Months since date: %i\n", months_since_date);

		days_since_date = current_day_date_count + days_since_date;

		// calculcate correct days since date
		if(years_since_date == 0)
		{
			days_since_date = 0;
			int j;
			for(j = 0; j < current_month_date_count; j++)
			{
				switch(j)
				{
					case JANUARY:
						days_since_date += 31;
						break;
					case FEBRUARY:
						days_since_date += 28;
						if(year_date % 4 == 0) // leap year
							days_since_date += 1;
						break;
					case MARCH:
						days_since_date += 31;
						break;
					case APRIL:
						days_since_date += 30;
						break;
					case MAY:
						days_since_date += 31;
						break;
					case JUNE:
						days_since_date += 30;
						break;
					case JULY:
						days_since_date += 31;
						break;
					case AUGUST:
						days_since_date += 31;
						break;
					case SEPTEMBER:
						days_since_date += 30;
						break;
					case OCTOBER:
						days_since_date += 31;
						break;
					case NOVEMBER:
						days_since_date += 30;
						break;
					case DECEMBER:
						days_since_date += 31;
						break;
				}
			}

			days_since_date += current_day_date_count;
		}
		printf("Days since date: %i\n", days_since_date);

		int hours_since_date = days_since_date * 24 - 24 + converted_time.hour;
		hours_since_date += 24 - hour_date;
		// remove 1 to account for the minutes until the full hour	
		hours_since_date -= 1;
		printf("Hours since date: %i\n", hours_since_date);

		int minutes_since_date = hours_since_date * 60 + converted_time.min;
		minutes_since_date += 60 - minute_date; 
		printf("Minutes since date: %i\n", minutes_since_date);

		int seconds_since_date = 0;
		printf("Seconds since date: %i\n", seconds_since_date);

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
