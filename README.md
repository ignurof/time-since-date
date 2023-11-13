# time-since-date 

## Changelog
### v0.2.1
- Prepare for input rework by passing data from program to thyme library.
### v0.2.0
- Moved date time functionality to thyme.c https://github.com/ignurof/thyme
- Preparing to keep program as only frontend (input, sanitize, errors, output)
### v0.1.2
- Add weeks since date calculation.
### v0.1.1
- Add some calculations to time differences to get the actual time since date.
### v0.1.0
- Created utility class to handle time object conversion and input validation.
- Compare the user-input date and time with the current.
- Automated debug instead of user-input for rapid prototyping.


## How-To

Build app:
gcc -o build/app src/*.c

Run app:
./build/app

