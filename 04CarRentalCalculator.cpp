//****************************************************************************
//	Filename:							04_CarRentalCalculator
//	Name:									Cooper DeLay		
//	Date:									10/10/2017
//	Assignment:					 	Car Rental Calculator
//	Description:		      Show prices and days and totals for renting a car 
//	Hours worked:					
//****************************************************************************

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
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
	const int WED_POS = 3; //SUN_POS-SAT_POS are output of dayofweek calculation
	const int THUR_POS = 4;
	const int FRI_POS = 5;
	const int SAT_POS = 6;
	const int LEAP_YEARS = 4;
	const int DAYS_IN_WEEK = 7;
	const int MONTHS_IN_YEAR = 12;
	const int MAX_DAYS_IN_MONTH = 31;
	const int CENTURY_YEARS = 100;
	const int CENTURY_LEAP_YEARS = 400;

	int month, day, year, daysMonth, weekDay, daysRented, loopcount = 0;
	int a, y, m; // used in day of week calculation
	double weekDayRate, weekEndRate, dailyCost, runningSum = 0;
	string finalWeekDay;
	bool bLeapYear;

	cout << setprecision (2) << fixed;
	cout << "**********************" << endl
		   << "*Car Rental Calculator*" << endl
	     << "**********************" << endl << endl;

	cout << "What is the month? ";
	cin >> month;

	cout << "What is the year? ";
	cin >> year;

	cout << "What is the day of the month? ";
	cin >> day;

	cout << endl << "What is the weekday rate? ";
	cin >> weekDayRate;

	cout << "what is the weekend rate? ";
	cin >> weekEndRate;

	cout << endl << "How many days will you rent the car? ";
	cin >> daysRented;

	cout << setw (14) << left << "Date" << setw (14) << left
			 << "day" << setw (14) << "Daily Cost" << setw (14) << "Running Sum"
			 << endl << "-----------------------------------------------------";

	//below if else chain detects whether the given year is a leap year

	if ((year % LEAP_YEARS == 0) && (year % CENTURY_YEARS != 0))
	{
		bLeapYear = true;
	}
	else if ((year % CENTURY_YEARS == 0) &&
		(year % CENTURY_LEAP_YEARS == 0))
	{
		bLeapYear = true;
	}
	else
	{
		bLeapYear = false;
	}

	// switch statement to select correct days in selected month


	while (loopcount < daysRented)
	{

		switch (month)
		{
		case 2:
			if (bLeapYear)
			{
				daysMonth = 29;				//if feb and leapyear, 29 days, else 28
			}
			else
			{
				daysMonth = 28;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11: daysMonth = 30;
			break;

		default: daysMonth = 31;
			break;
		}

		a = (14 - month) / 12;
		y = year - a;						   // a, y ,and m are values for the weekday calc
		m = month + 12 * a - 2;

		// outputs an int 0-6, assgined to sun-sat

		weekDay = (day + y + y / LEAP_YEARS - y / CENTURY_YEARS + y
			/ CENTURY_LEAP_YEARS + (MAX_DAYS_IN_MONTH * m)
			/ MONTHS_IN_YEAR) % DAYS_IN_WEEK;


		//converts the int 0-6 to the correct day

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
		
		if ((finalWeekDay != SUN) && (finalWeekDay != SAT))
		{
			dailyCost = weekDayRate;
		}
		else
		{
			dailyCost = weekEndRate;
		}

		runningSum += dailyCost;

		if (finalWeekDay == SAT)
		{
			cout << endl << setw (14) << left << day << setw (14) << left
				<< finalWeekDay << setw (14) << dailyCost << setw (14) << runningSum
				<< endl;
		}
		else {
			cout << endl << setw (14) << left << day << setw (14) << left
				<< finalWeekDay << setw (14) << dailyCost << setw (14) << runningSum;
		}

		++day;
		++loopcount;

		if (day > daysMonth)
		{
			++month;
			day = 1;
		}
	}

	cout << endl << "-----------------------------------------------------"
		<< endl << setw (33) << right << "Total Cost" << setw (14) << runningSum 
		<< endl << endl;

	return EXIT_SUCCESS;

}