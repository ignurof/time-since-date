#ifndef UTILS_H
#define UTILS_H

#define APP_NAME "age-since-birth"

#define TRUE 1
#define FALSE 0

void handle_app_exit(int*);
int validate_year(int);
int validate_month(int);
int validate_day(int);
int validate_hour(int);
int validate_minute(int);

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
