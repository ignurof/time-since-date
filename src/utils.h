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
int validate_second(int);

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


#endif
