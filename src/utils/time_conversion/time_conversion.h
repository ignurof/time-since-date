#ifndef TIME_CONVERSION_H
#define TIME_CONVERSION_H

// We need the struct time_object definition here so it can be used in main.c or other included files
typedef struct time_object
{
	int year;
	int month;
} time_object;

time_object handle_time_conversion(void);

#endif
