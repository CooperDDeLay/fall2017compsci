//***************************************************************************
// File name:  Card.cpp
// Author:     Cooper DeLay
// Date:       3/10/18
// Class:      CS250
// Assignment: Card
// Purpose:    Implements constructers and functions of class Card
//***************************************************************************
#include "stdafx.h"
#include "Card.h"
#include "Deck.h"

const enum getCardDenominations {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                               EIGHT, NINE, TEN, JACK, QUEEN, KING};

//static lookup tables to reduce the need for ifs or switch statements
const char Card::aSuit[] = { 'H', 'D', 'C', 'S',};
const std::string Card::aDenomination[] = { "2", "3", "4", "5", "6", "7", "8",
                                            "9", "10", "J", "Q", "K", "A" };

//***************************************************************************
// Constructor: card
//
// Description: Initializes data members to default values
//
// Parameters:  int cardValue - The Value that determines the number and suit 
//                             of the card
//
// Returned: None
//***************************************************************************
Card::Card (int cardid)
{
  mCardId = cardid;
}

//***************************************************************************
// Function:    getSuit
//
// Description: prints the Suit of a given card
//
// Parameters:  None
//
// Returned:    Char
//
//***************************************************************************
char Card::getSuit () const
{
  return aSuit[mCardId / CARDS_IN_SUIT];

}

//***************************************************************************
// Function:    getDenomination
//
// Description: gets the number of a given card
//
// Parameters:  None
//
// Returned:    String
//
//***************************************************************************
std::string Card::getDenomination () const
{
  return aDenomination[mCardId % CARDS_IN_SUIT];
}

//***************************************************************************
// Function:    isLegalCardId
//
// Description: Checks if a card ID is legal
// Parameters:  cardID -- the number to be confirmed
//
// Returned:    True or False
//
//***************************************************************************
bool Card::isLegalCardId (int cardId)
{
  return cardId < MAX_CARD_ID && cardId > MIN_CARD_ID;
}

void Card::testPrint () //TEMPORARY|DONT FORGET TO REMOVE
{
  std::cout << getDenomination () << getSuit ();
}

//***************************************************************************
// Function:    islessThan
//
// Description: compares the parent card to a given card
//
// Parameters:  card cCard2 - the given card to be compared
//
// Returned:    True or False
//
//***************************************************************************
bool Card::isLessThan (const Card &rcCard) const
{
  return mCardId / CARDS_IN_SUIT < rcCard.mCardId / CARDS_IN_SUIT;
}

//***************************************************************************
// Function:    isGreaterThan
//
// Description: compares the parent card to a given card
//
// Parameters:  card cCard2 - the given card to be compared
//
// Returned:    True or False
//
//***************************************************************************
bool Card::isGreaterThan (const Card &rcCard) const
{
  return mCardId / CARDS_IN_SUIT > rcCard.mCardId / CARDS_IN_SUIT;
}

//***************************************************************************
// Function:    isEqual
//
// Description: compares the parent card to a given card
//
// Parameters:  card cCard2 - the given card to be compared
//
// Returned:    True or False
//
//***************************************************************************
bool Card::isEqual (const Card &rcCard) const
{
  return mCardId / CARDS_IN_SUIT == rcCard.mCardId / CARDS_IN_SUIT;
}
