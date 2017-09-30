//****************************************************************************
//	Filename:				01_Fraction
//	Name:					Cooper DeLay
//	Date:					9/8/2017
//	Assignment:			Fraction Calculator
//	Description:		Add two simple fractions together without simplifying 
//								the result
//	Hours worked:		40 minutes
//****************************************************************************

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int f1Num, f1Denom, 
		f2Num, f2Denom,
		endNum, endDenom; //calling my variables for later in the program

	cout << "***********************" << endl
			 << "* Fraction Calculator *" << endl
			 << "***********************" << endl; //Output's header

	cout << "Enter Fraction #1's numerator: ";
	cin >> f1Num;			//find first fraction numerator

	cout << "Enter Fraction #1's denominator: ";
	cin >> f1Denom;
	cout << endl;		    //find first fraction Denominator
																							
	cout << "Enter Fraction #2's numerator: ";
	cin >> f2Num;			//find second fraction numerator

	cout << "Enter Fraction #2's denominator: ";
	cin >> f2Denom;
	cout << endl;			//find second fraction Denominator

	endDenom = f1Denom * f2Denom;  //finds the common denominator

	endNum = (f1Num * f2Denom) + (f2Num * f1Denom); 
								  //uses common denominator to find 
								  //end numerator

	cout << f1Num << '/' << f1Denom << " + " << f2Num << '/'
		 << f2Denom << " = " << endNum << '/' << endDenom << endl;
											//Display Output
	return EXIT_SUCCESS;
   
}

