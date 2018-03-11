//***************************************************************************
// File name:  Card.h
// Author:     Cooper DeLay
// Date:       2/26/18
// Class:      CS250
// Assignment: Card
// Purpose:    Declares a programmer-defined class card for the info 
//             of a card
//***************************************************************************
#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>


class Card
{
public:
  Card (int cardId = 0);
  bool isEqual (const Card &rcCard) const;
  bool isLessThan (const Card &rcCard) const;
  bool isGreaterThan (const Card &rcCard) const;
  char getSuit () const;
  std::string getDenomination () const;
  static bool isLegalCardId (int cardId);
  void testPrint (); //TEMPORARY 

private:
  static const int NUM_SUITS = 4;
  static const int CARDS_IN_SUIT = 13;
  static const int MIN_CARD_ID = 0;
  static const int MAX_CARD_ID = 51;
  static const char aSuit[NUM_SUITS];
  static const std::string aDenomination[CARDS_IN_SUIT];
  int mCardId;
};
