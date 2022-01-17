#include "Clock.h"
#include <ctime>
#include <chrono>

/*
	The point of the clock class is to track data and save the time in which is being edited by the end user.
	For instance the clock class grabs the real time from your computer, and then saves it's values to a pointer in which the end user is able to edit by incrementing.
	This class is currently set up for future adaptability in the program in which I will be able to change the increment value and add new features by giving everything
	a set pointer rather then sharing references.

	Standard Time consists of : Hours/Minutes/Seconds 
	Military Time consists of : Hours/Minutes/Seconds 

	The reason this is done so in the future, I plan to modify the code so that the end user is able to change the values of each and every detail of the 
	clock in front of them without having to dish through shared references later.

*/




void Clock::RollOver()
{
									// Rollover is implace to make sure minutes and seconds don't go over the timings of a normal clock.
									// For instance rollover makes sure you can not have a time of "1:60:00pm"
	if (strdMins > 59) // Checks seperately if user exceeds 59
	{
		strdMins = 0;
		strdHours += 1;
	}
	if (strdSecs > 59)// Checks seperately if user exceeds 59
	{
		strdSecs = 0;
		strdMins += 1;
	}
	if (strdSecs > 59 && strdMins > 59 || strdMins == 60) // Checks if Seconds Exceeds 59 and then if the minutes exceed 59
	{
		strdMins = 0;
		strdSecs = 0;
		strdHours += 1;
	}
	if (milMins > 59)// Checks seperately if user exceeds 59

	{
		milMins = 0;
		milHours += 1;
	}
	if (milSecs > 59)// Checks seperately if user exceeds 59
	{
		milSecs = 0;
		milMins += 1;
	}
	if (milSecs > 59 && milMins > 59 || milMins == 60) // Checks if Seconds Exceeds 59 and then if the minutes exceed 59
	{
		milMins = 0;
		milSecs = 0;
		milHours += 1;
	}
}
void Clock::AddHourStandard(int& time )
{
	strdHours = time;
	time += 1;
}


void Clock::AddMinuteStandard(int& time)
{
	strdMins = time;
	time += 1;

}
void Clock::AddSecStandard(int& time)
{
	strd->tm_sec = time;
	time += 1;
}

void Clock::AddHourMil(int& time)
{
	milHours = time;
	time += 1;
}

void Clock::AddMinuteMil(int& time)
{
	milMins = time;
	time += 1;
}

void Clock::AddSecMil(int& time)
{
	milSecs = time;
	time += 1;
}
