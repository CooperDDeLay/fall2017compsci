//*****************************************************************************
// File name: 01_Hamming.cpp
// Author: Cooper DeLay
// Date: 2/6/18
// Class: CS250
// Assignment: Hamming Distance
// Purpose: This program determines and displays the hamming distance of a 
//          group of strings of DNA, relative to a string input by the user.
//*****************************************************************************

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int gMAX_STRAND_AMNT = 20;
const int gMAX_STRAND_LENG = 61;
const string gDNA_FILE_NAME = "dnastrings.txt";



void titleCard ();

void loadUserString (char userDNAString[], istream &input);

void loadStrings (char sourceDNAStrings[][gMAX_STRAND_LENG],
  istream &input, int &strandCount);

int hammingNumCheck (char inputDNAStrings[], 
                     char sourceDNAStrings[]);

int smallestHamming (int &smallestHammingString, int strandCount,
                     char inputDNAStrings[],
                     char sourceDNAStrings[][gMAX_STRAND_LENG]);

void infoPrint (char inputDNAStrings[], 
                char sourceDNAStrings[][gMAX_STRAND_LENG],
                int strandCount, int smallestHammingString);

int main ()
{
  ifstream dataFile;
  char aUserDNAString[gMAX_STRAND_LENG];
  char aSourceDNAStrings[gMAX_STRAND_AMNT][gMAX_STRAND_LENG];
  int smallestHammingString = 0;
  int strandCount = 0;


  //Checks for and opens correct File
  dataFile.open (gDNA_FILE_NAME);

  if (dataFile.fail ())
  {
    cout << "Error Opening Data File" << endl;
    exit (EXIT_FAILURE);
  }

  titleCard ();

  loadStrings (aSourceDNAStrings, dataFile, strandCount);

  loadUserString (aUserDNAString, cin);

  smallestHamming (smallestHammingString, strandCount, 
                   aUserDNAString, aSourceDNAStrings);

  infoPrint (aUserDNAString, aSourceDNAStrings, strandCount, 
             smallestHammingString);

  dataFile.close ();
  return EXIT_SUCCESS;
}

//*****************************************************************************
// Function: titleCard
//
// Description: Displays the title of the program on the screen
//
// Parameters: None
//
// Returned: None
//*****************************************************************************
void titleCard ()
{
  cout << "********************" << endl
       << "  Hamming distance  " << endl
       << "********************" << endl << endl;

  return;
}

//*****************************************************************************
// Function: loadUserString
//
// Description: used to input DNA strings from the user
//
// Parameters: char userDNAString[] -- the array that will hold the string
//             istream &input -- the vehicle for recieving the info
//
// Returned: None
//*****************************************************************************
void loadUserString (char userDNAString[], istream &input)
{
  cout << "Enter DNA String: ";
  input >> userDNAString;
  cout << endl << endl;

  return;
}

//*****************************************************************************
// Function: loadStrings
//
// Description: used to input DNA strings from the text file
//
// Parameters: char sourceDNAStrings[] -- the array that will hold the string
//             ifstream &input -- the vehicle for recieving the info
//
// Returned: strandCount -- makes it easier to compare them later
//*****************************************************************************
void loadStrings (char sourceDNAStrings[][gMAX_STRAND_LENG],
                  istream &input, int &strandCount)
{

  while (input >> sourceDNAStrings[strandCount])
  {
    strandCount++;
  }

  return;
}

//*****************************************************************************
// Function: smallestHamming
//
// Description: used to input DNA strings from the text file
//
// Parameters: int &smallestHammingString --hold which String has least hamming
//             int strandCount -- inputs the amount of times for loop to run
//             char inputDNAStrings[] -- holds user input for test
//             char sourceDNAStrings[][gMAX_STRAND_AMNT] -- holds file in
//
// Returned: smallestHammingString -- the sample which has smallest dH
//*****************************************************************************
int smallestHamming (int &smallestHammingString, int strandCount,
                     char inputDNAStrings[],
                     char sourceDNAStrings[][gMAX_STRAND_LENG])
{
  int smallestdH = gMAX_STRAND_LENG;
  for (int i = 0; i < strandCount; i++)
  {
    if (hammingNumCheck (inputDNAStrings, sourceDNAStrings[i]) < 
                         smallestdH)
    {
      smallestHammingString = i;
      smallestdH = hammingNumCheck (inputDNAStrings, sourceDNAStrings[i]);
    }
  }

  return smallestHammingString;
}
//*****************************************************************************
// Function: hammingNumCheck
//
// Description: compares the user dna string to a dna string from the file
//
// Parameters: char inputDNAStrings[] -- holds user input
//             char sourceDNAStrings[] -- holds file input
//
// Returned: hamming --The number of different bases
//*****************************************************************************
int hammingNumCheck (char inputDNAStrings[],
                     char sourceDNAStrings[])
{
  int hamming = 0;
  int tempCount = 0;

  while (sourceDNAStrings[tempCount] != '\0')
  {
    if (sourceDNAStrings[tempCount] != inputDNAStrings[tempCount])
    {
      hamming++;
    }
    tempCount++;
  }

  return hamming;
}

//*****************************************************************************
// Function: infoPrint
//
// Description: Displays all info to screen
//
// Parameters: char inputDNAStrings[]  -- holds user input for displaying
//             char sourceDNAStrings[][gMAX_STRAND_LENG] -- holds file input  
//                                                          for displaying
//             int smallestHammingString -- the string with the smallest dH
//             int strandCount -- the amount of strands in array
//
// Returned: none
//*****************************************************************************
void infoPrint (char inputDNAStrings[],
                char sourceDNAStrings[][gMAX_STRAND_LENG],
                int strandCount, int smallestHammingString)
{
  for (int i = 0; i < strandCount; i++)
  {
    cout << "Input String: " << setfill (' ') << setw (60) 
         << left << inputDNAStrings << right << endl;
 
    cout << setfill (' ') << setw (10) << "S" << setfill ('0') << setw (2) 
         << i+1 << ": " << sourceDNAStrings[i] << endl;

    cout << setfill (' ') << setw (14) << "dH: " 
         << hammingNumCheck (inputDNAStrings, sourceDNAStrings[i]) 
         << endl << endl;
  }

  cout << setfill ('0') << "String S" << setw (2) << smallestHammingString + 1
       << " Has the Smallest dH of "
       << hammingNumCheck (inputDNAStrings,
                           sourceDNAStrings[smallestHammingString]) << endl;

  return;
}