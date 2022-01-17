#pragma once
#include<ctime>
#pragma warning(disable : 4996)
class Clock
{
public:
								/*   Grabbing Time information from computer
									 using struct TM from <ctime> in order to grab local computer time
									 TM allows the user to access data indivdually like the hours/minutes/seconds and save them to a variable
								*/


	time_t ts = time(nullptr); // Standard Time 
	time_t tms = time(nullptr); // Military Time 

	tm* strd = localtime(&ts); // Standard time 
	tm* mil = localtime(&tms); // Military time 
	
									// Setting Integers to the int value of the time 
									// For instance tm_hour is a int in a struct called TM which allows us to grab the info of the HOURS column in the struct.
	// Standard Variables
	int strdHours = strd->tm_hour; 
	int strdMins = strd->tm_min;
	int strdSecs = strd->tm_sec;
	// Military Variables
	int milHours = mil->tm_hour;
	int milMins = mil->tm_min;
	int milSecs = mil->tm_sec;
	
	

public:
	void AddMinuteStandard(int& time);
	void AddHourStandard(int& time );
	void AddSecStandard(int& time);
	void AddHourMil(int& time);
	void AddMinuteMil(int& time);
	void AddSecMil(int& time);
	void RollOver();




};

