/*
# Created By Michael Colandrea
# Created On 1/13/2022
# CS-210 Project 1
*/

// Includes // 
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include "Main.h"
#include "Clock.h"
#include <iomanip>
#include<Windows.h> 

using namespace std;

// Forward Declaration //
void ShowClock();

 

int main()
{
	system("Color 0B"); // Added some color cause why not
	ShowClock();
	return 1;
}



void ShowClock()
{
	Clock clck; // OOP creating a clock object
	unsigned int selection = 0; // user Selection
	string tod; // tod == Time Of Day
		
	
	while (selection != 4)
	{
		
		clck.RollOver();
		// Checking if time frame is AM or PM based on time conversion
		if (clck.strdHours > 1 && clck.milHours >= 12 && clck.milHours < 24)
		{
			tod = "PM";
		}
		else {
			tod = "AM";
		}

		// Converting Military time to standard clock
		// Had a bug where Standard Time when checking at Midnight starts at 00, this if check fixes that
		if (clck.strdHours == 0) 
		{
			clck.strdHours = 12;
		}

		// Resets standard time to 1:00 after 12
		if (clck.strdHours > 12 && tod == "AM") 
		{
			clck.strdHours -= 12;
		}

		// Standard Time Conversion
		if (clck.strdHours > 12 && clck.milHours > 12) 
		{
			clck.strdHours -= 12;
		}

		/*if (clck.milHours > 24) // Disabled this check after switching military hours Midnight value to 00 instead of 2400
		{
			clck.milHours -= 24;
		}*/
		// This if check set's military time to 00:00 if Standard hours are 12 >=
		if (clck.strdHours >= 12 && clck.milHours > 23)
		{
			clck.milHours = 0;
		}
																	
																	// Main Menu console display information //
																
		cout << "\t\t\t\t\t\t   CHADA TECH" << endl;
		cout << "\n\n\n";
		cout << "\t\t\t      " << "12-Hour Clock" << "\t\t\t      " << "24-Hour Clock" << endl;
		cout << "\t\t\t" << "------------------------" << "\t\t" << "------------------------" << endl;
		cout << "\t\t\t\t" << setfill('0') << setw(2) << clck.strdHours << ":" <<  setfill('0') << setw(2) << clck.strdMins << ":" << setfill('0') << setw(2) << clck.strdSecs << " " << tod << "\t"
			<< "\t\t\t"<< setfill('0') << setw(2) << clck.milHours  << ":" << setfill('0') << setw(2) << clck.milMins << ":" << setfill('0') << setw(2) << clck.milSecs << " "<<tod << endl;
		cout << "\t\t\t" << "------------------------" << "\t\t" << "------------------------" << endl;

		cout << "\n\n";

		cout << "\t\t\t\t\tPlease Select from the following\n" << endl;
		cout << "\t\t\t\t\t      1. Add One Hour\n" << endl;
		cout << "\t\t\t\t\t      2. Add One Minute\n" << endl;
		cout << "\t\t\t\t\t      3. Add One Second\n" << endl;
		cout << "\t\t\t\t\t      4. Exit Program\n" << endl;
		
		cin >> selection;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		system("CLS");
		switch (selection)
		{
		case 1:
			// Adds One Hour to both time frames
			clck.AddHourMil(clck.milHours);
			clck.AddHourStandard(clck.strdHours);
			break;
		case 2:
			// Adds One Minute to both time Frames
			clck.AddMinuteStandard(clck.strdMins);
			clck.AddMinuteMil(clck.milMins);
			break;

		case 3:
			// Adds One Second to both time frames
			clck.AddSecStandard(clck.strdSecs);
			clck.AddSecMil(clck.milSecs);
			break;

		case 4: 
			// Clears console, then outputs terminated message
			system("CLS");
			cout << "Program Terminated";
			break;

		default:
			// if !cin.good() Clear console, print invalid command, continue loop.
			system("CLS");
			cout << "Invalid Command" << endl;
			break;
		}
	}
}
