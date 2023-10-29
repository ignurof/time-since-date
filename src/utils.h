#ifndef UTILS_H
#define UTILS_H

#define APP_NAME "age-since-birth"

void handle_app_exit(int*);
int validate_date(int);

// We need the struct definition here so it can be used wherever the header is #included
typedef struct
{
	int year;
	int month;
	int day_in_month;
	int hour;
	int min;
	int sec;
	int week_day;
	int day_in_year;
} time_object;

time_object handle_time_conversion(void);

#endif
