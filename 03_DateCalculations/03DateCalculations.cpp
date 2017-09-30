//****************************************************************************
//	Filename:							03_DateCalculations			
//	Name:									Cooper DeLay		
//	Date:									9/25/2017
//	Assignment:					  Text cost calculator			
//	Description:		      Find day of week other info of a specific date
//	Hours worked:					3
//****************************************************************************

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main ()
{
	int month, day, year, daysMonth, weekDay;
	int a, y, m; // day of week calculation
	string finalWeekDay;
	const string MON = "Monday";
	const string TUES = "Tuesday";
	const string WED = "Wednesday";
	const string THUR = "Thursday";
	const string FRI = "Friday";
	const string SAT = "Saturday";
	const string SUN = "Sunday";
	const int SUN_POS = 0;
	const int MON_POS = 1;
	const int TUES_POS = 2;
	const int WED_POS = 3;
	const int THUR_POS = 4;
	const int FRI_POS = 5;
	const int SAT_POS = 6;
	const int LEAP_YEARS = 4;
	const int DAYS_IN_WEEK = 7;
	const int MONTHS_IN_YEAR = 12;
	const int MAX_DAYS_IN_MONTH = 31;
	const int CENTURY_YEARS = 100;
	const int CENTURY_LEAP_YEARS = 400;
	bool bLeapYear;


	cout << "******************" << endl
		   << " Date Calculations" << endl
		   << "******************" << endl << endl;

	cout << "What is the month? ";
	cin >> month;

	cout << "What is the day of the month? ";
	cin >> day;

	cout << "What is the year? ";
	cin >> year;


	if ((year % LEAP_YEARS == 0) && (year % CENTURY_YEARS != 0))
	{
		cout << endl << year << " is a leap year" << endl << endl;
		bLeapYear = true;
	}
	else if ((year % CENTURY_YEARS == 0) && 
					 (year % CENTURY_LEAP_YEARS == 0))
	{
		cout << endl << year << " is a leap year" << endl << endl;
		bLeapYear = true;
	}
	else
	{
		cout << endl << year << " is not a leap year" << endl << endl;
		bLeapYear = false;
	}

	switch (month)
	{
		case 2 : 
			if (bLeapYear)
			{
				daysMonth = 29;				//if feb and leapyear, 29 days, else 28
			}
			else
			{
				daysMonth = 28;
			}
			break;

		case 4 :
		case 6 :
		case 9 :
		case 11: daysMonth = 30; //these months have 30 days
			break;

		default: daysMonth = 31;  //every other month has 31, so its the default
			break;
	}

	a = (14 - month) / 12;
	y = year - a;						
	m = month + 12 * a - 2;

	weekDay = (day + y + y / LEAP_YEARS - y / CENTURY_YEARS + y
						/ CENTURY_LEAP_YEARS + (MAX_DAYS_IN_MONTH * m)
						/ MONTHS_IN_YEAR) % DAYS_IN_WEEK;


	switch (weekDay)
	{
		case SUN_POS: finalWeekDay = SUN;
			break;
		case MON_POS: finalWeekDay = MON;
			break;
		case TUES_POS: finalWeekDay = TUES;
			break;
		case WED_POS: finalWeekDay = WED;
			break;
		case THUR_POS: finalWeekDay = THUR;
			break;
		case FRI_POS: finalWeekDay = FRI;
			break;
		case SAT_POS: finalWeekDay = SAT;
			break;
	}

	cout << "The number of days in " << month << '/' << year << " is: "
			 << daysMonth << endl << endl;

	cout << month << '/' << day << '/' << year << " is a " << finalWeekDay
			 << endl << endl;



	return EXIT_SUCCESS;
	







}