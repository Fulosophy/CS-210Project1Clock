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
		if (clck.strdHours == 0)
		{
			clck.strdHours = 12;
		}
		if (clck.strdHours > 12 && tod == "AM") // Resets standard time
		{
			clck.strdHours -= 12;
		}
		if (clck.strdHours > 12 && clck.milHours > 12)
		{
			clck.strdHours -= 12;
		}
		if (clck.milHours > 24)
		{
			clck.milHours -= 24;
		}
		if (clck.strdHours >= 12 && clck.milHours > 23)
		{
			clck.milHours = 0;
		}
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
			clck.AddHourMil(clck.milHours);
			clck.AddHourStandard(clck.strdHours);
			break;
		case 2:
			clck.AddMinuteStandard(clck.strdMins);
			clck.AddMinuteMil(clck.milMins);
			break;

		case 3:
			clck.AddSecStandard(clck.strdSecs);
			clck.AddSecMil(clck.milSecs);
			break;

		case 4:
			system("CLS");
			cout << "Program Terminated";
			break;

		default:
			
			system("CLS");
			cout << "Invalid Command" << endl;
			break;
		}
	}
}
