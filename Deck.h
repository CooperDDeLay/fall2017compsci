//***************************************************************************
// File name:  Deck.h
// Author:     Cooper DeLay
// Date:       3/10/18
// Class:      CS250
// Assignment: Card
// Purpose:    Declares a programmer-defined class card for the info 
//             of a Deck
//***************************************************************************
#pragma once

#include "Card.h"
#include <iostream>


class Deck
{

	public:
		Deck ();
		void shuffle ();
		Card deal ();
		int cardsLeft () const;
    void testPrintt () const;

	private:
		static const int MAX_CARDS_IN_DECK = 52;
		Card macDeckOfCards[MAX_CARDS_IN_DECK];
		int mTopCardIndex;
};