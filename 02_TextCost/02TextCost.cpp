//****************************************************************************
//	Filename:							02_TextCost			
//	Name:									Cooper DeLay		
//	Date:									9/19/2017
//	Assignment:					  Text cost calculator			
//	Description:		      Calculate the monthly price of text messages sent
//	Hours worked:					1
//****************************************************************************

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int numTexts, numPics; // user input variables
	double totalCost;      // totalcost is the end result of the program
	int end;               // this determines whether the 
												 // program succeeded or failed
	const double UNDER_100_PRICE = 0.02;
	const double OVER_100_PRICE = 0.01;
	const double PIC_PRICE = 0.10; // constants for totalCost calculation later

	cout << setprecision(2) << fixed;

	cout << "**********************" << endl
		   << "*Text Cost Calculator*" << endl
		   << "**********************" << endl; // header

	cout << "How many text messages did you send last month? ";
	cin >> numTexts;								// user input of how many texts sent

	cout << "How many text messages contained a picture? ";
	cin >> numPics;					// user input of how many texts included pictures

	if (numTexts <= 100)
	{
		totalCost = numTexts * UNDER_100_PRICE + numPics * PIC_PRICE;
	}											//using the sub 100 texts rate

	if (numTexts > 100)
	{
		totalCost = numTexts * OVER_100_PRICE + numPics * PIC_PRICE;
	}											// using the more than 100 texts rate
	
	if ((numTexts <= 0) || (numPics > numTexts) || (numPics < 0))
	{
		cout << "\nInvalid Input" << endl << endl;
		end = EXIT_FAILURE; 
	}								// if input doesnt make sense, it throws an error
	
	if ((numTexts >= 0) && (numPics <= numTexts) && (numPics >=0))
	{
		cout << "\nYou will be charged: " 
			   << totalCost << endl << endl;
		end = EXIT_SUCCESS; 
	}					// if the input makes sense it shows the total cost for the month

	return end; // I return the exit as a variable, so I only have to
							// use return once.
}

